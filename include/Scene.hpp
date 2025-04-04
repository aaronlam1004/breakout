#pragma once

#include <vector>
#include <glm/glm.hpp>

#include <Constants.hpp>
#include <Level.hpp>
#include <Entity.hpp>
#include <Sprite.hpp>

class Scene
{
    public:
        Scene();
        void setBackgroundColor(float r, float g, float b);
        void loadLevel(Level level);
        void render(void);

    private:
        std::vector<Sprite> levelEntities;
    
        void setBlockColor(Sprite& block, int blockType);
};
