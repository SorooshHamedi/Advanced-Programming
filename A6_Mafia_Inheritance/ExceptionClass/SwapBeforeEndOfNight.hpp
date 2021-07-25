#ifndef _SWAP_BEFORE_END_OF_NIGHT_HPP_
#define _SWAP_BEFORE_END_OF_NIGHT_HPP_

#include <exception>
const char SWAP_BEFORE_END_OF_NIGHT_ERROR[] = "Can't swap before end of night\n";

class SwapBeforeEndOfNightError : public std::exception
{
public:
    const char* what() const throw();
};

#endif


