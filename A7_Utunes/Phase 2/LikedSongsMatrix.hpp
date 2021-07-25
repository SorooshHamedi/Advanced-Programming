#ifndef _LIKED_SONGS_MATRIX_HPP_
#define _LIKED_SONGS_MATRIX_HPP_ 1

#include "Song.hpp"
#include "User.hpp"
#include <vector>
#include <map>
#include <utility>

class LikedSongsMatrix
{
public:
    LikedSongsMatrix(const std::vector<User*>& users, const std::vector<Song*>& songs);
    LikedSongsMatrix(const std::vector<Song*>&  songs);
    void addUser(User* user);
    void addLike(User* user, Song* song);
    void deleteLike(User* user, Song* song);
    float getSimilarity(User* a, User* b);
    float getConfidence(User* user, Song* song);
    bool operator[](std::pair<User*, Song*> index);
private:
    std::vector<Song*> songs;
    std::vector<User*> users;
    std::map<std::pair<User*, Song*>, bool> data;

    void updateData();
    void updateData(User* user);
};




#endif