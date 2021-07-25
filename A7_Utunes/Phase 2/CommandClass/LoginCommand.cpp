#include "LoginCommand.hpp"
using namespace std;

const int EMAIL_INDEX = 4;
const int PASSWORD_INDEX = 6;
const string EMAIL = "email";
const string PASSWORD = "password";
const string EMPTY_STRING = "";

LoginCommand::LoginCommand(const InputLine& input)
{
    verify(input);
    password = input[PASSWORD_INDEX];
    email = input[EMAIL_INDEX];
}

CommandType LoginCommand::getType()
{
    return LOGIN;
}


std::string LoginCommand::getEmail()
{
    return email;
}

std::string LoginCommand::getPassword()
{
    return password;
}

void LoginCommand::verify(const InputLine& input)
{
    InputLine correctSyntax = getCorrectSyntax();
    if(input.size() != correctSyntax.size())
    {
        invalidCommand();
    }
    for(int i=0; i<correctSyntax.size(); i++)
    {
        if(!isAnInfoIndex(i) && (input[i] != correctSyntax[i]))
        {
            invalidCommand();
        }
    }
}

InputLine LoginCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(WRITE_REQUEST);
    syntax.push_back(LOGIN_COMMAND);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(EMAIL);
    syntax.push_back(EMPTY_STRING);
    syntax.push_back(PASSWORD);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void LoginCommand::invalidCommand()
{
    exception* ex = new NotFoundError();
    throw ex;
}

bool LoginCommand::isAnInfoIndex(int i)
{
    return i == EMAIL_INDEX || i == PASSWORD_INDEX;
}