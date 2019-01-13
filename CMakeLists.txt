# CMakeList.txt : CMake project for Build-City-Project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
set(EXE "BuilCityGame")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/SFML)
set(SFML_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(SFML REQUIRED COMPONENTS graphics window system) # Look for SFML
include_directories(${SFML_INCLUDE_DIR}) # You forgot this line above; add SFML's include dir

add_executable (EXE "src/Main.cpp" "src/Main.h")

target_link_libraries(EXE ${SFML_LIBRARIES} ${SFML_DEPENDENCIES}) # Link SFML
# TODO: Add tests and install targets if needed.
