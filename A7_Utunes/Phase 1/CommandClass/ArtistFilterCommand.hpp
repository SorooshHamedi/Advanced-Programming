#ifndef _ARTIST_FILTER_COMMAND_HPP_
#define _ARTIST_FILTER_COMMAND_HPP_ 1

#include "NewFilterCommand.hpp"
const std::string ARTIST_FILTER_IDENTIFIER = "artist";

class ArtistFilterCommand : public NewFilterCommand
{
public:
    ArtistFilterCommand(const InputLine& input);
    FilterType getFilterType();
    std::string getArtist();
private:
    std::string artist;

    void verify(const InputLine& input);
    InputLine getCorrectSyntax();
    void invalidCommand();
    bool isAnInfoIndex(int i);
};

#endif