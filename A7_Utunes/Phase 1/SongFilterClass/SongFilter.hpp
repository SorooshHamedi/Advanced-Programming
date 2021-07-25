#ifndef _SONG_FILTER_HPP_
#define _SONG_FILTER_HPP_

#include "../Song.hpp"
#include <vector>

class SongFilter
{
public: 
    virtual std::vector<Song*> meetCriteria(const std::vector<Song*>& songs) = 0;
};



#endif