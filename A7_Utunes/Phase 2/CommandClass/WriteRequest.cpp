#include "WriteRequest.hpp"

WriteRequest::WriteRequest()
{
}

CommandGroup WriteRequest::getGroup()
{
    return WRITE;
}