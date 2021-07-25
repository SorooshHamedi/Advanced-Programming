#ifndef _GET_SIMILAR_USERS_COMMAND_HPP_
#define _GET_SIMILAR_USERS_COMMAND_HPP_ 1

#include "ReadRequest.hpp"

const std::string SIMILAR_USERS_COMMAND = "similar_users";

class GetSimilarUsersCommand : public ReadRequest
{
public:
    GetSimilarUsersCommand(const InputLine& input);
    CommandType getType();
    int getCount();
private:
    int count;

    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
    bool isAnInfoIndex(int i);
};


#endif