#ifndef _GET_COMMENTS_COMMAND_HPP_
#define _GET_COMMENTS_COMMAND_HPP_ 1

#include "ReadRequest.hpp"


class GetCommentsCommand : public ReadRequest
{
public:
    GetCommentsCommand(const InputLine& input);
    int getID();
    CommandType getType();
private:
    int id;

    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
    bool isAnInfoIndex(int i);
};





#endif