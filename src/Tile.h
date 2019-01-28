#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class Tile : public sf::Drawable
{
private:
    sf::Vector2f size;
    sf::Text text;
    sf::RectangleShape shape;
    sf::Color default_background = sf::Color::Green;
public:
    Tile();
    Tile(sf::Vector2f position, sf::Vector2f size, std::string text);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    static const int tile_size = 64;
    void set_fill_color(sf::Color color);
    void highlight();
    void reset_background();
};