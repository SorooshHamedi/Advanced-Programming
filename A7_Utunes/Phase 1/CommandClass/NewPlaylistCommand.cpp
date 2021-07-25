#include "NewPlaylistCommand.hpp"

const int NAME_INDEX = 4;
const int PRIVACY_INDEX = 6;
const std::string PRIVATE = "private";
const std::string PUBLIC = "public";
const std::string PRIVACY = "privacy";
const std::string NAME = "name";
const std::string PLAYLISTS_COMMAND = "playlists";
const std::string EMPTY_STRING = "";

NewPlaylistCommand::NewPlaylistCommand(const InputLine& input)
{
    verify(input);
    name = input[NAME_INDEX];
    isPrivateFlag = (input[PRIVACY_INDEX] == PRIVATE) ? true : false; 
}

CommandType NewPlaylistCommand::getType()
{
    return NEW_PLAYLIST;
}

std::string NewPlaylistCommand::getName()
{
    return name;
}

bool NewPlaylistCommand::isPrivate()
{
    return isPrivateFlag;
}

void NewPlaylistCommand::verify(const InputLine& input)
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
    if(input[PRIVACY_INDEX] != PRIVATE && input[PRIVACY_INDEX] != PUBLIC)
        invalidCommand();
}

InputLine NewPlaylistCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(WRITE_REQUEST);
    syntax.push_back(PLAYLISTS_COMMAND);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(NAME);
    syntax.push_back(EMPTY_STRING);
    syntax.push_back(PRIVACY);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void NewPlaylistCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

bool NewPlaylistCommand::isAnInfoIndex(int i)
{
    return i == NAME_INDEX || i == PRIVACY_INDEX;
}