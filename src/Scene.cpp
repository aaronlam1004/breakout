#include <Scene.hpp>

Scene::Scene()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Scene::setBackgroundColor(float r, float g, float b)
{
    glClearColor(r, g, b, 1.0f);
}

void Scene::loadLevel(Level level)
{
    LOG_INFO("Loading level: %s\n", level.getName());
    std::vector<std::vector<unsigned int>> levelData = level.getLevel();
    for (int i = 0; i < levelData.size(); ++i)
    {
        for (int j = 0; j < levelData[i].size(); ++j)
        {
            if (levelData[i][j] != 0)
            {
                Sprite block;
                block.size = { 800.0f / level.numColumns(), 50.0f };
                block.pos = { j * (block.size.width), i * (block.size.height) };
                block.color = { 1.0f, 1.0f, 0.0f };
                block.load("resources/textures/block.png", false, false);

                levelEntities.push_back(block);
            }
        }
    }
}

void Scene::render(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i < levelEntities.size(); ++i)
    {
        levelEntities[i].render();
    }
}
