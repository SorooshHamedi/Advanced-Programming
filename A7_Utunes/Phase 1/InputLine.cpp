#include "InputLine.hpp"

InputLine::InputLine(){}


std::string& InputLine::operator[](size_t i)
{
    return data[i];
}

void InputLine::push_back(const std::string& s)
{
    data.push_back(s);
}

int InputLine::size() const
{
    return data.size();
}

const std::string& InputLine::operator[](size_t i) const
{
    return data[i];
}
