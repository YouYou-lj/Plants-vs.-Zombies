#pragma once

#include <easyx.h>
#include "Vec2.h"

class Plant {
private:
    Plant() = default;
    Plant(Plant&) = default;

public:
    static Plant* create();
    static Plant* create(const char* filename);

    bool init();
    void drawTick();
    void eventTick(float delta);

public:
    bool setImage(const char* filename);

    void setPosition(const Vec2& pos) {
        m_Positon = pos;
    }

private:
    IMAGE m_Image;
    Vec2 m_Positon;
};
