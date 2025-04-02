#pragma once

#include <Entity.hpp>
#include <Constants.hpp>

const float SPRITE_VERTICES[] = {
    // aPos (xy) // aTexCoord(xy)
    0.0f, 1.0f,  0.0f, 1.0f,
    1.0f, 0.0f,  1.0f, 0.0f,
    0.0f, 0.0f,  0.0f, 0.0f,
                
    0.0f, 1.0f,  0.0f, 1.0f,
    1.0f, 1.0f,  1.0f, 1.0f,
    1.0f, 0.0f,  1.0f, 0.0f
};

const int SPRITE_ATTRIBUTE_SLICES[] = {
    2, 2
};

const VertexAttributes SPRITE_ATTRIBUTES = {
    2, 4, (unsigned int*) SPRITE_ATTRIBUTE_SLICES
};

class Sprite: public Entity
{
    public:
        Sprite();
        void loadSprite(Shader& spriteShader);
};
