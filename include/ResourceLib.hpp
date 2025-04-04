#pragma once

#include <Constants.hpp>
#include <Shader.hpp>
#include <Sprite.hpp>
#include <Entity.hpp>

Sprite sprite;

void loadEntities(void)
{
    sprite.size = { 200.0f, 50.0f };
    sprite.pos = { 0.0f, HEIGHT - (sprite.size.height * 2) };
    sprite.color = { 1.0f, 1.0f, 1.0f };
    sprite.load("resources/textures/paddle.png");
    // sprite.updateEntity = moveHorizontally;
}
