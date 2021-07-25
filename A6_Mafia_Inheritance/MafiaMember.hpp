#ifndef _MAFIA_MEMBER_HPP_
#define _MAFIA_MEMBER_HPP_

#include "Mafia.hpp"

const std::string MAFIA = "mafia";
class MafiaMember : public Mafia
{
public:
    MafiaMember(std::string name);
    virtual void nightAction(Person* person);
};

#endif
