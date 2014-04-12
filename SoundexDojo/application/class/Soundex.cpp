#include <Class/Soundex.hpp>
#include <cctype>

Soundex::Soundex()
{
    translationTable['b'] = '1';
    translationTable['f'] = '1';
    translationTable['p'] = '1';
    translationTable['v'] = '1';
    translationTable['c'] = '2';
    translationTable['g'] = '2';
    translationTable['j'] = '2';
    translationTable['k'] = '2';
    translationTable['q'] = '2';
    translationTable['s'] = '2';
    translationTable['x'] = '2';
    translationTable['z'] = '2';
    translationTable['d'] = '3';
    translationTable['t'] = '3';
    translationTable['l'] = '4';
    translationTable['m'] = '5';
    translationTable['n'] = '5';
    translationTable['r'] = '6';
}

Soundex::~Soundex()
{
}

std::string Soundex::encode(std::string arg)
{
    std::string result;
    if (!arg.empty())
    {
        for (int i = 0; i < arg.length(); ++i) 
        {
            if(isalpha(arg[i]))
            {
                result += arg[i];
                
            }
        }

        for (int i = 1; i < result.length(); ++i) 
        {
            if (translationTable.count(result[i]))
            {
                result[i] = translationTable[result[i]];
            }
        }
    }
    return result;
}