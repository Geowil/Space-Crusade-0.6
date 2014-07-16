#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "entity.h"
#include "planet.h"
#include "station.h"
#include "data_placeholder.h"
#include "battleproc.h"
#include "map.h"
#include "c_ai.h"
#include "hand.h"

using std::string;
using std::vector;

struct bet;

class Game
{
public:
	Game();

	//Misc Game Functions

	//Save & Load Game Functions
	void gSave(Player& mPlayer);
	void gLoad(Player& mPlayer);


	//Planet Functions

	//Planet Generation
	void getPNames();
	void generatePlanets();
	float calcPop();
	void getDefenses(int rand, float eks);
	void getShields(int rand, float eks);
	void addDefenses(int i, float eks);
	void addShields(int i, float eks);



	bool isDest(int id); //check if planet already destroyed by player
	//bool isOwned(int id); //check if planet already counqured by player
	void fPlanets(); //find planets
	int pPlanets(Player& mPlayer); //print list of found planets

	void initPVector(); //Initialize planet vectors

	void iSPlanets(); //Init the scanned planets vector
	void rSPlanets(); //Reset scanned planets vector

	void getDList(); //get list destroyed planets
	string getDPlanet(int i); //get destroyed planet
	void setSDPlanet(int i, string name); //set specific destroyed planet (for name encryption)
	void loadPlanet(planetData plData);
	//void setPOwned(string plname); //set planet as owned by player
	//void getOPlanets(); //get list of planets owned by player

	void pMenu(Player& mPlayer, Planet* gPlanet, Game& mGame_m, string* eResult, Map& m_m, battleProc& bp_m, NPC& mNPC); //Planet interact menu
	void gPHail1(Player& mPlayer, Planet* gPlanet);
	//void gPHail2(string race, string affiliation, Player& mPlayer);
	void gFABelts(Player& mPlayer, Planet* gPlanet);


	//Station Functions

	//Station getStation(string name); //return station

	void iTStations(); //Init the scanned planets vector
	void rTStations(); //Reset scanned planets vector
	void fStations(); //Find Stations and create them if they do not exist
	int pStations(Player& mPlayer);

	void sSItem(Player& mPlayer, Station& stat_g, bool bought); //Store item in inventory
	void sGItem(Player& mPlayer, Station& stat_g); //Get an item from this station

	void createStation(string name, Player& mPlayer); //Create station reference for menu operations AND create the actual station and place it into gStations if it does not already exist

	void sMenu(Player& mPlayer, Station& stat_g); //station menu
	void sSBuyW(); //buy weapon
	void sSBuyS(); //buy ship
	void sSBuyM(); //buy mod

	void sMLoop1(Player& mPlayer, Station& stat_g); //station market loop

	//Buy market
	void sMLoop2A1(Player& mPlayer, Station& stat_g); //Start buy market
	void sWMLoopB(Player& mPlayer, Station& stat_g); //station weapon menu loop
	void sSMLoopB(Player& mPlayer, Station& stat_g); //station ship menu loop
	void sEMLoopB(Player& mPlayer, Station& stat_g); //station equipment menu loop
	void sRMLoopB(Player& mPlayer, Station& stat_g); //station resource buy menu
	void sOMLoopB(Player& mPlayer, Station& stat_g); //station ore buy menu

	//Sell market
	void sMLoop2B1(Player& mPlayer, Station& stat_g); //Start sell market
	void sMLoop3A1(Player& mPlayer, Station& stat_g); //Where is it located - non-ship
	void sMLoop3A2(Player& mPlayer, Station& stat_g); //Where is it located - ship
	void sMLoop4A(Player& mPlayer, Station& stat_g, bool ship, bool station); //Choose what to sell (non-ship)
	void sMLoop4B(Player& mPlayer, Station& stat_g, bool ship, bool station); //Choose what to sell (ship)

	/*
	void sWMLoopS(Player& mPlayer, Station& stat_g); //station weapon menu loop
	void sSMLoopS(Player& mPlayer, Station& stat_g); //station ship menu loop
	void sEMLoopS(Player& mPlayer, Station& stat_g); //station equipment menu loop
	void sRMLoopS(Player& mPlayer, Station& stat_g); //station resource menu loop
	*/

