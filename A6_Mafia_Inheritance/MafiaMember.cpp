#include "MafiaMember.hpp"

MafiaMember::MafiaMember(std::string name) : Mafia(name)
{
    role = MAFIA;
}

void MafiaMember::nightAction(Person* person)
{
    deadUserCheck();
    mafiaVote(person);
}
