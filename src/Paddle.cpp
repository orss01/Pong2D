#include "Paddle.hpp"

Paddle::Paddle()
{
    this->x = 0;
    this->y = 0;
    initRect();
}

Paddle::Paddle(float x, float y)
{
    this->x = x;
    this->y = y;
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

void Paddle::moveVertical(float speed)
{
    this->rs.move({0.f, speed});
    this->y = this->rs.getPosition().y;
}