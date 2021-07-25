#include "AddLikeCommand.hpp"
#include <string>
using namespace std;
const int ID_INDEX = 4;
const string LIKES_COMMAND = "likes";
const string EMPTY_STRING = "";
const string ID = "id";


AddLikeCommand::AddLikeCommand(const InputLine& input)
{
    verify(input);
    id = stoi(input[ID_INDEX]);
}

int AddLikeCommand::getID()
{
    return id;
}

CommandType AddLikeCommand::getType()
{
    return ADD_LIKE;
}

void AddLikeCommand::verify(const InputLine& input)
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

InputLine AddLikeCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(WRITE_REQUEST);
    syntax.push_back(LIKES_COMMAND);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(ID);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void AddLikeCommand::invalidCommand()
{
    exception* ex = new NotFoundError();
    throw ex;
}

bool AddLikeCommand::isAnInfoIndex(int i)
{
    return i == ID_INDEX;
}