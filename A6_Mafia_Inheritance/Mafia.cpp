#include "Mafia.hpp"
using namespace std;

Mafia::Mafia(string name) : Person(name)
{

}

void Mafia::mafiaVote(Person* votee)
{
    if(prevVotee != nullptr)
        prevVotee->subtractVote();
    
    votee->addVote();
    prevVotee = votee;
}

bool Mafia::isMafia()
{
    return true;
}

bool Mafia::isCitizen()
{
    return false;
}

std::string Mafia::toStringInfoForNight()
{
    if(isAlive())
        return name + INFO_DIVIDER + role + NEXT_LINE;
    else
        return EMPTY_STRING;
}

void Mafia::askAbout()
{
    deadSuspectCheck();
    print(MAFIA_ANSWER);
}