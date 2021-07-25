#ifndef _ADD_COMMENT_COMMAND_HPP_
#define _ADD_COMMENT_COMMAND_HPP_ 1

#include "WriteRequest.hpp"


class AddCommentCommand : public WriteRequest
{
public:
    AddCommentCommand(const InputLine& input);
    int getTime();
    int getSongID();
    std::string getComment();
    CommandType getType();
private:
    int time;
    std::string comment;
    int songID;

    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
    bool isAnInfoIndex(int i);
};



#endif