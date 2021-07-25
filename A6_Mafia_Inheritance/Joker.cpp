#include "Joker.hpp"
using namespace std;

Joker::Joker(string name) : Person(name)
{
    role = JOKER;
}

void Joker::nightAction(Person* person)
{
    exception* ex = new UserNightWakeUpError();
    throw ex;
}

bool Joker::isMafia()
{
    return false;
}

bool Joker::isCitizen()
{
    return false;
}

std::string Joker::toStringInfoForNight()
{
    return EMPTY_STRING;
}

void Joker::askAbout()
{
    deadSuspectCheck();
    print(JOKER_ANSWER);
}