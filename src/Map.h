#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Tile.h"
#include "ViewLayer.h"

class Map : public ViewLayer, public sf::Drawable
{
private:
    sf::Vector2i previous_hover_coords;
    std::vector<std::vector<Tile>> tiles;
    Tile road_hub;
    int rows;
    int columns;
    bool omit_highlight;
protected:
    void on_tick(float delta_time, sf::Vector2i mouse_position) override;
    void on_resize(sf::Vector2f game_resolution) override;
public:
    Map(sf::Vector2f resolution, int rows, int columns);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void set_omit_highlight(bool omit_highlight);
};