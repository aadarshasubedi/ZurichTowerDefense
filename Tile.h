#pragma once
#include "typedefs.h"
#include "Orientation.h"
#include "ResourceIdentifiers.h"
#include "ResourceMap.hpp"
#include <memory>

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

template<typename T>
class Tile
{
private:
    TileAttributes::Orientation mOrientation;
    TileAttributes::Type mType;
    std::unique_ptr<T> mEntity;
    TextureHolder& mTextureMap;
public:
    Tile(TileAttributes::Orientation, TileAttributes::Type, TextureHolder&);

    Tile operator=(const Tile& other);

    sf::Texture& getTexture(Textures::ID);

    void setEntity(std::unique_ptr<T>&&);

    bool isWalkable();

    bool isBuildable();

};
