#pragma once

#include "Entity.h"
#include "Command.h"
#include "CommandQueue.h"
#include "ResourceIdentifiers.h"
#include "TextNode.h"

#include <SFML/Graphics/Sprite.hpp>


class Mob : public Entity
{
public:
    enum Type
    {
        PROTOMAN,
        NUMBER_OF_MOB_TYPES
    };


public:
    Mob(Type type, const TextureHolder& textures, const FontHolder& fonts);

    virtual unsigned int	getCategory() const;
    virtual sf::FloatRect	getBoundingRect() const;
    virtual bool 			isMarkedForRemoval() const;
    float					getSpeed() const;


private:
    virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void 			updateCurrent(sf::Time dt, CommandQueue& commands);
    void					updateMovementPattern(sf::Time dt);

    void					updateTexts();


private:
    Type					mType;
    sf::Sprite				mSprite;

    std::size_t				mDirectionIndex;
    TextNode*				mHealthDisplay;
};