	void sSell(Player& mPlayer, Station& stat_g, bool bIOShip, bool bIOStation, bool bIsShip, int slot); //Sell chosen item

	void sMBClone(Player& mPlayer, Station& stat_g, int iID); //Buy clone
	void sMRefund(Player& mPlayer, Station& stat_g); //Refund a purchase as a last resort

	string getIType(); //get specific item type for special weapon stat values

	void sMPurchase(Player& mPlayer, Station& stat_g); //station market purchase

	void sRepair(Player& mPlayer, Station& stat_g);
	void bClone(Player& mPlayer, Station& stat_g);
	void useClone(Player& mPlayer, int sID, int sIID, int iID);
	void sShop(Player& mPlayer);
	void sMOffice(Player& mPlayer);
	void sBOffice(Player& mPlayer);
	void sEAFOffice(Player& mPlayer);
	void sPub(Player& mPlayer);
	void sCasino(Player& mPlayer);

	void sDepart(Player& mPlayer, Station& stat_g);

	void loadStation(stationData& stData);

	void startMission(Player& mPlayer);
	void completeMission(Player& mPlayer);

	void createBInfo();

	//Casino Functions
	void sCSlots(Player& mPlayer);
	void setupSlots();
	int sCSCheck(); //Check the slot reels to see if a combination has been achieved
  
	void sCBJack(Player& mPlayer);
	void setupPBJBet(Player& mPlayer); //Set up the player's bet; blackjack
	void setupAIBJBet(); //Set up the AI bets; blackjack
	void aiBJTurn(); //Process AI blackjack turn
	void rPBJack(Player& mPlayer); //Round processing; blackjack
    
	void sCPoker(Player& mPlayer);

	void sCP5Card(Player& mPlayer); //Normal poker
	void sCP5CPSetup(); //Pre-game setup; Poker 5-Card
	void sCP5Bet(Player& mPlayer); //Bet processing (P/AI); Poker 5-card
	void sCP5AIBCalc(); //Bet calculation for AI; Poker 5-card
	void sCP5CTProc(Player& mPlayer); //Card trading processing (both player and AI); Poker 5-card
	void sCP5HProc(Player& mPlayer); //Hand processing (both player and AI); Poker 5-card
	
	void sCPTHEm(Player& mPlayer); //Texas Hold'em
	void sCPTPSetup(); //Pre-game setupl Poker Texas Hold'em
	void sCPTBet(Player& mPlayer); //Bet processing (P/AI); Texas Hold'em
	void sCPTHProc(Player& mPlayer); //Hand processing (P/AI); Texas Hold'em

	void sCPOHEm(Player& mPlayer); //Omaha Hold'em
	void sCPOPSetup(); //Pre-game setup Omaha Hold'em
	void sCPOBet(Player& mPlayer); //Bet processing (P/AI); Omaha Hold'em
	void sCPOHProc(Player& mPlayer); //Hand processing (P/AI); Omaha Hold'em
    
	void sCRoulette(Player& mPlayer);
    
	//void sCDJott(Player& mPlayer);
    
	void sCCraps(Player& mPlayer);
    

	void setupCAI(bool R, bool P);
	void setupCards();
	void dealCards(bool P5, bool PTH, bool POH, Player& mPlayer);
    void setupCCards(); //Works based on size of sCCCards vector to determine what phase of the game is being played
	void collectBlinds(Player& mPlayer);
	void collectAnte(Player& mPlayer);
	void setupDealer(Player& mPlayer); //Setup the dealer for poker games
    
	void sSFitting(Player& mPlayer, Station& stat_g); //Allow player to edit ship equipment
	void sStorage(Station& stat_g); //Cycle through any stored items on this station

	//Planet Public Vectors
	vector<Planet> gPlanets; //Generated planets
	vector<Planet> sPlanets; //scanned planets vector, max of 15 planets found at anytime
	vector<Planet> pDestPlan; //destroyed planets name vector
	//vector<Planet> oPlanets; //player owned planets


