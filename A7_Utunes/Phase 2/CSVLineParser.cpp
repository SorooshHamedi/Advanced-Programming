#include "CSVLineParser.hpp"

const char DELIMITER = ',';
CSVLineParser::CSVLineParser(std::string str)
{
    input = str;
    parse();
}

void CSVLineParser::parse()
{
    std::stringstream sstream(input);
    std::string word;

    while(getline(sstream, word, DELIMITER))
    {
        parsedInput.push_back(word);
    }
}

InputLine CSVLineParser::getParsedInput()
{
    return parsedInput;
}

