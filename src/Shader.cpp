#include <Shader.hpp>

Shader::Shader()
{
}

void Shader::use(void)
{
    if (id != -1)
    {
        glUseProgram(id);
    }
    else
    {
        LOG_WARNING("Shader not loaded\n");
    }
}

void Shader::load(const char* vsFile, const char* fsFile)
{
    id = glCreateProgram();
    vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    bool compiled = loadVertexShader(vsFile);
    compiled &= loadFragmentShader(fsFile);
    if (compiled)
    {
        glLinkProgram(id);
    }
}

bool Shader::loadVertexShader(const char* vsFile)
{
    std::ifstream vertexSource(vsFile);
    std::stringstream vertexShaderStream;
    vertexShaderStream << vertexSource.rdbuf();
    vertexSource.close();
    
    std::string vertexShaderString = vertexShaderStream.str();
    const char* vertexShaderSource = vertexShaderString.c_str();
    glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShaderID);

    bool compiled = checkShaderCompiled(vertexShaderID);
    if (compiled)
    {
        LOG_INFO("Vertex shader (%s) compiled successfully\n", vsFile); 
        glAttachShader(id, vertexShaderID);
    }
    else
    {
        LOG_ERROR("Vertex shader (%s) failed to compile\n", vsFile);
    }
    glDeleteShader(vertexShaderID);
    return compiled;
}

bool Shader::loadFragmentShader(const char* fsFile)
{
    std::ifstream fragmentSource(fsFile);
    std::stringstream fragmentShaderStream;
    fragmentShaderStream << fragmentSource.rdbuf();
    fragmentSource.close();
    
    std::string fragmentShaderString = fragmentShaderStream.str();
    const char* fragmentShaderSource = fragmentShaderString.c_str();
    glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShaderID);

    bool compiled = checkShaderCompiled(fragmentShaderID);
    if (compiled)
    {
        LOG_INFO("Fragment shader (%s) compiled successfully\n", fsFile); 
        glAttachShader(id, fragmentShaderID);
    }
    else
    {
        LOG_ERROR("Vertex shader (%s) failed to compile\n", fsFile);
    }
    glDeleteShader(fragmentShaderID);
    return compiled;
}

bool Shader::checkShaderCompiled(int shaderID)
{
    int status;
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &status);
    return status != 0;
}

int Shader::findVar(const char* var)
{
    return glGetUniformLocation(id, var);
}

void Shader::setInt(const char* var, int value)
{
    glUniform1i(findVar(var), value);
}
