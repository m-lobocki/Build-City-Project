# CMakeList.txt : CMake project for Build-City-Project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable (Build-City-Project "src/Main.cpp" "src/Main.h")

# TODO: Add tests and install targets if needed.
