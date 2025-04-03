#pragma once

#include <glm/glm.hpp>

#include <Mesh.hpp>
#include <Entity.hpp>

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

const struct EntityData SPRITE_ENTITY_DATA = {
    "shaders/sprite.vs",
    "shaders/sprite.fs",
    SPRITE_VERTICES,
    sizeof(SPRITE_VERTICES),
    SPRITE_ATTRIBUTES
};

class Sprite: public Entity
{
    public:
        Sprite();
        void loadSprite(const char* spriteTextureFile, bool textureFlipped = false, bool textureHasAlpha = true);
        virtual void draw(void) override;
        virtual void update(void) override;
};
