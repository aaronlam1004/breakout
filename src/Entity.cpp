#include <Entity.hpp>

#include <iostream>

Entity::Entity()
{
}

void Entity::load(Shader& entityShader,
                  const float vertices[], const unsigned int numVertices,
                  const int attributeCounts[], const unsigned int numAttributes)
{
    glGenBuffers(1, &vboID); // Vertex buffer
    glGenVertexArrays(1, &vaoID); // Vertex attributes buffer
    glGenBuffers(1, &eboID); // Element buffer
    
    shader = &entityShader;
    loadVertices(vertices, numVertices);
    loadAttributes(attributeCounts, numAttributes);
}

void Entity::loadVertices(const float vertices[], const unsigned int numVertices)
{
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, numVertices, vertices, GL_STATIC_DRAW);
}

void Entity::loadAttributes(const int attributeCounts[], const unsigned int numAttributes)
{
    glBindVertexArray(vaoID);
    int totalSize = 0;
    for (int i = 0; i < numAttributes; ++i)
    {
        totalSize += attributeCounts[i] * sizeof(float);
    }

    int start = 0;
    for (int i = 0; i < numAttributes; ++i)
    {
        start += sizeof(float) * i * attributeCounts[i];
        glVertexAttribPointer(i, attributeCounts[i],
                              GL_FLOAT,
                              GL_FALSE,
                              totalSize,
                              (void*) start);
        glEnableVertexAttribArray(i);
    }
}


void Entity::show(void)
{
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBindVertexArray(vaoID);
    shader->use();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
