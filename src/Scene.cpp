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
                
                block.size.width = 800 / level.numColumns();
                block.pos.x += j * (block.size.width);
                block.pos.y += i * (block.size.height);

                block.color.r = 1.0f;
                block.color.g = 1.0f;
                block.color.b = 0.0f;

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
