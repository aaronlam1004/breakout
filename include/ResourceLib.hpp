#pragma once

#include <iostream>
#include <Shader.hpp>
#include <Sprite.hpp>
#include <Entity.hpp>

Sprite sprite;

void loadEntities(void)
{
    sprite.size.width = 200;
    sprite.load("resources/textures/paddle.png");
    // sprite.updateEntity = moveHorizontally;
}
