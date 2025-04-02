#include <Entity.hpp>

Entity::Entity()
{
}

void Entity::load(Shader& entityShader,
                  const float vertices[], const unsigned int sizeOfVertices,
                  const VertexAttributes attributes)
{
    glGenBuffers(1, &vboID); // Vertex buffer
    glGenVertexArrays(1, &vaoID); // Vertex attributes buffer
    glGenBuffers(1, &eboID); // Element buffer

    assert(sizeOfVertices > 0);
    
    shader = &entityShader;
    loadVertices(vertices, sizeOfVertices);
    loadAttributes(attributes);

    numOfTriangles = (sizeOfVertices / sizeof(float)) / attributes.totalCount;
}

void Entity::loadVertices(const float vertices[], const unsigned int sizeOfVertices)
{
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeOfVertices, vertices, GL_STATIC_DRAW);
}

void Entity::loadAttributes(const VertexAttributes attributes)
{
    glBindVertexArray(vaoID);
    int start = 0;
    for (int i = 0; i < attributes.numAttributes; ++i)
    {
        start += i * attributes.slices[i] * sizeof(float);
        glVertexAttribPointer(i, attributes.slices[i],
                              GL_FLOAT,
                              GL_FALSE,
                              attributes.totalCount * sizeof(float),
                              (void*) start);
        glEnableVertexAttribArray(i);
    }
}


void Entity::show(void)
{
    if (vboID != -1 && vaoID != -1 && shader != nullptr)
    {
        glBindBuffer(GL_ARRAY_BUFFER, vboID);
        glBindVertexArray(vaoID);
        shader->use();
        glDrawArrays(GL_TRIANGLES, 0, numOfTriangles);
    }
    else
    {
        // TODO: log error here
    }
}
