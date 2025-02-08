#include <iostream>
#include "Game.hpp"

Game::Game()
{
    initWindow();
    initPaddle();
}

Game::~Game()
{

}

void Game::initWindow()
{
    this->videoMode.size = {640u, 480u};
    this->window = new sf::RenderWindow(this->videoMode, "Pong", sf::Style::Close | sf::Style::Titlebar);
}

bool Game::running()
{
    return this->window->isOpen();
}

void Game::pollEvents()
{
    while(const std::optional event = this->window->pollEvent())
    {
        if(event->is<sf::Event::Closed>())
        {
            this->window->close();
        }

        else if(const auto *KeyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if(KeyPressed->scancode == sf::Keyboard::Scancode::Escape)
            {
                this->window->close();
            }
            if(KeyPressed->scancode == sf::Keyboard::Scancode::Escape)
            {

            }
        }
    }
}

void Game::update()
{
    this->pollEvents();
}

void Game::render()
{
    this->window->clear();

    this->renderPaddle();

    this->window->display();
}

void Game::initPaddle()
{
    this->paddle.setSize(sf::Vector2f({15.f, 75.f}));
}

void Game::renderPaddle()
{
    this->window->draw(this->paddle);
}
