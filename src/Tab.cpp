#include "Tab.h"

Tab::Tab(const std::string &name, Asset icon, GuiComponent content) : GuiComponent::GuiComponent(name),
    Highlightable::Highlightable(sf::Color(64,64,64,250), sf::Color(100,100,100,250)), content(content)
{
    this->icon = icon;
    this->content = content;
}

void Tab::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape header_background(size);
    header_background.setFillColor(Highlightable::background);
    header_background.setOutlineColor(sf::Color::Black);
    header_background.setOutlineThickness(1);
    header_background.setPosition(position);

    sf::Texture icon_texture = Resources::get_asset(icon);
    icon_texture.setSmooth(true);
    sf::Sprite sprite;
    sprite.setTexture(icon_texture);
    sprite.setScale(icon_scale, icon_scale);
    sprite.move(position + sf::Vector2f((size.x-icon_texture.getSize().x*icon_scale)/2.f,(size.y-icon_texture.getSize().y*icon_scale)/2.f));

    target.draw(header_background);
    target.draw(sprite);
}

Asset Tab::get_icon()
{
    return icon;
}

GuiComponent Tab::get_content()
{
    return content;
}
