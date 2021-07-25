#include "Person.hpp"

Person::Person(std::string _name)
{
    name = _name;
    lifeStatus = ALIVE;
    isSilenced = false;
    votes = 0;
}

void Person::setName(std::string _name)
{
    name = _name;
}

void Person::setSilence(bool _silence)
{
    isSilenced = _silence;
}
void Person::die()
{
    lifeStatus = DEAD;
}

void Person::heal()
{
    deadPatientCheck();
    wasHealed = true;
}

void Person::deadPatientCheck()
{
    if(!isAlive())
    {
        std::exception* ex = new DeadPatientError();
        throw ex;
    }
}

void Person::deadSuspectCheck()
{
    if(!isAlive())
    {
        std::exception* ex = new DeadSuspectError();
        throw ex;
    }
}

void Person::silence()
{
    deadPersonCheck();
    isSilenced = true;
}

void Person::deadPersonCheck()
{
    if(!isAlive())
    {
        std::exception* ex = new DeadPersonError();
        throw ex;
    }
}

bool Person::isAlive()
{
    return lifeStatus;
}

void Person::addVote()
{
    deadVoteeCheck();
    votes++;
}

void Person::subtractVote()
{
    votes--;
}

void Person::dayVote(Person* votee)
{
    silencedVoterCheck();
    deadUserCheck();
    votee->addVote();
    if(prevVotee != nullptr)
    {
        prevVotee->subtractVote();
    }
    prevVotee = votee;

}

std::string Person::getRole()
{
    return role;
}

void Person::silencedVoterCheck()
{
    if(isSilenced)
    {
        std::exception* ex = new SilencedVoterError();
        throw ex;
    }
}

void Person::deadVoteeCheck()
{
    if(lifeStatus == DEAD)
    {
        std::exception* ex = new DeadVoteeError();
        throw ex;
    }
}

std::string Person::getName()
{
    return name;
}

int Person::getVotes()
{
    return votes;
}

void Person::deadUserCheck()
{
    if(!isAlive())
    {
        std::exception* ex = new DeadUserError();
        throw ex;
    }
}

void Person::print(std::string str)
{
    std::cout << str;
    std::cout.flush();
}

void Person::dieByMafia()
{
    if(!wasHealed)
        lifeStatus = DEAD;
}

void Person::updateAfterDay()
{
    prevVotee = nullptr;
    isSilenced = false;
    votes = 0;
}

void Person::updateAfterNight()
{
    prevVotee = nullptr;
    votes = 0;
}

bool Person::isSilence()
{
    return isSilenced;
}