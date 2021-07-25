#ifndef _CHARACTERS_ALREADY_SWAPPED_HPP_
#define _CHARACTERS_ALREADY_SWAPPED_HPP_

#include <exception>
const char CHARACTERS_ALREADY_SWAPPED_ERROR[] = "Characters already swapped\n";

class CharactersAlreadySwappedError : public std::exception
{
public:
    const char* what() const throw();
};


#endif