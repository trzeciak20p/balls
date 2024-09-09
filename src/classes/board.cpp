#include "board.h"
#include <fstream>
#include <iostream>

sf::Color convertToSFColor(std::ifstream &file)
{
    std::string str{*std::istream_iterator<std::string>(file)};

    std::cout << "str: " << str << "\n";

    if (str == "white")
    {
        return sf::Color::White;
    }

    return {*std::istream_iterator<sf::Uint8>(file), *std::istream_iterator<sf::Uint8>(file), *std::istream_iterator<sf::Uint8>(file)};
}

Ball makeBall(std::ifstream &file, Board* board)
{
    float x{*std::istream_iterator<float>(file)};
    float y{*std::istream_iterator<float>(file)};
    float r{*std::istream_iterator<float>(file)};

    const sf::Color color = convertToSFColor(file);
    return {x, y, r, color, board};
}

Wall makeWall(std::ifstream &file)
{
    int x{*std::istream_iterator<int>(file)};
    int y{*std::istream_iterator<int>(file)};
    int x_size{*std::istream_iterator<int>(file)};
    int y_size{*std::istream_iterator<int>(file)};

    Wall::Type type{*std::istream_iterator<int>(file)};

    return {x, y, x_size, y_size, type};
}

Board::Board(const std::string &path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        file.close();
        std::cout << "\nCOULDN'T FIND A FILE TO LOAD MAP\tunder path:\"" << path << "\"\n";
        return;
    }

    char obj;
    while (file >> obj)
    {
        if (obj == 'b')
        {
            m_balls.emplace_back(makeBall(file, this));
        }
        else
        {
            m_walls.emplace_back(makeWall(file));
        }
    }
    file.close();
}