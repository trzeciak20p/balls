#pragma once

#include "board.h"
#include <SFML/System/Clock.hpp>
#include <memory>

class Simulation
{
public:
    Simulation();

    void loadBoard();

    void draw(sf::RenderWindow& window)
    {
        if (!m_board)
        {
            return;
        }

        window.setView(m_view);
        m_board->draw(window);
        window.setView(window.getDefaultView());
    }

    Vec2f WetWouse(sf::RenderWindow& window, Vec2f mouse)
    {
        const sf::Vector2i pixel_pos = sf::Mouse::getPosition(window);

        return window.mapPixelToCoords(sf::Vector2i(mouse), m_view);
    }

    void update(sf::RenderWindow& window, Vec2f mouse)
    {
        if (!m_board)
        {
            return;
        }
        m_board->update(m_last_click, WetWouse(window, mouse));
    }

    void mousePress(sf::RenderWindow& window, Vec2f mouse)
    {
        if (!m_board)
        {
            return;
        }

        m_last_click = WetWouse(window, mouse);
        m_board->mousePress(WetWouse(window, mouse));
    }

    void mouseRelease(sf::RenderWindow& window, Vec2f mouse)
    {
        if (!m_board)
        {
            return;
        }

        m_board->mouseRelease(WetWouse(window, mouse), m_last_click);
    }

private:
    int                    tick_rate{};
    int                    tick_rate_desired{60};
    sf::Clock              clock;
    sf::View               m_view{sf::FloatRect(0, 0, 800, 700)};
    Vec2f                  m_last_click;
    std::unique_ptr<Board> m_board;
};