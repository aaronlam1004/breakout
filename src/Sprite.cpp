#include <Sprite.hpp>
#include <iostream>

Sprite::Sprite() : Entity()
{
}

void Sprite::loadSprite(const char* spriteTextureFile, bool textureFlipped, bool textureHasAlpha)
{
    Entity::load(SPRITE_ENTITY_DATA);

    // Need to use shader in order to set variables
    shader.use();

    // Texture
    mesh.loadTexture(spriteTextureFile, textureFlipped, textureHasAlpha);
    shader.setInt("image", 0);

    // Projection Matrix
    glm::mat4 projection = glm::ortho(0.0f, 800.0f, 800.0f, 0.0f, -1.0f, 1.0f);
    shader.setMat4f("projection", projection);

    // View Matrix
    glm::mat4 view = glm::mat4(1); // Identity matrix
    shader.setMat4f("view", view);
}

void Sprite::draw(void)
{
    shader.use();
    
    // Model Matrix
    glm::mat4 model = glm::mat4(1);
    model = glm::translate(model, glm::vec3(pos.x, pos.y, 1.0f));
    model = glm::scale(model, glm::vec3(size.width, size.height, 1.0f));
    shader.setMat4f("model", model);

    Entity::draw();
}


void Sprite::update(void)
{
    if (pos.x <= 0)
    {
        vel.x = 0.1f;
    }
    else if (pos.x >= 800.0f - size.width)
    {
        vel.x = -0.1f;
    }
    
    pos.x += vel.x;
}