	//Station Public Vectors
	vector<Station> gStations; //Generated stations
	vector<Station> tStats; //Temp Stations used while finding stations


private:

	//Misc Game Variables

	//Save/Load Variables
	string storage1;
	string storage3;
	float storage2;
	int storage4;

	bool bDSComplete, bDLComplete; //bools: did save/load copmplete successfully?

	//Global Use
	int i,i2,i3, i4, i5, i6, i7, i8;


	//Planet Variables

	//Randoms
	int pNRand; //Name
	float pERand; //EKS
	float pSRand; //planet size
	int pSRRand; //planet size range
	int pDRand; //Defense Point(s)
	int popRand1, popRand2, popRand3; //population randoms
	int pDisRand;
	int pAffRand;

	int pRID; //random planet id for scanning

	string tempDisp;
	string tempAffi;
	string tempRace;

	//Constants (const as in non-random)
	long long int pPMax; //planet max sustainable pop
	float pPStore; //store planet pop so we can cast to lli
	string sName; //store planet name for duplicate checking
	int nCode; //planet name code

	//Vectors
	vector<string> pNStorage; //Planet name storage

	//Bools
	bool bUPName; //bool: does planet have a non-used (unique) name
	bool bPPGen; //bool: has planet population been generated

	bool		replaced; //Has array element been replaced?
	int			nSPlanets; //number of scannable planets, will vary based on equipped modules in future; for now hard capped at 15
	int			nTStations; //number of scannable stations, will vary based on equipped modules in future; for now hard capped at 25
	int			nTSPID; //store id for planet whose name is used for the station
	int			nTSSV; //store random value to determine the suffix of the station name
	string		nTSSuffix; //Store the suffix here until it is ready to use

	int numODef, numOShd, rRange;

	/*
		Planet Scanning:

		Factory ships under Cruiser class can only scan a maximum of 5 planets at a time.
		Upgrades available to increase this.  Ships at or above Cruiser can scan up to 10.
		Upgrade required for the extra five slots on those ship classes.
	*/


	//Station Variables
	int			pChoice; //Player Choice
	bool		sLeave; //Leave station?
	bool		sMMenu, sMMenu2, sMMenu3, sMMenu4; //Stay at market menu?
	bool		sWMenu; //Stay at weapon menu?
	bool		sSMenu; //Stay at ship menu?
	bool		sMDMenu; //Stay at mod menu?
	int			cCode; //For ship classification
	string		cCode2; //For ship classification
	int			iCode; //To obtain information on item
	string		iType; //To determine the type of item that was purchased
	string		iType2; //To determine the specific item type
	bool		sMBuy; //Check if player decided to purchase item
	int			csPos; //for cStations position
	string			wType; //To store name of specific weapon type for weapon installation
	string			wClass; //Weapon class, used in weapon installation

	//Store Data
	float sISG2; //Hold sg2 size of inventory items

	//For selling
	int amount;

	int sTCost, sPTax, sTPCost; //Store cost values for clone buying; will likely be applied to everything in future
	float sTax; //Store tax percentage for clone sales

	bool		bDASlot; //Player bought storage slot?
	bool		bDASpace; //Player bought storage space?
	bool		bDone;	//Item Store is Done?
	bool		bContinue, bContinue2, bContinue3; //For station menu looping
	bool		bRepair; //bool: Repair your ship?
	bool		bSSuccess; //bool: was storage successful?
	bool		bValid; //bool: is selection valid?

	int			pAffin; //Store player affinity for later use
	int			sRCPPX; //cost per percentage point to repair; Xarn
	int			sRCPPR; //cost per percentage point to repair; Rubies
	int			sRCPPDi; //cost per percentage point to repair; Diamonds
	int			sRCPPD; //cost per percentage point to repair; Draconic

	bool bExchange; //bool: did player say to exchange their current ship for the new one?

	float dPerc;
	float dPerc_R;
	int   dPerc_I,dPerc_I2,dPerc_T;

