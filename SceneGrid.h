#pragma once
#include <ratio>
#include <memory>
#include "Command.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <array>


class SceneGrid :public sf::Transformable, public sf::Drawable, private sf::NonCopyable 
{
public:
    typedef std::unique_ptr<SceneGrid> Ptr;


public:
    SceneGrid();

    void                    onCommand(const Command& command, sf::Time dt);
    void					attachChild(Ptr child);
    Ptr						detachChild(const SceneNode& node);

    void					update(sf::Time dt);

    sf::Vector2f			getWorldPosition() const;
    sf::Transform			getWorldTransform() const;


private:
    virtual void			updateCurrent(sf::Time dt);
    void					updateChildren(sf::Time dt);

    virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void					drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    std::array<Tile<int>, 12> mTilemap;
};