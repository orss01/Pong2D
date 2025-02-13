#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle{
    private:
    float WIDTH = 15.f;
    float HEIGHT = 75.f;
    float x;
    float y;
    sf::RectangleShape rs;

    bool up;
    bool down;

    //functions
    void initRect();

    public:
    Paddle();
    Paddle(float x, float y);
    ~Paddle();
    sf::RectangleShape rect();
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    void moveVertical(float speed, float windowBottom);
    float getPaddleHeight();
    void updatePaddle();
    void goingUp();
    void goingDown();
    bool getUp();
    bool getDown();
};

#endif