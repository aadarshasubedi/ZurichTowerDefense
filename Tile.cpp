#include "Tile.h"
#include <utility>
#include "SceneGrid.h"

using namespace std;

Tile::Tile()
    : mOrientation(TileAttributes::Orientation::FULL), mType(TileAttributes::Type::Tower), mEntity(nullptr), mSprite()
{
}

Tile::Tile(const Tile &other)
{
    mOrientation = other.mOrientation;
    mType = other.mType;
    mCoordinates = other.mCoordinates;
}

Tile::Tile(const TileAttributes::Orientation orientation, const TileAttributes::Type type, const sf::Sprite sprite, uint32 x, uint32 y)
    : mOrientation(orientation), mType(type), mEntity(nullptr), mSprite(sprite), mCoordinates{ x, y}
{
}

Tile & Tile::operator=(Tile && other)
{
    mOrientation = other.mOrientation;
    mType        = other.mType;
    mEntity      = move(other.mEntity);
    mSprite      = other.mSprite;
    mCoordinates = other.mCoordinates;
    return *this;
}
Tile & Tile::operator=(const Tile & other)
{
    mOrientation = other.mOrientation;
    mType = other.mType;
    mSprite = other.mSprite;
    mCoordinates = other.mCoordinates;
    return *this;
}


const TileAttributes::Orientation Tile::getOrientation() const
{
    return mOrientation;
}

const TileAttributes::Type Tile::getType() const
{
    return mType;
}

void Tile::findPath(SceneGrid & grid)
{
}

sf::Sprite & Tile::getSprite()
{
    return mSprite;
}

const sf::Sprite & Tile::getSprite() const
{
    return mSprite;
}

void Tile::setEntity(std::unique_ptr<Tower>&& universalRef)
{
    mEntity = move_if_noexcept(universalRef);
}

