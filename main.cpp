#include <SFML/Graphics.hpp>
#include <iostream>
#include "Zomboid.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Zomboids");
    sf::View camera(sf::Vector2f(0,0), sf::Vector2f(800,600));
    sf::Clock clock;
    bool mouse_dragging = false;
    sf::Vector2i drag_start(0,0);
    sf::Vector2i last_mousepos(0,0);

    Zomboid* z1 = new Zomboid();
    z1->setPosition(sf::Vector2f(100.f, 100.f));

    window.setView(camera);

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (mouse_dragging == false) {
                drag_start = sf::Mouse::getPosition();
            }
            mouse_dragging = true;
        } else {
            mouse_dragging = false;
        }

        if (mouse_dragging) {
            //std::cout << "mouse dragging" << std::endl;
            sf::Vector2i diff = last_mousepos - drag_start;
            std::cout << diff.x << ":" << diff.y << std::endl;
            camera.move(diff.x, diff.y);
            //camera.setCenter(camera.getCenter() + (sf::Mouse::getPosition() - drag_start));
        }

        z1->process(elapsed.asSeconds());

        window.clear();
        window.draw(z1->getShape());
        window.display();

        last_mousepos = sf::Mouse::getPosition();
    }

    return 0;
}
