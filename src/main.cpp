#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main()
{
    //Making the window
    sf::RenderWindow window;
    window.create(sf::VideoMode({800, 600}), "Pong");

    //Main game loop
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
            
            
        }
        window.setVerticalSyncEnabled(true);
        //Setting the frame rate
        window.setFramerateLimit(60);

        //First thing to call
        window.clear(sf::Color::Black);

        sf::CircleShape shape(50.f);
        // set the shape color to green
        shape.setFillColor(sf::Color(100, 250, 50));

        window.draw(shape);
        window.display();
    }
}