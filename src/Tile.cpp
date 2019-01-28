#include <iostream>
#include "Tile.h"
#include "Resources.h"

Tile::Tile() = default;

Tile::Tile(sf::Vector2f position, sf::Vector2f size, std::string text)
{
    this->size = size;
    sf::RectangleShape shape(size);
    shape.setPosition(position);
    shape.setFillColor(default_background);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(1);
    this->shape = shape;
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(shape);
}

void Tile::set_fill_color(sf::Color color)
{
    shape.setFillColor(color);
}

void Tile::reset_background()
{
    shape.setFillColor(default_background);
}

void Tile::highlight()
{
    set_fill_color(sf::Color(default_background.r, default_background.g, default_background.b, 200));
}
