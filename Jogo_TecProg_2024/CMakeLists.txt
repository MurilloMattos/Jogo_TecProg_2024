# Define a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(TecProgGame)

# Configuração das variáveis
set(CMAKE_CXX_STANDARD 14) # ou outra versão de C++ se preferir
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Definir os diretórios
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Adicionar cabeçalhos ao projeto
include_directories(${INCLUDE_DIR})

# Buscar automaticamente todos os arquivos .cpp dentro de src
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)

# Criar o executável
add_executable(sfml-app ${SOURCES})

# Linkar com as bibliotecas da SFML
target_link_libraries(sfml-app sfml-graphics sfml-window sfml-system)

# Exibir mensagens úteis
message(STATUS "Source files: ${SOURCES}")
message(STATUS "Include dir: ${INCLUDE_DIR}")
