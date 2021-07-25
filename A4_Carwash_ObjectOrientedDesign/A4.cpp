#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;


const string ADD_STAGE_COMMAND = "add_stage";
const string ADD_CAR_COMMAND = "add_car";
const string ADVANCE_TIME_COMMAND = "advance_time";
const string SHOW_STAGE_INFO_COMMAND = "show_stage_info";
const string SHOW_CARWASH_INFO_COMMAND = "show_carwash_info";
const string FINISH_COMMAND = "finish";

class Car{
public: 
    Car(int id_, int luxuryCoefficient_)
    {
        id = id_;
        luxuryCoefficient = luxuryCoefficient_;
    }
    string infoToString();
    int getLuxuryCoefficient() { return luxuryCoefficient; }
private:
    int id;
    int luxuryCoefficient;
};

string Car::infoToString()
{
    ostringstream os;
    os << "Car ID: " << id << "\nLuxury coefficient: " << luxuryCoefficient << "\n";
    return os.str();
}

class CarQueue{
public:
    CarQueue() {}
    void addCar(Car* car);
    void addCars(CarQueue cars);
    bool isEmpty() { return queue.empty(); }
    Car* getFront(){ return queue.front(); }
    int getSize(){ return queue.size(); }
    void removeFront();
    void removeCar(Car* car);
    void removeCars(CarQueue cars);
    void clearQueue();
    string infoToString();
private:
    list<Car*> queue;
};

void CarQueue::addCar(Car* car)
{
    queue.push_back(car);
}

void CarQueue::removeCar(Car* car)
{
    queue.remove(car);
}

void CarQueue::removeFront()
{
    queue.pop_front();
}

void CarQueue::addCars(CarQueue cars)
{
    while(!cars.isEmpty())
    {
        Car* car = cars.getFront();
        addCar(car);
        cars.removeFront();
    }
}

void CarQueue::removeCars(CarQueue cars)
{
    while(!cars.isEmpty())
    {
        Car* car = cars.getFront();
        removeCar(car);
        cars.removeFront();
    }
}

void CarQueue::clearQueue()
{
    queue.clear();
}

string CarQueue::infoToString()
{
    ostringstream os;
    for(auto const& car:queue)
    {
        os << car->infoToString();
    }
    return os.str();
}

class Worker{
public:
    Worker(int id_, int timeCoefficient_, Car* car_ = nullptr, int timeLeft_ = 0, bool isWorking_ = false)
    {
        id = id_;
        timeCoefficient = timeCoefficient_;
        car = car_;
        timeLeft = timeLeft_;
        isWorking = isWorking_;
    }
    string infoToString();
    void cleanCar();
    bool getIsWorking() { return isWorking; }
    Car* getCar(){ return car; }
    void removeCar(){ car = nullptr; }
    void updateStatus();
    void assignCar(Car* car);
private:
    int id;
    int timeCoefficient;
    Car* car;
    int timeLeft;
    bool isWorking;
};

void Worker::cleanCar()
{
    if(isWorking)
        timeLeft--;
}

void Worker::updateStatus()
{
    if(isWorking && timeLeft == 0)
    {
        isWorking = false;
    }
}

void Worker::assignCar(Car* newCar)
{
    car = newCar;
    isWorking = true;
    timeLeft = car->getLuxuryCoefficient() * timeCoefficient;
}

string Worker::infoToString()
{
    ostringstream os;
    os << "Worker ID: " << id << "\n";
    if(isWorking)
    {
        os << car->infoToString();
        os << "Time left: " << timeLeft; 
    }
    else
    {
        os << "Free";
    }
    
    return os.str(); 
}

class Stage{
public:
    Stage(int id_) { id = id_;  }
    int getID(){ return id; }
    string infoToString();
    void addWorkers(vector<int> workerInfo, int idStart);
    void cleanCars();
    CarQueue getFinishedCars();
    void removeFinishedCars();
    void removeFinishedCars(CarQueue finishedCars);
    void addNewCars(CarQueue newCars);
    void updateStageInfo();
    void assignCars();
private:
    void addWorker(Worker newWorker);
    int id;
    vector<Worker> workers;
    CarQueue waitingCars;
    CarQueue CarsBeingCleaned;
};

void Stage::addWorker(Worker worker)
{
    workers.push_back(worker); 
}

void Stage::addWorkers(vector<int> workerInfo, int idStart)
{
    for(int i=0; i<workerInfo.size() ; i++)
    {
        addWorker( Worker(idStart+i, workerInfo[i]) );
    }
}

