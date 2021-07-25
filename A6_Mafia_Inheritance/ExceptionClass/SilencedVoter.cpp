#include "SilencedVoter.hpp"

const char* SilencedVoterError::what() const throw()
{
    return SILENCED_VOTER_ERROR;
}