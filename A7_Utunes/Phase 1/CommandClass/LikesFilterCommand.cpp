#include "LikesFilterCommand.hpp"

const int MIN_INDEX = 4;
const int MAX_INDEX = 6;
const std::string MIN = "min_like";
const std::string MAX = "max_like";
const std::string FILTERS = "filters";
const std::string EMPTY_STRING = "";

LikesFilterCommand::LikesFilterCommand(const InputLine& input)
{
    verify(input);
    min = stoi(input[MIN_INDEX]);
    max = stoi(input[MAX_INDEX]);
    if(min > max || min < 0 || max < 0)
    {
        badRequest();
    }
}

int LikesFilterCommand::getMin()
{
    return min;
}

int LikesFilterCommand::getMax()
{
    return max;
}

FilterType LikesFilterCommand::getFilterType()
{
    return LIKES;
}

void LikesFilterCommand::verify(const InputLine& input)
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

InputLine LikesFilterCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(WRITE_REQUEST);
    syntax.push_back(FILTERS);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(MIN);
    syntax.push_back(EMPTY_STRING);
    syntax.push_back(MAX);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void LikesFilterCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

bool LikesFilterCommand::isAnInfoIndex(int i)
{
    return i == MIN_INDEX || i == MAX_INDEX;
}

void LikesFilterCommand::badRequest()
{
    std::exception* ex = new BadRequestError();
    throw ex;
}