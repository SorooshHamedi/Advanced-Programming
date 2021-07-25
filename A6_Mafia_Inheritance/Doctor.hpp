#ifndef _DOCTOR_HPP_
#define _DOCTOR_HPP_

#include "Citizen.hpp"
#include "ExceptionClass/DoctorAlreadyHealed.hpp"

const std::string DOCTOR = "doctor";
class Doctor : public Citizen
{
public:
    Doctor(std::string name);
    virtual void nightAction(Person* person);
    virtual std::string toStringInfoForNight();
    virtual void updateAfterNight();
private:
    bool hasUsedHealing;
    void heal(Person* person);
    void usedHealingCheck();
};



#endif