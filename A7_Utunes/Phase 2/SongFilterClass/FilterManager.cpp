#include "FilterManager.hpp"

FilterManager::FilterManager(NewFilterCommand* command)
{
    parse(command);
}

void FilterManager::parse(NewFilterCommand* command)
{
    switch(command->getFilterType())
    {
        case ARTIST:
        {
            artistCriteria((ArtistFilterCommand*)command);
            break;
        }
        case LIKES:
        {
            likesCriteria((LikesFilterCommand*)command);
            break;
        }
        case RELEASE_YEAR:
        {
            releaseYearCriteria(((ReleaseYearFilterCommand*)command));
            break;
        }

    }
}

void FilterManager::artistCriteria(ArtistFilterCommand* command)
{
    filter = new ArtistCriteria(command->getArtist());
}

void FilterManager::likesCriteria(LikesFilterCommand* command)
{
    filter = new NumberOfLikesCriteria(command->getMin(), command->getMax());
}

void FilterManager::releaseYearCriteria(ReleaseYearFilterCommand* command)
{
    filter = new ReleaseYearCriteria(command->getMin(), command->getMax());
}

SongFilter* FilterManager::getFilter()
{
    return filter;
}

