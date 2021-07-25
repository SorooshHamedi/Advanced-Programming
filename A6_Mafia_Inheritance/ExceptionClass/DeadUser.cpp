#include "DeadUser.hpp"

const char* DeadUserError::what() const throw()
{
    return DEAD_USER_ERROR;
}