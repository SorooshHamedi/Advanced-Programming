#include "Ball.hpp"

Ball::Ball(Point _center, int _radius, Pitch* _pitch, int _mass, Window* _window) : center(_center.x, _center.y), velocity(0,0), newVelocity(0,0)
{
    radius = _radius;
    pitch = _pitch; 
    mass = _mass;
    hadCollision = false;
    gameWindow = _window;
}

Ball::Ball() : center(PITCH_CENTER.x, PITCH_CENTER.y), velocity(0,0), newVelocity(0,0)
{
    radius = BALL_RADIUS;
    hadCollision = false;
    gameWindow = nullptr;
}

void Ball::setWindow(Window* _window)
{
    gameWindow = _window;
}

Point Ball::getCenter()
{
    return center;
}

void Ball::setCenter(Point _center)
{
    center = _center;
}

int Ball::getRadius()
{
    return radius;
}

float Ball::getMass()
{
    return mass;
}
void Ball::advanceTime()
{
    center.x += velocity.x * TIME_PASSED_PER_FRAME;
    center.y += velocity.y * TIME_PASSED_PER_FRAME;
    updateVelocity();
}

void Ball::rewindTime(Time time)
{
    center.x -= velocity.x * time;
    center.y -= velocity.y * time;
}

bool Ball::isMoving()
{
    return (velocity.x != 0) || (velocity.y != 0);
}

GeometricVector Ball::getVelocity()
{
    return velocity;
}

void Ball::processCollisionWith(Point pawnCenter, GeometricVector pawnVelocity, float pawnMass, Time time)
{
    hadCollision = true;
    Point difference = center - pawnCenter;
    float diffSize = size(difference);
    GeometricVector velocityDifference = subtract(velocity, pawnVelocity);
    float constFactor = (1.00/pow(diffSize,2)) * ((2*pawnMass)/(pawnMass+mass));
    GeometricVector tempVelocity = multiply(difference, dotProduct(velocityDifference, difference));
    tempVelocity = multiply(tempVelocity, constFactor);
    newVelocity = subtract(velocity, tempVelocity);
}

void Ball::processCollisionWithWall()
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
    /*bool changedX = false;
    bool changedY = false;
    while(outOfBounds())
    {
        if(center.x < radius)
        {
            center.x = radius + CLIPPING_MARGIN;
            changedX = true;
            reflectX(changedX);
        }
        if(center.y < radius)
        {
            center.y = radius + CLIPPING_MARGIN;
            changedY = true;
            reflectY(changedY);
        }

        if(center.x > pitch->getWidth() - radius)
        {
            center.x = pitch->getWidth() - radius - CLIPPING_MARGIN;
            changedX = true;
            reflectX(changedX);
        }

        if(center.y > pitch->getHeight() - radius)
        {
            center.y = pitch->getHeight() - radius - CLIPPING_MARGIN;
            changedY = true;
            reflectY(changedY);
        }   
    }*/
}

void Ball::updateVelocity()
{
    float decreasedVelocity = FRICTION_ACCERALATION * TIME_PASSED_PER_FRAME;
 
    if(velocity.x > 0)
    {
        velocity.x = std::max((float)0,velocity.x-decreasedVelocity);
    }
    else if(velocity.x < 0)
    {
        velocity.x = std::min((float)0, velocity.x+decreasedVelocity);
    }

    if(velocity.y > 0)
    {
        velocity.y = std::max((float)0,velocity.y-decreasedVelocity);
    }
    else if(velocity.y < 0)
    {
        velocity.y = std::min((float)0, velocity.y+decreasedVelocity);
    }
}

bool Ball::outOfBounds()
{
    return (center.x < radius) 
            || (center.y < radius)
            || (center.x > pitch->getWidth()-radius)
            || (center.y > pitch->getHeight()-radius);
}

int Ball::checkForGoal()
{
    int ans = NO_GOAL;
    if(center.x < radius)
    {
        ans = FIRST_PLAYER;
    }
    else if((center.x > pitch->getWidth())  || (abs(pitch->getWidth()-center.x) < radius))
    {
        ans = SECOND_PLAYER;
    }
    if(center.y > GOAL_FIRST_POST && center.y < GOAL_SECOND_POST)
    {
        return ans;
    }
    else
        return NO_GOAL;
}

void Ball::updateAfterCollision()
{
    if(hadCollision)
    {
        velocity = newVelocity;
        hadCollision = false;
    }
}

void Ball::reflectX(bool changed)
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

void Ball::reflectY(bool changed)
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

void Ball::draw(RGB color)
{
    processCollisionWithWall();
    gameWindow->fill_circle(center, radius, color);
    gameWindow->update_screen();
}


