//External Headers
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <direct.h>
//#include <cstdlib>
#include "datasystem.h"
#include "random.h"
#include "msgproc.h"
#include "debug.h"
#include "mining.h"
#include "c_ai.h"
#include "nameGen.h"
#include "globalvars.h"

//Internal Header(s)
#include "game.h"

using std::string;
using std::vector;
using std::endl;
using std::cout;

namespace gv = gVars;

//Class References
//Story gStory;
dataSystem ds_g;
msgProc mp_g;
Station stat_g;
Debug d_g;
Mining mine;
casinoAI cai;
nameGen ng_g;


Game::Game()
{
	nSPlanets = 15; //External value tag: int
	nTStations = 25; //External value tag: int

	string sCRWheel[76] = {
		"G 0",
		"B 30", //1
		"R 57",
		"B 38",
		"R 17",
		"B 16",
		"R 7",
		"B 68",
		"R 55",
		"B 41",
		"R 1",
		"B 24", //11
		"R 52",
		"B 63",
		"R 60",
		"B 59",
		"R 50",
		"B 45",
		"R 47", //18
		"G 00",
		"R 9", //20
		"B 20",
		"R 11",
		"B 28",
		"R 49",
		"B 40",
		"R 5",
		"B 44",
		"R 36",
		"B 62",
		"R 65", //30
		"B 3",
		"R 32",
		"B 71",
		"R 14",
		"B 23",
		"R 22",
		"B 70", //37
		"G 000",
		"B 31", //39
		"R 58",
		"B 39",
		"R 18",
		"B 17",
		"R 8",
		"B 69",
		"R 56",
		"B 42",
		"R 2",
		"B 25", //49
		"R 53",
		"B 64",
		"R 61",
		"B 60",
		"R 51",
		"B 46",
		"R 48", //56
		"G 0000",
		"R 10", //58
		"B 21",
		"R 12",
		"B 29",
		"R 50",
		"B 41",
		"R 6",
		"B 45",
		"R 37",
		"B 63",
		"R 66", //68
		"B 4",
		"R 33",
		"B 72",
		"R 15",
		"B 24",
		"R 23",
		"B 71" //76
	};

	string cSR1[20] =
	{
		"1",
		"4",
		"2",
		"Bar",
		"6",
		"7",
		"Heart",
		"9",
		"11",
		"Jackpot",
		"5",
		"Bell",
		"Break",
		"10",
		"12",
		"14",
		"3",
		"8",
		"15"
	};

	string cSR2[20] =
	{
		"4",
		"Bar",
		"11",
		"6",
		"Heart",
		"Break",
		"7",
		"1",
		"5",
		"Bell",
		"13",
		"15",
		"8",
		"3",
		"Jackpot",
		"2",
		"10",
		"9",
		"14",
		"12"
	};

	string cSR3[20] =
	{
		"Break",
		"2",
		"11",
		"6",
		"1",
		"9",
		"Heart",
		"7",
		"3",
		"14",
		"Bar",
		"Bell",
		"5",
		"13",
		"15",
		"Jackpot",
		"4",
		"8",
		"12",
		"10"
	};

	string cSR4[20] =
	{
		"14",
		"2",
		"9",
		"1",
		"6",
		"Jackpot",
		"Bar",
		"8",
		"11",
		"5",
		"Bell",
		"15",
		"13",
		"Heart",
		"3",
		"7",
		"Break",
		"4",
		"10",
		"12"
	};

	string cSR5[20] =
	{
		"1",
		"Jackpot",
		"5",
		"11",
		"Break",
		"9",
		"13",
		"14",
		"7",
		"Bell",
		"4",
		"8",
		"Heart",
		"Bar",
		"3",
		"10",
		"6",
		"12",
		"2",
		"15"
	};

	string cSR6[20] =
	{
		"Break",
		"2",
		"13",
		"Heart",
		"4",
		"1",
		"9",
		"11",
		"7",
		"6",
		"Bar",
		"Jackpot",
		"8",
		"3",
		"5",
		"Bell",
		"10",
		"15",
		"12",
		"14"
	};

	string cSR7[20] =
	{
		"14",
		"7",
		"10",
		"4",
		"Bar",
		"Break",
		"1",
		"9",
		"15",
		"11",
		"Bell",
		"3",
		"8",
		"12",
		"Jackpot",
		"Heart",
		"2",
		"6",
		"13",
		"5"
	};

	string cSR8[20] =
	{
		"Bar",
		"1",
		"12",
		"8",
		"3",
		"Bell",
		"Break",
		"10",
		"4",
		"Jackpot",
		"6",
		"13",
		"Heart",
		"9",
		"7",
		"15",
		"2",
		"11",
		"5",
		"14"
	};

	string cSR9[20] =
	{
		"9",
		"3",
		"12",
		"7",
		"1",
		"15",
		"5",
		"Bar",
		"11",
		"8",
		"Jackpot",
		"Heart",
		"6",
		"Break",
		"2",
		"14",
		"Bell",
		"4",
		"10",
		"13"
	};

	string cSR10[20] =
	{
		"11",
		"1",
		"12",
		"15",
		"Break",
		"6",
		"10",
		"Bell",
		"7",
		"13",
		"Heart",
		"Bar",
		"5",
		"4",
		"Bell",
		"2",
		"8",
		"9",
		"3",
		"14"
	};

	string cSR11[20] =
	{
		"7",
		"11",
		"4",
		"12",
		"9",
		"2",
		"10",
		"Break",
		"1",
		"Bell",
		"Heart",
		"13",
		"6",
		"10",
		"5",
		"Jackpot",
		"Bar",
		"3",
		"8",
		"14"
	};

	string cSR12[20] =
	{
		"Heart",
		"13",
		"8",
		"10",
		"2",
		"Break",
		"7",
		"12",
		"9",
		"5",
		"Jackpot",
		"1",
		"4",
		"Bar",
		"6",
		"11",
		"15",
		"Bell",
		"14",
		"3"
	};

	string cards[52] =
	{
		"A H",
		"2 H",
		"3 H",
		"4 H",
		"5 H",
		"6 H",
		"7 H",
		"8 H",
		"9 H",
		"T H",
		"J H",
		"Q H",
		"K H",
		"A D",
		"2 D",
		"3 D",
		"4 D",
		"5 D",
		"6 D",
		"7 D",
		"8 D",
		"9 D",
		"T D",
		"J D",
		"Q D",
		"K D",
		"A C",
		"2 C",
		"3 C",
		"4 C",
		"5 C",
		"6 C",
		"7 C",
		"8 C",
		"9 C",
		"T C",
		"J C",
		"Q C",
		"K C",
		"A S",
		"2 S",
		"3 S",
		"4 S",
		"5 S",
		"6 S",
		"7 S",
		"8 S",
		"9 S",
		"T S",
		"J S",
		"Q S",
		"K S"
	};
}

void Game::gSave(Player& mPlayer)
{
	cout << "Beginning saving process..." << endl;

	cout << "Opening save database..." << endl;

	bDSComplete = ds_g.sData(mPlayer, this);

	if (bDSComplete)
	{
		cout << "Player data saved successfully!" << endl;
		cout << endl;
		mp_g.mCScreen(true);
	}

	else
	{
		cout << "Saving did not complete successfully.  Check game log for more details" << endl;
		mp_g.mCScreen(true);
	}
}

void Game::gLoad(Player& mPlayer)
{
	cout << "Beginning loading process..." << endl;

	cout << "Opening the save database..." << endl;

	bDLComplete = ds_g.lData(mPlayer, this);

	if (bDLComplete)
	{
		cout << "Player data loaded successfully!" << endl;
		cout << endl;
		mp_g.mCScreen(true);
	}

	else
	{
		cout << "Loading did not complete successfully.  Check game log for more details" << endl;
		mp_g.mCScreen(true);
	}
}

void Game::getPNames()
{
	pNStorage.push_back(string());
	ds_g.getPNames(pNStorage);
}

void Game::generatePlanets()
{
	for(i = 1; pNStorage.size() > 1; i++) //No condition against i since we want to go until all of the names have been used or until the chosen number of planets has been reached
	{
		pNRand = Random(0,pNStorage.size()-1); //Random to the size of the names vector

		pDisRand = Random(1,4); //External value tag: int range

		if (pDisRand == 1)
		{
			tempDisp = "Allied";
		}

		else if (pDisRand == 2)
		{
			tempDisp = "Neutral";
		}

		else if (pDisRand == 3)
		{
			tempDisp = "Hostile";
		}

		/*else if (pDisRand == 4)
		{
		tempDisp = "Controlled";
		}*/

		pAffRand = Random(1,7); //External value tag: int range

		if (pAffRand == 1)
		{
			tempAffi = "Earth Alliance";
			tempRace = "Human";
			tempDisp = "Allied"; //Override tempDisp from earlier for story related elements at start of game
		}

		else if (pAffRand == 2)
		{
			tempAffi = "Sluikan Imperium";
			tempRace = "Sluikan";
			tempDisp = "Hostile";
		}

		else if (pAffRand == 3)
		{
			tempAffi = "Juslorth Empire";
			tempRace = "Juslorth";
			tempDisp = "Hostile";
		}

		else if (pAffRand == 4)
		{
			tempAffi = "Visar Collectorate";
			tempRace = "Visar";
		}

		else if (pAffRand == 5)
		{
			tempAffi = "Adent Council";
			tempRace = "Adent";
		}

		else if (pAffRand == 6)
		{
			tempAffi = "Prokl Unity";
			tempRace = "Prokl";
		}

		else if (pAffRand == 7)
		{
			tempAffi = "Groz Hermiteag";
			tempRace = "Groz";
		}


		gPlanets.push_back(Planet(i,pNStorage.at(pNRand),tempDisp,tempAffi, tempRace)); //Create a planet with the choosen name

		pNStorage.erase(pNStorage.begin()+pNRand); //Remove the name from the names vector

		//Start Planet Info Setup

		//EKS and Size Range Randomization
		pERand = Random(1.0f,5500.0f); //External value tag: float range
		pSRRand = Random(1,1000); //External value tag: int range

		pERand = pERand * 0.001; //Convert random EKS value to a proper format

		bPPGen = false; //So while loops will run

		//Type 0
		if ((pERand >= 0.0f) && (pERand <= 0.9f)) //External value tag: int range
		{
			while (!bPPGen) //While planet pop has not been generated
			{
				pSRand = Random(1.0f,2.5f); //Randomize the planet size and then get to checking

				if ((pSRRand >= 450) && (pSRRand <= 625)) //If planet size range is within the range of 450 and 625 continue
				{
					if (pSRand < 1.2f || pSRand > 1.8f) //If planet size is outside of the range of 1.2 to 1.8 continue otherwise reroll the size rand on next loop
					{
						pPStore = calcPop(); //Calculate the population and return to pPStore
						pPMax = (long long int)pPStore; //Convert pPStore to a lli and save to pPMax
						bPPGen = true; //Pop has been generated so set to true
					}

				}

				else if (pSRRand < 450 || pSRRand > 625) //If planet size range is outside of the range of 450 to 625 continue
				{
					if ((pSRand >= 1.2f) && (pSRand <= 1.8f)) //If planet size is within the range of 1.2 and 1.8 continue otherwise reroll the size rand on next loop
					{
						pPStore = calcPop();
						pPMax = (long long int)pPStore;
						bPPGen = true;
					}
				}
			}
		}

		//Type 1
		else if ((pERand >= 1.0f) && (pERand <= 1.9f)) //External value tag: int range
		{
			while (!bPPGen)
			{
				pSRand = Random(1.9f,3.0f);

				if ((pSRRand >= 450) && (pSRRand <= 625))
				{
					if (pSRand < 2.0f || pSRand > 2.3f)
					{
						pPStore = calcPop();
						pPMax = (long long int)pPStore;
						bPPGen = true;
					}

				}

				else if (pSRRand < 450 || pSRRand > 625)
				{
					if ((pSRand >= 2.0f) && (pSRand <= 2.3f))
					{
						pPStore = calcPop();
						pPMax = (long long int)pPStore;
						bPPGen = true;
					}
				}
			}
		}


		//Type 2
		else if ((pERand >= 2.0f) && (pERand <= 2.9f)) //External value tag: int range
		{
			while (!bPPGen)
			{
				pSRand = Random(2.4f,5.3f);

				if ((pSRRand >= 450) && (pSRRand <= 625))
				{
					if (pSRand < 2.8f || pSRand > 4.1f)
					{
						pPStore = calcPop();
						pPMax = (long long int)pPStore;
						bPPGen = true;
					}

				}

				else if (pSRRand < 450 || pSRRand > 625)
				{
					if ((pSRand >= 2.8f) && (pSRand <= 4.1f))
					{
						pPStore = calcPop();
						pPMax = (long long int)pPStore;
						bPPGen = true;
					}
				}
			}
		}

		//Type 3
		else if ((pERand >= 3.0f) && (pERand <= 3.9f)) //External value tag: int range
		{
			while (!bPPGen)
			{
				pSRand = Random(4.2f,7.7f);

				if ((pSRRand >= 450) && (pSRRand <= 625))
				{
					if (pSRand < 4.8f || pSRand > 6.9f)
					{
						pPStore = calcPop();
						pPMax = (long long int)pPStore;
						bPPGen = true;
					}

				}

				else if (pSRRand < 450 || pSRRand > 625)
				{
					if ((pSRand >= 4.8f) && (pSRand <= 6.9f))
					{
						pPStore = calcPop();
						pPMax = (long long int)pPStore;
						bPPGen = true;
					}
				}
			}
		}

		//Type 4
		else if ((pERand >= 4.0f) && (pERand <= 4.9f)) //External value tag: int range
		{
			while (!bPPGen)
			{
				pSRand = Random(7.0f,8.4f);

				if ((pSRRand >= 450) && (pSRRand <= 625))
				{
					if (pSRand < 7.5f || pSRand > 7.9f)
					{
						pPStore = calcPop();
						pPMax = (long long int)pPStore;
						bPPGen = true;
					}

				}

				else if (pSRRand < 450 || pSRRand > 625)
				{
					if ((pSRand >= 7.5f) && (pSRand <= 7.9f))
					{
						pPStore = calcPop();
						pPMax = (long long int)pPStore;
						bPPGen = true;
					}
				}
			}
		}

		//Type 5
		else if (pERand > 4.9f) //External value tag: int range
		{
			while (!bPPGen)
			{
				pSRand = Random(8.0f,10.0f);

				if ((pSRRand >= 450) && (pSRRand <= 625))
				{
					if (pSRand < 8.8f || pSRand > 9.7f)
					{
						pPStore = calcPop();
						pPMax = (long long int)pPStore;
						bPPGen = true;
					}

				}

				else if (pSRRand < 450 || pSRRand > 625)
				{
					if ((pSRand >= 8.8f) && (pSRand <= 9.7f))
					{
						pPStore = calcPop();
						pPMax = (long long int)pPStore;
						bPPGen = true;
					}
				}
			}
		}

		gPlanets.at(i-1).setEKS(pERand); //Set planet EKS value
		gPlanets.at(i-1).setSize(pSRand); //Set planet size
		gPlanets.at(i-1).updatePop(pPMax,"set"); //Set planet population
		gPlanets.at(i-1).updateMPop(pPMax,"set"); //Set planet max population

		getDefenses(Random(1,100), pERand);
		getShields(Random(1,100), pERand);

		if (numODef > 0)
		{
			addDefenses(i-1, pERand);
		}

		if (numOShd > 0)
		{
			addShields(i-1, pERand);
		}

		gPlanets.at(i-1).createBelts();
	}
}

float Game::calcPop()
{
	//Randomize population rands
	popRand1 = Random(1,60);
	popRand2 = Random(1,100);
	popRand3 = Random(1,260);

	return ((((((8000 * popRand1) * popRand2) * pERand) * pSRand) * popRand3) / 6);
}

void Game::getDefenses(int rand, float eks)
{
	if ((eks > 0.0f) && (eks < 1.0f)) //Type 0 Planet
	{
		if ((rand >= 1) && (rand <= 35)) //36% chance for 0 defenses
		{
			numODef = 0;
		}

		else if ((rand >= 36) && (rand <= 60)) //25% chance for 1 defense
		{
			numODef = 1;
		}

		else if ((rand >= 61) && (rand <= 78)) //18% chance for 2 defenses
		{
			numODef = 2;
		}

		else if ((rand >= 79) && (rand <= 87)) //7% chance for 3 defenses
		{
			numODef = 3;
		}

		else if ((rand >= 88) && (rand <= 94)) //7% chance for 4 defenses
		{
			numODef = 4;
		}

		else if ((rand >= 95) && (rand <= 98)) //4% chance for 5 defenses
		{
			numODef = 5;
		}

		else if (rand >= 99) //2% Chance for 6 defenses
		{
			numODef = 6;
		}
	}

	else if ((eks >= 1.0f) && (eks < 2.0f)) //Type 1 Planet
	{
		if ((rand >= 1) && (rand <= 28)) //29% chance for 0 defenses
		{
			numODef = 0;
		}

		else if ((rand >= 28) && (rand <= 55)) //28% chance for 1 defense
		{
			numODef = 1;
		}

		else if ((rand >= 56) && (rand <= 71)) //16% chance for 2 defenses
		{
			numODef = 2;
		}

		else if ((rand >= 72) && (rand <= 82)) //11% chance for 3 defenses
		{
			numODef = 3;
		}

		else if ((rand >= 83) && (rand <= 90)) //8% chance for 4 defenses
		{
			numODef = 4;
		}

		else if ((rand >= 91) && (rand <= 96)) //7% chance for 5 defenses
		{
			numODef = 5;
		}

		else if (rand >= 97) //4% Chance for 6 defenses
		{
			numODef = 6;
		}
	}

	else if ((eks >= 2.0f) && (eks < 3.0f)) //Type 2 Planet
	{
		if ((rand >= 1) && (rand <= 28)) //29% chance for 0 defenses
		{
			numODef = 0;
		}

		else if ((rand >= 29) && (rand <= 56)) //28% chance for 1 defense
		{
			numODef = 1;
		}

		else if ((rand >= 57) && (rand <= 70)) //14% chance for 2 defenses
		{
			numODef = 2;
		}

		else if ((rand >= 71) && (rand <= 82)) //12% chance for 3 defenses
		{
			numODef = 3;
		}

		else if ((rand >= 83) && (rand <= 91)) //9% chance for 4 defenses
		{
			numODef = 4;
		}

		else if ((rand >= 92) && (rand <= 96)) //5% chance for 5 defenses
		{
			numODef = 5;
		}

		else if (rand >= 97) //4% Chance for 6 defenses
		{
			numODef = 6;
		}
	}

	else if ((eks >= 3.0f) && (eks < 4.0f)) //Type 3 Planet
	{
		if ((rand >= 1) && (rand <= 20)) //21% chance for 0 defenses
		{
			numODef = 0;
		}

		else if ((rand >= 21) && (rand <= 46)) //26% chance for 1 defense
		{
			numODef = 1;
		}

		else if ((rand >= 47) && (rand <= 68)) //19% chance for 2 defenses
		{
			numODef = 2;
		}

		else if ((rand >= 68) && (rand <= 80)) //13% chance for 3 defenses
		{
			numODef = 3;
		}

		else if ((rand >= 81) && (rand <= 89)) //9% chance for 4 defenses
		{
			numODef = 4;
		}

		else if ((rand >= 90) && (rand <= 95)) //6% chance for 5 defenses
		{
			numODef = 5;
		}

		else if ((rand >= 96) && (rand <= 98)) //3% chance for 6 defenses
		{
			numODef = 6;
		}

		else if (rand >= 99) //2% chance for 7 defenses
		{
			numODef = 7;
		}
	}

	else if ((eks >= 4.0f) && (eks < 5.0f)) //Type 4 Planet
	{
		if ((rand >= 1) && (rand <= 18)) //19% chance for 0 defenses
		{
			numODef = 0;
		}

		else if ((rand >= 19) && (rand <= 35)) //15% chance for 1 defense
		{
			numODef = 1;
		}

		else if ((rand >= 36) && (rand <= 55)) //20% chance for 2 defenses
		{
			numODef = 2;
		}

		else if ((rand >= 56) && (rand <= 68)) //13% chance for 3 defenses
		{
			numODef = 3;
		}

		else if ((rand >= 69) && (rand <= 80)) //12% chance for 4 defenses
		{
			numODef = 4;
		}

		else if ((rand >= 81) && (rand <= 89)) //9% chance for 5 defenses
		{
			numODef = 5;
		}

		else if ((rand >= 90) && (rand <= 95)) //6% chance for 6 defenses
		{
			numODef = 6;
		}

		else if (rand >= 96) //5% chance for 7 defenses
		{
			numODef = 7;
		}
	}

	else if (eks >= 5.0f) //Type 5 Planet
	{
		if ((rand >= 1) && (rand <= 12)) //13% chance for 0 defenses
		{
			numODef = 0;
		}

		else if ((rand >= 13) && (rand <= 28)) //16% chance for 1 defense
		{
			numODef = 1;
		}

		else if ((rand >= 29) && (rand <= 48)) //20% chance for 2 defenses
		{
			numODef = 2;
		}

		else if ((rand >= 49) && (rand <= 62)) //14% chance for 3 defenses
		{
			numODef = 3;
		}

		else if ((rand >= 63) && (rand <= 74)) //12% chance for 4 defenses
		{
			numODef = 4;
		}

		else if ((rand >= 75) && (rand <= 85)) //11% chance for 5 defenses
		{
			numODef = 5;
		}

		else if ((rand >= 86) && (rand <= 92)) //9% chance for 6 defenses
		{
			numODef = 6;
		}

		else if ((rand >= 93) && (rand <= 97)) //5% chance for 7 defenses
		{
			numODef = 7;
		}

		else if (rand >= 98) //3% chance for 8 defenses
		{
			numODef = 8;
		}
	}
}

void Game::getShields(int rand, float eks)
{
	if ((eks > 0.0f) && (eks < 1.0f)) //Type 0 Planet
	{
		if ((rand >= 1) && (rand <= 60)) //61% chance for 0 shields
		{
			numOShd = 0;
		}

		else if ((rand >= 61) && (rand <= 86)) //26% chance for 1 shields
		{
			numOShd = 1;
		}

		else if (rand >= 86) //17% chance for 2 shields
		{
			numOShd = 2;
		}
	}

	else if ((eks >= 1.0f) && (eks < 2.0f)) //Type 1 Planet
	{
		if ((rand >= 1) && (rand <= 52)) //53% chance for 0 shields
		{
			numOShd = 0;
		}

		else if ((rand >= 53) && (rand <= 84)) //22% chance for 1 shields
		{
			numOShd = 1;
		}

		else if (rand >= 85) //15% chance for 2 shields
		{
			numOShd = 2;
		}
	}

	else if ((eks >= 2.0f) && (eks < 3.0f)) //Type 2 Planet
	{
		if ((rand >= 1) && (rand <= 35)) //36% chance for 0 shields
		{
			numOShd = 0;
		}

		else if ((rand >= 36) && (rand <= 68)) //33% chance for 1 shields
		{
			numOShd = 1;
		}

		else if ((rand >= 69) && (rand <= 87)) //18% chance for 2 shields
		{
			numOShd = 2;
		}

		else if (rand >= 88) //13% chance for 3 shields
		{
			numOShd = 3;
		}
	}

	else if ((eks >= 3.0f) && (eks < 4.0f)) //Type 3 Planet
	{
		if ((rand >= 1) && (rand <= 27)) //28% chance for 0 shields
		{
			numOShd = 0;
		}

		else if ((rand >= 28) && (rand <= 64)) //27% chance for 1 shields
		{
			numOShd = 1;
		}

		else if ((rand >= 64) && (rand <= 84)) //21% chance for 2 shields
		{
			numOShd = 2;
		}

		else if (rand >= 85) //16% chance for 3 shields
		{
			numOShd = 3;
		}
	}

	else if ((eks >= 4.0f) && (eks < 5.0f)) //Type 4 Planet
	{
		if ((rand >= 1) && (rand <= 20)) //21% chance for 0 shields
		{
			numOShd = 0;
		}

		else if ((rand >= 21) && (rand <= 48)) //28% chance for 1 shields
		{
			numOShd = 1;
		}

		else if ((rand >= 49) && (rand <= 74)) //26% chance for 2 shields
		{
			numOShd = 2;
		}

		else if ((rand >= 75) && (rand <= 88)) //14% chance for 3 shields
		{
			numOShd = 3;
		}

		else if (rand >= 89) //12% chance for 4 shields
		{
			numOShd = 4;
		}
	}

	else if (eks >= 5.0f) //Type 5 Planet
	{
		if ((rand >= 1) && (rand <= 18)) //19% chance for 0 shields
		{
			numOShd = 0;
		}

		else if ((rand >= 19) && (rand <= 36)) //18% chance for 1 shields
		{
			numOShd = 1;
		}

		else if ((rand >= 37) && (rand <= 65)) //29% chance for 2 shields
		{
			numOShd = 2;
		}

		else if ((rand >= 66) && (rand <= 84)) //19% chance for 3 shields
		{
			numOShd = 3;
		}

		else if (rand >= 85) //16% chance for 4 shields
		{
			numOShd = 4;
		}
	}
}

void Game::addDefenses(int i, float eks)
{
	if ((eks > 0.0f) && (eks < 1.0f)) //Type 0 Planet
	{
		for (i2 = 0; i2 < numODef; i2++)
		{
			gPlanets.at(i).addPDefenses(true,Random(101,103),false,0,false);
		}
	}

	else if ((eks >= 1.0f) && (eks < 2.0f)) //Type 1 Planet
	{
		for (i2 = 0; i2 < numODef; i2++)
		{
			gPlanets.at(i).addPDefenses(true,Random(101,106),false,0,false);
		}
	}

	else if ((eks >= 2.0f) && (eks < 3.0f)) //Type 2 Planet
	{
		for (i2 = 0; i2 < numODef; i2++)
		{
			gPlanets.at(i).addPDefenses(true,Random(101,109),false,0,false);
		}
	}

	else if ((eks >= 3.0f) && (eks < 4.0f)) //Type 3 Planet
	{
		for (i2 = 0; i2 < numODef; i2++)
		{
			gPlanets.at(i).addPDefenses(true,Random(101,112),false,0,false);
		}
	}

	else if ((eks >= 4.0f) && (eks < 5.0f)) //Type 4 Planet
	{
		for (i2 = 0; i2 < numODef; i2++)
		{
			gPlanets.at(i).addPDefenses(true,Random(101,115),false,0,false);
		}
	}

	else if (eks >= 5.0f) //Type 5 Planet
	{
		for (i2 = 0; i2 < numODef; i2++)
		{
			gPlanets.at(i).addPDefenses(true,Random(101,118),false,0,false);
		}
	}
}

void Game::addShields(int i, float eks)
{
	if ((eks > 0.0f) && (eks < 1.0f)) //Type 0 Planet
	{
		for (i2 = 0; i2 < numOShd; i2++)
		{
			gPlanets.at(i).addPDefenses(false,0,true,Random(1,3),false);
		}
	}

	else if ((eks >= 1.0f) && (eks < 2.0f)) //Type 1 Planet
	{
		for (i2 = 0; i2 < numOShd; i2++)
		{
			gPlanets.at(i).addPDefenses(false,0,true,Random(1,6),false);
		}
	}

	else if ((eks >= 2.0f) && (eks < 3.0f)) //Type 2 Planet
	{
		for (i2 = 0; i2 < numOShd; i2++)
		{
			gPlanets.at(i).addPDefenses(false,0,true,Random(1,9),false);
		}
	}

	else if ((eks >= 3.0f) && (eks < 4.0f)) //Type 3 Planet
	{
		for (i2 = 0; i2 < numOShd; i2++)
		{
			gPlanets.at(i).addPDefenses(false,0,true,Random(1,12),false);
		}
	}

	else if ((eks >= 4.0f) && (eks < 5.0f)) //Type 4 Planet
	{
		for (i2 = 0; i2 < numOShd; i2++)
		{
			gPlanets.at(i).addPDefenses(false,0,true,Random(1,15),false);
		}
	}

	else if (eks >= 5.0f) //Type 5 Planet
	{
		for (i2 = 0; i2 < numOShd; i2++)
		{
			gPlanets.at(i).addPDefenses(false,0,true,Random(1,18),false);
		}
	}
}

bool Game::isDest(int id)
{
	if (gPlanets.at(id).bPIsDest())
	{
		return true;
	}

	else
	{
		return false;
	}
}

void Game::iSPlanets()
{
	for (i = 0; i < nSPlanets; i++)
	{
		sPlanets.push_back(Planet());

		sPlanets.at(i).setName("Default");
	}
}

void Game::rSPlanets()
{
	sPlanets.clear();
}

/*bool Game::isOwned()
{

}*/

void Game::fPlanets()
{
	for (i = 0; i < sPlanets.size();)
	{
		pRID = Random(1, gPlanets.size());

		if (!gPlanets.at(pRID-1).bPIsDest())
		{
			for(i2 = 0; i2 <= sPlanets.size(); i2++)
			{
				if ((i2 == sPlanets.size()) && (sPlanets.at(i).getName() == "Default")) //Only add the planet to sPlanets if no element in sPlanets is the same as gPlanets.at(pRID) and the sPlanets element does not already have a planet in it
				{
					sPlanets.at(i).setPID(gPlanets.at(pRID-1).getPID());
					sPlanets.at(i).setName(gPlanets.at(pRID-1).getName());
					sPlanets.at(i).setEKS(gPlanets.at(pRID-1).getEKS());
					sPlanets.at(i).setAffil(gPlanets.at(pRID-1).getAffil());
					sPlanets.at(i).setDispo(gPlanets.at(pRID-1).getDispo());
					sPlanets.at(i).setRace(gPlanets.at(pRID-1).getRace());
					sPlanets.at(i).setSize(gPlanets.at(pRID-1).getSize());
					sPlanets.at(i).updatePop(gPlanets.at(pRID-1).getPop(), "set");
					sPlanets.at(i).updateMPop(gPlanets.at(pRID-1).getMPop(), "set");

					if (gPlanets.at(pRID-1).pDef.size() > 0)
					{
						for (i3 = 0; i3 < gPlanets.at(pRID-1).pDef.size(); i3++)
						{
							sPlanets.at(i).addPDefenses(true, gPlanets.at(pRID-1).pDef.at(i3).getID(), false, 0, false);
						}
					}

					if (gPlanets.at(pRID-1).pShd.size() > 0)
					{
						for (i3 = 0; i3 < gPlanets.at(pRID-1).pShd.size(); i3++)
						{
							sPlanets.at(i).addPDefenses(false, 0, true, gPlanets.at(pRID-1).pShd.at(i3).getID(), false);
						}
					}

					sPlanets.at(i).setTDist(Random(8,50)); //Set the travel distance

					i += 1; //iterate i in first for loop
					break;
				}

				else if (sPlanets.at(i2).getName() == gPlanets.at(pRID-1).getName()) //If the randomly picked planet already exists in sPlanets then break this loop
				{
					break;
				}

				else if (sPlanets.at(i).getName() != "Default") //If for some reason the current element is NOT default; as a safty precausion in case of weirdness
				{
					i += 1; //Increment the first for loop and break the second
					break;
				}
			}
		}
	}
}

int Game::pPlanets(Player& mPlayer)
{
	pChoice = mp_g.gGTPlanet(sPlanets, mPlayer);
	mp_g.mCScreen(false);

	if (pChoice != -1)
	{
		return pChoice;
	}

	else
	{
		return -1;
	}
}

