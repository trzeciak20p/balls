#include "board.h"
#include "ball.h"
#include "wall.h"
#include <SFML/Config.hpp>
#include <SFML/Graphics/Color.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

sf::Color makeColor(std::ifstream &file)
{
    std::string str{};
    file >> str;

    if (str == "white")
    {
        return sf::Color::White;
    }

    sf::Uint8 r{};
    file >> r;
    sf::Uint8 g{};
    file >> g;
    sf::Uint8 b{};
    file >> b;

    return {r, g, b};
}

Ball makeBall(std::ifstream &file)
{
    float x{};
    file >> x;
    float y{};
    file >> y;
    float r{};
    file >> r;

    const sf::Color color = makeColor(file);
    return {x, y, r, color};
}

Wall makeWall(std::ifstream &file)
{
    int x{};
    file >> x;
    int y{};
    file >> y;

    int x_size{};
    file >> x_size;
    int y_size{};
    file >> y_size;

    const Wall::Type type{*std::istream_iterator<int>(file)};

    return {x, y, x_size, y_size, type};
}

Board::Board(const std::string &path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cout << "COULDN'T FIND A FILE TO LOAD MAP under path:\"" << path << "\"\n";
        return;
    }

    file >> m_width;
    file >> m_height;

    char obj = 0;
    while (file >> obj)
    {
        if (obj == 'b')
        {
            m_balls.emplace_back(makeBall(file));
        }
        else
        {
            m_walls.emplace_back(makeWall(file));
        }
    }

    file.close();
}