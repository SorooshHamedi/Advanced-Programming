#include "Silencer.hpp"

Silencer::Silencer(std::string name) : Mafia(name)
{
    hasSilenced = false;
    role = SILENCER;
}

void Silencer::nightAction(Person* person)
{
    if(hasSilenced)
    {
        Mafia::mafiaVote(person);
    }
    else {
        deadUserCheck();
        silence(person);
    }
}

void Silencer::silence(Person* person)
{
    person->silence();
    hasSilenced = true;
}

void Silencer::updateAfterNight()
{
    Person::updateAfterNight();
    hasSilenced = false;
}