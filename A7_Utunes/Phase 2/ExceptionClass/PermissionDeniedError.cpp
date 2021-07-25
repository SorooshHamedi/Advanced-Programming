#include "PermissionDeniedError.hpp"

const char PERMISSION_DENIED_ERROR[] = "Permission Denied\n";

PermissionDeniedError::PermissionDeniedError(){}

const char* PermissionDeniedError::what() const throw()
{
    return PERMISSION_DENIED_ERROR;
}