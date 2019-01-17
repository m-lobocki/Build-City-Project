#pragma once
#include <tuple>
#include <iostream>
#include "SFML/Graphics/View.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"
#include "Settings.h"

class Camera
{
	const float movement_speed = 0.5;
	const int border_offset = 50;
	std::tuple<sf::IntRect, sf::Vector2f> camera_movement_triggers[4];
	sf::View view;
	std::shared_ptr<Settings> settings_ptr;
public:
	enum Direction
	{
		None = -1, Left = 0, Right = 1, Top = 2, Bottom = 3
	};
	Camera(std::shared_ptr<Settings>& settings_ptr);

	sf::View get_view();
	void follow_mouse(sf::Vector2i mouse_position);
	sf::Vector2f get_position();
	void set_game_resolution(sf::Vector2f game_resolution);
	void refresh_resolution();
};
