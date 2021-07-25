#ifndef _EMPTY_ERROR_HPP_
#define _EMPTY_ERROR_HPP_ 1

#include <exception>
class EmptyError : public std::exception
{
public:
    EmptyError();
    const char* what() const throw();
};

#endif