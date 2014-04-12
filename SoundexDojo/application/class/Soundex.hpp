#ifndef SOUNDEX_HPP_ASFSADF
#define SOUNDEX_HPP_ASFSADF

#include <string>
#include <map>

class Soundex
{
public:
    Soundex();
    virtual ~Soundex();

    std::string encode(std::string arg);
private:
    std::map<char, char> translationTable;
    char removeInvalidChars(std::string arg)
    {

    }
};

#endif
