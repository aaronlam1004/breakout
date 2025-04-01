#include <Entity.hpp>

#include <iostream>

Entity::Entity(Shader& entityShader,
               const float vertices[], const unsigned int numVertices,
               const VertexAttributes attributes[], const unsigned int numAttributes)
{
    shader = &entityShader;
    
    glGenBuffers(1, &vboID); // Vertex buffer
    glGenVertexArrays(1, &vaoID); // Vertex attributes buffer
    glGenBuffers(1, &eboID); // Element buffer

    loadVertices(vertices, numVertices);
    loadAttributes(attributes, numAttributes);
}

void Entity::loadVertices(const float vertices[], const unsigned int numVertices)
{
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, numVertices, vertices, GL_STATIC_DRAW);
}

void Entity::loadAttributes(const VertexAttributes attributes[], const unsigned int numAttributes)
{
    glBindVertexArray(vaoID);
    for (int i = 0; i < numAttributes; ++i)
    {
        VertexAttributes currAttribute = attributes[i];
        glVertexAttribPointer(currAttribute.id, currAttribute.count,
                              GL_FLOAT,
                              GL_FALSE,
                              currAttribute.totalSize,
                              (void*) currAttribute.startIndex);
        glEnableVertexAttribArray(currAttribute.id);
    }
}


void Entity::show(void)
{
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBindVertexArray(vaoID);
    shader->use();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
