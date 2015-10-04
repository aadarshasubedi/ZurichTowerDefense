#pragma once

class Entity
{
public:
    explicit Entity(int hitpoints);
    void repair(int points);
    void damage(int poiuts);
    void destroy();

    int getHitpoints() const;
    bool isDestroyed() const;

private:
    int mHitpoints;


};