void Stage::cleanCars()
{
    for(Worker& worker:workers)
    {
        worker.cleanCar();
    }
}

CarQueue Stage::getFinishedCars()
{
    CarQueue finishedCars;
    for(Worker& worker:workers)
    {
        if(!worker.getIsWorking() && worker.getCar() != nullptr)
        {
            finishedCars.addCar( worker.getCar() );
            worker.removeCar();
            break;
        }
    }
    return finishedCars;
}

void Stage::removeFinishedCars()
{
    CarQueue finishedCars = getFinishedCars();
    CarsBeingCleaned.removeCars(finishedCars);
}

void Stage::removeFinishedCars(CarQueue finishedCars)
{
    CarsBeingCleaned.removeCars(finishedCars);
}

void Stage::addNewCars(CarQueue newCars)
{
    waitingCars.addCars(newCars);
}

void Stage::updateStageInfo()
{
    for(Worker& worker:workers)
    {
        worker.updateStatus();
    }
}

void Stage::assignCars()
{
    if(waitingCars.isEmpty())
    {
        return;
    }
    Car* frontCar = waitingCars.getFront();
    for(Worker& worker:workers)
    {
        if(!worker.getIsWorking())
        {
            worker.assignCar(frontCar);
            waitingCars.removeFront();
            return;
        }
    }
}

string Stage::infoToString()
{
    ostringstream os;
    os << "Stage ID: " << id << "\n";
    for(Worker worker:workers)
    {
            os << worker.infoToString() << "\n";
    } 
    os << "Cars in waiting queue:\n";
    if(!waitingCars.isEmpty())
    {
          os << waitingCars.infoToString();
    }
    return os.str();
}
class CarWash{
public:
    CarWash() { idForNewCar = 0, timeElapsed = 0, idForNewWorker = 0; }
    string infoToString();
    void addStage(vector<int> workerInfo);
    void addCar(int luxuryCoefficient);
    void advanceTime(int time);
    void finish();
    string showStageInfo(int stageID);
    string showCarWashInfo();

private:
    void advanceTimeByOne();
    void cleanCars();
    void moveFinishedCarsInStages();
    void updateFinishedCars();
    void moveWaitingCars();
    void updateStagesInfo();
    void assignCars();
    void emptyCarWashProcedure();
    void updateIdForNewWorker(int cnt) { idForNewWorker += cnt; }
    CarQueue getWaitingCars();
    Stage findStageByID(int id);
    string stagesInfoToString();
    vector<Stage> stages;
    list<Car> allCars;
    CarQueue waitingCars;
    CarQueue finishedCars;
    int idForNewCar;
    int timeElapsed;
    int idForNewWorker;
};

void CarWash::addStage(vector<int> workerInfo)
{
    Stage newStage(stages.size());
    newStage.addWorkers(workerInfo, idForNewWorker);
    updateIdForNewWorker(workerInfo.size());
    stages.push_back(newStage);
}

void CarWash::addCar(int luxuryCoefficient)
{
    Car newCar = Car(idForNewCar, luxuryCoefficient);
    allCars.push_back(newCar);
    waitingCars.addCar(&(allCars.back()));
    idForNewCar++;
}

void CarWash::advanceTimeByOne() 
{
    if(stages.empty())
    {
        emptyCarWashProcedure();
        return;
    }
    updateStagesInfo();
    cleanCars();
    moveFinishedCarsInStages();
    moveWaitingCars();
    assignCars();
    timeElapsed++;
}

void CarWash::cleanCars()
{
    for(Stage& stage:stages)
    {
        stage.cleanCars();
    }
}

void CarWash::moveFinishedCarsInStages()
{
    for(int i=0; i<stages.size()-1 ; i++)
    {
        CarQueue finishedCars = stages[i].getFinishedCars();
        stages[i+1].addNewCars(finishedCars);
        stages[i].removeFinishedCars(finishedCars);
    }   
    updateFinishedCars();
}

void CarWash::updateFinishedCars()
{
    CarQueue newFinishedCars = stages[stages.size()-1].getFinishedCars();
    finishedCars.addCars(newFinishedCars);
    stages[stages.size()-1].removeFinishedCars(newFinishedCars);
}

void CarWash::moveWaitingCars()
{
    CarQueue departingWaitingCars = getWaitingCars();
    stages.front().addNewCars(departingWaitingCars);
    waitingCars.removeCars(departingWaitingCars);
}

CarQueue CarWash::getWaitingCars()
{
    CarQueue answer;
    if( !waitingCars.isEmpty())
        answer.addCar(waitingCars.getFront());
    return answer;
}

