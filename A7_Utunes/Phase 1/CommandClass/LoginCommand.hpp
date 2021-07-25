#ifndef _LOGIN_COMMAND_HPP_
#define _LOGIN_COMMAND_HPP_ 1

#include "WriteRequest.hpp"

#include <string>

const std::string LOGIN_COMMAND = "login";

class LoginCommand : public WriteRequest
{
public:
    LoginCommand(const InputLine& input);
    CommandType getType();
    std::string getEmail();
    std::string getPassword();
private:
    std::string email;
    std::string password;

    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
    bool isAnInfoIndex(int i);
};

#endif
