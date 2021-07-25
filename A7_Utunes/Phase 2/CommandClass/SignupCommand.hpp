#ifndef _SIGNUP_COMMAND_HPP_
#define _SIGNUP_COMMAND_HPP_ 1

#include "WriteRequest.hpp"
 
#include <string>

const std::string SIGNUP_COMMAND = "signup";

class SignupCommand : public WriteRequest
{
public:
    SignupCommand(const InputLine& input);
    CommandType getType();
    std::string getUserName();
    std::string getEmail();
    std::string getPassword();
private:
    std::string username;
    std::string email;
    std::string password;

    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
    bool isAnInfoIndex(int i);
};

#endif
