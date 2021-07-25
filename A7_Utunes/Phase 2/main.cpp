#include <iostream>
#include "Utunes.hpp"
using namespace std;

const int SONGS_ADDRESS_INDEX = 1;
const int LIKED_SONGS_ADDRESS_INDEX = 2;

int main(int argc, char* argv[])
{
    Utunes utunes(argv[SONGS_ADDRESS_INDEX], argv[LIKED_SONGS_ADDRESS_INDEX]);
    utunes.execute();
    return 0;    
}