#include <iostream>
#include "GuiTabPanel.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

GuiTabPanel::GuiTabPanel(const std::string& name) : GuiComponent::GuiComponent(name) {}

void GuiTabPanel::add_tab(Tab tab)
{
    tab.size = tab_size;
    tabs.push_back(tab);
}

void GuiTabPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape background(sf::Vector2f(size.x, size.y - tab_size.y - 1));
    background.setFillColor(sf::Color(64,64,64,240));
    background.setPosition(sf::Vector2f(position.x, position.y + tab_size.y + 1));
    background.setOutlineColor(sf::Color::Black);
    background.setOutlineThickness(1);
    target.draw(background);

    for(auto& tab : tabs)
    {
        target.draw(tab);
    }
}

void GuiTabPanel::resize(sf::Vector2f new_resolution)
{
    current_x = 0;
    size = sf::Vector2f(new_resolution.x,panel_height);
    position = sf::Vector2f(0, new_resolution.y - panel_height);
    for(auto& tab : tabs)
    {
        tab.position = sf::Vector2f(current_x, position.y);
        current_x += tab_size.x;
    }
}

void GuiTabPanel::on_mouse_over(sf::Vector2i mouse_position)
{
    for(auto& tab : tabs)
    {
        if(tab.collision(mouse_position))
        {
            tab.highlight();
        }
        else
        {
            tab.unhighlight();
        }
    }
}
