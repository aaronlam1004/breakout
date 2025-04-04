#pragma once

#include <Entity.hpp>

struct CollisionEntity : public Entity
{
    void (*onCollision)(Entity* self, Entity* collider) = nullptr;
    
    virtual void update(void)
    {
        if (onCollision != nullptr)
        {
            // TODO: check if there is a collision, if there is trigger onCollision
        }
        Entity::update();
    }
};
