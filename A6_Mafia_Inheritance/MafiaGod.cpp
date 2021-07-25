#include "MafiaGod.hpp"
using namespace std;
MafiaGod::MafiaGod()
{
    gameCreated = gameStarted = false;
    dayCounter = nightCounter = TIME_START;
    deadJoker = false;
    hasSwapped = false;
    ongoingNight = false;
    nightVictim = nullptr;
}

void MafiaGod::executeGame()
{
    string inputLine;
    while(getline(cin, inputLine))
    {
        Parser inputParser(inputLine);
        try 
        {
            executeRequest(inputParser.parsedInput);
        } catch(exception* ex) {
            print(ex->what());
            delete ex;
        }
    }
}

void MafiaGod::print(string message)
{
    cout << message;
    cout.flush();
}

void MafiaGod::executeRequest(Input request)
{
    if(request.front() == CREATE_GAME)
    {
        request.erase(request.begin());
        createGame(request);
    }
    else if(request.front() == ASSIGN_ROLE)
    {
        request.erase(request.begin());
        assignRole(request[0], request[1]);
    }
    else if(request.front() == START_GAME)
    {
        startGame();
    }
    else if(request.front() == SWAP_CHARACTER)
    {
        request.erase(request.begin());
        swapCharacter(request[0], request[1]);
    }
    else if(request.front() == END_NIGHT)
    {
        processNightEvents();
    }
    else if(request.front() == END_VOTE)
    {
        processDayVoting();
    }
    else if(request.front() == GET_GAME_STATE)
    {
        getGameState();
    }
    else
    {
        executeAction(request[0], request[1]);
    }
}

void MafiaGod::createGame(Input request)
{
    gameCreated = true;
    for(string name:request)
    {
        names.push_back(name);
        people[name] = nullptr;
    }
}

void MafiaGod::assignRole(string name, string role)
{
    assignRoleErrorCheck(name);

    roles[name] = role;   
    if(people[name] != nullptr)
        delete people[name];
    createPerson(name, role); 
}

void MafiaGod::startGame()
{
    startGameErrorCheck();

    updateInfoAboutGroups();
    gameStarted = true;
    printPeoplesRoles();
    printStartGameMessage();
    startNewDay();
}

void MafiaGod::printStartGameMessage()
{
    print(START_GAME_MESSAGE + NEXT_LINE);
}

void MafiaGod::printPeoplesRoles()
{
    for(string name:names)
    {
        printInfo(name);
    }
}
  
void MafiaGod::createPerson(std::string name, std::string role)
{
    Person* newRole;

    if(role == JOKER)
    {
        newRole = new Joker(name);
    }
    else if(role == VILLAGER)
    {
        newRole = new Villager(name);
    }
    else if(role == SILENCER)
    {
        newRole = new Silencer(name);
    }
    else if(role == MAFIA)
    {
        newRole = new MafiaMember(name);
    }
    else if(role == GODFATHER)
    {
        newRole = new GodFather(name);
    }
    else if(role == DETECTIVE)
    {
        newRole = new Detective(name);
    }
    else if(role == DOCTOR)
    {
        newRole = new Doctor(name);
    }
    else if(role == BULLETPROOF)
    {
        newRole = new BulletProof(name);
    }
    people[name] = newRole;
}


void MafiaGod::startNewDay()
{
    timeOfDay = DAY_TIME;
    dayVoteInProgress = true;
    printNewDayMessage();
    reportLastNightEvents();
    updateAfterNight();
    dayCounter++;
}

void MafiaGod::startNewNight()
{
    updateAfterDay();
    printStartOfNightInfo();
    nightCounter++;
    timeOfDay = NIGHT_TIME;
    ongoingNight = true;
}

void MafiaGod::reportLastNightEvents()
{
    reportLastNightDeath();
    reportSilencedPeople();

}

void MafiaGod::reportLastNightDeath()
{
    if(nightVictim == nullptr)
        return;

    if(!nightVictim->isAlive())
    {
        print(nightVictim->getName() + NIGHT_DEATH_MESSAGE +NEXT_LINE);
    }
}

