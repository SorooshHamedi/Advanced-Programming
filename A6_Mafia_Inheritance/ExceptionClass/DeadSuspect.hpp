#ifndef _DEAD_SUSPECT_HPP_
#define _DEAD_SUSPECT_HPP_

#include <exception>
const char DEAD_SUSPECT_ERROR[] = "Suspect is dead\n";

class DeadSuspectError : public std::exception
{
public:
    const char* what() const throw();
};

#endif