#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <Logger.hpp>
#include <ResourceLib.hpp>

bool polygonMode = false;

void processFramebufferResize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
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
                float playerDelta = player.move(20.0f);
                if (ball.stuck)
                {
                    ball.pos.x += playerDelta;
                }
            } break;
            case GLFW_KEY_LEFT:
            {
                float playerDelta = player.move(-20.0f);
                if (ball.stuck)
                {
                    ball.pos.x += playerDelta;
                }
            } break;
            case GLFW_KEY_SPACE:
            {
                ball.release();
            } break;
            case GLFW_KEY_TAB:
            {
                polygonMode = !polygonMode;
                if (polygonMode)
                {
                    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                }
                else
                {
                    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                }
            } break;
        }
    }
}
