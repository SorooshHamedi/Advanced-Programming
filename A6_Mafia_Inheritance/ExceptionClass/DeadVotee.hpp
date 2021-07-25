#ifndef _DEAD_VOTEE_HPP_
#define _DEAD_VOTEE_HPP_

#include <exception>

const char DEAD_VOTEE_ERROR[] = "Votee already dead\n";

class DeadVoteeError : public std::exception
{
public:
    const char* what() const throw();
};

#endif

