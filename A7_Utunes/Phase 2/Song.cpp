#include "Song.hpp"
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

const string NUM_OF_LIKES_STRING = "#likes:";
const string NUM_OF_COMMENTS_STRING = "#comments:";
const string NUM_OF_PLAYLISTS_STRING = "#playlists:";

Song::Song(int _id, std::string _artist, std::string _title, int _releaseYear, std::string _link)
{
    id = _id;
    artist = _artist;
    title = _title;
    releaseYear = _releaseYear;
    link = _link;
    numberOfPlaylists = 0;
    numberOfLikes = 0;
}

Song::~Song()
{
    for(SongComment* comment:comments)
    {
        delete comment;
    }
}
ostream& operator<<(std::ostream& stream, const Song& song)
{
    stream << song.id << " ";
    stream << song.title << " ";
    stream << song.artist << " ";
    stream << song.releaseYear;
    return stream;
}

bool operator<(const Song a, const Song b)
{
    return a.id < b.id;
}

std::string Song::infoInStyle()
{
    stringstream sstream;
    sstream << id << "\n";
    sstream << title << "\n";
    sstream << artist << "\n";
    sstream << releaseYear << "\n";
    sstream << NUM_OF_LIKES_STRING << " " << numberOfLikes << "\n";
    sstream << NUM_OF_COMMENTS_STRING << " " << comments.size() << "\n";
    sstream << NUM_OF_PLAYLISTS_STRING << " " << numberOfPlaylists;
    return sstream.str();
}

int Song::getID()
{
    return id;
}


bool SongComparator::operator()(Song* a, Song* b)
{
    return *a < *b;
}

void Song::addLike()
{
    numberOfLikes++;
}

void Song::addPlaylist()
{
    numberOfPlaylists++;
}

void Song::deleteLike()
{
    numberOfLikes--;
}

void Song::deletePlaylist()
{
    numberOfPlaylists--;
}

void Song::addComment(int time,std::string text, std::string username)
{
    SongComment* newComment = new SongComment(time, username, text);
    comments.push_back(newComment);
    sort(comments.begin(), comments.end(), SongCommentComparator());
}

std::string Song::printAllComments()
{
    if(comments.empty())
    {
        exception* ex = new EmptyError();
        throw ex;
    }
    else
    {
        stringstream output;
        for(SongComment* comment:comments)
        {
            output << *comment << "\n"; 
        }
        return output.str();
    }
}

string Song::getArtist()
{
    return artist;
}

int Song::getReleaseYear()
{
    return releaseYear;
}

int Song::getNumberOfLikes()
{
    return numberOfLikes;
}