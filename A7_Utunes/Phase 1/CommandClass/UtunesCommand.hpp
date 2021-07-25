#ifndef _UTUNES_COMMAND_HPP_
#define _UTUNES_COMMAND_HPP_ 1

#include <string>
#include "CommandEnums.hpp"
#include "../InputLine.hpp"
#include "../ExceptionClass/NotFoundError.hpp"

const std::string INPUT_ADDITIONAL_INFO_CHAR = "?";

class UtunesCommand
{
public:
    UtunesCommand();
    virtual CommandGroup getGroup() = 0;
    virtual CommandType getType() = 0;
protected:

};






#endif