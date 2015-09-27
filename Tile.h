#pragma once
#include "typedefs.h"
#include "Orientation.h"
#include "ResourceIdentifiers.h"
#include "ResourceMap.hpp"
#include <memory>
#include <SFML/Graphics.hpp>
#include "Tower.h"

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
        Tower
    };
};

class Tile
{
private:
    TileAttributes::Orientation mOrientation;
    TileAttributes::Type        mType;
    std::unique_ptr<Tower>      mEntity;
    sf::Sprite                  mSprite;
    
public:
    Tile();
    Tile(const TileAttributes::Orientation orientation, const TileAttributes::Type type, const sf::Sprite sprite);
    Tile(const Tile &);
    Tile & operator=(const Tile & other);
    Tile & operator=(Tile && other);

    const TileAttributes::Orientation getOrientation() const;
    const TileAttributes::Type        getType() const;

    sf::Sprite& getSprite();
    const sf::Sprite& getSprite() const;
    void Tile::setEntity(std::unique_ptr<Tower>&& other);

};
