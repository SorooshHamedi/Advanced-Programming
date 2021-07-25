#include "DetectiveAlreadyAsked.hpp"

const char* DetectiveAlreadyAskedError::what() const throw()
{
    return DETECTIVE_ALREADY_ASKED_ERROR;
}