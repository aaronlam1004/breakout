#include <Level.hpp>

Level::Level()
{
}

void Level::readLevel(const char* levelFile)
{
    std::ifstream levelSource(levelFile);
    std::stringstream levelFileStream;
    levelFileStream << levelSource.rdbuf();
    levelSource.close();

    levelName = levelFile;
    parseLevel(levelFileStream.str());
}

void Level::parseLevel(std::string levelString)
{
    rows = 0;
    columns = 0;
    level.clear();

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
            numValues++;
        }

        if (levelString[i] == '\n')
        {
            if (rows > 0 && columns != numValues)
            {
                LOG_ERROR("Invalid level (row: %d), mismatch num of columns (expected: %d, actual: %d)\n", rows, columns, numValues);
                rows = 0;
                columns = 0;
                return;
            }
            rows++;
            numValues = 0;
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        std::vector<unsigned int> levelRow;
        for (int j = 0; j < columns; ++j)
        {
            levelRow.push_back(values[(i * columns) + j]);
        }
        level.push_back(levelRow);
    }
}

std::vector<std::vector<unsigned int>> Level::getLevel(void)
{
    return level;
}

unsigned int Level::numRows(void)
{
    return rows;
}

unsigned int Level::numColumns(void)
{
    return columns;
}

const char* Level::getName(void)
{
    return levelName;
}
