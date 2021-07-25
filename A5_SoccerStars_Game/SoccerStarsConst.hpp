#ifndef _SOCCER_STARS_CONST_HPP_
#define _SOCCER_STARS_CONST_HPP_
#include <utility>
#include "rsdl.hpp"

typedef float Time;

const int PAWN_RADIUS = 20;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT= 480;
const int PITCH_WIDTH = 800;
const int PITCH_HEIGHT = 480;
const int TOP_TEXT_MARGIN = 0;

const Point PITCH_TOP_LEFT(0,0);
const Point FIRST_PLAYER_NAME_TEXT_POINT(10,PITCH_HEIGHT  + 50);
const Point SECOND_PLAYER_NAME_TEXT_POINT(400,PITCH_HEIGHT + 50);
const Point FIRST_PLAYER_ROUND_SCORE_POINT(PITCH_WIDTH/2 - 50, PITCH_HEIGHT + 90);
const Point SECOND_PLAYER_ROUND_SCORE_POINT(PITCH_WIDTH/2 + 50, PITCH_HEIGHT  + 90);
const Point FIRST_PLAYER_GOAL_SCORE_POINT(PITCH_WIDTH/2 - 10, 40);
const Point SECOND_PLAYER_GOAL_SCORE_POINT(PITCH_WIDTH/2 + 10, 40);
const Point ROUNDS_LEFT_TEXT_POINT(70,15);
const Point GAME_OVER_TEXT_POINT(300,20);
const Point RESULT_TEXT_POINT(600, 20);
const std::string WINDOW_NAME = "Soccer Stars";
const int BALL_RADIUS = 10;

const std::string ROUNDS_LEFT_TEXT = "Rounds left: ";
const std::string SECOND_PLAYER_TEXT = "Player 2";
const std::string FIRST_PLAYER_TEXT = "Player 1";
const std::string GOALS_TEXT = "Goals: ";
const std::string ROUNDS_TEXT = "Rounds won: ";
const std::string GAME_OVER_TEXT = "Game over";
const std::string WIN_TEXT = " has won!";
const std::string DRAW_TEXT = "It's a draw!";
const std::string FREE_SANS_ADDRESS = "FreeSans-LrmZ.ttf";
const int NUMBER_OF_PLAYERS = 2;
const RGB BALL_COLOR = WHITE;
const RGB PLAYER_COLORS[NUMBER_OF_PLAYERS] = {BLUE, RED};
const RGB PITCH_COLOR(118, 184, 35);
const Point PITCH_CENTER(PITCH_WIDTH/2, PITCH_HEIGHT/2 + TOP_TEXT_MARGIN);

const float CLIPPING_MARGIN = 5;
const float SAFE_CLIPPING_DISTANCE_PAWNS = 2*PAWN_RADIUS + CLIPPING_MARGIN;
const float SAFE_CLIPPING_DISTANCE_BALL_PAWN = PAWN_RADIUS + BALL_RADIUS + CLIPPING_MARGIN;

const int FIRST_PLAYER = 0;
const int SECOND_PLAYER = 1;
const int NUMBER_OF_PAWNS_PER_PLAYER = 5;
const int DEFENDER_MARGIN_1211 = 100;
const int GOALKEEPER_MARGIN_1211 = PAWN_RADIUS + CLIPPING_MARGIN;
const int FIRST_ATTACKER_MARGIN_1211 = DEFENDER_MARGIN_1211*2;
const int SECOND_ATTACKER_MARGIN_1211 = PITCH_CENTER.x - PAWN_RADIUS - 20;
const Point ONE_TWO_ONE_ONE_FORMATION[NUMBER_OF_PLAYERS][NUMBER_OF_PAWNS_PER_PLAYER] = 
                                                {
                                                    { 
                                                        {GOALKEEPER_MARGIN_1211,PITCH_HEIGHT/2 + TOP_TEXT_MARGIN}, 
                                                        {DEFENDER_MARGIN_1211, PITCH_HEIGHT/4 + TOP_TEXT_MARGIN},
                                                        {DEFENDER_MARGIN_1211, (PITCH_HEIGHT/4)*3 + TOP_TEXT_MARGIN},
                                                        {FIRST_ATTACKER_MARGIN_1211, PITCH_HEIGHT/2 + TOP_TEXT_MARGIN},
                                                        {SECOND_ATTACKER_MARGIN_1211, PITCH_HEIGHT/2 + TOP_TEXT_MARGIN}
                                                    },
                                                    {
                                                        {PITCH_WIDTH-GOALKEEPER_MARGIN_1211, PITCH_HEIGHT/2 + TOP_TEXT_MARGIN},
                                                        {PITCH_WIDTH-DEFENDER_MARGIN_1211, PITCH_HEIGHT/4 + TOP_TEXT_MARGIN},
                                                        {PITCH_WIDTH-DEFENDER_MARGIN_1211, (PITCH_HEIGHT/4)*3 + TOP_TEXT_MARGIN},
                                                        {PITCH_WIDTH-FIRST_ATTACKER_MARGIN_1211, PITCH_HEIGHT/2 + TOP_TEXT_MARGIN},
                                                        {PITCH_WIDTH-SECOND_ATTACKER_MARGIN_1211, PITCH_HEIGHT/2 + TOP_TEXT_MARGIN} 
                                                    }
                                                };
const int MAX_THROW_RADIUS = 60;
const int MAX_INITIAL_SPEED = 1000;
const Point TOP_LEFT(0,0); 
const int FRICTION_ACCERALATION = 300;
const Time TIME_PASSED_PER_FRAME = 1.00/60.00;
const bool RELEASED = true;
const bool NOT_RELEASED = false;
const float PAWN_MASS = 2;
const float BALL_MASS = 1;
const int GOAL_FIRST_POST = 160;
const int GOAL_SECOND_POST = 320;
const int GOAL_WIDTH = 60; 
const int GOAL_HEIGHT = GOAL_SECOND_POST - GOAL_FIRST_POST;
const Point LEFT_GOAL_TOP_LEFT(0, GOAL_FIRST_POST);
const Point RIGHT_GOAL_TOP_LEFT(PITCH_WIDTH-GOAL_WIDTH, GOAL_FIRST_POST);
const int NO_GOAL = -1;
const int VELOCITY_REFLECT_FACTOR = -1;
#endif