#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <sstream>
#include <string>
#include <vector>

typedef std::vector<std::string> Input;

class Parser
{
public:
    Parser(std::string str);
    Input parsedInput;
private:
    std::string input;
    void parse();
};

#endif
