#include "Main.h"
#ifdef _WIN32
#include <Windows.h>
#endif

int main()
{
	print_working_directory();
	Resources::load_fonts();
	auto settings_ptr = std::make_shared<Settings>(sf::Vector2f(800, 800));

	sf::RenderWindow window(settings_ptr->game_resolution_mode(), "BuildCityProject");
	window.setFramerateLimit(60);
	Camera camera(settings_ptr);

	sf::View map_view(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(1500, 1500)));

	sf::CircleShape shape(400.f);
	shape.setFillColor(sf::Color::Green);

	sf::RectangleShape position_box(sf::Vector2f(150, 30));
	position_box.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		float mouse_wheel_delta = 0;
		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::Resized)
			{
				settings_ptr->game_resolution = sf::Vector2f(event.size.width, event.size.height);
				camera.update_resolution();
			}
			if (event.type == sf::Event::MouseWheelScrolled)
			{
				mouse_wheel_delta = event.mouseWheelScroll.delta;
			}
		}

		window.clear();
		window.setView(map_view);

		sf::Vector2f player_position = camera.get_position();
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		window.setView(camera.refresh(mouse_position, mouse_wheel_delta));
		window.draw(shape);

		sf::View gui_view(sf::FloatRect(sf::Vector2f(0, 0), settings_ptr->game_resolution));
		window.setView(gui_view);
		window.draw(position_box);
		sf::Font font = Resources::get_font(Regular);
		sf::Text position_text("X: " + std::to_string(int(player_position.x)) + ",Y: " + std::to_string(int(player_position.y)), font, 16U);
		window.draw(position_text);

		window.display();
	}
	return 0;
}

void print_working_directory()
{
	//A debug feature
#ifdef _WIN32
	char buffer[1000];
	GetModuleFileName(nullptr, buffer, 1000);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	std::cout << std::string(buffer).substr(0, pos) << std::endl;
#else
	//cos nie dziala
	//std::cout << std::filesystem::current_path() << std::endl;
#endif
}
