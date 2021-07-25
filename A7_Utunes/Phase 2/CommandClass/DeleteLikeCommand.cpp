#include "DeleteLikeCommand.hpp"
#include <string>
const int ID_INDEX = 4;
const std::string LIKES_COMMAND = "likes";
const std::string ID = "id";
const std::string EMPTY_STRING = "";

DeleteLikeCommand::DeleteLikeCommand(const InputLine& input)
{
    verify(input);
    id = stoi(input[ID_INDEX]);
}

CommandType DeleteLikeCommand::getType()
{
    return DELETE_LIKE;
}

int DeleteLikeCommand::getID()
{
    return id;
}

void DeleteLikeCommand::verify(const InputLine& input)
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

InputLine DeleteLikeCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(DELETE_REQUEST);
    syntax.push_back(LIKES_COMMAND);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(ID);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void DeleteLikeCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

bool DeleteLikeCommand::isAnInfoIndex(int i)
{
    return i == ID_INDEX;
}
