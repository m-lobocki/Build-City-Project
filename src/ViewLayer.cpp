#include "ViewLayer.h"

ViewLayer::ViewLayer(sf::Vector2f resolution)
{
    view = generate_view(resolution);
}

sf::View ViewLayer::refresh(float delta_time, sf::Vector2i mouse_position)
{
    on_tick(delta_time, mouse_position);
    return view;
}

void ViewLayer::update_resolution(sf::Vector2f new_resolution)
{
    on_resize(new_resolution);
    view.setSize(new_resolution);
}

sf::View ViewLayer::generate_view(sf::Vector2f resolution) {
    return sf::View(sf::FloatRect(sf::Vector2f(0, 0), resolution));
}
