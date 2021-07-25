#ifndef _DETECTIVE_ALREADY_ASKED_HPP_
#define _DETECTIVE_ALREADY_ASKED_HPP_

#include <exception>
const char DETECTIVE_ALREADY_ASKED_ERROR[] = "Detective has already asked\n";

class DetectiveAlreadyAskedError : public std::exception
{
public:
    const char* what() const throw();
};

#endif