#ifndef _DOCTOR_ALREADY_HEALED_HPP_
#define _DOCTOR_ALREADY_HEALED_HPP_

#include <exception>
const char DOCTOR_ALREADY_HEALED_ERROR[] = "Doctor has already healed\n";

class DoctorAlreadyHealedError : public std::exception
{
public:
    const char* what() const throw();
};

#endif