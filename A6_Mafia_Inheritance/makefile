CC := g++ -std=c++11 -g
BUILD_DIR = build
EXCEPTION_DIR = ExceptionClass

.PHONY: all
all: makedir mafia.out

mafia.out: $(BUILD_DIR)/main.o $(BUILD_DIR)/MafiaGod.o $(BUILD_DIR)/Joker.o $(BUILD_DIR)/Citizen.o $(BUILD_DIR)/Mafia.o $(BUILD_DIR)/Person.o $(BUILD_DIR)/Parser.o $(BUILD_DIR)/Villager.o $(BUILD_DIR)/Detective.o $(BUILD_DIR)/Doctor.o $(BUILD_DIR)/GodFather.o $(BUILD_DIR)/BulletProof.o $(BUILD_DIR)/Silencer.o $(BUILD_DIR)/MafiaMember.o $(BUILD_DIR)/NoGameCreated.o $(BUILD_DIR)/UserNotJoined.o $(BUILD_DIR)/PlayerWithoutRole.o $(BUILD_DIR)/GameAlreadyStarted.o $(BUILD_DIR)/SilencedVoter.o $(BUILD_DIR)/DeadVotee.o $(BUILD_DIR)/UserNightWakeUp.o $(BUILD_DIR)/DeadUser.o $(BUILD_DIR)/DetectiveAlreadyAsked.o $(BUILD_DIR)/DeadSuspect.o $(BUILD_DIR)/DeadPatient.o $(BUILD_DIR)/DeadPerson.o $(BUILD_DIR)/CharactersAlreadySwapped.o $(BUILD_DIR)/SwapBeforeEndOfNight.o $(BUILD_DIR)/VotingInProgress.o $(BUILD_DIR)/DoctorAlreadyHealed.o
	$(CC)  $(BUILD_DIR)/main.o $(BUILD_DIR)/MafiaGod.o $(BUILD_DIR)/Joker.o $(BUILD_DIR)/Citizen.o $(BUILD_DIR)/Mafia.o $(BUILD_DIR)/Person.o $(BUILD_DIR)/Parser.o $(BUILD_DIR)/Villager.o $(BUILD_DIR)/Detective.o $(BUILD_DIR)/Doctor.o $(BUILD_DIR)/GodFather.o $(BUILD_DIR)/BulletProof.o $(BUILD_DIR)/Silencer.o $(BUILD_DIR)/MafiaMember.o $(BUILD_DIR)/NoGameCreated.o $(BUILD_DIR)/UserNotJoined.o $(BUILD_DIR)/PlayerWithoutRole.o $(BUILD_DIR)/GameAlreadyStarted.o $(BUILD_DIR)/SilencedVoter.o $(BUILD_DIR)/DeadVotee.o $(BUILD_DIR)/UserNightWakeUp.o $(BUILD_DIR)/DeadUser.o $(BUILD_DIR)/DetectiveAlreadyAsked.o $(BUILD_DIR)/DeadSuspect.o $(BUILD_DIR)/DeadPatient.o $(BUILD_DIR)/DeadPerson.o $(BUILD_DIR)/CharactersAlreadySwapped.o $(BUILD_DIR)/SwapBeforeEndOfNight.o $(BUILD_DIR)/VotingInProgress.o $(BUILD_DIR)/DoctorAlreadyHealed.o -o mafia.out

$(BUILD_DIR)/main.o: main.cpp MafiaGod.hpp Joker.hpp Citizen.hpp Mafia.hpp Person.hpp Parser.hpp Villager.hpp Detective.hpp Doctor.hpp GodFather.hpp BulletProof.hpp Silencer.hpp MafiaMember.hpp $(EXCEPTION_DIR)/NoGameCreated.hpp $(EXCEPTION_DIR)/UserNotJoined.hpp $(EXCEPTION_DIR)/PlayerWithoutRole.hpp $(EXCEPTION_DIR)/GameAlreadyStarted.hpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/UserNightWakeUp.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DetectiveAlreadyAsked.hpp $(EXCEPTION_DIR)/DeadSuspect.hpp $(EXCEPTION_DIR)/DoctorAlreadyHealed.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadPerson.hpp $(EXCEPTION_DIR)/CharactersAlreadySwapped.hpp $(EXCEPTION_DIR)/SwapBeforeEndOfNight.hpp $(EXCEPTION_DIR)/VotingInProgress.hpp $(EXCEPTION_DIR)/DetectiveAlreadyAsked.hpp
	$(CC) -c main.cpp -o $(BUILD_DIR)/main.o 