void Game::getDList()
{
	cout << "The following planets have been listed as destroyed:" << endl;
	for (i = 0; i < gPlanets.size(); i++)
	{
		if (gPlanets.at(i).bPIsDest())
		{
			cout << gPlanets.at(i).getName() << endl;
		}
	}
}

string Game::getDPlanet(int i)
{
	return pDestPlan.at(i).getName();
}

void Game::setSDPlanet(int i, string name)
{
	pDestPlan.at(i).setName(name);
}

/*void Game::setPOwned(string plname)
{

}

void getOPlanets()
{

}*/

void Game::loadPlanet(planetData plData)
{
	gPlanets.push_back(Planet());

	gPlanets.at(gPlanets.size()-1).setPID(plData.pID); //Planet ID
	gPlanets.at(gPlanets.size()-1).setName(plData.pName);
	gPlanets.at(gPlanets.size()-1).setAffil(plData.pAffiliation);
	gPlanets.at(gPlanets.size()-1).setDispo(plData.pDispo);
	gPlanets.at(gPlanets.size()-1).setRace(plData.pRace);
	gPlanets.at(gPlanets.size()-1).setPPOwned(plData.bIsPOwned);
	gPlanets.at(gPlanets.size()-1).setPDest(plData.bIsDestroyed);
	gPlanets.at(gPlanets.size()-1).setEKS(plData.pEKS);
	gPlanets.at(gPlanets.size()-1).setSize(plData.pSize);
	gPlanets.at(gPlanets.size()-1).updatePop(plData.pCPop, "set");
	gPlanets.at(gPlanets.size()-1).updateMPop(plData.pMPop, "set");
}

void Game::pMenu(Player& mPlayer, Planet* gPlanet, Game& mGame_m, string* eResult, Map& m_m, battleProc& bp_m, NPC& mNPC)
{
	bDone = false;

	if (!m_m.shipEncounter(gPlanet->getTDist())) //If no ships are encountered
	{
		while (!bDone)
		{
			pChoice = mp_g.plMenu1();

			switch(pChoice)
			{
			case 1:
				gPHail1(mPlayer, gPlanet);
				break;

			case 2:
				gFABelts(mPlayer, gPlanet);
				break;

			case 3:
				mp_g.hBSStatus_PB(gPlanet,false,0,false,0,true);
				break;

			case 4:
				*eResult = bp_m.pBLoop(mPlayer,gPlanet, mGame_m); //Then contniue to planet.  -1 because of the way generatePlanets generates the planet ID
				bDone = true;
				break;

			case 5:
				*eResult = "No Battle";
				bDone = true;
				break;
			}
		}
	}

	else //Else if ship is encountered
	{
		*eResult = bp_m.sBLoop(mPlayer,gPlanet, false, mGame_m, mNPC); //Load ship encounter events
		bDone = true;
	}
}

void Game::gPHail1(Player& mPlayer, Planet* gPlanet)
{
	//First we need to determine if the planet will attack the player on intilization.  This only happens for planets that belong to entities that are enemies.  Check affiliation of planet against the affinity of that affil with the player relations; if it does not exist create it
	for (i = 0; i <= mPlayer.pRelations.size(); i++)
	{
		if (i == mPlayer.pRelations.size()) //If the player has not yet met whomever is in control of this planet
		{
			mPlayer.addRelation(gPlanet->getAffil(),Random(-20,20)); //Then create the relation
		}

		if (gPlanet->getAffil() == mPlayer.pRelations.at(i).getRName()) //If the player has met whomever is in control of this planet
		{

		}
	}

	string affiliation = gPlanet->getAffil();
	string prace = gPlanet->getRace();

	//Check to see if this target's affiliation has made contact with player before
	int tAffinity = mPlayer.getRStatus(affiliation);

	//get hail response from message proc
	bool bTResponded = mp_g.bHail1(affiliation, prace , tAffinity);

	if (bTResponded)
	{
		pChoice = mp_g.bHail2(tAffinity);

		switch (pChoice)
		{
		case 1:
			if (mp_g.bHail3(tAffinity,pChoice,prace,affiliation))
			{
				//mp.bHInfo(tAffinity,race);
				cout << mp_g.mRMessage(2001) << endl;
				//bITNHostile = true;
			}

			//bITNHostile = true;
			break;

		case 2:
			if (mp_g.bHail3(tAffinity, pChoice, prace, affiliation))
			{
				//mp.bHEnemies(race);
				cout << mp_g.mRMessage(2001) << endl;
				//bITNHostile = true;
			}

			//bITNHostile = true;
			break;

		case 3:
			if (mp_g.bHail3(tAffinity, pChoice, prace, affiliation))
			{
				//mp.bHSurrender(tAffinity,race);
				//bDTSurrender = true;

				cout << mp_g.mRMessage(2001) << endl;
			}

			else
			{
				//bITNHostile = false;
				cout << mp_g.mRMessage(2001) << endl;
			}

			break;

		case 4:
			//pChoice2 = mp.bHTrade();
			//Start trade dialog; created class, start from there after stations re-added
			cout << mp_g.mRMessage(2001) << endl; //Temp until 0.6A
			break;

		case 5:

			//mp.bHNothing();
			//bITNHostile = true;
			cout << mp_g.mRMessage(2001) << endl;
			break;

		default:
			if (mp_g.bHail3(tAffinity,1,prace,affiliation))
			{
				//mp.bHInfo(tAffinity,race);
				cout << mp_g.mRMessage(2001) << endl;
				//bITNHostile = true;
			}

			//bITNHostile = true;
			break;
		}
	}

	/*else
	{
	cout << mp_g.mRMessage(2000) << endl;
	bITNHostile = true;
	}

	if (bDTSurrender) //If enemy surrenders end the battle and break the while loop
	{
	bEnd = true;
	bpResult = "No Battle";
	break;
	}

	else if ((!bDTSurrender) && (mPlayer.getRStatus(gPlanet->getAffil()) <= -23)) //If enemy does not surrender then the battle starts only if suspicious or higher; deals with this causing the game to bug out with erroneous battle
	{
	bEnd = false;
	bPBattle = true;
	}

	if (bDTTrade) //If the planet engaged in trade end the battle and break the loop
	{
	bEnd = true;
	bpResult = "No Battle";
	break;
	}

	else if (bITNHostile) //If the planet did not take a hostile act end the battle and break the loop
	{
	bEnd = true;
	bpResult = "No Battle";
	break;
	}

	else if (bEnd) //If player escaped end the battle and break the loop
	{
	bDPEscape = true;
	bpResult = "Escaped";
	break;
	}*/
}

/*void Game::gPHail2(string race, string affiliation, Player& mPlayer)
{


if (bTResponded)
{
pChoice = mp.bHail2(tAffinity);

switch (pChoice)
{
case 1:
if (mp.bHail3(tAffinity,pChoice,race,affiliation))
{
//mp.bHInfo(tAffinity,race);
cout << mp.mRMessage(2001) << endl;
bITNHostile = true;
}

bITNHostile = true;
break;

case 2:
if (mp.bHail3(tAffinity, pChoice, race, affiliation))
{
//mp.bHEnemies(race);
cout << mp.mRMessage(2001) << endl;
bITNHostile = true;
}

bITNHostile = true;
break;

case 3:
if (mp.bHail3(tAffinity, pChoice, race, affiliation))
{
//mp.bHSurrender(tAffinity,race);
bDTSurrender = true;
}

else
{
bITNHostile = false;
}

break;

case 4:
//pChoice2 = mp.bHTrade();
//Start trade dialog; created class, start from there after stations re-added
cout << mp.mRMessage(2001) << endl; //Temp until 0.6A
break;

case 5:
mp.bHail3(tAffinity,pChoice,race,affiliation);

//mp.bHNothing();
bITNHostile = true;
break;

default:
if (mp.bHail3(tAffinity,1,race,affiliation))
{
//mp.bHInfo(tAffinity,race);
cout << mp.mRMessage(2001) << endl;
bITNHostile = true;
}

bITNHostile = true;
break;
}
}

else
{
cout << mp.mRMessage(2000) << endl;
bITNHostile = true;
}

//response = hResponse
}*/

void Game::gFABelts(Player& mPlayer, Planet* gPlanet)
{
	pChoice = mp_g.gGTABelt(gPlanet);

	if (pChoice != -1)
	{
		mine.mLoop(mPlayer, &gPlanet->belts.at(pChoice));
	}
}

//Station Processing Functions

void Game::createStation(string name, Player& mPlayer)
{
	gStations.push_back(Station());

	pAffRand = Random(1,7);

	if (pAffRand == 1)
	{
		tempAffi = "Earth Alliance";
		tempRace = "Human";
	}

	else if (pAffRand == 2)
	{
		tempAffi = "Sluikan Imperium";
		tempRace = "Sluikan";
	}

	else if (pAffRand == 3)
	{
		tempAffi = "Juslorth Empire";
		tempRace = "Juslorth";
	}

	else if (pAffRand == 4)
	{
		tempAffi = "Visar Collectorate";
		tempRace = "Visar";
	}

	else if (pAffRand == 5)
	{
		tempAffi = "Adent Council";
		tempRace = "Adent";
	}

	else if (pAffRand == 6)
	{
		tempAffi = "Prokl Unity";
		tempRace = "Prokl";
	}

	else if (pAffRand == 7)
	{
		tempAffi = "Groz Hermiteag";
		tempRace = "Groz";
	}

	for (i = 0; i <= mPlayer.pRelations.size(); i++)
	{
		if (i == mPlayer.pRelations.size()) //If relation does not yet exist
		{
			pAffRand = Random(-20, 20); //Create the affinity and then

			mPlayer.addRelation(tempAffi, pAffRand); //Add it

			tempDisp = mPlayer.pRelations.at(i).getAffinityS(); //Get the string version of the affinity
			break;
		}

		else if (tempAffi == mPlayer.pRelations.at(i).getRName()) //Else if the relation does exist
		{
			tempDisp = mPlayer.pRelations.at(i).getAffinityS(); //Get the string version of the affinity
			break;
		}
	}

	stlevel = Random(1,10);

	sslevel = Random(1,20);

	gStations.at(gStations.size()-1).initStation(gStations.size(), name, stlevel, sslevel, 1.0f, tempDisp, tempAffi);
}

void Game::iTStations()
{
	for (i = 0; i < nTStations; i++)
	{
		tStats.push_back(Station());

		tStats.at(i).setName("Default");
	}
}

void Game::rTStations()
{
	tStats.clear();
}

//TODO: Add a way to check gStations to see if the station is already created.

void Game::fStations()
{
	if (tStats.size() == 0)
	{

	}

	else
	{
		for (i = 0; i < tStats.size();) //Loop this this n times until all elements are filled.  Iteration takes place in the second for loop
		{
			nTSPID = Random(1, gPlanets.size());

			nTSSV = Random(1,5);

			switch(nTSSV)
			{
			case 1:
				nTSSuffix = "Alpha";
				break;

			case 2:
				nTSSuffix = "Beta";
				break;

			case 3:
				nTSSuffix = "Chi";
				break;

			case 4:
				nTSSuffix = "Delta";
				break;

			case 5:
				nTSSuffix = "Epsilon";
				break;
			}


			for (i2 = 0; i2 <= tStats.size(); i2++) //Loop through tStats here in order to determine if iteration of first loop is valid
			{
				if (i2 == 0) //Only on the first time through to save cpu cycles
				{
					for (i3 = 0; i3 < gStations.size();i3++) //Checking gStations for already existing stations
					{
						if (gPlanets.at(nTSPID-1).getName() + " " + nTSSuffix == gStations.at(i3).getName()) //If the randomly selected station exists
						{
							tStats.at(i) = gStations.at(i3); //Then set that station to tStats
							break;
						}
					}
				}

				if ((i2 == tStats.size()) && (tStats.at(i).getName() == "Default")) //Only add the planet to sPlanets if no element in sPlanets is the same as gPlanets.at(pRID) and the sPlanets element does not already have a planet in it
				{
					tStats.at(i).setName(gPlanets.at(nTSPID-1).getName() + " " + nTSSuffix);
					i += 1;
					break;
				}

				else if (gPlanets.at(nTSPID-1).getName() + " " + nTSSuffix == tStats.at(i2).getName()) //If the randomly picked planet already exists in sPlanets then break this loop
				{
					break;
				}

				else if (tStats.at(i).getName() != "Default") //This is here for the result of the third for loop.  Since stuff above this but under the third for loop requires non-modified i value, we need to do it here
				{
					i += 1; //iterate i in first for loop
					break;
				}
			}
		}
	}
}

int Game::pStations(Player& mPlayer)
{
	pChoice = mp_g.gGTStation(tStats, mPlayer, this);

	if (pChoice != -1)
	{
		return pChoice;
	}

	else
	{
		return -1;
	}
}


void Game::sRepair(Player& mPlayer, Station& stat_g)
{
	cout << mp_g.mRMessage(2009) << endl;
	mp_g.mCScreen(true);

	pChoice = mp_g.sDRMenu1(mPlayer);

	if (pChoice != 5)
	{
		for (i = 0; i <= mPlayer.pRelations.size(); i++) //Get affinity
		{
			if (i == mPlayer.pRelations.size()) //Always check to see if a realtion does not already exist first and add it if it does not
			{
				mPlayer.addRelation(stat_g.getAffil(), Random(-20,20));

				pAffin = mPlayer.pRelations.at(mPlayer.pRelations.size()-1).getAffinity(); //Do this now
				break;
			}

			else if (mPlayer.pRelations.at(i).getRName() == stat_g.getAffil())
			{
				pAffin = mPlayer.pRelations.at(i).getAffinity();
				break;
			}
		}

		//Set Up CPP Here
		if(pAffin >= 77)
		{
			sRCPPX = 2;
			sRCPPR = 1;
			sRCPPDi = 1;
			sRCPPD = 3;
		}

		else if ((pAffin <= 74) && (pAffin >= 52))
		{
			sRCPPX = 4;
			sRCPPR = 2;
			sRCPPDi = 1;
			sRCPPD = 7;
		}

		else if ((pAffin <= 51) && (pAffin >= 26))
		{
			sRCPPX = 5;
			sRCPPR = 3;
			sRCPPDi = 3;
			sRCPPD = 8;
		}

		else if ((pAffin <= 25) && (pAffin >= 1))
		{
			sRCPPX = 8;
			sRCPPR = 5;
			sRCPPDi = 4;
			sRCPPD = 10;
		}

		else if (pAffin == 0)
		{
			sRCPPX = 10;
			sRCPPR = 6;
			sRCPPDi = 7;
			sRCPPD = 11;
		}

		else if ((pAffin  <= -1) && (pAffin >= -22))
		{
			sRCPPX = 13;
			sRCPPR = 9;
			sRCPPDi = 8;
			sRCPPD = 12;
		}

		else if ((pAffin <= -23) && (pAffin >= -48))
		{
			sRCPPX = 18;
			sRCPPR = 11;
			sRCPPDi = 10;
			sRCPPD = 16;
		}

		else if ((pAffin <= -49) && (pAffin >= -74))
		{
			sRCPPX = 22;
			sRCPPR = 16;
			sRCPPDi = 14;
			sRCPPD = 20;
		}

		else if (pAffin <= -75)
		{
			sRCPPX = 28;
			sRCPPR = 19;
			sRCPPDi = 20;
			sRCPPD = 35;
		}

		if (pChoice == 1)
		{
			bRepair = mp_g.sDRMenu2(pAffin, mPlayer, sRCPPX, sRCPPR, sRCPPDi, sRCPPD);

			if (bRepair)
			{
				//Calc percent of armor damaged then round it
				dPerc = (mPlayer.ship.getSArmor() / mPlayer.ship.getSMArmor()) * 100;

				dPerc_R = floor(dPerc * 100 + 0.5) / 100;
				dPerc_I = dPerc_R;

				if (dPerc_R >= dPerc_I + 0.5) //If the value after the decimal is equal to or greater then truncated dPerc_R +0.5
				{
					dPerc_I += 1; //then round up
				}

				if (dPerc_I <= 0) //In case of fully depleted armor
				{
					dPerc_I = 100;
				}

				//Check to see if the player has the resources to repair
				if (mPlayer.getXarn () < sRCPPX*dPerc_I || mPlayer.getRubies () < sRCPPR*dPerc_I || mPlayer.getDia () < sRCPPDi*dPerc_I || mPlayer.getDrac() < sRCPPD*dPerc_I)
				{
					cout << mp_g.mRMessage(2013) << endl;
					cout << endl;
				}

				else
				{
					mPlayer.updateXarn(sRCPPX*dPerc_I, "sub");
					mPlayer.updateRubies(sRCPPR*dPerc_I, "sub");
					mPlayer.updateDia(sRCPPDi*dPerc_I, "sub");
					mPlayer.updateDrac(sRCPPD*dPerc_I, "sub");

					mPlayer.ship.updateSArmor(mPlayer.ship.getSMArmor(),"set");
				}
			}
		}

		else if (pChoice == 2)
		{
			bRepair = mp_g.sDRMenu3(pAffin, mPlayer, sRCPPX, sRCPPR, sRCPPDi, sRCPPD);

			if (bRepair)
			{
				//Calc percent of hull damaged then round it
				dPerc = (mPlayer.ship.getSHull() / mPlayer.ship.getSMHull()) * 100;

				dPerc_R = floor(dPerc * 100 + 0.5) / 100;
				dPerc_I2 = dPerc_R;

				if (dPerc_R >= dPerc_I2 + 0.5) //If the value after the decimal is equal to or greater then truncated dPerc_R +0.5
				{
					dPerc_I2 += 1; //then round up
				}

				//Check to see if the player has the resources to repair
				if (mPlayer.getXarn () < sRCPPX*dPerc_I2 || mPlayer.getRubies () < sRCPPR*dPerc_I2 || mPlayer.getDia () < sRCPPDi*dPerc_I2 || mPlayer.getDrac() < sRCPPD*dPerc_I2)
				{
					cout << mp_g.mRMessage(2013) << endl;
					cout << endl;
				}

				else
				{
					mPlayer.updateXarn(sRCPPX*dPerc_I2, "sub");
					mPlayer.updateRubies(sRCPPR*dPerc_I2, "sub");
					mPlayer.updateDia(sRCPPDi*dPerc_I2, "sub");
					mPlayer.updateDrac(sRCPPD*dPerc_I2, "sub");

					mPlayer.ship.updateSHull(mPlayer.ship.getSMHull(),"set");
				}
			}
		}

		else if (pChoice == 3)
		{
			bRepair = mp_g.sDRMenu4(pAffin, mPlayer, sRCPPX, sRCPPR, sRCPPDi, sRCPPD);

			if (bRepair)
			{
				//Calc percent of armor damaged then round it
				dPerc = (mPlayer.ship.getSArmor() / mPlayer.ship.getSMArmor()) * 100;

				dPerc_R = floor(dPerc * 100 + 0.5) / 100;
				dPerc_I = dPerc_R;

				if (dPerc_R >= dPerc_I + 0.5) //If the value after the decimal is equal to or greater then truncated dPerc_R +0.5
				{
					dPerc_I += 1; //then round up
				}

				if (dPerc_I <= 0) //In case of fully depleted armor
				{
					dPerc_I = 100;
				}

				//Calc percent of hull damaged then round it
				dPerc = (mPlayer.ship.getSHull() / mPlayer.ship.getSMHull()) * 100;

				dPerc_R = floor(dPerc * 100 + 0.5) / 100;
				dPerc_I2 = dPerc_R;

				if (dPerc_R >= dPerc_I2 + 0.5) //If the value after the decimal is equal to or greater then truncated dPerc_R +0.5
				{
					dPerc_I2 += 1; //then round up
				}

				dPerc_T = dPerc_I + dPerc_I2;

				//Check to see if the player has the resources to repair
				if (mPlayer.getXarn () < sRCPPX*dPerc_T || mPlayer.getRubies () < sRCPPR*dPerc_T || mPlayer.getDia () < sRCPPDi*dPerc_T || mPlayer.getDrac() < sRCPPD*dPerc_T)
				{
					cout << mp_g.mRMessage(2024) << endl;
					cout << endl;
				}

				else
				{
					mPlayer.updateXarn(sRCPPX*dPerc_T, "sub");
					mPlayer.updateRubies(sRCPPR*dPerc_T, "sub");
					mPlayer.updateDia(sRCPPDi*dPerc_T, "sub");
					mPlayer.updateDrac(sRCPPD*dPerc_T, "sub");

					mPlayer.ship.updateSArmor(mPlayer.ship.getSMArmor(),"set");
					mPlayer.ship.updateSHull(mPlayer.ship.getSMHull(),"set");
				}
			}
		}

		else if (pChoice == 4)
		{
			mPlayer.ship.sWSCenter(mPlayer);
		}
	}
}

void Game::bClone(Player& mPlayer, Station& stat_g)
{
	pChoice = mp_g.sBClone();

	if (pChoice != 0)
	{
		sMBClone(mPlayer, stat_g, pChoice);
	}
}

void Game::useClone(Player& mPlayer, int sID, int sIID, int iID)
{
	//First remove the clone from the station inventory slot
	gStations.at(sID).removeItem(sIID, 1);

	//Then Remove CEXP; hardcode based now but will as for range in later versions in an ini file
	if (iID == 1) //Most primitive clone; take off 12% of CXP
	{
		oldCXPTNL = mPlayer.calcOCXPTNL(mPlayer.getCELvl());
		mPlayer.updateCEXP(mPlayer.getCEXP()*0.12,"sub");

		if (oldCXPTNL > mPlayer.getCEXP()) //If using the clone cause the player's cEXP to drop below the level required for the player's current level
		{
			mPlayer.cELDown(); //Then de-level the player
			mPlayer.setCXPTNL(oldCXPTNL); //And set cexp to next level to the pervious level's value
		}
	}

	else if (iID == 2) //Most primitive clone; take off 12% of CXP
	{
		oldCXPTNL = mPlayer.calcOCXPTNL(mPlayer.getCELvl());
		mPlayer.updateCEXP(mPlayer.getCEXP()*0.10,"sub");

		if (oldCXPTNL > mPlayer.getCEXP()) //If using the clone cause the player's cEXP to drop below the level required for the player's current level
		{
			mPlayer.cELDown(); //Then de-level the player
			mPlayer.setCXPTNL(oldCXPTNL); //And set cexp to next level to the pervious level's value
		}
	}

	else if (iID == 3) //Most primitive clone; take off 12% of CXP
	{
		oldCXPTNL = mPlayer.calcOCXPTNL(mPlayer.getCELvl());
		mPlayer.updateCEXP(mPlayer.getCEXP()*0.07,"sub");

		if (oldCXPTNL > mPlayer.getCEXP()) //If using the clone cause the player's cEXP to drop below the level required for the player's current level
		{
			mPlayer.cELDown(); //Then de-level the player
			mPlayer.setCXPTNL(oldCXPTNL); //And set cexp to next level to the pervious level's value
		}
	}
}

void Game::sMOffice(Player& mPlayer)
{
	pChoice = mp_g.sMOMenu1();

	switch(pChoice)
	{
	case 1:
		pChoice = mp_g.sMOMenu2(&mID, mPlayer);

		if ((pChoice != 0) && (mID != 0))
		{
			startMission(mPlayer);
		}

		break;

	case 2:
		pChoice = mp_g.sMOMenu3(mPlayer);

		if ((pChoice != 0) && (mID != 0))
		{
			completeMission(mPlayer);
		}

		break;

	default:
		//Add exit message
		break;
	}
}

void Game::sBOffice(Player& mPlayer)
{
	pChoice = mp_g.sBOMenu1();

	switch(pChoice)
	{
	case 1:
		pChoice = mp_g.sBOMenu2(&mID, mPlayer);

		if ((pChoice != 0) && (mID != 0))
		{
			startMission(mPlayer);
		}

		break;

	case 2:
		pChoice = mp_g.sBOMenu3(mPlayer);

		if ((pChoice != 0) && (mID != 0))
		{
			completeMission(mPlayer);
		}

		break;

	default:
		//Add exit message
		break;
	}
}

void Game::sEAFOffice(Player& mPlayer)
{
	pChoice = mp_g.sEAFOMenu1();

	switch(pChoice)
	{
	case 1:
		pChoice = mp_g.sEAFOMenu2(&mID, mPlayer);

		if ((pChoice != 0) && (mID != 0))
		{
			startMission(mPlayer);
		}

		break;

	case 2:
		pChoice = mp_g.sEAFOMenu3(mPlayer);

		if ((pChoice != 0) && (mID != 0))
		{
			completeMission(mPlayer);
		}

		break;

	default:
		//Add exit message
		break;
	}
}

void Game::startMission(Player& mPlayer)
{
	gMStart = mp_g.sSMission(mID);

	if (gMStart)
	{
		mPlayer.addMission(mID);
	}
}

void Game::completeMission(Player& mPlayer)
{
	mID = mp_g.sMOMenu3(mPlayer);

	if (mID != 0)
	{
		ds_g.rData("Mission_Data","select from", mPlayer.pMissions.at(mID).getMID());

		if (ds_g.getMType() == "Mining")
		{
			if ((ds_g.getMRR() <= mPlayer.getRubies()) && (ds_g.getMDiR() <= mPlayer.getDia()) && (ds_g.getMDR() <= mPlayer.getDrac()) && (ds_g.getMLR() <= mPlayer.getLith()) && (ds_g.getMPlR() <= mPlayer.getPlat()) && (ds_g.getMUR() <= mPlayer.getUra()) && (ds_g.getMPR() <= mPlayer.getPlut()))
			{
				cout << mp_g.mRMessage(2013) << endl;

				//These are hardcoded for now but will be based on station values and exchange rates in 0.6a
				xarnMultiplier = Random(1.5f,3.5f);
				xarnReward = 0;

				if (ds_g.getMRR() != 0)
				{
					xarnReward += xarnMultiplier * ds_g.getMRR();
					mPlayer.updateRubies(ds_g.getMRR(), "sub");
				}

				if (ds_g.getMDiR() != 0)
				{
					xarnReward += xarnMultiplier * ds_g.getMDiR();
					mPlayer.updateDia(ds_g.getMDiR(), "sub");
				}

				if (ds_g.getMDR() != 0)
				{
					xarnReward += xarnMultiplier * ds_g.getMDR();
					mPlayer.updateDrac(ds_g.getMDR(), "sub");
				}

				if (ds_g.getMLR() != 0)
				{
					xarnReward += xarnMultiplier * ds_g.getMLR();
					mPlayer.updateLith(ds_g.getMLR(), "sub");
				}

				if (ds_g.getMPlR() != 0)
				{
					xarnReward += xarnMultiplier * ds_g.getMPlR();
					mPlayer.updatePlat(ds_g.getMPlR(), "sub");
				}

				if (ds_g.getMUR() != 0)
				{
					xarnReward += xarnMultiplier * ds_g.getMUR();
					mPlayer.updateUra(ds_g.getMUR(), "sub");
				}

				if (ds_g.getMPR() != 0)
				{
					xarnReward += xarnMultiplier * ds_g.getMPR();
					mPlayer.updatePlut(ds_g.getMPR(), "sub");
				}

				mPlayer.updateXarn(xarnReward, "add");

				mPlayer.completeMission(mID);
			}

			else
			{
				cout << mp_g.mRMessage(2014) << endl;
			}
		}

		else if (ds_g.getMType() == "Transport")
		{

		}

		else if (ds_g.getMType() == "Stock")
		{

		}

		else if (ds_g.getMType() == "Survey")
		{

		}

		else if (ds_g.getMType() == "Bounty")
		{
			if (mPlayer.getBOKills() > 0)
			{
				cout << mp_g.mRMessage(2015) << endl;

				mPlayer.updateXarn(ds_g.getMBounty(), "add");
			}

			else
			{
				cout << mp_g.mRMessage(2016) << endl;
			}
		}

		else if (ds_g.getMType() == "Main")
		{

		}

		else if (ds_g.getMType() == "EA")
		{

		}
	}
}

void Game::sPub(Player& mPlayer)
{
	cout << mp_g.mRMessage(2001) << endl;
}

void Game::sDepart(Player& mPlayer, Station& stat_g)
{
	cout << mp_g.mRMessage(14) << stat_g.getName() << ".  " << mp_g.mRMessage(15) << endl;
	gStations.at(csPos) = stat_g; //Update vector elemment with new data from stat instance
}

void Game::sMenu(Player& mPlayer, Station& stat_g)
{
	if (stat_g.getSID() == 0)
	{
		csPos = 0; //set position in cStations for updating vector element later on
	}

	else
	{
		csPos = stat_g.getSID() - 1; //set position in cStations for updating vector element later on
	}

	pChoice == 0; //For spacing check

	while (!sLeave) //Start Station Loop
	{
		if (pChoice != 0)
		{
			cout << endl;
		}

		pChoice = mp_g.sMMenu(stat_g); //Create main station menu

		switch (pChoice) //Start Station Menu
		{
		case 1:
			sRepair(mPlayer, stat_g);
			break;

		case 2: //Classification

			sMLoop1(mPlayer, stat_g); //Start Market Menu
			break;

		case 3: //Pub
			sPub(mPlayer);
			break;

		case 4: //Bounty Office
			sBOffice(mPlayer);
			break;

		case 5: //Earth Alliance Field Office
			sEAFOffice(mPlayer);
			break;

		case 6:
			bClone(mPlayer, stat_g);
			break;

		case 7:

			cout << mp_g.mRMessage(2001) << endl;

			//Disable the casino for now; will complete for V0.6A
			//sCasino(mPlayer);
			break;

		case 8:
			sSItem(mPlayer, stat_g, false);
			break;

		case 9:
			sGItem(mPlayer, stat_g);
			break;

		case 10:
			sSFitting(mPlayer, stat_g);
			break;

		case 11:
			sStorage(stat_g);
			break;

		case 12: //Leave Station
			sDepart(mPlayer,stat_g);
			sLeave = true;
			break;

		default: //Repair Dock
			sRepair(mPlayer,stat_g);
			break;
		} //End Station Menu
	} //End Station Loop

	sLeave = false;
}

void Game::sMLoop1(Player& mPlayer, Station& stat_g)
{
	pChoice = mp_g.sMBS();

	switch(pChoice)
	{
	case 1:
		sMLoop2A1(mPlayer,stat_g);
		break;

	case 2:
		sMLoop2B1(mPlayer,stat_g);
		break;

	default:
		break;
	}
}

//Buy
void Game::sMLoop2A1(Player& mPlayer, Station& stat_g)
{
	sMMenu = true; //Make sure this is true

	while (sMMenu) //Start Market Loop
	{		
		pChoice = mp_g.sMMenu1A();

		if (pChoice == 1 || pChoice == 3)
		{
			cCode = mp_g.sMCMenu(mPlayer); //Get ship classification
		}

		switch (pChoice)
		{
		case 1: //Weapons
			sWMLoopB(mPlayer, stat_g); //Start Weapon Menu
			break;

		case 2: //Ships
			sSMLoopB(mPlayer, stat_g);
			break;

		case 3: //Equipment
			sEMLoopB(mPlayer, stat_g);
			break;

		default: //Back to staion menu
			sMMenu = false;
			break;
		}
	} //End Market Loop
}

