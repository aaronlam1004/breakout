#pragma once

#include <cassert>
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include <Logger.hpp>
#include <Mesh.hpp>
#include <Shader.hpp>

struct Size
{
    float width;
    float height;
};

struct Pos
{
    float x;
    float y;
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
    std::vector<float> vertices;
    VertexAttributes attributes;
};

struct Entity
{
    int type     { -1 };
    Size size    { 0.0f, 0.0f };
    Pos pos      { 0.0f, 0.0f };
    Velocity vel { 0.0f, 0.0f };
    Color color  { 1.0f, 1.0f, 1.0f };
    
    Shader shader;
    Mesh mesh;

    void (*updateEntity)(Entity* self) = nullptr;

    virtual void loadShader(const char* vsFile, const char* fsFile)
    {
        shader.load(vsFile, fsFile);
    }

    virtual void loadMesh(MeshData meshData)
    {
        mesh.load(meshData.vertices, meshData.attributes);
    }

    virtual void render(void)
    {
        shader.use();
        mesh.render();
    }

    virtual void update(void)
    {
        if (updateEntity != nullptr)
        {
            updateEntity(this);
        }
    }
};
