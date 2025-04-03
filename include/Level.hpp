#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

#include <glm/glm.hpp> // TODO: move below to another file

#include <Sprite.hpp> // TODO: move below to another file

class Level
{
    public:
        Level() {};
    
        void readLevel(const char* levelFileName)
        {
            std::ifstream levelFile(levelFileName);
            std::stringstream levelFileStream;
            levelFileStream << levelFile.rdbuf();
            levelFile.close();

            std::string levelString = levelFileStream.str();
            std::cout << levelString << std::endl;

            parseLevel(levelString);
        }

        void parseLevel(std::string levelString)
        {
            rows = 0;
            columns = 0;

            int numValues = 0;

            std::vector<int> values;
            for (int i = 0; i < levelString.length(); ++i)
            {
                if (levelString[i] != ' ' && levelString[i] != '\n')
                {
                    values.push_back(atoi(&levelString[i]));   
                    if (rows == 0)
                    {
                        columns++;
                    }
                }
                
                if (levelString[i] == '\n')
                {
                    rows++;
                    if (rows > 0 && columns != numValues)
                    {
                        // TODO: throw error here regarding parsing level
                    }
                    numValues = 0;
                }
            }
            
            std::cout << "Read columns: " << columns << std::endl;
            std::cout << "Read rows: " << rows << std::endl;

            for (int i = 0; i < rows; ++i)
            {
                std::vector<unsigned int> level;
                for (int j = 0; j < columns; ++j)
                {
                    level.push_back(values[(i * columns) + j]);
                }
                levelData.push_back(level);
            }

            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < columns; ++j)
                {
                    std::cout << levelData[i][j] << ' ';
                }
                std::cout << std::endl;
            }
        }

        std::vector<std::vector<unsigned int>> getLevel(void)
        {
            return levelData;
        }

        unsigned int numRows(void)
        {
            return rows;
        }

        unsigned int numColumns(void)
        {
            return columns;
        }
    
    private:
        unsigned int rows = 0;
        unsigned int columns = 0;
        std::vector<std::vector<unsigned int>> levelData;
};

// TODO: move to another file
class LevelRenderer
{
    public:
        LevelRenderer() {};

        void load(Level level)
        {
            std::cout << "LOADING LEVEL" << std::endl;
            std::vector<std::vector<unsigned int>> levelData = level.getLevel();
            
            for (int i = 0; i < level.numRows(); ++i)
            {
                for (int j = 0; j < level.numColumns(); ++j)
                {
                    if (levelData[i][j] != 0)
                    {
                        Sprite block;
                        block.size.width = 800 / level.numColumns();
                        block.pos.x += j * (block.size.width);
                        block.pos.y += i * (block.size.height);
                        block.loadSprite("resources/textures/block.png", false, false);
                        blocks.push_back(block);
                    }
                }
            }
        }

        void draw(void)
        {
            for (int i = 0; i < blocks.size(); ++i)
            {
                blocks[i].draw();
            }
        }

    private:
        std::vector<Sprite> blocks;
};
