#include "BadRequestError.hpp"

const char BAD_REQUEST_ERROR[] = "Bad Request\n";

BadRequestError::BadRequestError(){}

const char*  BadRequestError::what() const throw()
{
    return BAD_REQUEST_ERROR;
}