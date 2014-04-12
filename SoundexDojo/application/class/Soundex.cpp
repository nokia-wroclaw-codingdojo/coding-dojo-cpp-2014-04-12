#include <Class/Soundex.hpp>

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
    //std::string result(arg.at(0));

    for (int i = 1; i < arg.length(); ++i) 
    {
        if (translationTable.count(arg[i])) 
        {
            arg[i] = translationTable[arg[i]];
        }
    }

    return arg;
}