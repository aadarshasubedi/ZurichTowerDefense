#include "MobData.h"

Direction::Direction(float _angle, float _distance)
{
    angle = _angle;
    distance = _distance;
}
std::vector<MobData> initializeMobData()
{
    std::vector<MobData> data(static_cast<unsigned>(MobIdentifier::NUMBER_OF_MOBS));

    data[static_cast<unsigned>(MobIdentifier::PROTOMAN)].hitpoints = 100;
    data[static_cast<unsigned>(MobIdentifier::PROTOMAN)].speed = 2.0f;
    data[static_cast<unsigned>(MobIdentifier::PROTOMAN)].texture = Textures::ID::PROTOMAN;

    return data;
}
