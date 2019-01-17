#pragma once
#include "SFML/Graphics/Font.hpp"

enum FontWeight
{
	Regular = 0,
	Italic = 1,
	Light = 2,
	Bold = 3
};

namespace Resources
{
	bool load_fonts();
	sf::Font get_font(FontWeight weight);
}