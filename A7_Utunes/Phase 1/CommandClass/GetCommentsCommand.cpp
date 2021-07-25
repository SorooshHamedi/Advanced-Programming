#include "GetCommentsCommand.hpp"

const int ID_INDEX = 4;
const std::string SONG_ID = "song_id";
const std::string EMPTY_STRING = "";
const std::string COMMENTS_COMMAND = "comments";

GetCommentsCommand::GetCommentsCommand(const InputLine& input)
{
    verify(input);
    id = stoi(input[ID_INDEX]);
}

int GetCommentsCommand::getID()
{
    return id;
}

CommandType GetCommentsCommand::getType()
{
    return GET_COMMENTS;
}

void GetCommentsCommand::verify(const InputLine& input)
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

InputLine GetCommentsCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(READ_REQUEST);
    syntax.push_back(COMMENTS_COMMAND);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(SONG_ID);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void GetCommentsCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

bool GetCommentsCommand::isAnInfoIndex(int i)
{
    return i == ID_INDEX;
}