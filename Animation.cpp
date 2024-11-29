#include "Animation.h"

Animation* Animation::create() {
    return new Animation;
}

void Animation::addImage(const char* filename) {
    IMAGE img;
    loadimage(&img, filename);
    m_ImageArray.push_back(img);
}

IMAGE* Animation::index(int i) {
    return &m_ImageArray[i];
}
