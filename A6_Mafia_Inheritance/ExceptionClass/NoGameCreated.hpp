#ifndef _NO_GAME_CREATED_HPP_
#define _NO_GAME_CREATED_HPP_

#include <exception>
#include <string>

const char NO_GAME_CREATED_ERROR[] = "No game created\n";

class NoGameCreatedError : public std::exception
{
public:
    const char* what() const throw();
};



#endif