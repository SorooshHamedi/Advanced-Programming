#ifndef _NUMBER_OF_LIKES_CRITERIA_HPP_
#define _NUMBER_OF_LIKES_CRITERIA_HPP_ 1

#include "SongFilter.hpp"

class NumberOfLikesCriteria : public SongFilter
{
public:
    NumberOfLikesCriteria(int min, int max);
    std::vector<Song*> meetCriteria(const std::vector<Song*>& songs);
private:
    int min;
    int max;
};

#endif