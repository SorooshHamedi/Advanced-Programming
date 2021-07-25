#include "Pawn.hpp"
#include <iostream>

Pawn::Pawn(int x, int y, int _radius, Pitch* _pitch, Window* window, int _mass) : center(x,y), velocity(0,0), newVelocity(0,0)
{
    radius = _radius;
    pitch = _pitch; 
    gameWindow = window;
    mass = _mass;
    hadCollision = false;
}

Pawn::Pawn(Point _center, int _radius, Pitch* _pitch, Window* window, int _mass) : center(_center.x, _center.y), velocity(0,0), newVelocity(0,0)
{
    radius = _radius;
    pitch = _pitch; 
    gameWindow = window;
    mass = _mass;
    hadCollision = false;
}


Point Pawn::getCenter()
{
    return center;
}

void Pawn::setCenter(Point _center)
{
    center = _center;
}

int Pawn::getRadius()
{
    return radius;
}

bool Pawn::contains(Point point)
{
    return distance(center,point) <= (float) radius;
}

void Pawn::setWindow(Window* window)
{
    gameWindow = window;
}

void Pawn::moveProcedure()
{
    while(true)
    {
        while(gameWindow->has_pending_event())
        {
            if(processEvent(gameWindow->poll_for_event()) == RELEASED)
            {
                return;
            }            
            
        }
    }
}

bool Pawn::processEvent(Event event)
{
    switch(event.get_type())
    {
        case Event::LRELEASE:
        {                    
            release(get_current_mouse_position());
            return RELEASED;
        }
        case Event::MMOTION:
        case Event::LCLICK:
        {
            return NOT_RELEASED;
        }
    }
}
void Pawn::release(Point point)
{
    GeometricVector distanceVec((point - center).x, (point-center).y); 
    float dis = size(distanceVec);
    if( dis < MAX_THROW_RADIUS)
    {
        velocity = multiply(multiply(distanceVec, (-1.00/MAX_THROW_RADIUS)), MAX_INITIAL_SPEED);
    }
    else
    {
        velocity = multiply(multiply(distanceVec, (-1.00/dis)), MAX_INITIAL_SPEED);
    }
}

void Pawn::advanceTime()
{
    center.x += velocity.x * TIME_PASSED_PER_FRAME;
    
    center.y += velocity.y * TIME_PASSED_PER_FRAME;
    updateVelocity();
}

void Pawn::rewindTime(Time time)
{
    center.x -= velocity.x * time;
    center.y -= velocity.y * time;
}

void Pawn::updateVelocity()
{
    float decreasedVelocity = FRICTION_ACCERALATION * TIME_PASSED_PER_FRAME;
    if(velocity.x > 0)
    {
        velocity.x = std::max((float)0,velocity.x-decreasedVelocity);
    }
    else
    {
        velocity.x = std::min((float)0, velocity.x+decreasedVelocity);
    }

    if(velocity.y > 0)
    {
        velocity.y = std::max((float)0,velocity.y-decreasedVelocity);
    }
    else
    {
        velocity.y = std::min((float)0, velocity.y+decreasedVelocity);
    }
}

bool Pawn::isMoving()
{
    return (velocity.x != 0) || (velocity.y != 0);
}

void Pawn::processCollisionWith(Ball ball, Time time)
{
    hadCollision = true;
    rewindTime(time);
    float ballMass = ball.getMass();
    Point difference = center - ball.getCenter();
    float diffSize = size(difference);
    GeometricVector velocityDifference = subtract(velocity, ball.getVelocity());
    float constFactor = (1.00/pow(diffSize,2)) * ((2*ballMass)/(ballMass+mass));
    GeometricVector tempVelocity = multiply(difference, dotProduct(velocityDifference, difference));
    tempVelocity = multiply(tempVelocity, constFactor);
    newVelocity = subtract(velocity, tempVelocity);
}

void Pawn::processCollisionWith(Pawn pawn, Time time)
{
    hadCollision = true;
    rewindTime(time);
    float pawnMass = pawn.getMass();
    Point difference = center - pawn.getCenter();
    float diffSize = size(difference);
    GeometricVector velocityDifference = subtract(velocity, pawn.getVelocity());
    float constFactor = (1/pow(diffSize,2)) * ((2*pawnMass)/(pawnMass+mass));
    GeometricVector tempVelocity = multiply(difference, dotProduct(velocityDifference, difference));
    tempVelocity = multiply(tempVelocity, constFactor);
    newVelocity = subtract(velocity, tempVelocity);
}

void Pawn::processCollisionWithWall()
{
    if(center.x < radius)
    {
        center.x = radius + CLIPPING_MARGIN;
        velocity.x *= VELOCITY_REFLECT_FACTOR;
    }

    if(center.x > pitch->getWidth() - radius)
    {
        center.x = pitch->getWidth() - radius;
        velocity.x *= VELOCITY_REFLECT_FACTOR;
    }
    if(center.y < radius)
    {
        center.y = radius + CLIPPING_MARGIN;
        velocity.y *= VELOCITY_REFLECT_FACTOR;
    }

    if(center.y > pitch->getHeight() - radius)
    {
        center.y = pitch->getHeight() - radius;
        velocity.y *= VELOCITY_REFLECT_FACTOR;
    }
}

bool Pawn::doesCollideWith(Ball ball)
{
    return distance(center, ball.getCenter()) <= radius + ball.getRadius();
}

bool Pawn::doesCollideWith(Pawn pawn)
{
    return distance(center, pawn.getCenter()) <= radius + pawn.getRadius();
}

float Pawn::getMass()
{
    return mass;
}

GeometricVector Pawn::getVelocity()
{
    return velocity;
}

bool Pawn::outOfBounds()
{
    return (center.x < radius) 
            || (center.y < radius)
            || (center.x > pitch->getWidth()-radius)
            || (center.y > pitch->getHeight()-radius);
}

void Pawn::updateAfterCollision()
{
    if(hadCollision)
    {
        velocity = newVelocity;
        hadCollision = false;
    }
}

void Pawn::reflectX(bool changed)
{
    if(changed)
    {
        newVelocity.x *= VELOCITY_REFLECT_FACTOR;
    }
    else
    {
        newVelocity.x = velocity.x * VELOCITY_REFLECT_FACTOR;
    }
    
}

void Pawn::reflectY(bool changed)
{
    if(changed)
    {
        newVelocity.y *= VELOCITY_REFLECT_FACTOR;
    }
    else
    {
        newVelocity.y = velocity.y * VELOCITY_REFLECT_FACTOR;
    }
    
}

void Pawn::draw(RGB color)
{
    processCollisionWithWall();
    gameWindow->fill_circle(center, radius, color);
    gameWindow->update_screen();
}