#ifndef _PAWN_HPP_
#define _PAWN_HPP_
#include "Pitch.hpp"
#include "Ball.hpp"
#include "GeometricVector.hpp"
#include "SoccerStarsConst.hpp"
#include "rsdl.hpp"
#include "MathFunctions.hpp"

class Pawn
{
public:
    Pawn(int x, int y, int radius = PAWN_RADIUS, Pitch* pitch = nullptr, Window* window = nullptr, int mass = PAWN_MASS);
    Pawn(Point _center, int radius = PAWN_RADIUS, Pitch* pitch = nullptr, Window* window = nullptr, int mass = PAWN_MASS);
    Point getCenter();
    void setCenter(Point _center);
    int getRadius();
    bool contains(Point point);
    void setWindow(Window* window);
    void moveProcedure();
    void advanceTime();
    void rewindTime(Time time);
    bool isMoving();
    void processCollisionWith(Ball ball, Time time);
    void processCollisionWith(Pawn pawn, Time time);
    void processCollisionWithWall(); 
    GeometricVector getVelocity();
    float getMass();
    bool doesCollideWith(Ball ball);
    bool doesCollideWith(Pawn pawn);
    void updateAfterCollision();
    void draw(RGB color);
private:
    Point center;
    GeometricVector velocity;
    GeometricVector newVelocity;
    bool hadCollision;
    int radius;
    Pitch* pitch;
    Window* gameWindow;
    float mass;
    void release(Point point);
    bool processEvent(Event event);
    void updateVelocity();
    bool outOfBounds();
    void reflectX(bool changed);
    void reflectY(bool changed);


};

#endif