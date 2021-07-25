#include "CSVParser.hpp"

CSVParser::CSVParser(std::string _fileAddress)
{
    fileAddress = _fileAddress;
    parse();
}

void CSVParser::parse()
{
    std::ifstream stream;
    stream.open(fileAddress);
    std::string word;
    while(getline(stream, word))
    {
        CSVLineParser lineParser(word);
        parsedInput.push_back(lineParser.getParsedInput());
    } 
    stream.close();
}

std::vector<InputLine> CSVParser::getParsedInput()
{
    return parsedInput;
}