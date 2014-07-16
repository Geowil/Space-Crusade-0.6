#include "c_ai.h"

casinoAI::casinoAI()
{

}

casinoAI::casinoAI(string name, string race, char sex, int chips)
{
    cAIName = name;
    cAIRace = race;
    cAISex = sex;
    cAIChips = chips;
}

string casinoAI::getName()
{
    return cAIName;
}

string casinoAI::getRace()
{
    return cAIRace;
}

char casinoAI::getSex()
{
    return cAISex;
}

int casinoAI::getChips()
{
    return cAIChips;
}

void casinoAI::setName(string s)
{
    cAIName = s;
}

void casinoAI::setRace(string r)
{
    cAIRace = r;
}

void casinoAI::setSex(char s)
{
    cAISex = s;
}

void casinoAI::updateChips(int c, string operation)
{
    if (operation == "add")
    {
        cAIChips += c;
    }

    else if (operation == "sub")
    {
        cAIChips -= c;
    }

    else if (operation == "set")
    {
        cAIChips == c;
    }
}