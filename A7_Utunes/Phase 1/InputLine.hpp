#ifndef _INPUT_LINE_HPP_
#define _INPUT_LINE_HPP_ 1

#include <vector>
#include <string>

class InputLine
{
public:
    InputLine();
    std::string& operator[](size_t i);
    const std::string& operator[](size_t i) const;
    void push_back(const std::string& s);
    int size() const;
private:
    std::vector<std::string> data;
};



#endif