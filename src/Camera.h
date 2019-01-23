#pragma once

#include <tuple>
#include <SFML/Window.hpp>
#include "SFML/Graphics/View.hpp"
#include "ViewLayer.h"

class Camera : public ViewLayer
{
private:
	const float movement_speed = 250;
	const int border_thickness = 50;
    std::tuple<sf::IntRect, sf::Vector2f> camera_movement_triggers[4];
protected:
	void on_tick(float delta_time, sf::Vector2i mouse_position) override;
	void on_resize(sf::Vector2f game_resolution) override;
public:
	enum Direction
	{
		Left = 0, Right = 1, Top = 2, Bottom = 3
	};
	Camera(sf::Vector2f resolution);
	sf::Vector2f get_position();
	sf::Vector2i get_pixel_position(const sf::RenderWindow& window, sf::Vector2i mouse_position);
};
