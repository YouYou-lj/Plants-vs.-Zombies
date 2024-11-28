# pragma once

#include <easyx.h>
#include <vector>

class Animation {
public:
    static::Animation* create();
    void addImage(const char* filename);
    IMAGE* index(int i);

    int count() const {
        return m_ImageArray.size();
    }

    void setInterval(float interval) {
        m_Interval = interval;
    }

    float getInterval() {
        return m_Interval;
    }

private:
    float m_Interval = 0.0f;
    std::vector<IMAGE> m_ImageArray;
};
