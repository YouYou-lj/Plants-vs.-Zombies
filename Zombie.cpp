#include "Zombie.h"
#include "Tools.h"

Zombie* Zombie::create() {
    Zombie* zombie = new Zombie;

    if(zombie->init())	{
        return zombie;
    }

    delete zombie;
    return nullptr;
}

Zombie* Zombie::create(const char* filename) {
    Zombie* zombie = new Zombie;

    if (zombie->init() && zombie->setImage(filename)) {
        return zombie;
    }

    delete zombie;
    return nullptr;
}

bool Zombie::init() {
    return true;
}

void Zombie::drawTick() {
    if (m_IsStartAnim) {
        if(m_IsMove) {
            Tools::putimage_alpha(m_Position.x, m_Position.y, m_Animation->index(m_AnimIndex));
        } else {
            Tools::putimage_alpha(m_Position.x, m_Position.y, m_AttackAnimation->index(m_AnimIndex));
        }
    } else {
        Tools::putimage_alpha(m_Position.x, m_Position.y, &m_Image);
    }

    Rect rect = getBoundingBox();
    setlinecolor(RED);
    setlinestyle(PS_SOLID, 3);
    rectangle(rect.x, rect.y, rect.x + rect.w, rect.y + rect.h);
}

void Zombie::eventTick(float delta) {
    if (m_IsMove) {
        m_Position.x -= 20.0f * delta;
    }

    m_AnimCount += delta;

    if (m_IsMove) {
        if (m_AnimCount >= m_Animation->getInterval()) {
            m_AnimIndex++;

            if (m_AnimIndex >= m_Animation->count()) {
                m_AnimIndex = 0;
            }

            m_AnimCount -= m_Animation->getInterval();
        }
    } else {
        if (m_AnimCount >= m_AttackAnimation->getInterval()) {
            m_AnimIndex++;

            if (m_AnimIndex >= m_AttackAnimation->count()) {
                m_AnimIndex = 0;
            }

            m_AnimCount -= m_AttackAnimation->getInterval();
        }
    }
}

bool Zombie::setImage(const char* filename) {
    loadimage(&m_Image, filename);
    return true;
}
