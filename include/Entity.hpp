#pragma once

#include <glad/glad.h>
#include <Shader.hpp>

class Entity
{
    public:
        Entity();
        void show(void);
        void load(Shader& entityShader,
                  const float vertices[], const unsigned int numVertices,
                  const int attributeCounts[], const unsigned int numAttributes);

    private:
        unsigned int vboID;
        unsigned int vaoID;
        unsigned int eboID;
        Shader* shader;

        void loadVertices(const float vertices[], const unsigned int numVertices);
        void loadAttributes(const int attributeCounts[], const unsigned int numAttributes);
};
