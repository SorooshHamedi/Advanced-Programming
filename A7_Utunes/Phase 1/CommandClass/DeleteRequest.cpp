#include "DeleteRequest.hpp"

DeleteRequest::DeleteRequest()
{
}

CommandGroup DeleteRequest::getGroup()
{
    return DELETE;
}