$(BUILD_DIR)/MafiaGod.o: MafiaGod.cpp MafiaGod.hpp Joker.hpp Citizen.hpp Mafia.hpp Person.hpp Parser.hpp Villager.hpp Detective.hpp Doctor.hpp GodFather.hpp BulletProof.hpp Silencer.hpp MafiaMember.hpp $(EXCEPTION_DIR)/NoGameCreated.hpp $(EXCEPTION_DIR)/UserNotJoined.hpp $(EXCEPTION_DIR)/PlayerWithoutRole.hpp $(EXCEPTION_DIR)/GameAlreadyStarted.hpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/UserNightWakeUp.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DetectiveAlreadyAsked.hpp $(EXCEPTION_DIR)/DeadSuspect.hpp $(EXCEPTION_DIR)/DoctorAlreadyHealed.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadPerson.hpp $(EXCEPTION_DIR)/CharactersAlreadySwapped.hpp $(EXCEPTION_DIR)/SwapBeforeEndOfNight.hpp $(EXCEPTION_DIR)/VotingInProgress.hpp $(EXCEPTION_DIR)/DetectiveAlreadyAsked.hpp
	$(CC) -c MafiaGod.cpp -o $(BUILD_DIR)/MafiaGod.o

$(BUILD_DIR)/Joker.o: Joker.hpp Joker.cpp Person.hpp $(EXCEPTION_DIR)/UserNightWakeUp.hpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadSuspect.hpp $(EXCEPTION_DIR)/DeadPerson.hpp
	$(CC) -c Joker.cpp -o $(BUILD_DIR)/Joker.o

$(BUILD_DIR)/Citizen.o: Citizen.hpp Citizen.cpp Person.hpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadSuspect.hpp $(EXCEPTION_DIR)/DeadPerson.hpp
	$(CC) -c Citizen.cpp -o $(BUILD_DIR)/Citizen.o

$(BUILD_DIR)/Mafia.o: Mafia.hpp Mafia.cpp Person.hpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadSuspect.hpp $(EXCEPTION_DIR)/DeadPerson.hpp
	$(CC) -c Mafia.cpp -o $(BUILD_DIR)/Mafia.o

$(BUILD_DIR)/Person.o: Person.hpp Person.cpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadSuspect.hpp $(EXCEPTION_DIR)/DeadPerson.hpp
	$(CC) -c Person.cpp -o $(BUILD_DIR)/Person.o

$(BUILD_DIR)/Parser.o: Parser.hpp Parser.cpp
	$(CC) -c Parser.cpp -o $(BUILD_DIR)/Parser.o

$(BUILD_DIR)/Villager.o: Villager.cpp Villager.hpp Person.hpp Citizen.hpp $(EXCEPTION_DIR)/UserNightWakeUp.hpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadSuspect.hpp $(EXCEPTION_DIR)/DeadPerson.hpp
	$(CC) -c Villager.cpp -o $(BUILD_DIR)/Villager.o

$(BUILD_DIR)/Detective.o: Detective.cpp Detective.hpp Person.hpp Citizen.hpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DetectiveAlreadyAsked.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadSuspect.hpp $(EXCEPTION_DIR)/DeadPerson.hpp
	$(CC) -c Detective.cpp -o $(BUILD_DIR)/Detective.o

$(BUILD_DIR)/Doctor.o: Doctor.cpp Doctor.hpp Person.hpp Citizen.hpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DoctorAlreadyHealed.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadSuspect.hpp $(EXCEPTION_DIR)/DeadPerson.hpp
	$(CC) -c Doctor.cpp -o $(BUILD_DIR)/Doctor.o

$(BUILD_DIR)/GodFather.o: GodFather.cpp GodFather.hpp Person.hpp Mafia.hpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadPerson.hpp
	$(CC) -c GodFather.cpp -o $(BUILD_DIR)/GodFather.o

$(BUILD_DIR)/BulletProof.o: BulletProof.cpp BulletProof.hpp Person.hpp Citizen.hpp $(EXCEPTION_DIR)/UserNightWakeUp.hpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadSuspect.hpp $(EXCEPTION_DIR)/DeadPerson.hpp
	$(CC) -c BulletProof.cpp -o $(BUILD_DIR)/BulletProof.o

$(BUILD_DIR)/Silencer.o: Silencer.cpp Silencer.hpp Person.hpp Mafia.hpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadSuspect.hpp $(EXCEPTION_DIR)/DeadPerson.hpp
	$(CC) -c Silencer.cpp -o $(BUILD_DIR)/Silencer.o

$(BUILD_DIR)/MafiaMember.o: MafiaMember.cpp MafiaMember.hpp Person.hpp Mafia.hpp $(EXCEPTION_DIR)/DeadVotee.hpp $(EXCEPTION_DIR)/SilencedVoter.hpp $(EXCEPTION_DIR)/DeadUser.hpp $(EXCEPTION_DIR)/DeadPatient.hpp $(EXCEPTION_DIR)/DeadSuspect.hpp $(EXCEPTION_DIR)/DeadPerson.hpp
	$(CC) -c MafiaMember.cpp -o $(BUILD_DIR)/MafiaMember.o

$(BUILD_DIR)/NoGameCreated.o: $(EXCEPTION_DIR)/NoGameCreated.cpp $(EXCEPTION_DIR)/NoGameCreated.hpp
	$(CC) -c $(EXCEPTION_DIR)/NoGameCreated.cpp -o $(BUILD_DIR)/NoGameCreated.o

$(BUILD_DIR)/UserNotJoined.o: $(EXCEPTION_DIR)/UserNotJoined.cpp $(EXCEPTION_DIR)/UserNotJoined.hpp
	$(CC) -c $(EXCEPTION_DIR)/UserNotJoined.cpp -o $(BUILD_DIR)/UserNotJoined.o

