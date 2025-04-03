#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Logger.hpp>
#include <Shader.hpp>
#include <ResourceLib.hpp>

Logger logger;

const int WIDTH = 800;
const int HEIGHT = 800;

int main(int argc, char* argv[])
{
    // GLFW window
    if (!glfwInit())
    {
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Window", NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create GLFW window\n");
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD for OpenGL\n");
        return -1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Event handlers

    // Entities
    loadEntities();

    // Loop
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        sprite.draw();
        sprite.update();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    return 0;
}
