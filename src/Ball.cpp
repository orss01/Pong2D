#include "Ball.hpp"
#include <iostream>

Ball::Ball()
{
    this->x = 0;
    this->y = 0;
    this->right = true;
    this->left = false;
    this->up = false;
    this->down = false;
    this->getTime = true;
    this->speedy = 5.f;
    this->speedx = 5.f;
    initRect();
    auto start = std::chrono::high_resolution_clock::now();
}

Ball::Ball(float x, float y)
{
    this->x = x;
    this->y = y;
    this->right = true;
    this->left = false;
    this->up = false;
    this->down = false;
    this->getTime = true;
    this->speedy = 5.f;
    this->speedx = 5.f;
    initRect();
}

Ball::~Ball()
{
    
}

void Ball::initRect()
{
    this->rs.setSize(sf::Vector2f({this->DIMENSION, this->DIMENSION}));
    this->rs.setPosition(this->getPosition());
}

sf::Vector2f Ball::getPosition()
{
    return sf::Vector2f({this->x, this->y});
}

sf::RectangleShape Ball::rect()
{
    return this->rs;
}

void Ball::updateBall(float bottomWindow, float rightWindow, Paddle &paddleL, Paddle &paddleR)
{   
    if(this->y < 0)
    {
        this->down = true;
        this->up = false;
    }
    if(this->y > bottomWindow - 14)
    {
        this->down = false;
        this->up = true;
    }
    if(this->x < 0)
    {
        if(this->getTime)
        {
            this->spawnTimer = std::chrono::high_resolution_clock::now();
            this->getTime = false;
            paddleR.addPoint();
        }
        this->spawn();
    }
    if(this->x > rightWindow - 14)
    {
        if(this->getTime)
        {
            this->spawnTimer = std::chrono::high_resolution_clock::now();
            this->getTime = false;
            paddleL.addPoint();
        }
        this->spawn();
    }

    if(this->right && this->up)
    {
        this->rs.move({this->speedx, -this->speedy});
    }
    else if(this->right && this->down)
    {
        this->rs.move({this->speedx, this->speedy});
    }
    else if(this->left && this->up)
    {
        this->rs.move({-this->speedx, -this->speedy});
    }
    else if(this->left && this->down)
    {
        this->rs.move({-this->speedx, this->speedy});
    }
    else if(this->left)
    {
        this->rs.move({-this->speedx, 0.f});
    }
    else if(this->right)
    {
        this->rs.move({this->speedx, 0.f});
    }
    else if(this->down)
    {
        this->rs.move({0.f, this->speedy});
    }
    else if(this->up)
    {
        this->rs.move({0.f, -this->speedy});
    }
    this->x = this->rs.getPosition().x; 
    this->y = this->rs.getPosition().y;
}

void Ball::paddleCollision(Paddle paddleL, Paddle paddleR)
{

    if (this->rs.getGlobalBounds().findIntersection(paddleL.rect().getGlobalBounds()).has_value())
    {
        this->speedx = 10.f;
        this->speedy = 15.f;
        this->right = true;
        this->left = false;
        if(this->rs.getGlobalBounds().getCenter().y > paddleL.rect().getGlobalBounds().getCenter().y + 8.f)
        {
            this->speedx = 10.f;
            this->speedx = 10.f;
            this->up = false;
            this->down = true;
        }
        
        else if(this->rs.getGlobalBounds().getCenter().y < paddleL.rect().getGlobalBounds().getCenter().y - 8.f)
        {
            this->speedx = 10.f;
            this->speedx = 10.f;
            this->up = true;
            this->down = false;
        }
        else
        {
            this->speedx = 10.f;
            this->speedx = 10.f;
            this->up = false;
            this->down = false;
        }

    }
    if (this->rs.getGlobalBounds().findIntersection(paddleR.rect().getGlobalBounds()).has_value())
    {
        this->speedx = 10.f;
        this->speedy = 15.f;
        this->right = false;
        this->left = true;
        if(this->rs.getGlobalBounds().getCenter().y > paddleR.rect().getGlobalBounds().getCenter().y + 8.f)
        {
            this->speedx = 10.f;
            this->speedx = 10.f;
            this->up = false;
            this->down = true;
        }
        
        else if(this->rs.getGlobalBounds().getCenter().y < paddleR.rect().getGlobalBounds().getCenter().y - 8.f)
        {
            this->speedx = 10.f;
            this->speedx = 10.f;
            this->up = true;
            this->down = false;
        }
        else
        {
            this->speedx = 10.f;
            this->speedx = 10.f;
            this->up = false;
            this->down = false;
        }
    }
}

void Ball::spawn()
{
    auto dur = std::chrono::high_resolution_clock::now() - this->spawnTimer;
    if(std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() > 500)
    {
        int offset = (rand() % 400) - 200;
        float centerBv = (480 / 2) - 7 + offset;
        float centerBh = (640 / 2) - 7;
        this->rs.setPosition({centerBh, centerBv});
        this->getTime = true;
        this->right = this->left;
        this->left = !this->left;
        if(offset % 2)
        {
            this->down = true;
            this->up = false;
        }
        else
        {
            this->down = false;
            this->up = true;
        }
        this->speedx = 5.f;
        this->speedy = 5.f;
    }

}