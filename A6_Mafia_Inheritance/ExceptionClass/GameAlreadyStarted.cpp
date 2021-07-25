#include "GameAlreadyStarted.hpp"

const char* GameAlreadyStartedError::what() const throw()
{
    return GAME_ALREADY_STARTED_ERROR;
}