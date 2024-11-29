#pragma once

#include "Vec2.h"

class Rect {
public:
    Rect() :x(0.0f), y(0.0f), w(0.0f), h(0.0f) {}
    Rect(float x, float y, float w, float h) :x(x), y(y), w(w), h(h) {}

    bool isOverlay(const Vec2&pos)const {
        if (x <= pos.x && pos.x <= x + w && y <= pos.y && pos.y <= y + h) {
            return true;
        }

        return false;
    }

    bool isOverlay(const Rect& rect)const {
        if (x <= rect.x + rect.w && rect.x <= x + w && y <= rect.y + rect.h && rect.y <= y + h) {
            return true;
        }

        return false;
    }

    float x, y, w, h;
};