$(BUILD_DIR)/PlayerWithoutRole.o: $(EXCEPTION_DIR)/PlayerWithoutRole.cpp $(EXCEPTION_DIR)/PlayerWithoutRole.hpp
	$(CC) -c $(EXCEPTION_DIR)/PlayerWithoutRole.cpp -o $(BUILD_DIR)/PlayerWithoutRole.o

$(BUILD_DIR)/GameAlreadyStarted.o: $(EXCEPTION_DIR)/GameAlreadyStarted.cpp $(EXCEPTION_DIR)/GameAlreadyStarted.hpp
	$(CC) -c $(EXCEPTION_DIR)/GameAlreadyStarted.cpp -o $(BUILD_DIR)/GameAlreadyStarted.o

$(BUILD_DIR)/SilencedVoter.o: $(EXCEPTION_DIR)/SilencedVoter.cpp $(EXCEPTION_DIR)/SilencedVoter.hpp
	$(CC) -c $(EXCEPTION_DIR)/SilencedVoter.cpp -o $(BUILD_DIR)/SilencedVoter.o

$(BUILD_DIR)/DeadVotee.o: $(EXCEPTION_DIR)/DeadVotee.cpp $(EXCEPTION_DIR)/DeadVotee.hpp
	$(CC) -c $(EXCEPTION_DIR)/DeadVotee.cpp -o $(BUILD_DIR)/DeadVotee.o

$(BUILD_DIR)/UserNightWakeUp.o: $(EXCEPTION_DIR)/UserNightWakeUp.cpp $(EXCEPTION_DIR)/UserNightWakeUp.hpp
	$(CC) -c $(EXCEPTION_DIR)/UserNightWakeUp.cpp -o $(BUILD_DIR)/UserNightWakeUp.o

$(BUILD_DIR)/DeadUser.o: $(EXCEPTION_DIR)/DeadUser.cpp $(EXCEPTION_DIR)/DeadUser.hpp
	$(CC) -c $(EXCEPTION_DIR)/DeadUser.cpp -o $(BUILD_DIR)/DeadUser.o

$(BUILD_DIR)/DetectiveAlreadyAsked.o: $(EXCEPTION_DIR)/DetectiveAlreadyAsked.cpp $(EXCEPTION_DIR)/DetectiveAlreadyAsked.hpp
	$(CC) -c $(EXCEPTION_DIR)/DetectiveAlreadyAsked.cpp -o $(BUILD_DIR)/DetectiveAlreadyAsked.o

$(BUILD_DIR)/DeadSuspect.o: $(EXCEPTION_DIR)/DeadSuspect.cpp $(EXCEPTION_DIR)/DeadSuspect.hpp
	$(CC) -c $(EXCEPTION_DIR)/DeadSuspect.cpp -o $(BUILD_DIR)/DeadSuspect.o

$(BUILD_DIR)/DoctorAlreadyHealed.o: $(EXCEPTION_DIR)/DoctorAlreadyHealed.cpp $(EXCEPTION_DIR)/DoctorAlreadyHealed.hpp
	$(CC) -c $(EXCEPTION_DIR)/DoctorAlreadyHealed.cpp -o $(BUILD_DIR)/DoctorAlreadyHealed.o

$(BUILD_DIR)/DeadPatient.o: $(EXCEPTION_DIR)/DeadPatient.cpp $(EXCEPTION_DIR)/DeadPatient.hpp
	$(CC) -c $(EXCEPTION_DIR)/DeadPatient.cpp -o $(BUILD_DIR)/DeadPatient.o

$(BUILD_DIR)/DeadPerson.o: $(EXCEPTION_DIR)/DeadPerson.cpp $(EXCEPTION_DIR)/DeadPerson.hpp
	$(CC) -c $(EXCEPTION_DIR)/DeadPerson.cpp -o $(BUILD_DIR)/DeadPerson.o

$(BUILD_DIR)/CharactersAlreadySwapped.o: $(EXCEPTION_DIR)/CharactersAlreadySwapped.cpp $(EXCEPTION_DIR)/CharactersAlreadySwapped.hpp
	$(CC) -c $(EXCEPTION_DIR)/CharactersAlreadySwapped.cpp -o $(BUILD_DIR)/CharactersAlreadySwapped.o

$(BUILD_DIR)/SwapBeforeEndOfNight.o: $(EXCEPTION_DIR)/SwapBeforeEndOfNight.cpp $(EXCEPTION_DIR)/SwapBeforeEndOfNight.hpp
	$(CC) -c $(EXCEPTION_DIR)/SwapBeforeEndOfNight.cpp -o $(BUILD_DIR)/SwapBeforeEndOfNight.o

$(BUILD_DIR)/VotingInProgress.o: $(EXCEPTION_DIR)/VotingInProgress.cpp $(EXCEPTION_DIR)/VotingInProgress.hpp
	$(CC) -c $(EXCEPTION_DIR)/VotingInProgress.cpp -o $(BUILD_DIR)/VotingInProgress.o

makedir:
	mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
