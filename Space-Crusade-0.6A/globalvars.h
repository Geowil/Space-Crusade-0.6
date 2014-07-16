#ifndef GLOBALVARS_H
#define GLOBALVARS_H

#include <string>
#include <vector>
#include "range.h"

using std::string;
using std::vector;

namespace gVars
{
	void getCData(); //Get the config data from the ini file
	void printData(); //Print out loaded data
	void setNIValues(); //Deal with imported lists
	template<typename t> void fillVect(vector<t> vect, string type); //Fill a vector from an imported string list
	template<typename t> void clearVect(vector<t> vect); //Clear the passed vector

	//Configuration Variables

	//EMI ID Ranges 
	extern Range iIRPShields; //Planetary Shield Item ID Range
	extern Range iIRPDefenses; //Planetary Defense Item ID Range
	extern Range iIRClones; //Clone Item ID Range

	extern Range iIRSShips; //Starter Ship Range

	//Ship ID Ranges By Class
	extern Range iIRSCFrig; //Frigate ID Range
	extern Range iIRSCDest; //Destroyer ID Range
	extern Range iIRSCCrui; //Cruiser ID Range
	extern Range iIRSCBCru; //Battle Cruiser ID Range
	extern Range iIRSCBShi; //Battleship ID Range
	extern Range iIRSCCShi; //Commandship ID Range
	extern Range iIRSCMShi; //Mother Ship ID Range
	extern Range iIRSCTita; //Titan Ship ID Range
	extern Range iIRSCMBar; //Mining Barge Item ID Range

	//Weapon ID Ranges By Class

	//Frigate Ranges
	extern Range iIRLCFrig; //Laser ID Range
	extern Range iIRMCFrig; //Missile ID Range
	extern Range iIRBCFrig; //Bomb ID Range
	extern Range iIRRCFrig; //Rail ID Range
	extern Range iIRHCFrig; //Heavy ID Range

	//Destroyer Ranges
	extern Range iIRLCDest; //Laser ID Range
	extern Range iIRMCDest; //Missile ID Range
	extern Range iIRBCDest; //Bomb ID Range
	extern Range iIRRCDest; //Rail ID Range
	extern Range iIRHCDest; //Heavy ID Range

	//Crusiser Ranges
	extern Range iIRLCCrui; //Laser ID Range
	extern Range iIRMCCrui; //Missile ID Range
	extern Range iIRBCCrui; //Bomb ID Range
	extern Range iIRRCCrui; //Rail ID Range
	extern Range iIRHCCrui; //Heavy ID Range

	//Battle Cruiser Ranges
	extern Range iIRLCBCru; //Laser ID Range
	extern Range iIRMCBCru; //Missile ID Range
	extern Range iIRBCBCru; //Bomb ID Range
	extern Range iIRRCBCru; //Rail ID Range
	extern Range iIRHCBCru; //Heavy ID Range

	//Battleship Ranges
	extern Range iIRLCBShi; //Laser ID Range
	extern Range iIRMCBShi; //Missile ID Range
	extern Range iIRBCBShi; //Bomb ID Range
	extern Range iIRRCBShi; //Rail ID Range
	extern Range iIRHCBShi; //Heavy ID Range

	//Commandship Ranges
	extern Range iIRLCCShi; //Laser ID Range
	extern Range iIRMCCShi; //Missile ID Range
	extern Range iIRBCCShi; //Bomb ID Range
	extern Range iIRRCCShi; //Rail ID Range
	extern Range iIRHCCShi; //Heavy ID Range

	//Mothership Ranges
	extern Range iIRLCMShi; //Laser ID Range
	extern Range iIRMCMShi; //Missile ID Range
	extern Range iIRBCMShi; //Bomb ID Range
	extern Range iIRRCMShi; //Rail ID Range
	extern Range iIRHCMShi; //Heavy ID Range

