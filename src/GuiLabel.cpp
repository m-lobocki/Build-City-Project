#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include "GuiLabel.h"

GuiLabel::GuiLabel(const std::string& name, const std::string& text, unsigned font_size, FontWeight font_weight) : text(text), GuiComponent::GuiComponent(name)
{
    this->font_size = font_size;
    this->font_weight = font_weight;
}

void GuiLabel::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Font& font = Resources::get_font(font_weight);
    sf::Text text(this->text, font, font_size);
    text.setFillColor(foreground);
    auto size = this->size;
    if(size == sf::Vector2f(0,0))
    {
        auto dimension = text.getLocalBounds();
        size = sf::Vector2f(dimension.width, dimension.height * 1.4f);
    }
    sf::RectangleShape background(size);
    background.setFillColor(this->background);

    target.draw(background);
    target.draw(text);
}

void GuiLabel::set_text(const std::string &text)
{
    this->text = text;
}
