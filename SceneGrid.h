#pragma once
#include <ratio>
#include <memory>
#include "Command.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <array>
#include "Constants.h"
#include "Tower.h"

class SceneGrid : public sf::Drawable
{

public:
    SceneGrid(const TextureHolder& th);
    SceneGrid(const SceneGrid& other) = delete;
    void SceneGrid::LoadFromFile(const std::string & inputFilename);
    Tile& SceneGrid::getTile(const uint32 rowIndex, const uint32 columnIndex);
    const Tile& SceneGrid::getTile(const uint32 rowIndex, const uint32 columnIndex) const;
    // Inherited via Drawable
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
    TextureHolder& mTextures;
    std::vector<std::vector<Tile>> mGrid;
};
