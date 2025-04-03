#pragma once

#include <GLFW/glfw3.h>

#include <ResourceLib.hpp>

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
                sprite.pos.x += sprite.size.width / 2;
            } break;
            case GLFW_KEY_LEFT:
            {
                sprite.pos.x -= sprite.size.width / 2;
            } break;
        }
    }
}
