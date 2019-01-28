#include "Highlightable.h"

Highlightable::Highlightable(sf::Color default_background, sf::Color highlight_background)
    : default_background(default_background), highlight_background(highlight_background)
{
    background = default_background;
}

void Highlightable::highlight()
{
    background = highlight_background;
}

void Highlightable::unhighlight()
{
    background = default_background;
}
