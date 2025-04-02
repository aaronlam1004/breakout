#pragma once

#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/type_ptr.hpp>

class Shader
{
    public:
        Shader();
        void load(const char* vsFile, const char* fsFile);
        void use(void);

    private:
        int id = -1;
        int vertexShaderID = -1;
        int fragmentShaderID = -1;
    
        bool loadVertexShader(const char* vsFile);
        bool loadFragmentShader(const char* fsFile);
        bool checkShaderCompiled(int shaderID);
};
