#include "GetUsersCommand.hpp"
const std::string USERS_COMMAND = "users";

GetUsersCommand::GetUsersCommand(const InputLine& input)
{
    verify(input);
}

CommandType GetUsersCommand::getType()
{
    return GET_USERS;
}

void GetUsersCommand::verify(const InputLine& input)
{
    InputLine correctSyntax = getCorrectSyntax();
    if(input.size() != correctSyntax.size())
    {
        invalidCommand();
    }
}

InputLine GetUsersCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(READ_REQUEST);
    syntax.push_back(USERS_COMMAND);
    return syntax;
}

void GetUsersCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

