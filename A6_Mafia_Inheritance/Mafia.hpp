#ifndef _MAFIA_HPP_
#define _MAFIA_HPP_
#include "Person.hpp"
#include <string>

const std::string MAFIA_ANSWER = "Yes\n";

class Mafia : public Person
{
public:
    Mafia(std::string name);
    virtual bool isMafia();
    virtual bool isCitizen();
    virtual std::string toStringInfoForNight();
    virtual void askAbout();
protected:
    void mafiaVote(Person* person);

};




#endif