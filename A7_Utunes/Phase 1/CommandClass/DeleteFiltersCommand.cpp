#include "DeleteFiltersCommand.hpp"
const std::string FILTERS = "filters";
const int SIZE = 2;
DeleteFiltersCommand::DeleteFiltersCommand(const InputLine& input)
{
    verify(input); 
}


CommandType DeleteFiltersCommand::getType()
{
    return DELETE_FILTERS;
}

void DeleteFiltersCommand::verify(const InputLine& input)
{
    InputLine correctSyntax = getCorrectSyntax();
    if(input.size() < SIZE)
    {
        invalidCommand();
    }
    for(int i=0; i<correctSyntax.size(); i++)
    {
        if(input[i] != correctSyntax[i])
        {
            invalidCommand();
        }
    }
}

InputLine DeleteFiltersCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(DELETE_REQUEST);
    syntax.push_back(FILTERS);
    return syntax;
}

void DeleteFiltersCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}


