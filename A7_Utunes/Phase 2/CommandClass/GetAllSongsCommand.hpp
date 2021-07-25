#ifndef _GET_ALL_SONGS_COMMAND_HPP_
#define _GET_ALL_SONGS_COMMAND_HPP_ 1

#include "ReadRequest.hpp"

const std::string SONGS_COMMAND = "songs";
class GetAllSongsCommand : public ReadRequest
{
public:
    GetAllSongsCommand(const InputLine& input);
    CommandType getType();
private:
    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();    
};

#endif