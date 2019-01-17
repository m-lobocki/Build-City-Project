#pragma once

#include <memory>
#include <SFML/Graphics/View.hpp>
#include "Settings.h"

class ViewLayer
{
    sf::View view;
    const std::shared_ptr<Settings> settings_ptr;
public:
    ViewLayer(std::shared_ptr<Settings>& settings_ptr);
    virtual sf::View refresh(sf::Vector2i mouse_position, float mouse_wheel_delta);
    virtual void update_resolution();
};