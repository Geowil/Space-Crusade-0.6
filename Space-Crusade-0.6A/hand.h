#ifndef HAND_H
#define HAND_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct hand
{
	vector<string> cards;
	string state;
	bool dealer; //For poker games
};
#endif