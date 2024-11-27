#include "Scene.h"
#include "Vec2.h"

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

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            m_PlantTable[i][j] = Plant::create("D:/CLion 2024.2.2/Plants vs. Zombies/assets/PlantAnimation/Peashooter/Idle/Peashooter_Idle_0.png");
            m_PlantTable[i][j]->setPosition(Vec2(320 + j * 96, 120 + 117 * i));
        }
    }


    return true;
}

void Scene::drawTick() {
    putimage(0, 0, &m_BackgroundImg);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (m_PlantTable[i][j]){
                m_PlantTable[i][j]->drawTick();
            }
        }
    }
}

void Scene::eventTick(float delta) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (m_PlantTable[i][j]){
                m_PlantTable[i][j]->eventTick(delta);
            }
        }
    }
}
