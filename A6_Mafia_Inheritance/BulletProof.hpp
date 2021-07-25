#ifndef _BULLETPROOF_HPP_
#define _BULLETPROOF_HPP_

#include "Citizen.hpp"
#include "ExceptionClass/UserNightWakeUp.hpp"
const std::string BULLETPROOF = "bulletproof";
class BulletProof : public Citizen
{
public:
    BulletProof(std::string name);
    virtual void nightAction(Person* person);
    virtual std::string toStringInfoForNight();
    virtual void dieByMafia();
private:
    bool usedAbility;
};

#endif