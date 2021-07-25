#include "VotingInProgress.hpp"

const char* VotingInProgressError::what() const throw()
{
    return VOTING_IN_PROGRESS_ERROR;
}