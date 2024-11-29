#include "Scene.h"
#include <cstdio>

Scene* Scene::create() {
	Scene* scene = new Scene;

	if (scene->init()) {
		return scene;
	}

	delete scene;
	return nullptr;
}

bool Scene::init() {
	loadimage(&m_BackgroundImg, "D:/CLion 2024.2.2/Plants vs. Zombies/assets/DaytimeScene.png");
	Animation* PlantAnimation = Animation::create();
	PlantAnimation->setInterval(0.1f);

	for (int i = 0;i<=12;++i) {
		char buff[128] = { 0 };
		sprintf(buff, "D:/CLion 2024.2.2/Plants vs. Zombies/assets/PlantAnimation/Peashooter/Idle/Peashooter_Idle_%d.png", i);
		PlantAnimation->addImage(buff);
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 9; ++j) {
			m_PlantTable[i][j] = nullptr;
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 9; ++j) {
			m_PlantTable[i][j] = Plant::create("D:/CLion 2024.2.2/Plants vs. Zombies/assets/PlantAnimation/Peashooter/Idle/Peashooter_Idle_0.png");
			m_PlantTable[i][j]->setPosition(Vec2(320 + j * 96, 120 + i * 117));
			m_PlantTable[i][j]->setAnimation(PlantAnimation);
			m_PlantTable[i][j]->startAnimation(true);
		}
	}

	m_ZombieAnimation = Animation::create();
	m_ZombieAnimation->setInterval(0.1f);

	for (int i = 0; i <= 21; ++i) {
		char buff[128] = { 0 };
		sprintf(buff, "D:/CLion 2024.2.2/Plants vs. Zombies/assets/ZombieAnimation/RegularZombie/Walk/RegularZombie_walk_%d.png", i);
		m_ZombieAnimation->addImage(buff);
	}

	m_ZombieAttackAnimation = Animation::create();
	m_ZombieAttackAnimation->setInterval(0.1f);

	for (int i = 0; i <= 20; ++i) {
		char buff[128] = { 0 };
		sprintf(buff, "D:/CLion 2024.2.2/Plants vs. Zombies/assets/ZombieAnimation/RegularZombie/Attack/RegularZombie_Attack_%d.png", i);
		m_ZombieAttackAnimation->addImage(buff);
	}

	return true;
}

void Scene::drawTick() {
	putimage(0, 0, &m_BackgroundImg);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (m_PlantTable[i][j])
				m_PlantTable[i][j]->drawTick();
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (auto& zombie : m_Zombies[i]) {
			zombie->drawTick();
		}
	}
}

void Scene::eventTick(float delta) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (m_PlantTable[i][j])
				m_PlantTable[i][j]->eventTick(delta);
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (auto& zombie : m_Zombies[i]) {
			zombie->eventTick(delta);
		}
	}

	for (int i = 0; i <5;++i) {
		for (auto& zombie : m_Zombies[i]) {
			bool is = false;
			for (int j = 0; j < 9; ++j) {
				if (m_PlantTable[i][j]) {
					if (m_PlantTable[i][j]->getBoundingBox().isOverlay(zombie->getBoundingBox())) {
						is = true;
						zombie->setIsMove(false);
					}
				}
			}

			if (!is) {
				zombie->setIsMove(true);
			}
		}
	}

	m_CreateZombieCount += delta;

	if (m_CreateZombieCount >= 2.0f) {
		Zombie* zombie = Zombie::create("D:/CLion 2024.2.2/Plants vs. Zombies/assets/ZombieAnimation/RegularZombie/Walk/RegularZombie_walk_0.png");
		zombie->setAnimation(m_ZombieAnimation);
		zombie->setAttackAnimation(m_ZombieAttackAnimation);
		zombie->startAnimation(true);
		int row = rand() % 5;
		zombie->setPosition(Vec2(1110, 70 + row * 120));
		m_Zombies[row].push_back(zombie);
		m_CreateZombieCount -= 2.0f;
	}
}

void Scene::eventTick(const ExMessage* msg) {
	if (msg->message == WM_LBUTTONDOWN) {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (m_PlantTable[i][j]) {
					if (m_PlantTable[i][j]->getBoundingBox().isOverlay(Vec2(msg->x, msg->y))) {
						delete m_PlantTable[i][j];
						m_PlantTable[i][j] = nullptr;
					}
				}
			}
		}
	}
}
