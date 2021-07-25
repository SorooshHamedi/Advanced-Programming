#ifndef _SONG_COMMENT_HPP_
#define _SONG_COMMENT_HPP_ 1

#include <string>
#include <iostream>

class SongComment
{
public:
    SongComment(int time, std::string username, std::string text);
    friend std::ostream& operator<<(std::ostream& stream, const SongComment& comment);
    int getTime();
private:
    int time;
    std::string username;
    std::string text;
};

struct SongCommentComparator
{
    bool operator()(SongComment* a, SongComment* b);
};


#endif