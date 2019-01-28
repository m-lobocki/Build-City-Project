#pragma once

#include "SFML/Graphics.hpp"

enum class FontWeight
{
	Regular = 0,
	Italic = 1,
	Light = 2,
	Bold = 3
};

enum class Asset
{
	EducationIcon = 0,
	HospitalIcon = 1,
	FactoryIcon = 2,
	FireStationIcon = 3,
	ParkIcon = 4,
	HouseIcon = 5,
	PowerIcon = 6,
	PoliceIcon = 7,
	WasteIcon = 8,
	WaterIcon = 9
};

namespace Resources
{
	void load_fonts();
	void load_assets();
	sf::Font& get_font(FontWeight weight);
	sf::Texture& get_asset(Asset asset);
	template <class T>
	std::vector<T> load_from_file(const std::string& folder, const std::string& file_extension, std::vector<std::string> filenames);
}
