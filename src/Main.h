#pragma once

#include <iostream>
#include "SFML/Window/Window.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics.hpp"
#include "Resources.h"
#include "Camera.h"
#include "Gui.h"
#include "Map.h"
#include "GuiLabel.h"
#include "GuiTabPanel.h"
#include "Tab.h"

std::shared_ptr<sf::RenderWindow> window;
std::shared_ptr<GuiLabel> position_label;
std::shared_ptr<GuiTabPanel> toolbox_panel;
void create_window(sf::VideoMode video_mode, Gui& gui);