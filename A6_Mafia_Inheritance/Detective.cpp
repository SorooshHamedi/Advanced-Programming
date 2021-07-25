#include "Detective.hpp"

Detective::Detective(std::string name) : Citizen(name)
{
    hasAsked = false;
    role = DETECTIVE;
}

void Detective::nightAction(Person* person)
{
    deadUserCheck();
    askAbout(person);
}

void Detective::askAbout(Person* person)
{
    alreadyAskedCheck();
    person->askAbout();
    hasAsked = true;
}

std::string Detective::toStringInfoForNight()
{
    if(isAlive())
        return name + INFO_DIVIDER + role + NEXT_LINE;
    else
        return EMPTY_STRING;
}

void Detective::alreadyAskedCheck()
{
    if(hasAsked)
    {
        std::exception* ex = new DetectiveAlreadyAskedError();
        throw ex;
    }
}

void Detective::updateAfterNight()
{
    Person::updateAfterNight();
    hasAsked = false;
}