void Game::sWMLoopB(Player& mPlayer, Station& stat_g)
{
	iType = "Weapon";
	bContinue = true; //Make sure that this is true

	while (bContinue) //Start Weapon Menu loop
	{
		pChoice = mp_g.sMMenu2();  //Return a weapon type

		switch (pChoice)
		{
		case 1: //Lasers
			iCode = mp_g.sWLMenu(cCode); //Choose an item

			if (iCode != 0) //Only proceed if a selection was made
			{

				iType2 = getIType(); //Get type of weapon

				sMBuy = mp_g.sMIInfo(iCode,iType,iType2, mPlayer, stat_g, 1); //Print out item information


				if (sMBuy) //If player wants to buy
				{
					sMPurchase(mPlayer, stat_g);
				}
			}

			break;

		case 2:
			iCode = mp_g.sWMMenu(cCode); //Choose an item

			if (iCode != 0) //Only proceed if a selection was made
			{

				iType2 = getIType(); //Get type of weapon

				sMBuy = mp_g.sMIInfo(iCode,iType,iType2, mPlayer, stat_g, 1); //Print out item information


				if (sMBuy) //If player wants to buy
				{
					sMPurchase(mPlayer, stat_g);
				}
			}

			break;

		case 3:
			iCode = mp_g.sWBMenu(cCode); //Choose an item

			if (iCode != 0) //Only proceed if a selection was made
			{

				iType2 = getIType(); //Get type of weapon

				sMBuy = mp_g.sMIInfo(iCode,iType,iType2, mPlayer, stat_g, 1); //Print out item information


				if (sMBuy) //If player wants to buy
				{
					sMPurchase(mPlayer, stat_g);
				}
			}

			break;

		case 4:
			iCode = mp_g.sWRMenu(cCode); //Choose an item

			if (iCode != 0) //Only proceed if a selection was made
			{

				iType2 = getIType(); //Get type of weapon

				sMBuy = mp_g.sMIInfo(iCode,iType,iType2, mPlayer, stat_g, 1); //Print out item information


				if (sMBuy) //If player wants to buy
				{
					sMPurchase(mPlayer, stat_g);
				}
			}

			break;

		case 5:
			iCode = mp_g.sWHMenu(cCode); //Choose an item

			if (iCode != 0) //Only proceed if a selection was made
			{

				iType2 = getIType(); //Get type of weapon

				sMBuy = mp_g.sMIInfo(iCode,iType,iType2, mPlayer, stat_g, 1); //Print out item information


				if (sMBuy) //If player wants to buy
				{
					sMPurchase(mPlayer, stat_g);
				}
			}

			break;

		case 6:
			bContinue = false;
			break;
		}
	} //End Weapon Menu Loop
}

void Game::sSMLoopB(Player& mPlayer, Station& stat_g)
{
	iType = "Ship";
	bContinue = true; //Make sure that this is true

	while (bContinue) //Start Weapon Menu loop
	{
		iCode = mp_g.sMMenu8(); //Choose a ship

		if (iCode != 0) //Only proceed if a selection was made
		{

			iType2 = ""; //Not needed for this item type

			sMBuy = mp_g.sMIInfo(iCode,iType,iType2, mPlayer, stat_g, 1); //Print out item information


			if (sMBuy) //If player wants to buy
			{
				sMPurchase(mPlayer, stat_g);
			}
		}

		else
		{
			bContinue = false;
		}
	} //End Weapon Menu Loop
}

void Game::sEMLoopB(Player& mPlayer, Station& stat_g)
{
	iType = "Equipment";
	bContinue = true; //Make sure that this is true

	while (bContinue) //Start Weapon Menu loop
	{
		pChoice = mp_g.sMMenu2();  //Return a weapon type

		switch (pChoice)
		{
		case 1: //Items
			iCode = mp_g.sWLMenu(cCode); //Choose an item

			if (iCode != 0) //Only proceed if a selection was made
			{

				iType2 = "Item"; //Get type of weapon

				sMBuy = mp_g.sMIInfo(iCode,iType,iType2, mPlayer, stat_g, 1); //Print out item information


				if (sMBuy) //If player wants to buy
				{
					sMPurchase(mPlayer, stat_g);
				}
			}

			break;

		case 2: //Modules
			iCode = mp_g.sMMenu9(cCode); //Choose a module

			if (iCode != 0) //Only proceed if a selection was made
			{

				iType2 = "Module"; //Get type of weapon

				sMBuy = mp_g.sMIInfo(iCode,iType,iType2, mPlayer, stat_g, 1); //Print out item information


				if (sMBuy) //If player wants to buy
				{
					sMPurchase(mPlayer, stat_g);
				}
			}

			break;

		case 3: //Planetary Equipment - split into defense and shield
			iCode = mp_g.sWBMenu(cCode); //Choose an item

			if (iCode != 0) //Only proceed if a selection was made
			{

				iType2 = "PEquip"; //Get type of weapon

				sMBuy = mp_g.sMIInfo(iCode,iType,iType2, mPlayer, stat_g, 1); //Print out item information


				if (sMBuy) //If player wants to buy
				{
					sMPurchase(mPlayer, stat_g);
				}
			}

			break;

		case 5: //Upgrades
			iCode = mp_g.sWHMenu(cCode); //Choose an item

			if (iCode != 0) //Only proceed if a selection was made
			{

				iType2 = "Upgrades"; //Get type of weapon

				sMBuy = mp_g.sMIInfo(iCode,iType,iType2, mPlayer, stat_g, 1); //Print out item information


				if (sMBuy) //If player wants to buy
				{
					sMPurchase(mPlayer, stat_g);
				}
			}

			break;

		case 6:
			bContinue = false;
			break;
		}
	} //End Weapon Menu Loop
}

void Game::sMBClone(Player& mPlayer, Station& stat_g, int iID)
{
	iCode = iID; //Set the class member here, no need to pass the value any further

	sMBuy = mp_g.sMIInfo(iCode,"Equipment","Clone", mPlayer, stat_g, 1); //Print out item information

	if (sMBuy)
	{
		//Since the player has already decided to buy the item call sMPurchase
		iType = "Equipment";
		iType2 = "Clone";
		sMPurchase(mPlayer, stat_g);
	}
}

void Game::sRMLoopB(Player& mPlayer, Station& stat_g)
{
	iType = "Resource";
	bContinue = true; //Make sure that this is true

	while (bContinue) //Start Weapon Menu loop
	{
		iCode = mp_g.sMBRes(); //Choose a resource

		if (iCode != 0) //Only proceed if a selection was made
		{

			iType2 = ""; //Not needed for this item type

			amount = mp_g.sMBAmount(iCode, iType, mPlayer, stat_g); //Get player to choose the number of items to buy

			sMBuy = mp_g.sMIInfo(iCode,iType,iType2, mPlayer, stat_g, amount); //Print out item information


			if (sMBuy) //If player wants to buy
			{
				sMPurchase(mPlayer, stat_g);
			}
		}

		else
		{
			bContinue = false;
		}
	}
}

void Game::sOMLoopB(Player& mPlayer, Station& stat_g)
{
	iType = "Ore";
	bContinue = true; //Make sure that this is true

	while (bContinue) //Start Weapon Menu loop
	{
		iCode = mp_g.sMBOre(); //Choose an ore

		if (iCode != 0) //Only proceed if a selection was made
		{

			iType2 = ""; //Not needed for this item type

			amount = mp_g.sMBAmount(iCode, iType, mPlayer, stat_g); //Get player to choose the number of items to buy

			sMBuy = mp_g.sMIInfo(iCode,iType,iType2, mPlayer, stat_g, amount); //Print out item information


			if (sMBuy) //If player wants to buy
			{
				sMPurchase(mPlayer, stat_g);
			}
		}

		else
		{
			bContinue = false;
		}
	}
}


