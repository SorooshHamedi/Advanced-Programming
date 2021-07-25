#include "LikedSongsMatrix.hpp"
using namespace std;

LikedSongsMatrix::LikedSongsMatrix(const vector<User*>& _users, const vector<Song*>& _songs)
{
    users = _users;
    songs = _songs;
    updateData();
}

LikedSongsMatrix::LikedSongsMatrix(const vector<Song*>& _songs)
{
    songs = _songs;
    updateData();
}
    
void LikedSongsMatrix::addUser(User* user)
{
    users.push_back(user);
    updateData(user);
}

void LikedSongsMatrix::addLike(User* user, Song* song)
{
    data[{user, song}] = true;
}   

void LikedSongsMatrix::deleteLike(User* user, Song* song)
{
    data[{user, song}] = false;
}

float LikedSongsMatrix::getSimilarity(User* a, User* b)
{
    int sharedLikes = 0;
    for(Song* song:songs)
    {
        if(data[{a,song}] && data[{b,song}])
            sharedLikes++;
    }
    return (float)sharedLikes / songs.size();
}

void LikedSongsMatrix::updateData()
{
    for(User* user:users)
    {
        for(Song* song:songs)
        {
            data[{user, song}] = user->hasLiked(song);
        }
    }
}
    
void LikedSongsMatrix::updateData(User* user)
{
    for(Song* song:songs)
    {
        data[{user, song}] = user->hasLiked(song);
    }
}

bool LikedSongsMatrix::operator[](pair<User*, Song*> index)
{
    return data[index];
}

float LikedSongsMatrix::getConfidence(User* user, Song* song)
{
    float confidence = 0.00;
    if(users.size() == 1)
    {
        return confidence;
    }

    for(User* u:users)
    {
        if(u != user && data[{u, song}])
        {
            confidence += getSimilarity(user, u);
        }
    }
    return confidence / (users.size()-1);
}
