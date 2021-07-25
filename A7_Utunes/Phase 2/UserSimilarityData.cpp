#include "UserSimilarityData.hpp"
using namespace std;
const float PERCENT = 100;
const int PRECISION = 2;
const char PERCENTAGE_CHAR = '%';

UserSimilarityData::UserSimilarityData(float _similarity, string _name)
{
    similarity = _similarity;
    name = _name;
}

bool operator<(UserSimilarityData a, UserSimilarityData b)
{
    if(a.similarity != b.similarity)
    {
        return a.similarity < b.similarity;
    }
    else
    {
        return a.name > b.name;
    }
}

ostream& operator<<(ostream& stream, const UserSimilarityData& u)
{
    float percent = u.similarity * PERCENT;
    stream << fixed << setprecision(PRECISION) << percent << PERCENTAGE_CHAR << " " << u.name;
    return stream;
}