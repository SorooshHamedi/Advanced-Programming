#include "GodFather.hpp"

GodFather::GodFather(std::string name) : Mafia(name)
{
    role = GODFATHER;
}

void GodFather::nightAction(Person* person)
{
    deadUserCheck();
    mafiaVote(person);
}

void GodFather::askAbout()
{
    deadSuspectCheck();
    print(GODFATHER_ANSWER);
}