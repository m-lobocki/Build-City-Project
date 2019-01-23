#pragma once

#include <iostream>
#include <SFML/Graphics/View.hpp>

class ViewLayer
{
protected:
    sf::View view;
    sf::View generate_view(sf::Vector2f resolution);
    virtual void on_tick(float delta_time, sf::Vector2i mouse_position) = 0;
    virtual void on_resize(sf::Vector2f game_resolution) = 0;
public:
    ViewLayer(sf::Vector2f resolution);
    sf::View refresh(float delta_time, sf::Vector2i mouse_position);
    void update_resolution(sf::Vector2f new_resolution);
    sf::View get_view();
};
