#ifndef _RELEASE_YEAR_FILTER_COMMAND_HPP_
#define _RELEASE_YEAR_FILTER_COMMAND_HPP_ 1

#include "NewFilterCommand.hpp"
#include "../ExceptionClass/BadRequestError.hpp"

const std::string RELEASE_YEAR_FILTER_IDENTIFIER = "min_year";

class ReleaseYearFilterCommand : public NewFilterCommand
{
public:
    ReleaseYearFilterCommand(const InputLine& input);
    FilterType getFilterType();
    int getMin();
    int getMax();
private:
    int min;
    int max;

    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
    void badRequest();
    bool isAnInfoIndex(int i);
};

#endif