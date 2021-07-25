#include "ReleaseYearFilterCommand.hpp"

const int MIN_INDEX = 4;
const int MAX_INDEX = 6;
const std::string MIN = "min_year";
const std::string MAX = "max_year";
const std::string FILTERS = "filters";
const std::string EMPTY_STRING = "";

ReleaseYearFilterCommand::ReleaseYearFilterCommand(const InputLine& input)
{
    verify(input);
    min = stoi(input[MIN_INDEX]);
    max = stoi(input[MAX_INDEX]);
    if(min > max)
    {
        badRequest();
    }
}

int ReleaseYearFilterCommand::getMin()
{
    return min;
}

int ReleaseYearFilterCommand::getMax()
{
    return max;
}

FilterType ReleaseYearFilterCommand::getFilterType()
{
    return RELEASE_YEAR;
}

void ReleaseYearFilterCommand::verify(const InputLine& input)
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

InputLine ReleaseYearFilterCommand::getCorrectSyntax()
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

void ReleaseYearFilterCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

bool ReleaseYearFilterCommand::isAnInfoIndex(int i)
{
    return i == MIN_INDEX || i == MAX_INDEX;
}

void ReleaseYearFilterCommand::badRequest()
{
    std::exception* ex = new BadRequestError();
    throw ex;
}