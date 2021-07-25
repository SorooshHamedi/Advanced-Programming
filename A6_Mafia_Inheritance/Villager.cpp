#include "Villager.hpp"

using namespace std;
Villager::Villager(string name) : Citizen(name)
{
    role = VILLAGER;
}

void Villager::nightAction(Person* person)
{
    exception* ex = new UserNightWakeUpError();
    throw ex;
}

std::string Villager::toStringInfoForNight()
{
    return EMPTY_STRING;
}