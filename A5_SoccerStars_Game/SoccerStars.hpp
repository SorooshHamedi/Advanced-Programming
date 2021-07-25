#ifndef _SOCCER_STARS_HPP_
#define _SOCCER_STARS_HPP_
#include "Pawn.hpp"
#include "Pitch.hpp"
#include "rsdl.hpp"
#include "SoccerStarsConst.hpp"
#include "Ball.hpp"
#include "Player.hpp"
#include <vector>
#include <utility>
#include <string>
#include <iostream>
class SoccerStars
{
public:
    SoccerStars();
    void openGame();
    void update();
private:
    Window* gameWindow;
    Player players[NUMBER_OF_PLAYERS];
    int gameScore[NUMBER_OF_PLAYERS];
    int roundScore[NUMBER_OF_PLAYERS];
    int turn;
    Pitch pitch;
    Ball ball;
    int goalsToEnd;
    int numberOfRounds;
    bool ongoingRound;
    bool ballInPlay;
    void getInput();
    void drawPitch(Point topLeft, RGB color);
    void processEvent(Event event);
    void quitGame();
    void drawPawns();
    void drawPawnsForPlayer(int index);
    void createPawns();
    void createPawnsForPlayer(int index);
    void movePawnProcedure(int playerIndex, Point mousePosition);
    void renderMovements();
    void updateObjectPositions();
    void updateScreen();
    void drawObjects();
    void updatePawnsPositions();
    void updatePawnPositionsForPlayer(int index);
    bool thereIsAMovingObject();
    bool thereIsAMovingObjectForPlayer(int index);
    void changeTurn();
    void processCollisions();
    void processCollisionsWithWall();
    void processCollisionsWithBall();
    void processCollisionsBetweenPawns();    
    void processCollisionsWithWallForPlayer(int index);
    void processCollisionsWithBallForPlayer(int index);
    void processCollisionsBetweenPawnsForPlayer(int index);
    Time calculateNecessaryRewindTwoPawns(Pawn a, Pawn b);
    Time calculateNecessaryRewindPawnAndBall(Pawn a, Ball b);
    void showScores();
    void showRoundsLeft();
    void showAllTexts();
    void showText(std::string text, Point point, RGB color = WHITE);
    void goalScoredProcedure(int index);
    void startNewRound();
    void endGameProcedure();
    void resetPawns();
    void resetPawnsForPlayer(int index);
    void updateAfterCollision();
    void updatePawnsAfterCollisionPlayer(int index);
};
#endif