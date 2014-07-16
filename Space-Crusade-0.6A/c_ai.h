#ifndef C_AI_H
#define C_AI_H

#include <string>
#include <vector>
#include "hand.h"

using std::string;
using std::vector;

class casinoAI
{
public:
    casinoAI();
    casinoAI(string name, string race, char sex, int chips); //Later on add in a personality parameter that will allow certain types of behaviors while playing to be displayed

    string getName();
    string getRace();
    char getSex();
    int getChips();

    void setName(string s);
    void setRace(string r);
    void setSex(char s);
    void updateChips(int c, string operation);

	vector<hand> hands; //Store cards for blackjack or poker

private:
    string cAIName;
    string cAIRace;
    char cAISex;
    int cAIChips;	
};

#endif // C_AI_H
