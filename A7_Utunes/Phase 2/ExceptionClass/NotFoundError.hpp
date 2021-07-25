#ifndef _NOT_FOUND_ERROR_HPP_
#define _NOT_FOUND_ERROR_HPP_ 1

#include <exception>
#include <string>

class NotFoundError : public std::exception
{
public:
    NotFoundError();
    const char* what() const throw();
private:
};








#endif