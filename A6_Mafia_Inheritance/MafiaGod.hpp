#ifndef _MAFIA_GOD_HPP_
#define _MAFIA_GOD_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include "Parser.hpp"
#include "Person.hpp"
#include "Mafia.hpp"
#include "Joker.hpp"
#include "BulletProof.hpp"
#include "Silencer.hpp"
#include "Villager.hpp"
#include "Detective.hpp"
#include "Doctor.hpp"
#include "MafiaMember.hpp"
#include "GodFather.hpp"
#include "ExceptionClass/NoGameCreated.hpp"
#include "ExceptionClass/UserNotJoined.hpp"
#include "ExceptionClass/CharactersAlreadySwapped.hpp"
#include "ExceptionClass/DeadPatient.hpp"
#include "ExceptionClass/DeadPerson.hpp"
#include "ExceptionClass/DeadSuspect.hpp"
#include "ExceptionClass/DeadUser.hpp"
#include "ExceptionClass/DeadVotee.hpp"
#include "ExceptionClass/DetectiveAlreadyAsked.hpp"
#include "ExceptionClass/DoctorAlreadyHealed.hpp"
#include "ExceptionClass/GameAlreadyStarted.hpp"
#include "ExceptionClass/PlayerWithoutRole.hpp"
#include "ExceptionClass/SilencedVoter.hpp"
#include "ExceptionClass/SwapBeforeEndOfNight.hpp"
#include "ExceptionClass/UserNightWakeUp.hpp"
#include "ExceptionClass/UserNotJoined.hpp"
#include "ExceptionClass/VotingInProgress.hpp"

const std::string CREATE_GAME = "create_game";
const std::string ASSIGN_ROLE = "assign_role";
const std::string START_GAME = "start_game";
const std::string END_VOTE = "end_vote";
const std::string END_NIGHT = "end_night";
const std::string SWAP_CHARACTER = "swap_character";
const std::string GET_GAME_STATE = "get_game_state";

const std::string END_NIGHT_VICTIM_MESSAGE = "Mafia tried to kill ";
const std::string START_GAME_MESSAGE = "Ready? Set! Go.";
const std::string NEW_DAY_MESSAGE = "Day";
const std::string NEW_NIGHT_MESSAGE = "Night ";
const std::string DAY_DEATH_MESSAGE = " died";
const std::string NIGHT_DEATH_MESSAGE = " was killed";
const std::string SILENCED_MESSAGE = "Silenced ";
const std::string MAFIA_NUMBER_MESSAGE = "Mafia = ";
const std::string CITIZEN_NUMBER_MESSAGE = "Villager = ";
const std::string JOKER_WIN_MESSAGE = "Joker won";
const std::string CITIZEN_WIN_MESSAGE = "Villagers won";
const std::string MAFIA_WIN_MESSAGE = "Mafia won";

const int TIME_START = 1;
const int DAY_TIME = 0;
const int NIGHT_TIME = 1;

const int JOKER_WIN = 0;
const int MAFIA_WIN = 1;
const int CITIZEN_WIN = 2;

const int SWAP_COMMAND = 1;
const int OTHER_COMMAND = 2;

const int NO_VOTE = 0;

class MafiaGod
{
public:
    MafiaGod();
    void executeGame();
private:
    std::vector<std::string> names;
    std::map<std::string, std::string> roles;
    std::map<std::string, Person*> people;
    Person* nightVictim;
    int dayCounter;
    int nightCounter;
    int timeOfDay;
    int numberOfMafia;
    int numberOfCitizens;
    std::pair<std::string, std::string> swappedPeople;
    bool deadJoker;
    bool gameCreated;
    bool dayVoteInProgress;
    bool gameStarted;
    bool hasSwapped;
    bool ongoingNight;

    void executeRequest(Input request);

    void print(std::string message);
    void printInfo(std::string name);
    void printNewDayMessage();
    void printNewNightMessage();
    void printStartOfNightInfo();
    void printStartGameMessage();
    void reportNightVictim();
    void reportLastNightEvents();
    void reportLastNightDeath();
    void reportSilencedPeople();
    void createGame(Input request);
    void assignRole(std::string name, std::string role);
    void startGame();
    void endGame(int result);
    void printPeoplesRoles();
    void createObjects();
    void createPerson(std::string name, std::string role);
    void startNewDay();
    void dayVote(std::string name1, std::string name2);
    void executeAction(std::string name1, std::string name2);
    void nightAction(std::string name1, std::string name2);
    void processDayVoting();
    Person* getVotingResult();
    void processAfterDeath();
    void updateInfoAboutGroups();
    void updateGroupsInfoUsing(std::string name);
    void reportDayVotingResult(Person* chosen);
    void startNewNight();
    void updateAfterDay();
    void updateAfterNight();
    void processNightEvents();
    void processNightVoting();
    void swapCharacter(std::string name1, std::string name2);
    void checkForSwap();
    int swapCheckExecuteRequest(Input input);
    void getGameState();
    void reportGameResult(int result);
    void checkIfUserExists(std::string name);
    void checkIfGameWasCreated();
    void assignRoleErrorCheck(std::string name);
    void startGameErrorCheck();
    void checkForPlayerWithoutRole();
    void checkIfGameHasAlreadyStarted();
    void checkIfAlreadySwapped();
    void checkIfNightHasEnded();
    void checkForVotingInProgress();
    void swapCharacterErrorCheck(std::string name1, std::string name2);
    void swap(std::string a, std::string b);
    bool votingCompFunc(Person* a, Person* b);

};


#endif