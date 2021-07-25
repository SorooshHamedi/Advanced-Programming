#include "NotFoundError.hpp"

const char NOT_FOUND_ERROR[] = "Not Found\n";

NotFoundError::NotFoundError(){}


const char* NotFoundError::what() const throw()
{
    return NOT_FOUND_ERROR;
}