#ifndef _GET_PLAYLIST_COMMAND_HPP_
#define _GET_PLAYLIST_COMMAND_HPP_ 1

#include "ReadRequest.hpp"


class GetPlaylistCommand : public ReadRequest
{
public:
    GetPlaylistCommand(const InputLine& input);
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