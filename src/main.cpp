#include "Game.hpp"

int main() 
{
    Game *game= new Game();
    while (game->running())
    {
        game->pollEvents();
        game->update();
        game->render();
    }
    
}