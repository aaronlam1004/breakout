#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

#include <Logger.hpp>

enum BlockTypes
{
    EMPTY = 0,
    SOLID,
    BREAK
};

enum BlockColors
{
    BLUE = BlockTypes::BREAK,
    GREEN,
    RED
};

class Level
{
    public:
        Level();
    
        void readLevel(const char* levelFile);
        void parseLevel(std::string levelString);
        std::vector<std::vector<unsigned int>> getLevel(void);
        unsigned int numRows(void);
        unsigned int numColumns(void);
        const char* getName(void);
    
    private:
        unsigned int rows = 0;
        unsigned int columns = 0;
        std::vector<std::vector<unsigned int>> level;
        const char* levelName;
};
