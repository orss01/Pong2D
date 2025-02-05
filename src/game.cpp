#include "../include/game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

game::game() 
{
    game::x = 0;
    game::y = 0;
}

void game::init()
{
    //Making the window
    sf::RenderWindow window;
    window.create(sf::VideoMode({800, 600}), "Pong");

    //Main game loop
    while (window.isOpen())
    {
        window.setVerticalSyncEnabled(true);
        //Setting the frame rate
        window.setFramerateLimit(60);

        sf::CircleShape shape(50.f);
        // set the shape color to green
        shape.setFillColor(sf::Color(100, 250, 50));

        shape.setPosition(sf::Vector2f(game::x, game::y));        
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
            
            if(const auto*keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if(keyPressed -> scancode == sf::Keyboard::Scan::W)
                {
                    game::y -= 10;
                    // std::cout << "A was pressed" << std :: endl;
                }
                if(keyPressed -> scancode == sf::Keyboard::Scan::S)
                {
                    game::y += 10;
                    // std::cout << "A was pressed" << std :: endl;
                }
                if(keyPressed -> scancode == sf::Keyboard::Scan::A)
                {
                    game::x -= 10;
                    // std::cout << "A was pressed" << std :: endl;
                }
                if(keyPressed -> scancode == sf::Keyboard::Scan::D)
                {
                    game::x += 10;
                    // std::cout << "A was pressed" << std :: endl;
                }
            }
        }

        //First thing to call
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }
}