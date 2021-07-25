#include "SongConfidenceData.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

const float PERCENT = 100;
const int PRECISION = 2;
const char PERCENTAGE_CHAR = '%';

SongConfidenceData::SongConfidenceData(float _confidence, Song* _song)
{
    confidence = _confidence;
    song = _song;
}

bool operator<(SongConfidenceData a, SongConfidenceData b)
{
    if(a.confidence != b.confidence)
    {
        return a.confidence < b.confidence;
    }
    else
    {
        return *(a.song) < *(b.song);
    }
}

ostream& operator<<(ostream& stream, const SongConfidenceData& u)
{
    stringstream sstream;
    sstream << *(u.song);
    string word;
    sstream >> word;
    stream << word << " " << fixed << setprecision(PRECISION) << u.confidence*PERCENT << PERCENTAGE_CHAR;

    while(sstream >> word)
    {
        stream << " ";
        stream << word;
    }
    return stream;
}