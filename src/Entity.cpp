#include <Entity.hpp>

Entity::Entity()
{
}

void Entity::load(EntityData data)
{
    shader.load(data.vsFile, data.fsFile);
    mesh.load(data.vertices, data.sizeOfVertices, data.attributes);
}

void Entity::draw(void)
{
    shader.use();
    mesh.draw();
}
