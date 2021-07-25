#include "Playlist.hpp"
#include <sstream>
using namespace std;

const int LIKED_ID = 0;

const std::string PRIVATE = "private";
const std::string PUBLIC = "public";

Playlist::Playlist(int _id, string _title, bool _isPrivate)
{
    id = _id;
    title = _title;
    size = 0;
    isPrivateFlag = _isPrivate;
}

Playlist::Playlist()
{
    id = LIKED_ID;
    size = 0;
}

void Playlist::addSong(Song* song)
{
    checkForDuplicateSongError(song);
    songs.push_back(song);
    size++;
    songs.sort(SongComparator());
    
    if(id == LIKED_ID)
        song->addLike();
    else
        song->addPlaylist();
    
}

void Playlist::deleteSong(Song* song)
{
    checkForSongNotInPlaylistError(song);
    songs.remove(song);
    size--;
    songs.sort(SongComparator());

    if(id == LIKED_ID)
        song->deleteLike();
    else
        song->deletePlaylist();
}

void Playlist::checkForDuplicateSongError(Song* song) const
{
    if(isSongInPlaylist(song))
    {
        duplicateSongError();
    }
}

void Playlist::duplicateSongError() const
{
    exception* ex = new BadRequestError();
    throw ex;
}

void Playlist::checkForSongNotInPlaylistError(Song* song) const
{
    if(!isSongInPlaylist(song))
    {
        songNotInPlaylistError();
    }
}

void Playlist::songNotInPlaylistError() const
{
    exception* ex = new BadRequestError();
    throw ex;
}

bool Playlist::isSongInPlaylist(Song* song) const
{
    for(Song* intSong:songs)
    {
        if(intSong == song)
        {
            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& stream, const Playlist& playlist)
{
    playlist.checkForEmptyError();
    for(Song* song:playlist.songs)
    {
        stream << *song << '\n'; 
    }
    return stream;
}


void Playlist::checkForEmptyError() const
{
    if(songs.empty())
    {
        emptyError();
    }
}

void Playlist::emptyError() const
{
    exception* ex = new EmptyError();
    throw ex;
}

bool PlaylistComparator::operator()(Playlist* a, Playlist* b)
{
    return a->getID() < b->getID();
}

int Playlist::getID()
{
    return id;
}

string Playlist::printInfo()
{
    stringstream sstream;
    sstream << id << " ";
    sstream << title << " ";
    if(isPrivateFlag)
        sstream << PRIVATE;
    else
        sstream << PUBLIC;
    return sstream.str();
}

bool Playlist::isPrivate()
{
    return isPrivateFlag;
}