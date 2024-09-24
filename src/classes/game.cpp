#include "game.h"
#include "fontLoader.h"

constexpr float pi{std::numbers::pi_v<float>};

Game::Game()
{
    bnw::loadFont("fonts/comic.ttf");

    m_window.create(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close);
    m_window.setFramerateLimit(60);

    m_view.reset(sf::FloatRect(0, 0, 800, 700));
    m_window.setView(m_view);

    m_ui.loadGuiScenario(gui::GUI::Scenario::menu);
}

void Game::gaming()
{
    while (m_window.isOpen())
    {
        sf::Event event{};
        while (m_window.pollEvent(event))
        {
            eventHandle(event);
        }

        // Rendering
        m_window.clear({102, 102, 102});
        update();
        draw();
        m_window.display();
    }
}

void Game::setLastClick()
{
    m_last_click = getMouse();
}

Vec2f Game::getMouse()
{
    const sf::Vector2i pixel_pos = sf::Mouse::getPosition(m_window);

    return m_window.mapPixelToCoords(pixel_pos);
}

void Game::mousePress()
{
    setLastClick();
    m_ui.mousePress(m_last_click);
    m_board.mousePress(m_last_click);
}

void Game::mouseRelease()
{
    m_ui.mouseRelease();
    m_board.mouseRelease(getMouse(), m_last_click);
}

void Game::eventHandle(sf::Event event)
{
    switch (event.type)
    {
    case sf::Event::Closed:
        m_window.close();
        break;

    case sf::Event::MouseButtonPressed:
        mousePress();
        break;

    case sf::Event::MouseButtonReleased:
        mouseRelease();
        break;

    case sf::Event::KeyPressed:
        std::cerr << "kpress: " << sf::Keyboard::getDescription(event.key.scancode).toAnsiString() << '\n';
        m_view.move(0, 10);
        m_window.setView(m_view);
        break;

    case sf::Event::KeyReleased:

    default:
        break;
    }
}

void Game::update()
{
    m_ui.update(getMouse());
    m_board.update(m_last_click, getMouse());
}

void Game::draw()
{
    m_ui.draw(m_window);
    m_board.draw(m_window);
}