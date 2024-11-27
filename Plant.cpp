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
    Tools::putimage_alpha(m_Positon.x, m_Positon.y, &m_Image);
}

void Plant::eventTick(float delta) {

}

bool Plant::setImage(const char *filename) {
    loadimage(&m_Image, filename);
    return true;
}
