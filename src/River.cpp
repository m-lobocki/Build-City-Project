#include "River.h"

River::River(sf::Vector2f position, sf::Vector2f size, std::string& text) : Tile(position, size, text)
{
    this->set_fill_color(sf::Color::Blue);
}
