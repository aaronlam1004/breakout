#define STB_IMAGE_IMPLEMENTATION
#include <Mesh.hpp>

Mesh::Mesh()
{
}

void Mesh::load(const float vertices[], const unsigned int sizeOfVertices, const VertexAttributes attributes)
{
    assert(sizeOfVertices > 0);
    initBuffers();
    loadVertices(vertices, sizeOfVertices);
    loadAttributes(attributes);
    numOfTriangles = (sizeOfVertices / sizeof(float)) / attributes.totalCount;
}

void Mesh::loadTexture(const char* textureFile, bool flipped, bool hasAlpha)
{
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(flipped);
    int width, height, numChannels;
    unsigned char* imageData = stbi_load(textureFile, &width, &height,&numChannels, 0);
    if (imageData)
    {
        LOG_INFO("Texture (%s) loaded successfully\n", textureFile);
        unsigned int glColModel = hasAlpha ? GL_RGBA : GL_RGB;
        if (hasAlpha)
        {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        }
        glTexImage2D(GL_TEXTURE_2D, 0, glColModel, width, height, 0, glColModel, GL_UNSIGNED_BYTE, imageData);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        LOG_WARNING("Could not load texture (%s)\n", textureFile);
    }
    stbi_image_free(imageData);
}

void Mesh::initBuffers(void)
{
    // Vertex buffer
    if (vboID == -1)
    {
        glGenBuffers(1, &vboID);
    }

    // Vertex attributes buffer
    if (vaoID == -1)
    {
        glGenVertexArrays(1, &vaoID);
    }
}

void Mesh::loadVertices(const float vertices[], const unsigned int sizeOfVertices)
{
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeOfVertices, vertices, GL_STATIC_DRAW);
}

void Mesh::loadAttributes(const VertexAttributes attributes)
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

void Mesh::draw(void)
{
    if (vboID != -1 || vaoID != -1)
    {
        glBindBuffer(GL_ARRAY_BUFFER, vboID);
        glBindVertexArray(vaoID);
        if (textureID != -1)
        {
            // TODO: handle multiple textures
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, textureID);
        }
        glDrawArrays(GL_TRIANGLES, 0, numOfTriangles);
    }
    else
    {
        LOG_WARNING("Mesh not loaded\n");
    }
}

unsigned int Mesh::getTextureID(void)
{
    return textureID;
}
