#ifndef _USER_NOT_JOINED_HPP_
#define _USER_NOT_JOINED_HPP_

#include <exception>
#include <string>

const char USER_NOT_JOINED_ERROR[] = "User not joined\n";

class UserNotJoinedError : public std::exception
{
public:
    const char* what() const throw();
};


#endif