#include <memory>
#include <SFML\Graphics.hpp>
#include "World.h"
#include "SpriteNode.h"

CommandQueue& World::getCommandQueue()
{
    return mCommandQueue;
}

World::World(sf::RenderWindow& window)
    : mWindow(window)
    , mWorldView(window.getDefaultView())
    , mTextures()
    , mSceneGraph()
    , mSceneLayers()
    , mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
    , mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
    , mScrollSpeed(-50.f)
{
    loadTextures();
    buildScene();

    // Prepare the view
    mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{

    while (!mCommandQueue.isEmpty())
    {
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);
    }
    /*
    sf::Vector2f velocity = mPlayerAircraft->getVelocity();

    if (velocity.x != 0.f && velocity.y != 0.f)
    {
        mPlayerAircraft->setVelocity(velocity / std::sqrt(2.f));
    }

    mPlayerAircraft->accelerate(sf::Vector2f(0.f, mScrollSpeed));

    // Apply movements
    mSceneGraph.update(dt);

    // Keep player's position inside the screen bounds, at least borderDistance units from the border
    sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
    const float borderDistance = 40.f;

    sf::Vector2f position = mPlayerAircraft->getPosition();
    position.x = std::max(position.x, viewBounds.left + borderDistance);
    position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
    position.y = std::max(position.y, viewBounds.top + borderDistance);
    position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
    mPlayerAircraft->setPosition(position.x, position.y);
    */
}

void World::draw()
{
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{

    mTextures.load(Textures::FULL_TOWER_TILE, "GrassFull.png");
    mTextures.load(Textures::FULL_WALK_TILE, "SandFull.png");
    mTextures.load(Textures::NE_TILE, "GrassNE.png");
    mTextures.load(Textures::NW_TILE, "GrassNW.png");
    mTextures.load(Textures::SW_TILE, "GrassSW.png");
    mTextures.load(Textures::SE_TILE, "GrassSE.png");
}

void World::buildScene()
{
    
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        SceneNode::Ptr layer(new SceneNode());
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }
    
    
    // Prepare the tiled background
    sf::Texture& texture = mTextures.get(Textures::FULL_WALK_TILE);
    sf::IntRect textureRect(mWorldBounds);
    texture.setRepeated(1);

    // Add the background sprite to the scene
    std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
    backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
    mSceneLayers[Walkable]->attachChild(std::move(backgroundSprite));
    /*
    // Add player's aircraft
    std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle, mTextures));
    mPlayerAircraft = leader.get();
    mPlayerAircraft->setPosition(mSpawnPosition);
    mPlayerAircraft->setVelocity(40.f, mScrollSpeed);
    mSceneLayers[Air]->attachChild(std::move(leader));

    // Add two escorting aircrafts, placed relatively to the main plane
    std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Raptor, mTextures));
    leftEscort->setPosition(-80.f, 50.f);
    mPlayerAircraft->attachChild(std::move(leftEscort));

    std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Raptor, mTextures));
    rightEscort->setPosition(80.f, 50.f);
    mPlayerAircraft->attachChild(std::move(rightEscort));
    */

}