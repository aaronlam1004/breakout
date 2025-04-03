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

const MeshData SPRITE_MESH_DATA = {
    (float*) SPRITE_VERTICES,
    sizeof(SPRITE_VERTICES),
    SPRITE_ATTRIBUTES
};

struct Sprite : public Entity
{
    void load(const char* textureFile, bool flipped = false, bool hasAlpha = true)
    {
        loadShader("shaders/sprite.vs", "shaders/sprite.fs");
        loadMesh(SPRITE_MESH_DATA);
        loadTexture(textureFile, flipped, hasAlpha);
    }
    
    virtual void loadShader(const char* vsFile, const char* fsFile) override
    {
        Entity::loadShader(vsFile, fsFile);

        shader.use();

        // Color
        shader.setVec3f("spriteColor", color.toVec());

        // Projection Matrix
        glm::mat4 projection = glm::ortho(0.0f, 800.0f, 800.0f, 0.0f, -1.0f, 1.0f);
        shader.setMat4f("projection", projection);

        // View Matrix
        glm::mat4 view = glm::mat4(1); // Identity matrix
        shader.setMat4f("view", view);        
    }
    
    virtual void loadTexture(const char* textureFile, bool flipped = false, bool hasAlpha = true)
    {
        shader.use();
        mesh.loadTexture(textureFile, flipped, hasAlpha);
        shader.setInt("image", 0);
    }

    virtual void render(void) override
    {
        shader.use();
    
        // Model Matrix
        glm::mat4 model = glm::mat4(1); // Identity matrix
        model = glm::translate(model, glm::vec3(pos.x, pos.y, 1.0f));
        model = glm::scale(model, glm::vec3(size.width, size.height, 1.0f));
        shader.setMat4f("model", model);

        Entity::render();
    }
};

static void moveHorizontally(Entity* entity)
{
    if (entity->pos.x <= 0)
    {
        entity->vel.x = 0.1f;
    }
    else if (entity->pos.x >= 800.0f - entity->size.width)
    {
        entity->vel.x = -0.1f;
    }
    entity->pos.x += entity->vel.x;
}
