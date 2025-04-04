#pragma once

#include <Constants.hpp>

void handleBallUpdate(Entity* self);

struct Ball : public Sprite
{
    bool stuck = true;
        
    void release(void)
    {
        stuck = false;
    }
};

void handleBallMove(Ball* self)
{
    if (!self->stuck)
    {
        self->pos.x += self->vel.x;
        self->pos.y -= self->vel.y;

        if (self->pos.x <= 0 || self->pos.x >= WIDTH - self->size.width)
        {
            self->vel.x *= -1;
        }
        if (self->pos.y <= 0)
        {
            self->vel.y *= -1;
        }
        
    }
}

void handleBallUpdate(Entity* self)
{
    Ball* ballPtr = reinterpret_cast<Ball*>(self);
    handleBallMove(ballPtr);
}
