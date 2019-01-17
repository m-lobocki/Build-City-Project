#pragma once
#include <tuple>
#include <iostream>
#include <memory>
#include "SFML/Graphics/View.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"
#include "Settings.h"

class Camera
{
	const float movement_speed = 150;
	const int border_offset = 50;
    sf::Clock refresh_clock;
    sf::View view;
    std::tuple<sf::IntRect, sf::Vector2f> camera_movement_triggers[4];
	std::shared_ptr<Settings> settings_ptr;
    void set_game_resolution(sf::Vector2f game_resolution);
    void follow_mouse(sf::Vector2i mouse_position, float mouse_wheel_delta);
public:
	enum Direction
	{
		Left = 0, Right = 1, Top = 2, Bottom = 3
	};
	Camera(std::shared_ptr<Settings>& settings_ptr);

	sf::View refresh(sf::Vector2i mouse_position, float mouse_wheel_delta);
	sf::Vector2f get_position();
	void update_resolution();
};
