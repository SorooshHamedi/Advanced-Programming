#ifndef _GET_SONG_COMMAND_HPP_
#define _GET_SONG_COMMAND_HPP_ 1

#include "ReadRequest.hpp"


const int SONG_COMMAND_SIZE = 5;
class GetSongCommand : public ReadRequest
{
public:
    GetSongCommand(const InputLine& input);
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