void Game::sMPurchase(Player& mPlayer, Station& stat_g)
{
	if (iType == "Weapon")
	{
		ds_g.rData("Weapon_Data","select from",iCode);

		//If weapon requires the resource remove that amount of resources from the playuer
		if (ds_g.getWXC() != 0)
		{
			mPlayer.updateXarn(ds_g.getWXC()* stat_g.getCMulti(), "sub");
		}

		if (ds_g.getWRC() != 0)
		{
			mPlayer.updateRubies(ds_g.getWRC()* stat_g.getCMulti(), "sub");
		}

		if (ds_g.getWDiC() != 0)
		{
			mPlayer.updateDia(ds_g.getWDiC()* stat_g.getCMulti(), "sub");
		}

		if (ds_g.getWDC() != 0)
		{
			mPlayer.updateDrac(ds_g.getWDC()* stat_g.getCMulti(), "sub");
		}

		if (ds_g.getWLC() != 0)
		{
			mPlayer.updateLith(ds_g.getWLC()* stat_g.getCMulti(), "sub");
		}

		if (ds_g.getWPC() != 0)
		{
			mPlayer.updatePlut(ds_g.getWPC()* stat_g.getCMulti(), "sub");
		}

		if (ds_g.getWUC() != 0)
		{
			mPlayer.updateUra(ds_g.getWUC()* stat_g.getCMulti(), "sub");
		}

		if (ds_g.getWNWC() != 0)
		{
			mPlayer.updateNWaste(ds_g.getWNWC()* stat_g.getCMulti(), "sub");
		}

		mp_g.mRMessage(2007);
		sSItem(mPlayer, stat_g, true); //Store the weapon
	}

	else if (iType == "Ship")
	{
		ds_g.rData("Ship_Data","select from",iCode);

		//If ship requires the resource remove that amount of resources from the player
		if (ds_g.getSXC() != 0)
		{
			mPlayer.updateXarn(ds_g.getSXC()* stat_g.getCMulti(), "sub");
		}

		if (ds_g.getSRC() != 0)
		{
			mPlayer.updateRubies(ds_g.getSRC()* stat_g.getCMulti(), "sub");
		}

		if (ds_g.getSDiC() != 0)
		{
			mPlayer.updateDia(ds_g.getSDiC()* stat_g.getCMulti(), "sub");
		}

		if (ds_g.getSDC() != 0)
		{
			mPlayer.updateDrac(ds_g.getSDC()* stat_g.getCMulti(), "sub");
		}

		if (ds_g.getWPC() != 0)
		{
			mPlayer.updatePlut(ds_g.getSPC()* stat_g.getCMulti(), "sub");
		}

		if (ds_g.getWUC() != 0)
		{
			mPlayer.updateUra(ds_g.getSUC()* stat_g.getCMulti(), "sub");
		}

		mp_g.mRMessage(2007);
		sSItem(mPlayer, stat_g, true);
	}

	else if (iType == "Equipment")
	{
		if (iType2 == "PShield" || iType2 == "PDefense" || iType2 == "Clone")
		{
			ds_g.rData("Equipment_Data","select from",iCode);

			//If item requires the resource remove that amount of resources from the playuer

			if (iType2 == "Clone")
			{
				if (ds_g.getCXC() != 0) //If the item is a clone use a different cost calculation
				{
					sTax = 0.25f; //Clone tax

					sTCost = ds_g.getCXC() * stat_g.getCMulti(); //Calculate CMulti cost
					sPTax = sTCost * sTax; //Calculate additional cost from tax

					sTPCost = sTCost + sPTax; //Calculate total cost

					mPlayer.updateXarn(sTPCost, "sub");
				}

				if (ds_g.getCRC() != 0)
				{
					mPlayer.updateRubies(ds_g.getCRC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getCDiC() != 0)
				{
					mPlayer.updateDia(ds_g.getCDiC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getCDC() != 0)
				{
					mPlayer.updateDrac(ds_g.getCDC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getCLC() != 0)
				{
					mPlayer.updateLith(ds_g.getCLC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getCPC() != 0)
				{
					mPlayer.updatePlut(ds_g.getCPC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getCUC() != 0)
				{
					mPlayer.updateUra(ds_g.getCUC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getCNWC() != 0)
				{

					mPlayer.updateNWaste(ds_g.getCNWC()* stat_g.getCMulti(), "sub");
				}
			}

			else if (iType2 == "PShield")
			{
				if (ds_g.getPSXC() != 0)
				{
					mPlayer.updateXarn(ds_g.getPSXC() * stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPSRC() != 0)
				{
					mPlayer.updateRubies(ds_g.getPSRC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPSDiC() != 0)
				{
					mPlayer.updateDia(ds_g.getPSDiC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPSDC() != 0)
				{
					mPlayer.updateDrac(ds_g.getPSDC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPSLC() != 0)
				{
					mPlayer.updateLith(ds_g.getPSLC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPSPC() != 0)
				{
					mPlayer.updatePlut(ds_g.getPSPC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPSUC() != 0)
				{
					mPlayer.updateUra(ds_g.getPSUC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPSNWC() != 0)
				{

					mPlayer.updateNWaste(ds_g.getPSNWC()* stat_g.getCMulti(), "sub");
				}
			}

			else if (iType2 == "PDefense")
			{
				if (ds_g.getPDXC() != 0)
				{
					mPlayer.updateXarn(ds_g.getPDXC() * stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPDRC() != 0)
				{
					mPlayer.updateRubies(ds_g.getPDRC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPDDiC() != 0)
				{
					mPlayer.updateDia(ds_g.getPDDiC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPDDC() != 0)
				{
					mPlayer.updateDrac(ds_g.getPDDC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPDLC() != 0)
				{
					mPlayer.updateLith(ds_g.getPDLC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPDPC() != 0)
				{
					mPlayer.updatePlut(ds_g.getPDPC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPDUC() != 0)
				{
					mPlayer.updateUra(ds_g.getPDUC()* stat_g.getCMulti(), "sub");
				}

				if (ds_g.getPDNWC() != 0)
				{

					mPlayer.updateNWaste(ds_g.getPDNWC()* stat_g.getCMulti(), "sub");
				}
			}

			mp_g.mRMessage(2007);
			sSItem(mPlayer, stat_g, true); //Store the item; temporary and only for now as only items are clones.  Eventually clones will recieve their own storage facilities
		}
	}

	else if (iType2 == "Resource")
	{
		ds_g.rData("Resource", "select from" , iCode);

		if (ds_g.getResXCost() > 0)
		{
			mPlayer.updateXarn(((ds_g.getResXCost() * amount) * stat_g.getCMulti()), "sub");
		}

		//Store resource
		sSItem(mPlayer, stat_g,true);
	}

	else if (iType2 == "Ore")
	{
		ds_g.rData("Ore", "select from" , iCode);

		if (ds_g.getOXCost() > 0)
		{
			mPlayer.updateXarn(((ds_g.getOXCost() * amount) * stat_g.getCMulti()), "sub");
		}

		//Store ore
		sSItem(mPlayer, stat_g, true);
	}
}

//Sell
void Game::sMLoop2B1(Player& mPlayer, Station& stat_g)
{
	sMMenu2 = true;

	while(sMMenu2)
	{
		pChoice = mp_g.sMMenu1B1();

		switch(pChoice)
		{
		case 1:
			iType = "Not Ship";
			sMLoop3A1(mPlayer, stat_g);
			break;

		case 2:
			iType = "Ship";
			sMLoop3A2(mPlayer, stat_g);
			break;

		default:
			sMMenu2 = false;
			break;
		}
	}
}

void Game::sMLoop3A1(Player& mPlayer, Station& stat_g)
{
	pChoice = mp_g.sMMenu1B2();

	switch(pChoice)
	{
	case 1:
		sMLoop4A(mPlayer, stat_g, true, false);
		break;

	case 2:
		sMLoop4A(mPlayer, stat_g, false, true);
		break;
	}
}

void Game::sMLoop3A2(Player& mPlayer, Station& stat_g)
{
	pChoice = mp_g.sMMenu1B2();

	switch(pChoice)
	{
	case 1:
		sMLoop4B(mPlayer, stat_g, true, false);
		break;

	case 2:
		sMLoop4B(mPlayer, stat_g, false, true);
		break;
	}
}

void Game::sMLoop4A(Player& mPlayer, Station& stat_g, bool ship, bool station)
{
	if (ship)
	{
		pChoice = mp_g.sMMenu1C1(mPlayer, iType);

		if (pChoice != -1)
		{
			sSell(mPlayer, stat_g, true, false, false, pChoice);
		}
	}

	else if (station)
	{
		pChoice = mp_g.sMMenu1C2(stat_g,iType);

		if (pChoice != -1)
		{
			sSell(mPlayer, stat_g, false, true, false, pChoice);
		}
	}
}

void Game::sMLoop4B(Player& mPlayer, Station& stat_g, bool ship, bool station)
{
	if (ship)
	{
		pChoice = mp_g.sMMenu1C1(mPlayer, iType);

		if (pChoice != -1)
		{
			sSell(mPlayer, stat_g, true, false, true, pChoice);
		}
	}

	else if (station)
	{
		pChoice = mp_g.sMMenu1C2(stat_g,iType);

		if (pChoice != -1)
		{
			sSell(mPlayer, stat_g, false, true, true, pChoice);
		}
	}
}

void Game::sSell(Player& mPlayer, Station& stat_g, bool bIOShip, bool bIOStation, bool bIsShip, int slot)
{
	if (bIOShip) //Item to sell is on player ship
	{
		if (!bIsShip) //Item to sell is not a ship
		{
			if (mPlayer.ship.sCargo.at(slot).getIAmount() > 1) //If there is a stack of items in the slot marked for sale, ask player for number of items to sell
			{
				amount = mp_g.mSSIAmount(mPlayer.ship.sCargo.at(slot).getIAmount());
			}

			else //Else set amount to 1
			{
				amount = 1;
			}

			pChoice  = mp_g.mSSIConfirm(amount, mPlayer.ship.sCargo.at(slot).getIID(), mPlayer.ship.sCargo.at(slot).getIType()); //Make player confirm that they want to sell item(s)

			if (pChoice == 0)
			{
				cout << mp_g.mRMessage(2043) << endl;
			}

			else
			{
				cout << mp_g.mRMessage(2044) << endl;

				if (mPlayer.ship.sCargo.at(slot).getIType() == "Weapon")
				{
					ds_g.rData(mPlayer.ship.sCargo.at(slot).getIType(), "select from", mPlayer.ship.sCargo.at(slot).getIID());

					//For now item sales will give 25% of total cost back, hard.  Values will shift in later versions based on the CMulti, affinity, and difficuly

					mPlayer.updateXarn(((ds_g.getWXC() * 0.25f) * amount), "add");
					mPlayer.updateRubies(((ds_g.getWRC() * 0.25f) * amount), "add");
					mPlayer.updateDia(((ds_g.getWDiC() * 0.25f) * amount), "add");
					mPlayer.updateDrac(((ds_g.getWDC() * 0.25f) * amount), "add");
					mPlayer.updateLith(((ds_g.getWLC() * 0.25f) * amount), "add");
					mPlayer.updateUra(((ds_g.getWUC() * 0.25f) * amount), "add");
					mPlayer.updatePlut(((ds_g.getWPC() * 0.25f) * amount), "add");

					mPlayer.ship.updateCIAmount(slot, amount, "sub", false, "");

					cout << "Sale of " <<  amount << " units of " << ds_g.getWName() << " completed." << endl;
					mp_g.mCScreen(true);
				}

				else if (mPlayer.ship.sCargo.at(slot).getIType() == "PShield")
				{
					ds_g.rData(mPlayer.ship.sCargo.at(slot).getIType(), "select from", mPlayer.ship.sCargo.at(slot).getIID());

					//For now item sales will give 25% of total cost back, hard.  Values will shift in later versions based on the CMulti, affinity, and difficuly

					mPlayer.updateXarn(((ds_g.getPSXC() * 0.25f) * amount), "add");
					mPlayer.updateRubies(((ds_g.getPSRC() * 0.25f) * amount), "add");
					mPlayer.updateDia(((ds_g.getPSDiC() * 0.25f) * amount), "add");
					mPlayer.updateDrac(((ds_g.getPSDC() * 0.25f) * amount), "add");
					mPlayer.updateLith(((ds_g.getPSLC() * 0.25f) * amount), "add");
					mPlayer.updateUra(((ds_g.getPSUC() * 0.25f) * amount), "add");
					mPlayer.updatePlut(((ds_g.getPSPC() * 0.25f) * amount), "add");

					mPlayer.ship.updateCIAmount(slot, amount, "sub", false, "");

					cout << "Sale of " <<  amount << " units of " << ds_g.getPSName() << " completed." << endl;
					mp_g.mCScreen(true);
				}

				else if (mPlayer.ship.sCargo.at(slot).getIType() == "PDefense")
				{
					ds_g.rData(mPlayer.ship.sCargo.at(slot).getIType(), "select from", mPlayer.ship.sCargo.at(slot).getIID());

					//For now item sales will give 25% of total cost back, hard.  Values will shift in later versions based on the CMulti, affinity, and difficuly

					mPlayer.updateXarn(((ds_g.getPDXC() * 0.25f) * amount), "add");
					mPlayer.updateRubies(((ds_g.getPDRC() * 0.25f) * amount), "add");
					mPlayer.updateDia(((ds_g.getPDDiC() * 0.25f) * amount), "add");
					mPlayer.updateDrac(((ds_g.getPDDC() * 0.25f) * amount), "add");
					mPlayer.updateLith(((ds_g.getPDLC() * 0.25f) * amount), "add");
					mPlayer.updateUra(((ds_g.getPDUC() * 0.25f) * amount), "add");
					mPlayer.updatePlut(((ds_g.getPDPC() * 0.25f) * amount), "add");

					mPlayer.ship.updateCIAmount(slot, amount, "sub", false, "");

					cout << "Sale of " <<  amount << " units of " << ds_g.getPDName() << " completed." << endl;
					mp_g.mCScreen(true);
				}

				else if (mPlayer.ship.sCargo.at(slot).getIType() == "Resource")
				{
					ds_g.rData(mPlayer.ship.sCargo.at(slot).getIType(), "select from", mPlayer.ship.sCargo.at(slot).getIID());

					//For now item sales will give 25% of total cost back, hard.  Values will shift in later versions based on the CMulti, affinity, and difficuly

					mPlayer.updateXarn(((ds_g.getResXCost() * 0.25f) * amount), "add");

					mPlayer.ship.updateCIAmount(slot, amount, "sub", false, "");

					cout << "Sale of " <<  amount << " units of " << ds_g.getResName() << " for " << ((ds_g.getOXCost() * 0.25f) * amount) << " Xarn completed." << endl;
					mp_g.mCScreen(true);
				}

				else if (mPlayer.ship.sCargo.at(slot).getIType() == "Ore")
				{
					ds_g.rData(mPlayer.ship.sCargo.at(slot).getIType(), "select from", mPlayer.ship.sCargo.at(slot).getIID());

					//For now item sales will give 25% of total cost back, hard.  Values will shift in later versions based on the CMulti, affinity, and difficuly

					mPlayer.updateXarn(((ds_g.getOXCost() * 0.25f) * amount), "add");

					mPlayer.ship.updateCIAmount(slot, amount, "sub", false, "");

					cout << "Sale of " <<  amount << " units of " << ds_g.getOName() << " for " << ((ds_g.getOXCost() * 0.25f) * amount) << " Xarn completed." << endl;
					mp_g.mCScreen(true);
				}
			}
		}

		else if (bIsShip) //Item to sell is a ship
		{
			pChoice  = mp_g.mSSIConfirm(mPlayer.ship.sCargo.at(slot).getIAmount(), mPlayer.ship.sCargo.at(slot).sShip.getID(), mPlayer.ship.sCargo.at(slot).getIType()); //Make player confirm that they want to sell item(s)

			if (pChoice == 1)
			{
				ds_g.rData("Ship", "select from", mPlayer.ship.sCargo.at(slot).sShip.getID());

				mPlayer.updateXarn(((ds_g.getSXC() * 0.25f) * amount), "add");
				mPlayer.updateRubies(((ds_g.getSRC() * 0.25f) * amount), "add");
				mPlayer.updateDia(((ds_g.getSDiC() * 0.25f) * amount), "add");
				mPlayer.updateDrac(((ds_g.getSDC() * 0.25f) * amount), "add");
				mPlayer.updateUra(((ds_g.getSUC() * 0.25f) * amount), "add");
				mPlayer.updatePlut(((ds_g.getSPC() * 0.25f) * amount), "add");

				mPlayer.ship.updateCIAmount(slot, amount, "sub", false, "");

				cout << "Sale of " << ds_g.getSName() << " completed." << endl;
				mp_g.mCScreen(true);
			}

			else if (pChoice == 0)
			{
				cout << mp_g.mRMessage(2043) << endl;
			}
		}
	}

	else if (bIOStation) //Item to sell is on the station
	{
		if (!bIsShip) //Item to sell is not a ship
		{
			if (stat_g.sInventory.at(slot).getIAmount() > 1) //If there is a stack of items in the slot marked for sale, ask player for number of items to sell
			{
				amount = mp_g.mSSIAmount(stat_g.sInventory.at(slot).getIAmount());
			}

			else //Else set amount to 1
			{
				amount = 1;
			}

			pChoice  = mp_g.mSSIConfirm(stat_g.sInventory.at(slot).getIAmount(), stat_g.sInventory.at(slot).getIID(), stat_g.sInventory.at(slot).getIType()); //Make player confirm that they want to sell item(s)

			if (pChoice == 0)
			{
				cout << mp_g.mRMessage(2043) << endl;
			}

			else
			{
				cout << mp_g.mRMessage(2044) << endl;

				if (stat_g.sInventory.at(slot).getIType() == "Weapon")
				{
					ds_g.rData(stat_g.sInventory.at(slot).getIType(), "select from", stat_g.sInventory.at(slot).getIID());

					//For now item sales will give 25% of total cost back, hard.  Values will shift in later versions based on the CMulti, affinity, and difficuly

					mPlayer.updateXarn(((ds_g.getWXC() * 0.25f) * amount), "add");
					mPlayer.updateRubies(((ds_g.getWRC() * 0.25f) * amount), "add");
					mPlayer.updateDia(((ds_g.getWDiC() * 0.25f) * amount), "add");
					mPlayer.updateDrac(((ds_g.getWDC() * 0.25f) * amount), "add");
					mPlayer.updateLith(((ds_g.getWLC() * 0.25f) * amount), "add");
					mPlayer.updateUra(((ds_g.getWUC() * 0.25f) * amount), "add");
					mPlayer.updatePlut(((ds_g.getWPC() * 0.25f) * amount), "add");

					stat_g.removeItem(slot, amount);

					cout << "Sale of " <<  amount << " units of " << ds_g.getWName() << " completed." << endl;
					mp_g.mCScreen(true);
				}

				else if (mPlayer.ship.sCargo.at(slot).getIType() == "PShield")
				{
					ds_g.rData(mPlayer.ship.sCargo.at(slot).getIType(), "select from", mPlayer.ship.sCargo.at(slot).getIID());

					//For now item sales will give 25% of total cost back, hard.  Values will shift in later versions based on the CMulti, affinity, and difficuly

					mPlayer.updateXarn(((ds_g.getPSXC() * 0.25f) * amount), "add");
					mPlayer.updateRubies(((ds_g.getPSRC() * 0.25f) * amount), "add");
					mPlayer.updateDia(((ds_g.getPSDiC() * 0.25f) * amount), "add");
					mPlayer.updateDrac(((ds_g.getPSDC() * 0.25f) * amount), "add");
					mPlayer.updateLith(((ds_g.getPSLC() * 0.25f) * amount), "add");
					mPlayer.updateUra(((ds_g.getPSUC() * 0.25f) * amount), "add");
					mPlayer.updatePlut(((ds_g.getPSPC() * 0.25f) * amount), "add");

					mPlayer.ship.updateCIAmount(slot, amount, "sub", false, "");

					cout << "Sale of " <<  amount << " units of " << ds_g.getPSName() << " completed." << endl;
					mp_g.mCScreen(true);
				}

				else if (mPlayer.ship.sCargo.at(slot).getIType() == "PDefense")
				{
					ds_g.rData(mPlayer.ship.sCargo.at(slot).getIType(), "select from", mPlayer.ship.sCargo.at(slot).getIID());

					//For now item sales will give 25% of total cost back, hard.  Values will shift in later versions based on the CMulti, affinity, and difficuly

					mPlayer.updateXarn(((ds_g.getPDXC() * 0.25f) * amount), "add");
					mPlayer.updateRubies(((ds_g.getPDRC() * 0.25f) * amount), "add");
					mPlayer.updateDia(((ds_g.getPDDiC() * 0.25f) * amount), "add");
					mPlayer.updateDrac(((ds_g.getPDDC() * 0.25f) * amount), "add");
					mPlayer.updateLith(((ds_g.getPDLC() * 0.25f) * amount), "add");
					mPlayer.updateUra(((ds_g.getPDUC() * 0.25f) * amount), "add");
					mPlayer.updatePlut(((ds_g.getPDPC() * 0.25f) * amount), "add");

					mPlayer.ship.updateCIAmount(slot, amount, "sub", false, "");

					cout << "Sale of " <<  amount << " units of " << ds_g.getPDName() << " completed." << endl;
					mp_g.mCScreen(true);
				}

				else if (stat_g.sInventory.at(slot).getIType() == "Resource")
				{
					ds_g.rData(stat_g.sInventory.at(slot).getIType(), "select from", stat_g.sInventory.at(slot).getIID());

					//For now item sales will give 25% of total cost back, hard.  Values will shift in later versions based on the CMulti, affinity, and difficuly

					mPlayer.updateXarn(((ds_g.getResXCost() * 0.25f) * amount), "add");

					stat_g.removeItem(slot, amount);

					cout << "Sale of " <<  amount << " units of " << ds_g.getResName() << " for " << ((ds_g.getOXCost() * 0.25f) * amount) << " Xarn completed." << endl;
					mp_g.mCScreen(true);
				}

				else if (stat_g.sInventory.at(slot).getIType() == "Ore")
				{
					ds_g.rData(stat_g.sInventory.at(slot).getIType(), "select from", stat_g.sInventory.at(slot).getIID());

					//For now item sales will give 25% of total cost back, hard.  Values will shift in later versions based on the CMulti, affinity, and difficuly

					mPlayer.updateXarn(((ds_g.getOXCost() * 0.25f) * amount), "add");

					stat_g.removeItem(slot, amount);

					cout << "Sale of " <<  amount << " units of " << ds_g.getOName() << " for " << ((ds_g.getOXCost() * 0.25f) * amount) << " Xarn completed." << endl;
					mp_g.mCScreen(true);
				}
			}
		}

		else if (bIsShip) //Item to sell is a ship
		{
			pChoice  = mp_g.mSSIConfirm(stat_g.sInventory.at(slot).getIAmount(), stat_g.sInventory.at(slot).sShip.getID(), stat_g.sInventory.at(slot).getIType()); //Make player confirm that they want to sell item(s)

			if (pChoice == 1)
			{
				ds_g.rData("Ship", "select from", stat_g.sInventory.at(slot).sShip.getID());

				mPlayer.updateXarn(((ds_g.getSXC() * 0.25f) * amount), "add");
				mPlayer.updateRubies(((ds_g.getSRC() * 0.25f) * amount), "add");
				mPlayer.updateDia(((ds_g.getSDiC() * 0.25f) * amount), "add");
				mPlayer.updateDrac(((ds_g.getSDC() * 0.25f) * amount), "add");
				mPlayer.updateUra(((ds_g.getSUC() * 0.25f) * amount), "add");
				mPlayer.updatePlut(((ds_g.getSPC() * 0.25f) * amount), "add");

				stat_g.removeItem(slot, amount);

				cout << "Sale of " << ds_g.getSName() << " completed." << endl;
				mp_g.mCScreen(true);
			}

			else if (pChoice == 0)
			{
				cout << mp_g.mRMessage(2043) << endl;
			}
		}
	}
}

string Game::getIType()
{
	if ((iCode >= 1) && (iCode <= 31)) //External value tag: value range; Add mining laser range here
	{
		return "laser";
	}

	else if ((iCode >= 32) && (iCode <= 102)) //External value tag: value range
	{
		return "missile";
	}

	else if ((iCode >= 103) && (iCode <= 125)) //External value tag: value range
	{
		return "bomb";
	}

	else if ((iCode >= 901) && (iCode <= 903)) //External value tag: value range
	{
		return "mining laser";
	}

	//TODO: Add railgun, heavy weapons
}

/*void Game::sSItem(Player& mPlayer, Station& stat_g)
{
while (!bDone)
{
ds_g.rData("Equipment_Data", "select from", iCode);

if (stat_g.getCSUsed() + ds_g.getESG2() < stat_g.getMUSpace())
{
for (i = 0; i <= stat_g.getISize(); i++)
{
if (i == stat_g.getISize())
{
stat_g.sSItem(iCode, 1, iType, ds_g.getESG2());
bDone = true;
break;
}

else if (stat_g.sInventory.at(i).getIID() == iCode)
{
stat_g.sInventory.at(i).updateIAmount(1,"add");
bDone = true;
break;
}
}
}

else
{
if (sBISpace(stat_g,mPlayer, ds_g.getESG2()))
{
for (i = 0; i <= stat_g.getISize(); i++)
{
if (i == stat_g.getISize())
{
stat_g.sSItem(iCode, 1, iType, ds_g.getESG2());
bDone = true;
break;
}

else if (stat_g.sInventory.at(i).getIID() == iCode)
{
stat_g.sInventory.at(i).updateIAmount(1,"add");
bDone = true;
break;
}
}
}

else
{
sMRefund(mPlayer, stat_g);
bDone = true;
}
}
}

bDone = false; //reset while loop
}*/

void Game::sSItem(Player& mPlayer, Station& stat_g, bool bought)
{
	bDone = false; //reset while loop

	if (bought)
	{
		if (iType == "Weapon")
		{
			while (!bDone)
			{
				if (stat_g.checkSpace(ds_g.getWSG2()))
				{
					for (i = 0; i <= stat_g.getISize(); i++)
					{
						if (i == stat_g.getISize())
						{
							stat_g.sSItem(iCode, 1, iType, ds_g.getWSG2(), false);
							bDone = true;
							break;
						}

						else if (stat_g.sInventory.at(i).getIID() == iCode)
						{
							stat_g.sInventory.at(i).updateIAmount(1,"add");
							bDone = true;

							cout << "Your item has been successfully stored." << endl;

							break;
						}
					}
				}

				else
				{
					if (stat_g.sBISpace(mPlayer, ds_g.getWSG2()))
					{
						for (i = 0; i <= stat_g.getISize(); i++)
						{
							if (i == stat_g.getISize())
							{
								stat_g.sSItem(iCode, 1, iType, ds_g.getWSG2(), false);
								bDone = true;
								break;
							}

							else if (stat_g.sInventory.at(i).getIID() == iCode)
							{
								stat_g.sInventory.at(i).updateIAmount(1,"add");
								bDone = true;

								cout << "Your item has been successfully stored." << endl;

								break;
							}
						}
					}

					else
					{
						sMRefund(mPlayer, stat_g);
						bDone = true;
					}
				}
			}
		}

		else if (iType == "Ship")
		{
			while (!bDone)
			{
				if (stat_g.checkSpace(ds_g.getSSG2()))
				{
					bExchange = mp_g.sMECShip();

					bSSuccess = stat_g.sSShip(iCode, bought, bExchange, mPlayer, this);

					if (bSSuccess)
					{
						bDone = true;
						cout << "Your ship has been successfully docked." << endl;

					}

					else if ((!bSSuccess) && (bought))
					{
						sMRefund(mPlayer, stat_g);
						bDone = true;
					}
				}

				else
				{
					if (!stat_g.sBISpace(mPlayer, ds_g.getSSG2()))
					{
						sMRefund(mPlayer, stat_g);
						bDone = true;
					}
				}
			}
		}

		else if (iType == "Equipment")
		{
			while (!bDone)
			{
				if (iType2 == "PShield" || iType2 == "PDefense" || iType2 == "Clone")
				{
					if (iType2 == "PShield")
					{
						ds_g.rData(iType2, "select from", iCode);

						sISG2 = ds_g.getPSSG2();
					}

					else if (iType2 == "PDefense")
					{
						ds_g.rData(iType2, "select from", iCode);

						sISG2 = ds_g.getPDSG2();
					}

					else if (iType2 == "Clone")
					{
						ds_g.rData(iType2, "select from", iCode);

						sISG2 = ds_g.getCSG2();
					}

					if (stat_g.checkSpace(sISG2))
					{
						for (i = 0; i <= stat_g.getISize(); i++)
						{
							if (i == stat_g.getISize())
							{
								stat_g.sSItem(iCode, 1, iType, sISG2, false);
								bDone = true;

								cout << "Your item has been successfully stored." << endl;

								break;
							}

							else if (stat_g.sInventory.at(i).getIID() == iCode)
							{
								stat_g.sInventory.at(i).updateIAmount(1,"add");
								bDone = true;

								cout << "Your item has been successfully stored." << endl;

								break;
							}
						}
					}

					else
					{
						if (stat_g.sBISpace(mPlayer, sISG2))
						{
							for (i = 0; i <= stat_g.getISize(); i++)
							{
								if (i == stat_g.getISize())
								{
									stat_g.sSItem(iCode, 1, iType, sISG2, false);
									bDone = true;

									cout << "Your item has been successfully stored." << endl;

									break;
								}

								else if (stat_g.sInventory.at(i).getIID() == iCode)
								{
									stat_g.sInventory.at(i).updateIAmount(1,"add");
									bDone = true;

									cout << "Your item has been successfully stored." << endl;

									break;
								}
							}
						}

						else
						{
							sMRefund(mPlayer, stat_g);
							bDone = true;
						}
					}
				}
			}
		}

		else if (iType == "Resource")
		{
			while (!bDone)
			{
				ds_g.rData("Resource", "select from", iCode);

				if (stat_g.checkSpace(ds_g.getResSG2()))
				{
					for (i = 0; i <= stat_g.getISize(); i++)
					{
						if (i == stat_g.getISize())
						{
							stat_g.sSItem(iCode, amount, iType, ds_g.getResSG2(), false);
							bDone = true;

							cout << "Your items have been successfully stored." << endl;

							break;
						}

						else if (stat_g.sInventory.at(i).getIID() == iCode)
						{
							stat_g.sInventory.at(i).updateIAmount(amount,"add");
							bDone = true;

							cout << "Your items have been successfully stored." << endl;

							break;
						}
					}
				}

				else
				{
					if (stat_g.sBISpace(mPlayer, ds_g.getResSG2()))
					{
						for (i = 0; i <= stat_g.getISize(); i++)
						{
							if (i == stat_g.getISize())
							{
								stat_g.sSItem(iCode, amount, iType, ds_g.getResSG2(), false);
								bDone = true;

								cout << "Your items have been successfully stored." << endl;

								break;
							}

							else if (stat_g.sInventory.at(i).getIID() == iCode)
							{
								stat_g.sInventory.at(i).updateIAmount(amount,"add");
								bDone = true;

								cout << "Your items have been successfully stored." << endl;

								break;
							}
						}
					}

					else
					{
						sMRefund(mPlayer, stat_g);
						bDone = true;
					}
				}
			}
		}

		else if (iType == "Ore")
		{
			while (!bDone)
			{
				ds_g.rData("Ore", "select from", iCode);

				if (stat_g.checkSpace(ds_g.getOSG2()))
				{
					for (i = 0; i <= stat_g.getISize(); i++)
					{
						if (i == stat_g.getISize())
						{
							stat_g.sSItem(iCode, amount, iType, ds_g.getOSG2(), false);
							bDone = true;

							cout << "Your items have been successfully stored." << endl;

							break;
						}

						else if (stat_g.sInventory.at(i).getIID() == iCode)
						{
							stat_g.sInventory.at(i).updateIAmount(amount,"add");
							bDone = true;

							cout << "Your items have been successfully stored." << endl;

							break;
						}
					}
				}

				else
				{
					if (stat_g.sBISpace(mPlayer, ds_g.getOSG2()))
					{
						for (i = 0; i <= stat_g.getISize(); i++)
						{
							if (i == stat_g.getISize())
							{
								stat_g.sSItem(iCode, amount, iType, ds_g.getOSG2(), false);
								bDone = true;

								cout << "Your items have been successfully stored." << endl;

								break;
							}

							else if (stat_g.sInventory.at(i).getIID() == iCode)
							{
								stat_g.sInventory.at(i).updateIAmount(amount,"add");
								bDone = true;

								cout << "Your items have been successfully stored." << endl;

								break;
							}
						}
					}

					else
					{
						sMRefund(mPlayer, stat_g);
						bDone = true;
					}
				}
			}
		}
	}

	else
	{
		//Determine if the item is a ship or a non-ship item//Determine where the itme the player wants to move is located
		pChoice = mp_g.sMSI1();

		if (pChoice == 0)
		{
			cout << "Ending storage processing..." << endl;
			bDone = true;
		}

		//Move a ship
		else if (pChoice == 1)
		{
			if (!stat_g.sSShip(0, false, false, mPlayer, this))
			{
				cout << "Storage process failed..." << endl;
				bDone = true;
			}
		}

		//Move a non-ship
		else
		{
			//Determine if the item is located on the station or in the player ship cargohold
			pChoice = mp_g.sMSI2();

			if (pChoice == 1) //Item is located on station - move to player ship
			{
				stat_g.getItem(mPlayer);
				bDone = true;
			}

			else if (pChoice == 2) //Item is located on the player ship - move to the station
			{
				mPlayer.ship.storeItem(stat_g, mPlayer);
				bDone = true;
			}

			else
			{
				cout << "Ending storage proceedures." << endl;
			}
		}
	}
}

void Game::sGItem(Player& mPlayer, Station& stat_g)
{
	if (stat_g.sInventory.size() == 0)
	{
		cout << "You do not have anything stored on this station." << endl;
	}

	else
	{
		pChoice = mp_g.sMMenu1B1();

		if (pChoice == 0)
		{
			cout << "Ending the retrieval process..." << endl;
		}

		else if (pChoice == 1)
		{
			pChoice = mp_g.sInv(stat_g);

			if (pChoice < 0)
			{
				cout << "Ending the retrieval process..." << endl;
			}

			else
			{
				if (stat_g.sInventory.at(pChoice-1).getIAmount() > 1)
				{
					amount = mp_g.mSSIAmount(stat_g.sInventory.at(pChoice=1).getIAmount());
				}

				else //Else set amount to 1
				{
					amount = 1;
				}

				pChoice  = mp_g.mSTIConfirm(amount, stat_g.sInventory.at(pChoice-1).getIID(), stat_g.sInventory.at(pChoice-1).getIType());

				if (pChoice == 1)
				{
					if (mPlayer.ship.checkSpace(stat_g.sInventory.at(pChoice-1).getISpace()*amount))
					{
						if (mPlayer.ship.addCItem(stat_g.sInventory.at(pChoice-1).getIID(), stat_g.sInventory.at(pChoice-1).getIType(),amount, false))
						{
							stat_g.removeItem(pChoice-1, amount);

							cout << "Your selected item(s) were successfully transfered to your ship." << endl;
						}

						else
						{
							cout << "Item transfer to ship failed.  Ending the retrieval process..." << endl;
						}
					}

					else
					{
						cout << "Not enough space on ship for cargo.  Ending the retrieval process..." << endl;
					}
				}

				else
				{
					cout << "Ending the retrieval process..." << endl;
				}
			}
		}

		else if (pChoice == 2)
		{
			cout << mp_g.mRMessage(2001) << endl;
		}
	}
}


void Game::loadStation(stationData& stData)
{
	gStations.push_back(Station());

	gStations.at(gStations.size()-1).setSID(stData.sID); //ID from table for dealing with player inventories in various stations
	gStations.at(gStations.size()-1).setName(stData.sName);
	gStations.at(gStations.size()-1).setAffil(stData.sAffiliation);
	gStations.at(gStations.size()-1).setDispo(stData.sDispo);
	gStations.at(gStations.size()-1).setTLevel(stData.sTLevel);
	gStations.at(gStations.size()-1).setSLevel(stData.sLevel); //Station level
	gStations.at(gStations.size()-1).updateISpace(stData.sMSpace, "set"); //Max usable storage space
	gStations.at(gStations.size()-1).setCMulti(stData.sCMulti); //Cost multiplier
}

void Game::sMRefund(Player& mPlayer, Station& stat_g)
{
	cout << mp_g.mRMessage(2008) << endl;
	cout << endl;

	if (iType == "Weapon")
	{
		ds_g.rData("Weapon_Data","select from",iCode);

		//If weapon requires the resource remove that amount of resources from the playuer
		if (ds_g.getWXC() != 0)
		{
			mPlayer.updateXarn(ds_g.getWXC()* stat_g.getCMulti(), "add");
		}

		if (ds_g.getWRC() != 0)
		{
			mPlayer.updateRubies(ds_g.getWRC()* stat_g.getCMulti(), "add");
		}

		if (ds_g.getWDiC() != 0)
		{
			mPlayer.updateDia(ds_g.getWDiC()* stat_g.getCMulti(), "add");
		}

		if (ds_g.getWDC() != 0)
		{
			mPlayer.updateDrac(ds_g.getWDC()* stat_g.getCMulti(), "add");
		}

		if (ds_g.getWLC() != 0)
		{
			mPlayer.updateLith(ds_g.getWLC()* stat_g.getCMulti(), "add");
		}

		if (ds_g.getWPC() != 0)
		{
			mPlayer.updatePlut(ds_g.getWPC()* stat_g.getCMulti(), "add");
		}

		if (ds_g.getWUC() != 0)
		{
			mPlayer.updateUra(ds_g.getWUC()* stat_g.getCMulti(), "add");
		}

		if (ds_g.getWNWC() != 0)
		{
			mPlayer.updateNWaste(ds_g.getWNWC()* stat_g.getCMulti(), "add");
		}
	}

	else if (iType == "Ship")
	{
		ds_g.rData("Ship_Data","select from",iCode);

		//If ship requires the resource remove that amount of resources from the player
		if (ds_g.getSXC() != 0)
		{
			mPlayer.updateXarn(ds_g.getSXC()* stat_g.getCMulti(), "add");
		}

		if (ds_g.getSRC() != 0)
		{
			mPlayer.updateRubies(ds_g.getSRC()* stat_g.getCMulti(), "add");
		}

		if (ds_g.getSDiC() != 0)
		{
			mPlayer.updateDia(ds_g.getSDiC()* stat_g.getCMulti(), "add");
		}

		if (ds_g.getSDC() != 0)
		{
			mPlayer.updateDrac(ds_g.getSDC()* stat_g.getCMulti(), "add");
		}

		if (ds_g.getWPC() != 0)
		{
			mPlayer.updatePlut(ds_g.getSPC()* stat_g.getCMulti(), "add");
		}

		if (ds_g.getWUC() != 0)
		{
			mPlayer.updateUra(ds_g.getSUC()* stat_g.getCMulti(), "add");
		}
	}

	else if (iType == "Equipment")
	{
		//If item requires the resource remove that amount of resources from the player

		if (iType2 == "Clone")
		{
			ds_g.rData(iType2,"select from",iCode);

			if (ds_g.getCXC() != 0)
			{
				sTax = 0.25f; //Clone tax

				sTCost = ds_g.getCXC() * stat_g.getCMulti(); //Calculate CMulti cost
				sPTax = sTCost * sTax; //Calculate additional cost from tax

				sTPCost = sTCost + sPTax; //Calculate total cost

				mPlayer.updateXarn(sTPCost, "add");
			}

			if (ds_g.getCRC() != 0)
			{
				mPlayer.updateRubies(ds_g.getCRC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getCDiC() != 0)
			{
				mPlayer.updateDia(ds_g.getCDiC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getCDC() != 0)
			{
				mPlayer.updateDrac(ds_g.getCDC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getCLC() != 0)
			{
				mPlayer.updateLith(ds_g.getCLC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getCPC() != 0)
			{
				mPlayer.updatePlut(ds_g.getCPC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getCUC() != 0)
			{
				mPlayer.updateUra(ds_g.getCUC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getCNWC() != 0)
			{

				mPlayer.updateNWaste(ds_g.getCNWC()* stat_g.getCMulti(), "add");
			}

		}

		else if (iType2 == "PShield")
		{
			ds_g.rData(iType2,"select from",iCode);

			if (ds_g.getPSXC() != 0)
			{
				mPlayer.updateXarn(ds_g.getPSXC() * stat_g.getCMulti(), "add");
			}

			if (ds_g.getPSRC() != 0)
			{
				mPlayer.updateRubies(ds_g.getPSRC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getPSDiC() != 0)
			{
				mPlayer.updateDia(ds_g.getPSDiC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getPSDC() != 0)
			{
				mPlayer.updateDrac(ds_g.getPSDC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getPSLC() != 0)
			{
				mPlayer.updateLith(ds_g.getPSLC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getPSPC() != 0)
			{
				mPlayer.updatePlut(ds_g.getPSPC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getPSUC() != 0)
			{
				mPlayer.updateUra(ds_g.getPSUC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getPSNWC() != 0)
			{

				mPlayer.updateNWaste(ds_g.getPSNWC()* stat_g.getCMulti(), "add");
			}
		}

		else if (iType2 == "PDefense")
		{
			ds_g.rData(iType2,"select from",iCode);

			if (ds_g.getPDXC() != 0)
			{
				mPlayer.updateXarn(ds_g.getPDXC() * stat_g.getCMulti(), "add");
			}

			if (ds_g.getPDRC() != 0)
			{
				mPlayer.updateRubies(ds_g.getPDRC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getPDDiC() != 0)
			{
				mPlayer.updateDia(ds_g.getPDDiC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getPDDC() != 0)
			{
				mPlayer.updateDrac(ds_g.getPDDC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getPDLC() != 0)
			{
				mPlayer.updateLith(ds_g.getPDLC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getPDPC() != 0)
			{
				mPlayer.updatePlut(ds_g.getPDPC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getPDUC() != 0)
			{
				mPlayer.updateUra(ds_g.getPDUC()* stat_g.getCMulti(), "add");
			}

			if (ds_g.getPDNWC() != 0)
			{

				mPlayer.updateNWaste(ds_g.getPDNWC()* stat_g.getCMulti(), "add");
			}
		}
	}
}

void Game::createBInfo()
{
	file = __FILE__;
	bLocale = "File: " + file + "  Line: ";

	time = __TIME__;
	date = __DATE__;

	bTDate = date + "  " + time;
}

void Game::sCasino(Player& mPlayer)
{
	bContinue = false;

	while (!bContinue)
	{
		if (mPlayer.getXarn() > 0)
		{
			pChoice = mp_g.sMCasino();

			switch(pChoice)
			{
			case 1:
				sCSlots(mPlayer);
				break;

			case 2:
				sCBJack(mPlayer);
				break;

			case 3:
				sCPoker(mPlayer);
				break;

			case 4:
				sCRoulette(mPlayer);
				break;

				/*case 5:
				sCDJott(mPlayer);
				break;*/

			case 6:
				//sCCraps(mPlayer);
				break;

			default:
				bContinue = true;
				break;
			}
		}

		else
		{
			cout << mp_g.mRMessage(2050) << endl;
			bContinue = true;
		}
	}
}


void Game::sCRoulette(Player& mPlayer)
{
	bContinue2 = true;

	//Setup AI Players
	setupCAI(true, false);

	while (bContinue2)
	{
		pChoice = mp_g.sCRMenu1();

		switch(pChoice)
		{
		case 1:
			mp_g.sCRTMenu();
			break;

		case 2:
			bContinue = true;

			while (bContinue)
			{
				//Cycle through players vector
				if (sCChips != 0)
				{
					for (i = 0; i <= players.size(); i++)
					{
						if (i == 0) //If it is the player's turn
						{
							pChoice = mp_g.sCMRBet1();

							if (pChoice != 0)
							{
								switch(pChoice)
								{
								case 1:
									iBValue = mp_g.sCMRBet2();

									rInt4 = mp_g.sCMBet(sCChips);

									rBets.push_back(bet());

									cout << mPlayer.getName() << " has placed a bet of " << rInt4 << " chips on " << iBValue << "!" << endl;

									//Save the bet data
									rBets.at(rBets.size()-1).bType = "Number";
									rBets.at(rBets.size()-1).chips = rInt4;
									rBets.at(rBets.size()-1).bName = mPlayer.getName();
									rBets.at(rBets.size()-1).number = iBValue;

									break;

								case 2:
									sBValue = mp_g.sCMRBet3();

									rInt4 = mp_g.sCMBet(sCChips);

									rBets.push_back(bet());

									cout << mPlayer.getName() << " has placed a bet of " << rInt4 << " chips on " << sBValue << "!" << endl;

									//Save the bet data
									rBets.at(rBets.size()-1).bType = "Zero";
									rBets.at(rBets.size()-1).chips = rInt4;
									rBets.at(rBets.size()-1).bName = mPlayer.getName();
									rBets.at(rBets.size()-1).zero = sBValue;

									break;

								case 3:
									iBValue = mp_g.sCMRBet4();

									if (iBValue == 1)
									{
										sBValue = "Red";
										cBValue = 'R';
									}

									else if (iBValue == 2)
									{
										sBValue = "Black";
										cBValue = 'B';
									}

									else if (iBValue == 3)
									{
										sBValue = "Green";
										cBValue = 'G';
									}

									rInt4 = mp_g.sCMBet(sCChips);

									rBets.push_back(bet());

									cout << mPlayer.getName() << " has placed a bet of " << rInt4 << " chips on " << sBValue << "!" << endl;

									//Save the bet data
									rBets.at(rBets.size()-1).bType = "Color";
									rBets.at(rBets.size()-1).chips = rInt4;
									rBets.at(rBets.size()-1).bName = mPlayer.getName();
									rBets.at(rBets.size()-1).color = cBValue;

									break;

								case 4:
									iBValue = mp_g.sCMRBet5();

									if (iBValue == 1)
									{
										sBValue = "Even";
									}

									else if (iBValue == 2)
									{
										sBValue = "Odd";
									}

									rInt4 = mp_g.sCMBet(sCChips);

									rBets.push_back(bet());

									cout << mPlayer.getName() << " has placed a bet of " << rInt4 << " chips on " << sBValue << "!" << endl;

									//Save the bet data
									rBets.at(rBets.size()-1).bType = "Type";
									rBets.at(rBets.size()-1).chips = rInt4;
									rBets.at(rBets.size()-1).bName = mPlayer.getName();
									rBets.at(rBets.size()-1).type = sBValue;

									break;

								case 5:
									iBValue = mp_g.sCMRBet6();

									if (iBValue % 2 == 0)
									{
										if (iBValue == 2)
										{
											sBValue = "Quarter 1 ";
										}

										else if (iBValue == 4)
										{
											sBValue = "Quarter 2 ";
										}

										else if (iBValue == 6)
										{
											sBValue = "Quarter 3 ";
										}

										else if (iBValue == 8)
										{
											sBValue = "Quarter 4 ";
										}

										sSize = "short";
									}

									else
									{
										if (iBValue == 1)
										{
											sBValue = "Quarter 1 ";
										}

										else if (iBValue == 3)
										{
											sBValue = "Quarter 2 ";
										}

										else if (iBValue == 5)
										{
											sBValue = "Quarter 3 ";
										}

										else if (iBValue == 7)
										{
											sBValue = "Quarter 4 ";
										}

										sSize = "long";
									}

									rInt4 = mp_g.sCMBet(sCChips);

									rBets.push_back(bet());

									cout << mPlayer.getName() << " has placed a bet of " << rInt4 << " chips on " << sBValue << sSize << "!" << endl;

									//Save the bet data
									rBets.at(rBets.size()-1).bType = "Section";
									rBets.at(rBets.size()-1).chips = rInt4;
									rBets.at(rBets.size()-1).bName = mPlayer.getName();
									rBets.at(rBets.size()-1).section = iBValue;

									break;

								case 6:
									iBValue = mp_g.sCMRBet7();

									rInt4 = mp_g.sCMBet(sCChips);

									rBets.push_back(bet());

									cout << mPlayer.getName() << " has placed a bet of " << rInt4 << " chips on Quarter " << iBValue << "!" << endl;

									//Save the bet data
									rBets.at(rBets.size()-1).bType = "Quarter";
									rBets.at(rBets.size()-1).chips = rInt4;
									rBets.at(rBets.size()-1).bName = mPlayer.getName();
									rBets.at(rBets.size()-1).quarter = iBValue;

									break;

								case 7:
									iBValue = mp_g.sCMRBet8();

									rInt4 = mp_g.sCMBet(sCChips);

									rBets.push_back(bet());

									cout << mPlayer.getName() << " has placed a bet of " << rInt4 << " chips on Half " << iBValue << "!" << endl;

									//Save the bet data
									rBets.at(rBets.size()-1).bType = "Half";
									rBets.at(rBets.size()-1).chips = rInt4;
									rBets.at(rBets.size()-1).bName = mPlayer.getName();
									rBets.at(rBets.size()-1).half = iBValue;

									break;

								default:
									bContinue = false;
									break;
								}
							}
						}

						else //If it is an AI's turn
						{
							if (players.at(i-1).getChips() != 0) //Make sure the ai has chips to use
							{
								//Place bet by random selection
								rFloat1 = Random(1.0f,120.0f);

								if ((rFloat1 >= 1.0f) && (rFloat1 < 20.0f)) //Number
								{
									rInt2 = Random(1,20);

									if ((rInt2 >= 1) && (rInt2 < 14)) //Number bet
									{
										rInt3 = Random(1,72); //Pick the number to bet on

										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on " << rInt3 << "!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Number";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).number = rInt3;
									}

									else //Zero bet
									{
										rInt3 = Random(1,4); //Pick the '0' to bet on

										switch(rInt3)
										{
										case 1:
											rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

											rBets.push_back(bet());

											cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on 0!" << endl;

											//Save the bet data
											rBets.at(rBets.size()-1).bType = "Zero";
											rBets.at(rBets.size()-1).chips = rInt4;
											rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
											rBets.at(rBets.size()-1).zero = "0";
											break;

										case 2:
											rInt4 = Random(1,players.at(i-1).getChips());

											rBets.push_back(bet());

											cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on 00!" << endl;

											rBets.at(rBets.size()-1).bType = "Zero";
											rBets.at(rBets.size()-1).chips = rInt4;
											rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
											rBets.at(rBets.size()-1).zero = "00";
											break;

										case 3:
											rInt4 = Random(1,players.at(i-1).getChips());

											rBets.push_back(bet());

											cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on 000!" << endl;

											rBets.at(rBets.size()-1).bType = "Zero";
											rBets.at(rBets.size()-1).chips = rInt4;
											rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
											rBets.at(rBets.size()-1).zero = "000";
											break;

										case 4:
											rInt4 = Random(1,players.at(i-1).getChips());

											rBets.push_back(bet());

											cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on 0000!" << endl;

											rBets.at(rBets.size()-1).bType = "Zero";
											rBets.at(rBets.size()-1).chips = rInt4;
											rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
											rBets.at(rBets.size()-1).zero = "0000";
											break;

										default:
											break;
										}
									}
								}

								else if ((rFloat1 >= 20.0f) && (rFloat1 < 40.0f)) //Color
								{
									rInt3 = Random(1,30);

									if ((rInt3 >= 1) && (rInt3 < 11)) //Red
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Red!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Color";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).color = 'R';
									}

									else if ((rInt3 >= 11) && (rInt3 < 21)) //Black
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Black!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Color";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).color = 'B';
									}

									else if (rInt3 >= 21) //Green
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Green!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Color";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).color = 'G';
									}
								}

								else if ((rFloat1 >= 40.0f) && (rFloat1 < 60.0f)) //Type
								{
									rInt3 = Random(1,20);

									if ((rInt3 >= 1) && (rInt3 < 11)) //Even
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Even!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Type";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).type = "Even";
									}

									else if (rInt3 >= 11) //Odd
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Odd!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Type";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).type = "Odd";
									}
								}

								else if ((rFloat1 >= 60.0f) && (rFloat1 < 80.0f)) //Section
								{
									rInt3 = Random(1,80);

									if ((rInt3 >= 1) && (rInt3 < 11)) //Section 1
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Block 1 long!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Section";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).section = 1;
									}

									else if ((rInt3 >= 11) && (rInt3 < 21)) //Section 2
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Block 1 short!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Section";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).section = 2;
									}

									else if ((rInt3 >= 21) && (rInt3 < 31)) //Section 3
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Block 2 long!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Section";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).section = 3;
									}

									else if ((rInt3 >= 31) && (rInt3 < 41)) //Section 4
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Block 2 short!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Section";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).section = 4;
									}

									else if ((rInt3 >= 41) && (rInt3 < 51)) //Section 5
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Block 3 long!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Section";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).section = 5;
									}

									else if ((rInt3 >= 51) && (rInt3 < 61)) //Section 6
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Block 3 short!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Section";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).section = 6;
									}

									else if ((rInt3 >= 61) && (rInt3 < 71)) //Section 7
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Block 4 long!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Section";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).section = 7;
									}

									else if (rInt3 >= 71) //Section 8
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Block 4 short!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Section";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).section = 8;
									}
								}

								else if ((rFloat1 >= 80.0f) && (rFloat1 < 100.0f)) //Quarter
								{
									rInt3 = Random(1,100);

									if ((rInt3 >= 1) && (rInt3 < 26))
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Quarter 1!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Quarter";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).quarter = 1;
									}

									else if ((rInt3 >= 26) && (rInt3 < 51))
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Quarter 2!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Quarter";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).quarter = 2;
									}

									else if ((rInt3 >= 51) && (rInt3 < 76))
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Quarter 3!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Quarter";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).quarter = 3;
									}

									else if (rInt3 >= 76)
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Quarter 4!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Quarter";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).bID = i-1;
										rBets.at(rBets.size()-1).quarter = 4;
									}
								}

								else if (rFloat1 >= 1000.0f) //Half
								{
									rInt3 = Random(1,100);

									if ((rInt3 >= 1) && (rInt3 < 51))
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Half 1!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Half";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).bID = i-1;
										rBets.at(rBets.size()-1).half = 1;
									}

									else if (rInt3 >= 51)
									{
										rInt4 = Random(1,players.at(i-1).getChips()); //Get the bet to be placed

										rBets.push_back(bet());

										cout << players.at(i-1).getName() << " has placed a bet of " << rInt4 << " chips on Half 2!" << endl;

										//Save the bet data
										rBets.at(rBets.size()-1).bType = "Half";
										rBets.at(rBets.size()-1).chips = rInt4;
										rBets.at(rBets.size()-1).bName = players.at(i-1).getName();
										rBets.at(rBets.size()-1).bID = i-1;
										rBets.at(rBets.size()-1).half = 2;
									}
								}
							}
						}
					}

					rInt1 = Random(1,76); //Process the table spin
					sCRWValue = sCRWheel[rInt1-1]; //Get actual string value from vector
					sCRWVInt = atoi(sCRWValue.c_str());

					cout << "Marble lands in pocket " << sCRWValue << endl << endl;

					cout << "Bet Results: " << endl;

					for (i2 = 0; i2 < rBets.size(); i2--)
					{
						if (rBets.at(i2).bType == "Number")
						{
							sCRWVString = sCRWValue.substr(2,2);

							sCRWVInt = atoi(sCRWVString.c_str());

							if (rBets.at(i2).number == sCRWVInt)
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRNum << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRNum;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRNum), "add");
								}
							}

							else
							{
								cout << rBets.at(i2).bName << " lost!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips -= rBets.at(i2).chips;

									if (sCChips < 0) //If chips becomes negative
									{
										sCChips = 0;
									}
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips), "sub");

									if (players.at(rBets.at(i2).bID).getChips() < 0) //If chips becomes negative
									{
										players.at(rBets.at(i2).bID).updateChips(0, "set");
									}
								}
							}
						}

						else if (rBets.at(i2).bType == "Zero")
						{
							sCRWVString = sCRWValue.substr(2,4);

							if (sCRWVString == rBets.at(i2).zero)
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRZeros << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRZeros;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRZeros), "add");
								}
							}

							else
							{
								cout << rBets.at(i2).bName << " lost!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips -= rBets.at(i2).chips;

									if (sCChips < 0) //If chips becomes negative
									{
										sCChips = 0;
									}
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips), "sub");

									if (players.at(rBets.at(i2).bID).getChips() < 0) //If chips becomes negative
									{
										players.at(rBets.at(i2).bID).updateChips(0, "set");
									}
								}
							}
						}

						else if (rBets.at(i2).bType == "Color")
						{
							sCRWVChar = sCRWValue[0];

							if (sCRWVChar == rBets.at(i2).color)
							{
								if (sCRWVChar == 'G')
								{
									cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRC_G << "!" << endl;

									if (rBets.at(i2).bName == mPlayer.getName())
									{
										sCChips += rBets.at(i2).chips * gv::cRBRC_G;
									}

									else
									{
										players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRC_G), "add");
									}
								}

								else if (sCRWVChar == 'R' || sCRWVChar == 'B')
								{
									cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRC_RB << "!" << endl;

									if (rBets.at(i2).bName == mPlayer.getName())
									{
										sCChips += rBets.at(i2).chips * gv::cRBRC_RB;
									}

									else
									{
										players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRC_RB), "add");
									}
								}
							}

							else
							{
								cout << rBets.at(i2).bName << " lost!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips -= rBets.at(i2).chips;

									if (sCChips < 0) //If chips becomes negative
									{
										sCChips = 0;
									}
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips), "sub");

									if (players.at(rBets.at(i2).bID).getChips() < 0) //If chips becomes negative
									{
										players.at(rBets.at(i2).bID).updateChips(0, "set");
									}
								}
							}
						}

						else if (rBets.at(i2).bType == "Type")
						{
							sCRWVString = sCRWValue.substr(2,2);
							sCRWVInt = atoi(sCRWVString.c_str());

							if ((rBets.at(i2).type == "Even") && (sCRWVInt % 2 == 0))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRType << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRType;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRType), "add");
								}
							}

							else if ((rBets.at(i2).type == "Odd") && (sCRWVInt % 2 != 0))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRType << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRType;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRType), "add");
								}
							}

							else
							{
								cout << rBets.at(i2).bName << " lost!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips -= rBets.at(i2).chips;

									if (sCChips < 0) //If chips becomes negative
									{
										sCChips = 0;
									}
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips), "sub");

									if (players.at(rBets.at(i2).bID).getChips() < 0) //If chips becomes negative
									{
										players.at(rBets.at(i2).bID).updateChips(0, "set");
									}
								}
							}
						}

						else if (rBets.at(i2).bType == "Section")
						{
							if (((sCRWVInt >= 1) && (sCRWVInt <= 11)) && (rBets.at(i2).section == 1))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRS_L << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRS_L;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRS_L), "add");
								}
							}

							else if (((sCRWVInt >= 12) && (sCRWVInt <= 18)) && (rBets.at(i2).section == 2))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRS_S << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRS_S;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRS_S), "add");
								}
							}

							else if (((sCRWVInt >= 20) && (sCRWVInt <= 30)) && (rBets.at(i2).section == 3))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRS_L << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRS_L;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRS_L), "add");
								}
							}

							else if (((sCRWVInt >= 31) && (sCRWVInt <= 37)) && (rBets.at(i2).section == 4))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRS_S << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRS_S;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRS_S), "add");
								}
							}

							else if (((sCRWVInt >= 39) && (sCRWVInt <= 49)) && (rBets.at(i2).section == 5))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRS_L << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRS_L;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRS_L), "add");
								}
							}

							else if (((sCRWVInt >= 50) && (sCRWVInt <= 56)) && (rBets.at(i2).section == 6))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRS_S << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRS_S;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRS_S), "add");
								}
							}

							else if (((sCRWVInt >= 58) && (sCRWVInt <= 68)) && (rBets.at(i2).section == 7))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRS_L << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRS_L;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRS_L), "add");
								}
							}

							else if (((sCRWVInt >= 70) && (sCRWVInt <= 76)) && (rBets.at(i2).section == 8))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRS_S << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRS_S;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRS_S), "add");
								}
							}

							else
							{
								cout << rBets.at(i2).bName << " lost!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips -= rBets.at(i2).chips;

									if (sCChips < 0) //If chips becomes negative
									{
										sCChips = 0;
									}
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips), "sub");

									if (players.at(rBets.at(i2).bID).getChips() < 0) //If chips becomes negative
									{
										players.at(rBets.at(i2).bID).updateChips(0, "set");
									}
								}
							}
						}

						else if (rBets.at(i2).bType == "Quarter")
						{
							if (((sCRWVInt >= 0) && (sCRWVInt < 19)) && (rBets.at(i2).quarter == 1))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRQ << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRQ;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRQ), "add");
								}
							}

							else if (((sCRWVInt >= 19) && (sCRWVInt < 38)) && (rBets.at(i2).quarter == 2))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRQ << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRQ;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRQ), "add");
								}
							}

							else if (((sCRWVInt >= 38) && (sCRWVInt < 57)) && (rBets.at(i2).quarter == 3))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRQ << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRQ;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRQ), "add");
								}
							}

							else if (((sCRWVInt >= 57) && (sCRWVInt <= 76)) && (rBets.at(i2).quarter == 4))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRQ << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRQ;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRQ), "add");
								}
							}

							else
							{
								cout << rBets.at(i2).bName << " lost!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips -= rBets.at(i2).chips;

									if (sCChips < 0) //If chips becomes negative
									{
										sCChips = 0;
									}
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips), "sub");

									if (players.at(rBets.at(i2).bID).getChips() < 0) //If chips becomes negative
									{
										players.at(rBets.at(i2).bID).updateChips(0, "set");
									}
								}
							}
						}

						else if (rBets.at(i2).bType == "Half")
						{
							if (((sCRWVInt >= 0) && (sCRWVInt < 38)) && (rBets.at(i2).half == 1))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRH << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRH;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRH), "add");
								}
							}

							else if (((sCRWVInt >= 38) && (sCRWVInt <= 76)) && (rBets.at(i2).half == 2))
							{
								cout << rBets.at(i2).bName << " won " << rBets.at(i2).chips * gv::cRBRH << "!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips += rBets.at(i2).chips * gv::cRBRH;
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips * gv::cRBRH), "add");
								}
							}

							else
							{
								cout << rBets.at(i2).bName << " lost!" << endl;

								if (rBets.at(i2).bName == mPlayer.getName())
								{
									sCChips -= rBets.at(i2).chips;

									if (sCChips < 0) //If chips becomes negative
									{
										sCChips = 0;
									}
								}

								else
								{
									players.at(rBets.at(i2).bID).updateChips((rBets.at(i2).chips), "sub");

									if (players.at(rBets.at(i2).bID).getChips() < 0) //If chips becomes negative
									{
										players.at(rBets.at(i2).bID).updateChips(0, "set");
									}
								}
							}
						}
					}
				}

				else
				{
					cout << "You have no more chips to bet with." << endl;
					bContinue = false;
				}
			}

			break;

		default:
			bContinue2 = false;
			break;
		}
	}
}

