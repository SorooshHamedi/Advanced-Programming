#include "DeadPerson.hpp"

const char* DeadPersonError::what() const throw()
{
    return DEAD_PERSON_ERROR;
}
