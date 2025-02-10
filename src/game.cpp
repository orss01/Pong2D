#include <iostream>
#include "Game.hpp"

Game::Game()
{
    initWindow();
    initPaddles();
}

Game::~Game()
{

}

void Game::initWindow()
{
    this->videoMode.size = {this->WIDTH, this->HEIGHT};
    this->window = new sf::RenderWindow(this->videoMode, "Pong", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    
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
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            this->paddleL->moveVertical(-this->PADDLE_SPEED); 
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            this->paddleL->moveVertical(this->PADDLE_SPEED); 
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            this->paddleR->moveVertical(-this->PADDLE_SPEED); 
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            this->paddleR->moveVertical(this->PADDLE_SPEED); 
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

    this->renderPaddles();

    this->window->display();
}

void Game::initPaddles()
{ 
    int center = (this->HEIGHT / 2) - 35;
    this->paddleL = new Paddle(20, center);
    this->paddleR = new Paddle(this->WIDTH - 35, center);

}

void Game::renderPaddles()
{
    this->window->draw(this->paddleL->rect());
    this->window->draw(this->paddleR->rect());
}
