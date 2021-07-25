#include <iostream>
using namespace std;
#include "SoccerStars.hpp"

int main()
{
    SoccerStars game;
    game.openGame();
    while(true)
    {
        game.update();
    }
    return 0;
}