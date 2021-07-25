#include "SoccerStars.hpp"
using namespace std;


const int DELAY_LENGTH = 25;
SoccerStars::SoccerStars() : pitch(), ball(PITCH_CENTER, BALL_RADIUS, &pitch)
{
    players[FIRST_PLAYER].gameScore = players[SECOND_PLAYER].gameScore
                = players[FIRST_PLAYER].roundScore = players[SECOND_PLAYER].roundScore = 0;
    turn = FIRST_PLAYER;
    numberOfRounds = 0;
    goalsToEnd = 0;
    ongoingRound = true;
    ballInPlay = true;
}

void SoccerStars::openGame()
{
    gameWindow = new Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    ball.setWindow(gameWindow);
    getInput();
    createPawns();
    updateScreen();
}

void SoccerStars::getInput()
{
    cin >> numberOfRounds;
    cin >> goalsToEnd;
}
void SoccerStars::update()
{
    while(gameWindow->has_pending_event())
    {
        processEvent(gameWindow->poll_for_event());
    }
}

void SoccerStars::changeTurn()
{
    turn = 1-turn;
}

void SoccerStars::drawPawns()
{
    drawPawnsForPlayer(FIRST_PLAYER);
    drawPawnsForPlayer(SECOND_PLAYER);
    gameWindow->update_screen();
}

void SoccerStars::drawPawnsForPlayer(int index)
{
    for(Pawn pawn:players[index].pawns)
    {
        pawn.draw(PLAYER_COLORS[index]);
    }
}
void SoccerStars::createPawns()
{
    for(int i=0; i<NUMBER_OF_PLAYERS; i++)
    {
        createPawnsForPlayer(i);
    }
}

void SoccerStars::createPawnsForPlayer(int index)
{
    for(Point coordination:ONE_TWO_ONE_ONE_FORMATION[index])
    {
        players[index].pawns.push_back(Pawn(coordination, PAWN_RADIUS, &pitch, gameWindow));
    }
}

void SoccerStars::drawPitch(Point topLeft, RGB color)
{
    gameWindow->fill_rect(Rectangle(topLeft, pitch.getWidth(), pitch.getHeight()), color);
    gameWindow->draw_line(Point(WINDOW_WIDTH/2,0) , Point(WINDOW_WIDTH/2, WINDOW_HEIGHT));
    gameWindow->fill_rect(Rectangle(LEFT_GOAL_TOP_LEFT, GOAL_WIDTH, GOAL_HEIGHT), WHITE);
    gameWindow->fill_rect(Rectangle(RIGHT_GOAL_TOP_LEFT, GOAL_WIDTH, GOAL_HEIGHT), WHITE);
    gameWindow->update_screen();
    
}

void SoccerStars::processEvent(Event event)
{
    switch(event.get_type())
    {
        case Event::LCLICK:
        {
            movePawnProcedure(turn, get_current_mouse_position());
            renderMovements();
            if(!ballInPlay)
            {
                startNewRound();
                return;
            }
            changeTurn();
            break;
        }
        case Event::LRELEASE:
        {
            break;
        }
        case Event::MMOTION:
        {
            break;
        }
        case Event::QUIT:
        {
            quitGame();
            break;
        }
        default:;
    }
}

void SoccerStars::movePawnProcedure(int playerIndex, Point mousePosition)
{
    for(Pawn& pawn:players[playerIndex].pawns)
    {
        if(pawn.contains(mousePosition))
        {
               pawn.moveProcedure();
               return;
        }
    }
}

void SoccerStars::renderMovements()
{
    while(thereIsAMovingObject())
    {
        updateObjectPositions();
        if(ball.checkForGoal() != NO_GOAL)
        {
            goalScoredProcedure(ball.checkForGoal());
            return;
        }
        updateScreen();
        processCollisions();
    }
}

bool SoccerStars::thereIsAMovingObject()
{
    for(int i=0; i<NUMBER_OF_PLAYERS; i++)
    {
        if(thereIsAMovingObjectForPlayer(i))
        {
            return true;
        }
    }
    return ball.isMoving();
}

bool SoccerStars::thereIsAMovingObjectForPlayer(int index)
{
    for(Pawn pawn:players[index].pawns)
    {
        if(pawn.isMoving())
        {
            return true;
        }
    }
}
void SoccerStars::quitGame()
{
    delete gameWindow;
    _Exit(0);
}

