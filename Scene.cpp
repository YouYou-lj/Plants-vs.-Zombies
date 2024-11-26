#include "Scene.h"

Scene *Scene::create() {
    Scene* scene = new Scene;

    if (scene->init()) {
        return scene;
    }

    delete scene;
    return nullptr;
}

bool Scene::init() {
    loadimage(&m_BackgroundImg, "D:/CLion 2024.2.2/Plants vs. Zombies/assets/DaytimeScene.png");

     return true;
}

void Scene::drawTick() {

}

void Scene::eventTick(float delta) {

}



