#include "ArtistFilterCommand.hpp"

const int ARTIST_INDEX = 4;
const int SIZE = 4;
const std::string FILTERS = "filters";
const std::string ARTIST_COMMAND = "artist";

ArtistFilterCommand::ArtistFilterCommand(const InputLine& input)
{
    verify(input);
    for(int i=ARTIST_INDEX; i<input.size(); i++)
    {
        if(i > ARTIST_INDEX)
        {
            artist += ' ';
        }
        artist += input[i];

    }
}

FilterType ArtistFilterCommand::getFilterType()
{
    return ARTIST;
}

std::string ArtistFilterCommand::getArtist()
{
    return artist;
}

void ArtistFilterCommand::verify(const InputLine& input)
{
    InputLine correctSyntax = getCorrectSyntax();
    if(input.size() < SIZE)
    {
        invalidCommand();
    }
    for(int i=0; i<SIZE; i++)
    {
        if(input[i] != correctSyntax[i])
        {
            invalidCommand();
        }
    }
}

InputLine ArtistFilterCommand::getCorrectSyntax()
{
    InputLine syntax;
    syntax.push_back(WRITE_REQUEST);
    syntax.push_back(FILTERS);
    syntax.push_back(INPUT_ADDITIONAL_INFO_CHAR);
    syntax.push_back(ARTIST_COMMAND);
    return syntax;
}

void ArtistFilterCommand::invalidCommand()
{
    std::exception* ex = new NotFoundError();
    throw ex;
}

bool ArtistFilterCommand::isAnInfoIndex(int i)
{
    return i == ARTIST_INDEX;
}

