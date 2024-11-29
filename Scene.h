#pragma once

#include <easyx.h>
#include "Plant.h"
#include "Zombie.h"
#include <list>

class Scene {
private:
    Scene() = default;
    Scene(Scene&) = default;

public:
    static Scene* create();

public:
    bool init();
    void drawTick();
    void eventTick(float delta);
    void eventTick(const ExMessage* msg);

private:
    IMAGE m_BackgroundImg;
    Plant* m_PlantTable[5][9];
    Animation* m_ZombieAnimation;
    Animation* m_ZombieAttackAnimation;
    std::list<Zombie*> m_Zombies[5];
    float m_CreateZombieCount = 0.0f;
};
