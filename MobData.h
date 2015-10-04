#pragma once
#include "ResourceIdentifiers.h"
#include <vector>

struct Direction
{
    Direction(float angle, float distance);
    float angle;
    float distance;
};

struct MobData
{
    int hitpoints;
    float speed;
    Textures::ID texture;
};

enum class MobIdentifier
{
    PROTOMAN,
    NUMBER_OF_MOBS
};
