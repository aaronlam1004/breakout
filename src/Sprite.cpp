#include <Sprite.hpp>

Sprite::Sprite() : Entity()
{
}


void Sprite::loadSprite(Shader& spriteShader)
{
    load(spriteShader, SPRITE_VERTICES, sizeof(SPRITE_VERTICES), SPRITE_ATTRIBUTES);
}
