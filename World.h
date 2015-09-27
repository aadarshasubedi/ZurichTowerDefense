#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceMap.hpp"
#include "ResourceIdentifiers.h"
#include <array>
#include "CommandQueue.h"
#include "SceneGrid.h"

class World : private sf::NonCopyable
{
public:
    CommandQueue& getCommandQueue();
    explicit World(sf::RenderWindow& window);
    void update(sf::Time dt);
    void draw();


private:
    void loadTextures();
    void buildScene();

    enum Layer : unsigned char
    {
        Walkable,
        Tower,
        Mob,
        LayerCount
    };
    CommandQueue mCommandQueue;
    sf::RenderWindow& mWindow;
    sf::View mWorldView;
    TextureHolder mTextures;
    SceneGrid mSceneGrid;
    std::array<SceneNode*, LayerCount> mSceneLayers;
    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;

};