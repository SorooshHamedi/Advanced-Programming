#include "DeadSuspect.hpp"

const char* DeadSuspectError::what() const throw()
{
    return DEAD_SUSPECT_ERROR;
}