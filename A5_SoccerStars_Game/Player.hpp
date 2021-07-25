#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_
#include "Pawn.hpp"
#include "SoccerStarsConst.hpp"
#include <vector>
#include <utility>
struct Player
{
    Player();
    std::vector<Pawn> pawns;
    int gameScore;
    int roundScore;
    bool status;
};




#endif