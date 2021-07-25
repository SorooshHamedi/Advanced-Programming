#include "CommandParser.hpp"

CommandParser::CommandParser(std::string str)
{
    input = str;
    parse();
}

void CommandParser::parse()
{
    std::stringstream sstream(input);
    std::string word;

    while(sstream >> word)
    {
        parsedInput.push_back(word);
    }
}

InputLine CommandParser::getParsedInput()
{
    return parsedInput;
}
