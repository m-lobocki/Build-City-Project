#include "Camera.h"

Camera::Camera(sf::Vector2f resolution) : ViewLayer(resolution)
{
	on_resize(resolution);
}

void Camera::on_tick(float delta_time, sf::Vector2i mouse_position)
{
	for (auto [rectangle, movement_vector] : camera_movement_triggers)
	{
		if(rectangle.contains(mouse_position))
		{
			view.move(movement_vector * delta_time);
		}
	}
}

void Camera::on_resize(sf::Vector2f game_resolution)
{
	camera_movement_triggers[Left] = std::make_tuple(sf::IntRect(int(game_resolution.x - border_thickness), 0, border_thickness, int(game_resolution.y)), sf::Vector2f(movement_speed, 0));
	camera_movement_triggers[Right] = std::make_tuple(sf::IntRect(0, 0, border_thickness, int(game_resolution.y)), sf::Vector2f(-movement_speed, 0));
	camera_movement_triggers[Top] = std::make_tuple(sf::IntRect(0, 0, int(game_resolution.x), border_thickness), sf::Vector2f(0, -movement_speed));
	camera_movement_triggers[Bottom] = std::make_tuple(sf::IntRect(0, int(game_resolution.y) - border_thickness, int(game_resolution.x), border_thickness), sf::Vector2f(0, movement_speed));
}

sf::Vector2f Camera::get_position()
{
	return view.getCenter();
}
