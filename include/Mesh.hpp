#pragma once

#include <cassert>
#include <vector>
#include <glad/glad.h>
#include <stb_image.h>

#include <Logger.hpp>

struct VertexAttributes
{
    unsigned int  numAttributes;
    unsigned int  totalCount;
    unsigned int* slices;
    // TODO: type (GL_FLOAT, etc.)
};

class Mesh
{
    public:
        Mesh();
        void load(const std::vector<float> vertices, const VertexAttributes attributes);
        void loadTexture(const char* textureFile, bool flipped = false, bool hasAlpha = true);
        void render(void);

        unsigned int getTextureID(void);

    protected:
        unsigned int vboID = -1;
        unsigned int vaoID = -1;
        unsigned int textureID = -1;

        // TODO: handle vector of textures

        unsigned int numOfTriangles = 0;

        void initBuffers(void);
        void loadVertices(const std::vector<float>);
        void loadAttributes(const VertexAttributes attributes);
};
