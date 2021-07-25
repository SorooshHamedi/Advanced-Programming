#include "ReleaseYearCriteria.hpp"
using namespace std;

ReleaseYearCriteria::ReleaseYearCriteria(int _min, int _max)
{
    min = _min;
    max = _max;
}

vector<Song*> ReleaseYearCriteria::meetCriteria(const vector<Song*>& songs)
{
    vector<Song*> filteredList;
    for(Song* song:songs)
    {
        int releaseYear = song->getReleaseYear();
        if(min <= releaseYear && releaseYear <= max)
        {
            filteredList.push_back(song);
        }
    }
    return filteredList;
}
