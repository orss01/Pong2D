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
    initRect();
}

Ball::Ball(float x, float y)
{
    this->x = x;
    this->y = y;
    this->right = true;
    this->left = false;
    this->up = false;
    this->down = false;
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

void Ball::updateBall(float speed, float bottomWindow, float rightWindow)
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
        this->right = true;
        this->left = false;
    }
    if(this->x > rightWindow - 14)
    {
        this->right = false;
        this->left = true;
    }

    if(this->right && this->up)
    {
        this->rs.move({speed, -speed});
    }
    else if(this->right && this->down)
    {
        this->rs.move({speed, speed});
    }
    else if(this->left && this->up)
    {
        this->rs.move({-speed, -speed});
    }
    else if(this->left && this->down)
    {
        this->rs.move({-speed, speed});
    }
    else if(this->left)
    {
        this->rs.move({-speed, 0.f});
    }
    else if(this->right)
    {
        this->rs.move({speed, 0.f});
    }
    else if(this->down)
    {
        this->rs.move({0.f, speed});
    }
    else if(this->up)
    {
        this->rs.move({0.f, -speed});
    }
    this->x = this->rs.getPosition().x; 
    this->y = this->rs.getPosition().y;
}