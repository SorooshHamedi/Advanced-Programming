#include "GetAllSongsCommand.hpp"

GetAllSongsCommand::GetAllSongsCommand(const InputLine& input)
{
    verify(input);
}
 
CommandType GetAllSongsCommand::getType()
{
    return GET_SONGS;
}

void GetAllSongsCommand::verify(const InputLine& input)
{
    InputLine correctSyntax = getCorrectSyntax();
    if(input.size() != correctSyntax.size())
    {
        invalidCommand();
    }
}

InputLine GetAllSongsCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(READ_REQUEST);
    syntax.push_back(SONGS_COMMAND);
    return syntax;
}

void GetAllSongsCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}