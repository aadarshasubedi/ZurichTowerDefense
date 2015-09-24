#include "Entity.h"

void Entity::setVelocity(const sf::Vector2f& velocity)
{
    mVelocity = velocity;
}

void Entity::setVelocity(float x, float y)
{
    setVelocity(sf::Vector2f(x, y));
}

sf::Vector2f Entity::getVelocity() const
{
    return mVelocity;
}

void Entity::updateCurrent(sf::Time dt)
{
    move(mVelocity*dt.asSeconds());
}
