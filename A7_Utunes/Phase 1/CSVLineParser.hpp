#ifndef _CSV_LINE_PARSER_HPP_
#define _CSV_LINE_PARSER_HPP_ 1

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "InputLine.hpp"

class CSVLineParser
{
public:
    CSVLineParser(std::string str);
    InputLine getParsedInput();
private:
    std::string input;
    void parse();
    InputLine parsedInput;
};

#endif
