#include "Game.hpp"
#include <cstdlib>
#include <ctime>

int main() 
{
    srand(time(0));
    Game *game= new Game();
    while (game->running())
    {
        game->pollEvents();
        game->keyboardInput();
        game->update();
        game->render();
    }
    
}