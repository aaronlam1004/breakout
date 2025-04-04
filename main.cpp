#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Constants.hpp>
#include <Logger.hpp>
#include <Scene.hpp>
#include <Level.hpp>
#include <Shader.hpp>
#include <Inputs.hpp>
#include <ResourceLib.hpp>

Logger logger;

int main(int argc, char* argv[])
{
    // GLFW window
    if (!glfwInit())
    {
        LOG_ERROR("Failed to initialize GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Breakout", NULL, NULL);
    if (window == NULL)
    {
        LOG_ERROR("Failed to create GLFW window\n");
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        LOG_ERROR("Failed to initialize GLAD for OpenGL\n");
        return -1;
    }

    // User inputs
    glfwSetFramebufferSizeCallback(window, processFramebufferResize);
    glfwSetKeyCallback(window, processKeyPress);

    Level level;
    level.readLevel("levels/level1.txt");

    // Scene
    Scene scene;
    scene.setBackgroundColor(0.2f, 0.2f, 0.2f);
    scene.loadLevel(level);

    // Event handlers
    loadEntities();

    // Loop
    while (!glfwWindowShouldClose(window))
    {
        scene.render();
        sprite.render();
        sprite.update();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    return 0;
}
