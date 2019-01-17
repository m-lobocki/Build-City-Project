#include "Resources.h"

std::string font_name[] = { "OpenSans-Regular", "OpenSans-Italic", "OpenSans-Light", "OpenSans-Bold" };
sf::Font fonts[4];

bool Resources::load_fonts()
{
	for (int i = 0; i < 4; i++)
	{
		fonts[i] = sf::Font();
		if(!fonts[i].loadFromFile("fonts/" + font_name[i] + ".ttf"))
		{
			return false;
		}
	}
	return true;
}

sf::Font Resources::get_font(FontWeight weight)
{
	return fonts[weight];
}
