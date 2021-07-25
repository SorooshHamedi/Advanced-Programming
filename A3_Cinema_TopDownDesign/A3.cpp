#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

enum WeekDays
{
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

typedef int DayIndex;
typedef string DayName;
const int NUMBER_OF_DAYS = 7;
const DayName daysStr[] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

typedef string MovieName;
typedef string CinemaName;
typedef int TicketPrice;
typedef int HallIndex;

struct Time
{
    int hour;
    int minute;
};
const int MINUTES_IN_AN_HOUR = 60;

struct MovieShowTime
{
    Time start;
    Time end;
};

struct ScreeningInfo
{
    CinemaName cinemaName;
    MovieShowTime showTime;
    DayIndex weekDay;
    HallIndex hallIndex;
    TicketPrice ticketPrice; 
};

typedef vector<ScreeningInfo> MovieSchedule;
typedef vector<MovieSchedule> WeekSchedule;

struct Movie
{
    MovieName name;
    MovieSchedule schedule;
};

typedef vector<Movie> Movies; 

struct InputInformation
{
    CinemaName cinemaName;
    MovieName movieName;
    DayIndex weekDay;
    MovieShowTime showTime;
    TicketPrice ticketPrice;
    HallIndex hallIndex;
};

typedef vector<InputInformation> InputArray;
typedef vector<char> OutputRow;
typedef vector<OutputRow> OutputTable;

struct OutputBlock
{
    OutputRow firstRow;
    OutputRow secondRow;
    OutputRow thirdRow;
};

struct GetScheduleOutput
{
    OutputTable outputStandard;
    vector<string> htmlOutput;
};

const char CSV_DELIMITER = ',';
const char PARSED_DELIMITER = ' ';
const char TIME_DELIMITER = ':';
const char SPACE = ' ';

const int NUMBER_OF_COLUMNS = 7;
const string INPUTCOLUMNS[NUMBER_OF_COLUMNS] = {"CinemaName", "MovieName", "Day", "StartingTime", "FinishingTime", "Price", "Hall"};
const string CINEMA_NAME_STRING = "CinemaName";
const string MOVIE_NAME_STRING = "MovieName";
const string DAY_STRING = "Day";
const string STARTING_TIME_STRING = "StartingTime";
const string FINISHING_TIME_STRING = "FinishingTime";
const string PRICE_STRING = "Price";
const string HALL_STRING = "Hall";

const int NUMBER_OF_MOVIE_HOURS = 9;
const string MOVIE_HOURS[NUMBER_OF_MOVIE_HOURS] = {"08:00", "10:00", "12:00", "14:00", "16:00", "18:00", "20:00", "22:00", "00:00"};

enum InputColumns
{
    CINEMANAME,
    MOVIENAME,
    DAY,
    STARTINGTIME,
    FINISHINGTIME,
    PRICE,
    HALL
};

const int MOVIE_DOESNT_EXIST = -1;

const string GET_ALL_MOVIES_COMMAND = "GET ALL MOVIES";
const string GET_SCHEDULE_COMMAND = "GET SCHEDULE";

const int NUMBER_OF_WORDS_GET_SCHEDULE = 2;
const int NO_LIMIT_ON_WORDS = 0;


const int OUTPUT_NUMBER_OF_ROWS = (NUMBER_OF_DAYS+1)*2;
const int OUTPUT_COLUMNS_FOR_DAYS = 10;
const int NUMBER_OF_COLUMNS_EACH_HOUR = 20;
const int OUTPUT_NUMBER_OF_COLUMNS = OUTPUT_COLUMNS_FOR_DAYS + (NUMBER_OF_MOVIE_HOURS-1)*NUMBER_OF_COLUMNS_EACH_HOUR + 5;
const int NUMBER_OF_CHARS_EACH_DENOMINATOR = 5;
const Time FINAL_SHOWING_TIME_TWELVE_HOUR = {0,0};
const Time OUTPUT_TABLE_DENOMINATOR = {0,30};
const Time FINAL_SHOWING_TIME_TWENTY_FOUR_HOUR = {24,0};
const Time FIRST_SHOWING_TIME = {8,0};
const char PLUS_CHARACTER = '+';
const char MINUS_CHARACTER = '-';
const char VERTICAL_CHARACTER = '|';

const int HTML_PIXELS_LEFT_MARGIN = 100;
const int HTML_PIXELS_TOP_MARGIN = 60;
const int HTML_PIXELS_EACH_DENOMINATOR = 50;
const int HTML_NUMBER_OF_VERTICAL_LINES = 17;
const string HTML_SUFFIX = ".html";

vector<stringstream*> readSchedule( string scheduleAddress );
map<string,int> getInputOrder( stringstream& sstream);
InputInformation storeLineOfInput( stringstream& input, map<string,int> inputOrder );
InputArray storeInput( vector<stringstream*>& input, map<string,int> inputOrder);

vector<string> lineToArrayOfWords( stringstream& sstream, char delimiter = SPACE );
DayIndex getDayIndex ( DayName name );
Time convertStringToTime( string str );
MovieShowTime getShowTime ( string startingTime, string finishingTime);

Movies getMoviesFromInput( const InputArray& inputArray );
int findMovieIndex( MovieName name, const Movies& movies);
Movie createNewMovie( const InputInformation& info );
ScreeningInfo createNewScreeningInfo( const InputInformation& info );

void freeSstreamMemory( vector<stringstream*> vec );

void printAllMovies( const Movies& movies );
void print( string str);

int stringToInt( string str);

bool isGetScheduleCommand( string command );
string getMovieNameFromCommand( stringstream& sstream );
string getSentence( const vector<string>& arrayOfWords, char delimiter, int index = 0, int numberOfWords = NO_LIMIT_ON_WORDS);
bool isGetAllMoviesCommand( string command);

GetScheduleOutput getScheduleCommand( Movie movie );

bool scheduleSortCompFunc( ScreeningInfo a, ScreeningInfo b);
bool movieNameBasedSortCompFunc( Movie a, Movie b);

Movies sortMoviesByName( Movies movies );
MovieSchedule sortMovieSchedule( MovieSchedule schedule );

bool isSmallerTimeCompFunc( Time a, Time b);
bool areEqualTimeCompFunc( Time a, Time b);
bool isSmallerMovieShowTimeCompFunc( MovieShowTime a, MovieShowTime b );
bool areEqualMovieShowTimeCompFunc( MovieShowTime a, MovieShowTime b);
bool isSmallerCinemaNameCompFunc( CinemaName a, CinemaName b);
bool areEqualCinemaNameCompFunc( CinemaName a, CinemaName b);
bool isSmallerTicketPriceCompFunc( TicketPrice a, TicketPrice b);
bool noOverLapShowTime( MovieShowTime a, MovieShowTime b);
bool isSmallerDayIndexCompFunc(DayIndex a, DayIndex b);
bool areEqualDayIndexCompFunc(DayIndex a, DayIndex b);
bool areEqualTicketPriceCompFunc( TicketPrice a, TicketPrice b);

WeekSchedule getBestSchedule( const MovieSchedule& movieSchedule);
MovieSchedule getBestScheduleByDay( const MovieSchedule& movieSchedule, DayIndex day);

void printError(string str);
string timeToString(Time a);
void printWeekSchedule( const vector<MovieSchedule>& weekSchedule );
void printSchedule( const MovieSchedule& schedule);

OutputRow addWordToRow( OutputRow row, string word, int index);
OutputTable generateOutputTable( WeekSchedule weekSchedule);
OutputTable addWeekDaysToTable( OutputTable table );
OutputRow addMovieHoursToRow( OutputRow row );
int getDayRowIndexInTable( int dayIndex );
OutputBlock addDayScheduleToBlock( OutputBlock block, MovieSchedule daySchedule);
OutputBlock addScreeningToBlock( OutputBlock block, ScreeningInfo info );
string getBorderStringInTable( int size );
int getScreeningStartingIndexInTable( Time start );
int getDivisionForOutputTable( Time a );
int getNumOfCharactersForCellInTable( Time a);
Time getScreeningLength( MovieShowTime showTime );
Time getTimeDifference( Time a, Time b);

void printOutputTable( OutputTable table);
void printOutputRow( OutputRow row);

vector<string> generateHtmlOutput( WeekSchedule weekSchedule);
void storeStringVectorInFile( vector<string> vec, string fileAddress );
vector<string> addWeekDaysToHtml( vector<string> htmlOutput );
vector<string> addMovieHoursToHtml( vector<string> htmlOutput );
vector<string> addHtmlHeader( vector<string> htmlHeader );
vector<string> addVerticalLinesHtml( vector<string> htmlOutput );
int getTopMarginDayHtml( int day );
vector<string> addDayToHtml( vector<string> htmlOutput, MovieSchedule schedule, int topMargin );
string addScreeningToHtml( vector<string> htmlOutput, ScreeningInfo info, int topMargin);
int getBoxWidthHtml( Time a);
int getBoxLeftMarginHtml( Time a );
vector<string> addHtmlFooter( vector<string> htmlHeader );


int main(int argc, char* argv[])
{
    string scheduleAddress = argv[1];

    vector<stringstream*> schedule = readSchedule( scheduleAddress );
    map<string,int> inputOrder = getInputOrder( *(schedule.front()) );
    InputArray inputArray = storeInput( schedule, inputOrder );
    freeSstreamMemory( schedule );
    Movies movies = getMoviesFromInput( inputArray );

    string command;
    while( getline(cin, command))
    {
        stringstream sstream(command);
        vector<string> arrayOfWords = lineToArrayOfWords(sstream);

        if( isGetAllMoviesCommand(command) )
        {
            movies = sortMoviesByName(movies);
            printAllMovies(movies);
        }
        else
        { 
            string getScheduleCommandStr = getSentence(arrayOfWords, SPACE, 0, NUMBER_OF_WORDS_GET_SCHEDULE);

            if( !isGetScheduleCommand( getScheduleCommandStr )  )
            {
                continue;
            }

            MovieName movieName = getSentence( arrayOfWords, SPACE, NUMBER_OF_WORDS_GET_SCHEDULE );
            int movieIndex = findMovieIndex( movieName, movies);
            if( movieIndex == MOVIE_DOESNT_EXIST )
            {
                continue;
            }

            GetScheduleOutput output = getScheduleCommand( movies[movieIndex]);
            storeStringVectorInFile( output.htmlOutput, movies[movieIndex].name+HTML_SUFFIX);
            printOutputTable(output.outputStandard);
        }
        
    }   
    
}

Movies sortMoviesByName( Movies movies )
{
    sort( movies.begin(), movies.end(), movieNameBasedSortCompFunc );
    return movies;
}

MovieSchedule sortMovieSchedule( MovieSchedule schedule )
{
    sort( schedule.begin(), schedule.end(), scheduleSortCompFunc);
    return schedule;
}

GetScheduleOutput getScheduleCommand( Movie movie )
{
    movie.schedule = sortMovieSchedule(movie.schedule);
    GetScheduleOutput output;
    WeekSchedule bestSchedule = getBestSchedule( movie.schedule);
    output.outputStandard = generateOutputTable(bestSchedule);
    output.htmlOutput = generateHtmlOutput(bestSchedule);
    return output;

}
vector<stringstream*> readSchedule( string scheduleAddress )
{
    ifstream inputStream;

    inputStream.open(scheduleAddress);

    if( !inputStream.good() )
    {
        exit(0);
    }

    vector<stringstream*> schedule;
    string inputLine;

    while( getline(inputStream, inputLine) )
    {
        stringstream* sstream = new stringstream;
        (*sstream).str( inputLine );
        schedule.push_back(sstream);
    }

    inputStream.close();

    return schedule;
}

map<string,int> getInputOrder( stringstream& sstream)
{
    map<string,int> inputOrder;

    string str;

    vector<string> arrayOfWords = lineToArrayOfWords( sstream, CSV_DELIMITER );

    for(int i=0 ; i<NUMBER_OF_COLUMNS ; i++)
    {
        inputOrder[ arrayOfWords[i] ] = i;
    }

    return inputOrder;
}

InputInformation storeLineOfInput( stringstream& input, map<string,int> inputOrder )
{
    InputInformation inputInfo;
    vector<string> inputAsArray = lineToArrayOfWords( input, CSV_DELIMITER );

    inputInfo.cinemaName = inputAsArray[ inputOrder[CINEMA_NAME_STRING] ];
    inputInfo.movieName = inputAsArray[ inputOrder[ MOVIE_NAME_STRING] ];
    inputInfo.hallIndex = stringToInt( inputAsArray[ inputOrder[ HALL_STRING ] ] );
    inputInfo.weekDay = getDayIndex( inputAsArray[ inputOrder[ DAY_STRING ]]);
    inputInfo.ticketPrice = stringToInt( inputAsArray[ inputOrder[ PRICE_STRING ]]);
    inputInfo.showTime = getShowTime( inputAsArray[ inputOrder[STARTING_TIME_STRING ]], inputAsArray[ inputOrder[ FINISHING_TIME_STRING]] );

    return inputInfo;
}

vector<string> lineToArrayOfWords( stringstream& sstream, char delimiter)
{
    vector<string> arrayOfWords;

    string word;
    while( getline(sstream, word, delimiter) )
    {
        arrayOfWords.push_back(word);
    }

    return arrayOfWords;

}

DayIndex getDayIndex ( DayName name )
{
    for(int i=0; i<NUMBER_OF_DAYS ; i++)
    {
        if( name == daysStr[i] )
        {
            return i;
        }
    }
}

MovieShowTime getShowTime ( string startingTime, string finishingTime)
{
    MovieShowTime showTime;
    showTime.start = convertStringToTime( startingTime );
    showTime.end = convertStringToTime( finishingTime );

    return showTime;
}

Time convertStringToTime( string str )
{
    stringstream sstream(str);
    Time time;
    
    string hour , minute;
    getline(sstream, hour, TIME_DELIMITER);
    getline(sstream, minute, TIME_DELIMITER);

    time.hour = stringToInt(hour);
    time.minute = stringToInt(minute);

    return time;
}

InputArray storeInput( vector<stringstream*>& input, map<string,int> inputOrder)
{
    InputArray storedInput;

    for(int i=1 ; i<input.size() ; i++)
    {
        InputInformation inputLineInfo = storeLineOfInput( *(input[i]), inputOrder );
        storedInput.push_back(inputLineInfo);
    }

    return storedInput;
}

Movies getMoviesFromInput( const InputArray& inputArray )
{
    Movies movies;

    for(auto info: inputArray)
    {
        int movieIndex = findMovieIndex( info.movieName , movies );

        if( movieIndex == MOVIE_DOESNT_EXIST)
        {
            movies.push_back( createNewMovie( info ) );
        }
        else
        {
            movies[movieIndex].schedule.push_back( createNewScreeningInfo( info ) );
        }
        
    }

    return movies;
}

int findMovieIndex( MovieName name, const Movies& movies)
{
    for(int i=0; i<movies.size() ; i++)
    {
        if( movies[i].name == name )
        {
            return i;
        }
    }

    return MOVIE_DOESNT_EXIST;
}

Movie createNewMovie( const InputInformation& info )
{
    Movie movie;
    movie.name = info.movieName;
    movie.schedule.push_back( createNewScreeningInfo(info) );

    return movie;
}

ScreeningInfo createNewScreeningInfo( const InputInformation& info )
{
    ScreeningInfo screeningInfo;
    screeningInfo.cinemaName = info.cinemaName;
    screeningInfo.showTime = info.showTime;
    screeningInfo.weekDay = info.weekDay;
    screeningInfo.hallIndex = info.hallIndex;
    screeningInfo.ticketPrice = info.ticketPrice;

    return screeningInfo;
}

void freeSstreamMemory( vector<stringstream*> vec )
{
    for(int i=0 ; i<vec.size() ; i++)
    {
        delete vec[i];
    }
}

void printAllMovies( const Movies& movies )
{
    for(Movie mov: movies)
    {
        print(mov.name + "\n");
    }
}


int stringToInt( string str)
{
    return stoi( str, nullptr);
}


void print( string str)
{
    cout << str;
}

bool movieNameBasedSortCompFunc( Movie a, Movie b)
{
    return a.name < b.name;
}

bool isGetScheduleCommand( string command )
{
    return command == GET_SCHEDULE_COMMAND;
}

bool isGetAllMoviesCommand( string command)
{
    return command == GET_ALL_MOVIES_COMMAND;
}


string getSentence( const vector<string>& arrayOfWords, char delimiter, int index , int numberOfWords)
{
    string sentence;

    int sentenceSize;

    if( numberOfWords == NO_LIMIT_ON_WORDS)
    {
        sentenceSize = arrayOfWords.size();
    }
    else
    {
        sentenceSize = numberOfWords;
    }
    
    for(int i=index ; i<sentenceSize && i < arrayOfWords.size()  ; i++)
    {
        if( i > index)
        {
            sentence += delimiter;
        }
        sentence += arrayOfWords[i];
    }

    return sentence;
}

bool scheduleSortCompFunc( ScreeningInfo a, ScreeningInfo b)
{
    if( isSmallerDayIndexCompFunc( a.weekDay, b.weekDay) )
    {
        return true;
    }
    else if( areEqualDayIndexCompFunc( a.weekDay, b.weekDay) )
    {
        if( isSmallerMovieShowTimeCompFunc(a.showTime, b.showTime ) )
        {
            return true;
        }
        else if( areEqualMovieShowTimeCompFunc(a.showTime, b.showTime) )
        {
            return isSmallerTicketPriceCompFunc(a.ticketPrice, b.ticketPrice) || ( areEqualTicketPriceCompFunc(a.ticketPrice, b.ticketPrice) && isSmallerCinemaNameCompFunc(a.cinemaName, b.cinemaName) );
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    
    
}

bool isSmallerDayIndexCompFunc(DayIndex a, DayIndex b)
{
    return a < b;
}

bool areEqualDayIndexCompFunc(DayIndex a, DayIndex b)
{
    return a == b;
}
bool isSmallerTimeCompFunc( Time a, Time b)
{
    return (a.hour < b.hour) || ( (a.hour == b.hour) && (a.minute < b.minute) );
}

bool areEqualTimeCompFunc( Time a, Time b)
{
    return (a.hour == b.hour) && (a.minute == b.minute);
}

bool isSmallerMovieShowTimeCompFunc( MovieShowTime a, MovieShowTime b )
{
    return isSmallerTimeCompFunc(a.start, b.start) || ( areEqualTimeCompFunc(a.start, b.start) && isSmallerTimeCompFunc(a.start, b.start));
}

bool areEqualMovieShowTimeCompFunc( MovieShowTime a, MovieShowTime b)
{
    return areEqualTimeCompFunc(a.start, b.start) && areEqualTimeCompFunc(a.end, b.end);
}

bool isSmallerCinemaNameCompFunc( CinemaName a, CinemaName b)
{
    return a < b;
}

bool areEqualCinemaNameCompFunc( CinemaName a, CinemaName b)
{
    return a == b;
}

bool isSmallerTicketPriceCompFunc( TicketPrice a, TicketPrice b)
{
    return a < b;
}

bool areEqualTicketPriceCompFunc( TicketPrice a, TicketPrice b)
{
    return a == b;
}

WeekSchedule getBestSchedule( const MovieSchedule& movieSchedule)
{
    WeekSchedule fullBestSchedule(NUMBER_OF_DAYS);

    for(int i=SATURDAY; i<=FRIDAY ; i++)
    {
        fullBestSchedule[i] = getBestScheduleByDay( movieSchedule, i );
    }
    return fullBestSchedule;
}


MovieSchedule getBestScheduleByDay( const MovieSchedule& movieSchedule, DayIndex day)
{
    MovieSchedule bestSchedule;

    for(int i=0 ; i<movieSchedule.size() ; i++)
    {
        if(movieSchedule[i].weekDay == day)
        {
            if( bestSchedule.empty() )
            {
                bestSchedule.push_back(movieSchedule[i]);
            }
            else if(noOverLapShowTime( bestSchedule.back().showTime, movieSchedule[i].showTime) )
            {
                bestSchedule.push_back(movieSchedule[i]);
            }
        }
    }
    return bestSchedule;
}

bool noOverLapShowTime( MovieShowTime a, MovieShowTime b)
{
    return isSmallerTimeCompFunc(a.end, b.start) || areEqualTimeCompFunc(a.end, b.start);
}


void printWeekSchedule( const vector<MovieSchedule>& weekSchedule )
{
    for(int i=SATURDAY; i<=FRIDAY; i++)
    {
        printError( "Day: "+ daysStr[i]+"\n" );
        printSchedule(weekSchedule[i]);
        printError("\n");
    }
}

void printSchedule( const MovieSchedule& schedule)
{   
    for(int i=0; i<schedule.size() ; i++)
    {
        cerr << schedule[i].cinemaName << ",";
        cerr << timeToString( schedule[i].showTime.start ) << ",";
        cerr << timeToString( schedule[i].showTime.end) << "\n";
    }   
}

string timeToString(Time a)
{
    return to_string(a.hour) + ':' + to_string(a.minute);
}

void printError(string str)
{
    cerr << str;
}

OutputTable generateOutputTable( WeekSchedule weekSchedule )
{

    OutputTable outputTable( OUTPUT_NUMBER_OF_ROWS, OutputRow (OUTPUT_NUMBER_OF_COLUMNS, ' ') );

    outputTable = addWeekDaysToTable(outputTable);

    outputTable.front() = addMovieHoursToRow( outputTable.front() );

    for(int i=SATURDAY; i<=FRIDAY ; i++)
    {
        int index = getDayRowIndexInTable(i);

        OutputBlock block = {outputTable[index-1], outputTable[index], outputTable[index+1]};

        block = addDayScheduleToBlock( block , weekSchedule[i]);

        outputTable[index-1] = block.firstRow;
        outputTable[index] = block.secondRow;
        outputTable[index+1] = block.thirdRow;
    }

    return outputTable;
}

OutputRow addWordToRow(OutputRow row, string word, int index)
{
    for(int i=0; i<word.size() ; i++)
    {
        if( (row[i+index] == PLUS_CHARACTER) && (word[i] == MINUS_CHARACTER))
        {
            continue;
        }
        row[i+index] = word[i];
    }
    return row;
}

OutputTable addWeekDaysToTable( OutputTable table )
{
    for(int i=SATURDAY; i<=FRIDAY ; i++)
    {
        int index = getDayRowIndexInTable(i);
        table[index] = addWordToRow( table[index], daysStr[i], 0);
    }
    return table;
}

OutputRow addMovieHoursToRow( OutputRow row )
{
    for(int i=0 ; i<NUMBER_OF_MOVIE_HOURS; i++)
    {
        row = addWordToRow(row, MOVIE_HOURS[i], OUTPUT_COLUMNS_FOR_DAYS + (NUMBER_OF_COLUMNS_EACH_HOUR * i) );
    }
    return row;
}

void printOutputTable( OutputTable table)
{
    for(OutputRow row: table)
    {
        printOutputRow(row);
    }
}
void printOutputRow( OutputRow row)
{
    string rowStr;
    for(int i=0 ; i<row.size() ; i++)
    {
        rowStr += row[i];
    }
    print(rowStr+"\n");
}

int getDayRowIndexInTable( int dayIndex )
{
    return (dayIndex+1)*2;
}

OutputBlock addDayScheduleToBlock( OutputBlock block, MovieSchedule daySchedule)
{
    for(ScreeningInfo info: daySchedule)
    {
        block = addScreeningToBlock(block, info);
    }

    return block;
}

OutputBlock addScreeningToBlock( OutputBlock block, ScreeningInfo info )
{
    Time screeningLength = getScreeningLength( info.showTime );


    int startingIndex = getScreeningStartingIndexInTable( getTimeDifference( info.showTime.start, FIRST_SHOWING_TIME)  );
    int numberOfCharacters = getNumOfCharactersForCellInTable( screeningLength );

    string borderChars = getBorderStringInTable(numberOfCharacters);

    block.firstRow = addWordToRow( block.firstRow, borderChars, startingIndex);
    block.thirdRow = addWordToRow( block.thirdRow, borderChars, startingIndex);

    block.secondRow[startingIndex] = VERTICAL_CHARACTER;
    block.secondRow = addWordToRow( block.secondRow, info.cinemaName, startingIndex+1);
    block.secondRow[startingIndex + numberOfCharacters-1] = VERTICAL_CHARACTER;

    return block;
}

Time getScreeningLength( MovieShowTime showTime )
{
    Time answer = getTimeDifference( showTime.end, showTime.start);
    return answer;
}

Time getTimeDifference( Time a, Time b)
{
    Time answer;
    if( areEqualTimeCompFunc( a, FINAL_SHOWING_TIME_TWELVE_HOUR))
    {
        a = FINAL_SHOWING_TIME_TWENTY_FOUR_HOUR;
    }

    if( a.minute >= b.minute )
    {
        answer =  {a.hour-b.hour, a.minute-b.minute};
    }
    else
    {
        answer = {a.hour-b.hour-1, a.minute+MINUTES_IN_AN_HOUR-b.minute};
    }

    return answer;
}

int getScreeningStartingIndexInTable( Time start )
{
    return OUTPUT_COLUMNS_FOR_DAYS + ( getDivisionForOutputTable(start) * NUMBER_OF_CHARS_EACH_DENOMINATOR );
}

int getDivisionForOutputTable( Time a)
{
    int answer =  (a.minute + (a.hour*MINUTES_IN_AN_HOUR) ) / OUTPUT_TABLE_DENOMINATOR.minute;
    return answer;
}

int getNumOfCharactersForCellInTable( Time a)
{
    return ( getDivisionForOutputTable(a) * NUMBER_OF_CHARS_EACH_DENOMINATOR ) + 1;
}

string getBorderStringInTable( int size )
{
    string answer;

    for(int i=0 ; i<size; i++)
    {
        if(i==0 || i==size-1)
        {
            answer += PLUS_CHARACTER;
        }
        else
        {
            answer += MINUS_CHARACTER;
        }
        
    }

    return answer;
}

vector<string> generateHtmlOutput( WeekSchedule weekSchedule)
{
    vector<string> htmlOutput;
    htmlOutput = addHtmlHeader(htmlOutput);
    htmlOutput = addWeekDaysToHtml(htmlOutput);
    htmlOutput = addMovieHoursToHtml(htmlOutput);
    htmlOutput = addVerticalLinesHtml(htmlOutput);

    for(int i=SATURDAY; i<=FRIDAY; i++)
    {
        int topMargin = getTopMarginDayHtml(i);

        htmlOutput = addDayToHtml(htmlOutput, weekSchedule[i], topMargin);
    }

    htmlOutput = addHtmlFooter(htmlOutput);

    return htmlOutput;
}

void storeStringVectorInFile( vector<string> vec, string fileAddress )
{
    ofstream fileStream;
    fileStream.open(fileAddress);

    for(int i=0 ; i<vec.size() ; i++)
    {
        fileStream << vec[i] << "\n";
    }
    fileStream.close();

}

vector<string> addWeekDaysToHtml( vector<string> htmlOutput )
{
    int topMargin = HTML_PIXELS_TOP_MARGIN;
    for(int i=SATURDAY; i<=FRIDAY ; i++)
    {
        string outputLine;

        outputLine += "<div class=\"day-box\" style=\"top: ";
        outputLine += to_string(topMargin);
        outputLine += "px;\">";
        outputLine += daysStr[i];
        outputLine += "</div>";

        htmlOutput.push_back(outputLine);
        topMargin += HTML_PIXELS_EACH_DENOMINATOR;
    }

    return htmlOutput;
}

vector<string> addMovieHoursToHtml( vector<string> htmlOutput )
{  
    int leftMargin = HTML_PIXELS_LEFT_MARGIN;
    int diff = HTML_PIXELS_LEFT_MARGIN*2;
    for(int i=0; i<NUMBER_OF_MOVIE_HOURS ; i++)
    {
        string outputLine;
        outputLine += "<div class=\"time-box\" style=\"left: ";
        outputLine += to_string(leftMargin);
        outputLine += "px;\"><p>";
        outputLine += MOVIE_HOURS[i];
        outputLine += "</p></div>";

        htmlOutput.push_back(outputLine);
        leftMargin += diff;
    }
    return htmlOutput;
}

vector<string> addHtmlHeader( vector<string> htmlHeader )
{

    htmlHeader.push_back( "<html lang=\"en\">"); 
    htmlHeader.push_back( "<head>");
    htmlHeader.push_back( "<title></title>");
    htmlHeader.push_back( "<link rel=\"stylesheet\" href=\"./style.css\" />" );
    htmlHeader.push_back( "</head>");
    htmlHeader.push_back( "<body>" );

    return htmlHeader;
}

vector<string> addHtmlFooter( vector<string> htmlHeader )
{
    htmlHeader.push_back( "</body>" );
    htmlHeader.push_back( "</html>" );

    return htmlHeader;
}
vector<string> addVerticalLinesHtml( vector<string> htmlOutput )
{
    int leftMargin = HTML_PIXELS_LEFT_MARGIN;
    int diff = HTML_PIXELS_LEFT_MARGIN;

    for(int i=0 ; i<HTML_NUMBER_OF_VERTICAL_LINES; i++)
    {
        string outputLine;

        outputLine += "<div class=\"vertical-line\" style=\"left: ";
        outputLine += to_string(leftMargin);
        outputLine += "px;\"></div>";

        htmlOutput.push_back(outputLine);
        leftMargin += diff;
    }

    return htmlOutput;
}

int getTopMarginDayHtml( int day )
{
    return HTML_PIXELS_TOP_MARGIN + (day * HTML_PIXELS_EACH_DENOMINATOR);
}

vector<string> addDayToHtml( vector<string> htmlOutput, MovieSchedule schedule, int topMargin )
{
    for(ScreeningInfo info: schedule)
    {
        htmlOutput.push_back( addScreeningToHtml(htmlOutput, info, topMargin));
    }
    return htmlOutput;
}

string addScreeningToHtml( vector<string> htmlOutput, ScreeningInfo info, int topMargin)
{
    int boxWidth = getBoxWidthHtml( getScreeningLength(info.showTime));
    int leftMargin = getBoxLeftMarginHtml( getTimeDifference(info.showTime.start, FIRST_SHOWING_TIME) );
    string outputLine;

    outputLine += "<div class=\"record-box\" style=\"width: ";
    outputLine += to_string(boxWidth);
    outputLine += "px; left: ";
    outputLine += to_string(leftMargin);
    outputLine += "px; top:";
    outputLine += to_string(topMargin);
    outputLine += "px; \">";
    outputLine += info.cinemaName;
    outputLine += "</div>";

    return outputLine;
}

int getBoxWidthHtml( Time a)
{
    return HTML_PIXELS_EACH_DENOMINATOR *  getDivisionForOutputTable(a);
}

int getBoxLeftMarginHtml( Time a )
{
    return HTML_PIXELS_LEFT_MARGIN + (HTML_PIXELS_EACH_DENOMINATOR * getDivisionForOutputTable(a));
}
