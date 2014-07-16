#ifndef	DATA_PLACEHOLDER_H
#define DATA_PLACEHOLDER_H

#include <string>
using std::string;

struct ship
{
    int sID;
    string sName;
    string sDesc;
	string sType;
    string sClass;
	int sTLevel;
    float sShield;
    float sArmor;
    float sHull;
    int sTHPoints;
    int sLBanks;
    int sMTurrets;
    int sRMounts;
    int sHWBays;
    int sBHolds;
    int sMInit;
    float sSG2;
    float sCargo;
    int sXCost;
    int sRCost;
    int sDiCost;
    int sDCost;
    int sUCost;
    int sPCost;
};

struct weapon
{
    int wID;
    string wName;
    string wDesc;
	string wType;
	string wClass;
	int wTLevel;
    float wMDamage;
    float wMxDamage;
	string wDType;
	float wDILow; //weapon damage intensity range low
	float wDIHigh; //weapon damage intensity range high
	int wACon; //weapon ammo consumption rate
    float wMass;
    int wMTDistance;
    int wMOTDistance;
    int wMxOTDistance;
    int wMxTDistance;
    float wSG2;
    int wMCLength;
    float wMCAmount;
    int wXCost;
    int wRCost;
    int wDiCost;
    int wDCost;
    int wLCost;
    int wUCost;
    int wPCost;
    int wNWCost;
};

struct pshield
{
    int psID;
    string psName;
    string psDesc;
    string psType;
    int psTLevel;
    float psSPoints;
    float psSPRegen;
    float psSG2;
    int psXCost;
    int psRCost;
    int psDiCost;
    int psDCost;
    int psLCost;
    int psUCost;
    int psPluCost;
    int psNWCost;
};

struct pdefense
{
    int pdID;
    string pdName;
    string pdDesc;
    string pdType;
    int pdTLevel;
    float pdSPoints;
    string pdDType;
    float pdMDmg;
    float pdMxDmg;
    int pdRng;
    float pdSG2;
    int pdXCost;
    int pdRCost;
    int pdDiCost;
    int pdDCost;
    int pdLCost;
    int pdUCost;
    int pdPluCost;
    int pdNWCost;
    int pdCXP;
};

struct clone
{
    int cID;
    string cName;
    string cDesc;
    string cType;
    int cTLevel;
    float cSG2;
    int cXCost;
    int cRCost;
    int cDiCost;
    int cDCost;
    int cLCost;
    int cUCost;
    int cPluCost;
    int cNWCost;
    string cEffect;
};


struct mission
{
    int mID;
    string mName;
    string mDesc;
    int mCBELevel;
    string mSCReq;
    string mMWReq;
    int mTLimit;
    string mDifficulty;
    string mSector;
    string mSystem;
    string mTName;
    string mTSClass;
    int mBounty;
    int mXarn;
    int mRubies;
    int mDiamonds;
    int mDraconic;
    int mLithium;
    int mPlatinum;
    int mUranium;
    int mPlutonium;
    int mNWaste;
    int mCEXP;
    string mItem;
    string mType;
};


struct message
{
    string mes;
};

struct planetName
{
    string pName;
    int pID;
};

/*
struct pDData //For Planetary defenders in later versions
{

};
*/

struct empires
{

};

struct corporations
{

};

struct diplomacy
{
    string dDisposition;
};

struct race
{
    string rName;
};

struct ranks
{
    string rkName;
};

struct name
{
    string name_;
};

struct resource
{
    string rName;
    string rDesc;
    float rSG2;
    string rType;
    int rXCost;
};

struct ore
{
    string oName;
    string oDesc;
    float oSG2;
    string oType;
    int oStage;
    float oBSize;
    string oResource;
    string oOre;
    float oRUnits;
    int oRProduced;
    int oRCost;
    float oRPLoss;
    int oXCost;
};

//Save File Table Structs
struct planetData
{
    int pID; //Planet ID
    string pName;
    string pAffiliation;
    string pDispo;
    string pRace;
    int bIsPOwned;
    int bIsDestroyed;
    float pEKS;
    float pSize;
    long long int pCPop;
    long long int pMPop;
};

struct pDefData
{
    int pID; //Planet ID from table
    int pDID; //Planetary Defense ID for table lookup
};

struct pSData
{
    int pID;
    int mID; //Moduel table item ID for table look up
};

struct pABelts
{
    int bID; //Belt ID from table
    int pID; //Planet ID that this belt belongs to
    string bName; //Belt name
    float bSize; //The size of the belt
    int bBIsFull; //bool: is this belt full (using integer interface)
};

struct pABRoids
{
    int aID; //Asteroid ID from table
    int bID; //Belt ID that this roid belongs to
    int pID;
    string aName; //Name of this roid
    string aDesc; //Roid description
    float aSize; //Size of this roid
    string aOName; //Ore name
    int aOID; //Ore ID
    float aOAmount; //How much ore is present in the roid

