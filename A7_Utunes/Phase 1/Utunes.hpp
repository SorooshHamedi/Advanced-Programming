#ifndef _UTUNES_HPP_
#define _UTUNES_HPP_ 1

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Song.hpp"
#include "CSVParser.hpp"
#include "Playlist.hpp"
#include "User.hpp"
#include "InputLine.hpp"
#include "AllExceptionClasses.hpp"
#include "AllCommandLibraries.hpp"
#include "AllSongFilterClasses.hpp"
#include <map>

class Utunes
{
public:
    Utunes(std::string fileAddress);
    ~Utunes();
    void execute();
private:
    std::vector<User*> users;
    std::vector<Song*> allSongs;
    std::vector<SongFilter*> filters;
    std::string songsAddress;
    User* loggedInUser;
    int newPlaylistID;

    void storeSongsData();
    void storeSong(const InputLine& line);
    bool getNewCommand(std::string& command);
    void executeCommand(UtunesCommand* command);
    void executeWriteRequest(UtunesCommand* command);
    void executeReadRequest(UtunesCommand* command);
    void executeDeleteRequest(UtunesCommand* command);
    void signup(SignupCommand* command);
    void signup(std::string email, std::string username, std::string password);
    void login(std::string email, std::string password);
    void login(LoginCommand* command);
    void logout();
    void addLike(AddLikeCommand* command);
    void printLikes();
    void deleteLike(DeleteLikeCommand* command);
    void createNewPlaylist(NewPlaylistCommand* command);
    void addSongToPlaylist(AddSongToPlaylistCommand* command);
    void deleteSongFromPlaylist(DeleteSongFrPlaylistCommand* command);
    void printPlaylistSongs(GetPlaylistCommand* command);
    void printAllPlaylists(GetAllPlaylistsCommand* command);
    void addCommentToSong(AddCommentCommand* command);
    void printComments(GetCommentsCommand* command);
    void addNewFilter(NewFilterCommand* command);
    void deleteFilters();
    std::vector<Song*> applyFilters();
    void printUsers(GetUsersCommand* command);

    void checkForDuplicateUser(std::string username, std::string email);
    void checkIfUserIsInSystem(std::string email);
    void checkIfUserIsInSystem(User* user);
    void userNotInSystemError();
    void checkForActiveUserError();
    void checkForNoActiveUserError();
    void checkForNoOtherUserError();
    User* findUserByEmail(std::string email);
    User* findUserByUsername(std::string username);
    Song* findSongByID(int id);
    void checkIfSongIsInSystem(Song* song);
    void songNotInSystemError();
    void checkForNoSongsError(std::vector<Song*> songs);
    void playlistNotInSystemError();

    void reportError(const std::string& error);
    void reportSuccess();
    void print(const std::string& str);
    void print(Song* song);
    void printAllSongs();
    void printSong(GetSongCommand* command);
    void print(Playlist* playlist);
};



#endif