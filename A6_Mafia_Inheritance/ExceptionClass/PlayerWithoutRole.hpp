#ifndef _PLAYER_WITHOUT_ROLE_HPP_
#define _PLAYER_WITHOUT_ROLE_HPP_

#include <exception>

const char PLAYER_WITHOUT_ROLE_ERROR[] = "One or more players do not have a role\n";

class PlayerWithoutRoleError : public std::exception
{
public:
    const char* what() const throw();
};


#endif