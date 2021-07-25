#ifndef _DELETE_SONG_FR_PLAYLIST_COMMAND_HPP_
#define _DELETE_SONG_FR_PLAYLIST_COMMAND_HPP_ 1

#include "DeleteRequest.hpp"

class DeleteSongFrPlaylistCommand : public DeleteRequest
{
public:
    DeleteSongFrPlaylistCommand(const InputLine& input);
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