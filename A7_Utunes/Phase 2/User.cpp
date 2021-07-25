#include "User.hpp"
#include <algorithm>
#include <functional>
using namespace std;

User::User(string _username, string _email, string _password)
{
    username = _username;
    email = _email;
    storePassword(_password);
    likedSongs = new Playlist();
    loginStatus = false;
}

User::~User()
{
    for(Playlist* playlist:personalPlaylists)
    {
        delete playlist;
    }
    delete likedSongs;
}


const string& User::getUsername()
{
    return username;
}

const string& User::getEmail()
{
    return email;
}

void User::login(const string& _password)
{
    checkIfPasswordMatches(_password);
    loginStatus = LOGGED_IN;
}

void User::logout()
{
    checkIfUserIsLoggedIn();
    loginStatus = LOGGED_OUT;
}

void User::checkIfPasswordMatches(const std::string& _password)
{
    hash<string> strHash;
    size_t newPass = strHash(_password);
    if(newPass != password)
    {
        exception* ex = new BadRequestError();
        throw ex;
    }
}

void User::checkIfUserIsLoggedIn()
{
    if(loginStatus != LOGGED_IN)
    {
        exception* ex = new PermissionDeniedError();
        throw ex;
    }
}

void User::addLike(Song* song)
{
    likedSongs->addSong(song);
}

Playlist* User::getLikedSongs()
{
    return likedSongs;
}

void User::deleteLike(Song* song)
{
    likedSongs->deleteSong(song);
}

void User::addNewPlaylist(int playlistID, string playlistTitle, bool isPrivate)
{
    Playlist* playlist = new Playlist(playlistID, playlistTitle, isPrivate);
    personalPlaylists.push_back(playlist);
    sort(personalPlaylists.begin(), personalPlaylists.end(), PlaylistComparator());
}


void User::addSongToPlaylist(int playlistID, Song* song)
{
    Playlist* playlist = findPlaylistByID(playlistID);
    checkForPlaylistNotForUserError(playlist);
    playlist->addSong(song);
}

Playlist* User::findPlaylistByID(int id)
{
    for(Playlist* playlist:personalPlaylists)
    {
        if(playlist->getID() == id)
            return playlist;
    }
    return nullptr;
}

void User::deleteSongFromPlaylist(int playlistID, Song* song)
{
    Playlist* playlist = findPlaylistByID(playlistID);
    checkForPlaylistNotForUserError(playlist);
    playlist->deleteSong(song);   
}

Playlist* User::getPlaylist(int playlistID)
{
    Playlist* playlist = findPlaylistByID(playlistID);
    if(playlist == nullptr)
    {
        return nullptr;
    }
    checkForAccessPermission(playlist);
    return playlist;  
}


void User::checkForPlaylistNotForUserError(Playlist* playlist)
{
    if(playlist == nullptr)
    {
        exception* ex = new PermissionDeniedError();
        throw ex;
    }
}

std::string User::printAllPlaylists()
{
    checkForNoPlaylistError();
    string output;
    for(Playlist* playlist:personalPlaylists)
    {
        if(loginStatus == LOGGED_IN)
             output += playlist->printInfo() + '\n';
        else
        {
            if(!playlist->isPrivate())
                output += playlist->printInfo() + '\n';
        }
        
    }
    return output;
}

void User::checkForNoPlaylistError()
{
    if(personalPlaylists.empty())
    {
        exception* ex = new EmptyError();
        throw ex;
    }
}

void User::checkForAccessPermission(Playlist* playlist)
{
    if(loginStatus != LOGGED_IN && playlist->isPrivate())
    {  
        exception* ex = new PermissionDeniedError();
        throw ex;
    }
}

bool UserComparator::operator()(User* a, User* b)
{
    return a->getUsername() < b->getUsername();
}

void User::storePassword(string _password)
{
    hash<string> strHash;
    password = strHash(_password);
}

bool User::hasLiked(Song* song)
{
    return likedSongs->isSongInPlaylist(song);
}

size_t User::getNumberOfLikedSongs()
{
    return likedSongs->size();
}
