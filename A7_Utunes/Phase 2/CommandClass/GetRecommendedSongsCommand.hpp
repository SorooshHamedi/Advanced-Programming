#ifndef _GET_RECOMMENDED_SONGS_COMMAND_HPP_
#define _GET_RECOMMENDED_SONGS_COMMAND_HPP_ 1

#include "ReadRequest.hpp"

const std::string RECOMMENDED_SONGS_COMMAND = "recommended";

class GetRecommendedSongsCommand : public ReadRequest
{
public:
    GetRecommendedSongsCommand(const InputLine& input);
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