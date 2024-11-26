#include <ctime>
#include <easyx.h>
#include <numbers>

#include "Scene.h"

int main() {
    initgraph(1280, 720, EX_SHOWCONSOLE);

    Scene* scene = Scene::create();

    float fps = 1000.0f / 60;
    clock_t begin_time = clock();
    clock_t end_time = 0;

    while (true) {
        end_time = clock();

        if (float(end_time - begin_time) >= fps) {
            scene->drawTick();
            scene->eventTick(float(end_time - begin_time));

            begin_time = end_time;
        }
    }
}
