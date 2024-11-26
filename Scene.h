#ifndef SCENE_H
#define SCENE_H

#endif //SCENE_H
#include <easyx.h>

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

};
