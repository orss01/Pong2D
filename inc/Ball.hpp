#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"
#include <chrono>

class Ball
{
    private:
    float x;
    float y;
    float DIMENSION = 14.f;
    float speed;

    sf::RectangleShape rs;

    bool right;
    bool left;
    bool up;
    bool down;

    bool getTime;
    std::chrono::high_resolution_clock::time_point spawnTimer;

    //Functions
    void initRect();


    public:
    Ball();
    Ball(float x, float y);
    ~Ball();
    sf::Vector2f getPosition();
    sf::RectangleShape rect();
    void updateBall(float bottomWindow, float rightWindow);
    void paddleCollision(Paddle paddleL, Paddle paddleR);
    void spawn();

};

#endif