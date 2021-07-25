#ifndef _SONG_HPP_
#define _SONG_HPP_ 1

#include <string>
#include <vector>
#include "SongComment.hpp"
#include "ExceptionClass/EmptyError.hpp"
class Song
{
public:
    Song(int _id, std::string _artist, std::string _title, int _releaseYear, std::string link);
    ~Song();
    friend std::ostream& operator<<(std::ostream& stream, const Song& song);
    friend bool operator<(const Song a, const Song b);
    int getID();
    std::string getArtist();
    int getReleaseYear();
    int getNumberOfLikes();
    void addLike();
    void addComment(int time,std::string text, std::string username);
    std::string printAllComments();
    void addPlaylist();
    void deleteLike();
    void deletePlaylist();
    std::string infoInStyle();
private:
    int id;
    std::string artist;
    std::string title;
    int releaseYear;
    std::string link;
    std::vector<SongComment*> comments;
    int numberOfPlaylists;
    int numberOfLikes;
};


struct SongComparator
{
    bool operator()(Song* a, Song* b);
};
#endif