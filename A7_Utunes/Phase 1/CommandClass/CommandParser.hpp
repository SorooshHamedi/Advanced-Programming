#ifndef _PARSER_HPP_
#define _PARSER_HPP_ 1

#include <sstream>
#include <string>
#include <vector>

#include "../InputLine.hpp"

class CommandParser
{
public:
    CommandParser(std::string str);
    InputLine getParsedInput();
private:
    std::string input;
    void parse();
    InputLine parsedInput;
};

#endif
