#include "DeadVotee.hpp"

const char* DeadVoteeError::what() const throw()
{
    return DEAD_VOTEE_ERROR;
}