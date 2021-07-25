#include "GetSimilarUsersCommand.hpp"
using namespace std;
const int COUNT_INDEX = 4;
const string COUNT = "count";
const string EMPTY_STRING = "";

GetSimilarUsersCommand::GetSimilarUsersCommand(const InputLine& line)
{
    verify(line);
    count = stoi(line[COUNT_INDEX]);
}

CommandType GetSimilarUsersCommand::getType()
{
    return GET_SIMILAR_USERS;
}

void GetSimilarUsersCommand::verify(const InputLine& input)
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

InputLine GetSimilarUsersCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(READ_REQUEST);
    syntax.push_back(SIMILAR_USERS_COMMAND);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(COUNT);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void GetSimilarUsersCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

bool GetSimilarUsersCommand::isAnInfoIndex(int i)
{
    return i == COUNT_INDEX;
}

int GetSimilarUsersCommand::getCount()
{
    return count;
}
