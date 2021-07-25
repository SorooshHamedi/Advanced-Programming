#include "DoctorAlreadyHealed.hpp"

const char* DoctorAlreadyHealedError::what() const throw()
{
    return DOCTOR_ALREADY_HEALED_ERROR;
}