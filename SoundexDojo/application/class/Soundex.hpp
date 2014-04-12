#ifndef SOUNDEX_HPP_ASFSADF
#define SOUNDEX_HPP_ASFSADF

#include <string>

class Soundex
{
public:
    Soundex();
    virtual ~Soundex();

    std::string encode(std::string arg);
};

#endif
