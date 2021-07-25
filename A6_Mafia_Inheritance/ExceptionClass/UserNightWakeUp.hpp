#ifndef _USER_NIGHT_WAKE_UP_HPP_
#define _USER_NIGHT_WAKE_UP_HPP_

#include <exception>
const char USER_NIGHT_WAKE_UP_ERROR[] = "User can not wake up during night\n";

class UserNightWakeUpError : public std::exception
{
public:
    const char* what() const throw();
};


#endif