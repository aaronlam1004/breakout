#pragma once

#include <iostream>
#include <Shader.hpp>
#include <Sprite.hpp>
#include <Entity.hpp>
#include <Triangle.hpp>

Shader triangleShader;
Shader spriteShader;

Sprite sprite;
Entity triangle;

void loadShaders(void)
{
    triangleShader.load("shaders/triangle.vs", "shaders/triangle.fs");
    spriteShader.load("shaders/sprite.vs", "shaders/sprite.fs");
}


void loadEntities(void)
{
    triangle.load(triangleShader, TRIANGLE_VERTICES, sizeof(TRIANGLE_VERTICES),
                  TRIANGLE_ATTRIBUTES);
    // sprite.loadSprite(spriteShader);
}
