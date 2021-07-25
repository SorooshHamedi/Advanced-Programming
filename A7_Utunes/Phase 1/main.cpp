#include <iostream>
#include "Utunes.hpp"
using namespace std;

const int FILE_ADDRESS_INDEX = 1;
int main(int argc, char* argv[])
{
    Utunes utunes(argv[FILE_ADDRESS_INDEX]);
    utunes.execute();
    return 0;    
}