#pragma once

#include <glad/glad.h>
#include <Shader.hpp>
#include <Constants.hpp>

class Entity
{
    public:
        Entity(Shader& entityShader,
               const float vertices[], const unsigned int numVertices,
               const VertexAttributes attributes[], const unsigned int numAttributes);
        void show(void);

    private:
        unsigned int vboID;
        unsigned int vaoID;
        unsigned int eboID;
        Shader* shader;

        void loadVertices(const float vertices[], const unsigned int numVertices);
        void loadAttributes(const VertexAttributes attributes[], const unsigned int numAttributes);
};
