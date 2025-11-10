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