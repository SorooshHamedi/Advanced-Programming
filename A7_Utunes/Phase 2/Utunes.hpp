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
#include "LikedSongsMatrix.hpp"
#include "AllExceptionClasses.hpp"
#include "AllCommandLibraries.hpp"
#include "AllSongFilterClasses.hpp"
#include "UserSimilarityData.hpp"
#include "SongConfidenceData.hpp"
#include <map>

class Utunes
{
public:
    Utunes(std::string songsAddress, std::string likedSongsAddress);
    ~Utunes();
    void execute();
private:
    std::vector<User*> users;
    std::vector<Song*> allSongs;
    std::vector<SongFilter*> filters;
    LikedSongsMatrix* songsMatrix;
    std::string songsAddress;
    std::string likedSongsAddress;
    User* loggedInUser;
    int newPlaylistID;

    void storeSongsData();
    void storeLikesData();
    void storeUserLike(const InputLine& line);
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
    void printSimilarUsers(GetSimilarUsersCommand* command);
    void printRecommendedSongs(GetRecommendedSongsCommand* command);

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
    std::vector<UserSimilarityData> getSimilarityData(User* user, int count);
    std::vector<SongConfidenceData> getConfidenceData(User* user, int count);

    void reportError(const std::string& error);
    void reportSuccess();
    void print(const std::string& str);
    void print(Song* song);
    void print(const UserSimilarityData& u);
    void print(const SongConfidenceData& u);
    void printAllSongs();
    void printSong(GetSongCommand* command);
    void print(Playlist* playlist);
};




#endif