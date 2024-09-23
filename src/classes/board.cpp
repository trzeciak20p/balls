#include "board.h"

sf::Color makeColor(std::ifstream& file)
{
    std::string str{};
    file >> str;

    if (str == "white")
    {
        return sf::Color::White;
    }

    int r{};
    file >> r;
    int g{};
    file >> g;
    int b{};
    file >> b;

    return {static_cast<sf::Uint8>(r), static_cast<sf::Uint8>(g), static_cast<sf::Uint8>(b)};
}

Ball makeBall(std::ifstream& file)
{
    float x{};
    file >> x;
    float y{};
    file >> y;
    float r{};
    file >> r;

    return {{x, y}, r, makeColor(file)};
}

Wall makeWall(std::ifstream& file)
{
    float x{};
    file >> x;
    float y{};
    file >> y;

    float x_size{};
    file >> x_size;
    float y_size{};
    file >> y_size;

    int type{};
    file >> type;

    return {{x, y}, {x_size, y_size}, static_cast<Wall::Type>(type)};
}

Board::Board(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cerr << "COULDN'T FIND A FILE TO LOAD MAP under path:\"" << path << "\"\n";
        return;
    }

    char obj{};
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

void Board::mousePress(Vec2f mouse)
{
    for (auto& ball : m_balls)
    {
        if (!ball.checkHover(mouse))
        {
            continue;
        }
        Ball::active_ball = &ball;
        break;
    }
}

void Board::update(bool dragging, Vec2f last_click, Vec2f mouse)
{
    for (auto& ball : m_balls)
    {
        ball.update(m_walls);
    }
    m_charge_meter.update(dragging, last_click, mouse);
}

void Board::draw(sf::RenderWindow* window)
{
    for (const auto& wall : m_walls)
    {
        window->draw(wall);
    }
    for (auto& ball : m_balls)
    {
        window->draw(ball);
    }
    m_charge_meter.draw(window);
}
