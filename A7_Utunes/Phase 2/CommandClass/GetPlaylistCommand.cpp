#include "GetPlaylistCommand.hpp"
const int ID_INDEX = 4;
const std::string ID = "id";
const std::string EMPTY_STRING = "";
const std::string PLAYLISTS_SONGS = "playlists_songs";

GetPlaylistCommand::GetPlaylistCommand(const InputLine& input)
{
    id = stoi(input[ID_INDEX]);
}

CommandType GetPlaylistCommand::getType()
{
    return GET_PLAYLIST;
}

int GetPlaylistCommand::getID()
{
    return id;
}

void GetPlaylistCommand::verify(const InputLine& input)
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

InputLine GetPlaylistCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(READ_REQUEST);
    syntax.push_back(PLAYLISTS_SONGS);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(ID);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void GetPlaylistCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

bool GetPlaylistCommand::isAnInfoIndex(int i)
{
    return i == ID_INDEX;
}