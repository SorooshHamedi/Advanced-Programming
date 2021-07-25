#include "GetLikesCommand.hpp"

const std::string LIKES_COMMAND = "likes";

GetLikesCommand::GetLikesCommand(const InputLine& input)
{
    verify(input);
}

CommandType GetLikesCommand::getType()
{
    return GET_LIKES;
}

void GetLikesCommand::verify(const InputLine& input)
{
    InputLine correctSyntax = getCorrectSyntax();
    if(input.size() != correctSyntax.size())
    {
        invalidCommand();
    }
}

InputLine GetLikesCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(READ_REQUEST);
    syntax.push_back(LIKES_COMMAND);
    return syntax;
}

void GetLikesCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}