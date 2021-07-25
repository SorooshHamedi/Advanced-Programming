#ifndef _BALL_HPP_
#define _BALL_HPP_
#include "rsdl.hpp"
#include "Pitch.hpp"
#include "GeometricVector.hpp"
#include "SoccerStarsConst.hpp"
#include "MathFunctions.hpp"

class Ball
{
public:
    Ball(Point center = PITCH_CENTER, int radius = BALL_RADIUS, Pitch* pitch = nullptr, int mass = BALL_MASS, Window* gameWindow = nullptr);
    Ball();
    Point getCenter();
    void setWindow(Window* _window);
    void setCenter(Point center);
    void advanceTime();
    void rewindTime(Time time);
    int getRadius();
    bool isMoving();
    float getMass();
    GeometricVector getVelocity();
    void processCollisionWith(Point pawnCenter, GeometricVector pawnVelocity, float pawnMass, Time time);
    void processCollisionWithWall();
    int checkForGoal();
    void updateAfterCollision();
    void draw(RGB color = BALL_COLOR);
private:
    Point center;  
    int radius;  
    GeometricVector velocity;
    Pitch* pitch;
    float mass;
    GeometricVector newVelocity;
    Window* gameWindow;
    bool hadCollision;
    void updateVelocity();
    bool outOfBounds();
    void reflectX(bool changed);
    void reflectY(bool changed);
};

#endif