#include "PlayerWithoutRole.hpp"

const char* PlayerWithoutRoleError::what() const throw()
{
    return PLAYER_WITHOUT_ROLE_ERROR;
}