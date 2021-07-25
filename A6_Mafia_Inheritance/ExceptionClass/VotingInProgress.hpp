#ifndef _VOTING_IN_PROGRESS_HPP_
#define _VOTING_IN_PROGRESS_HPP_

#include <exception>
const char VOTING_IN_PROGRESS_ERROR[] = "Voting in progress\n";

class VotingInProgressError : public std::exception
{
public:
    const char* what() const throw();
};

#endif