void CarWash::updateStagesInfo()
{
    for(Stage& stage:stages)
    {
        stage.updateStageInfo();
    }
}

void CarWash::assignCars()
{
    for(Stage& stage:stages)
    {
        stage.assignCars();
    }
}

void CarWash::advanceTime(int time)
{
    while(time--)
        advanceTimeByOne();
}

void CarWash::finish()
{
    while(finishedCars.getSize() != allCars.size())
    {
        advanceTimeByOne();
    }
}

string CarWash::stagesInfoToString()
{
    ostringstream os;
    for(Stage stage:stages)
    {
        os << stage.infoToString();
    }
    return os.str();
}

string CarWash::infoToString()
{
    ostringstream os;
    os << "Passed time: " << timeElapsed << "\n";
    os << "Cars waiting:\n";
    if(!waitingCars.isEmpty())
        os << waitingCars.infoToString();
    os << "Stages info:\n";
    os << stagesInfoToString();
    os << "Cars finished:\n";
    if(!finishedCars.isEmpty())
         os << finishedCars.infoToString();
    return os.str();
}

void CarWash::emptyCarWashProcedure()
{
    finishedCars.addCars(waitingCars);
    waitingCars.clearQueue();
}

string CarWash::showStageInfo(int stageID)
{
    Stage stage = findStageByID(stageID);
    return stage.infoToString();
}

string CarWash::showCarWashInfo()
{
    return infoToString();
}

Stage CarWash::findStageByID(int id)
{
    for(Stage stage:stages)
    {
        if(stage.getID() == id)
        {
            return stage;
        }
    }
}
vector<int> getWorkerInfo(const vector<string>& inputLine);
int getLuxuryCoefficient(const vector<string>& inputLine);
string getCommand(const vector<string>& inputLine);
vector<string> lineToArrayOfWords(string inputLine);
int getTime(const vector<string>& inputLine);
void printSuccessMessage();
void print(string str);
int getStageID(const vector<string>& inputLine);

int main()
{
    CarWash carWash;

    string inputLine;
    while(getline(cin, inputLine))
    {
        vector<string> arrayOfWords = lineToArrayOfWords(inputLine);
        string command = getCommand(arrayOfWords);
        if(command == ADD_STAGE_COMMAND)
        {
            vector<int> workerInfo = getWorkerInfo(arrayOfWords);
            carWash.addStage(workerInfo);
            printSuccessMessage();
        }
        else if(command == ADD_CAR_COMMAND)
        {
            int luxuryCoefficient = getLuxuryCoefficient(arrayOfWords);
            carWash.addCar(luxuryCoefficient);
            printSuccessMessage();
        }
        else if(command == ADVANCE_TIME_COMMAND)
        {
            int time = getTime(arrayOfWords);
            carWash.advanceTime(time);
            printSuccessMessage();
        }
        else if(command == SHOW_STAGE_INFO_COMMAND)
        {
            int stageID = getStageID(arrayOfWords);
            print( carWash.showStageInfo(stageID));
        }
        else if(command == SHOW_CARWASH_INFO_COMMAND)
        {
            print( carWash.showCarWashInfo());
        }
        else if(command == FINISH_COMMAND)
        {
            carWash.finish();
            printSuccessMessage();
        }
    }

    return 0;
}

vector<int> getWorkerInfo(const vector<string>& arrayOfWords)
{
    int numberOfWorkers = stoi(arrayOfWords[1]);
    vector<int> workerInfo(numberOfWorkers);
    for(int i=0; i<numberOfWorkers; i++)
    {
        workerInfo[i] =  stoi(arrayOfWords[i+2]) ;
    }
    return workerInfo;
}

int getLuxuryCoefficient(const vector<string>& arrayOfWords)
{
    int luxuryCoefficient = stoi(arrayOfWords[1]);
    return luxuryCoefficient;
}

string getCommand(const vector<string>& arrayOfWords)
{
    return arrayOfWords[0];
}

vector<string> lineToArrayOfWords(string inputLine)
{
    stringstream sstream(inputLine);
    vector<string> arrayOfWords;
    string word;
    while(sstream >> word)
    {
        arrayOfWords.push_back(word);
    }
    return arrayOfWords;
}

int getTime(const vector<string>& arrayOfWords)
{
    return stoi(arrayOfWords[1]);
}

void printSuccessMessage()
{
    print("OK\n");
}

void print(string str)
{
    cout << str;
}

int getStageID(const vector<string>& inputLine)
{
    return stoi(inputLine[1]);
}
