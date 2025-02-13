#include "Paddle.hpp"

Paddle::Paddle()
{
    this->x = 0;
    this->y = 0;
    this->up = false;
    this->down = false;
    initRect();
}

Paddle::Paddle(float x, float y)
{
    this->x = x - 7;
    this->y = y - 7;
    this->up = false;
    this->down = false;
    initRect();
}

Paddle::~Paddle()
{

}

void Paddle::initRect()
{
    this->rs.setSize(sf::Vector2f({this->WIDTH, this->HEIGHT}));
    this->rs.setPosition(this->getPosition());
}

sf::RectangleShape Paddle::rect()
{
    return this->rs;
}

sf::Vector2f Paddle::getPosition()
{
    return sf::Vector2f({this->x, this->y});
}

void Paddle::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Paddle::moveVertical(float speed, float windowBottom)
{
    if(this->y >= 0 && this->y <= windowBottom)
    {
        this->rs.move({0.f, speed});
        this->y = this->rs.getPosition().y;
    }
    if(this->y < 0)
    {
        this->y = 0;
    }
    if(this->y > windowBottom)
    {
        this->y = windowBottom;
    }
}

float Paddle::getPaddleHeight()
{
    return this->HEIGHT;
}

void Paddle::updatePaddle()
{
    this->rs.setPosition({this->x, this->y});
}

void Paddle::goingUp()
{
    this->up = true;
    this->down = false;
}

void Paddle::goingDown()
{
    this->up = false;
    this->down = true;
}

bool Paddle::getUp()
{
    return  this->up;
}

bool Paddle::getDown()
{
    return  this->down;
}
