#include "LogoutCommand.hpp"
 
LogoutCommand::LogoutCommand(const InputLine& input)
{
    verify(input);
}


CommandType LogoutCommand::getType()
{
    return LOGOUT;
}

void LogoutCommand::verify(const InputLine& input)
{
    InputLine correctSyntax = getCorrectSyntax();
    if(input.size() != correctSyntax.size())
    {
        invalidCommand();
    }
}

InputLine LogoutCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(WRITE_REQUEST);
    syntax.push_back(LOGOUT_COMMAND);
    return syntax;
}

void LogoutCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}