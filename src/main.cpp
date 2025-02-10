#include "Game.hpp"

int main() 
{
    Game *game= new Game();
    while (game->running())
    {
        game->pollEvents();
        game->keyboardInput();
        game->update();
        game->render();
    }
    
}