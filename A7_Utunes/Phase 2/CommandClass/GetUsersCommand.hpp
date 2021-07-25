#ifndef _GET_USERS_COMMAND_HPP_
#define _GET_USERS_COMMAND_HPP_

#include "ReadRequest.hpp"

class GetUsersCommand : public ReadRequest
{
public:
    GetUsersCommand(const InputLine& input);
    CommandType getType();
private:
    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
};

#endif