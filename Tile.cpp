#include "Tile.h"
#include <utility>

using namespace std;

template <typename T>
Tile<T>::Tile(TileAttributes::Orientation orientation, TileAttributes::Type type, TextureHolder& textures)
    : mOrientation(orientation), mType(type), mTextureMap(textures), mEntity(nullptr)
{
}

template<typename T>
sf::Texture & Tile<T>::getTexture(Textures::ID id)
{
    return mTextureMap.get(id);
}

template<typename T>
void Tile<T>::setEntity(std::unique_ptr<T>&& universalRef)
{
    mEntity = move_if_noexcept(universalRef)
}