void MafiaGod::reportSilencedPeople()
{
    for(string name:names)
    {
        if(people[name]->isSilence())
        {
            print(SILENCED_MESSAGE + name + NEXT_LINE);
        }
    }
}

void MafiaGod::printNewNightMessage()
{
    print(NEW_NIGHT_MESSAGE + to_string(nightCounter) + NEXT_LINE);
}

void MafiaGod::printStartOfNightInfo()
{
    printNewNightMessage();
    for(string name:names)
    {
        print(people[name]->toStringInfoForNight());
    }
}

void MafiaGod::printNewDayMessage()
{
    print(NEW_DAY_MESSAGE + " " + to_string(dayCounter) + NEXT_LINE);
}

void MafiaGod::printInfo(string name)
{
    print(name + INFO_DIVIDER + roles[name] + NEXT_LINE);
}
void MafiaGod::executeAction(string name1, string name2)
{
    checkIfUserExists(name1);
    checkIfUserExists(name2);

    if(timeOfDay == DAY_TIME)
    {
        dayVote(name1, name2);
    }
    else
    {
        nightAction(name1, name2);
    }
}

void MafiaGod::dayVote(std::string name1, std::string name2)
{
    people[name1]->dayVote(people[name2]);
}

void MafiaGod::nightAction(std::string name1, std::string name2)
{
    people[name1]->nightAction(people[name2]);
}

void MafiaGod::processDayVoting()
{
    dayVoteInProgress = false;
    Person* chosen = getVotingResult();
    if(chosen->getVotes() == NO_VOTE)
    {
        return;
    }
    reportDayVotingResult(chosen);
    chosen->die();
    processAfterDeath();
    startNewNight();
}

void MafiaGod::reportDayVotingResult(Person* chosen)
{
    print(chosen->getName() + DAY_DEATH_MESSAGE + NEXT_LINE);
}

void MafiaGod::processAfterDeath()
{
    updateInfoAboutGroups();
    if(deadJoker && timeOfDay == DAY_TIME)
        endGame(JOKER_WIN);
    else if(numberOfCitizens <= numberOfMafia)
        endGame(MAFIA_WIN);
    else if(numberOfMafia == 0)
        endGame(CITIZEN_WIN);
}

Person* MafiaGod::getVotingResult()
{
    vector<Person*> votesInfo;
    for(string name:names)
    {
        if(people[name]->isAlive())
        {
            votesInfo.push_back(people[name]);
        }
    }
    sort(votesInfo.begin(), votesInfo.end(), bind(&MafiaGod::votingCompFunc, this, placeholders::_1, placeholders::_2));
    return votesInfo.back();
}

bool MafiaGod::votingCompFunc(Person* a, Person* b)
{
    int voteA = a->getVotes();
    int voteB = b->getVotes();
    if(voteA != voteB)
    {
        return voteA < voteB;
    }
    else
    {
        return a->getName() > b->getName();
    }
    
}

void MafiaGod::checkIfUserExists(string name)
{
    if(!people.count(name))
    {
        exception* ex = new UserNotJoinedError();
        throw ex;
    }
}

void MafiaGod::checkIfGameWasCreated()
{
    if(!gameCreated)
    {
        exception* ex = new NoGameCreatedError();
        throw ex;
    }
}

void MafiaGod::endGame(int result)
{
    reportGameResult(result);
    for(auto u:people)
    {
        if(u.second != nullptr)
             delete u.second;
    }
    _Exit(0);
}

void MafiaGod::reportGameResult(int result)
{
    if(result == JOKER_WIN)
        print(JOKER_WIN_MESSAGE);
    else if(result == MAFIA_WIN)
        print(MAFIA_WIN_MESSAGE);
    else
        print(CITIZEN_WIN_MESSAGE);
}

void MafiaGod::assignRoleErrorCheck(std::string name)
{
    checkIfGameWasCreated();
    checkIfUserExists(name);
}

void MafiaGod::startGameErrorCheck()
{
    checkForPlayerWithoutRole();
    checkIfGameWasCreated();
    checkIfGameHasAlreadyStarted();
}

void MafiaGod::checkForPlayerWithoutRole()
{
    for(string name:names)
    {
        if(people[name] == nullptr)
        {
            exception* ex = new PlayerWithoutRoleError();
            throw ex;
        }
    }
}

