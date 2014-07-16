#include <string>
#include "weapon.h"
#include "datasystem.h"

using namespace std;

dataSystem ds_w;

//Weapon Functions
int Weapon::getWDRLow()
{
	return wDRange.iLow;
}

int Weapon::getWDRHigh()
{
	return wDRange.iHigh;
}

int Weapon::getWDROLow()
{
	return wDRange.iOLow;
}

int Weapon::getWDROHigh()
{
	return wDRange.iOHigh;
}

int Weapon::getWALow()
{
	return wAcc.iLow;
}

int Weapon::getWAHigh()
{
	return wAcc.iHigh;
}

int Weapon::getWAOLow()
{
	return wAcc.iOLow;
}

int Weapon::getWAOHigh()
{
	return wAcc.iOHigh;
}

int Weapon::getWTLevel()
{
	return wTLevel;
}

int Weapon::getWType()
{
	return wType;
}

string Weapon::getWClass()
{
	return wClass;
}

string Weapon::getWName()
{
	return wName;
}

string Weapon::getWDType()
{
	return wDType;
}
	

bool Weapon::isWDisabled()
{
	return wStatus;
}

void Weapon::toggleWeapon(int time)
{
	if (wStatus == false)
	{
		wStatus = true;
		wDTimer = time;
	}

	else
	{
		wStatus = false;
	}
}

void Weapon::initWeapon()
{
	wName = "No Weapon Installed";
	wID = 999999;
	wType = 0;
}

void Weapon::wSetup(int wCode)
{
	ds_w.rData("Weapon_Data","select from",wCode);
}

int Weapon::getWID()
{
	return wID;
}

float Weapon::getSG2()
{
	return wSG2;
}

void Weapon::setSG2(float sg2)
{
	wSG2 = sg2;
}

//Laser Functions
Laser::Laser()
{
	
}

void Laser::iWeapon()
{
	wID = ds_w.getWID();
	wName = ds_w.getWName();	
	wClass = ds_w.getWClass();
	wTLevel = ds_w.getWTLevel();
	wDType =  ds_w.getWDType();		
	wDRange.iLow = ds_w.getWDRLow();
	wDRange.iHigh = ds_w.getWDRHigh();	
	wAcc.iLow = ds_w.getWAMin();
	wAcc.iOLow = ds_w.getWAOMin();
	wAcc.iOHigh = ds_w.getWAOMax();
	wAcc.iHigh = ds_w.getWAMax();
	wSG2 = ds_w.getWSG2();
	wMCLength = ds_w.getWMCLength();
	wMCAmount = ds_w.getWMCAmount();
}

Laser* Laser::getWeapon()
{
	return this;
}

int Laser::getCLength()
{
	return wMCLength;
}

float Laser::getCMAmount()
{
	return wMCAmount;
}


//Missile Functions
Missile::Missile()
{

}

void Missile::iWeapon()
{
	wID = ds_w.getWID();
	wName = ds_w.getWName();	
	wClass = ds_w.getWClass();
	wTLevel = ds_w.getWTLevel();
	wDType =  ds_w.getWDType();		
	wDRange.iLow = ds_w.getWDRLow();
	wDRange.iHigh = ds_w.getWDRHigh();	
	wAcc.iHigh = ds_w.getWAMax();
	wSG2 = ds_w.getWSG2();
}

Missile* Missile::getWeapon()
{
	return this;
}

//Bomb Functions
Bomb::Bomb()
{

}

void Bomb::iWeapon()
{
	wID = ds_w.getWID();
	wName = ds_w.getWName();			
	wClass = ds_w.getWClass();
	wTLevel = ds_w.getWTLevel();
	wDType =  ds_w.getWDType();		
	wDRange.iLow = ds_w.getWDRLow();
	wDRange.iHigh = ds_w.getWDRHigh();
	bWeight = ds_w.getWWeight();
	wSG2 = ds_w.getWSG2();
}

int Bomb::getWeight()
{
	return bWeight;
}

Bomb* Bomb::getWeapon()
{
	return this;
}

//Rail Gun Functions
Rail::Rail()
{

}

void Rail::iWeapon()
{
	wID = ds_w.getWID();
	wName = ds_w.getWName();
	wClass = ds_w.getWClass();
	wTLevel = ds_w.getWTLevel();
	wDType =  ds_w.getWDType();		
	wDRange.iLow = ds_w.getWDRLow();
	wDRange.iHigh = ds_w.getWDRHigh();
	rAConsume = ds_w.getWACRate();
	wAcc.iLow = ds_w.getWAMin();
	wAcc.iOLow = ds_w.getWAOMin();
	wAcc.iOHigh = ds_w.getWAOMax();
	wAcc.iHigh = ds_w.getWAMax();
	wSG2 = ds_w.getWSG2();
}

string Rail::getAName()
{
	return rAName;
}

int Rail::getAAmount()
{
	return rAmmo;
}

int Rail::getACon()
{
	return rAConsume;
}

void Rail::setAName(string s)
{
	rAName = s;
}

void Rail::updateAAmount(int newAmmo, string operation)
{
	if (operation == "add")
	{
		rAmmo += newAmmo;
	}

	else if (operation == "sub")
	{
		rAmmo -= newAmmo;
	}

	else if (operation == "set")
	{
		rAmmo = newAmmo;
	}
}

Rail* Rail::getWeapon()
{
	return this;
}

//Heavy Weapon Functions
Heavy::Heavy()
{

}

void Heavy::iWeapon()
{
	wID = ds_w.getWID();
	wName = ds_w.getWName();
	wClass = ds_w.getWClass();
	wTLevel = ds_w.getWTLevel();
	wDType =  ds_w.getWDType();		
	wDRange.iLow = ds_w.getWDRLow();
	wDRange.iHigh = ds_w.getWDRHigh();	
	wAcc.iLow = ds_w.getWAMin();
	wAcc.iOLow = ds_w.getWAOMin();
	wAcc.iOHigh = ds_w.getWAOMax();
	wAcc.iHigh = ds_w.getWAMax();
	wSG2 = ds_w.getWSG2();
	hDInt.iOLow = ds_w.getWDIRLow();
	hDInt.iOHigh = ds_w.getWDIRHigh();
}

float Heavy::getDILow()
{
	return hDInt.fLow;
}

float Heavy::getDIHigh()
{
	return hDInt.fHigh;
}

void Heavy::setDIRange(float l, float h)
{
	hDInt.fLow = l;
	hDInt.fHigh = h;
}

Heavy* Heavy::getWeapon()
{
	return this;
}

