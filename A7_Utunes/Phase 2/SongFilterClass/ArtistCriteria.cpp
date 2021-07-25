#include "ArtistCriteria.hpp"
using namespace std;

ArtistCriteria::ArtistCriteria(string _artistName)
{
    artistName = _artistName;
}

vector<Song*> ArtistCriteria::meetCriteria(const vector<Song*>& songs)
{
    vector<Song*> filteredList;
    for(Song* song:songs)
    {
        if(song->getArtist() == artistName)
        {
            filteredList.push_back(song);
        }
    }
    return filteredList;
}

