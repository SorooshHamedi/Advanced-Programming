#ifndef _RELEASE_YEAR_CRITERIA_HPP_
#define _RELEASE_YEAR_CRITERIA_HPP_ 1

#include "SongFilter.hpp"

class ReleaseYearCriteria : public SongFilter
{
public:
    ReleaseYearCriteria(int min, int max);
    std::vector<Song*> meetCriteria(const std::vector<Song*>& songs);
private:
    int min;
    int max;
};

#endif