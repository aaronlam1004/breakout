#pragma once

#include <iostream>
#include <Shader.hpp>
#include <Sprite.hpp>
#include <Entity.hpp>

Sprite sprite;

void loadEntities(void)
{
    sprite.loadSprite("resources/textures/awesomeface.png");
}
