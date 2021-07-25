#include "NumberOfLikesCriteria.hpp"
using namespace std;

NumberOfLikesCriteria::NumberOfLikesCriteria(int _min, int _max)
{
    min = _min;
    max = _max;
}

vector<Song*> NumberOfLikesCriteria::meetCriteria(const vector<Song*>& songs)
{
    vector<Song*> filteredList;
    for(Song* song:songs)
    {
        int numberOfLikes = song->getNumberOfLikes();
        if(min <= numberOfLikes && numberOfLikes <= max)
        {
            filteredList.push_back(song);
        }
    }
    return filteredList;
}
