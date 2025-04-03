#pragma once

#include <cassert>
#include <glad/glad.h>
#include <glm/glm.hpp>

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

struct Color
{
    float r;
    float g;
    float b;

    glm::vec3 toVec(void)
    {
        return glm::vec3(r, g, b);
    }
};

struct MeshData
{
    float* vertices;
    unsigned int sizeOfVertices;
    VertexAttributes attributes;
};

struct Entity
{
    Pos pos {0.0f, 0.0f};
    Size size {50.0f, 50.0f};
    Velocity vel {0.0f, 0.0f};
    Color color {1.0f, 1.0f, 1.0f};
    Shader shader;
    Mesh mesh;

    void (*updateEntity)(Entity* entity) = nullptr;

    virtual void loadShader(const char* vsFile, const char* fsFile)
    {
        shader.load(vsFile, fsFile);
    }

    virtual void loadMesh(MeshData meshData)
    {
        mesh.load(meshData.vertices, meshData.sizeOfVertices, meshData.attributes);
    }

    virtual void render(void)
    {
        shader.use();
        mesh.render();
    }

    void update(void)
    {
        if (updateEntity != nullptr)
        {
            updateEntity(this);
        }
    }
};
