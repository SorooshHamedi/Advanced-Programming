#ifndef _DELETE_FILTERS_COMMAND_HPP_
#define _DELETE_FILTERS_COMMAND_HPP_ 1

#include "DeleteRequest.hpp"


class DeleteFiltersCommand : public DeleteRequest
{
public:
    DeleteFiltersCommand(const InputLine& input);
    CommandType getType();
private:
    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
};

#endif