#pragma once
namespace sf
{
    class Texture;
    class Font;
}

namespace Textures
{
    enum ID
    {

        NE_TILE,
        NW_TILE,
        SE_TILE,
        SW_TILE,
        FULL_TOWER_TILE,
        FULL_WALK_TILE,
        SPAWN_TILE,

        MAX_NUMBER_OF_TILES,

        TitleScreen,
        ButtonNormal,
        ButtonSelected,
        ButtonPressed
    };
}

namespace Fonts
{
    enum ID
    {
        Main,
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>   TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>			FontHolder;
