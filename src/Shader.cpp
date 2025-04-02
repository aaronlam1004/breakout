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
        // TODO: need to log here
    }
}

void Shader::load(const char* vsFile, const char* fsFile)
{
    id = glCreateProgram();
    vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    
    assert(loadVertexShader(vsFile));
    assert(loadFragmentShader(fsFile));
    glLinkProgram(id);
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
        glAttachShader(id, vertexShaderID);
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
        glAttachShader(id, fragmentShaderID);
    }
    glDeleteShader(fragmentShaderID);
    return compiled;
}

bool Shader::checkShaderCompiled(int shaderID)
{
    int status;
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &status);
    std::cout << status << std::endl;
    return status != 0;
}
