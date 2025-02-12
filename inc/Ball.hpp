#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball
{
    private:
    float x;
    float y;
    float DIMENSION = 14.f;

    sf::RectangleShape rs;

    bool right;
    bool left;
    bool up;
    bool down;

    //Functions
    void initRect();


    public:
    Ball();
    Ball(float x, float y);
    ~Ball();
    sf::Vector2f getPosition();
    sf::RectangleShape rect();
    void updateBall(float speed,  float bottomWindow, float rightWindow);

};

#endif