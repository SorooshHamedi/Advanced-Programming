#include "Parser.hpp"

Parser::Parser(std::string str)
{
    input = str;
    parse();
}

void Parser::parse()
{
    std::stringstream sstream(input);
    std::string word;

    while(sstream >> word)
    {
        parsedInput.push_back(word);
    }
}

