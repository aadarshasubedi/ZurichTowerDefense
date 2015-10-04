#pragma once
#include "ResourceIdentifiers.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "Utility.h"

class TextNode
{
public:
    explicit TextNode(const FontHolder& fonts, const std::string& text);
    void setString(const std::string& text);

private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Text mText;

};