	//Titan Ranges
	extern Range iIRLCTita; //Laser ID Range
	extern Range iIRMCTita; //Missile ID Range
	extern Range iIRBCTita; //Bomb ID Range
	extern Range iIRRCTita; //Rail ID Range
	extern Range iIRHCTita; //Heavy ID Range

	//Mining Lasers by Class
	extern Range iIRFMLaser; //Frigate Mining Laser ID Range
	extern Range iIRDMLaser; //Destroyer Mining Laser ID Range
	extern Range iIRCMLaser; //Cruiser Mining Laser ID Range
	extern Range iIRBCMLaser; //Battle Cruiser Mining Laser ID Range
	extern Range iIRBMLaser; //Battleship Mining Laser ID Range
	extern Range iIRCSMLaser; //Commandship Mining Laser ID Range
	extern Range iIRMMLaser; //Mothership Mining Laser ID Range
	extern Range iIRTMLaser; //Titan Mining Laser ID Range

	//Mining Barge Mining Laser ID Range
	extern Range iIRMBMLaser;


	//Ship Related Values
	extern string sCNames; //Comma-delimited list of ship class names
	extern int sCTypes; //Number of ship classes


	//Planet Related Values	
	extern int pNames; //Number of planet/system names in the database
	extern Range rPSize; //Planet Size Range
	extern Range rPEKS; //Planet EKS Range
	extern Range rPT0; //Planet Type 0 Range
	extern Range rPT0SRange; //Planet Type 0 Size Range	
	extern Range rPT1; //Planet Type 1 Range
	extern Range rPT1SRange; //Planet Type 1 Size Range
	extern Range rPT2; //Planet Type 2 Range
	extern Range rPT2SRange; //Planet Type 2 Size Range
	extern Range rPT3; //Planet Type 3 Range
	extern Range rPT3SRange; //Planet Type 3 Size Range
	extern Range rPT4; //Planet Type 4 Range
	extern Range rPT4SRange; //Planet Type 4 Size Range
	extern Range rPT5; //Planet Type 5 Range
	extern Range rPT5SRange; //Planet Type 5 Size Range
	extern int popBase; //Base for pop random ranges	
	extern Range rP1; //Planet Pop Range 1
	extern Range rP2; //Planet Pop Range 2
	extern Range rP3; //Planet Pop Range 3


	//Game Related Values
	extern int iNSPlanets; //The number of planets scannable at once TODO: make this the max possible
	extern int iNTStations; //The number of stations scannable at once TODO: same as above
	extern Range rGPDispo; //Planet disposition range
	extern Range rGPAff; //Planet affitiliation range


	//Asteroid/Belt Related Values
	extern Range rBAAmount; //Asteroid belt asteroid amount range
	extern Range rBSize; //Asteroid belt size range
	extern Range iIRS1Ore; //Stage 1 ore item ID range
	extern Range rAS1Size; //Stage 1 asteroid size range
	extern float aS1SMulti; //Stage 1 asteroid size multiplier
	extern Range iIRS2Ore; //Stage 2 ore item ID range
	extern Range rAS2Size; //Stage 2 asteroid size range
	extern float aS2SMulti; //Stage 2 asteroid size multiplier
	extern Range iIRS3Ore; //Stage 3 ore item ID range
	extern Range rAS3Size; //Stage 3 asteroid size range
	extern float aS3SMulti; //Stage 3 asteroid size multiplier


	//Mission Related Values
	extern Range mIR; //Mission ID Range
	extern string mMLine; //Comma-delimited list of main mission line mission and their order


	//Empire/Race Related Values
	extern int rcTypes; //Number of races
	extern int eTypes; //Number of empires
	extern string rcNames; //Comma-delimited list of race names
	extern string eNames; //Comma-delimited list of empire names


	//Displomacy Related Values
	extern int dTypes; //Number of diplomatic states
	extern string dNames; //Comma-delimited list of diplomatic state names


	//Rank Related Values
	extern int rkTypes; //Number of ranks
	extern string rkNames; //Comma-delimited list of rank names


