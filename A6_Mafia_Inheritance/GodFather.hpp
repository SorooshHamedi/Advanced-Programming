#ifndef _GODFATHER_HPP_
#define _GODFATHER_HPP_

#include "Mafia.hpp"

const std::string GODFATHER_ANSWER = "No\n";
const std::string GODFATHER = "godfather";
class GodFather : public Mafia
{
public:
    GodFather(std::string name);
    virtual void nightAction(Person* person);
    virtual void askAbout();
};

#endif