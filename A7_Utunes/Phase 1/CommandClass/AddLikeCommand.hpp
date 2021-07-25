#ifndef _ADD_LIKE_COMMENT_HPP_
#define _ADD_LIKE_COMMENT_HPP_ 1

#include "WriteRequest.hpp"

class AddLikeCommand : public WriteRequest
{
public:
    AddLikeCommand(const InputLine& inputLine);
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