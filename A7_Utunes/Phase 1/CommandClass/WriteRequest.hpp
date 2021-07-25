#ifndef _WRITE_COMMAND_HPP_
#define _WRITE_COMMAND_HPP_ 1

#include "UtunesCommand.hpp"

const std::string WRITE_REQUEST = "POST";

class WriteRequest : public UtunesCommand
{
public:
    WriteRequest();
    CommandGroup getGroup();
private:
};





#endif
