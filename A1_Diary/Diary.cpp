#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

enum INDIC{
    ZERO,
    ONE
};

enum BOOL{
    FALSE,
    TRUE
};

enum COMMAND_TYPE{
    START_DAY,
    SHOW_DAY,
    SHOW_LONGEST_DAY,
    SHOW_BEST_DAY,
    NON_COMMAND
};

enum DATE_COMP{
    LATER,
    EARLIER
};
typedef struct date{
    int day;
    int month;
    int year;
} Date;

typedef struct dayInformation{
    Date date;
    string notes;
    int numberOfPositiveWords;
    int diaryIndex;
} DayInfo;

typedef vector<DayInfo> Diary;

#define DATE_DIVIDER '/'
#define END_LINE '\n'
#define SHOW_DAY_COMMAND "show_day"
#define START_DAY_COMMAND "start_day"
#define SHOW_LONGEST_DAY_COMMAND "show_the_longest_day"
#define SHOW_BEST_DAY_COMMAND "show_the_best_day"

#define POSITIVE_WORDS_ADDRESS "positive-words.txt"

#define SHORT_PRINT_SIZE 20
#define SHORT_PRINT_END "..."

int getCommandType( string command);
string getStringFromSstream(stringstream& sStream);
Date getDateFromInput( stringstream& sStream);
Date convertStringToDate( string str);
stringstream parseString( string str, char divider);

void addNewDayToDiary( stringstream& sStream, Diary& diary, int index);
void addNotesToLastDay( string input, Diary& diary, vector<string> positiveWords);

void showDay( stringstream& sStream, Diary& diary);
DayInfo findDayByDate( Diary& diary, Date date);
bool datesAreEqual( Date a, Date b);

void printNotesFull( string str );
void printNotesShortened( string str);
void printDate( Date date);

int countNumberOfPositiveWords( DayInfo day, vector<string>& positiveWords);
bool isAPositiveWord( string str, vector<string>& positiveWords);

bool noteSizeCompFunc( DayInfo a, DayInfo b);
bool numberOfPositiveWordsCompFunc( DayInfo a, DayInfo b);

void showLongestDay( Diary diary);
void showBestDay( Diary diary);

vector<string> readPositiveWordsFile();

int main()
{
    string inputLine;
    int currentCommand;
    int lastCommand = NON_COMMAND;
    string command;
    
    int numberOfDaysAdded = ZERO;
    vector<string> positiveWords = readPositiveWordsFile();

    Diary diary;
    while(getline(cin, inputLine))
    {
        stringstream inputStringStream(inputLine);
        command = getStringFromSstream(inputStringStream);

        currentCommand = getCommandType(command);

        if( currentCommand == START_DAY )
        {
            addNewDayToDiary(inputStringStream, diary, ++numberOfDaysAdded);
        }
        else if( currentCommand == NON_COMMAND)
        {
            addNotesToLastDay(inputLine, diary, positiveWords);
        }
        else if( currentCommand == SHOW_DAY)
        {
            showDay(inputStringStream, diary);
        }
        else if( currentCommand == SHOW_LONGEST_DAY)
        {
            showLongestDay(diary);
        }
        else if( currentCommand == SHOW_BEST_DAY)
        {
            showBestDay(diary);
        }
        
    }
}

int getCommandType( string command)
{
    if( command == START_DAY_COMMAND)
    {
        return START_DAY;
    }
    else if( command == SHOW_DAY_COMMAND)
    {
        return SHOW_DAY;
    }
    else if( command == SHOW_LONGEST_DAY_COMMAND)
    {
        return SHOW_LONGEST_DAY;
    }
    else if( command == SHOW_BEST_DAY_COMMAND)
    {
        return SHOW_BEST_DAY;
    }
    else
    {
        return NON_COMMAND;
    }
}

string getStringFromSstream(stringstream& sStream)
{
    string str;
    sStream >> str;
    return str;
}

Date getDateFromInput( stringstream& sStream)
{
    Date newDate;

    string input = getStringFromSstream(sStream);

    newDate = convertStringToDate(input);

    return newDate;
}

