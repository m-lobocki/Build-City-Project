#cmake for the project
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

set(SFML_STATIC TRUE)
set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/SFML)
find_package(SFML 2.5 COMPONENTS window system graphics REQUIRED)
add_executable (BuilCityGame "src/Main.cpp" "src/Main.h" "src/Resources.cpp" "src/Resources.h" "src/Camera.h" "src/Camera.cpp" src/Gui.cpp src/Gui.h src/ViewLayer.cpp src/ViewLayer.h src/GuiComponent.cpp src/GuiComponent.h src/GuiLabel.cpp src/GuiLabel.h src/Map.cpp src/Map.h src/Tile.cpp src/Tile.h src/River.cpp src/River.h src/GuiTabPanel.cpp src/GuiTabPanel.h src/Tab.cpp src/Tab.h src/Highlightable.cpp src/Highlightable.h)
target_link_libraries(BuilCityGame sfml-window sfml-system sfml-graphics)
