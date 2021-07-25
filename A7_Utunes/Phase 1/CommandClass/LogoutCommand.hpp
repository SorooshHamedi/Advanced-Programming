#ifndef _LOGOUT_COMMAND_HPP_
#define _LOGOUT_COMMAND_HPP_ 1

#include "WriteRequest.hpp"

const std::string LOGOUT_COMMAND = "logout";

class LogoutCommand : public WriteRequest
{
public:
    LogoutCommand(const InputLine& input);
    CommandType getType();
private:
    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
};



#endif
