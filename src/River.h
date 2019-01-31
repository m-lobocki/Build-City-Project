#pragma once

#include "Tile.h"

class River : public Tile
{
    River(sf::Vector2f position, sf::Vector2f size, std::string& text);
};