#include "SceneGrid.h"
#include <fstream>
#include <cassert>
#include "Constants.h"
#include "Tile.h"
#include <array>

using namespace std;


SceneGrid::SceneGrid(const TextureHolder & th)
    : mTextures(const_cast<TextureHolder&>(th)),
    mGrid(GraphicsConstants::game_tiles_per_row, vector<Tile>(GraphicsConstants::game_tiles_per_column))
{
}

void SceneGrid::LoadFromFile(const std::string & inputFilename)
{
    ifstream inputStream(inputFilename);
    string line;
    uint32 rowIndex = 0;

    using namespace Textures;

    while (getline(inputStream, line))
    {
        uint32 colIndex = 0;
        assert(line.size() == GraphicsConstants::game_tiles_per_row);
        for (auto character : line)
        {
            using namespace TileAttributes;

            sf::IntRect rect(colIndex * GraphicsConstants::tile_square_dimension,
                rowIndex * GraphicsConstants::tile_square_dimension,
                GraphicsConstants::tile_square_dimension,
                GraphicsConstants::tile_square_dimension);

            sf::Sprite sprite(mTextures.get(ID::FULL_TOWER_TILE), rect);
            sprite.setPosition(colIndex * GraphicsConstants::tile_square_dimension, rowIndex * GraphicsConstants::tile_square_dimension);
            Orientation orientation = Orientation::FULL;
            Type type = Type::Tower;

            switch (character)
            {
            case '*':
                sprite.setTexture(mTextures.get(ID::FULL_TOWER_TILE));
                break;
            case '#':
                sprite.setTexture(mTextures.get(ID::FULL_WALK_TILE));
                type = Type::Path;
                break;
            case 'q':
                sprite.setTexture(mTextures.get(ID::NW_TILE));
                orientation = Orientation::NW;
                break;
            case 'w':
                sprite.setTexture(mTextures.get(ID::NE_TILE));
                orientation = Orientation::NE;
                break;
            case 'a':
                sprite.setTexture(mTextures.get(ID::SW_TILE));
                orientation = Orientation::SW;
                break;
            case 's':
                sprite.setTexture(mTextures.get(ID::SE_TILE));
                orientation = Orientation::SE;
                break;
            default:
                break;

            }
            getTile(rowIndex, colIndex) = Tile(orientation, type, sprite);
            ++colIndex;
        }
        ++rowIndex;
    }
}

Tile& SceneGrid::getTile(const uint32 rowIndex, const uint32 columnIndex)
{
    return mGrid[columnIndex][rowIndex];
}

const Tile& SceneGrid::getTile(const uint32 rowIndex, const uint32 columnIndex) const
{
    return mGrid[columnIndex][rowIndex];
}

void SceneGrid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto ui = 0; ui < mGrid[0].size(); ++ui)
    {
        for (auto uj = 0; uj < mGrid.size(); ++uj)
        {
            const sf::Sprite& sprite = getTile(ui, uj).getSprite();
            target.draw(sprite, states);
        }
    }
}
