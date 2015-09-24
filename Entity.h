#pragma once
#include <SFML/Graphics.hpp>
#include "SceneNode.h"
class Entity : public SceneNode
{
public:
    void setVelocity(const sf::Vector2f& velocity);
    void setVelocity(float x, float y);
    sf::Vector2f getVelocity() const;

private:
    virtual void updateCurrent(sf::Time dt);
    sf::Vector2f mVelocity;
};