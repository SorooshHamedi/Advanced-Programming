#ifndef _GET_LIKES_COMMAND_HPP_
#define _GET_LIKES_COMMAND_HPP_ 1

#include "ReadRequest.hpp"


class GetLikesCommand : public ReadRequest
{
public:
    GetLikesCommand(const InputLine& input);
    CommandType getType();
private:
    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();  
};




#endif