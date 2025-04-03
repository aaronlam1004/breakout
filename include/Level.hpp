#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

#include <Logger.hpp>

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
            
            levelName = levelFileName;
            parseLevel(levelFileStream.str());
        }

        void parseLevel(std::string levelString)
        {
            rows = 0;
            columns = 0;

            int numValues = 0;
            std::vector<unsigned int> values;
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
            
            for (int i = 0; i < rows; ++i)
            {
                std::vector<unsigned int> level;
                for (int j = 0; j < columns; ++j)
                {
                    level.push_back(values[(i * columns) + j]);
                }
                levelData.push_back(level);
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

        const char* getName(void)
        {
            return levelName;
        }
    
    private:
        unsigned int rows = 0;
        unsigned int columns = 0;
        std::vector<std::vector<unsigned int>> levelData;
        const char* levelName;
};
