#ifndef _USER_SIMILARITY_DATA_HPP_
#define _USER_SIMILARITY_DATA_HPP_ 1

#include <string>
#include <iostream>
#include <iomanip>

class UserSimilarityData
{
public:
    UserSimilarityData(float similarity, std::string name);
    friend bool operator<(UserSimilarityData a, UserSimilarityData b);
    friend std::ostream& operator<<(std::ostream& stream, const UserSimilarityData& u);
private:
    float similarity;
    std::string name;
};

#endif