	int oldCXPTNL; //For clone system

	int mID; //Hold mission ID
	bool gMStart; //Did player choose to undertake the mission?
	float xarnMultiplier;
	int xarnReward;

	string		sname;
	string		dispo;
	string		affil;
	int			stlevel;
	int			sslevel;

	vector<int> tWStorage; //Store non-compliant weapon ids here temporarily when changing ships

	//Temp storage for ship weapon vectors
	vector<hardPointL> tLBanks;
	vector<hardPointM> tMTurrets;
	vector<hardPointB> tBHolds;
	vector<hardPointR> tRMounts;
	vector<hardPointH> tHWBays;

	/*
	Tech Level & Station Level

	The technology level is the advanced state of the station.  It will determine several things:

	1. Can the station support cloning operations
	2. Can the station repair your ship
	3. Can you or how much you can store at the station
	4. Prices ontop of the multiplier
	5. What type and how many missions are available
	6. What items are sold at the station

	The list of how these break down is under development currently and is not yet finalized.

	*/

	//For Debug
	string file,line,bLocale,time,date,bTDate;


	//Casino Members
	int sCChips; //Casino Chips


	vector<casinoAI> players; //Store ai players here
	
	//Slot Reels
	string cSR1[20];
	string cSR2[20];
	string cSR3[20];
	string cSR4[20];
	string cSR5[20];
    string cSR6[20];
    string cSR7[20];
    string cSR8[20];
    string cSR9[20];
    string cSR10[20];
    string cSR11[20];
    string cSR12[20];

	//Card Deck(s)
    string cards[52];


    vector<vector<string>> slots;
    vector<string> tempSStr; //Temp vector for inserting empty string vectors into slots

    string tempReel, tReel1, tReel2, tReel3, tReel4; //Hold a reel element while it is being loaded
	int tReel1I, tReel2I, tReel3I, tReel4I; //Store int version of the reels if neccessary
    int rChips; //Returned chip value

    
    vector<bet> rBets;
    int rInt1, rInt2, rInt3, rInt4; //Int Randoms
    float rFloat1, rFloat2, rFloat3, rFloat4; //Float Randoms
    int rNOPlayers;
    int iBValue; //Hold player bet (int)
    string sBValue; //Hold player bet (string)
    char cBValue; //Hold player bet (char)
    string sSize; //Section size

	//Roulette
	 string sCRWValue; //Value that the marble stopped on
    int sCRWVInt; //To hold the int value of whatever the marble lands in
    string sCRWVString; //To hold the string value of whatever the marble lands in
    char sCRWVChar; //To hold char value of whatever the marble lands in (for colors)
	

	/* Setup for roulette table

	Total number of pockets = 76; 1-72 + 0/00/000/0000

	4 Blocks per table, two sections per block with one section being greater than the other (11P to 7P)

	Larger section setup so that odds are red and blacks are even
	Smaller section setup so that odds are black and evens are red

	0/00/000/0000 are green

	Numbers are arranged so that next or previous number in sequence is directly across from said pocket and is an opposing color

	At end of a block, the number should be in order.  Start of block, first pocket should be same type as end of last block and seems
	to be opposite of the block number (block 1 is even, block 2 is odd, etc.)

    */

    //TODO: fix the numbers so that they are correct.  Currently if a higher number is used, the next lowest number can be used after it and this adds the higher number to
    //the wheel in error

	string sCRWheel[76];

    //Poker/BJ

    //Card Deck
    vector<string> sCCDeck;

   //TODO: add a second player hand in case of split OR use a vector of string vectors (former being preferred)
   //Player Hand
   vector<hand> sCPHand;

   string tCard1, tCard2, tCard3, tCard4, tCard5; //Temp variables to hold substringed card values for use in conditional statements (the suit markers make this impossible otherwise)
   int card1, card2, card3, card4, card5; //Int storage for casted card values
   vector<int> iCValues, iCValues2; //Same as above but in a vector to deal with for looping; scond vector for player/dealer comparisons
   vector<string> sCValues; //Store string card values that have been substringed
   int tCValue, tCValue2; //Total cards value; second variable for player to dealer comparison

