#ifndef _DETECTIVE_HPP_
#define _DETECTIVE_HPP_

#include "Citizen.hpp"
#include "ExceptionClass/DetectiveAlreadyAsked.hpp"

const std::string DETECTIVE = "detective";
class Detective : public Citizen
{
public:
    Detective(std::string name);
    virtual void nightAction(Person* person);
    virtual std::string toStringInfoForNight();
    virtual void updateAfterNight();
private:
    bool hasAsked;
    void askAbout(Person* person);
    void alreadyAskedCheck();
};

#endif