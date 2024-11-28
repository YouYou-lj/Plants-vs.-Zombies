#include "Plant.h"
#include "Vec2.h"
#include "Tools.h"

Plant *Plant::create() {
    Plant* plant = new Plant;

    if (plant->init()) {
        return plant;
    }

    delete plant;
    return nullptr;
}

Plant *Plant::create(const char *filename) {
    Plant* plant = new Plant;

    if (plant->init() && plant->setImage(filename)) {
        return plant;
    }

    delete plant;
    return nullptr;
}


bool Plant::init() {
    return true;
}

void Plant::drawTick() {
    if (m_IsStartAnim) {
        Tools::putimage_alpha(m_Positon.x, m_Positon.y, m_Animation->index(m_AnimIndex));
    } else {
        Tools::putimage_alpha(m_Positon.x, m_Positon.y, &m_Image);
    }
}

void Plant::eventTick(float delta) {
    m_AnimCount += delta;
    m_Animation->getInterval();

    if (m_AnimCount >= 0.1f) {
        m_AnimIndex++;

        if (m_AnimIndex >= m_Animation->count()) {
            m_AnimIndex = 0;
        }

        m_AnimCount -= 0.1f;
    }
}

bool Plant::setImage(const char *filename) {
    loadimage(&m_Image, filename);
    return true;
}
