#include "UserNotJoined.hpp"

const char* UserNotJoinedError::what() const throw()
{
    return USER_NOT_JOINED_ERROR;
}