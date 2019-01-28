#include "GuiComponent.h"

GuiComponent::GuiComponent(const std::string &name)  : name(name) {}
void GuiComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const {}
void GuiComponent::on_mouse_over(sf::Vector2i mouse_position) {}

sf::FloatRect GuiComponent::get_collision_box()
{
    return sf::FloatRect(position, size);
}

bool GuiComponent::collision(sf::Vector2i mouse_position)
{
    return get_collision_box().contains(sf::Vector2f(mouse_position.x, mouse_position.y));
}
