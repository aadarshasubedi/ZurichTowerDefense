#pragma once
#include "typedefs.h"
#include "Orientation.h"
#include "ResourceIdentifiers.h"
#include "ResourceMap.hpp"
#include <memory>
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include "MobData.h"

class SceneGrid;

namespace TileAttributes
{
    enum class Orientation : uint8
    {
        NE,
        NW,
        SE,
        SW,
        FULL
    };

    enum class Type : uint8
    {
        Path,
        Scenery,
        Tower,
        Spawn
    };

    struct Coordinate
    {
        uint32 x;
        uint32 y;
    };
};

class Tile
{
private:
    TileAttributes::Orientation mOrientation;
    TileAttributes::Type        mType;
    TileAttributes::Coordinate  mCoordinates;
    std::unique_ptr<Tower>      mEntity;
    sf::Sprite                  mSprite;
    std::vector<TileAttributes::Coordinate> mPathToEnd;

    
public:
    Tile();
    Tile(const TileAttributes::Orientation orientation, const TileAttributes::Type type, const sf::Sprite sprite, uint32 x, uint32 y);
    Tile(const Tile &);
    Tile & operator=(const Tile & other);
    Tile & operator=(Tile && other);

    const TileAttributes::Orientation getOrientation() const;
    const TileAttributes::Type        getType() const;

    void findPath(SceneGrid& grid);

    sf::Sprite& getSprite();
    const sf::Sprite& getSprite() const;
    void Tile::setEntity(std::unique_ptr<Tower>&& other);

};
