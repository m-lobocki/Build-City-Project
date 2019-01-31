#pragma once

#include <SFML/Graphics/RenderStates.hpp>
#include "GuiComponent.h"
#include "Resources.h"
#include "Tab.h"

class GuiTabPanel : public GuiComponent
{
    std::vector<Tab> tabs;
    float current_x;
    const sf::Vector2f tab_size = sf::Vector2f(52, 52);
    const float panel_height = 250;
public:
    GuiTabPanel(const std::string& name);
    void add_tab(Tab tab);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void resize(sf::Vector2f new_resolution);
    void on_mouse_over(sf::Vector2i mouse_position) override;
};