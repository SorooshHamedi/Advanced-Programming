#ifndef _PERMISSION_DENIED_ERROR_HPP_
#define _PERMISSION_DENIED_ERROR_HPP_ 1

#include <exception>
#include <string>

class PermissionDeniedError : public std::exception
{
public:
    PermissionDeniedError();
    const char* what() const throw();
private:
};

#endif