#ifndef _USER_HPP_
#define _USER_HPP_ 1

#include "Playlist.hpp"
#include "AllExceptionClasses.hpp"
#include <string>
#include <vector>

const bool LOGGED_IN = true;
const bool LOGGED_OUT = false;

class User
{
public:
    User(std::string username, std::string email, std::string password);
    ~User();
    const std::string& getUsername();
    const std::string& getEmail(); 
    void login(const std::string& password);
    void logout();
    void addLike(Song* song);
    void addNewPlaylist(int playlistID, std::string playlistTitle, bool isPrivate);
    void addSongToPlaylist(int playlistID, Song* song);
    void deleteSongFromPlaylist(int playlistID, Song* song);
    void deleteLike(Song* song);
    std::string printAllPlaylists();
    Playlist* getPlaylist(int playlistID);
    Playlist* getLikedSongs();
    bool isLoggedIn();
private:
    std::string email;
    std::string username;
    size_t password;
    std::vector<Playlist*> personalPlaylists;
    Playlist* likedSongs;
    bool loginStatus;

    void storePassword(std::string password);
    void checkIfPasswordMatches(const std::string& _password);
    void checkIfUserIsLoggedIn();
    Playlist* findPlaylistByID(int id);
    void checkForPlaylistNotForUserError(Playlist* playlist);
    void checkForNoPlaylistError();
    void checkForAccessPermission(Playlist* playlist);
};

struct UserComparator
{
    bool operator()(User* a, User* b);
};
#endif