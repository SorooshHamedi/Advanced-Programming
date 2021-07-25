#ifndef _DEAD_USER_HPP_
#define _DEAD_USER_HPP_

#include <exception>
const char DEAD_USER_ERROR[] = "User is dead\n";

class DeadUserError : public std::exception
{
public:
    const char* what() const throw();
};

#endif