#include "DeadPatient.hpp"

const char* DeadPatientError::what() const throw()
{
    return DEAD_PATIENT_ERROR;
}
