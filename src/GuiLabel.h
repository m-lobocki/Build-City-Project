#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include "GuiComponent.h"

class GuiLabel : public GuiComponent
{
    std::string text;
public:
    explicit GuiLabel(const std::string& name, const std::string& text = "", unsigned font_size = 16U, FontWeight font_weight = FontWeight::Regular);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void set_text(const std::string& text);
};