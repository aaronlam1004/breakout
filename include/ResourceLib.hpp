#pragma once

#include <Constants.hpp>
#include <Shader.hpp>
#include <Player.hpp>
#include <Ball.hpp>

Ball ball;
Player player;

void loadEntities(void)
{
    player.size = { 200.0f, 50.0f };
    player.pos = { (WIDTH / 2) - (player.size.width / 2), HEIGHT - (player.size.height * 2) };
    player.color = { 1.0f, 1.0f, 1.0f };
    player.load("resources/textures/paddle.png");
    
    ball.size = { 40.0f, 30.0f};
    ball.pos = { player.pos.x + (player.size.width / 2) - (ball.size.width / 2), player.pos.y - ball.size.height };
    ball.vel = { 0.1f, 0.1f };
    ball.color = { 1.0f, 1.0f, 1.0f };
    ball.load("resources/textures/awesomeface.png");
    ball.updateEntity = handleBallUpdate;
}

void renderEntities(void)
{
    player.render();
    player.update();
    ball.render();
    ball.update();
}
