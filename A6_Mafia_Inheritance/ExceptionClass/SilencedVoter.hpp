#ifndef _SILENCED_VOTER_HPP_
#define _SILENCED_VOTER_HPP_

#include <exception>

const char SILENCED_VOTER_ERROR[] = "Voter is silenced\n";

class SilencedVoterError : public std::exception
{
public:
    const char* what() const throw();
};


#endif