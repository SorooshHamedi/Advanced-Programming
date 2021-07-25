#include "AddCommentCommand.hpp"

const int ID_INDEX = 4;
const int TIME_INDEX = 6;
const int COMMENT_INDEX = 8;
const std::string SONG_ID = "song_id";
const std::string TIME = "time";
const std::string COMMENT = "comment";
const std::string EMPTY_STRING = "";
const std::string COMMENTS_COMMAND = "comments";

AddCommentCommand::AddCommentCommand(const InputLine& input)
{
    verify(input);
    time = stoi(input[TIME_INDEX]);
    songID = stoi(input[ID_INDEX]);
    comment = input[COMMENT_INDEX];
}

int AddCommentCommand::getTime()
{
    return time;
}

int AddCommentCommand::getSongID()
{
    return songID;
}

std::string AddCommentCommand::getComment()
{
    return comment;
}

CommandType AddCommentCommand::getType()
{
    return ADD_COMMENT;
}

void AddCommentCommand::verify(const InputLine& input)
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

InputLine AddCommentCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(WRITE_REQUEST);
    syntax.push_back(COMMENTS_COMMAND);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(SONG_ID);
    syntax.push_back(EMPTY_STRING);
    syntax.push_back(TIME);
    syntax.push_back(EMPTY_STRING);
    syntax.push_back(COMMENT);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void AddCommentCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

bool AddCommentCommand::isAnInfoIndex(int i)
{
    return i == ID_INDEX || i == TIME_INDEX || i == COMMENT_INDEX;
}