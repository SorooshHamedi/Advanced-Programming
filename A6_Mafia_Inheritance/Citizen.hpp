#ifndef _CITIZEN_HPP_
#define _CITIZEN_HPP_

#include "Person.hpp"
#include <string>

const std::string CITIZEN_ANSWER = "No\n";

class Citizen : public Person
{
public:
    Citizen(std::string name);
    virtual bool isMafia();
    virtual bool isCitizen();
    virtual void askAbout();
private:


};



#endif