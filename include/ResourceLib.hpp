#pragma once

#include <iostream>
#include <Shader.hpp>
#include <Sprite.hpp>
#include <Entity.hpp>

Sprite sprite;

void loadEntities(void)
{
    sprite.load("resources/textures/awesomeface.png");
    // sprite.updateEntity = moveHorizontally;
}
