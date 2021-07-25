#include "GetRecommendedSongsCommand.hpp"
using namespace std;
const int COUNT_INDEX = 4;
const string COUNT = "count";
const string EMPTY_STRING = "";

GetRecommendedSongsCommand::GetRecommendedSongsCommand(const InputLine& line)
{
    verify(line);
    count = stoi(line[COUNT_INDEX]);
}

CommandType GetRecommendedSongsCommand::getType()
{
    return GET_RECOMMENDED_SONGS;
}

int GetRecommendedSongsCommand::getCount()
{
    return count;
}

void GetRecommendedSongsCommand::verify(const InputLine& input)
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

InputLine GetRecommendedSongsCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(READ_REQUEST);
    syntax.push_back(RECOMMENDED_SONGS_COMMAND);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(COUNT);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void GetRecommendedSongsCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

bool GetRecommendedSongsCommand::isAnInfoIndex(int i)
{
    return i == COUNT_INDEX;
}
