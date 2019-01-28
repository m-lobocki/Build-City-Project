#pragma once

#include "Resources.h"
#include "GuiComponent.h"
#include "Highlightable.h"

class Tab : public GuiComponent, public Highlightable
{
    const float icon_scale = 0.8f;
    Asset icon;
    GuiComponent content;
public:
    Tab(const std::string& name, Asset icon, GuiComponent content);
    Asset get_icon();
    GuiComponent get_content();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};