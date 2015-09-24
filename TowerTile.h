#pragma once
#include "Tile.h"
#include "Orientation.h"

class Tower;

namespace Tile
{
    class TowerTile : public Tile
    {
    private:

    public:
        TowerTile(Orientation);
        void attachTowerEntity(std::unique_ptr<Tower>&&);

    };

}