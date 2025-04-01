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
        Shader(const char* vsFile, const char* fsFile);
        void use(void);

    private:
        int id = glCreateProgram();
        int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        int fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    
        bool loadVertexShader(const char* vsFile);
        bool loadFragmentShader(const char* fsFile);
        bool checkShaderCompiled(int shaderID);
};
