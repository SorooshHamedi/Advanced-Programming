#include "AddSongToPlaylistCommand.hpp"
using namespace std;
const int PLAYLIST_ID_INDEX = 4;
const int SONG_ID_INDEX = 6;
const string SONG_PLAYLISTS = "playlists_songs";
const string PLAYLIST_ID = "playlist_id";
const string SONG_ID = "song_id";
const string EMPTY_STRING = "";

AddSongToPlaylistCommand::AddSongToPlaylistCommand(const InputLine& input)
{
    verify(input);
    playlistID = stoi(input[PLAYLIST_ID_INDEX]);
    songID = stoi(input[SONG_ID_INDEX]);
}

int AddSongToPlaylistCommand::getPlaylistID()
{
    return playlistID;
}

int AddSongToPlaylistCommand::getSongID()
{
    return songID;
}
    
CommandType AddSongToPlaylistCommand::getType()
{
    return ADD_SONG_PLAYLIST;
}

void AddSongToPlaylistCommand::verify(const InputLine& input)
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

InputLine AddSongToPlaylistCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(WRITE_REQUEST);
    syntax.push_back(SONG_PLAYLISTS);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(PLAYLIST_ID);
    syntax.push_back(EMPTY_STRING);
    syntax.push_back(SONG_ID);
    syntax.push_back(EMPTY_STRING);
    return syntax;
}

void AddSongToPlaylistCommand::invalidCommand()
{
    exception* ex = new NotFoundError();
    throw ex;
}

bool AddSongToPlaylistCommand::isAnInfoIndex(int i)
{
    return i == PLAYLIST_ID_INDEX || i == SONG_ID_INDEX;
}