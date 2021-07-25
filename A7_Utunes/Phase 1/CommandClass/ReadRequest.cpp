#include "ReadRequest.hpp"

ReadRequest::ReadRequest()
{
}

CommandGroup ReadRequest::getGroup()
{
    return READ;
}