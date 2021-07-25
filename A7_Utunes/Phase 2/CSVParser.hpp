#ifndef _CSV_PARSER_HPP_
#define _CSV_PARSER_HPP_ 1

#include "CSVLineParser.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class CSVParser
{
public:
    CSVParser(std::string _fileAddress);
    std::vector<InputLine> getParsedInput();
private:
    std::string fileAddress;
    std::vector<InputLine> parsedInput;
    void parse();
};




#endif