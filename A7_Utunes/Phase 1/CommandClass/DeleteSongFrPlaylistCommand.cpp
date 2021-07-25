#include "DeleteSongFrPlaylistCommand.hpp"
using namespace std;
const int PLAYLIST_ID_INDEX = 4;
const int SONG_ID_INDEX = 6;
const string SONG_PLAYLISTS = "playlists_songs";
const string PLAYLIST_ID = "playlist_id";
const string SONG_ID = "song_id";
const string EMPTY_STRING = "";

DeleteSongFrPlaylistCommand::DeleteSongFrPlaylistCommand(const InputLine& input)
{
    verify(input);
    playlistID = stoi(input[PLAYLIST_ID_INDEX]);
    songID = stoi(input[SONG_ID_INDEX]);
}

int DeleteSongFrPlaylistCommand::getPlaylistID()
{
    return playlistID;
}

int DeleteSongFrPlaylistCommand::getSongID()
{
    return songID;
}
    
CommandType DeleteSongFrPlaylistCommand::getType()
{
    return DELETE_SONG_PLAYLIST;
}

void DeleteSongFrPlaylistCommand::verify(const InputLine& input)
{
    InputLine correctSyntax = getCorrectSyntax();
    if(input.size() != correctSyntax.size())
    {
        invalidCommand();
    }
    for(int i=0; i<correctSyntax.size(); i++)
    {
        if(!isAnInfoIndex(i) && (input[i] != correctSyntax[i]))
        {
            invalidCommand();
        }
    }
}

InputLine DeleteSongFrPlaylistCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(DELETE_REQUEST);
    syntax.push_back(SONG_PLAYLISTS);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(PLAYLIST_ID);
    syntax.push_back(EMPTY_STRING);
    syntax.push_back(SONG_ID);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void DeleteSongFrPlaylistCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

bool DeleteSongFrPlaylistCommand::isAnInfoIndex(int i)
{
    return i == SONG_ID_INDEX || i == PLAYLIST_ID_INDEX;
}