#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game
    {
        private:
            sf::RenderWindow *window;
            sf::VideoMode videoMode;
            sf::RectangleShape paddle;

            //Functions
            void initWindow();
            void renderPaddle();
            void initPaddle();
            
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