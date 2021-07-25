#ifndef _ARTIST_CRITERIA_HPP_
#define _ARTIST_CRITERIA_HPP_ 1

#include "SongFilter.hpp"

class ArtistCriteria : public SongFilter
{
public:
    ArtistCriteria(std::string artistName);
    std::vector<Song*> meetCriteria(const std::vector<Song*>& songs);
private:
    std::string artistName;
}; 

#endif