#ifndef _READ_COMMAND_HPP_
#define _READ_COMMAND_HPP_ 1

#include "UtunesCommand.hpp"

const std::string READ_REQUEST = "GET";

class ReadRequest : public UtunesCommand
{
public:
    ReadRequest();
    CommandGroup getGroup();
private:
};





#endif
