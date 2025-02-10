#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

class Game
    {
        private:
            unsigned WIDTH = 640u;
            unsigned HEIGHT = 480u;
            float PADDLE_SPEED = 1.f;

            sf::RenderWindow *window;
            sf::VideoMode videoMode;
            sf::RectangleShape paddle;
            sf::Clock clock;

            //Objects
            Paddle *paddleL;
            Paddle *paddleR;

            //Functions
            void initWindow();
            void renderPaddles();
            void initPaddles();
            
        public:
            Game();
            ~Game();

            //Functions
            bool running();
            void pollEvents();
            void update();
            void render();
    };

#endif