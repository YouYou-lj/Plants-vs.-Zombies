#pragma once

#include <easyx.h>
#include "Plant.h"
#include "Vec2.h"

class Scene {
private:
    Scene() = default;
    Scene(Scene&) = default;

public:
    static  Scene* create();

public:
    bool init();
    void drawTick();
    void eventTick(float delta);

private:
    IMAGE m_BackgroundImg;

    Plant* m_PlantTable[5][9];
};
