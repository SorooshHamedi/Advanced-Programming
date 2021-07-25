#ifndef _BAD_REQUEST_ERROR_HPP_
#define _BAD_REQUEST_ERROR_HPP_ 1

#include <exception>
#include <string>

class BadRequestError : public std::exception
{
public:
    BadRequestError();
    const char* what() const throw();
private:
};








#endif