    //Roid position in belt
    int xPos;
    int yPos;
    int zPos;
};

struct playerData
{
    string pName;
    string pRank;
    int pCXPLevel;
    int pPDestroyed;
    int pFKills;
    int pDKills;
    int pCKills;
    int pBCKills;
    int pBKills;
	int pCSKills;
    int pMKills;
    int pTKills;
    int pCEXP;
    int pCXPTNL;
    int pXarn;
    int pRubies;
    int pDiamonds;
    int pDrac;
    int pLith;
    int pPla;
    int pUra;
    int pPlu;
    int pNWaste;
    string pAffiliation;
};

struct pShip
{
    string sName;
    string sClass;
    int sTLevel;
    float sSP;
    float sAP;
    float sHP;
    float sMSP;
    float sMAP;
    float sMHP;
    int sMInit;
    float sSG2;
    float sMCSpace;
    int sLB;
    int sMT;
    int sBH;
    int sRM;
    int sHWB;
    int sWHP;
    int sULB;
    int sUMT;
    int sUBH;
    int sURM;
    int sUHWB;
    int sMWSpreads; //Max number of usable weapon spreads
    int sID;
    int sSID; //Ship ID
    int sSTID; //Station ID
    string sLocal; //If this ship is stored, where? Station or ship?
};

struct pSInv
{
    int sID; //Ship ID
    int iID; //Item ID
    string iType; //Item Type
    int iAmount; //Amount of items
    float iSG2; //Space each item takes up
};

struct pSSpread
{
    int sID; //HPSlot value in the weapon vector indicated by the below variable
    string sWType; //What type of weapon was stored in the slot
    int sPID; //Spread ID, used to track which weapons belong to which spread
};

struct pSHPVect
{
    int sID; //HPSlot value in the weapon vector indicated by the below variable
    int wID; //Weapon ID
    string sWType; //What type of weapon was stored in the slot
};

struct pWingmenData
{
    string pWName;
    string pWRank;
    int pWCXPLevel;
};

struct pWShip
{
    int pWID; //ID from table to deal with multiple wingmen w/o having to use a crap ton of tables for each
    string sName;
    string sClass;
    int sTLevel;
    float sSP;
    float sAP;
    float sHP;
    float sMSP;
    float sMAP;
    float sMHP;
    int sMInit;
    int sLB;
    int sMT;
    int sBH;
    int sRM;
    int sHWB;
    int sWHP;
    int sULB;
    int sUMT;
    int sUBH;
    int sURM;
    int sUHWB;
    int sMWSpreads;
};

struct pWSSpread
{
    int sID; //HPSlot value in the weapon vector indicated by the below variable
    string sWType; //What type of weapon was stored in the slot
    int wID; //ID of wingmen this spread belongs to
    int sPID; //Spread ID
};

struct pWSHPVect
{
    int sID; //HPSlot value in the weapon vector indicated by the below variable
    int wep_ID; //Weapon ID
    string sWType; //What type of weapon was stored in the slot
    int wID; //ID of wingmen this spread belongs to
};

struct stationData
{
    int sID; //ID from table for dealing with player inventories in various stations
    string sName;
    string sAffiliation;
    string sDispo;
    int sTLevel;
    int sLevel; //Station level
    float sMSpace; //Max usable storage space
    float sCMulti; //Cost multiplier
};

struct sPInv
{
    int sID; //Station ID
    int iID; //Item ID
    int NOI; //Number of items stored
    string iType;
    float iSG2;
};

struct missionData
{
    int mID; //Mission ID
    string mName;
    string mDesc;
    string mType;
    int mCBEReq; //combat experience requirement
    string mSCReq; //ship requirement
    string mMWReq; //module/weapon requirement
    int mDur; //duration in days
    string mDifficulty;
    string mLSector; //location; sector
    string mLSystem; //location; system
    string mTName; //target name
    string mTSClass; //target ship class
    int mBounty;
    int mXR; //xarn reward
    int mRR; //ruby reward
    int mDiR; //diamond reward
    int mDR; //draconic reward
    int mLR; //lithium reward
    int mPlR; //platinum reward
    int mUR; //uranium reward
    int mPR; //plutonium reward
    int mNWR; //nuclear waste reward
    int mEXPR; //exp reward
    string mIR; //item reward;
    int mState; //Mission State
};

struct relationData
{
    string	rName; //Name of entity the relationship is relevent to (IE: Earth Alliance)
    int		rAffinity; //Value of the relationship; negative numbers indicate a negative relationship.
};

struct saveFlag
{
    string sfName; //Flag Name
    int sfValue; //Flag Value
};

#endif
