#include "SongComment.hpp"

SongComment::SongComment(int _time, std::string _username, std::string _text)
{
    time = _time;
    username = _username;
    text = _text;
}

std::ostream& operator<<(std::ostream& stream, const SongComment& comment)
{
    stream << comment.time << " ";
    stream << comment.username << ": ";
    stream << comment.text;
    return stream;
}

bool SongCommentComparator::operator()(SongComment* a, SongComment* b)
{
    return a->getTime() < b->getTime();
}

int SongComment::getTime()
{
    return time;
}