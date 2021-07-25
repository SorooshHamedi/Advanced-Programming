#ifndef _NEW_FILTER_COMMAND_HPP_
#define _NEW_FILTER_COMMAND_HPP_ 1

#include "WriteRequest.hpp"

enum FilterType
{
    ARTIST,
    RELEASE_YEAR,
    LIKES,
};

class NewFilterCommand : public WriteRequest
{
public:
    NewFilterCommand();
    CommandType getType();
    virtual FilterType getFilterType() = 0;
};



#endif