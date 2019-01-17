#cmake for the project
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

SET(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/SFML)
find_package(SFML 2.5 COMPONENTS window system graphics REQUIRED)
add_executable (BuilCityGame "src/Main.cpp" "src/Main.h" "src/Resources.cpp" "src/Resources.h" "src/Settings.cpp" "src/Settings.h" "src/Camera.h" "src/Camera.cpp" src/Gui.cpp src/Gui.h src/ViewLayer.cpp src/ViewLayer.h)
target_link_libraries(BuilCityGame sfml-window sfml-system sfml-graphics)
