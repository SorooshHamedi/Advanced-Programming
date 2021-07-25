#include "SignupCommand.hpp"
using namespace std;

const int EMAIL_INDEX = 4;
const int USERNAME_INDEX = 6;
const int PASSWORD_INDEX = 8;
const string EMAIL = "email";
const string PASSWORD = "password";
const string USERNAME = "username";
const string EMPTY_STRING = "";

SignupCommand::SignupCommand(const InputLine& input)
{
    verify(input);
    password = input[PASSWORD_INDEX];
    email = input[EMAIL_INDEX];
    username = input[USERNAME_INDEX];
}

CommandType SignupCommand::getType()
{
    return SIGNUP;
}

std::string SignupCommand::getUserName()
{
    return username;
}

std::string SignupCommand::getEmail()
{
    return email;
}

std::string SignupCommand::getPassword()
{
    return password;
}

void SignupCommand::verify(const InputLine& input)
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

InputLine SignupCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(WRITE_REQUEST);
    syntax.push_back(SIGNUP_COMMAND);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(EMAIL);
    syntax.push_back(EMPTY_STRING);
    syntax.push_back(USERNAME);
    syntax.push_back(EMPTY_STRING);
    syntax.push_back(PASSWORD);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void SignupCommand::invalidCommand()
{
    exception* ex = new NotFoundError();
    throw ex;
}

bool SignupCommand::isAnInfoIndex(int i)
{
    return i == EMAIL_INDEX || i == PASSWORD_INDEX || i == USERNAME_INDEX;
}