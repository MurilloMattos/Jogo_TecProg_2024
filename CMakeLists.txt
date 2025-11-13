# Versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(JogoTecProg LANGUAGES CXX)

# Define o padrão C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Encontrar Arquivos do Jogo ---

include_directories(Jogo_TecProg_2024)
file(GLOB SOURCES "Jogo_TecProg_2024/*.cpp")
file(GLOB HEADERS "Jogo_TecProg_2024/*.h")

# --- Configuração do SFML (Pasta Única) ---

# Define o caminho para a pasta local do SFML (com o nome padrão do download)
# ATENÇÃO: O CONTEÚDO desta pasta deve ser trocado ao mudar de OS.
set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1)

# Diz ao CMake para procurar pacotes (como o SFML) nesta pasta primeiro
set(CMAKE_PREFIX_PATH ${SFML_DIR})

# Procura pelo SFML.
# A versão 2.5 aqui deve corresponder ao nome da pasta/versão baixada
find_package(SFML 2.5 REQUIRED COMPONENTS system window graphics audio network)

# --- Criar o Executável ---

add_executable(JogoTecProg ${SOURCES} ${HEADERS})

target_link_libraries(JogoTecProg PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network)

# Ajuste de RPATH para Linux: faz com que o executável procure as libs em
# ${CMAKE_SOURCE_DIR}/SFML-2.5.1/lib durante a execução, evitando a necessidade
# de exportar LD_LIBRARY_PATH manualmente a cada execução.
if(UNIX AND NOT APPLE)
    # Caminho absoluto para a pasta das libs SFML
    # Usar RPATH relativo (ORIGIN) para tornar o binário portátil dentro do projeto.
    # $ORIGIN é o diretório do executável em tempo de execução; apontamos para
    # ../SFML-2.5.1/lib relativo a ele.
    set_target_properties(JogoTecProg PROPERTIES BUILD_RPATH "\$ORIGIN/../SFML-2.5.1/lib")
    set_target_properties(JogoTecProg PROPERTIES INSTALL_RPATH "\$ORIGIN/../SFML-2.5.1/lib")
    # Garantir que o RPATH seja preservado no build
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
endif()

# Alvo de conveniência: `cmake --build . --target run` executará o binário após a compilação
add_custom_target(run
    COMMAND $<TARGET_FILE:JogoTecProg>
    DEPENDS JogoTecProg
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Copiar assets para o diretório de build para que o executável encontre recursos
# quando executado a partir de build/ (evita problemas com caminhos relativos).
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# --- Específico para Windows: Copiar DLLs ---

# Esta é a "condição do windows" que mantivemos.
# Ela só roda no Windows e copia as .dll necessárias para junto do .exe
if(WIN32)
    file(GLOB SFML_DLLS "${SFML_DIR}/bin/*.dll")
    
    add_custom_command(TARGET JogoTecProg POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${SFML_DLLS}
        $<TARGET_FILE_DIR:JogoTecProg>
    )
endif()

# Em sistemas POSIX (Linux) copiamos as .so localmente para o diretório do executável
# como fallback prático (opcional). Isso evita depender de variáveis de ambiente.
## note: omitted auto-copy of .so files because it can complicate the build
## on some toolchains. RPATH is set so the executable will find the SFML libs
## in the project's SFML-2.5.1/lib directory at runtime.