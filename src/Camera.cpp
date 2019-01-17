#include "Camera.h"

Camera::Camera(std::shared_ptr<Settings>& settings_ptr)
{
	this->settings_ptr = settings_ptr;
	view = sf::View(sf::FloatRect(sf::Vector2f(0, 0), settings_ptr->game_resolution));
	set_game_resolution(settings_ptr->game_resolution);
}

/// called every tick
sf::View Camera::refresh(sf::Vector2i mouse_position, float mouse_wheel_delta)
{
	follow_mouse(mouse_position, mouse_wheel_delta);
	refresh_clock.restart();
	return view;
}

void Camera::follow_mouse(sf::Vector2i mouse_position, float mouse_wheel_delta)
{
	float dt = refresh_clock.getElapsedTime().asSeconds();
	for (auto [rectangle, movement_vector] : camera_movement_triggers)
	{
		if(rectangle.contains(mouse_position))
		{
			view.move(movement_vector * dt);
		}
	}
	if(mouse_wheel_delta > 0)
	{
		view.zoom(0.99f);
	}
	else if(mouse_wheel_delta < 0)
	{
		view.zoom(1.01f);
	}
}

sf::Vector2f Camera::get_position()
{
	return view.getCenter();
}

void Camera::set_game_resolution(sf::Vector2f game_resolution)
{
	camera_movement_triggers[Left] = std::make_tuple(sf::IntRect(int(game_resolution.x - border_offset), 0, border_offset, int(game_resolution.y)), sf::Vector2f(movement_speed, 0));
	camera_movement_triggers[Right] = std::make_tuple(sf::IntRect(0, 0, border_offset, int(game_resolution.y)), sf::Vector2f(-movement_speed, 0));
	camera_movement_triggers[Top] = std::make_tuple(sf::IntRect(0, 0, int(game_resolution.x), border_offset), sf::Vector2f(0, -movement_speed));
	camera_movement_triggers[Bottom] = std::make_tuple(sf::IntRect(0, int(game_resolution.y) - border_offset, int(game_resolution.x), border_offset), sf::Vector2f(0, movement_speed));
	view.setSize(game_resolution);
}

void Camera::update_resolution()
{
	set_game_resolution(settings_ptr->game_resolution);
}
