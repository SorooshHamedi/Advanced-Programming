#ifndef _LIKES_FILTER_COMMAND_HPP_
#define _LIKES_FILTER_COMMAND_HPP_

#include "NewFilterCommand.hpp"
#include "../ExceptionClass/BadRequestError.hpp"
const std::string LIKES_FILTER_IDENTIFIER = "min_like";


class LikesFilterCommand : public NewFilterCommand
{
public:
    LikesFilterCommand(const InputLine& input);
    int getMin();
    int getMax();
    FilterType getFilterType();
private:
    int min;
    int max;

    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
    bool isAnInfoIndex(int i);
    void badRequest();
};

#endif