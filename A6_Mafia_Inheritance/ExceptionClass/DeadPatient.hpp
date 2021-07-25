#ifndef _DEAD_PATIENT_HPP_
#define _DEAD_PATIENT_HPP_

#include <exception>
const char DEAD_PATIENT_ERROR[] = "Patient is dead\n";

class DeadPatientError : public std::exception
{
public:
    const char* what() const throw();
};

#endif