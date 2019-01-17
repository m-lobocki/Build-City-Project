#pragma once
#include "SFML/Window/VideoMode.hpp"
#include "SFML/System/Vector2.hpp"

class Settings
{
public:
	sf::Vector2f game_resolution;
	Settings(sf::Vector2f game_resolution);
	sf::VideoMode game_resolution_mode();
};
