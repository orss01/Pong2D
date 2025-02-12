#ifndef GAME_HPP
#define GAME_HPP

#include "Paddle.hpp"
#include "Ball.hpp"
#include <SFML/Graphics.hpp>
#include <vector>


class Game
    {
        private:
            unsigned WIDTH = 640u;
            unsigned HEIGHT = 480u;
            float PADDLE_SPEED = 10.f;
            float BALL_SPEED = 10.f;

            sf::RenderWindow *window;
            sf::VideoMode videoMode;

            //Objects
            Paddle *paddleL;
            Paddle *paddleR;
            Ball *ball;
            std::vector<sf::RectangleShape> ballWall;


            //Functions
            void initWindow();
            void renderObjects();
            void initObjects();
            
        public:
            Game();
            ~Game();

            //Functions
            bool running();
            void pollEvents();
            void keyboardInput();
            void update();
            void render();
    };

#endif