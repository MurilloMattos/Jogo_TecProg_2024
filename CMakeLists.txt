cmake_minimum_required(VERSION 3.10.0)
project(JOGO_TECPROG_2024 VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SOURCES "Jogo_TecProg_2024/*.cpp")
file(GLOB_RECURSE HEADER_FILES "Jogo_TecProg_2024/*.h" "Jogo_TecProg_2024/*.hpp")

set(INCLUDE_DIRECTORIES "")

foreach(HEADER_FILE ${HEADER_FILES})
    get_filename_component(DIR ${HEADER_FILE} DIRECTORY)
    list(APPEND INCLUDE_DIRECTORIES ${DIR})
endforeach()

list(REMOVE_DUPLICATES INCLUDE_DIRECTORIES)

add_executable(JOGO_TECPROG_2024 ${SOURCES})

target_include_directories(JOGO_TECPROG_2024 PUBLIC ${INCLUDE_DIRECTORIES})
target_include_directories(JOGO_TECPROG_2024 PUBLIC "SFML-2.5.1/include")

target_link_directories(JOGO_TECPROG_2024 PUBLIC "libs/SFML/lib")

target_link_directories(JOGO_TECPROG_2024 PUBLIC "SFML-2.5.1/lib")
target_link_libraries(JOGO_TECPROG_2024
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    sfml-network
)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