void Game::setupCAI(bool R, bool P)
{
	//Break this down by game.  Some games will have a higher max player count than others.  Roulette can have as many players as neccessary while Blackjack and poker will have a max of four including the player
	//Start by making sure that the vector is clean
	if (players.size() > 0)
	{
		players.clear();
	}

	//Next determine the number of players between 0 and 9
	rFloat1 = Random(1.0f,100.0f);

	if (rFloat1 < 10.0f)
	{
		if (R)
		{
			rNOPlayers = 0;
		}

		else if (P)
		{
			rNOPlayers = 1;
		}
	}

	else if ((rFloat1 >= 10.0f) && (rFloat1 < 20.0f))
	{
		if (R)
		{
			rNOPlayers = 1;
		}

		else if (P)
		{
			rNOPlayers = 1;
		}
	}

	else if ((rFloat1 >= 20.0f) && (rFloat1 < 30.0f))
	{
		if (R)
		{
			rNOPlayers = 2;
		}

		else if (P)
		{
			rNOPlayers = 1;
		}
	}

	else if ((rFloat1 >= 30.0f) && (rFloat1 < 40.0f))
	{
		if (R)
		{
			rNOPlayers = 3;
		}

		else if (P)
		{
			rNOPlayers = 2;
		}
	}

	else if ((rFloat1 >= 40.0f) && (rFloat1 < 50.0f))
	{
		if (R)
		{
			rNOPlayers = 4;
		}

		else if (P)
		{
			rNOPlayers = 2;
		}
	}

	else if ((rFloat1 >= 50.0f) && (rFloat1 < 60.0f))
	{
		if (R)
		{
			rNOPlayers = 5;
		}

		else if (P)
		{
			rNOPlayers = 2;
		}
	}

	else if ((rFloat1 >= 60.0f) && (rFloat1 < 70.0f))
	{
		if (R)
		{
			rNOPlayers = 6;
		}

		else if (P)
		{
			rNOPlayers = 3;
		}
	}

	else if ((rFloat1 >= 70.0f) && (rFloat1 < 80.0f))
	{
		if (R)
		{
			rNOPlayers = 7;
		}

		else if (P)
		{
			rNOPlayers = 3;
		}
	}

	else if ((rFloat1 >= 80.0f) && (rFloat1 < 90.0f))
	{
		if (R)
		{
			rNOPlayers = 8;
		}

		else if (P)
		{
			rNOPlayers = 3;
		}
	}

	else if (rFloat1 >= 90.0f)
	{
		if (R)
		{
			rNOPlayers = 9;
		}

		else if (P)
		{
			rNOPlayers = 3;
		}
	}

	//Now create the data for each ai player
	for (i = 0; i < rNOPlayers; i++)
	{
		players.push_back(casinoAI());

		players.at(players.size()-1).setName(ng_g.genName("Human"));
		players.at(players.size()-1).setRace("Human");

		rInt1 = Random(1,10);

		if ((rInt1 >=1) && (rInt1 <= 5))
		{
			players.at(players.size()-1).setSex('M');
		}

		else if ((rInt1 >= 6) && (rInt1 <= 10))
		{
			players.at(players.size()-1).setSex('F');
		}

		players.at(players.size()-1).updateChips(Random(3000, 9000), "set");
	}
}

void Game::sCSlots(Player& mPlayer)
{
	bContinue2 = true;

	//Setup Slots
	setupSlots();

	while (bContinue2)
	{
		pChoice = mp_g.sCSMenu1();

		switch(pChoice)
		{
		case 1:
			mp_g.sCSTMenu();
			break;

		case 2:
			//Subtract chips from player if they have them, if not send back to casino menu
			if (sCChips >= 5)
			{
				sCChips -= 5;
			}

			else
			{
				cout << mp_g.mRMessage(2115) << endl;
				bContinue2 = false;

				break;
			}

			//Get a random value from each reel
			rInt1 = Random(0,19);
			rInt2 = Random(0,19);
			rInt3 = Random(0,19);
			rInt4 = Random(0,19);

			tReel1 = slots[0].at(rInt1);
			tReel2 = slots[1].at(rInt2);
			tReel3 = slots[2].at(rInt3);
			tReel4 = slots[3].at(rInt4);

			cout << tReel1 << " | " << tReel2 << " | " << tReel3 << " | " << tReel4 << endl << endl;

			//Call checking functions to see if any combinations have been made and then add returned chips to sCChip total
			sCChips += sCSCheck();

			break;

		default:
			bContinue2 = false;
			break;
		}
	}
}

void Game::sCBJack(Player& mPlayer)
{
	bContinue2 = true;

	//Setup AI
	setupCAI(false, true);

	//Add Dealer
	players.push_back(casinoAI());

	players.at(players.size()-1).setName("Dealer");
	players.at(players.size()-1).setRace("Human");
	players.at(players.size()-1).updateChips(2000000, "set"); //Dealer starts with 2 million chips; should be more than enough

	//Setup card deck
	setupCards();

	while (bContinue2)
	{
		pChoice = mp_g.sCBJMenu1();

		switch (pChoice)
		{
		case 1:
			mp_g.sCBJTMenu();
			break;

		case 2:

			bContinue = true;

			while (bContinue)
			{
				//TODO: Add menu to ask player if they want to play another round
				pChoice = mp_g.sCBJMenu1();

				switch(pChoice)
				{
				case 1:
					if (sCChips == 0)
					{
						cout << "You do not have any chips to bet with." << endl;
						bContinue = false;
						bContinue2 = false;
					}

					else
					{
						//TODO: Figure out a way to use multiple decks

						//Setup rDone and hFin values.  rDone will always be equal to the total number of hands currently in play (hands that are not status of stand, busted, or surrendered).
						//As hands finish add 1 to hFin until it equals rDone.  Splitting hands will increase rDone value to compensate
						//To start rDone = size of players vector + 1 (for the player)
						rDone = players.size() + 1;
						hFin = 0; //Reset this value each round

						//Check to make sure that the deck has enough cards to play the game
						//Calculated the number of cards required by multiplying the number of players by 5 as 5 cards is the max that any player may have
						if (sCCDeck.size() < (players.size() + 2) * 5) //If not enough cards to play a game assuming all AI players, the player, and the dealer get to five cards
						{
							setupCards(); //Setup a new deck
						}

						//Give starting cards to the player
						rInt1 = Random(0,sCCDeck.size());
						rInt2 = Random(0,sCCDeck.size());

						//Insert the cards into player hand
						if (sCPHand.size() > 0) //Make sure the vector is empty first
						{
							sCPHand.clear();
						}

						sCPHand.push_back(hand());

						sCPHand.at(0).cards.push_back(sCCDeck.at(rInt1));
						sCPHand.at(0).cards.push_back(sCCDeck.at(rInt2));

						//Remove cards from deck
						sCCDeck.erase(sCCDeck.begin() + rInt1);

						//If rInt1 is larger than rInt2 then no change to the value of rInt2 needs to be made, however if the reverse is true then 1 has to be subtracted
						if (rInt1 < rInt2)
						{
							rInt2 -= 1;
						}

						sCCDeck.erase(sCCDeck.begin() + rInt2);


						//Now do the same for the AI and dealer
						for (i = 0; i < players.size(); i++)
						{
							//Give starting cards to the player
							rInt1 = Random(0,sCCDeck.size());
							rInt2 = Random(0,sCCDeck.size());

							//Insert the cards into player hand
							if ( players.at(i).hands.size() > 0) //Make sure the vector is empty first
							{
								players.at(i).hands.clear();
							}

							//Add a hand for the AI to the vector
							players.at(i).hands.push_back(hand());

							//Add the cards to the int vector
							players.at(i).hands.at(0).cards.push_back(sCCDeck.at(rInt1));
							players.at(i).hands.at(0).cards.push_back(sCCDeck.at(rInt2));

							//Remove cards from deck
							sCCDeck.erase(sCCDeck.begin() + rInt1);

							//If rInt1 is larger than rInt2 then no change to the value of rInt2 needs to be made, however if the reverse is true then 1 has to be subtracted
							if (rInt1 < rInt2)
							{
								rInt2 -= 1;
							}

							sCCDeck.erase(sCCDeck.begin() + rInt2);
						}

						bContinue3 = true;

						//Set up the player's bet

						setupPBJBet(mPlayer);

						//Set up thg AI bets
						setupAIBJBet();

						while (bContinue3)
						{
							//Player's turn
							for (i = 0; i < sCPHand.size(); i++)
							{
								if ((sCPHand.at(i).state != "Stand") && (sCPHand.at(i).state != "Busted") && (sCPHand.at(i).state != "Surrendered"))
								{
									for (i2 = 0; i2 < rBets.size(); i2++)
									{
										if (rBets.at(i2).bName == mPlayer.getName())
										{
											pChoice = mp_g.sCBJMenu2(sCPHand.at(i).cards, sCChips, rBets.at(i2).chips);

											switch(pChoice)
											{
											case 1: //Hit
												//Add a card to the player's hand
												rInt1 = Random(0,sCCDeck.size());

												sCPHand.at(i).cards.push_back(sCCDeck.at(rInt1));

												//Remove cards from deck
												sCCDeck.erase(sCCDeck.begin() + rInt1);

												break;

											case 2: //Stand
												sCPHand.at(i).state = "Stand";
												hFin += 1;
												break;

											case 3: //Double Down
												//Search bets for the player's

												//We use the hand member to track which hand the bet is for in case the player splits
												//So we use i, the hand being operated on, to get the correct bet in the rBets vector
												//We do not need to check to make sure the player has the chips to double down because this was already checked in the msgProc function
												if (rBets.at(i2).hand == i)
												{
													rBets.at(i2).chips = rBets.at(i2).chips * 2;

													//Then add a card to the player's hand
													//Add a card to the player's hand
													rInt1 = Random(0,sCCDeck.size());

													sCPHand.at(i).cards.push_back(sCCDeck.at(rInt1));

													//Remove cards from deck
													sCCDeck.erase(sCCDeck.begin() + rInt1);

													//Then "stand" the player
													sCPHand.at(i).state = "Stand";
													hFin += 1;
												}

												break;

											case 4: //Split
												//Create a new hand for the player
												sCPHand.push_back(hand());

												//Now we need to take the second card from the first hand and move it to the second hand
												sCPHand.at(sCPHand.size()-1).cards.push_back(sCPHand.at(i+1).cards.at(1));

												//Now remove the card from the first hand
												sCPHand.at(i).cards.erase(sCPHand.at(i).cards.begin()+1);

												//Now duplicate the bet for the second hand
												//Dont have to check for enough chips as that is already done in the msgProc function
												rBets.push_back(bet());

												rBets.at(rBets.size()-1).bName = mPlayer.getName();
												rBets.at(rBets.size()-1).chips = rBets.at(i2).chips;
												rBets.at(rBets.size()-1).hand = i+1;

												//Now add a second card to each of the player's hands
												rInt1 = Random(0,sCCDeck.size());
												rInt2 = Random(0,sCCDeck.size());

												sCPHand.at(i).cards.push_back(sCCDeck.at(rInt1));
												sCPHand.at(i+1).cards.push_back(sCCDeck.at(rInt2));

												//Remove cards from deck
												sCCDeck.erase(sCCDeck.begin() + rInt1);

												//If rInt1 is larger than rInt2 then no change to the value of rInt2 needs to be made, however if the reverse is true then 1 has to be subtracted
												if (rInt1 < rInt2)
												{
													rInt2 -= 1;
												}

												sCCDeck.erase(sCCDeck.begin() + rInt2);

												rDone += 1;

												break;

											case 5: //Surrender
												cout << mPlayer.getName() << " surrenders!" << endl;

												if (rBets.at(i2).bName == mPlayer.getName())
												{
													//Give player back half of bet
													sCChips += rBets.at(i2).chips / 2;
												}

												sCPHand.at(i).state = "Surrendered";
												hFin += 1;

												break;

											default:
												break;

											}
										}
									}

									//Clear iCValues if it is not empty
									if (iCValues.size() > 0)
									{
										iCValues.clear();
									}

									//Check for bust or 5-card win								
									//Need to convert the cards to ints for further processing
									for (i2 = 0; i2 < sCPHand.at(i).cards.size(); i2++)
									{
										//If no face card or ten or ace
										if ((sCPHand.at(i).cards.at(i2).substr(1,1) != "T") && (sCPHand.at(i).cards.at(i2).substr(1,1) != "J") && (sCPHand.at(i).cards.at(i2).substr(1,1) != "Q") && (sCPHand.at(i).cards.at(i2).substr(1,1) != "K") && (sCPHand.at(i).cards.at(i2).substr(1,2) != "A1") && (sCPHand.at(i).cards.at(i2).substr(1,2) != "A2"))
										{
											card1 = atoi(sCPHand.at(i).cards.at(i2).substr(1,1).c_str()); //Might need to explode this out, could be too many functions being accessed at once here
											iCValues.push_back(card1);
										}

										else if (sCPHand.at(i).cards.at(i2).substr(1,1) == "T" || sCPHand.at(i).cards.at(i2).substr(1,1) == "J" || sCPHand.at(i).cards.at(i2).substr(1,1) == "Q" || sCPHand.at(i).cards.at(i2).substr(1,1) == "K")
										{
											iCValues.push_back(10);
										}

										//Aces will be handleded differently now; will make code changes once done with this section of code.  A1 signifies a value of 1 while A2 signifies a value of 11
										else if (sCPHand.at(i).cards.at(i2).substr(1,2) == "A1")
										{
											iCValues.push_back(1);
										}

										else if (sCPHand.at(i).cards.at(i2).substr(1,2) == "A2")
										{
											iCValues.push_back(11);
										}
									}

									tCValue = 0; //Zero this out now

									for (i2 = 0; i2 < iCValues.size(); i2++)
									{					
										tCValue += iCValues.at(i2); //Get the total value of all cards
									}

									if (iCValues.size() < 5)
									{
										if (tCValue > 21)
										{
											cout << mPlayer.getName() << " has busted out of this hand: total card values = " << tCValue << endl;
											sCPHand.at(i).state = "Busted";

											hFin += 1;
										}
									}

									else if (iCValues.size() == 5)
									{
										if (tCValue > 21)
										{
											cout << mPlayer.getName() << " has busted out of this hand: total card values = " << tCValue << endl;
											sCPHand.at(i).state = "Busted";

											hFin += 1;
										}

										else if (tCValue <= 21)
										{
											cout << mPlayer.getName() << " has reached five cards without busting and now stands." << endl;
											sCPHand.at(i).state = "Stand";

											hFin += 1;
										}
									}	
								}

								else
								{
									if (sCPHand.at(i).state == "Stand")
									{
										cout << mPlayer.getName() << " is standing." << endl;
									}

									else if (sCPHand.at(i).state == "Busted")
									{
										cout << mPlayer.getName() << " has busted out of this hand." << endl;
									}

									else if (sCPHand.at(i).state == "Surrendered")
									{
										cout << mPlayer.getName() << " has surrendered this hand." << endl;
									}
								}
							}

							//AI turns & dealer
							aiBJTurn();

							//If all hands are finished then we need to deal with the aftermath of wins/losses
							//All of these are checking against the Dealer
							if (rDone == hFin)
							{
								rPBJack(mPlayer);
							}
						}
					}

					break;

				default:
					bContinue = false;
					break;
				}				
			}

			break;

		default:
			bContinue2 = false;
			break;
		}
	}
}

