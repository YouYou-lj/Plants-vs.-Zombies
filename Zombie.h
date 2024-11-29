#pragma once

#include <easyx.h>
#include "Vec2.h"
#include "Animation.h"
#include "Rect.h"

class Zombie {
private:
    Zombie() = default;
    Zombie(Zombie&) = default;

public:
    static Zombie* create();
    static Zombie* create(const char* filename);
    bool init();
    void drawTick();
    void eventTick(float delta);

public:
    bool setImage(const char* filename);

    void setPosition(const Vec2& pos) {
        m_Position = pos;
    }

    void setAnimation(Animation* anim) {
        m_Animation = anim;
    }

    void setAttackAnimation(Animation* anim) {
        m_AttackAnimation = anim;
    }

    void startAnimation(bool isStartAnim = true) {
        m_IsStartAnim = isStartAnim;
    }

    Rect getBoundingBox() {
        return Rect(m_Position.x, m_Position.y, m_Image.getwidth(), m_Image.getheight());
    }

    void setIsMove(bool isMove) {
        if (isMove != m_IsMove) {
            m_AnimIndex = 0;
            m_AnimCount = 0.0f;
        }

        m_IsMove = isMove;
    };

private:
    IMAGE m_Image;
    Vec2 m_Position;
    Animation* m_Animation;
    Animation* m_AttackAnimation;
    bool m_IsStartAnim = false;
    int m_AnimIndex = 0;
    float m_AnimCount = 0.0f;
    bool m_IsMove = true;
};
