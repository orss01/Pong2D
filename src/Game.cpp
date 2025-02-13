#include <iostream>
#include "Game.hpp"

Game::Game()
{
    this->initWindow();
    this->initObjects();
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
    }
}

void Game::keyboardInput()
{
    float windowBottom = this->HEIGHT - paddleL->getPaddleHeight();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        this->paddleL->moveVertical(-this->PADDLE_SPEED, windowBottom); 
        this->paddleL->goingUp();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        this->paddleL->moveVertical(this->PADDLE_SPEED, windowBottom); 
        this->paddleL->goingDown();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        this->paddleR->moveVertical(-this->PADDLE_SPEED, windowBottom);
        this->paddleR->goingUp();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        this->paddleR->moveVertical(this->PADDLE_SPEED, windowBottom); 
        this->paddleR->goingDown();
    }
}

void Game::update()
{
    this->ball->paddleCollision(*this->paddleL, *this->paddleR);
    this->paddleL->updatePaddle();
    this->paddleR->updatePaddle();
    this->ball->updateBall(this->HEIGHT, this->WIDTH);
}

void Game::render()
{
    this->window->clear();

    this->renderObjects();

    this->window->display();
}

void Game::initObjects()
{ 
    float centerP = (this->HEIGHT / 2) - 35;
    float centerBv = (this->HEIGHT / 2) - 7;
    float centerBh = (this->WIDTH / 2) - 7;
    this->paddleL = new Paddle(20, centerP);
    this->paddleR = new Paddle(this->WIDTH - 35, centerP);
    this->ball = new Ball(centerBh, centerBv);

}

void Game::renderObjects()
{
    this->window->draw(this->paddleL->rect());
    this->window->draw(this->paddleR->rect());
    this->window->draw(this->ball->rect());
}