void SoccerStars::updateScreen()
{
    drawObjects();
    //showAllTexts();
    delay(DELAY_LENGTH);
}

void SoccerStars::drawObjects()
{
    drawPitch(PITCH_TOP_LEFT, PITCH_COLOR);
    gameWindow->update_screen();
    drawPawns();
    ball.draw();
}

void SoccerStars::updateObjectPositions()
{
    updatePawnsPositions();
    ball.advanceTime();
}

void SoccerStars::updatePawnsPositions()
{
    for(int i=0 ; i<NUMBER_OF_PLAYERS; i++)
    {
        updatePawnPositionsForPlayer(i);
    }
}

void SoccerStars::updatePawnPositionsForPlayer(int index)
{
    for(Pawn& pawn:players[index].pawns)
    {
        pawn.advanceTime();
    }
}

void SoccerStars::processCollisions()
{
    processCollisionsWithBall();
    processCollisionsBetweenPawns();
    updateAfterCollision();
}

void SoccerStars::processCollisionsWithWall()
{
    for(int i=0 ; i<NUMBER_OF_PLAYERS; i++)
    {
        processCollisionsWithWallForPlayer(i);
    }
    ball.processCollisionWithWall();
}

void SoccerStars::processCollisionsWithBall()
{
    for(int i=0 ; i<NUMBER_OF_PLAYERS; i++)
    {
        processCollisionsWithBallForPlayer(i);
    }
}

void SoccerStars::processCollisionsBetweenPawns()
{
    processCollisionsBetweenPawnsForPlayer(FIRST_PLAYER);
    processCollisionsBetweenPawnsForPlayer(SECOND_PLAYER);
    
    for(int i=0; i<NUMBER_OF_PAWNS_PER_PLAYER; i++)
    {
        for(int j=0; j<NUMBER_OF_PAWNS_PER_PLAYER; j++)
        {
            if(players[FIRST_PLAYER].pawns[j].doesCollideWith(players[SECOND_PLAYER].pawns[i]))
            {
                Time time = calculateNecessaryRewindTwoPawns(players[FIRST_PLAYER].pawns[i],  players[SECOND_PLAYER].pawns[j]);
                players[FIRST_PLAYER].pawns[i].processCollisionWith(players[SECOND_PLAYER].pawns[j], time);
                players[SECOND_PLAYER].pawns[j].processCollisionWith(players[FIRST_PLAYER].pawns[i], time);
            }
        }
    }
}

Time SoccerStars::calculateNecessaryRewindTwoPawns(Pawn a, Pawn b)
{
    Point aCenter = a.getCenter();
    Point bCenter = b.getCenter();
    Time begin = 0.00, end = TIME_PASSED_PER_FRAME;
    Time mid;
    if(distance(aCenter, bCenter) == 2*PAWN_RADIUS)
    {
        return begin;
    }
    while(begin < end)
    {
        mid = (begin+end)/2;
        a.setCenter(aCenter);
        b.setCenter(bCenter);
        a.rewindTime(mid);
        b.rewindTime(mid);

        if(a.doesCollideWith(b))
        {
            begin = mid+1;
        }
        else if(distance(a.getCenter(), b.getCenter()) > SAFE_CLIPPING_DISTANCE_PAWNS)
        {
            end = mid-1;
        }
        else
        {
            return mid;
        }   
    } 
    return mid;
}

void SoccerStars::processCollisionsBetweenPawnsForPlayer(int index)
{
    for(int i=0; i<NUMBER_OF_PAWNS_PER_PLAYER; i++)
    {
        for(int j=i+1; j<NUMBER_OF_PAWNS_PER_PLAYER; j++)
        {
            if(players[index].pawns[i].doesCollideWith(players[index].pawns[j]))
            {
                Time time = calculateNecessaryRewindTwoPawns(players[index].pawns[i],  players[index].pawns[j]);
                players[index].pawns[i].processCollisionWith(players[index].pawns[j], time);
                players[index].pawns[j].processCollisionWith(players[index].pawns[i], time);
            }
        }
    }
}
void SoccerStars::processCollisionsWithWallForPlayer(int index)
{
    for(Pawn& pawn:players[index].pawns)
    {
        pawn.processCollisionWithWall();
    }
}

void SoccerStars::processCollisionsWithBallForPlayer(int index)
{
    for(Pawn& pawn:players[index].pawns)
    {
        if(pawn.doesCollideWith(ball))
        {
            int time = calculateNecessaryRewindPawnAndBall(pawn, ball);
            pawn.processCollisionWith(ball, time);
            ball.processCollisionWith(pawn.getCenter(), pawn.getVelocity(), pawn.getMass(), time);
        }
    }
}

