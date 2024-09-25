#include "classes/chungus.h"
#include "classes/fontLoader.h"
#include "classes/game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close);
    window.setFramerateLimit(60);

    bnw::loadFont("fonts/comic.ttf");
    Game gra(&window);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            gra.eventHandle(event);
        }

        // Rendering
        window.clear({102, 102, 102});
        gra.update();
        gra.draw();
        window.display();
    }
    return 0;
}