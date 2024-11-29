#include <ctime>
#include <easyx.h>
#include "Scene.h"

int main() {
    srand(time(nullptr));
    initgraph(1280, 720, EX_SHOWCONSOLE);

    Scene* scene = Scene::create();

    float fps = 1000.0f / 60;
    clock_t begin_time = clock(), end_time = 0;
    BeginBatchDraw();
    ExMessage msg;

    while (true) {
        end_time = clock();
        if (float(end_time - begin_time) >= fps) {
            scene->drawTick();
            FlushBatchDraw();
            scene->eventTick(float(end_time - begin_time) / CLOCKS_PER_SEC);
            begin_time = end_time;
        }

        if (peekmessage(&msg)) {
            scene->eventTick(&msg);
        }
    }

    EndBatchDraw();
    return 0;
}
