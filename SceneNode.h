#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include <memory>

#include "SceneNode.h"
#include "Command.h"

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;


public:
    SceneNode();

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
    std::vector<Ptr>		mChildren;
    SceneNode*				mParent;
};