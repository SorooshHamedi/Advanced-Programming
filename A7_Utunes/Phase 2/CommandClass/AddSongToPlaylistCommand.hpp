#ifndef _ADD_SONG_TO_PLAYLIST_COMMAND_HPP_
#define _ADD_SONG_TO_PLAYLIST_COMMAND_HPP_ 1

#include "WriteRequest.hpp"


class AddSongToPlaylistCommand : public WriteRequest
{
public:
    AddSongToPlaylistCommand(const InputLine& input);
    int getPlaylistID();
    int getSongID();
    CommandType getType();
private:
    int playlistID;
    int songID;

    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
    bool isAnInfoIndex(int i);
};


#endif