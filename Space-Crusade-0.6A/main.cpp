#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "globalvars.h"
#include "msgproc.h"
#include "datasystem.h"
#include "database.h"
#include "debug.h"
#include "game.h"
#include "entity.h"
#include "battleproc.h"
#include "map.h"


using namespace std;
namespace gv = gVars;

Game mGame_m;
Player mPlayer;
NPC mNPC;
msgProc mp_m;
Database db_m;
battleProc bp_m;
Map m_m;
dataSystem ds_m;


int main()
{
	srand( time(0) );

	int pChoice;
	int gSRows;
	int pID;
	int sID;

	char pCChoice;

	bool gQuit;
	bool gMMenu = true;
	bool bErrors;
	bool lStation;
	bool locked = false; //Use this to lock the main menu from the player during certain events such as using a clone

	string eResult; //Event result; used for any time a loop is done where multiple outcomes, more than two, can be achieved

	//Get data from configuration file
	gv::getCData();
	mp_m.cdPrint();

	cout << setprecision(2) << fixed; //for percentages later on

	while (gMMenu)
	{
		pChoice = mp_m.gTMenu();
		mp_m.mCScreen(false);

		if (pChoice == 3)
		{
			gQuit = true;
			gMMenu = false;
		}

		else if (pChoice == 2)
		{
			//Check to make sure there is actually save data
			db_m.openSave(&bErrors);

			if (!bErrors)
			{
				gSRows = db_m.getCount("Player_Data", &bErrors);

				if ((!bErrors) && (gSRows > 0))
				{
					mGame_m.gLoad(mPlayer);
					gQuit = false;
					gMMenu = false;
				}

				else if (bErrors)
				{
					cout << mp_m.mRMessage(2018) << endl;
					mp_m.mCScreen(true);
				}

				else if (gSRows == 0)
				{
					cout << mp_m.mRMessage(2017) << endl;
					mp_m.mCScreen(true);
				}

				db_m.closeDB(&bErrors);
			}

			else
			{
				cout << mp_m.mRMessage(2018) << endl;
				mp_m.mCScreen(true);
			}
		}

		else if (pChoice == 1)
		{
			//Story function goes here
			mPlayer.pSetup();
			gQuit = false;
			gMMenu = false;

			//Other stuff that needs setting up
			mGame_m.getPNames();
			mGame_m.generatePlanets();
		}
	}

	//For testing; put items in ship cargo
	//mPlayer.ship.addCItem(32,"Ore",100,false);

	while (!gQuit)
	{
		if (!locked)
		{
			pChoice = mp_m.nMenu1();
			mp_m.mCScreen(false);
		}

		switch(pChoice)
		{
		case 1:
			mGame_m.iSPlanets();
			mGame_m.fPlanets(); //Locate planets

			pID = mGame_m.pPlanets(mPlayer);
			//pID = 200;

			if (pID != -1)
			{
				if (!m_m.shipEncounter(mGame_m.sPlanets.at(pID).getTDist())) //If no ships are encountered
				{
					mGame_m.pMenu(mPlayer, &mGame_m.gPlanets.at(mGame_m.sPlanets.at(pID).getPID()-1), mGame_m, &eResult, m_m, bp_m, mNPC);
					//pID = mGame_m.sPlanets.at(pID).getPID();
					//eResult = bp_m.pBLoop(mPlayer,&mGame_m.gPlanets.at(pID - 1), mGame_m); //Then contniue to planet.  -1 because of the way generatePlanets generates the planet ID
				}

				else //Else if ship is encountered
				{
					eResult = bp_m.sBLoop(mPlayer,&mGame_m.gPlanets.at(pID), false, mGame_m, mNPC); //Load ship encounter events
				}

				if (eResult == "Used Clone")
				{
					locked = true;
					pChoice = 9;
				}

				else if (eResult == "Destroyed")
				{
					system("Pause");
					gQuit = true;
				}
			}

			mGame_m.rSPlanets();
			break;

		case 2:
			mGame_m.iTStations();
			mGame_m.fStations(); //Locate planets

			sID = mGame_m.pStations(mPlayer);
			mp_m.mCScreen(false);

			//Set pID here so that we do not crash if a ship is encountered
			pID = 1; //Use 1 so that we pass 0, just in case something strange happens so we are not causing any index problems from a -1 value

			if (sID != -1)
			{
				if (!m_m.shipEncounter(mGame_m.tStats.at(sID).getTDist())) //If no ships are encountered
				{
					mGame_m.sMenu(mPlayer,mGame_m.gStations.at(sID));
				}

				else //Else if ship is encountered
				{
					eResult = bp_m.sBLoop(mPlayer,&mGame_m.gPlanets.at(pID-1), false, mGame_m, mNPC); //Load ship encounter events
				}

				if (eResult == "Used Clone")
				{
					locked = true;
					pChoice = 9;
				}

				else if (eResult == "Destroyed")
				{
					system("Pause");
					gQuit = true;
				}
			}

			mGame_m.rTStations();
			break;

		case 3:
			if (m_m.shipEncounter(mPlayer.ship.getMInit())) //If ship(s) are encountered
			{
				eResult = bp_m.sBLoop(mPlayer,&mGame_m.gPlanets.at(0), false, mGame_m, mNPC); //Load ship encounter events

				if (eResult == "Used Clone")
				{
					locked = true;
					pChoice = 9;
				}

				else if (eResult == "Destroyed")
				{
					system("Pause");
					gQuit = true;
				}
			}

			else
			{
				cout << "No ships found" << endl << endl;
			}

			break;

		case 4:
			mp_m.pInfo(mPlayer, mGame_m);
			break;

		case 5:
			break;

		case 6:
			mGame_m.gSave(mPlayer);
			break;

		case 7:
			mGame_m.gLoad(mPlayer);
			break;

		case 8:
			gQuit = true;
			break;

		case 9:
			mGame_m.createStation(mPlayer.getPLocale(),mPlayer);
			break;
		}
	}

	return 0;

	/*
	//Ini Test Value Range w/ Database
	scOps::options_description desc("Settings");
	desc.add_options()
		("itemid.lwlow",scOps::value<int>(&gv::iIRLWeaps.iLow),"player_name")
		("itemid.lwhigh",scOps::value<int>(&gv::iIRLWeaps.mHigh),"player_id");

	scOps::variables_map vm;

	try
	{
		ifstream settings_file("scValues.ini",ifstream::in);
		scOps::store(scOps::parse_config_file(settings_file, desc, true), vm);
		settings_file.close();
		scOps::notify(vm);
	}

	catch (const scOps::error& e )
	{
        std::cerr << e.what() << std::endl;
    }

	int iRand = iRandom(gv::iIRLWeaps);

	ds_m.rData("Weapon_Data","select from",iRand);

	cout << ds_m.getWName() << endl;
	cout << iRand << endl;
	system("Pause");*/
}
