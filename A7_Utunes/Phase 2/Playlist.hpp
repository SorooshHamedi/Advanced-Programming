#ifndef _PLAYLIST_HPP_
#define _PLAYLIST_HPP_ 1

#include "Song.hpp"
#include <list>
#include <string>
#include "ExceptionClass/BadRequestError.hpp"
#include "ExceptionClass/EmptyError.hpp"

class Playlist
{
public:
    Playlist();
    Playlist(int id, std::string title, bool isPrivate = true);
    void addSong(Song* song);
    friend std::ostream& operator<<(std::ostream& stream, const Playlist& Playlist);
    int getID();
    size_t size();
    std::string printAllSongs();
    void deleteSong(Song* song);
    bool isPrivate();
    std::string printInfo();
    bool isSongInPlaylist(Song* song) const;
private:
    std::list<Song*> songs;
    std::string title;
    int id;
    bool isPrivateFlag;

    void checkForDuplicateSongError(Song* song) const;
    void checkForSongNotInPlaylistError(Song* song) const;
    void songNotInPlaylistError() const;
    void duplicateSongError() const;
    void checkForEmptyError() const;
    void emptyError() const;
};

struct PlaylistComparator
{
    bool operator()(Playlist* a, Playlist* b);
};



#endif