#include "Map.h"
#include <iostream>

Map::Map(sf::Vector2f resolution, int columns, int rows) : ViewLayer(resolution), columns(columns), rows(rows)
{
    int size = Tile::tile_size;
    view = sf::View(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(columns, rows)));
    tiles = std::vector<std::vector<Tile>>(unsigned(columns), std::vector<Tile>(unsigned(rows)));
    road_hub = Tile(sf::Vector2f(-size, rows/2.f*size), sf::Vector2f(size-1, size-1), "X");
    road_hub.set_fill_color(sf::Color(64,64,64));

    int count = 0;
    for(int column = 0, pos_x = 0; column < columns; column++, pos_x += size)
    {
        for (int row = 0, pos_y = 0; row < rows; row++, pos_y += size)
        {
            Tile tile(sf::Vector2f(pos_x, pos_y), sf::Vector2f(size,size), std::to_string(++count));
            tiles[column][row] = tile;
        }
    }
}

void Map::on_resize(sf::Vector2f game_resolution) {}

void Map::on_tick(float delta_time, sf::Vector2i mouse_position)
{
    sf::Vector2i tile_coords(mouse_position.x/Tile::tile_size, mouse_position.y/Tile::tile_size);
    if(!omit_highlight && tile_coords.x >= 0 && tile_coords.y >= 0 && tile_coords.x < columns && tile_coords.y < rows)
    {
        tiles[previous_hover_coords.x][previous_hover_coords.y].reset_background();
        tiles[tile_coords.x][tile_coords.y].highlight();
        previous_hover_coords = tile_coords;
    }
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(road_hub);
    for(int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            target.draw(tiles[i][j]);
        }
    }
}

void Map::set_omit_highlight(bool omit_highlight)
{
    this->omit_highlight = omit_highlight;
}
