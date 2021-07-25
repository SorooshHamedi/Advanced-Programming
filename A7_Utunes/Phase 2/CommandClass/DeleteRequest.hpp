#ifndef _DELETE_COMMAND_HPP_
#define _DELETE_COMMAND_HPP_ 1

#include "UtunesCommand.hpp"

const std::string DELETE_REQUEST = "DELETE";

class DeleteRequest : public UtunesCommand
{
public:
    DeleteRequest();
    CommandGroup getGroup();
private:
};





#endif
