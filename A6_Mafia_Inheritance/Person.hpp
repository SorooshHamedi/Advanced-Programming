#ifndef _PERSON_HPP_
#define _PERSON_HPP_

#include <string>
#include <iostream>
#include "ExceptionClass/SilencedVoter.hpp"
#include "ExceptionClass/DeadVotee.hpp"
#include "ExceptionClass/DeadUser.hpp"
#include "ExceptionClass/DeadPatient.hpp"
#include "ExceptionClass/DeadSuspect.hpp"
#include "ExceptionClass/DeadPerson.hpp"

const bool ALIVE = true;
const bool DEAD = false;
const std::string INFO_DIVIDER = ": ";
const std::string EMPTY_STRING = "";
const char NEXT_LINE = '\n';
class Person
{
public:
    Person(std::string name);
    void changeNameTo(std::string name);
    std::string getRole();
    virtual bool isMafia() = 0;
    virtual bool isCitizen() = 0;
    bool isSilence();
    int getVotes();
    void setName(std::string _name);
    void setSilence(bool _silence);
    std::string getName();
    void die();
    bool isAlive();
    void dayVote(Person* person);
    void addVote();
    void subtractVote(); 
    virtual std::string toStringInfoForNight() = 0;
    void heal();
    virtual void askAbout() = 0;
    virtual void dieByMafia();
    void silence();
    void updateAfterDay();
    virtual void updateAfterNight();
    virtual void nightAction(Person* person) = 0;
    void deadUserCheck();
private:
    int votes;
    bool isSilenced;

    void deadPatientCheck();
    void deadPersonCheck();
protected:
    std::string name;
    std::string role;
    Person* prevVotee;
    bool lifeStatus;
    bool wasHealed;
    void silencedVoterCheck();
    void deadVoteeCheck();  
    void print(std::string);  
    void deadSuspectCheck();
};


#endif