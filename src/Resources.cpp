#include "Resources.h"

//kolejnosc ma znaczenie, polaczone z enum
std::vector<std::string> fonts_names;
std::vector<sf::Font> fonts;
std::vector<std::string> assets_names;
std::vector<sf::Texture> assets;

void Resources::load_fonts()
{
	fonts_names = { "OpenSans-Regular", "OpenSans-Italic", "OpenSans-Light", "OpenSans-Bold" };
	fonts = load_from_file<sf::Font>("fonts", ".ttf", fonts_names);
}

sf::Font& Resources::get_font(FontWeight weight)
{
	return fonts[int(weight)];
}

void Resources::load_assets()
{
	assets_names = { "icons8-graduation-cap-50", "icons8-clinic-50", "icons8-factory-50", "icons8-fire-station-50",
				     "icons8-forest-50", "icons8-home-50", "icons8-lightning-bolt-50", "icons8-police-station-50",
				     "icons8-waste-50", "icons8-water-50" };

	assets = load_from_file<sf::Texture>("assets", ".png", assets_names);
}

sf::Texture& Resources::get_asset(Asset asset)
{
	return assets[int(asset)];
}

template <class T>
std::vector<T> Resources::load_from_file(const std::string& folder, const std::string& file_extension, std::vector<std::string> filenames)
{
	std::vector<T> output;
	for(auto& filename : filenames)
	{
		T target;
		target.loadFromFile(folder + "/" + filename + file_extension);
		output.push_back(target);
	}
	return output;
}
