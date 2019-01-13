#cmake for the project
cmake_minimum_required (VERSION 3.8)

SET(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/SFML)
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS window system graphics REQUIRED)
add_executable (BuilCityGame "src/Main.cpp" "src/Main.h")
target_link_libraries(BuilCityGame sfml-window sfml-system sfml-graphics)