	//Name Generation Related Values
	extern Range rNPfx; //Prefix ID Range
	extern Range rNStem; //Stem ID Range
	extern Range rNSfx; //Suffix ID Range


	//Message Related Values



	//Resource Related Values
	extern int resTypes; //Number of resources
	extern string resNames; //Comma-delimited list of resources

	//Casino Related Values

	//Slot Payouts
	extern int cSPJP4; //Four Jackpots
	extern int cSPJP3_Br; //Three Jackpots + Bar
	extern int cSPJP3_7; //Three Jackpots + 7
	extern int cSPJP3_H; //Three Jackpots + Heart
	extern int cSPJP3_B; //Three Jackpots + Bell
	extern int cSPJP3_N; //Three Jackpots + Number

	//Bars
	extern int cSPBr4; //Four Bars
	extern int cSPBr3_J; //Three Bars + Jackpot
	extern int cSPBr3_7; //Three Bars + 7
	extern int cSPBr3_H; //Three Bars + Heart
	extern int cSPBr3_B; //Three Bars + Bell
	extern int cSPBr3_N; //Three Bars + Number

	//Sevens
	extern int cSP74; //Four Sevens
	extern int cSP73_J; //Three Sevens + Jackpot
	extern int cSP73_Br; //Three Sevens + Bar
	extern int cSP73_H; //Three Sevens + Heart
	extern int cSP73_B; //Three Sevens + Bell
	extern int cSP73_N; //Three Sevens + Number

	//Hearts
	extern int cSPH4; //Four Hearts
	extern int cSPH3_J; //Three Hearts + Jackpot
	extern int cSPH3_Br; //Three Hearts + Bar
	extern int cSPH3_7; //Three Hearts + 7
	extern int cSPH3_B; //Three Hearts + Bell
	extern int cSPH3_N; //Three Hearts + Number

	//Bells
	extern int cSPB4; //Four Bells
	extern int cSPB3_J; //Three Bells + Jackpot
	extern int cSPB3_Br; //Three Bells + Bar
	extern int cSPB3_7; //Three Bells + 7
	extern int cSPB3_H; //Three Bells + Heart
	extern int cSPB3_N; //Three Bells + Number

	//Numbers
	extern int cSPN4; //Four Numbers
	extern int cSPN3_J; //Three Numbers + Jackpot
	extern int cSPN3_Br; //Three Numbers + Bar
	extern int cSPN3_7; //Three Numbers + 7
	extern int cSPN3_H; //Three Numbers + Heart
	extern int cSPN3_B; //Three Numbers + Bell


	//Roulette Returns
	extern float cRBRZeros; //Zeros
	extern float cRBRNum; //Number
	extern float cRBRC_G; //Color; Green
	extern float cRBRType; //Type
	extern float cRBRC_RB; //Color; Red/Black
	extern float cRBRS_S; //Section; Small
	extern float cRBRS_L; //Section; Long
	extern float cRBRQ; //Quarter
	extern float cRBRH; //Half

	
	//Damage Related Values
	extern int dTTypes; //Number of damage types
	extern string dTNames; //Comma-delimited string of damage type names
	extern string dTEDP; //Comma-delimited string of extra damage percentages
	extern string dDPT; //Comma-delimited string of turns for turn based damage

	
	//Vectors
	extern vector<string> sClasses; //Ship Classes
	extern vector<string> eRanks; //Entity Ranks
	extern vector<string> rNames; //Race Names
	extern vector<string> rENames; //Race Empire Names
	extern vector<string> sDNames; //Secondary Damage Names
	extern vector<float>  sDDPerc; //Secondary Damage Damage Percentges
	extern vector<int>	   sDETurns; //Secondary Damage Effect Turns
	extern vector<string> gRNames; //Resource Names
	extern vector<string> gDNames; //Diplomatic State Names
	extern vector<int>	gMMissions; //Main mission line

	//Misc
	extern int i,i2,i3,i4; //For for loops
	extern vector<string> temp1; //For vector imports that have to be cast to another type 


};
#endif