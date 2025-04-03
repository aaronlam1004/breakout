#include <Sprite.hpp>

Sprite::Sprite() : Entity()
{
}

void Sprite::loadSprite(const char* spriteTextureFile)
{
    Entity::load(SPRITE_ENTITY_DATA);
    mesh.loadTexture(spriteTextureFile);
    shader.setInt("image", 0);
}
