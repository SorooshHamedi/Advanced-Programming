#ifndef _SONG_CONFIDENCE_DATA_HPP_
#define _SONG_CONFIDENCE_DATA_HPP_ 1

#include "Song.hpp"

class SongConfidenceData
{
public:
    SongConfidenceData(float confidence, Song* song);
    friend bool operator<(SongConfidenceData a, SongConfidenceData b);
    friend std::ostream& operator<<(std::ostream& stream, const SongConfidenceData& u);
private:
    float confidence;
    Song* song;
};


#endif