#cmake for the project
cmake_minimum_required (VERSION 3.8)

set(EXE "BuilCityGame")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/SFML)
set(SFML_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(SFML REQUIRED COMPONENTS graphics window system)
include_directories(${SFML_INCLUDE_DIR})

add_executable (EXE "src/Main.cpp" "src/Main.h")

target_link_libraries(EXE ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
