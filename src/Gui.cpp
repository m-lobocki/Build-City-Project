#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>
#include "Gui.h"
#include "Resources.h"

Gui::Gui(sf::Vector2f resolution) : ViewLayer(resolution)
{
    on_resize(resolution);
}

void Gui::on_tick(float delta_time, sf::Vector2i mouse_position)
{
    is_mouse_over_gui = false;
    for (auto& [_,component] : components)
    {
        if(component->collision(mouse_position))
        {
            is_mouse_over_gui = true;
            component->on_mouse_over(mouse_position);
        }
    }
}

void Gui::on_resize(sf::Vector2f game_resolution)
{
    view = generate_view(game_resolution);
}

void Gui::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto& [_,component] : components)
    {
        target.draw(*component);
    }
}

void Gui::add_component(const std::shared_ptr<GuiComponent>& component)
{
    components[component->name] = component;
}

void Gui::delete_component(const std::string &component_name)
{
    components.erase(components.find(component_name));
}

bool Gui::is_mouse_over()
{
    return is_mouse_over_gui;
}