int Game::sCSCheck()
{
	//Process the reels and check for combinations
	//Check for "Break" first because this overrides any combo
	if (tReel1 == "Break" || tReel2 == "Break" || tReel3 == "Break" || tReel4 == "Break")
	{
		cout << mp_g.mRMessage(2116) << endl;
		rChips = 0;
	}

	//Jackpot Combos
	else if ((tReel1 == "Jackpot") && (tReel2 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Jackpot"))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPJP4;
	}

	else if (((tReel1 == "Jackpot") && (tReel2 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Bar")) || ((tReel1 == "Jackpot") && (tReel2 == "Jackpot") && (tReel4 == "Jackpot") && (tReel3 == "Bar")) || ((tReel1 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Jackpot") && (tReel2 == "Bar")) || ((tReel1 == "Bar") && (tReel2 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Jackpot")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPJP3_Br;
	}

	else if (((tReel1 == "Jackpot") && (tReel2 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "7")) || ((tReel1 == "Jackpot") && (tReel2 == "Jackpot") && (tReel4 == "Jackpot") && (tReel3 == "7")) || ((tReel1 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Jackpot") && (tReel2 == "7")) || ((tReel1 == "7") && (tReel2 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Jackpot")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPJP3_7;
	}

	else if (((tReel1 == "Jackpot") && (tReel2 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Heart")) || ((tReel1 == "Jackpot") && (tReel2 == "Jackpot") && (tReel4 == "Jackpot") && (tReel3 == "Heart")) || ((tReel1 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Jackpot") && (tReel2 == "Heart")) || ((tReel1 == "Heart") && (tReel2 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Jackpot")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPJP3_H;
	}

	else if (((tReel1 == "Jackpot") && (tReel2 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Bell")) || ((tReel1 == "Jackpot") && (tReel2 == "Jackpot") && (tReel4 == "Jackpot") && (tReel3 == "Bell")) || ((tReel1 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Jackpot") && (tReel2 == "Bell")) || ((tReel1 == "Bell") && (tReel2 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Jackpot")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPJP3_B;
	}

	else if (((tReel1 == "Jackpot") && (tReel2 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "1" || tReel4 == "2" || tReel4 == "3" || tReel4 == "4" || tReel4 == "5" || tReel4 == "6" || tReel4 == "8" || tReel4 == "9" || tReel4 == "10" || tReel4 == "11" || tReel4 == "12" || tReel4 == "13" || tReel4 == "14" || tReel4 == "15")) || ((tReel1 == "Jackpot") && (tReel2 == "Jackpot") && (tReel4 == "Jackpot") && (tReel3 == "1" || tReel3 == "2" || tReel3 == "3" || tReel3 == "4" || tReel3 == "5" || tReel3 == "6" || tReel3 == "8" || tReel3 == "9" || tReel3 == "10" || tReel3 == "11" || tReel3 == "12" || tReel3 == "13" || tReel3 == "14" || tReel3 == "15")) || ((tReel1 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Jackpot") && (tReel2 == "1" || tReel2 == "2" || tReel2 == "3" || tReel2 == "4" || tReel2 == "5" || tReel2 == "6" || tReel2 == "8" || tReel2 == "9" || tReel2 == "10" || tReel2 == "11" || tReel2 == "12" || tReel2 == "13" || tReel2 == "14" || tReel2 == "15")) || ((tReel1 == "1" || tReel1 == "2" || tReel1 == "3" || tReel1 == "4" || tReel1 == "5" || tReel1 == "6" || tReel1 == "8" || tReel1 == "9" || tReel1 == "10" || tReel1 == "11" || tReel1 == "12" || tReel1 == "13" || tReel1 == "14" || tReel1 == "15") && (tReel2 == "Jackpot") && (tReel3 == "Jackpot") && (tReel4 == "Jackpot")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPJP3_N;
	}

	//Bar Combos
	else if ((tReel1 == "Bar") && (tReel2 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Bar"))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPBr4;
	}

	else if (((tReel1 == "Bar") && (tReel2 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Jackpot")) || ((tReel1 == "Bar") && (tReel2 == "Bar") && (tReel4 == "Bar") && (tReel3 == "Jackpot")) || ((tReel1 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Bar") && (tReel2 == "Jackpot")) || ((tReel1 == "Jackpot") && (tReel2 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Bar")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPBr3_J;
	}

	else if (((tReel1 == "Bar") && (tReel2 == "Bar") && (tReel3 == "Bar") && (tReel4 == "7")) || ((tReel1 == "Bar") && (tReel2 == "Bar") && (tReel4 == "Bar") && (tReel3 == "7")) || ((tReel1 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Bar") && (tReel2 == "7")) || ((tReel1 == "7") && (tReel2 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Bar")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPBr3_7;
	}

	else if (((tReel1 == "Bar") && (tReel2 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Heart")) || ((tReel1 == "Bar") && (tReel2 == "Bar") && (tReel4 == "Bar") && (tReel3 == "Heart")) || ((tReel1 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Bar") && (tReel2 == "Heart")) || ((tReel1 == "Heart") && (tReel2 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Bar")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPBr3_H;
	}

	else if (((tReel1 == "Bar") && (tReel2 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Bell")) || ((tReel1 == "Bar") && (tReel2 == "Bar") && (tReel4 == "Bar") && (tReel3 == "Bell")) || ((tReel1 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Bar") && (tReel2 == "Bell")) || ((tReel1 == "Bell") && (tReel2 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Bar")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPBr3_B;
	}

	else if (((tReel1 == "Bar") && (tReel2 == "Bar") && (tReel3 == "Bar") && (tReel4 == "1" || tReel4 == "2" || tReel4 == "3" || tReel4 == "4" || tReel4 == "5" || tReel4 == "6" || tReel4 == "8" || tReel4 == "9" || tReel4 == "10" || tReel4 == "11" || tReel4 == "12" || tReel4 == "13" || tReel4 == "14" || tReel4 == "15")) || ((tReel1 == "Bar") && (tReel2 == "Bar") && (tReel4 == "Bar") && (tReel3 == "1" || tReel3 == "2" || tReel3 == "3" || tReel3 == "4" || tReel3 == "5" || tReel3 == "6" || tReel3 == "8" || tReel3 == "9" || tReel3 == "10" || tReel3 == "11" || tReel3 == "12" || tReel3 == "13" || tReel3 == "14" || tReel3 == "15")) || ((tReel1 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Bar") && (tReel2 == "1" || tReel2 == "2" || tReel2 == "3" || tReel2 == "4" || tReel2 == "5" || tReel2 == "6" || tReel2 == "8" || tReel2 == "9" || tReel2 == "10" || tReel2 == "11" || tReel2 == "12" || tReel2 == "13" || tReel2 == "14" || tReel2 == "15")) || ((tReel1 == "1" || tReel1 == "2" || tReel1 == "3" || tReel1 == "4" || tReel1 == "5" || tReel1 == "6" || tReel1 == "8" || tReel1 == "9" || tReel1 == "10" || tReel1 == "11" || tReel1 == "12" || tReel1 == "13" || tReel1 == "14" || tReel1 == "15") && (tReel2 == "Bar") && (tReel3 == "Bar") && (tReel4 == "Bar")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPBr3_N;
	}

	//7 Combos
	else if ((tReel1 == "7") && (tReel2 == "7") && (tReel3 == "7") && (tReel4 == "7"))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSP74;
	}

	else if (((tReel1 == "7") && (tReel2 == "7") && (tReel3 == "7") && (tReel4 == "Jackpot")) || ((tReel1 == "7") && (tReel2 == "7") && (tReel4 == "7") && (tReel3 == "Jackpot")) || ((tReel1 == "7") && (tReel3 == "7") && (tReel4 == "7") && (tReel2 == "Jackpot")) || ((tReel1 == "Jackpot") && (tReel2 == "7") && (tReel3 == "7") && (tReel4 == "7")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips =gv::cSP73_J;
	}

	else if (((tReel1 == "7") && (tReel2 == "7") && (tReel3 == "7") && (tReel4 == "Bar")) || ((tReel1 == "7") && (tReel2 == "7") && (tReel4 == "7") && (tReel3 == "Bar")) || ((tReel1 == "7") && (tReel3 == "7") && (tReel4 == "7") && (tReel2 == "Bar")) || ((tReel1 == "Bar") && (tReel2 == "7") && (tReel3 == "7") && (tReel4 == "7")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSP73_Br;
	}

	else if (((tReel1 == "7") && (tReel2 == "7") && (tReel3 == "7") && (tReel4 == "Heart")) || ((tReel1 == "7") && (tReel2 == "7") && (tReel4 == "7") && (tReel3 == "Heart")) || ((tReel1 == "7") && (tReel3 == "7") && (tReel4 == "7") && (tReel2 == "Heart")) || ((tReel1 == "Heart") && (tReel2 == "7") && (tReel3 == "7") && (tReel4 == "7")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSP73_H;
	}

	else if (((tReel1, tReel2, tReel3 == "7") && (tReel4 == "Bell")) || ((tReel1, tReel2, tReel4 == "7") && (tReel3 == "Bell")) || ((tReel1, tReel3, tReel4 == "7") && (tReel2 == "Bell")) || ((tReel1 == "Bell") && (tReel2, tReel3, tReel4 == "7")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSP73_B;
	}

	else if (((tReel1 == "7") && (tReel2 == "7") && (tReel3 == "7") && (tReel4 == "1" || tReel4 == "2" || tReel4 == "3" || tReel4 == "4" || tReel4 == "5" || tReel4 == "6" || tReel4 == "8" || tReel4 == "9" || tReel4 == "10" || tReel4 == "11" || tReel4 == "12" || tReel4 == "13" || tReel4 == "14" || tReel4 == "15")) || ((tReel1 == "7") && (tReel2 == "7") && (tReel4 == "7") && (tReel3 == "1" || tReel3 == "2" || tReel3 == "3" || tReel3 == "4" || tReel3 == "5" || tReel3 == "6" || tReel3 == "8" || tReel3 == "9" || tReel3 == "10" || tReel3 == "11" || tReel3 == "12" || tReel3 == "13" || tReel3 == "14" || tReel3 == "15")) || ((tReel1 == "7") && (tReel3 == "7") && (tReel4 == "7") && (tReel2 == "1" || tReel2 == "2" || tReel2 == "3" || tReel2 == "4" || tReel2 == "5" || tReel2 == "6" || tReel2 == "8" || tReel2 == "9" || tReel2 == "10" || tReel2 == "11" || tReel2 == "12" || tReel2 == "13" || tReel2 == "14" || tReel2 == "15")) || ((tReel1 == "1" || tReel1 == "2" || tReel1 == "3" || tReel1 == "4" || tReel1 == "5" || tReel1 == "6" || tReel1 == "8" || tReel1 == "9" || tReel1 == "10" || tReel1 == "11" || tReel1 == "12" || tReel1 == "13" || tReel1 == "14" || tReel1 == "15") && (tReel2 == "7") && (tReel3 == "7") && (tReel4 == "7")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSP73_N;
	}

	//Heart Combos
	else if ((tReel1 == "Heart") && (tReel2 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Heart"))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPH4;
	}

	else if (((tReel1 == "Heart") && (tReel2 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Jackpot")) || ((tReel1 == "Heart") && (tReel2 == "Heart") && (tReel4 == "Heart") && (tReel3 == "Jackpot")) || ((tReel1 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Heart") && (tReel2 == "Jackpot")) || ((tReel1 == "Jackpot") && (tReel2 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Heart")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPH3_J;
	}

	else if (((tReel1 == "Heart") && (tReel2 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Bar")) || ((tReel1 == "Heart") && (tReel2 == "Heart") && (tReel4 == "Heart") && (tReel3 == "Bar")) || ((tReel1 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Heart") && (tReel2 == "Bar")) || ((tReel1 == "Bar") && (tReel2 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Heart")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPH3_Br;
	}

	else if (((tReel1 == "Heart") && (tReel2 == "Heart") && (tReel3 == "Heart") && (tReel4 == "7")) || ((tReel1 == "Heart") && (tReel2 == "Heart") && (tReel4 == "Heart") && (tReel3 == "7")) || ((tReel1 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Heart") && (tReel2 == "7")) || ((tReel1 == "7") && (tReel2 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Heart")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPH3_7;
	}

	else if (((tReel1 == "Heart") && (tReel2 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Bell")) || ((tReel1 == "Heart") && (tReel2 == "Heart") && (tReel4 == "Heart") && (tReel3 == "Bell")) || ((tReel1 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Heart") && (tReel2 == "Bell")) || ((tReel1 == "Bell") && (tReel2 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Heart")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPH3_B;
	}

	else if (((tReel1 == "Heart") && (tReel2 == "Heart") && (tReel3 == "Heart") && (tReel4 == "1" || tReel4 == "2" || tReel4 == "3" || tReel4 == "4" || tReel4 == "5" || tReel4 == "6" || tReel4 == "8" || tReel4 == "9" || tReel4 == "10" || tReel4 == "11" || tReel4 == "12" || tReel4 == "13" || tReel4 == "14" || tReel4 == "15")) || ((tReel1 == "Heart") && (tReel2 == "Heart") && (tReel4 == "Heart") && (tReel3 == "1" || tReel3 == "2" || tReel3 == "3" || tReel3 == "4" || tReel3 == "5" || tReel3 == "6" || tReel3 == "8" || tReel3 == "9" || tReel3 == "10" || tReel3 == "11" || tReel3 == "12" || tReel3 == "13" || tReel3 == "14" || tReel3 == "15")) || ((tReel1 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Heart") && (tReel2 == "1" || tReel2 == "2" || tReel2 == "3" || tReel2 == "4" || tReel2 == "5" || tReel2 == "6" || tReel2 == "8" || tReel2 == "9" || tReel2 == "10" || tReel2 == "11" || tReel2 == "12" || tReel2 == "13" || tReel2 == "14" || tReel2 == "15")) || ((tReel1 == "1" || tReel1 == "2" || tReel1 == "3" || tReel1 == "4" || tReel1 == "5" || tReel1 == "6" || tReel1 == "8" || tReel1 == "9" || tReel1 == "10" || tReel1 == "11" || tReel1 == "12" || tReel1 == "13" || tReel1 == "14" || tReel1 == "15") && (tReel2 == "Heart") && (tReel3 == "Heart") && (tReel4 == "Heart")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPH3_N;
	}

	//Bell Combos
	else if ((tReel1 == "Bell") && (tReel2 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Bell"))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPB4;
	}

	else if (((tReel1 == "Bell") && (tReel2 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Jackpot")) || ((tReel1 == "Bell") && (tReel2 == "Bell") && (tReel4 == "Bell") && (tReel3 == "Jackpot")) || ((tReel1 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Bell") && (tReel2 == "Jackpot")) || ((tReel1 == "Jackpot") && (tReel2 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Bell")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPB3_J;
	}

	else if (((tReel1 == "Bell") && (tReel2 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Bar")) || ((tReel1 == "Bell") && (tReel2 == "Bell") && (tReel4 == "Bell") && (tReel3 == "Bar")) || ((tReel1 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Bell") && (tReel2 == "Bar")) || ((tReel1 == "Bar") && (tReel2 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Bell")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPB3_Br;
	}

	else if (((tReel1 == "Bell") && (tReel2 == "Bell") && (tReel3 == "Bell") && (tReel4 == "7")) || ((tReel1 == "Bell") && (tReel2 == "Bell") && (tReel4 == "Bell") && (tReel3 == "7")) || ((tReel1 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Bell") && (tReel2 == "7")) || ((tReel1 == "7") && (tReel2 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Bell")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPB3_7;
	}

	else if (((tReel1 == "Bell") && (tReel2 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Heart")) || ((tReel1 == "Bell") && (tReel2 == "Bell") && (tReel4 == "Bell") && (tReel3 == "Heart")) || ((tReel1 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Bell") && (tReel2 == "Heart")) || ((tReel1 == "Heart") && (tReel2 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Bell")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPB3_H;
	}

	else if (((tReel1 == "Bell") && (tReel2 == "Bell") && (tReel3 == "Bell") && (tReel4 == "1" || tReel4 == "2" || tReel4 == "3" || tReel4 == "4" || tReel4 == "5" || tReel4 == "6" || tReel4 == "8" || tReel4 == "9" || tReel4 == "10" || tReel4 == "11" || tReel4 == "12" || tReel4 == "13" || tReel4 == "14" || tReel4 == "15")) || ((tReel1 == "Bell") && (tReel2 == "Bell") && (tReel4 == "Bell") && (tReel3 == "1" || tReel3 == "2" || tReel3 == "3" || tReel3 == "4" || tReel3 == "5" || tReel3 == "6" || tReel3 == "8" || tReel3 == "9" || tReel3 == "10" || tReel3 == "11" || tReel3 == "12" || tReel3 == "13" || tReel3 == "14" || tReel3 == "15")) || ((tReel1 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Bell") && (tReel2 == "1" || tReel2 == "2" || tReel2 == "3" || tReel2 == "4" || tReel2 == "5" || tReel2 == "6" || tReel2 == "8" || tReel2 == "9" || tReel2 == "10" || tReel2 == "11" || tReel2 == "12" || tReel2 == "13" || tReel2 == "14" || tReel2 == "15")) || ((tReel1 == "1" || tReel1 == "2" || tReel1 == "3" || tReel1 == "4" || tReel1 == "5" || tReel1 == "6" || tReel1 == "8" || tReel1 == "9" || tReel1 == "10" || tReel1 == "11" || tReel1 == "12" || tReel1 == "13" || tReel1 == "14" || tReel1 == "15") && (tReel2 == "Bell") && (tReel3 == "Bell") && (tReel4 == "Bell")))
	{
		cout << mp_g.mRMessage(2117) << endl;

		rChips = gv::cSPB3_N;
	}

	else //Do this so we can convert the reel values as required w/o breaking the if/else if/else chain
	{
		//If the value of a reel is a number but not 7, then convert it to a number and store in tReel#I variables
		if ((tReel1 != "Jackpot") && (tReel1 != "Break") && (tReel1 != "Bar") && (tReel1 != "7") && (tReel1 != "Heart") && (tReel1 != "Bell"))
		{
			tReel1I = atoi(tReel1.c_str());
		}

		if ((tReel2 != "Jackpot") && (tReel2 != "Break") && (tReel2 != "Bar") && (tReel2 != "7") && (tReel2 != "Heart") && (tReel2 != "Bell"))
		{
			tReel2I = atoi(tReel2.c_str());
		}

		if ((tReel3 != "Jackpot") && (tReel3 != "Break") && (tReel3 != "Bar") && (tReel3 != "7") && (tReel3 != "Heart") && (tReel3 != "Bell"))
		{
			tReel3I = atoi(tReel3.c_str());
		}

		if ((tReel4 != "Jackpot") && (tReel4 != "Break") && (tReel4 != "Bar") && (tReel4 != "7") && (tReel4 != "Heaart") && (tReel4 != "Bell"))
		{
			tReel4I = atoi(tReel4.c_str());
		}

		//Number Combos
		if ((tReel1I & tReel2I & tReel3I & tReel4I))
		{
			cout << mp_g.mRMessage(2117) << endl;

			rChips = gv::cSPN4;
		}

		else if (((tReel1I & tReel2I & tReel3I) && (tReel4 == "Jackpot")) || ((tReel1I & tReel2I & tReel4I) && (tReel3 == "Jackpot")) || ((tReel1I & tReel3I & tReel4I) && (tReel2 == "Jackpot")) || ((tReel1 == "Jackpot") && (tReel2I & tReel3I & tReel4I)))
		{
			cout << mp_g.mRMessage(2117) << endl;

			rChips = gv::cSPN3_J;
		}

		else if (((tReel1I & tReel2I & tReel3I) && (tReel4 == "Bar")) || ((tReel1I & tReel2I & tReel4I) && (tReel3 == "Bar")) || ((tReel1I & tReel3I & tReel4I) && (tReel2 == "Bar")) || ((tReel1 == "Bar") && (tReel2I & tReel3I & tReel4I)))
		{
			cout << mp_g.mRMessage(2117) << endl;

			rChips = gv::cSPN3_Br;
		}

		else if (((tReel1I & tReel2I & tReel3I) && (tReel4 == "7")) || ((tReel1I & tReel2I & tReel4I) && (tReel3 == "7")) || ((tReel1I & tReel3I & tReel4I) && (tReel2 == "7")) || ((tReel1 == "7") && (tReel2I & tReel3I & tReel4I)))
		{
			cout << mp_g.mRMessage(2117) << endl;

			rChips = gv::cSPN3_7;
		}

		else if (((tReel1I & tReel2I & tReel3I) && (tReel4 == "Heart")) || ((tReel1I & tReel2I & tReel4I) && (tReel3 == "Heart")) || ((tReel1I & tReel3I & tReel4I) && (tReel2 == "Heart")) || ((tReel1 == "Heart") && (tReel2I & tReel3I & tReel4I)))
		{
			cout << mp_g.mRMessage(2117) << endl;

			rChips = gv::cSPN3_H;
		}

		else if (((tReel1I & tReel2I & tReel3I) && (tReel4 == "Bell")) || ((tReel1I & tReel2I & tReel4I) && (tReel3 == "Bell")) || ((tReel1I & tReel3I & tReel4I) && (tReel2 == "Bell")) || ((tReel1 == "Bell") && (tReel2I & tReel3I & tReel4I)))
		{
			cout << mp_g.mRMessage(2117) << endl;

			rChips = gv::cSPN3_B;
		}

		else
		{
			cout << "No combination match.  Please play again." << endl;
			rChips = 0;
		}
	}

	return rChips;
}

void Game::setupPBJBet(Player& mPlayer)
{
	rInt4 = mp_g.sCMBJBet(sCPHand.at(0).cards, sCChips);

	rBets.push_back(bet());

	cout << mPlayer.getName() << " has bet " << rInt4 << " chips." << endl;

	//Save the bet data
	rBets.at(rBets.size()-1).chips = rInt4;
	rBets.at(rBets.size()-1).bName = mPlayer.getName();
	rBets.at(rBets.size()-1).hand = 0;

	sCChips -= rInt4;
}

void Game::setupAIBJBet()
{
	for (i = 0; i < players.size(); i++)
	{
		if ((players.at(i).getChips() == 0) && (players.at(i).getName() != "Dealer"))
		{
			cout << players.at(i).getName() << " has left the table." << endl;

			//Remove this player from the players vector
			players.erase(players.begin()+i);
		}

		else
		{
			if ((players.at(i).getChips() <= 100000 * players.size()) && (players.at(i).getName() == "Dealer"))
			{
				cout << "Dealer has run out of chips.  Please wait while the table is restocked" << endl;

				//TODO: Create a timer like is used in the mining code
			}

			//Dealer does not bet
			if (players.at(i).getName() != "Dealer")
			{
				//Get base bet
				rInt1 = Random(1,players.at(i).getChips()); //We use max chips on high because we do not know how many chips the AI might have, this value will get edited later on as well.

				//Get substringed values from cards
				tCard1 = players.at(i).hands.at(0).cards.at(0).substr(1,1);
				tCard2 =  players.at(i).hands.at(0).cards.at(1).substr(1,1);

				if (((tCard1 == "A") && (tCard2 == "T" || tCard2 == "J" || tCard2 == "Q" || tCard2 == "K")) || ((tCard2 == "A") && (tCard1 == "T" || tCard1 == "J" || tCard1 == "Q" || tCard1 == "K"))) //If AI has blackjack
				{
					//Then we need to adjust the base bet

					//First we need to find out if the bet is less than max chips
					if (rInt1 < players.at(i).getChips())
					{
						//If it is less then we need to add 7x to the base bet divided by 6
						rInt1 = (rInt1 * 7) / 6;

						if (rInt1 > players.at(i).getChips()) //Now we need to check again if the bet is greater than the max chips
						{
							//This time if it is, divide the bet by eith.  This should be more than enough to bring it back under the max chips unless something goes wrong
							rInt1 = rInt1 / 8;
						}
					}

					else //Else if the bet is equal to all of AI's chips, divide by three
					{
						rInt1 = rInt1 / 3;
					}
				}

				else if ((tCard1 == "T" || tCard1 == "J" || tCard1 == "Q" || tCard1 == "K") && (tCard2 == "T" || tCard2 == "J" || tCard2 == "Q" || tCard2 == "K")) //Check for 20; can only get to 20 in two cards with 10 or face card
				{
					if (rInt1 < players.at(i).getChips())
					{
						//If it is less then we need to add 6x to the base bet divided by 5
						rInt1 = (rInt1 * 6) / 5;

						if (rInt1 > players.at(i).getChips()) //Now we need to check again if the bet is greater than the max chips
						{
							//This time if it is, divide the bet by seven.  This should be more than enough to bring it back under the max chips unless something goes wrong
							rInt1 = rInt1 / 7;
						}
					}

					else //Else if the bet is equal to all of AI's chips, divide by four
					{
						rInt1 = rInt1 / 4;
					}
				}

				else if (((tCard1 == "T" || tCard1 == "J" || tCard1 == "Q" || tCard1 == "K") && (tCard2 == "9")) || ((tCard2 == "T" || tCard2 == "J" || tCard2 == "Q" || tCard2 == "K") && (tCard1 == "9"))) //Check for 19; can only get to 19 in two cards with 10/face card + 9
				{
					if (rInt1 < players.at(i).getChips())
					{
						//If it is less then we need to add 5x to the base bet divided by 4
						rInt1 = (rInt1 * 5) / 4;

						if (rInt1 > players.at(i).getChips()) //Now we need to check again if the bet is greater than the max chips
						{
							//This time if it is, divide the bet by six.  This should be more than enough to bring it back under the max chips unless something goes wrong
							rInt1 = rInt1 / 6;
						}
					}

					else //Else if the bet is equal to all of AI's chips, divide by five
					{
						rInt1 = rInt1 / 5;
					}
				}

				else if ((((tCard1 == "T" || tCard1 == "J" || tCard1 == "Q" || tCard1 == "K") && (tCard2 == "8")) || ((tCard2 == "T" || tCard2 == "J" || tCard2 == "Q" || tCard2 == "K") && (tCard1 == "8"))) || ((tCard1 == "9") && (tCard2 == "9"))) //Check for 18; can get to 18 in two cards with 10/face card + 8 OR double nines
				{
					if ((tCard1 == "9") && (tCard2 == "9")) //If 18 is achieved through a double, use different values
					{
						if (rInt1 < players.at(i).getChips())
						{
							//If it is less then we need to add 4x to the base bet divided by 2
							rInt1 = (rInt1 * 4) / 2;

							if (rInt1 > players.at(i).getChips()) //Now we need to check again if the bet is greater than the max chips
							{
								//This time if it is, divide the bet by six.  This should be more than enough to bring it back under the max chips unless something goes wrong
								rInt1 = rInt1 / 6;
							}
						}

						else //Else if the bet is equal to all of AI's chips, divide by five
						{
							rInt1 = rInt1 / 5;
						}
					}

					else //Else if gotten with 8 + T/FC then use these values
					{
						if (rInt1 < players.at(i).getChips())
						{
							//If it is less then we need to add 4x to the base bet divided by 3
							rInt1 = (rInt1 * 4) / 3;

							if (rInt1 > players.at(i).getChips()) //Now we need to check again if the bet is greater than the max chips
							{
								//This time if it is, divide the bet by five.  This should be more than enough to bring it back under the max chips unless something goes wrong
								rInt1 = rInt1 / 5;
							}
						}

						else //Else if the bet is equal to all of AI's chips, divide by six
						{
							rInt1 = rInt1 / 6;
						}
					}
				}

				else if ((((tCard1 == "T" || tCard1 == "J" || tCard1 == "Q" || tCard1 == "K") && (tCard2 == "7")) || ((tCard2 == "T" || tCard2 == "J" || tCard2 == "Q" || tCard2 == "K") && (tCard1 == "7"))) || (((tCard1 == "8") && (tCard2 == "9")) || ((tCard1 == "9") && (tCard2 == "8")))) //Check for 17; can get to 17 in two cards with 10/face card + 8 OR nine and 8
				{
					if (rInt1 < players.at(i).getChips())
					{
						//If it is less then we need to add 3x to the base bet divided by 2
						rInt1 = (rInt1 * 3) / 2;

						if (rInt1 > players.at(i).getChips()) //Now we need to check again if the bet is greater than the max chips
						{
							//This time if it is, divide the bet by four.  This should be more than enough to bring it back under the max chips unless something goes wrong
							rInt1 = rInt1 / 4;
						}
					}

					else //Else if the bet is equal to all of AI's chips, divide by seven
					{
						rInt1 = rInt1 / 7;
					}
				}

				//For the next conditional we need to get int values for the cards
				//Anything 16 or under is considered non-special territory so betting will be done on all values there in on a consistant set of values

				else
				{
					//First we need to account for non-int values and change them to ints
					if (tCard1 == "T" || tCard1 == "J" || tCard1 == "Q" || tCard1 == "K") //Change value to 10 if any of these is true
					{
						tCard1 = "10";
					}

					else if (tCard1 == "A") //If this is true then we need to choose between 11 or 1; 1 will be more common than 11.
					{
						rInt2 = Random(1,20);

						if ((rInt2 >= 1) && (rInt2 < 14))
						{
							tCard1 == "1";
							tCard3 = players.at(i).hands.at(0).cards.at(0);
							tCard4 = tCard3.substr(2,4);
							players.at(i).hands.at(0).cards.at(0) = "A1" + tCard4;
						}

						else if (rInt2 >= 14)
						{
							tCard1 == "11";
							tCard3 = players.at(i).hands.at(0).cards.at(0);
							tCard4 = tCard3.substr(2,4);
							players.at(i).hands.at(0).cards.at(0) = "A2" + tCard4;
						}
					}

					if (tCard2 == "T" || tCard2 == "J" || tCard2 == "Q" || tCard2 == "K")
					{
						tCard2 = "10";
					}

					else if (tCard2 == "A")
					{
						rInt2 = Random(1,20);

						if ((rInt2 >= 1) && (rInt2 < 14))
						{
							tCard2 == "1";
							tCard3 = players.at(i).hands.at(0).cards.at(1);
							tCard4 = tCard3.substr(2,4);
							players.at(i).hands.at(0).cards.at(1) = "A1" + tCard4;
						}

						else if (rInt2 >= 14)
						{
							tCard2 == "11";
							tCard3 = players.at(i).hands.at(0).cards.at(1);
							tCard4 = tCard3.substr(2,4);
							players.at(i).hands.at(0).cards.at(1) = "A2" + tCard4;
						}
					}

					card1 = atoi(tCard1.c_str());
					card2 = atoi(tCard2.c_str());

					//Once again, we check for double values
					if (card1 == card2)
					{
						if (rInt1 < players.at(i).getChips())
						{
							//If it is less then we need to add 4x to the base bet divided by 2
							rInt1 = (rInt1 * 4) / 2;

							if (rInt1 > players.at(i).getChips()) //Now we need to check again if the bet is greater than the max chips
							{
								//This time if it is, divide the bet by six.  This should be more than enough to bring it back under the max chips unless something goes wrong
								rInt1 = rInt1 / 6;
							}
						}

						else //Else if the bet is equal to all of AI's chips, divide by five
						{
							rInt1 = rInt1 / 5;
						}
					}

					//We have to check for values equal to and over 17 because of the chance for ace being 11
					else if (card1 + card2 >= 17)
					{
						if (rInt1 < players.at(i).getChips())
						{
							//If it is less then we need to add 4x to the base bet divided by 2
							rInt1 = (rInt1 * 6) / 2;

							if (rInt1 > players.at(i).getChips()) //Now we need to check again if the bet is greater than the max chips
							{
								//This time if it is, divide the bet by six.  This should be more than enough to bring it back under the max chips unless something goes wrong
								rInt1 = rInt1 / 4;
							}
						}

						else //Else if the bet is equal to all of AI's chips, divide by five
						{
							rInt1 = rInt1 / 7;
						}
					}

					//If total of both cards is under 17
					else if (card1 + card2 < 17)
					{
						if (rInt1 < players.at(i).getChips())
						{
							//If it is less then we need to add 2x to the base bet
							rInt1 = (rInt1 * 2);

							if (rInt1 > players.at(i).getChips()) //Now we need to check again if the bet is greater than the max chips
							{
								//This time if it is, divide the bet by three.  This should be more than enough to bring it back under the max chips unless something goes wrong
								rInt1 = rInt1 / 3;
							}
						}

						else //Else if the bet is equal to all of AI's chips, divide by eight
						{
							rInt1 = rInt1 / 8;
						}
					}
				}
			}

			//Now save the bet data
			rBets.push_back(bet());

			cout << players.at(i).getName() << " has bet " << rInt1 << " chips." << endl;

			rBets.at(rBets.size()-1).chips = rInt1;
			rBets.at(rBets.size()-1).bName = players.at(i).getName();
			rBets.at(rBets.size()-1).hand = 0;

			players.at(i).updateChips(rInt4, "sub");
		}
	}
}

void Game::aiBJTurn()
{
	//TODO: On values 16 and lower add a chance for double down
	for (i = 0; i < players.size(); i++)
	{
		for (i2 = 0; i2 < players.at(i).hands.size(); i2++)
		{
			//Check to make sure the AI player is still in the game
			if ((players.at(i).hands.at(i2).state != "Busted") && (players.at(i).hands.at(i2).state != "Surrendered") && (players.at(i).hands.at(i2).state != "Stand"))
			{
				for (i3 = 0; i3 < players.at(i).hands.at(i2).cards.size(); i3++)
				{
					//First time through we will want to check for specific two-card situations so these will be based on the number of cards in the hand
					//Check for the highest order of possibilities to the lowest; following the same method we used above for the bet calculations for AI.
					//Dealer will always stand at a value greater than 16, AI (non-dealer) will always stand at 19 or higher but will have decreasing chances to stand for 18 and 17; will never stand on 16 or lower

					if (players.at(i).hands.at(i2).cards.at(i3).size() == 2) //If the AI hand has two cards
					{
						//Get the first characters of the card string
						tCard1 = players.at(i).hands.at(i2).cards.at(0).substr(1,2);
						tCard2 = players.at(i).hands.at(i2).cards.at(1).substr(1,1);

						//Get the first characters of the card string
						tCard3 = players.at(i).hands.at(i2).cards.at(1).substr(1,2);
						tCard4 = players.at(i).hands.at(i2).cards.at(0).substr(1,1);

						//Separate checks for card 1/2 as ace because of how we now track the 1/11 value of the card; unrealistic as if you had blackjack you would go with 11 and not 1 but will fix it in 0.6

						//Check for blackjack
						if ((tCard1 == "A2") && (tCard2 == "T" || tCard2 == "J" || tCard2 == "Q" || tCard2 == "K"))
						{
							//AI/Dealer will stand
							players.at(i).hands.at(i2).state = "Stand";
							hFin += 1;
						}

						else if ((tCard3 == "A2") && (tCard4 == "T" || tCard4 == "J" || tCard4 == "Q" || tCard4 == "K"))
						{
							//AI/Dealer will stand
							players.at(i).hands.at(i2).state = "Stand";
							hFin += 1;
						}

						//Next check for 20 to 17 with ace
						//20
						else if ((tCard1 == "A2") && (tCard2 == "9")) //11+9
						{
							//AI/Dealer will stand
							players.at(i).hands.at(i2).state = "Stand";
							hFin += 1;
						}

						else if ((tCard3 == "A2") && (tCard4 == "9"))
						{
							//AI/Dealer will stand
							players.at(i).hands.at(i2).state = "Stand";
							hFin += 1;
						}

						//19
						else if ((tCard1 == "A2") && (tCard2 == "8")) //11+8
						{
							//AI/Dealer will stand
							players.at(i).hands.at(i2).state = "Stand";
							hFin += 1;
						}

						else if ((tCard3 == "A2") && (tCard4 == "8"))
						{
							//AI/Dealer will stand
							players.at(i).hands.at(i2).state = "Stand";
							hFin += 1;
						}

						//18
						else if ((tCard1 == "A2") && (tCard2 == "7")) //11+7
						{
							//Dealer will stand
							if (players.at(i).getName() == "Dealer")
							{
								players.at(i).hands.at(i2).state = "Stand";
								hFin += 1;
							}

							else //If not dealer
							{
								rInt4 = Random(1,25);

								if ((rInt4 >= 1) && (rInt4 < 23)) //Stand
								{
									players.at(i).hands.at(i2).state = "Stand";
									hFin += 1;
								}

								if (rInt4 >= 23) //Hit
								{
									//Add a card to the player's hand
									rInt3 = Random(0,sCCDeck.size());

									players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

									//Remove cards from deck
									sCCDeck.erase(sCCDeck.begin() + rInt3);
								}
							}
						}

						else if ((tCard3 == "A2") && (tCard4 == "7")) //11+7
						{
							//Dealer will stand
							if (players.at(i).getName() == "Dealer")
							{
								players.at(i).hands.at(i2).state = "Stand";
								hFin += 1;
							}

							else //If not dealer
							{
								rInt4 = Random(1,25);

								if ((rInt4 >= 1) && (rInt4 < 23)) //Stand
								{
									players.at(i).hands.at(i2).state = "Stand";
									hFin += 1;
								}

								if (rInt4 >= 23) //Hit
								{
									//Add a card to the player's hand
									rInt3 = Random(0,sCCDeck.size());

									players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

									//Remove cards from deck
									sCCDeck.erase(sCCDeck.begin() + rInt3);
								}
							}
						}

						//17
						else if ((tCard1 == "A2") && (tCard2 == "6")) //11+6
						{
							//Dealer will stand
							if (players.at(i).getName() == "Dealer")
							{
								players.at(i).hands.at(i2).state = "Stand";
								hFin += 1;
							}

							else //If not dealer
							{
								rInt4 = Random(1,25);

								if ((rInt4 >= 1) && (rInt4 < 18)) //Stand
								{
									players.at(i).hands.at(i2).state = "Stand";
									hFin += 1;
								}

								if (rInt4 >= 18) //Hit
								{
									//Add a card to the player's hand
									rInt3 = Random(0,sCCDeck.size());

									players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

									//Remove cards from deck
									sCCDeck.erase(sCCDeck.begin() + rInt3);
								}
							}
						}

						else if ((tCard3 == "A2") && (tCard4 == "6")) //11+6
						{
							//Dealer will stand
							if (players.at(i).getName() == "Dealer")
							{
								players.at(i).hands.at(i2).state = "Stand";
								hFin += 1;
							}

							else //If not dealer
							{
								rInt4 = Random(1,25);

								if ((rInt4 >= 1) && (rInt4 < 18)) //Stand
								{
									players.at(i).hands.at(i2).state = "Stand";
									hFin += 1;
								}

								if (rInt4 >= 18) //Hit
								{
									//Add a card to the player's hand
									rInt3 = Random(0,sCCDeck.size());

									players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

									//Remove cards from deck
									sCCDeck.erase(sCCDeck.begin() + rInt3);
								}
							}
						}

						//<=16
						else if ((tCard1 == "A2") && (tCard2 == "5" || tCard2 == "4" || tCard2 == "3" || tCard2 == "2")) //11+5to2
						{
							//Dealer/AI will Hit

							//Add a card to the player's hand
							rInt3 = Random(0,sCCDeck.size());

							players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

							//Remove cards from deck
							sCCDeck.erase(sCCDeck.begin() + rInt3);
						}

						else if ((tCard3 == "A2") && (tCard4 == "5" || tCard4 == "4" || tCard4 == "3" || tCard4 == "2")) //11+5to2
						{
							//Dealer/AI will Hit

							//Add a card to the player's hand
							rInt3 = Random(0,sCCDeck.size());

							players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

							//Remove cards from deck
							sCCDeck.erase(sCCDeck.begin() + rInt3);
						}

						//Double Aces
						else if ((tCard1 == "A1" || tCard1 == "A2") && (tCard2 == "A1" || tCard2 == "A2"))
						{
							if (players.at(i).getName() != "Dealer")
							{
								//Create a new hand for the AI Player
								players.at(i).hands.push_back(hand());

								//Now we need to take the second card from the first hand and move it to the second hand
								players.at(i).hands.at(sCPHand.size()-1).cards.push_back(players.at(i).hands.at(i2).cards.at(1));

								//Now remove the card from the first hand
								players.at(i).hands.at(i2).cards.erase(players.at(i).hands.at(i2).cards.begin()+1);

								for (i3 = 0; i3 < rBets.size(); i3++)
								{
									if (rBets.at(i3).bName == players.at(i).getName())
									{
										//Now duplicate the bet for the second hand
										//Dont have to check for enough chips as that is already done in the msgProc function
										rBets.push_back(bet());

										rBets.at(rBets.size()-1).bName = players.at(i).getName();
										rBets.at(rBets.size()-1).chips = rBets.at(i2).chips;
										rBets.at(rBets.size()-1).hand = i2+1;
									}
								}

								//Now add a second card to each of the player's hands
								rInt1 = Random(0,sCCDeck.size());
								rInt2 = Random(0,sCCDeck.size());

								players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt1));
								players.at(i).hands.at(i2+1).cards.push_back(sCCDeck.at(rInt2));

								//Remove cards from deck
								sCCDeck.erase(sCCDeck.begin() + rInt1);

								//If rInt1 is larger than rInt2 then no change to the value of rInt2 needs to be made, however if the reverse is true then 1 has to be subtracted
								if (rInt1 < rInt2)
								{
									rInt2 -= 1;
								}

								sCCDeck.erase(sCCDeck.begin() + rInt2);

								rDone += 1;
							}
						}

						//Checks under 21 without aces
						//Do an else because we need to change how the cards are processed by substring and cannot do that between else ifs
						else
						{
							//Get the first characters of the card string
							tCard1 = players.at(i).hands.at(i2).cards.at(0).substr(1,1);
							tCard2 = players.at(i).hands.at(i2).cards.at(1).substr(1,1);

							//20
							if ((tCard1 == "T" || tCard1 == "J" || tCard1 == "Q" || tCard1 == "K") && (tCard2 == "T" || tCard2 == "J" || tCard2 == "Q" || tCard2 == "K"))
							{
								//Dealer/AI Stand
								//AI/Dealer will stand
								players.at(i).hands.at(i2).state = "Stand";
								hFin += 1;
							}

							//19
							else if (((tCard1 == "T" || tCard1 == "J" || tCard1 == "Q" || tCard1 == "K") && ( tCard2 == "9")) || ((tCard2 == "T" || tCard2 == "J" || tCard2 == "Q" || tCard2 == "K") && ( tCard1 == "9")))
							{
								//Dealer/AI Stand
								//AI/Dealer will stand
								players.at(i).hands.at(i2).state = "Stand";
								hFin += 1;
							}

							//18
							else if (((tCard1 == "T" || tCard1 == "J" || tCard1 == "Q" || tCard1 == "K") && ( tCard2 == "8")) || ((tCard2 == "T" || tCard2 == "J" || tCard2 == "Q" || tCard2 == "K") && ( tCard1 == "8")))
							{
								//Dealer will stand
								if (players.at(i).getName() == "Dealer")
								{
									players.at(i).hands.at(i2).state = "Stand";
									hFin += 1;
								}

								else //If not dealer
								{
									rInt4 = Random(1,25);

									if ((rInt4 >= 1) && (rInt4 < 23)) //Stand
									{
										players.at(i).hands.at(i2).state = "Stand";
										hFin += 1;
									}

									if (rInt4 >= 23) //Hit
									{
										//Add a card to the player's hand
										rInt3 = Random(0,sCCDeck.size());

										players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

										//Remove cards from deck
										sCCDeck.erase(sCCDeck.begin() + rInt3);
									}
								}
							}

							//17
							else if (((tCard1 == "T" || tCard1 == "J" || tCard1 == "Q" || tCard1 == "K") && (tCard2 == "7")) || ((tCard2 == "T" || tCard2 == "J" || tCard2 == "Q" || tCard2 == "K") && (tCard1 == "7")) || ((tCard1 == "9") && (tCard2 =="8")) || ((tCard1 == "8") && (tCard2 == "9")))
							{
								//Dealer will stand
								if (players.at(i).getName() == "Dealer")
								{
									players.at(i).hands.at(i2).state = "Stand";
									hFin += 1;
								}

								else //If not dealer
								{
									rInt4 = Random(1,25);

									if ((rInt4 >= 1) && (rInt4 < 18)) //Stand
									{
										players.at(i).hands.at(i2).state = "Stand";
										hFin += 1;
									}

									if (rInt4 >= 18) //Hit
									{
										//Add a card to the player's hand
										rInt3 = Random(0,sCCDeck.size());

										players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

										//Remove cards from deck
										sCCDeck.erase(sCCDeck.begin() + rInt3);
									}
								}
							}

							//<16
							else if (((tCard1 == "T" || tCard1 == "J" || tCard1 == "Q" || tCard1 == "K") && (tCard2 == "6" || tCard2 == "5" || tCard2 == "4" || tCard2 == "3" || tCard2 == "2")) || ((tCard2 == "T" || tCard2 == "J" || tCard2 == "Q" || tCard2 == "K") && (tCard1 == "6" || tCard1 == "5" || tCard1 == "4" || tCard1 == "3" || tCard1 == "2")))
							{
								//Add a card to the player's hand
								rInt3 = Random(0,sCCDeck.size());

								players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

								//Remove cards from deck
								sCCDeck.erase(sCCDeck.begin() + rInt3);

							}

							//Non-face/T/A card handling
							else 
							{
								//First we need to cast to int
								card1 = atoi(players.at(i).hands.at(i2).cards.at(0).substr(1,1).c_str());
								card2 = atoi(players.at(i).hands.at(i2).cards.at(1).substr(1,1).c_str());

								//First check double
								if (card1 == card2)
								{
									if (players.at(i).getName() != "Dealer")
									{
										//Create a new hand for the AI Player
										players.at(i).hands.push_back(hand());

										//Now we need to take the second card from the first hand and move it to the second hand
										players.at(i).hands.at(sCPHand.size()-1).cards.push_back(players.at(i).hands.at(i2).cards.at(1));

										//Now remove the card from the first hand
										players.at(i).hands.at(i2).cards.erase(players.at(i).hands.at(i2).cards.begin()+1);

										for (i3 = 0; i3 < rBets.size(); i3++)
										{
											if (rBets.at(i3).bName == players.at(i).getName())
											{
												//Now duplicate the bet for the second hand
												//Dont have to check for enough chips as that is already done in the msgProc function
												rBets.push_back(bet());

												rBets.at(rBets.size()-1).bName = players.at(i).getName();
												rBets.at(rBets.size()-1).chips = rBets.at(i2).chips;
												rBets.at(rBets.size()-1).hand = i2+1;
											}
										}

										//Now add a second card to each of the player's hands
										rInt1 = Random(0,sCCDeck.size());
										rInt2 = Random(0,sCCDeck.size());

										players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt1));
										players.at(i).hands.at(i2+1).cards.push_back(sCCDeck.at(rInt2));

										//Remove cards from deck
										sCCDeck.erase(sCCDeck.begin() + rInt1);

										//If rInt1 is larger than rInt2 then no change to the value of rInt2 needs to be made, however if the reverse is true then 1 has to be subtracted
										if (rInt1 < rInt2)
										{
											rInt2 -= 1;
										}

										sCCDeck.erase(sCCDeck.begin() + rInt2);

										rDone += 1;
									}
								}

								//Any other combo
								//17 or higher
								else if (card1 + card2 > 16)
								{
									if (players.at(i).getName() == "Dealer")
									{
										players.at(i).hands.at(i2).state = "Stand";
										hFin += 1;
									}

									else
									{
										rInt4 = Random(1,25);

										if ((rInt4 >= 1) && (rInt4 < 18)) //Stand
										{
											players.at(i).hands.at(i2).state = "Stand";
											hFin += 1;
										}

										if (rInt4 >= 18) //Hit
										{
											//Add a card to the player's hand
											rInt3 = Random(0,sCCDeck.size());

											players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

											//Remove cards from deck
											sCCDeck.erase(sCCDeck.begin() + rInt3);
										}
									}
								}

								else //16 or lower
								{
									//Add a card to the player's hand
									rInt3 = Random(0,sCCDeck.size());

									players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

									//Remove cards from deck
									sCCDeck.erase(sCCDeck.begin() + rInt3);
								}
							}
						}
					}

					else //Else if the AI player's hand has more than two cards
					{
						//First see if the player has busted out or 5-card win	
						//Need to convert the cards to ints for further processing
						for (i3 = 0; i3 < players.at(i).hands.at(i2).cards.size(); i3++)
						{
							//Clear iCValues if it is not empty
							if (iCValues.size() > 0)
							{
								iCValues.clear();
							}

							//If no face card or ten or ace
							if ((players.at(i).hands.at(i2).cards.at(i3).substr(1,1) != "T") && (players.at(i).hands.at(i2).cards.at(i3).substr(1,1) != "J") && (players.at(i).hands.at(i2).cards.at(i3).substr(1,1) != "Q") && (players.at(i).hands.at(i2).cards.at(i3).substr(1,1) != "K") && (players.at(i).hands.at(i2).cards.at(i3).substr(1,2) != "A1") && (players.at(i).hands.at(i2).cards.at(i3).substr(1,2) != "A2"))
							{
								card1 = atoi(players.at(i).hands.at(i2).cards.at(i3).substr(1,1).c_str()); //Might need to explode this out, could be too many functions being accessed at once here
								iCValues.push_back(card1);
							}

							else if (players.at(i).hands.at(i2).cards.at(i3).substr(1,1) == "T" || players.at(i).hands.at(i2).cards.at(i3).substr(1,1) == "J" || players.at(i).hands.at(i2).cards.at(i3).substr(1,1) == "Q" || players.at(i).hands.at(i2).cards.at(i3).substr(1,1) == "K")
							{
								iCValues.push_back(10);
							}

							//Aces will be handleded differently now; will make code changes once done with this section of code.  A1 signifies a value of 1 while A2 signifies a value of 11
							else if (players.at(i).hands.at(i2).cards.at(i3).substr(1,2) == "A1")
							{
								iCValues.push_back(1);
							}

							else if (players.at(i).hands.at(i2).cards.at(i3).substr(1,2) == "A2")
							{
								iCValues.push_back(11);
							}
						}

						tCValue = 0; //Zero this out now

						for (i3 = 0; i3 < iCValues.size(); i3++)
						{					
							tCValue += iCValues.at(i3); //Get the total value of all cards
						}

						if (iCValues.size() < 5)
						{
							if (tCValue > 21)
							{
								cout << players.at(i).getName() << " has busted out of this hand: total card values = " << tCValue << endl;
								players.at(i).hands.at(i2).state = "Busted";
								hFin += 1;
							}
						}

						else if (iCValues.size() == 5)
						{
							if (tCValue > 21)
							{
								cout << players.at(i).getName() << " has busted out of this hand: total card values = " << tCValue << endl;
								players.at(i).hands.at(i2).state = "Busted";
								hFin += 1;
							}

							else if (tCValue <= 21)
							{
								cout <<players.at(i).getName() << " has reached five cards without busting and now stands." << endl;
								players.at(i).hands.at(i2).state = "Stand";
								hFin += 1;
							}
						}

						//Now we need to deal with what happens if neither of those is true and what the AI does in response
						//If the AI player is the dealer, stand above 16 and hit below 16
						if ((tCValue > 16) && (players.at(i).getName() == "Dealer"))
						{
							players.at(i).hands.at(i2).state = "Stand";
							hFin += 1;
						}

						else if (((tCValue <= 21 ) && (tCValue >= 19)) && (players.at(i).getName() != "Dealer"))
						{
							players.at(i).hands.at(i2).state = "Stand";
							hFin += 1;
						}

						else if ((tCValue == 18) && (players.at(i).getName() != "Dealer"))
						{
							rInt4 = Random(1,25);

							if ((rInt4 >= 1) && (rInt4 < 23)) //Stand
							{
								players.at(i).hands.at(i2).state = "Stand";
								hFin += 1;
							}

							if (rInt4 >= 23) //Hit
							{
								//Add a card to the player's hand
								rInt3 = Random(0,sCCDeck.size());

								players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

								//Remove cards from deck
								sCCDeck.erase(sCCDeck.begin() + rInt3);
							}
						}

						else if ((tCValue == 17) && (players.at(i).getName() != "Dealer"))
						{
							rInt4 = Random(1,25);

							if ((rInt4 >= 1) && (rInt4 < 18)) //Stand
							{
								players.at(i).hands.at(i2).state = "Stand";
								hFin += 1;
							}

							if (rInt4 >= 18) //Hit
							{
								//Add a card to the player's hand
								rInt3 = Random(0,sCCDeck.size());

								players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

								//Remove cards from deck
								sCCDeck.erase(sCCDeck.begin() + rInt3);
							}
						}

						else if (tCValue < 16)
						{
							//Add a card to the player's hand
							rInt3 = Random(0,sCCDeck.size());

							players.at(i).hands.at(i2).cards.push_back(sCCDeck.at(rInt3));

							//Remove cards from deck
							sCCDeck.erase(sCCDeck.begin() + rInt3);
						}
					}
				}
			}

			else
			{
				if (players.at(i).hands.at(i2).state == "Stand")
				{
					cout << players.at(i).getName() << " is standing." << endl;
				}

				else if (players.at(i).hands.at(i2).state == "Busted")
				{
					cout << players.at(i).getName() << " has busted out of this hand." << endl;
				}

				else if (players.at(i).hands.at(i2).state == "Surrendered")
				{
					cout << players.at(i).getName() << " has surrendered this hand." << endl;
				}
			}
		}
	}
}

void Game::rPBJack(Player& mPlayer)
{
	cout << "Processing hands and bets for this round: " << endl << endl;

	for (i = 0; i < players.size(); i++)
	{
		//Get the dealer's element
		if (players.at(i).getName() == "Dealer") 
		{
			//Make sure the dealer did not bust before continuing and has less than five cards
			if ((players.at(i).hands.at(0).state == "Stand") && (players.at(i).hands.at(0).cards.size() < 5))
			{
				cout << "Dealer's Hand: ";
				for (i3 = 0; i3 < players.at(i).hands.at(0).cards.size(); i3++)
				{
					cout << players.at(i).hands.at(0).cards.at(i3) << ", ";

					//Clear iCValues if it is not empty
					if (iCValues.size() > 0)
					{
						iCValues.clear();
					}

					//If no face card or ten or ace
					if ((players.at(i).hands.at(0).cards.at(i3).substr(1,1) != "T") && (players.at(i).hands.at(0).cards.at(i3).substr(1,1) != "J") && (players.at(i).hands.at(0).cards.at(i3).substr(1,1) != "Q") && (players.at(i).hands.at(0).cards.at(i3).substr(1,1) != "K") && (players.at(i).hands.at(0).cards.at(i3).substr(1,2) != "A1") && (players.at(i).hands.at(0).cards.at(i3).substr(1,2) != "A2"))
					{
						card1 = atoi(players.at(i).hands.at(0).cards.at(i3).substr(1,1).c_str()); //Might need to explode this out, could be too many functions being accessed at once here
						iCValues.push_back(card1);
					}

					else if (players.at(i).hands.at(0).cards.at(i3).substr(1,1) == "T" || players.at(i).hands.at(0).cards.at(i3).substr(1,1) == "J" || players.at(i).hands.at(0).cards.at(i3).substr(1,1) == "Q" || players.at(i).hands.at(0).cards.at(i3).substr(1,1) == "K")
					{
						iCValues.push_back(10);
					}

					//Aces will be handleded differently now; will make code changes once done with this section of code.  A1 signifies a value of 1 while A2 signifies a value of 11
					else if (players.at(i).hands.at(0).cards.at(i3).substr(1,2) == "A1")
					{
						iCValues.push_back(1);
					}

					else if (players.at(i).hands.at(0).cards.at(i3).substr(1,2) == "A2")
					{
						iCValues.push_back(11);
					}
				}

				cout << endl << endl;

				tCValue = 0; //Zero this out now

				for (i3 = 0; i3 < iCValues.size(); i3++)
				{					
					tCValue += iCValues.at(i3); //Get the total value of all cards
				}

				//iterate through player hands first
				cout <<  mPlayer.getName() << "'s Outcomes:" << endl;

				for (i2 = 0; i2 < sCPHand.size(); i2++)
				{		
					//Now find the bet than corresponds to this hand
					for (i4 = 0; i4 < rBets.size(); i4++)
					{
						if (rBets.at(i4).bName == mPlayer.getName()) //A bet made by the player
						{
							if (rBets.at(i4).hand == i2) //The bet for the current hand
							{
								//Check the player first; standing hands first
								if (sCPHand.at(i2).state == "Stand")
								{
									//Get the total value of the hand
									for (i3 = 0; i3 < sCPHand.at(i2).cards.size(); i3++)
									{
										//Clear iCValues if it is not empty
										if (iCValues.size() > 0)
										{
											iCValues.clear();
										}
										if ((sCPHand.at(i).cards.at(i3).substr(1,1) != "T") && (sCPHand.at(i).cards.at(i3).substr(1,1) != "J") && (sCPHand.at(i).cards.at(i3).substr(1,1) != "Q") && (sCPHand.at(i).cards.at(i3).substr(1,1) != "K") && (sCPHand.at(i).cards.at(i3).substr(1,2) != "A1") && (sCPHand.at(i).cards.at(i3).substr(1,2) != "A2"))
										{
											card1 = atoi(sCPHand.at(i).cards.at(i3).substr(1,1).c_str()); //Might need to explode this out, could be too many functions being accessed at once here
											iCValues.push_back(card1);
										}

										else if (sCPHand.at(i).cards.at(i3).substr(1,1) == "T" || sCPHand.at(i).cards.at(i3).substr(1,1) == "J" || sCPHand.at(i).cards.at(i3).substr(1,1) == "Q" || sCPHand.at(i).cards.at(i3).substr(1,1) == "K")
										{
											iCValues.push_back(10);
										}

										//Aces will be handleded differently now; will make code changes once done with this section of code.  A1 signifies a value of 1 while A2 signifies a value of 11
										else if (sCPHand.at(i).cards.at(i3).substr(1,2) == "A1")
										{
											iCValues.push_back(1);
										}

										else if (sCPHand.at(i).cards.at(i3).substr(1,2) == "A2")
										{
											iCValues.push_back(11);
										}
									}

									tCValue2 = 0; //Zero this out now

									for (i3 = 0; i3 < iCValues.size(); i3++)
									{					
										tCValue2 += iCValues.at(i3); //Get the total value of all cards
									}

									if (sCPHand.at(i2).cards.size() == 5)
									{
										cout << "Hand " << i2 << " wins with 5 cards under 22." << endl;

										//Give player bet chips times two
										sCChips += rBets.at(i4).chips * 2;

										//Remove these chips from the table store
										players.at(i).updateChips((rBets.at(i4).chips * 2), "sub");
									}

									else if (tCValue2 == tCValue) //If player and dealer tied
									{
										cout << "Hand " << i2 << " is a tie" << endl;

										//Return player's bet chips
										sCChips += rBets.at(i4).chips;
									}

									else if (tCValue2 > tCValue) //If player has a higher tVal than dealer
									{
										cout << "Hand " << i2 << " wins with a value higher than the dealer's!" << endl;

										//Give player bet chips times two
										sCChips += rBets.at(i4).chips * 2;

										//Remove these chips from the table store
										players.at(i).updateChips((rBets.at(i4).chips * 2), "sub");
									}

									else if (tCValue2 < tCValue) //If player has a lower tVal than dealer
									{
										cout << "Hand " << i2 << " lost with a value lower than the dealer's." << endl;

										//Take bet chips away from player - already done so nothing needs to be done here
										//Add them to the table store
										//Remove these chips from the table store
										players.at(i).updateChips(rBets.at(i4).chips, "add");
									}
								}

								else if (sCPHand.at(i2).state == "Busted") //If hand is busted
								{
									cout << "Hand " << i2 << " busted out." << endl;

									//Player loses bet chips

									//Add these chips from the table store
									players.at(i).updateChips(rBets.at(i4).chips, "add");
								}

								else if (sCPHand.at(i2).state == "Surrendered") //If hand is surrendered
								{
									cout << "Hand " << i2 << " was surrendered." << endl;

									//Player will keep half of bet chips back while dealer gets the other half
									sCChips += rBets.at(i4).chips/2;

									players.at(i).updateChips((rBets.at(i4).chips / 2), "sub");

								}
							}
						}
					}
				}

				cout << endl << endl;

				//Now deal with AI players - dealer
				for (i2 = 0; i2 < players.size(); i2++)
				{
					//Non-Dealer AI
					if (players.at(i2).getName() != "Dealer")
					{
						cout << players.at(i2).getName() << "'s Outcomes:" << endl;

						//Iterate current AI player's hand(s)
						for (i3 = 0; i3 < players.at(i2).hands.size(); i3++)
						{
							//Find the bet for this hand
							for (i4 = 0; i4 < rBets.size(); i4++)
							{
								if (rBets.at(i4).bName == players.at(i2).getName())
								{
									if (rBets.at(i4).hand == i3)
									{
										if (players.at(i2).hands.at(i3).state == "Stand")
										{
											//Get the total value of the hand
											for (i5 = 0; i5 < players.at(i2).hands.at(i3).cards.size(); i5++)
											{
												//Clear iCValues if it is not empty
												if (iCValues.size() > 0)
												{
													iCValues.clear();
												}
												if ((players.at(i2).hands.at(i3).cards.at(i5).substr(1,1) != "T") && (players.at(i2).hands.at(i3).cards.at(i5).substr(1,1) != "J") && (players.at(i2).hands.at(i3).cards.at(i5).substr(1,1) != "Q") && (players.at(i2).hands.at(i3).cards.at(i5).substr(1,1) != "K") && (players.at(i2).hands.at(i3).cards.at(i5).substr(1,2) != "A1") && (players.at(i2).hands.at(i3).cards.at(i5).substr(1,2) != "A2"))
												{
													card1 = atoi(players.at(i2).hands.at(i3).cards.at(i5).substr(1,1).c_str()); //Might need to explode this out, could be too many functions being accessed at once here
													iCValues.push_back(card1);
												}

												else if (players.at(i2).hands.at(i3).cards.at(i5).substr(1,1) == "T" || players.at(i2).hands.at(i3).cards.at(i5).substr(1,1) == "J" || players.at(i2).hands.at(i3).cards.at(i5).substr(1,1) == "Q" || players.at(i2).hands.at(i3).cards.at(i5).substr(1,1) == "K")
												{
													iCValues.push_back(10);
												}

												//Aces will be handleded differently now; will make code changes once done with this section of code.  A1 signifies a value of 1 while A2 signifies a value of 11
												else if (players.at(i2).hands.at(i3).cards.at(i5).substr(1,2) == "A1")
												{
													iCValues.push_back(1);
												}

												else if (players.at(i2).hands.at(i3).cards.at(i5).substr(1,2) == "A2")
												{
													iCValues.push_back(11);
												}
											}

											tCValue2 = 0; //Zero this out now

											for (i5 = 0; i5 < iCValues.size(); i5++)
											{					
												tCValue2 += iCValues.at(i5); //Get the total value of all cards
											}

											if (players.at(i2).hands.at(i3).cards.size() == 5)
											{
												cout << "Hand " << i3 << " wins with 5 cards under 22." << endl;

												//Give player bet chips times two
												players.at(i2).updateChips((rBets.at(i4).chips * 2), "add");

												//Remove these chips from the table store
												players.at(i).updateChips((rBets.at(i4).chips * 2), "sub");
											}

											else if (tCValue2 == tCValue) //If player and dealer tied
											{
												cout << "Hand " << i3 << " is a tie" << endl;

												//Return player's bet chips
												players.at(i2).updateChips(rBets.at(i4).chips, "add");
											}

											else if (tCValue2 > tCValue) //If player has a higher tVal than dealer
											{
												cout << "Hand " << i3 << " wins with a value higher than the dealer's!" << endl;

												//Give player bet chips times two
												players.at(i2).updateChips((rBets.at(i4).chips * 2), "add");

												//Remove these chips from the table store
												players.at(i).updateChips((rBets.at(i4).chips * 2), "sub");
											}

											else if (tCValue2 < tCValue) //If player has a lower tVal than dealer
											{
												cout << "Hand " << i3 << " lost with a value lower than the dealer's." << endl;

												//Take bet chips away from player - already done so nothing needs to be done here
												//Add them to the table store
												//Remove these chips from the table store
												players.at(i).updateChips(rBets.at(i4).chips, "add");
											}
										}

										else if (players.at(i2).hands.at(i3).state == "Busted")
										{
											cout << "Hand " << i2 << " busted out." << endl;

											//Player loses bet chips

											//Add these chips from the table store
											players.at(i).updateChips(rBets.at(i4).chips, "add");
										}

										else if (players.at(i2).hands.at(i3).state == "Surrendered")
										{
											cout << "Hand " << i2 << " was surrendered." << endl;

											//Player will keep half of bet chips back while dealer gets the other half
											players.at(i2).updateChips((rBets.at(i4).chips / 2), "add");

											players.at(i).updateChips((rBets.at(i4).chips / 2), "sub");
										}
									}
								}
							}
						}
					}

					cout << endl << endl;
				}
			}
		}
	}
}

void Game::sCPoker(Player& mPlayer)
{
	bContinue = false;

	while (!bContinue)
	{
		if (sCChips > 0)
		{
			pChoice = mp_g.sCPMenu();

			switch(pChoice)
			{
			case 1:
				sCP5Card(mPlayer);

				break;

			case 2:
				//sCPTHEm(mPlayer);
				break;

			case 3:
				//sCPOHEm(mPlayer);
				break;

			default:
				bContinue = true;
				break;
			}
		}

		else
		{
			cout << "You do not have any chips to play with." << endl;
		}
	}
}


void Game::sCP5Card(Player& mPlayer)
{
	pChoice = mp_g.sCP5Menu1();

	switch (pChoice)
	{
	case 1:
		mp_g.sCP5TMenu();
		break;

	case 2:
		bContinue2 = true;

		//Phase 1; set up the AI; only happens once per game played (a game is any number of rounds until all ai players or the player is knocked out or the player quits
		setupCAI(false, true);

		while (bContinue2)
		{
			//Phase 2: Pregame Setup
			sCP5CPSetup();

			//Phase 3; set up the deck
			setupCards();

			//Phase 4: Collect the ante
			collectAnte(mPlayer);

			//Phase 5: Determine Dealer
			setupDealer(mPlayer);

			//Phase 6: Deal cards
			dealCards(true, false, false, mPlayer);

			//Phase 7: First Bet
			sCP5Bet(mPlayer);

			//Only continue if more than one player remains in the round
			if (betOrder.size() > 1)
			{
				//Phase 8: Card Trading

				//Phase 9: Second Bet

				//Only continue if more than one player remains in the round
				if (betOrder.size() > 1)
				{
					//Phase 10: Process Hands
				}

				else
				{
					//Phase 11: Declair Defacto Winner
				}
			}

			else
			{
				//Phase 11: Declair Defacto Winner
			}

		}

		break;

	default:
		break;
	}
}


void Game::setupSlots()
{
	slots.clear(); //Make sure there is nothing in the vector

	for (i = 0; i < 4; i++)
	{
		slots.push_back(tempSStr); //Create a new vector that will hold a reel
	}

	//Get the reels which will be used
	rInt1 = Random(1,12);

	rInt2 = Random(1,12);

	//Now we have to check rInt2 to make sure it is not equal to rInt1; must be done for each reel after 1
	bValid = false;

	while (!bValid)
	{
		if (rInt2 != rInt1)
		{
			bValid = true;
		}

		else
		{
			rInt2 = Random(1,12);
		}
	}

	rInt3 = Random(1,12);

	bValid = false;

	while (!bValid)
	{
		if ((rInt3 != rInt1) && (rInt3 != rInt1))
		{
			bValid = true;
		}

		else
		{
			rInt3 = Random(1,12);
		}
	}

	rInt4 = Random(1,12);

	bValid = true;

	while (!bValid)
	{
		if ((rInt4 != rInt1) && (rInt4 != rInt2) && (rInt4 != rInt3))
		{
			bValid = true;
		}

		else
		{
			rInt4 = Random(1,12);
		}
	}

	//Now add reel array elements to the vectors; VERY code heavy for now, try and find a way to refactor in future!
	for (i = 0; i < 4; i++)
	{
		for (i2 = 0; i2 < 20; i++)
		{
			if (i == 0)
			{
				if (rInt1 == 1)
				{
					tempReel = cSR1[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt1 == 2)
				{
					tempReel = cSR2[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt1 == 3)
				{
					tempReel = cSR3[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt1 == 4)
				{
					tempReel = cSR4[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt1 == 5)
				{
					tempReel = cSR5[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt1 == 6)
				{
					tempReel = cSR6[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt1 == 7)
				{
					tempReel = cSR7[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt1 == 8)
				{
					tempReel = cSR8[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt1 == 9)
				{
					tempReel = cSR9[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt1 == 10)
				{
					tempReel = cSR10[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt1 == 11)
				{
					tempReel = cSR11[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt1 == 12)
				{
					tempReel = cSR12[i2];
					slots[i].push_back(tempReel);
				}
			}

			else if (i == 1)
			{
				if (rInt2 == 1)
				{
					tempReel = cSR1[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt2 == 2)
				{
					tempReel = cSR2[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt2 == 3)
				{
					tempReel = cSR3[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt2 == 4)
				{
					tempReel = cSR4[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt2 == 5)
				{
					tempReel = cSR5[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt2 == 6)
				{
					tempReel = cSR6[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt2 == 7)
				{
					tempReel = cSR7[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt2 == 8)
				{
					tempReel = cSR8[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt2 == 9)
				{
					tempReel = cSR9[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt2 == 10)
				{
					tempReel = cSR10[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt2 == 11)
				{
					tempReel = cSR11[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt2 == 12)
				{
					tempReel = cSR12[i2];
					slots[i].push_back(tempReel);
				}
			}

			else if (i == 2)
			{
				if (rInt3 == 1)
				{
					tempReel = cSR1[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt3 == 2)
				{
					tempReel = cSR2[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt3 == 3)
				{
					tempReel = cSR3[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt3 == 4)
				{
					tempReel = cSR4[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt3 == 5)
				{
					tempReel = cSR5[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt3 == 6)
				{
					tempReel = cSR6[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt3 == 7)
				{
					tempReel = cSR7[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt3 == 8)
				{
					tempReel = cSR8[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt3 == 9)
				{
					tempReel = cSR9[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt3 == 10)
				{
					tempReel = cSR10[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt3 == 11)
				{
					tempReel = cSR11[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt3 == 12)
				{
					tempReel = cSR12[i2];
					slots[i].push_back(tempReel);
				}
			}

			else if (i == 3)
			{
				if (rInt4 == 1)
				{
					tempReel = cSR1[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt4 == 2)
				{
					tempReel = cSR2[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt4 == 3)
				{
					tempReel = cSR3[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt4 == 4)
				{
					tempReel = cSR4[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt4 == 5)
				{
					tempReel = cSR5[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt4 == 6)
				{
					tempReel = cSR6[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt4 == 7)
				{
					tempReel = cSR7[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt4 == 8)
				{
					tempReel = cSR8[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt4 == 9)
				{
					tempReel = cSR9[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt4 == 10)
				{
					tempReel = cSR10[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt4 == 11)
				{
					tempReel = cSR11[i2];
					slots[i].push_back(tempReel);
				}

				else if (rInt4 == 12)
				{
					tempReel = cSR12[i2];
					slots[i].push_back(tempReel);
				}
			}
		}
	}
}

void Game::setupCards()
{
	if (sCCDeck.size() != 0)
	{
		sCCDeck.clear();
	}

	for (i = 51; i >= 0; i--)
	{
		bValid = false;

		while (!bValid)
		{
			//Get a random card
			rInt1 = Random(0,51);

			//Check to make sure that card is not already present
			if (sCCDeck.size() != 0)
			{
				for (i2 = 0; i2 <= sCCDeck.size(); i2++)
				{
					if (i2 == sCCDeck.size())
					{
						sCCDeck.push_back(cards[rInt1]);
						bValid = true;
					}

					else if (cards[rInt1] == sCCDeck.at(i2))
					{
						break;
					}
				}
			}

			else //If sCCDeck is empty
			{
				//Add random card to deck
				sCCDeck.push_back(cards[rInt1]);
				bValid = true;
			}
		}
	}
}

void Game::sCP5CPSetup()
{
	//Set up ante
	rInt1 = Random(25, 70);
	ante = rInt1;

	//If sCPHand's size is not 0 clear it
	if (sCPHand.size() > 0)
	{
		sCPHand.clear();
	}

	//Setup Hand elements (no cards yet)
	sCPHand.push_back(hand());

	for (i = 0; i < players.size(); i++)
	{
		players.at(i).hands.push_back(hand());
	}
}

void Game::collectAnte(Player& mPlayer)
{
	//Get the antes for playing the round.

	//First make sure that each player has the chips to pay the ante before asking/calculating
	if (sCChips > ante)
	{
		pChoice = mp_g.sCPAnte(ante);

		if (pChoice == 1)
		{
			sCPHand.at(0).state = "Playing";
			sCChips -= ante;
			pot += ante;
		}

		else
		{
			sCPHand.at(0).state = "Not Playing";
		}
	}

	else
	{
		cout << mPlayer.getName() << " has been knocked out of the game." << endl;
		sCPHand.at(0).state = "Not Playing";

		//Since this is the player, also set bContinue/2 to true/false
		bContinue = true;
		bContinue2 = false;
	}


	for (i = 0; i < players.size(); i++)
	{
		if (players.at(i).getChips() > ante)
		{
			rInt1 = Random(1,30);

			if ((rInt1 >= 1) && (rInt1 < 21))
			{
				players.at(i).hands.at(0).state = "Playing";
				players.at(i).updateChips(ante, "sub");
				pot += ante;
			}

			else if (rInt1 >= 21)
			{
				players.at(i).hands.at(0).state = "Not Playing";
			}
		}

		else
		{
			cout << players.at(i).getName() << " has been knocked out of the game." << endl;
			players.erase(players.begin()+i);
			i -= 1; //Do this because the vector is now one element smaller; deals with possible index out of bounds crash
		}
	}
}

void Game::setupDealer(Player& mPlayer)
{
	//If the player is not the current dealer
	if (!sCPHand.at(0).dealer)
	{
		//Then search the players vector
		for (i = 0; i <= players.size(); i++)
		{
			//If no one is a dealer (just started the game)
			if (i == players.size())
			{
				//Then setup the player as the dealer
				sCPHand.at(0).dealer = true;

				cout << mPlayer.getName() << " is now the dealer." << endl;
			}

			//Else If an AI player is the dealer and it happens to be the last AI player, then set the player as the dealer
			else if ((players.at(i).hands.at(0).dealer) && (i == players.size()-1))
			{
				players.at(i).hands.at(0).dealer = false;
				sCPHand.at(0).dealer = true;

				cout << mPlayer.getName() << " is now the dealer." << endl;

				break; //Do this here because we do not want to go through the final loop needlessly
			}

			//Else If an AI player is the current dealer and it is NOT the last AI player
			else if (players.at(i).hands.at(0).dealer)
			{
				//Then make the next AI player the dealer for the current round
				players.at(i+1).hands.at(0).dealer = true;

				cout << players.at(i+1).getName() << " is now the dealer." << endl;

				players.at(i).hands.at(0).dealer = false;

				break; //As before, use this here so we do not have to go through the entire for loop when it is no longer needed
			}
		}
	}

	//Else If the player IS the current dealer, set the first AI player as the dealer for the current round
	else
	{
		players.at(0).hands.at(0).dealer = true;

		cout << players.at(0).getName() << " is now the dealer." << endl;

		sCPHand.at(0).dealer = false;
	}
}

void Game::dealCards(bool P5, bool PTH, bool POH, Player& mPlayer)
{
	//Clear out any neccessary vectors
	betOrder.clear();
	sCPHand.at(0).cards.clear();

	for (i = 0; i < players.size(); i++)
	{
		players.at(i).hands.at(0).cards.clear();
	}

	//Straight/5Card
	if (P5)
	{
		//First find the Dealer

		//If the player is the dealer
		if (sCPHand.at(0).dealer)
		{
			//Then start dealing with the AI and ending with the player
			//Also set up the betting order at this time
			for (i = 0; i < players.size(); i++)
			{
				betOrder.push_back(players.at(i).getName());

				//Deal cards to this player
				for (i2 = 0; i2 < 5; i2++)
				{
					//Get a random card
					rInt2 = Random(0, sCCDeck.size()-1);

					//Place it in the current player's hand
					players.at(i).hands.at(0).cards.push_back(sCCDeck.at(rInt2));

					//Now remove this card from the deck
					sCCDeck.erase(sCCDeck.begin()+rInt2);				
				}
			}

			//Now deal the player's hand

			betOrder.push_back(mPlayer.getName());

			for (i = 0; i < 5; i++)
			{
				//Get a random card
				rInt2 = Random(0, sCCDeck.size()-1);

				//Place it in the current player's hand
				sCPHand.at(0).cards.push_back(sCCDeck.at(rInt2));

				//Now remove this card from the deck
				sCCDeck.erase(sCCDeck.begin()+rInt2);				
			}
		}

		//Else If the player is not the dealer
		else if (!sCPHand.at(0).dealer)
		{
			//Locate the dealer and then set the position in the vector to dPos
			for (i = 0; i < players.size(); i++)
			{
				if (players.at(i).hands.at(0).dealer)
				{
					dPos = i;
					break;
				}
			}

			//Now deal the cards

			//If the dealer is the last AI start with the player
			if (dPos == players.size()-1)
			{
				betOrder.push_back(players.at(i).getName());

				for (i = 0; i < 5; i++)
				{
					//Get a random card
					rInt2 = Random(0, sCCDeck.size()-1);

					//Place it in the current player's hand
					sCPHand.at(0).cards.push_back(sCCDeck.at(rInt2));

					//Now remove this card from the deck
					sCCDeck.erase(sCCDeck.begin()+rInt2);
				}

				for (i = 0; i < players.size(); i++)
				{
					betOrder.push_back(players.at(i).getName());

					//Deal cards to this player
					for (i2 = 0; i2 < 5; i2++)
					{
						//Get a random card
						rInt2 = Random(0, sCCDeck.size()-1);

						//Place it in the current player's hand
						players.at(i).hands.at(0).cards.push_back(sCCDeck.at(rInt2));

						//Now remove this card from the deck
						sCCDeck.erase(sCCDeck.begin()+rInt2);				
					}
				}
			}

			else //If the dealer is NOT the last AI
			{
				//Start from dealer + 1, include the player, and then deal to the AI that came before the player, if any.
				for (i = dPos+1; i <= players.size(); i++)
				{
					if (i == players.size())
					{
						betOrder.push_back(mPlayer.getName());

						//Deal the player then reset i to -1;
						for (i2 = 0; i2 < 5; i2++)
						{
							//Get a random card
							rInt2 = Random(0, sCCDeck.size()-1);

							//Place it in the current player's hand
							sCPHand.at(0).cards.push_back(sCCDeck.at(rInt2));

							//Now remove this card from the deck
							sCCDeck.erase(sCCDeck.begin()+rInt2);

							i = -1; //-1 beause it will be iterated to 0 on the next time through the for loop
						}
					}

					else if (i == dPos) //Deal the dealer
					{
						betOrder.push_back(players.at(i).getName());

						//Deal cards to this player
						for (i2 = 0; i2 < 5; i2++)
						{
							//Get a random card
							rInt2 = Random(0, sCCDeck.size()-1);

							//Place it in the current player's hand
							players.at(i).hands.at(0).cards.push_back(sCCDeck.at(rInt2));

							//Now remove this card from the deck
							sCCDeck.erase(sCCDeck.begin()+rInt2);				
						}

						break; //Because we will have gone full circle by now and everyone will have cards
					}

					else
					{
						betOrder.push_back(players.at(i).getName());

						//Deal cards to this player
						for (i2 = 0; i2 < 5; i2++)
						{							
							//Get a random card
							rInt2 = Random(0, sCCDeck.size()-1);

							//Place it in the current player's hand
							players.at(i).hands.at(0).cards.push_back(sCCDeck.at(rInt2));

							//Now remove this card from the deck
							sCCDeck.erase(sCCDeck.begin()+rInt2);				
						}
					}
				}
			}
		}

		//Texas Hold'em
		else if (PTH)
		{

		}

		//Omaha Hold'em
		else if (POH)
		{

		}
	}
}

void Game::sCP5Bet(Player& mPlayer)
{
	//Process a betting turn
	for (i = 0; i <= betOrder.size(); i++)
	{
		if ((bRaise) && (i == betOrder.size()))
		{
			i = -1; //If a raise is issued reset i to 0 after the current for loop cycle is completed (-1 to deal with iteration)
		}

		else if ((bRaise) && (i == rPos)) //Have returned to raiser's position
		{
			//The raiser must now call his own bet and check; betting turn ends
			//If the raiser is the player
			if (betOrder.at(i) == mPlayer.getName())
			{
				cout << mPlayer.getName() << " checks." << endl;

				bCheck = true;
				bRaise = false; //Unflag this because there is no new raise
			}

			else //If the raiser is an AI player
			{
				for (i2 = 0; i2 < players.size(); i2++)
				{
					if (betOrder.at(i) == players.at(i2).getName())
					{
						cout << players.at(i2).getName() << " checks." << endl;

						bCheck = true;
						bRaise = false; //Unflag this because there is no new raise
					}
				}
			}
		}

		else if ((bCheck) && (i == betOrder.size() || i == rPos+1)) //If check flag is true and if we are either at the end of the betting order or on the bettor directly following a check by a raiser
		{
			//End the betting turn
			cout << "Betting has been concluded." << endl;
			mp_g.mCScreen(true);
			break;
		}

		else if ((betOrder.at(i) == mPlayer.getName()) && (sCPHand.at(0).state != "Fold") && (sCPHand.at(0).state != "All In"))
		{
			//Get player to choose an action
			pChoice = mp_g.sCP5Menu2(sCPHand.at(0).cards, lastBet, sCChips);

			switch (pChoice)
			{
			case 1:

				cout << mPlayer.getName() << " calls the last bet of " << lastBet << "." << endl;
				pot += lastBet;

				if ((i != betOrder.size()-1) && (!bRaise)) //If no raise has been made and we are at the end of the bet order; auto check 
				{
					bCheck = true;
				}

				else
				{
					//Remove the chips from the player
					sCChips -= lastBet;

					//Add them to the pot
					pot += lastBet;
				}			

				break;

			case 2:

				pChoice = mp_g.sCP5BMenu(sCPHand.at(0).cards, lastBet, sCChips);

				if (pChoice == sCChips)
				{
					cout << mPlayer.getName() << " raises the pot to " << pot+sCChips << " and goes all-in!" << endl;
					sCPHand.at(0).state = "All In";
					bAIn = true;

					//Set last bet
					lastBet = sCChips;

					//Add chips to the pot
					pot += sCChips;

					//Remove all of the player's chips
					sCChips = 0;
				}

				else
				{
					cout << mPlayer.getName() << " raises the pot to " << pot+sCChips << "." << endl;

					//Take the chips out of the player's total chips
					sCChips -= pChoice;

					//Add chips to the pot
					pot += pChoice;

					//Set flag and pos to indicate a raise
					rPos = i;
					bRaise = true;

					//Set last bet
					lastBet = pChoice;
				}

				break;

			case 3:

				//Player has folded, change hand state to reflect
				sCPHand.at(0).state = "Fold";

				//Then add one to hFin for rDone - may not be needed, commenting out for now until usage becomes more clear
				//hFin += 1;

				//Now we need to get the player out of the betting order since they are no longer playing
				betOrder.erase(betOrder.begin()+i);

				//Take one off of i because we have shifted the size down by one
				i -= 1;

				break;
			}
		}

		else
		{
			//Cycle through AI players to find the current bettor
			for (i2 = 0; i2 < players.size(); i2++)
			{
				//If current player is the current bettor and has not folded or gone all-in
				if ((betOrder.at(i) == players.at(i2).getName()) && (players.at(i2).hands.at(0).state != "Fold") && (players.at(i2).hands.at(0).state != "All In"))
				{
					sCP5AIBCalc();
				}
			}
		}
	}
}

void Game::sCP5AIBCalc()
{
	//Determine the bet to be made
	//First we need to determine what kind of hand the AI has.  We have to take into account both card calue and suit!
	//We meed to use this to determine several values
	//First the bet range, and second the call/raise/all-in/fold/bet variability

	//The bet range determines the max and min amount that will be bet on this turn
	//The call varibility will determine the rate at which calling will be favored; this is not mutually exclusive
	//The raise variability will determine the rate at which a raise will be favored; same as above
	//The all-in variability will be used if another player has gone all in and will determine how going all-in will be favored; same as above
	//The fold rate will determine the rate at which folding will be favored; same as above

	//The bet variability determines how much the bet will be by used as a multiplier with a value from within the betting range; this is not affected by any of the previous values except call, fold, or all-in as it will not apply there unless, for call, they are the first bettor

	//Start by determining the bet range, this will be changed later on
	//If the current player is the first bettor then we calculate the bet based on randoms, multipliers, and forumlas
	if (lastBet != 0)
	{
		aiBRange.iLow = Random(10, 60);
		aiBRange.iHigh = Random(70, 145);

		//Get the base range multiplier
		aiBRMulti = Random(1, 40);

		//Apply the base range multiplier
		aiBRange.iLow = aiBRange.iLow * aiBRMulti;
		aiBRange.iHigh = aiBRange.iHigh * aiBRMulti;

		//We need to get the base bet now
		aiBBet = iRandom(aiBRange);
	}

	//However if there is a previous bet then we start with that as the base without the calculations
	else
	{
		aiBBet = lastBet;
	}

	//Set base bet var
	aiBVar = Random(0,40);

	//Now start examining the players cards and figuring out the suit/value variables and flags
	for (i3 = 0; i3 < 2; i3++)
	{
		//Start with suits
		if (i3 = 0)
		{
			//Loop through each suit
			for (i4 = 0; i < 4; i4++)
			{
				if (i4 == 0) //Hearts
				{
					for (i5 = 0; i5 < players.at(i2).hands.at(0).cards.size(); i5++)
					{
						tCard1 = players.at(i2).hands.at(0).cards.at(i5).substr(3,1); //Get the suit of the card

						if (tCard1 == "H")
						{
							aiSSuit1 += 1;
						}
					}
				}

				else if (i4 == 1) //Diamonds
				{
					for (i5 = 0; i5 < players.at(i2).hands.at(0).cards.size(); i5++)
					{
						tCard1 = players.at(i2).hands.at(0).cards.at(i5).substr(3,1); //Get the suit of the card

						if (tCard1 == "D")
						{
							aiSSuit2 += 1;
						}
					}
				}

				else if (i4 == 2) //Clubs
				{
					for (i5 = 0; i5 < players.at(i2).hands.at(0).cards.size(); i5++)
					{
						tCard1 = players.at(i2).hands.at(0).cards.at(i5).substr(3,1); //Get the suit of the card

						if (tCard1 == "C")
						{
							aiSSuit3 += 1;
						}
					}
				}

				else if (i4 == 3) //Spades
				{
					for (i5 = 0; i5 < players.at(i2).hands.at(0).cards.size(); i5++)
					{
						tCard1 = players.at(i2).hands.at(0).cards.at(i5).substr(3,1); //Get the suit of the card

						if (tCard1 == "S")
						{
							aiSSuit4 += 1;
						}
					}
				}
			}
		}

		//Then values
		else if (i3 = 1)
		{
			sCValues.clear(); //Clear the vector each time before use
			//fill_n(aiRCards, 13, 0); //zero out the array each time

			for (i4 = 0; i4 < players.at(i2).hands.at(0).cards.size(); i4++)
			{
				sCValues.push_back(players.at(i2).hands.at(0).cards.at(i4).substr(1,1)); //substring each card and then put into vector
			}

			for (i4 = 1; i4 < 14; i4++)
			{
				for (i5 = 0; i5 < sCValues.size(); i5++)
				{
					if (i4 == 1)
					{
						if (sCValues.at(i5) == "A") //If card is an ace
						{
							aiRCards[0] += 1; //Add 1 to element 0; apply theory to all other conditional blocks
						}
					}

					else if (i4 == 2)
					{
						if (sCValues.at(i5) == "2")
						{
							aiRCards[1] += 1;
						}
					}

					else if (i4 == 3)
					{
						if (sCValues.at(i5) == "3")
						{
							aiRCards[2] += 1;
						}
					}

					else if (i4 == 4)
					{
						if (sCValues.at(i5) == "4")
						{
							aiRCards[3] += 1;
						}
					}

					else if (i4 == 5)
					{
						if (sCValues.at(i5) == "5")
						{
							aiRCards[4] += 1;
						}
					}

					else if (i4 == 6)
					{
						if (sCValues.at(i5) == "6")
						{
							aiRCards[5] += 1;
						}
					}

					else if (i4 == 7)
					{
						if (sCValues.at(i5) == "7")
						{
							aiRCards[6] += 1;
						}
					}

					else if (i4 == 8)
					{
						if (sCValues.at(i5) == "8")
						{
							aiRCards[7] += 1;
						}
					}

					else if (i4 == 9)
					{
						if (sCValues.at(i5) == "9")
						{
							aiRCards[8] += 1;
						}
					}

					else if (i4 == 10)
					{
						if (sCValues.at(i5) == "10")
						{
							aiRCards[9] += 1;
						}
					}

					else if (i4 == 11)
					{
						if (sCValues.at(i5) == "J")
						{
							aiRCards[10] += 1;
						}
					}

					else if (i4 == 12)
					{
						if (sCValues.at(i5) == "Q")
						{
							aiRCards[11] += 1;
						}
					}

					else if (i4 == 13)
					{
						if (sCValues.at(i5) == "K")
						{
							aiRCards[12] += 1;
						}
					}
				}
			}
		}
	}

	//Now it is time to set the flags which will determine the bet range and action variability
	//First we need to check for certain combinations.  We do not need to try and detect combinations at this point, just certain groupings of card values and suits
	//Note that for values, certain numbers will overrule others; for example a four of one type means that three and two do not need to be checked as they are lower value but if you have a three two
	//situation (full house) these will overrule other value types and the first suit-based combination (a flush).

	//First, however, we need to set the base value for the favorability vars
	aiCFav = Random(-6,5);
	aiRFav = Random(-4,5);
	aiAFav = Random(-4,3);
	aiFFav = Random(-2,3);		

	//Now check suits first
	if (aiSSuit1 == 5 || aiSSuit2 == 5 || aiSSuit3 == 5 || aiSSuit4 == 5) //Check for flush
	{
		//Set variability bonuses
		aiRFav += 3;
		aiAFav += 2;
		aiCFav -= 1;
		aiFFav -= 3;

		//Alter bet multiplier
		aiBVar += 4;
	}

	else if (aiSSuit1 == 4 || aiSSuit2 == 4 || aiSSuit3 == 4 || aiSSuit4 == 4) //Check for near flush
	{
		//Set variability bonuses
		aiRFav += 2;
		aiAFav += 1;
		aiCFav += 1;
		aiFFav -= 2;

		//Alter bet multiplier
		aiBVar += 2;
	}

	else if (aiSSuit1 == 3 || aiSSuit2 == 3 || aiSSuit3 == 3 || aiSSuit4 == 3) //Check for 3/5th flush
	{
		//Set variability bonuses
		aiRFav += 2;
		aiAFav += 0;
		aiCFav += 2;
		aiFFav += 2;

		//Alter bet multiplier
		aiBVar += 1;
	}

	else if ((aiSSuit1 == 2 || aiSSuit2 == 2 || aiSSuit3 == 2 || aiSSuit4 == 2) || (aiSSuit1 == 1 || aiSSuit2 == 1 || aiSSuit3 == 1 || aiSSuit4 == 1)) //All other suit combinations down to 1
	{
		//Set variability bonuses
		aiRFav -= 1;
		aiAFav -= 2;
		aiCFav += 1;
		aiFFav += 2;

		//Alter bet multiplier
		aiBVar -= 1;
	}

	//Now deal with the values
	for (i3 = 0; i3 < 14; i3++)
	{
		if (aiRCards[i3] == 4) //Check for four of a kind
		{
			//Set variability bonuses
			aiRFav += 1;
			aiAFav += 2;
			aiCFav -= 1;
			aiFFav -= 2;

			//Alter bet multiplier
			aiBVar += 3;
		}

		else if (aiRCards[i3] == 3) //Check for three of a kind
		{
			//Set variability bonuses
			aiRFav += 1;
			aiAFav += 1;
			aiCFav -= 1;
			aiFFav -= 1;

			//Alter bet multiplier
			aiBVar += 2;
		}

		else if (aiRCards[i3] == 2 || aiRCards[i3] == 1)  //2 to 1
		{
			//Set variability bonuses

			aiRFav += 1;
			aiAFav -= 0;
			aiCFav += 1;
			aiFFav += 1;

			//Alter bet multiplier
			aiBVar -= 1;
		}
	}

	//Now we need to calculate the bet and then determine the action to take
	//Now we need to calc out the probability of certain actions based on the information gathered and examined above

	//AI Actions will be calculated based on float using the values calculated above

	aiAVar = Random(-0.20f, 0.70f); //Get the action variability variable, makes actions a bit more random

	if (!bAIn)
	{
		//Call
		aiCall = (((0.10f * aiCFav) + aiAVar) * 2.2f) * 0.30f;

		//Raise
		aiRaise = (((0.10f * aiRFav) + aiAVar) * 2.2f) * 0.30f;

		//Fold
		aiFold = (((0.10f * aiFFav) + aiAVar) * 2.2f) * 0.30f;

		//All-in
		aiAIn = (((0.10f * aiAFav) + aiAVar) * 2.2f) * 0.30f;
	}

	//If someone has gone all-in we want to modify what the AI does in response
	else if (bAIn)
	{
		//Call * 1.6
		aiCall = (((0.10f * aiCFav) + aiAVar) * 2.2f) * 0.30f * 1.6f;

		//Raise * 0.5
		aiRaise = (((0.10f * aiRFav) + aiAVar) * 2.2f) * 0.30f * 0.5f;

		//Fold * 2.5
		aiFold = (((0.10f * aiFFav) + aiAVar) * 2.2f) * 0.30f * 2.5f;

		//All-in * 1.1
		aiAIn = (((0.10f * aiAFav) + aiAVar) * 2.2f) * 0.30f * 1.1f;
	}

	//Now calculate the total bet

	aiTBet = (((((aiBVar * 12) + aiBBet) / 2) + aiBBet) * 6) / 4;

	//Do the chip check now
	if (aiTBet > players.at(i2).getChips())
	{
		aiTBet = players.at(i2).getChips();
		bAIn = true;
	}

	//Now determine the action the AI will undertake
	//Calculation to determine, still at random but still leaning toward those options that are much more likely

	//TODO: If any calculated value in here becomes negative, multiply by negative 1

	//First we need a random float
	rFloat1 = Random(-0.2f, 0.34f);

	//Now use this with the calculations to determine what is done.  Use an if conditional using floats, if the float is a certain value then execute that specific action
	for (i6 = 0; i6 <= 4; i6++)
	{
		if (i6 == 4) //None of the actions were chosen, reset the random and retry
		{
			rFloat1 = Random(-0.2f, 0.34f);
			i6 = -1;
		}

		else if (i6 == 0)
		{
			if ((rFloat1 * aiCall) / 0.15f > 0.45f) //The first action to reach this condition will be done even if another action could potentially have a higher value later on
			{
				if (lastBet != 0) //If there is a previous bet
				{
					if (players.at(i2).getChips() > lastBet)
					{
						cout << players.at(i2).getName() << " calls the last bet of " << lastBet << "." << endl;

						//remove the chips from the player
						players.at(i2).updateChips(lastBet, "sub");

						//Add chips to pot
						pot += lastBet;

						break;
					}

					else //else if player does not have enough chips, all in
					{
						cout << players.at(i2).getName() << " goes all-in!" << endl;

						//Set lastBet
						lastBet = players.at(i2).getChips();

						//Add chips to pot
						pot += players.at(i2).getChips();

						//Remove chips and set flags
						players.at(i2).updateChips(0, "set");

						bAIn = true;

						players.at(i2).hands.at(0).state = "All In";

						break;
					}
				}

				else //If no previous bet
				{
					if (players.at(i2).getChips() > aiTBet)
					{
						cout << players.at(i2).getName() << " bets " << aiTBet << "." << endl;

						//remove the chips from the player
						players.at(i2).updateChips(aiTBet, "sub");

						//Set lastBet
						lastBet = aiTBet;

						//Add chips to pot
						pot += aiTBet;

						break;
					}

					else //else if player does not have enough chips, all in
					{
						cout << players.at(i2).getName() << " goes all-in!" << endl;

						//Set lastBet
						lastBet = players.at(i2).getChips();

						//Add chips to pot
						pot += players.at(i2).getChips();

						//Remove chips and set flags
						players.at(i2).updateChips(0, "set");

						bAIn = true;

						players.at(i2).hands.at(0).state = "All In";

						break;
					}
				}
			}
		}

		else if (i6 == 1)
		{
			if ((rFloat1 * aiRaise) / 0.15f > 0.45f) //The first action to reach this condition will be done even if another action could potentially have a higher value later on
			{
				if (lastBet != 0) //If there is a previous bet
				{
					if (players.at(i2).getChips() > lastBet)
					{
						cout << players.at(i2).getName() << " calls the last bet of " << lastBet << " and raises the pot to " << pot+aiTBet << "." << endl;

						//remove the chips from the player
						players.at(i2).updateChips(aiTBet, "sub");

						//Add chips to pot
						pot += aiTBet;

						//Set flags
						rPos = i;
						bRaise = true;

						//Set lastBet
						lastBet = aiTBet;		

						break;
					}

					else //else if player does not have enough chips, all in
					{
						cout << players.at(i2).getName() << " goes all-in!" << endl;

						//Set lastBet
						lastBet = players.at(i2).getChips();

						//Add chips to pot
						pot += players.at(i2).getChips();

						//Remove chips and set flags
						players.at(i2).updateChips(0, "set");

						bAIn = true;

						players.at(i2).hands.at(0).state = "All In";

						break;
					}
				}

				else //If no previous bet
				{
					if (players.at(i2).getChips() > aiTBet)
					{
						cout << players.at(i2).getName() << " bets " << aiTBet << "." << endl;

						//remove the chips from the player
						players.at(i2).updateChips(aiTBet, "sub");

						//Set lastBet
						lastBet = aiTBet;

						//Add chips to pot
						pot += aiTBet;

						break;
					}

					else //else if player does not have enough chips, all in
					{
						cout << players.at(i2).getName() << " goes all-in!" << endl;

						//Set lastBet
						lastBet = players.at(i2).getChips();

						//Add chips to pot
						pot += players.at(i2).getChips();

						//Remove chips and set flags
						players.at(i2).updateChips(0, "set");

						bAIn = true;

						players.at(i2).hands.at(0).state = "All In";

						break;
					}
				}
			}
		}

		else if (i6 == 2)
		{
			if ((rFloat1 * aiFold) / 0.15f > 0.45f) //The first action to reach this condition will be done even if another action could potentially have a higher value later on
			{
				cout << players.at(i2).getName() << " has folded." << endl;

				players.at(i2).hands.at(0).state = "Fold";

				//Now we need to get the player out of the betting order since they are no longer playing
				betOrder.erase(betOrder.begin()+i);

				//Take one off of i because we have shifted the size down by one
				i -= 1;

				break;
			}
		}

		else if (i6 == 3)
		{
			if ((rFloat1 * aiAIn) / 0.15f > 0.45f) //The first action to reach this condition will be done even if another action could potentially have a higher value later on
			{
				cout << players.at(i2).getName() << " goes all-in!" << endl;

				//Set lastBet
				lastBet = players.at(i2).getChips();

				//Add chips to pot
				pot += players.at(i2).getChips();

				//Remove chips and set flags
				players.at(i2).updateChips(0, "set");

				bAIn = true;

				players.at(i2).hands.at(0).state = "All In";

				break;
			}
		}
	}
}

void Game::sCP5CTProc(Player& mPlayer)
{
	for (i3 = 0; i3 < betOrder.size(); i3++)
	{
		if (betOrder.at(i3) == mPlayer.getName())
		{
			mp_g.sCP5CTMenu(sCPHand.at(0).cards);

			for(i4 = sCPHand.at(0).cards.size(); i4 < 5; i4++)
			{
				//Get a random card
				rInt2 = Random(0, sCCDeck.size()-1);

				//Place it in the current player's hand
				players.at(i).hands.at(0).cards.push_back(sCCDeck.at(rInt2));

				//Now remove this card from the deck
				sCCDeck.erase(sCCDeck.begin()+rInt2);
			}
		}

		else if (betOrder.at(i3) == players.at(i2).getName())
		{
			rInt3 = Random(1,30);

			//if ((rInt3

		}
	}
}

void Game::sSFitting(Player& mPlayer, Station& stat_g)
{
	bContinue = true;

	while (bContinue)
	{
		pChoice = mp_g.sSFMenu1();

		switch(pChoice)
		{
		case 1:
			cout << mp_g.mRMessage(2001) << endl;
			break;

		case 2:
			//Get the item to install
			pChoice = mp_g.sSFMenu3(stat_g, mPlayer);

			//If the player picked a valid item then continue
			if (pChoice != -1)
			{
				//Next determine if the player ship can support the item
				ds_g.rData("Weapon_Data","select from",stat_g.sInventory.at(pChoice).getIID());

				if (ds_g.getWType() == "laser" || ds_g.getWType() == "mining laser")
				{
					if (ds_g.getWType() == "laser")
					{
						cout << mp_g.mRMessage(2001);
					}

					else if (ds_g.getWType() == "mining laser")
					{
						if (mPlayer.ship.getLHP() > mPlayer.ship.getULHP()) //If this ship has open laser hard points
						{
							cout << "Installing your selected weapon onto your ship..." << endl;

							if (mPlayer.ship.iWeapon("mining laser",stat_g.sInventory.at(pChoice).getIID()))
							{
								//Since the weapon installed correctly we need to remove it or at least one of them from the station inventory
								stat_g.removeItem(pChoice, 1);
							}

							else
							{
								cout << "The weapon could not be installed." << endl;
							}
						}

						else
						{
							cout << "Your ship does not have enough open laser hardpoints to install this weapon.  Please uninstall a weapon and try again." << endl;
						}
					}
				}

				else if (ds_g.getWType() == "missile")
				{
					cout << mp_g.mRMessage(2001);
				}

				else if (ds_g.getWType() == "bomb")
				{
					cout << mp_g.mRMessage(2001);
				}

				else if (ds_g.getWType() == "rail")
				{
					cout << mp_g.mRMessage(2001);
				}

				else if (ds_g.getWType() == "heavy")
				{
					cout << mp_g.mRMessage(2001);
				}
			}

		case 3:
			cout << mp_g.mRMessage(2001);
			break;

		default:
			bContinue = false;
			break;
		}
	}
}

void Game::sStorage(Station& stat_g)
{
	mp_g.sSSMenu(stat_g);
}