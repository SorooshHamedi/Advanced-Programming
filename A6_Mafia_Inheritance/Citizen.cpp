#include "Citizen.hpp"
using namespace std;

Citizen::Citizen(string name) : Person(name)
{

}

bool Citizen::isMafia()
{
    return false;
}

bool Citizen::isCitizen()
{
    return true;
}

void Citizen::askAbout()
{
    deadSuspectCheck();
    print(CITIZEN_ANSWER);
}