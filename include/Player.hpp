#pragma once

#include <Constants.hpp>

struct Player : public Sprite
{
    float move(float delta)
    {
        pos.x += delta;
        if (pos.x <= 0.0f)
        {
            pos.x = 0;
            return 0;
        }
        if (pos.x >= WIDTH - size.width)
        {
            pos.x = WIDTH - size.width;
            return 0;
        }
        return delta;
    }
};
