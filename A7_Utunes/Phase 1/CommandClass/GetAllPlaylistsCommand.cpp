#include "GetAllPlaylistsCommand.hpp"

const int USERNAME_INDEX = 4;
const std::string USERNAME = "username";
const std::string EMPTY_STRING = "";
const std::string PLAYLISTS_COMMAND = "playlists";

GetAllPlaylistsCommand::GetAllPlaylistsCommand(const InputLine& input)
{
    verify(input);
    username = input[USERNAME_INDEX];
}

CommandType GetAllPlaylistsCommand::getType()
{
    return GET_PLAYLISTS;
}

std::string GetAllPlaylistsCommand::getUsername()
{
    return username;
}

void GetAllPlaylistsCommand::verify(const InputLine& input)
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

InputLine GetAllPlaylistsCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(READ_REQUEST);
    syntax.push_back(PLAYLISTS_COMMAND);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(USERNAME);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void GetAllPlaylistsCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

bool GetAllPlaylistsCommand::isAnInfoIndex(int i)
{
    return i == USERNAME_INDEX;
}