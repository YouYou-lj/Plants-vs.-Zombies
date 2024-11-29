#include "Tools.h"
#include "Plant.h"

Plant* Plant::create() {
    Plant* plant = new Plant;

    if (plant->init()) {
        return plant;
    }

    delete plant;
    return nullptr;
}

Plant* Plant::create(const char* filename)
{
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
        Tools::putimage_alpha(m_Position.x, m_Position.y, m_Animation->index(m_AnimIndex));
    } else {
        Tools::putimage_alpha(m_Position.x, m_Position.y, &m_Image);
    }

    Rect rect = getBoundingBox();
    setlinecolor(RED);
    setlinestyle(PS_SOLID, 3);
    rectangle(rect.x, rect.y, rect.x + rect.w, rect.y + rect.h);
}

void Plant::eventTick(float delta) {
    m_AnimCount += delta;

    if (m_AnimCount >= m_Animation->getInterval()) {
        m_AnimIndex++;

        if (m_AnimIndex >= m_Animation->count()) {
            m_AnimIndex = 0;
        }

        m_AnimCount -= m_Animation->getInterval();
    }
}

bool Plant::setImage(const char* filename) {
    loadimage(&m_Image, filename);
    return true;
}
