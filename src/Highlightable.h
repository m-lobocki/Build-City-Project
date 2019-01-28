#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/System.hpp>

class Highlightable
{
    const sf::Color default_background;
    const sf::Color highlight_background;
protected:
    sf::Color background;
public:
    Highlightable(sf::Color default_background, sf::Color highlight_background);
    void highlight();
    void unhighlight();
};