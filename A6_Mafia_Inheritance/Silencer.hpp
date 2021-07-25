#ifndef _SILENCER_HPP_
#define _SILENCER_HPP_

#include "Mafia.hpp"
const std::string SILENCER = "silencer";
class Silencer : public Mafia
{
public:
    Silencer(std::string name);
    virtual void nightAction(Person* person);
    virtual void updateAfterNight();
private:
    bool hasSilenced;
    void silence(Person* person);
};

#endif