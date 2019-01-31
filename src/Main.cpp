#include "Main.h"

int main()
{
	Resources::load_fonts();
	Resources::load_assets();

	auto maximized_mode =  sf::VideoMode::getFullscreenModes()[0];
	sf::Vector2f resolution = sf::Vector2f(maximized_mode.width, maximized_mode.height);

	Map map(resolution, 24, 18);
	Camera camera(resolution);
	Gui gui(resolution);
	sf::Clock tick_clock;
	create_window(maximized_mode, gui);

	while (window->isOpen())
	{
		sf::Event event{};
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			if (event.type == sf::Event::Resized)
			{
                resolution = sf::Vector2f(event.size.width, event.size.height);
				camera.update_resolution(resolution);
				gui.update_resolution(resolution);
                toolbox_panel->resize(resolution);
			}
		}

		sf::Vector2i mouse_position = sf::Mouse::getPosition(*window);
		float delta_time = tick_clock.restart().asSeconds();
		sf::Vector2i pixel_position = camera.get_pixel_position(*window, mouse_position);
		window->clear();

		map.set_omit_highlight(gui.is_mouse_over());
		window->setView(map.refresh(delta_time, pixel_position));
		window->setView(camera.refresh(delta_time, mouse_position));
		window->draw(map);

		window->setView(gui.refresh(delta_time, mouse_position));
		sf::Vector2f player_position = camera.get_position();
		position_label->set_text("X: " + std::to_string(int(player_position.x)) + ",Y: " + std::to_string(int(player_position.y)));
		window->draw(gui);
		window->display();
	}
	return 0;
}

void create_window(sf::VideoMode video_mode, Gui& gui)
{
	window = std::make_shared<sf::RenderWindow>(video_mode, "BuildCityProject");
	window->setFramerateLimit(60);

	position_label = std::make_shared<GuiLabel>(GuiLabel("position_label"));
	gui.add_component(position_label);

	toolbox_panel = std::make_shared<GuiTabPanel>(GuiTabPanel("toolbox"));
	toolbox_panel->add_tab(Tab("tab1", Asset::HouseIcon, GuiComponent("content1")));
	toolbox_panel->add_tab(Tab("tab2", Asset::FactoryIcon, GuiComponent("content2")));
	toolbox_panel->add_tab(Tab("tab3", Asset::PowerIcon, GuiComponent("content3")));
	toolbox_panel->add_tab(Tab("tab4", Asset::WaterIcon, GuiComponent("content4")));
	toolbox_panel->add_tab(Tab("tab5", Asset::WasteIcon, GuiComponent("content5")));
	toolbox_panel->add_tab(Tab("tab6", Asset::EducationIcon, GuiComponent("content6")));
	toolbox_panel->add_tab(Tab("tab7", Asset::FireStationIcon, GuiComponent("content7")));
	toolbox_panel->add_tab(Tab("tab8", Asset::PoliceIcon, GuiComponent("content8")));
	toolbox_panel->add_tab(Tab("tab9", Asset::HospitalIcon, GuiComponent("content9")));
	toolbox_panel->add_tab(Tab("tab10", Asset::ParkIcon, GuiComponent("content10")));
	gui.add_component(toolbox_panel);
}
