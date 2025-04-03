#pragma once

#include <cassert>
#include <glad/glad.h>

#include <Logger.hpp>
#include <Mesh.hpp>
#include <Shader.hpp>

struct EntityData
{
    // Shaders
    const char* vsFile;
    const char* fsFile;

    // Mesh
    const float* vertices;
    const unsigned int sizeOfVertices;
    const VertexAttributes attributes;
};

class Entity
{
    public:
        Entity();
        void load(EntityData data);
        virtual void draw(void);

    protected:
        Shader shader;
        Mesh mesh;
};