Date convertStringToDate( string str)
{
    stringstream sStream = parseString( str, DATE_DIVIDER);

    Date date;

    
    sStream >> date.day >> date.month >> date.year;

    return date;
}

stringstream parseString( string str, char divider)
{
    stringstream inputStream(str);
    stringstream parsedStream;
    string segment;
    
    while(getline(inputStream, segment, divider))
    {
        parsedStream << segment << ' ';
    }

    return parsedStream;

}

void addNewDayToDiary( stringstream& sStream, Diary& diary, int index)
{
    DayInfo newDay;
    newDay.date = getDateFromInput(sStream);
    newDay.diaryIndex = index;
    diary.push_back(newDay);
    
    return;
}

void addNotesToLastDay( string input, Diary& diary, vector<string> positiveWords)
{

    if( diary.back().notes.size() != ZERO )
    {
        diary.back().notes += END_LINE;
    }

    diary.back().notes += input;
    diary.back().numberOfPositiveWords = countNumberOfPositiveWords(diary.back(), positiveWords);
    return;
}

void showDay( stringstream& sStream, Diary& diary)
{
    Date date = getDateFromInput(sStream);
    DayInfo day = findDayByDate(diary , date);

    printNotesFull( day.notes );

    return;
}

DayInfo findDayByDate( Diary& diary, Date date)
{
    DayInfo answer;
    for(int i=ZERO ; i<diary.size() ; i++)
    {
        if( datesAreEqual( date, diary[i].date) )
        {
            return diary[i];
        }
    }
}

bool datesAreEqual( Date a, Date b)
{
    if( ( a.day == b.day ) && (a.month == b.month) && (a.year == b.year) )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void printNotesFull( string str )
{
    cout << str << "\n";
    return;
}

void printNotesShortened( string str)
{
    string output;
    if( str.size() < SHORT_PRINT_SIZE)
    {
        output = str;
    }
    else
    {
        output = str.substr(ZERO, SHORT_PRINT_SIZE);
        output += SHORT_PRINT_END; 
    }

    cout << output << "\n";

    return;
}

void printDate( Date date)
{
    cout << date.day << DATE_DIVIDER << date.month << DATE_DIVIDER << date.year << "\n";
}

int countNumberOfPositiveWords( DayInfo day, vector<string>& positiveWords)
{
    stringstream sStream(day.notes);
    int answer = ZERO;

    string str;

    while(sStream >> str)
    {
        if( isAPositiveWord(str, positiveWords) )
        {
            answer++;
        }
    }

    return answer;
}

bool isAPositiveWord( string str, vector<string>& positiveWords)
{

    for(auto u:positiveWords)
    {
        if(u == str)
        {
            return TRUE;
        }
    }
    return FALSE;
}

vector<string> readPositiveWordsFile()
{
    ifstream input;
    input.open(POSITIVE_WORDS_ADDRESS);

    string positiveWord;
    vector<string> vec;

    while(input >> positiveWord)
    {
        vec.push_back(positiveWord);
    }
    input.close();

    return vec;
}

bool noteSizeCompFunc( DayInfo a, DayInfo b)
{
    if( a.notes.size() == b.notes.size() )
    {
        return a.diaryIndex > b.diaryIndex;
    }
    else
    {
        return a.notes.size() < b.notes.size();
    }    
}

bool numberOfPositiveWordsCompFunc( DayInfo a, DayInfo b)
{
    if( a.numberOfPositiveWords == b.numberOfPositiveWords )
    {
        return a.diaryIndex > b.diaryIndex;
    }
    else
    {
        return a.numberOfPositiveWords < b.numberOfPositiveWords;
    }
}


void showLongestDay( Diary diary)
{
    sort(diary.begin(), diary.end(), noteSizeCompFunc);
    printDate(diary.back().date);
    printNotesShortened( diary.back().notes );
    return;
}

void showBestDay( Diary diary)
{
    sort(diary.begin(), diary.end(), numberOfPositiveWordsCompFunc);

    printDate(diary.back().date);
    printNotesShortened( diary.back().notes);
}
