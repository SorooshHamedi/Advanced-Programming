#ifndef _DEAD_PERSON_HPP_
#define _DEAD_PERSON_HPP_

#include <exception>
const char DEAD_PERSON_ERROR[] = "Person is dead\n";

class DeadPersonError : public std::exception
{
public:
    const char* what() const throw();
};

#endif