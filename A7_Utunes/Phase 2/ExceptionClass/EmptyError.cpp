#include "EmptyError.hpp"

const char EMPTY_ERROR[] = "Empty\n";

EmptyError::EmptyError(){}

const char* EmptyError::what() const throw()
{
    return EMPTY_ERROR;
}