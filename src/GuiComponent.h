#pragma once

#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include "Resources.h"

class GuiComponent : public sf::Drawable
{
public:
    FontWeight font_weight = FontWeight::Regular;
    unsigned int font_size = 16U;
    sf::Color background = sf::Color::Blue;
    sf::Color foreground = sf::Color::White;
    sf::Vector2f position = sf::Vector2f(0,0);
    sf::Vector2f size = sf::Vector2f(0,0);
    std::string name;
    sf::FloatRect get_collision_box();
    bool collision(sf::Vector2i mouse_position);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    virtual void on_mouse_over(sf::Vector2i mouse_position);
    explicit GuiComponent(const std::string& name);
};