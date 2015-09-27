#include <memory>
#include <SFML\Graphics.hpp>
#include "World.h"
#include "Constants.h"

CommandQueue& World::getCommandQueue()
{
    return mCommandQueue;
}

World::World(sf::RenderWindow& window)
    : mWindow(window)
    , mWorldView(window.getDefaultView())
    , mTextures()
    , mSceneGrid(mTextures)
    , mSceneLayers()
    , mWorldBounds(0.f, 0.f,  GraphicsConstants::getAbsoluteWidth(), GraphicsConstants::getAbsoluteHeight() )
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

}

void World::draw()
{
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGrid);

}

void World::loadTextures()
{
    mTextures.load(Textures::FULL_TOWER_TILE, "GrassFull.png");
    mTextures.load(Textures::FULL_WALK_TILE,  "SandFull.png");
    mTextures.load(Textures::NE_TILE,         "GrassNE.png");
    mTextures.load(Textures::NW_TILE,         "GrassNW.png");
    mTextures.load(Textures::SW_TILE,         "GrassSW.png");
    mTextures.load(Textures::SE_TILE,         "GrassSE.png");
    mTextures.setAllRepeated();
    mTextures.setAllSmooth();
}

void World::buildScene()
{
    mSceneGrid.LoadFromFile("level.txt");
}