void MafiaGod::checkIfGameHasAlreadyStarted()
{
    if(gameStarted)
    {
        exception* ex = new GameAlreadyStartedError();
        throw ex;
    }
}

void MafiaGod::updateInfoAboutGroups()
{
    numberOfCitizens = numberOfMafia = 0;
    for(string name:names)
    {
        updateGroupsInfoUsing(name);
    }
}

void MafiaGod::updateGroupsInfoUsing(string name)
{
    bool isAlive = people[name]->isAlive();
    bool isMafia = people[name]->isMafia();
    bool isCitizen = people[name]->isCitizen();
    if(isAlive)
    {
        numberOfMafia += isMafia;
        numberOfCitizens += isCitizen;
    }
    else if(!isMafia && !isCitizen)
    {
        deadJoker = true;
    }
}

void MafiaGod::processNightEvents()
{
    ongoingNight = false;
    nightVictim = getVotingResult();
    nightVictim->dieByMafia();
    reportNightVictim();
    checkForSwap();
    if(timeOfDay == NIGHT_TIME)
    {
        startNewDay();
    }
}

void MafiaGod::updateAfterNight()
{
    for(string name:names)
    {
        people[name]->updateAfterNight();
    }
    hasSwapped = false;
}

void MafiaGod::updateAfterDay()
{
    for(string name:names)
    {
        people[name]->updateAfterDay();
    }
    nightVictim = nullptr;
}

void MafiaGod::reportNightVictim()
{
    print(END_NIGHT_VICTIM_MESSAGE + nightVictim->getName() + NEXT_LINE);
}

void MafiaGod::swapCharacter(string name1, string name2)
{
    swapCharacterErrorCheck(name1, name2);
    MafiaGod::swap(name1, name2);
    hasSwapped = true;
}

void MafiaGod::swap(string a, string b)
{
    Person* aPerson = people[a];
    Person* bPerson = people[b];
    bool aSilence = aPerson->isSilence(), bSilence = bPerson->isSilence();
    people[a] = bPerson, people[b] = aPerson;
    people[a]->setName(a), people[b]->setName(b);
    people[a]->setSilence(aSilence), people[b]->setSilence(bSilence);
}

void MafiaGod::swapCharacterErrorCheck(string name1, string name2)
{
    checkIfUserExists(name1), checkIfUserExists(name2);
    people[name1]->deadUserCheck(), people[name2]->deadUserCheck();
    checkIfAlreadySwapped();
    checkIfNightHasEnded();
    checkForVotingInProgress();
}

void MafiaGod::checkForVotingInProgress()
{
    if(dayVoteInProgress)
    {
        exception* ex = new VotingInProgressError();
        throw ex;
    }
}

void MafiaGod::checkIfAlreadySwapped()
{
    if(hasSwapped)
    {
        exception* ex = new CharactersAlreadySwappedError();
        throw ex;
    }
}

void MafiaGod::checkIfNightHasEnded()
{
    if(ongoingNight)
    {
        exception* ex = new SwapBeforeEndOfNightError();
        throw ex;
    }
}

void MafiaGod::checkForSwap()
{
    string inputLine;
    while(getline(cin, inputLine))
    {
        Parser inputParser(inputLine);
        try{
            int ans = swapCheckExecuteRequest(inputParser.parsedInput);
            if(ans == SWAP_COMMAND)
                continue;
            else
            {
                startNewDay();
                executeRequest(inputParser.parsedInput);
                break;
            }
        } catch(exception* ex)
        {
            print(ex->what());
            delete ex;
        }
    }
}

int MafiaGod::swapCheckExecuteRequest(Input request)
{
    if(request.front() == SWAP_CHARACTER)
    {
        request.erase(request.begin());
        swapCharacter(request[0], request[1]);
        return SWAP_COMMAND;
    }
    else
        return OTHER_COMMAND;
    
}

void MafiaGod::getGameState()
{
    updateInfoAboutGroups();
    print(MAFIA_NUMBER_MESSAGE + to_string(numberOfMafia) + NEXT_LINE);
    print(CITIZEN_NUMBER_MESSAGE + to_string(numberOfCitizens) + NEXT_LINE);
}



