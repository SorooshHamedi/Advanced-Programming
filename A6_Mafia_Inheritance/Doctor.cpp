#include "Doctor.hpp"

Doctor::Doctor(std::string name) : Citizen(name)
{
    hasUsedHealing = false;
    role = DOCTOR;
}

void Doctor::nightAction(Person* person)
{
    deadUserCheck();
    heal(person);
}

void Doctor::heal(Person* person)
{
    usedHealingCheck();
    person->heal();
    hasUsedHealing = true;
}

std::string Doctor::toStringInfoForNight()
{
    if(isAlive())
        return name + INFO_DIVIDER + role + NEXT_LINE;
    else
        return EMPTY_STRING;
}

void Doctor::usedHealingCheck()
{
    if(hasUsedHealing)
    {
        std::exception* ex = new DoctorAlreadyHealedError();
        throw ex;
    }
}

void Doctor::updateAfterNight()
{
    Person::updateAfterNight();
    hasUsedHealing = false;
}