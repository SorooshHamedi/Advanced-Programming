#ifndef _DELETE_LIKE_COMMAND_HPP_
#define _DELETE_LIKE_COMMAND_HPP_ 1

#include "DeleteRequest.hpp"


class DeleteLikeCommand : public DeleteRequest
{
public:
    DeleteLikeCommand(const InputLine& input);
    CommandType getType();
    int getID();
private:
    int id;

    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
    bool isAnInfoIndex(int i);
};


#endif