#ifndef _GAME_ALREADY_STARTED_HPP_
#define _GAME_ALREADY_STARTED_HPP_

#include <exception>

const char GAME_ALREADY_STARTED_ERROR[] = "Game has already started\n";

class GameAlreadyStartedError : public std::exception
{
public:
    const char* what() const throw();
};

#endif