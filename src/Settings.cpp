#include "Settings.h"

Settings::Settings(sf::Vector2f game_resolution) : game_resolution(game_resolution)
{
}

sf::VideoMode Settings::game_resolution_mode()
{
	return sf::VideoMode(game_resolution.x, game_resolution.y);
}