   //Variables for poker games
   vector<string> sCCCards; //For Texas and Omaha Hold'em community cards

   //Values for poker games
   int blind1, blind2; //For TH/OH; blinds increase 25% every three hands
   int ante; //For all poker games
   int pot; //For all poker games
   int sPot; //For side pot; Hold'em games

   vector<string> betOrder; //Store the order of player betting by name

   int dPos; //Dealer position; used when the dealer is an AI player

   int rDone; //Value to reach to finish a round; tracks the number of total hands played a blackjack round
   int hFin; //Hands finished; when reaches rDone then the round is over

   bool bRaise, bCall, bCheck, bAIn; //To be used as loop controls for betting so that if a raise is issued each player is required to re-call
   int rPos; //To keep track of the last raiser's position in the betting order
   int lastBet;

   Range aiBRange; //AI betting range
   int aiCFav; //AI call/check favorability; will be used as a multiplier
   int aiRFav; //AI raise favorability; will be used as a multiplier
   int aiFFav; //AI fold favorability; will be used as a multiplier
   int aiAFav; //AI all-in favorability; will be used as a multiplier
   int aiBVar; //AI bet variability; will be used as part of a multiplier by using this value times 12 added to the base bet

   //Total of all variables may be more or less than 100%
   float aiCall; //How likely it is that the AI will call (out of 100%)
   float aiRaise; //How likely it is that the AI will raise (out of 100%)
   float aiFold; //How likely it is that the AI will fold (out of 100%)
   float aiAIn; //How likely it is that the AI will all-in (out of 100%)

   float aiAVar; //A variability value to make AI action a bit more random; random value between 0.2 and 0.7

   int aiBBet; //Base Bet
   int aiBRMulti; //Bet range multiplier
   int aiTBet; //Total final bet of an AI player

   int aiSSuit1,aiSSuit2,aiSSuit3,aiSSuit4; //Used to store how many cards of a certain suit are in the AI player's hand
   int aiSVal; //Used to store how many cards with the same value are in the AI player's hand; only tracks the greatest number for betting

   //Bidding flags/array-
   /*
		These flags are used by the AI to determine the second multiplier to the bet range.  Bet range will almost always start low (10 to 60 min max and 70 to 145 max max).
		Bet range is influenced by betting flags and then further by the above two variable groups as a basic multiplier.  Flags representing greater hands will have
		a larger effect on the bet range while less will have a lower effect.  These will further be influenced by the bRaise and bAIn flags.

		The array will track the number of the number of same-valued cards in the current hand being examined.  Done this way, even though more resource intensive, because it represents up to date information
		that using the hand struct would otherwise not provide (would have to update and recheck the struct instead of doing all that at once even if multiple times).
   */

   bool bSFlush; //Flag to alert the AI to a straight flush which will heavily influence betting
   bool bFlush; //Flag to alert the AI to a flush which will heavily influence betting
   bool bStraight; //Flag to alert the AI to a straight which will heavily influence betting
   bool bFHouse; //Flag to alert the AI to a full house which will moderatly influence betting
   bool bFKind; //Flag to alert the AI to four of a kind which will moderatly influence betting
   bool bTKind; //Flag to alert the AI to three of a kind which will lightly influence betting
   bool bTPair; //Flag to alert the AI of a two pair which will slightly influence bidding
   bool bPaid; //Flag to alert the AI of a pair which will barely influence bidding
   bool bHCard; //Flag to alert the AI of a high card situation (no combos) will not influence bidding
   int aiRCards[13]; //Ai's recurring card values


 };

struct bet
{
    string bType; //What type of bet is this
    int chips; //How many chips were placed on this bet
    string bName; //Better's name
    int bID; //Better's ID (for AI)

    //Bet specifics
    int number;
    string zero;
    char color;
    string type;
    int section;
    int quarter;
    int half;
	int hand; //To track which hand the bet is for if a player splits
};
#endif



