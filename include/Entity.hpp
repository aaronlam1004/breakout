#pragma once

#include <cassert>
#include <glad/glad.h>

#include <Logger.hpp>
#include <Mesh.hpp>
#include <Shader.hpp>

struct Pos
{
    float x;
    float y;
};

struct Size
{
    float width;
    float height;
};

struct Velocity
{
    float x;
    float y;
};

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
        virtual void update(void) {}

    protected:
        Shader shader;
        Mesh mesh;

        Pos pos {0.0f, 0.0f};
        Size size {50.0f, 50.0f};
        Velocity vel {0.0f, 0.0f};
};
