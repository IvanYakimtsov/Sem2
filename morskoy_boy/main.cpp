#include <iostream>
#include "game.h"
using namespace std;


int main()
{
    GameBust *game = new GameBust();
    game->gameSetUp();
    game->startPlaying();
    return 0;
}
