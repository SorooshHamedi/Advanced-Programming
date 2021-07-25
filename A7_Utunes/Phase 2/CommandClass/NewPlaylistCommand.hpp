#ifndef _NEW_PLAYLIST_COMMAND_HPP_
#define _NEW_PLAYLIST_COMMAND_HPP_ 1

#include "WriteRequest.hpp"

class NewPlaylistCommand : public WriteRequest
{
public:
    NewPlaylistCommand(const InputLine& input);
    CommandType getType();
    std::string getName();
    bool isPrivate();
private:
    std::string name;
    bool isPrivateFlag;

    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
    bool isAnInfoIndex(int i);
};





#endif