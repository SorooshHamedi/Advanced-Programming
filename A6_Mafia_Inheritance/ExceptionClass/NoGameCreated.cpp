#include "NoGameCreated.hpp"

const char* NoGameCreatedError::what() const throw()
{
    return NO_GAME_CREATED_ERROR;
}