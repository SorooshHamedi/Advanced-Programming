#ifndef _JOKER_HPP_
#define _JOKER_HPP_

#include "Person.hpp"
#include <string>
#include "ExceptionClass/UserNightWakeUp.hpp"
const std::string JOKER = "joker";
const std::string JOKER_ANSWER = "No\n";

class Joker : public Person
{
public:
    Joker(std::string name);
    virtual void nightAction(Person* person);
    virtual bool isMafia();
    virtual bool isCitizen();
    virtual std::string toStringInfoForNight();
    virtual void askAbout();
private:

};

#endif