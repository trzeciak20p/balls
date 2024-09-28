#pragma once

#include "board.h"
#include <SFML/System/Clock.hpp>
#include <memory>

namespace sim
{

class Simulation
{
public:
    void loadBoard();
    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow& window, Vec2f mouse);
    void mousePress(sf::RenderWindow& window, Vec2f mouse);
    void mouseRelease(sf::RenderWindow& window, Vec2f mouse);
    void onResize(sf::Event::SizeEvent size);
    void moveView(Vec2f diff);

private:
    Vec2f wetWouse(sf::RenderWindow& window, Vec2f mouse);

    int                    m_tick_rate{};
    int                    m_tick_rate_desired{60};
    sf::Clock              m_clock;
    sf::View               m_view{sf::FloatRect(0, 0, 800, 700)};
    Vec2f                  m_last_click;
    std::unique_ptr<Board> m_board;
};

} // namespace sim