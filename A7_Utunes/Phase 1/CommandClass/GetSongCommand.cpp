#include "GetSongCommand.hpp"
const int ID_INDEX = 4;
using namespace std;

const string ID = "id";
const string SONGS_COMMAND = "songs";
const string EMPTY_STRING = "";

GetSongCommand::GetSongCommand(const InputLine& input)
{
    verify(input);
    id = stoi(input[ID_INDEX]);
}

CommandType GetSongCommand::getType()
{
    return GET_SONG;
}

int GetSongCommand::getID()
{
    return id;
}

void GetSongCommand::verify(const InputLine& input)
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

InputLine GetSongCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(READ_REQUEST);
    syntax.push_back(SONGS_COMMAND);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(ID);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void GetSongCommand::invalidCommand()
{
    exception* ex = new NotFoundError();
    throw ex;
}

bool GetSongCommand::isAnInfoIndex(int i)
{
    return i == ID_INDEX;
}