Time SoccerStars::calculateNecessaryRewindPawnAndBall(Pawn a, Ball b)
{
    Point aCenter = a.getCenter();
    Point bCenter = b.getCenter();
    Time begin = 0.00, end = TIME_PASSED_PER_FRAME;
    Time mid;

    if(distance(aCenter, bCenter) == PAWN_RADIUS + BALL_RADIUS)
    {
        return begin;
    }

    while(begin < end)
    {
        a.setCenter(aCenter);
        b.setCenter(bCenter);
        mid = (begin+end)/2.00;
        a.rewindTime(mid);
        b.rewindTime(mid);
        if(a.doesCollideWith(b))
        {
            begin = mid+1;
        }
        else if(distance(a.getCenter(), b.getCenter()) > SAFE_CLIPPING_DISTANCE_BALL_PAWN)
        {
            end = mid-1;
        }
        else
        {
            return mid;
        }   
    } 
    return mid;
}

void SoccerStars::showAllTexts()
{
    //showText(ROUNDS_LEFT_TEXT+to_string(numberOfRounds), ROUNDS_LEFT_TEXT_POINT);
    showText(FIRST_PLAYER_TEXT, FIRST_PLAYER_NAME_TEXT_POINT);
    //showText(to_string(players[FIRST_PLAYER].gameScore), FIRST_PLAYER_GOAL_SCORE_POINT);
    showText(to_string(players[FIRST_PLAYER].roundScore), FIRST_PLAYER_ROUND_SCORE_POINT);
    //showText(SECOND_PLAYER_TEXT, SECOND_PLAYER_NAME_TEXT_POINT);
    showText(to_string(players[SECOND_PLAYER].gameScore), SECOND_PLAYER_GOAL_SCORE_POINT);
    showText(to_string(players[SECOND_PLAYER].roundScore), SECOND_PLAYER_ROUND_SCORE_POINT);
    gameWindow->update_screen();
}

void SoccerStars::showText(string text, Point point, RGB color)
{
    gameWindow->show_text(text, point, color, FREE_SANS_ADDRESS);
    gameWindow->update_screen();
}

void SoccerStars::goalScoredProcedure(int index)
{
    ballInPlay = false;
    players[index].gameScore++;
    if(players[index].gameScore == goalsToEnd)
    {
        players[index].roundScore++;
        numberOfRounds--;
        if(!numberOfRounds)
        {
            endGameProcedure();
        }
    }
}

void SoccerStars::startNewRound()
{
    ballInPlay = true;
    turn = FIRST_PLAYER;
    ball.setCenter(PITCH_CENTER);
    resetPawns();
    updateScreen();
}

void SoccerStars::resetPawns()
{
    for(int i=0 ; i<NUMBER_OF_PLAYERS; i++)
    {
        resetPawnsForPlayer(i);
    }
}

void SoccerStars::resetPawnsForPlayer(int index)
{
    for(int i=0 ; i<NUMBER_OF_PAWNS_PER_PLAYER; i++)
    {
        players[index].pawns[i].setCenter(ONE_TWO_ONE_ONE_FORMATION[index][i]);
    }
}

void SoccerStars::endGameProcedure()
{
    showText(GAME_OVER_TEXT, GAME_OVER_TEXT_POINT);
    if(players[FIRST_PLAYER].roundScore > players[SECOND_PLAYER].roundScore)
    {
        showText(FIRST_PLAYER_TEXT + WIN_TEXT, RESULT_TEXT_POINT);
    }
    else if(players[SECOND_PLAYER].roundScore > players[FIRST_PLAYER].roundScore)
    {
        showText(SECOND_PLAYER_TEXT + WIN_TEXT, RESULT_TEXT_POINT);
    }
    else
    {
        showText(DRAW_TEXT, RESULT_TEXT_POINT);
    }
    
}

void SoccerStars::updateAfterCollision()
{  
    ball.updateAfterCollision();
    updatePawnsAfterCollisionPlayer(FIRST_PLAYER);
    updatePawnsAfterCollisionPlayer(SECOND_PLAYER);
}

void SoccerStars::updatePawnsAfterCollisionPlayer(int index)
{
    for(Pawn& pawn:players[index].pawns)
    {
        pawn.updateAfterCollision();
    }
}
