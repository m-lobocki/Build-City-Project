#pragma once

#include "ViewLayer.h"
#include "GuiComponent.h"

class Gui : public ViewLayer, public sf::Drawable
{
    bool is_mouse_over_gui;
protected:
    void on_tick(float delta_time, sf::Vector2i mouse_position) override;
    void on_resize(sf::Vector2f game_resolution) override;
public:
    Gui(sf::Vector2f resolution);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    std::map<std::string, std::shared_ptr<GuiComponent>> components;
    void add_component(const std::shared_ptr<GuiComponent>& component);
    void delete_component(const std::string& component_name);
    bool is_mouse_over();
};