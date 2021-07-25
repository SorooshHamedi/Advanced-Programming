#include "Pitch.hpp"

Pitch::Pitch()
{
    height = PITCH_HEIGHT;
    width = PITCH_WIDTH;
}

int Pitch::getHeight()
{
    return height;
}

int Pitch::getWidth()
{
    return width;
}
