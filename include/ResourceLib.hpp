#pragma once

#include <iostream>
#include <Shader.hpp>
#include <Entity.hpp>
#include <Triangle.hpp>

Shader triangleShader;
Entity triangle;

void loadShaders(void)
{
    triangleShader.load("triangle.vs", "triangle.fs");
}


void loadEntities(void)
{
    triangle.load(triangleShader, TRIANGLE_VERTICES, sizeof(TRIANGLE_VERTICES),
                  TRIANGLE_ATTR_COUNT, sizeof(TRIANGLE_ATTR_COUNT) / sizeof(int));
}
