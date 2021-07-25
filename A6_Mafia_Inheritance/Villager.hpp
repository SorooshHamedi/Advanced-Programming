#ifndef _VILLAGER_HPP_
#define _VILLAGER_HPP_

#include "Citizen.hpp"
#include "Person.hpp"
#include "ExceptionClass/UserNightWakeUp.hpp"
const std::string VILLAGER = "villager";
class Villager : public Citizen
{
public:
    Villager(std::string name);
    virtual void nightAction(Person* person);
    virtual std::string toStringInfoForNight();
private:

};


#endif