#pragma once

#include <easyx.h>
#include "Vec2.h"
#include "Animation.h"

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

    void setAnimation (Animation* anim) {
        m_Animation = anim;
    }

    void startAnimation(bool isStartAnim = true) {
        m_IsStartAnim = isStartAnim;
    }

private:
    IMAGE m_Image;
    Vec2 m_Positon;
    Animation* m_Animation;
    bool m_IsStartAnim = false;
    int m_AnimIndex = 0;
    float m_AnimCount = 0.0f;
};
