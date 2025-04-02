#pragma once

#include <cassert>
#include <glad/glad.h>
#include <Shader.hpp>
#include <Constants.hpp>

class Entity
{
    public:
        Entity();
        void show(void);
        void load(Shader& entityShader,
                  const float vertices[], const unsigned int sizeOfVertices,
                  const VertexAttributes attributes);

    protected:
        unsigned int vboID = -1;
        unsigned int vaoID = -1;
        unsigned int eboID = -1;
        Shader* shader = nullptr;

        unsigned int numOfTriangles = 0;

        void loadVertices(const float vertices[], const unsigned int sizeOfVertices);
        void loadAttributes(const VertexAttributes attributes);
};
