#include "ViewLayer.h"

ViewLayer::ViewLayer(std::shared_ptr<Settings>& settings_ptr) : settings_ptr(settings_ptr)
{
    view = sf::View(sf::FloatRect(sf::Vector2f(0, 0), settings_ptr->game_resolution));
}

sf::View ViewLayer::refresh(sf::Vector2i mouse_position, float mouse_wheel_delta)
{
    return view;
}

void ViewLayer::update_resolution()
{
    view.setSize(settings_ptr->game_resolution);
}
