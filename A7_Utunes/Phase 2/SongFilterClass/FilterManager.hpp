#ifndef _FILTER_MANAGER_HPP_
#define _FILTER_MANAGER_HPP_ 1

#include "../CommandClass/NewFilterCommand.hpp"
#include "../CommandClass/ArtistFilterCommand.hpp"
#include "../CommandClass/LikesFilterCommand.hpp"
#include "../CommandClass/ReleaseYearFilterCommand.hpp"
#include "ArtistCriteria.hpp"
#include "SongFilter.hpp"
#include "ReleaseYearCriteria.hpp"
#include "NumberOfLikesCriteria.hpp"

class FilterManager
{
public:
    FilterManager(NewFilterCommand* command);
    SongFilter* getFilter();
private:
    void parse(NewFilterCommand* command);
    void artistCriteria(ArtistFilterCommand* command);
    void likesCriteria(LikesFilterCommand* command);
    void releaseYearCriteria(ReleaseYearFilterCommand* command);
    SongFilter* filter;
};

#endif
