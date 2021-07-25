#include "BulletProof.hpp"

BulletProof::BulletProof(std::string name) : Citizen(name)
{
    role = BULLETPROOF;
    usedAbility = false;
}

void BulletProof::nightAction(Person* person)
{
    std::exception* ex = new UserNightWakeUpError();
    throw ex;    
}

std::string BulletProof::toStringInfoForNight()
{
    return EMPTY_STRING;
}

void BulletProof::dieByMafia()
{
    if(!wasHealed && usedAbility)
    {
        lifeStatus = DEAD;
    }
    else if(!wasHealed)
    {
        usedAbility = true;
    }
}