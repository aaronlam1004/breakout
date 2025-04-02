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
    triangleShader.load("triangle.vs", "triangle.fs");
    spriteShader.load("sprite.vs", "sprite.fs");
}


void loadEntities(void)
{
    triangle.load(triangleShader, TRIANGLE_VERTICES, sizeof(TRIANGLE_VERTICES),
                  TRIANGLE_ATTRIBUTES);
    sprite.loadSprite(spriteShader);
}
