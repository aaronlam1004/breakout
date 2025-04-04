#pragma once

#include <GLFW/glfw3.h>

#include <ResourceLib.hpp>

void processFramebufferResize(GLFWwindow* window, int width, int height)
{
    glViewPort(0, 0, width, height);
}

void processKeyPress(GLFWwindow* window, int key, int scanCode, int action, int mods)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
            case GLFW_KEY_ESCAPE:
            {
                glfwSetWindowShouldClose(window, true);
            } break;
            case GLFW_KEY_RIGHT:
            {
                sprite.pos.x += 20.0f;
            } break;
            case GLFW_KEY_LEFT:
            {
                sprite.pos.x -= 20.0f;
            } break;
        }
    }
}
