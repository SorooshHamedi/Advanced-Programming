#ifndef _GET_ALL_PLAYLISTS_COMMAND_HPP_
#define _GET_ALL_PLAYLISTS_COMMAND_HPP_ 1

#include "ReadRequest.hpp"


class GetAllPlaylistsCommand : public ReadRequest
{
public:
    GetAllPlaylistsCommand(const InputLine& input);
    CommandType getType();
    std::string getUsername();
private:
    std::string username;

    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
    bool isAnInfoIndex(int i);
};




#endif