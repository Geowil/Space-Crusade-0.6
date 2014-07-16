#include "damage.h"
#include "planet.h"
#include "random.h"
#include "datasystem.h"
#include "map.h"
#include "msgproc.h"
#include "globalvars.h"

using std::string;
namespace gv = gVars;


dataSystem ds_dmg;
Map m_dmg;
msgProc mp_dmg;

Damage::Damage()
{

}

void Damage::dmgProcessing(bEntity& bAttacker, bEntity& bTarget)
{
	setupWQueue(bAttacker);
	bAttack(bAttacker, bTarget);
	bDamage(bAttacker, bTarget);
	clearBAT(bAttacker, bTarget);

	if (bIsDestroyed)
	{
		bIsDestroyed = false; //Reset this for the next battle
	}
}

void Damage::dmgProcessing_PS(bEntity& bAttacker, bEntity& bTarget)
{
	setupWQueue(bAttacker);
	bAttack_PS(bAttacker, bTarget);
	bDamage_PS(bAttacker, bTarget);
	clearBAT_PS(bAttacker, bTarget);

	if (bIsDestroyed)
	{
		bIsDestroyed = false; //Reset this for the next battle
	}
}

void Damage::dmgProcessing_PDP(bEntity& bAttacker, bEntity& bTarget)
{
	setupWQueue(bAttacker);
	bAttack_PDP(bAttacker, bTarget);
	bDamage_PDP(bAttacker, bTarget);
	clearBAT_PDPA(bAttacker, bTarget);

	if (bIsDestroyed)
	{
		bIsDestroyed = false; //Reset this for the next battle
	}
}

void Damage::dmgProcessing_PDD(bEntity& bAttacker, bEntity& bTarget)
{
	setupWQueue_PD(bAttacker);
	bAttack_PDD(bAttacker, bTarget);
	bDamage_PDD(bAttacker, bTarget);
	clearBAT_PDDA(bAttacker, bTarget);

	if (bIsDestroyed)
	{
		bIsDestroyed = false; //Reset this for the next battle
	}
}

void Damage::dmgProcessing_PB(bEntity& bAttacker, bEntity& bTarget)
{
	setupWQueue(bAttacker);
	bAttack_PB(bAttacker, bTarget);
	bDamage_PB(bAttacker, bTarget);
	clearBAT_PB(bAttacker, bTarget);

	if (bIsDestroyed)
	{
		bIsDestroyed = false; //Reset this for the next battle
	}
}

void Damage::bAttack(bEntity& bAttacker, bEntity& bTarget)
{
	//Zero out all damage
	vDamage = 0.0f;
	mDamage = 0.0f;
	fDamage = 0.0f;
	sDamage = 0.0f;
	dBCollateral = 0.0f;

	processWQueue(bAttacker, bTarget);

	//Check for secondary damage
	if (bTarget.entity->ship.cDamage.size() > 0)
	{
		getTDamage(bTarget);
	}
}

void Damage::bAttack_PS(bEntity& bAttacker, bEntity& bTarget)
{
	//Zero out all damage
	vDamage = 0.0f;
	mDamage = 0.0f;
	fDamage = 0.0f;
	sDamage = 0.0f;
	dBCollateral = 0.0f;

	processWQueue_PB(bAttacker, bTarget, false, true, false);
}

void Damage::bAttack_PDP(bEntity& bAttacker, bEntity& bTarget)
{
	//Zero out all damage
	vDamage = 0.0f;
	mDamage = 0.0f;
	fDamage = 0.0f;
	sDamage = 0.0f;
	dBCollateral = 0.0f;

	processWQueue_PB(bAttacker, bTarget, true, false, false);

	//Check for secondary damage
	if (bTarget.pDefense->cDamage.size() > 0)
	{
		getTDamage_PDP(bTarget);
	}
}

void Damage::bAttack_PDD(bEntity& bAttacker, bEntity& bTarget)
{
	//Zero out all damage
	vDamage = 0.0f;
	mDamage = 0.0f;
	fDamage = 0.0f;
	sDamage = 0.0f;
	dBCollateral = 0.0f;

	processWQueue_PB(bAttacker, bTarget, false, false, true);

	//Check for secondary damage
	if (bTarget.entity->ship.cDamage.size() > 0)
	{
		getTDamage(bTarget);
	}
}

void Damage::bAttack_PB(bEntity& bAttacker, bEntity& bTarget)
{
	//Zero out all damage
	vDamage = 0.0f;
	mDamage = 0.0f;
	fDamage = 0.0f;
	sDamage = 0.0f;
	dBCollateral = 0.0f;

	processWQueue_PB(bAttacker, bTarget, false, false, false);

	//Leave this here for possible turn based damage to planets through use of certain bomb types in future versions
	
	//Check for secondary damage
//	if (bTarget.entity->ship.cDamage.size() > 0)
	//{
//	getTDamage(bTarget);
	//}
}

void Damage::bDamage(bEntity& bAttacker, bEntity& bTarget)
{
	fDamage = vDamage;

	processDamage(bAttacker, bTarget, false);
}

void Damage::bDamage_PS(bEntity& bAttacker, bEntity& bTarget)
{
	fDamage = vDamage;

	processDamage_PS(bAttacker, bTarget);
}

void Damage::bDamage_PDP(bEntity& bAttacker, bEntity& bTarget) //Player is attacking defense
{
	fDamage = vDamage;

	processDamage_PDP(bAttacker, bTarget);
}

void Damage::bDamage_PDD(bEntity& bAttacker, bEntity& bTarget) //Defense is attacking player
{
	fDamage = vDamage;

	processDamage(bAttacker, bTarget, true);
}

void Damage::bDamage_PB(bEntity& bAttacker, bEntity& bTarget)
{
	fDamage = vDamage;

	processDamage_PB(bAttacker, bTarget);
}

void Damage::processWQueue(bEntity& bAttacker,bEntity& bTarget)
{
	/*mDistance = m_dmg.getDistance((float)bAttacker.entity->ship.getXPos(),(float)bTarget.entity->ship.getXPos(),(float)bAttacker.entity->ship.getYPos(),(float)bTarget.entity->ship.getYPos(),(float)bAttacker.entity->ship.getZPos(),(float)bTarget.entity->ship.getZPos());

	for (i = 0; i < weaponQueue.size(); i++)
	{
		if (weaponQueue.at(i).getHPWType() == "laser")
		{
			wDType = bAttacker.entity->ship.getLWDType(weaponQueue.at(i).getHPSlot()); //send slot of current laser weapon to ship for return of item name

			if ((mDistance >= bAttacker.entity->ship.lBanks.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWAOLow()) && (mDistance <= bAttacker.entity->ship.lBanks.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWAOHigh()))
			{
				//In future multiply by 1.5 to 2.5 random
				dLow = 2 * (bAttacker.entity->ship.lBanks.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRLow());
				dHigh = 2 * (bAttacker.entity->ship.lBanks.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRHigh());
			}

			else
			{
				dLow = bAttacker.entity->ship.lBanks.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRLow();
				dHigh = bAttacker.entity->ship.lBanks.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRHigh();
			}
		}

		else if (weaponQueue.at(i).getHPWType() == "missile")
		{
			wDType = bAttacker.entity->ship.getMWDType(weaponQueue.at(i).getHPSlot()); //send slot of current missile weapon to ship for return of item name

			if (mDistance < bAttacker.entity->ship.mTurrets.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWAHigh())
			{
				dLow = bAttacker.entity->ship.mTurrets.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRLow();
				dHigh = bAttacker.entity->ship.mTurrets.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRHigh();
			}

			else
			{
				dLow = 0;
				dHigh = 0;
			}
		}

		else if (weaponQueue.at(i).getHPWType() == "rail")
		{
			wDType = bAttacker.entity->ship.getRWDType(weaponQueue.at(i).getHPSlot()); //send slot of current rail gun weapon to ship for return of item name

			dLow = bAttacker.entity->ship.rMounts.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRLow();
			dHigh = bAttacker.entity->ship.rMounts.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRHigh();
		}

		else if (weaponQueue.at(i).getHPWType() == "heavy")
		{
			wDType = bAttacker.entity->ship.getHWDType(weaponQueue.at(i).getHPSlot()); //send slot of current heavy weapon to ship for return of item name

			dLow = bAttacker.entity->ship.hWBays.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRLow();
			dHigh = bAttacker.entity->ship.hWBays.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRHigh();
		}

		else if (weaponQueue.at(i).getHPWType() == "defense")
		{
			wDType = bAttacker.pDefense->getDDType();

			dLow = bAttacker.pDefense->getDDRLow();
			dHigh = bAttacker.pDefense->getDDRHigh();
		}

		if (wDType == "null") //If no secondary damage type
		{
			vDamage += Random(dLow, dHigh);
		}

		else if (wDType != "null")
		{
			sDamage = Random(dLow, dHigh); //Needs explaining; sDamage becomes the vehicle of vDamage in processSDamage, we take the damage done by the current weapon through to that function for processing and NOT vDamage because vD could have damage from other weapons
			vDamage += sDamage; //We do this here even though it is subtracted in pircing types below because some secondary damage types do not do direct damage

			processSDamage(bAttacker, bTarget);
		}

		if (bIsDestroyed)
		{
			break;
		}
	}*/
}

void Damage::processWQueue_PB(bEntity& bAttacker,bEntity& bTarget, bool pAPDef, bool pAPShd, bool pADef)
{
	//Everything related to distance is disabled for now, but will be re-enabled in the future after the movement system has been added to planets in terms of positioning on the battle field

	//mDistance = m_dmg.getDistance((float)bAttacker.entity->ship.getXPos(),(float)bTarget.entity->ship.getXPos(),(float)bAttacker.entity->ship.getYPos(),(float)bTarget.entity->ship.getYPos(),(float)bAttacker.entity->ship.getZPos(),(float)bTarget.entity->ship.getZPos()); //Calculate distance between attacker and defender

	for (i = 0; i < weaponQueue.size(); i++)
	{
		if (weaponQueue.at(i).getHPWType() == "laser")
		{
			if(pADef)
			{
				wDType = bAttacker.pDefense->getDType();

				dLow = bAttacker.pDefense->getDDRLow();
				dHigh = bAttacker.pDefense->getDDRHigh();
			}

			else
			{
				wDType = bAttacker.entity->ship.getLWDType(weaponQueue.at(i).getHPSlot()); //send slot of current laser weapon to ship for return of item name

				//if ((mDistance >= bAttacker.entity->ship.lBanks.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWAOLow()) && (mDistance <= bAttacker.entity->ship.lBanks.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWAOHigh()))
				//{
				//In future multiply by 1.5 to 2.5 random
				//dLow = 2 * (bAttacker.entity->ship.lBanks.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRLow());
				//dHigh = 2 * (bAttacker.entity->ship.lBanks.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRHigh());
				//}

				//else
				//{
				dLow = bAttacker.entity->ship.lBanks.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRLow();
				dHigh = bAttacker.entity->ship.lBanks.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRHigh();
				//}
			}
		}

		else if (weaponQueue.at(i).getHPWType() == "missile")
		{
			if(pADef)
			{
				wDType = bAttacker.pDefense->getDType();

				dLow = bAttacker.pDefense->getDDRLow();
				dHigh = bAttacker.pDefense->getDDRHigh();
			}

			else
			{
				wDType = bAttacker.entity->ship.getMWDType(weaponQueue.at(i).getHPSlot()); //send slot of current missile weapon to ship for return of item name

				//if (mDistance < bAttacker.entity->ship.mTurrets.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWAHigh())
				//{
				dLow = bAttacker.entity->ship.mTurrets.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRLow();
				dHigh = bAttacker.entity->ship.mTurrets.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRHigh();
				//}

				//else
				//{
				//	dLow = 0;
				//	dHigh = 0;
				//}
			}
		}

		else if (weaponQueue.at(i).getHPWType() == "bomb")
		{
			wDType = bAttacker.entity->ship.getBWDType(weaponQueue.at(i).getHPSlot()); //send slot of current bomb weapon to ship for return of item name

			dBCollateral = (bAttacker.entity->ship.bHolds.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWeight() * Random(7850, 16450)) / 2; //Calculate collateral damage caused by weight of bomb

			dLow = bAttacker.entity->ship.bHolds.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRLow();
			dHigh = bAttacker.entity->ship.bHolds.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRHigh();
		}

		else if (weaponQueue.at(i).getHPWType() == "rail")
		{
			if(pADef)
			{
				wDType = bAttacker.pDefense->getDType();

				dLow = bAttacker.pDefense->getDDRLow();
				dHigh = bAttacker.pDefense->getDDRHigh();
			}

			else
			{
				wDType = bAttacker.entity->ship.getRWDType(weaponQueue.at(i).getHPSlot()); //send slot of current rail gun weapon to ship for return of item name

				dLow = bAttacker.entity->ship.rMounts.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRLow();
				dHigh = bAttacker.entity->ship.rMounts.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRHigh();
			}
		}

		else if (weaponQueue.at(i).getHPWType() == "heavy")
		{
			if(pADef)
			{
				wDType = bAttacker.pDefense->getDType();

				dLow = bAttacker.pDefense->getDDRLow();
				dHigh = bAttacker.pDefense->getDDRHigh();
			}

			else
			{
				wDType = bAttacker.entity->ship.getHWDType(weaponQueue.at(i).getHPSlot()); //send slot of current heavy weapon to ship for return of item name

				dLow = bAttacker.entity->ship.hWBays.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRLow();
				dHigh = bAttacker.entity->ship.hWBays.at(weaponQueue.at(i).getHPSlot()).hpWeapon.getWDRHigh();
			}
		}

		if (wDType == "null") //If no secondary damage type
		{
			vDamage += Random(dLow, dHigh);

			if (dBCollateral != 0) //If there is collateral damage from a bomb weapon
			{
				vDamage += dBCollateral; //Add that damage to vDamage
			}
		}

		else if ((wDType != "null") && (!pAPDef) && (!pAPShd) && (!pADef))
		{
			sDamage = Random(dLow, dHigh); //Needs explaining; sDamage becomes the vehicle of vDamage in processSDamage, we take the damage done by the current weapon through to that function for processing and NOT vDamage because vD could have damage from other weapons
			vDamage += sDamage; //We do this here even though it is subtracted in pircing types below because some secondary damage types do not do direct damage

			if (dBCollateral != 0) //If bomb was used and there is collateral damage
			{
				vDamage += dBCollateral; //Then add it to vDamage
			}

			processSDamage(bAttacker, bTarget);
		}

		else if ((wDType != "null") && (pAPDef)) //If player is attack a defensive structure then we need to handle things differently in secondary damage/effects
		{
			sDamage = Random(dLow, dHigh); //Needs explaining; sDamage becomes the vehicle of vDamage in processSDamage, we take the damage done by the current weapon through to that function for processing and NOT vDamage because vD could have damage from other weapons
			vDamage += sDamage; //We do this here even though it is subtracted in pircing types below because some secondary damage types do not do direct damage
			processSDamage_PD(bAttacker, bTarget);
		}

		else if ((wDType != "null") && (pAPShd))
		{
			sDamage = Random(dLow, dHigh); //Needs explaining; sDamage becomes the vehicle of vDamage in processSDamage, we take the damage done by the current weapon through to that function for processing and NOT vDamage because vD could have damage from other weapons
			vDamage += sDamage; //We do this here even though it is subtracted in pircing types below because some secondary damage types do not do direct damage
			processSDamage_PS(bAttacker, bTarget);
		}

		else if ((wDType != "Null") && (pADef))
		{
			sDamage = Random(dLow, dHigh); //Needs explaining; sDamage becomes the vehicle of vDamage in processSDamage, we take the damage done by the current weapon through to that function for processing and NOT vDamage because vD could have damage from other weapons
			vDamage += sDamage; //We do this here even though it is subtracted in pircing types below because some secondary damage types do not do direct damage
			//processSDamage_PS(bAttacker, bTarget);
		}

		if (bIsDestroyed)
		{
			break;
		}
	}
}

//special damage is now direct damage; to deal with damage bonuses not being applied to improper interfaces
void Damage::processSDamage(bEntity& bAttacker, bEntity& bTarget)
{
	/*if (wDType == "piercing1")
	{
		vDamage -= sDamage; //Remove current damage from vDamage since it is directly applied from here; do not want to apply the same damage twice

		if (bTarget.entity->ship.getSShield() < sDamage) //If target shields less than sDamage
		{
			if (bTarget.entity->ship.getSShield() > 0)
			{
				mp_dmg.dDamage1SA(sDamage, sDamage - bTarget.entity->ship.getSShield(), bAttacker, bTarget, false);

				sDamage -= bTarget.entity->ship.getSShield(); //Remove spoints first then apply damage to shields
				bTarget.entity->ship.updateSShield(0.00f,"Set"); //Set shields to zero and continue processing damage
			}

			//Setup bonus damage outside armor statements
			mp_dmg.dBonus(sDamage, sDamage * AP1P, wDType, bAttacker);

			mDamage = sDamage * AP1P; //Get the modifier value for use later
			sDamage += mDamage; //Get modified damage first; could use mDamage to make this simpler but works for now

			if (bTarget.entity->ship.getSArmor() < sDamage) //If armor is less than sDamage
			{
				mp_dmg.dSDamageAH(sDamage, sDamage - bTarget.entity->ship.getSArmor(), wDType, bTarget);

				sDamage -= bTarget.entity->ship.getSArmor(); //Remove apoints first then apply damage to armor
				bTarget.entity->ship.updateSArmor(0.00f,"Set"); //Set armor to zero and continue processing damage

				//IMPORTANT: Take bonus off of remaining sDamage; AP1 does not affect hull
				sDamage -= mDamage;

				if (sDamage < 0) //If sDamage is less than zero, zero it out
				{
					sDamage = 0;
				}

				if (bTarget.entity->ship.getSHull() < sDamage) //If hull less than sDamage
				{
					mp_dmg.dSDamageH(sDamage, wDType, bTarget);

					sDamage = 0; //Zero out sDamage
					bTarget.entity->ship.updateSHull(0.00f,"Set"); //Set hull to zero
					bIsDestroyed = true; //And set the bIsDestroyed flag

					mp_dmg.mCScreen(true);
				}

				else if (bTarget.entity->ship.getSHull() > sDamage) //Else if hull greater than sDamage
				{
					bTarget.entity->applyHDamage(sDamage); //Take sDamage off of hull
					mp_dmg.dSDamageH(sDamage, wDType, bTarget);

					mp_dmg.mCScreen(true);
				}
			}

			else if ((bTarget.entity->ship.getSArmor() > sDamage) && (sDamage != 0)) //Else if armor greater than sDamage and sDamage is larger than zero
			{
				bTarget.entity->applyADamage(sDamage); //Take sDamage off of armor
				mp_dmg.dSDamageA(sDamage, wDType, bTarget);

				mp_dmg.mCScreen(true);
			}
		}

		else if ((bTarget.entity->ship.getSShield() > sDamage) && (sDamage != 0)) //Else if shield greater than sDamage and sDamage is larger than zero
		{
			bTarget.entity->applySDamage(sDamage); //Take sDamage off of shield
			mp_dmg.dDamage1S(sDamage, bAttacker, bTarget, false);

			mp_dmg.mCScreen(true);
		}
	}

	if (wDType == "piercing2")
	{
		vDamage -= sDamage; //Remove current damage from vDamage since it is directly applied from here; do not want to apply the same damage twice

		if (bTarget.entity->ship.getSShield() < sDamage) //If target has shields and sDamage is greater than the total spoints
		{
			if (bTarget.entity->ship.getSShield() > 0)
			{
				mp_dmg.dDamage1SA(sDamage, sDamage - bTarget.entity->ship.getSShield(), bAttacker, bTarget, false);

				sDamage -= bTarget.entity->ship.getSShield(); //Remove spoints first then apply damage to shields
				bTarget.entity->ship.updateSShield(0.00f,"Set"); //Set shields to zero and continue processing damage
			}

			if (bTarget.entity->ship.getSArmor() < sDamage) //If armor is greater than zero and is less than sDamage
			{
				if (bTarget.entity->ship.getSArmor() > 0)
				{
					mp_dmg.dSDamageAH(sDamage, sDamage - bTarget.entity->ship.getSArmor(), wDType, bTarget);

					sDamage -= bTarget.entity->ship.getSArmor(); //Remove apoints first then apply damage to armor
					bTarget.entity->ship.updateSArmor(0.00f,"Set"); //Set armor to zero and continue processing damage
				}

				if (sDamage < 0) //If sDamage is less than zero, zero it out
				{
					sDamage = 0;
				}

				//Setup bonus damage outside of hull statements
				mp_dmg.dBonus(sDamage, sDamage * AP2P, wDType, bAttacker);

				mDamage = sDamage * AP2P; //Get the modifier value for use later
				sDamage += mDamage; //Get modified damage first; could use mDamage to make this simpler but works for now

				if (bTarget.entity->ship.getSHull() < sDamage) //If hull greater than zero but less than sDamage
				{
					mp_dmg.dSDamageH(sDamage, wDType, bTarget);

					sDamage = 0; //Zero out sDamage
					bTarget.entity->ship.updateSHull(0.00f,"Set"); //Set hull to zero
					bIsDestroyed = true; //And set the bIsDestroyed flag

					mp_dmg.mCScreen(true);
				}

				else if (bTarget.entity->ship.getSHull() > sDamage) //Else if hull greater than sDamage and sDamage is larger than zero
				{
					bTarget.entity->applyHDamage(sDamage); //Take sDamage off of hull

					mp_dmg.dSDamageH(sDamage, wDType, bTarget);

					mp_dmg.mCScreen(true);
				}
			}

			else if (bTarget.entity->ship.getSArmor() > sDamage) //Else if armor greater than sDamage and sDamage is larger than zero
			{
				bTarget.entity->applyADamage(sDamage); //Take sDamage off of armor

				mp_dmg.dSDamageA(sDamage, wDType, bTarget);

				mp_dmg.mCScreen(true);
			}
		}

		else if (bTarget.entity->ship.getSShield() > sDamage) //Else if shield greater than sDamage and sDamage is larger than zero
		{
			bTarget.entity->applySDamage(sDamage); //Take sDamage off of shield

			mp_dmg.dDamage1S(sDamage, bAttacker, bTarget, false);

			mp_dmg.mCScreen(true);
		}
	}

	if (wDType == "piercing3")
	{
		vDamage -= sDamage; //Remove current damage from vDamage since it is directly applied from here; do not want to apply the same damage twice

		if (bTarget.entity->ship.getSShield() < sDamage) //If target has shields and sDamage is greater than the total spoints
		{
			if (bTarget.entity->ship.getSShield() > 0)
			{
				mp_dmg.dDamage1SA(sDamage, sDamage - bTarget.entity->ship.getSShield(), bAttacker, bTarget, false);

				sDamage -= bTarget.entity->ship.getSShield(); //Remove spoints first then apply damage to shields
				bTarget.entity->ship.updateSShield(0.00f,"Set"); //Set shields to zero and continue processing damage
			}

			//Setup bonus damage outside armor statements
			mDamage = sDamage * AP3PA; //Get the modifier value for use later

			mp_dmg.dBonus(sDamage, mDamage, wDType, bAttacker);

			sDamage += mDamage; //Get modified damage first; could use mDamage to make this simpler but works for now

			if (bTarget.entity->ship.getSArmor() < sDamage) //If armor is greater than zero and is less than sDamage
			{
				if (bTarget.entity->ship.getSArmor() > 0)
				{
					mp_dmg.dSDamageAH(sDamage, sDamage - bTarget.entity->ship.getSArmor(), wDType, bTarget);

					sDamage -= bTarget.entity->ship.getSArmor(); //Remove apoints first then apply damage to armor
					bTarget.entity->ship.updateSArmor(0.00f,"Set"); //Set armor to zero and continue processing damage
				}

				//IMPORTANT: Take bonus off of remaining sDamage; AP3A does not affect hull
				sDamage -= mDamage;

				if (sDamage < 0) //If sDamage is less than zero, zero it out
				{
					sDamage = 0;
				}

				//Setup bonus damage outside of hull statements

				mp_dmg.dBonus(sDamage, sDamage * AP3PH, wDType, bAttacker);

				mp_dmg.mCScreen(true);

				sDamage += sDamage * AP3PH; //Get modified damage first; could use mDamage to make this simpler but works for now

				if ((bTarget.entity->ship.getSHull() > 0) && (bTarget.entity->ship.getSHull() < sDamage)) //If hull greater than zero but less than sDamage
				{
					mp_dmg.dSDamageH(sDamage, wDType, bTarget);

					mp_dmg.mCScreen(true);

					sDamage = 0; //Zero out sDamage
					bTarget.entity->ship.updateSHull(0.00f,"Set"); //Set hull to zero
					bIsDestroyed = true; //And set the bIsDestroyed flag
				}

				else if ((bTarget.entity->ship.getSHull() > sDamage) && (sDamage != 0)) //Else if hull greater than sDamage and sDamage is larger than zero
				{
					bTarget.entity->applyHDamage(sDamage); //Take sDamage off of hull
					mp_dmg.dSDamageH(sDamage, wDType, bTarget);

					mp_dmg.mCScreen(true);
				}
			}

			else if ((bTarget.entity->ship.getSArmor() > sDamage) && (sDamage != 0)) //Else if armor greater than sDamage and sDamage is larger than zero
			{
				bTarget.entity->applyADamage(sDamage); //Take sDamage off of armor
				mp_dmg.dSDamageA(sDamage, wDType, bTarget);

				mp_dmg.mCScreen(true);
			}
		}

		else if ((bTarget.entity->ship.getSShield() > sDamage) && (sDamage != 0)) //Else if shield greater than sDamage and sDamage is larger than zero
		{
			bTarget.entity->applySDamage(sDamage); //Take sDamage off of shield
			mp_dmg.dDamage1S(sDamage, bAttacker, bTarget, false);

			mp_dmg.mCScreen(true);
		}
	}

	if (wDType == "napalm1")
	{
		bTarget.entity->ship.addTDamage((sDamage * NP1P), NP1T, "Napalm");
		mp_dmg.dSDInflicted(bAttacker, bTarget, wDType, NP1T);

		mp_dmg.mCScreen(true);
	}

	else if (wDType == "napalm2")
	{
		bTarget.entity->ship.addTDamage((sDamage * NP2P), NP2T, "Napalm");
		mp_dmg.dSDInflicted(bAttacker, bTarget, wDType, NP2T);

		mp_dmg.mCScreen(true);
	}

	else if (wDType == "napalm3")
	{
		bTarget.entity->ship.addTDamage((sDamage * NP3P), NP3T, "Napalm");
		mp_dmg.dSDInflicted(bAttacker, bTarget, wDType, NP3T);

		mp_dmg.mCScreen(true);
	}

	else if (wDType == "nanite1")
	{
		bTarget.entity->ship.addTDamage(NAN1P, NAN1T, "Nanite");
		mp_dmg.dSDInflicted(bAttacker, bTarget, wDType, NAN1T);

		mp_dmg.mCScreen(true);
	}

	else if (wDType == "nanite2")
	{
		bTarget.entity->ship.addTDamage(NAN2P, NAN2T, "Nanite");
		mp_dmg.dSDInflicted(bAttacker, bTarget, wDType, NAN2T);

		mp_dmg.mCScreen(true);
	}

	else if (wDType == "nanite3")
	{
		bTarget.entity->ship.addTDamage(NAN3P, NAN3T, "Nanite");
		mp_dmg.dSDInflicted(bAttacker, bTarget, wDType, NAN3T);

		mp_dmg.mCScreen(true);
	}

	else if (wDType == "emp1")
	{
		if ((bTarget.entity->ship.isDisabled()) && (bTarget.entity->ship.getSShield() == 0)) //If ship is not disabled already and shilds are 0
		{
			//TODO: make this a random chance based on type level

			bTarget.entity->ship.disableShip(EMP1DT);

			mp_dmg.dSDisabled(bTarget, EMP1DT);

			mp_dmg.mCScreen(true);
		}

		else if ((bTarget.entity->ship.getShieldStatus()) && (bTarget.entity->ship.getSShield() != 0)) //If shields are enabled and are greater then 0
		{
			if (sDamage > 0.0f)
			{
				mp_dmg.dBonus(sDamage, 0.50f * (EMP1P * sDamage), wDType, bAttacker);

				sDamage += (0.50f * (EMP1P * sDamage));

				mp_dmg.mCScreen(true);
			}

			else
			{
				mp_dmg.dBonus(sDamage, EMP1P * sDamage, wDType, bAttacker);

				sDamage += EMP1P * sDamage;

				mp_dmg.mCScreen(true);
			}
		}
	}

	else if (wDType == "emp2")
	{
		if ((bTarget.entity->ship.isDisabled()) && (bTarget.entity->ship.getSShield() == 0)) //If ship is not disabled already and shilds are 0
		{
			bTarget.entity->ship.disableShip(EMP2DT);

			mp_dmg.dSDisabled(bTarget, EMP2DT);

			mp_dmg.mCScreen(true);
		}

		else if ((bTarget.entity->ship.getShieldStatus()) && (bTarget.entity->ship.getSShield() != 0)) //If shields are enabled and are greater then 0
		{
			if (sDamage > 0.0f)
			{
				mp_dmg.dBonus(sDamage, 0.50f * (EMP2P * sDamage), wDType, bAttacker);

				sDamage += (0.50f * (EMP2P * sDamage));

				mp_dmg.mCScreen(true);
			}

			else
			{
				mp_dmg.dBonus(sDamage, EMP2P * sDamage, wDType, bAttacker);

				sDamage += EMP2P * sDamage;

				mp_dmg.mCScreen(true);
			}
		}
	}

	else if (wDType == "emp3")
	{
		if ((bTarget.entity->ship.isDisabled()) && (bTarget.entity->ship.getSShield() == 0)) //If ship is not disabled already and shilds are 0
		{
			bTarget.entity->ship.disableShip(EMP3DT);

			mp_dmg.dSDisabled(bTarget, EMP3DT);

			mp_dmg.mCScreen(true);
		}

		else if ((bTarget.entity->ship.getShieldStatus()) && (bTarget.entity->ship.getSShield() != 0)) //If shields are enabled and are greater then 0
		{
			if (sDamage > 0.0f)
			{
				mp_dmg.dBonus(sDamage, 0.50f * (EMP3P * sDamage), wDType, bAttacker);

				sDamage += (0.50f * (EMP3P * sDamage));

				mp_dmg.mCScreen(true);
			}

			else
			{
				mp_dmg.dBonus(sDamage, EMP3P * sDamage, wDType, bAttacker);

				sDamage += EMP3P * sDamage;

				mp_dmg.mCScreen(true);
			}
		}
	}*/
}

//special damage is now direct damage; to deal with damage bonuses not being applied to improper interfaces
void Damage::processSDamage_PS(bEntity& bAttacker, bEntity& bTarget)
{
	//if (wDType == "nanite1")
	//{
	//bTarget.entity->ship.addTDamage(NAN1P, NAN1T, "Nanite");
//	}
//
//	else if (wDType == "nanite2")
//	{
//	bTarget.entity->ship.addTDamage(NAN2P, NAN2T, "Nanite");
//	}

//	else if (wDType == "nanite3")
//	{
//	bTarget.entity->ship.addTDamage(NAN3P, NAN3T, "Nanite");
//	}

//	else if (wDType == "emp1")
//	{
//	if ((bTarget.entity->ship.isDisabled()) && (bTarget.entity->ship.getSShield() == 0)) //If ship is not disabled already and shilds are 0
//	{
//	bTarget.entity->ship.disableShip(EMP1DT);
//	}
//
//	else if ((bTarget.entity->ship.getShieldStatus()) && (bTarget.entity->ship.getSShield() != 0)) //If shields are enabled and are greater then 0
//	{
//	if (sDamage > 0.0f)
//	{
//	sDamage += (0.50f * (EMP1P * sDamage));
//	}

//	else
//	{
//	sDamage += EMP1P * sDamage;
//	}
//	}
//	}

//	else if (wDType == "emp2")
//	{
//	if ((bTarget.entity->ship.isDisabled()) && (bTarget.entity->ship.getSShield() == 0)) //If ship is not disabled already and shilds are 0
//	{
//	bTarget.entity->ship.disableShip(EMP2DT);
//	}

//	else if ((bTarget.entity->ship.getShieldStatus()) && (bTarget.entity->ship.getSShield() != 0)) //If shields are enabled and are greater then 0
//	{
//	if (sDamage > 0.0f)
//	{
//	sDamage += (0.50f * (EMP2P * sDamage));
//	}

//	else
//	{
//	sDamage += EMP2P * sDamage;
//	}
//	}
//	}

	//else if (wDType == "emp3")
//	{
//	if ((bTarget.entity->ship.isDisabled()) && (bTarget.entity->ship.getSShield() == 0)) //If ship is not disabled already and shilds are 0
//	{
//	bTarget.entity->ship.disableShip(EMP3DT);
	//}

//	else if ((bTarget.entity->ship.getShieldStatus()) && (bTarget.entity->ship.getSShield() != 0)) //If shields are enabled and are greater then 0
//	{
//	if (sDamage > 0.0f)
//	{
//	sDamage += (0.50f * (EMP3P * sDamage));
	//}

	//else
//	{
//	sDamage += EMP3P * sDamage;
	//}
//	}
//	}
}

void Damage::processSDamage_PD(bEntity& bAttacker, bEntity& bTarget)
{
	//if (wDType == "piercing1")
	//{
	//vDamage -= sDamage; //Remove current damage from vDamage since it is directly applied from here; do not want to apply the same damage twice

	//Setup bonus damage outside armor statements
//	mDamage = sDamage * AP1P; //Get the modifier value for use later
//	sDamage += mDamage; //Get modified damage first; could use mDamage to make this simpler but works for now

	//if (bTarget.pDefense->getSPoints() <= sDamage) //If target structural integrity less than sDamage
	//{
	//sDamage -= bTarget.pDefense->getSPoints(); //Remove spoints first then apply damage to shields
	//bTarget.pDefense->updateSPoints(0.00f,"set"); //Set shields to zero and continue processing damage
	//}

	//else if (bTarget.pDefense->getSPoints() > sDamage)
	//{
//	bTarget.pDefense->updateSPoints(sDamage,"sub"); //Set shields to zero and continue processing damage
//	}
//	}

//	if (wDType == "piercing2")
//	{
//	vDamage -= sDamage; //Remove current damage from vDamage since it is directly applied from here; do not want to apply the same damage twice

	//Setup bonus damage outside armor statements
//	mDamage = sDamage * AP3PH; //Get the modifier value for use later
//	sDamage += mDamage; //Get modified damage first; could use mDamage to make this simpler but works for now

//	if (bTarget.pDefense->getSPoints() <= sDamage) //If target structural integrity less than sDamage
//	{
//	sDamage -= bTarget.pDefense->getSPoints(); //Remove spoints first then apply damage to shields
//	bTarget.pDefense->updateSPoints(0.00f,"set"); //Set shields to zero and continue processing damage
//	}

//	else if (bTarget.pDefense->getSPoints() > sDamage)
//	{
//	bTarget.pDefense->updateSPoints(sDamage,"sub"); //Set shields to zero and continue processing damage
//	}
//	}
//
//	if (wDType == "piercing3")
//	{
//	vDamage -= sDamage; //Remove current damage from vDamage since it is directly applied from here; do not want to apply the same damage twice

	//Setup bonus damage outside armor statements
//	mDamage = sDamage * AP1P; //Get the modifier value for use later
//	sDamage += mDamage; //Get modified damage first; could use mDamage to make this simpler but works for now

//	if (bTarget.pDefense->getSPoints() <= sDamage) //If target structural integrity less than sDamage
//	{
//	sDamage -= bTarget.pDefense->getSPoints(); //Remove spoints first then apply damage to shields
//	bTarget.pDefense->updateSPoints(0.00f,"set"); //Set shields to zero and continue processing damage
//	}

//	else if (bTarget.pDefense->getSPoints() > sDamage)
//	{
//	bTarget.pDefense->updateSPoints(sDamage,"sub"); //Set shields to zero and continue processing damage
//	}
//	}

//	if (wDType == "napalm1")
//	{
//	bTarget.pDefense->addTDamage((sDamage * NP1P), NP1T, "Napalm");
//	}

//	else if (wDType == "napalm2")
//	{
//	bTarget.pDefense->addTDamage((sDamage * NP2P), NP2T, "Napalm");
//	}

//	else if (wDType == "napalm3")
//	{
//	bTarget.pDefense->addTDamage((sDamage * NP3P), NP3T, "Napalm");
//	}

//	else if (wDType == "nanite1")
//	{
	//bTarget.pDefense->addTDamage(NAN1P, NAN1T, "Nanite");
	//}

//	else if (wDType == "nanite2")
//	{
//	bTarget.pDefense->addTDamage(NAN2P, NAN2T, "Nanite");
//	}

//	else if (wDType == "nanite3")
//	{
//	bTarget.pDefense->addTDamage(NAN3P, NAN3T, "Nanite");
//	}	
}

void Damage::processDamage(bEntity& bAttacker, bEntity& bTarget, bool defense)
{
	if (bTarget.entity->ship.getSShield() >= fDamage) //If shields can absorb all damage; note need shield bypass check later on
	{
		bTarget.entity->applySDamage(fDamage);

		mp_dmg.dDamage1S(fDamage, bAttacker, bTarget, defense); //Print out damage was taken
		mp_dmg.mCScreen(true);
	}

	else if (bTarget.entity->ship.getSShield() < fDamage) //If shields cannot abosrb all damage
	{
		if (bTarget.entity->ship.getSShield() != 0)
		{
			mp_dmg.dDamage1SA(fDamage, fDamage - bTarget.entity->ship.getSShield(), bAttacker, bTarget, defense); //Have to do this before damage is taken because of how fDamage is processed below
		}

		fDamage -= bTarget.entity->ship.getSShield();
		bTarget.entity->applySDamage(bTarget.entity->ship.getSShield());

		if (bTarget.entity->ship.getSArmor() >= fDamage) //If armor can absorb all damage
		{
			bTarget.entity->applyADamage(fDamage);

			mp_dmg.dDamage1A(fDamage, bAttacker, bTarget, defense);
			mp_dmg.mCScreen(true);
		}

		else if (bTarget.entity->ship.getSArmor() < fDamage) //If armor cannot absorb all damage
		{
			if (bTarget.entity->ship.getSArmor() != 0)
			{
				mp_dmg.dDamage1AH(fDamage, fDamage - bTarget.entity->ship.getSArmor(), bAttacker, bTarget, defense);
			}

			fDamage -= bTarget.entity->ship.getSArmor();
			bTarget.entity->applyADamage(bTarget.entity->ship.getSArmor());

			if (bTarget.entity->ship.getSHull() >= fDamage) //If hull can absorb all damage
			{
				bTarget.entity->applyHDamage(fDamage);

				mp_dmg.dDamage1H(fDamage, bAttacker, bTarget, defense);
				mp_dmg.mCScreen(true);
			}

			else if (bTarget.entity->ship.getSHull() < fDamage) //If hull cannot absorb all damage
			{
				bTarget.entity->applyHDamage(bTarget.entity->ship.getSHull());

				mp_dmg.dDamage1H(fDamage, bAttacker, bTarget, defense);
				mp_dmg.dDamage1H_K(bAttacker, bTarget, defense);

				mp_dmg.mCScreen(true);

				bIsDestroyed = true;
			}
		}
	}
}

void Damage::processDamage_PS(bEntity& bAttacker, bEntity& bTarget)
{
	if (bTarget.pShield->getSP() <= fDamage) //If shields cannot absorb all damage, set to 0 and disable for a time
	{
		bTarget.pShield->updateSP(0.0f, "set");

		mp_dmg.dDamage2S(fDamage, bAttacker, bTarget, tempPlanet);

		bTarget.pShield->dShield(2); //Disable shield for 2 turns
		bTarget.pShield->updateDTGrace(true); //So that we actually get two turns of disabled shield instead of one

		mp_dmg.dPSDisabled(tempPlanet, bTarget, bTarget.pShield->getSDTimer());

		mp_dmg.mCScreen(true);
	}

	else
	{
		bTarget.pShield->updateSP(fDamage, "sub"); //Else subtract fDamage

		mp_dmg.dDamage2S(fDamage, bAttacker, bTarget, tempPlanet);

		mp_dmg.mCScreen(true);
	}
}

void Damage::processDamage_PDP(bEntity& bAttacker, bEntity& bTarget)
{
	if (bTarget.pDefense->getSPoints() <= fDamage) //If defenses cannot absorb all damage
	{
		bTarget.pDefense->updateSPoints(0.0, "set");

		mp_dmg.dDamage2D(fDamage, bAttacker, bTarget, tempPlanet);
		mp_dmg.dDamage2D_K(bAttacker, bTarget, tempPlanet);

		mp_dmg.mCScreen(true);
	}

	else
	{
		bTarget.pDefense->updateSPoints(fDamage, "sub"); //Else subtract fDamage
		mp_dmg.dDamage2D(fDamage, bAttacker, bTarget, tempPlanet);

		mp_dmg.mCScreen(true);
	}
}

void Damage::processDamage_PB(bEntity& bAttacker, bEntity& bTarget)
{
	if (bTarget.bPlanet->getPop() <= fDamage) //If attack kills entire population then
	{
		bTarget.bPlanet->updatePop(0.0, "set"); //Set population to 0
		mp_dmg.dDamage2P(fDamage, bAttacker, bTarget);
		mp_dmg.dDamage2P_K(bAttacker, bTarget);

		mp_dmg.mCScreen(true);
	}

	else
	{
		bTarget.bPlanet->updatePop(fDamage, "sub"); //Else subtract casualties from planet population
		mp_dmg.dDamage2P(fDamage, bAttacker, bTarget);

		mp_dmg.mCScreen(true);
	}
}

void Damage::getTDamage(bEntity& bTarget)
{
	if (bTarget.entity->ship.cDamage.size() != 0)
	{
		for (i = 0; i < bTarget.entity->ship.cDamage.size(); i++)
		{
			if (bTarget.entity->ship.cDamage.at(i).getTurns() != 0)
			{
				processTDamage(bTarget,i);
			}
		}
	}

	bTarget.entity->ship.checkTDamage(); //After each turn check for any zero turn damages and remove them
}

void Damage::getTDamage_PDP(bEntity& bTarget)
{
	if (bTarget.pDefense->cDamage.size() != 0)
	{
		for (i = 0; i < bTarget.pDefense->cDamage.size(); i++)
		{
			if (bTarget.pDefense->cDamage.at(i).getTurns() != 0)
			{
				processTDamage_PDP(bTarget,i);
			}
		}
	}

	bTarget.pDefense->checkTDamage(); //After each turn check for any zero turn damages and remove them
}

void Damage::processTDamage(bEntity& bTarget, int elm)
{
	//Store damage and type values for use in a second
	tDamage = bTarget.entity->ship.cDamage.at(elm).getDamage();
	tDType = bTarget.entity->ship.cDamage.at(elm).getType();

	if (tDType == "Napalm") //If damage type is napalm
	{
		if (bTarget.entity->ship.cDamage.at(elm).getATo() == "Armor") //If damage was applied to armor
		{
			if (tDamage < bTarget.entity->ship.getSArmor()) //If armor is currently above zero and damage less than total apoints
			{
				bTarget.entity->ship.updateSArmor(tDamage, "sub"); //Subtract damage from armor
				mp_dmg.dSDamageA(tDamage, tDType, bTarget);

				mp_dmg.mCScreen(true);
			}

			else if ((bTarget.entity->ship.getSArmor() > 0) && (tDamage > bTarget.entity->ship.getSArmor())) //Else if armor is currently not zero but damage is greater than total apoints
			{
				mp_dmg.dSDamageAH(tDamage, tDamage - bTarget.entity->ship.getSArmor(), tDType, bTarget);

				//Take apoints from damage first
				tDamage -= bTarget.entity->ship.getSArmor();

				//Set armor to zero
				bTarget.entity->ship.updateSArmor(0.0f,"set");

				//Set appliedTo to hull
				bTarget.entity->ship.cDamage.at(elm).setATo("Hull"); //Napalm has eaten through armor and is now damaging hull

				if (bTarget.entity->ship.getSHull() < tDamage)
				{
					bTarget.entity->ship.updateSHull(0.0f, "set");
					bIsDestroyed = true;
				}

				else
				{
					bTarget.entity->ship.updateSHull(tDamage, "sub");
				}
			}

			else if (bTarget.entity->ship.getSArmor() == 0)
			{
				//Set appliedTo to hull
				bTarget.entity->ship.cDamage.at(elm).setATo("Hull"); //Napalm has eaten through armor and is now damaging hull

				if (bTarget.entity->ship.getSHull() < tDamage)
				{
					bTarget.entity->ship.updateSHull(0.0f, "set");

					mp_dmg.dSDamageH(tDamage, tDType, bTarget);

					mp_dmg.mCScreen(true);

					bIsDestroyed = true;
				}

				else
				{
					bTarget.entity->ship.updateSHull(tDamage, "sub");

					mp_dmg.dSDamageH(tDamage, tDType, bTarget);

					mp_dmg.mCScreen(true);
				}
			}
		}

		if (bTarget.entity->ship.cDamage.at(elm).getATo() == "Hull") //If damage was applied to armor
		{
			if ((bTarget.entity->ship.getSHull()) > 0 && (tDamage < bTarget.entity->ship.getSHull())) //If hull is currently above zero and damage less than total apoints
			{
				bTarget.entity->ship.updateSHull(tDamage, "sub"); //Subtract damage from armor

				mp_dmg.dSDamageH(tDamage, tDType, bTarget);

				mp_dmg.mCScreen(true);
			}

			else if ((bTarget.entity->ship.getSHull() > 0) && (tDamage > bTarget.entity->ship.getSHull())) //Else if hull is currently not zero but damage is greater than total apoints
			{
				bTarget.entity->ship.updateSHull(0.0f,"set");

				mp_dmg.dSDamageH(tDamage, tDType, bTarget);

				mp_dmg.mCScreen(true);

				bIsDestroyed = true;
			}
		}
	}

	else if (tDType == "Nanite")
	{
		if (bTarget.entity->ship.getSShield() > 0)
		{
			mp_dmg.dSDamageS(bTarget.entity->ship.getSShield()*tDamage, tDType, bTarget);
			bTarget.entity->applySDamage(bTarget.entity->ship.getSShield()*tDamage);

			mp_dmg.mCScreen(true);

		}

		if (bTarget.entity->ship.getSArmor() > 0)
		{
			mp_dmg.dSDamageA(bTarget.entity->ship.getSArmor()*tDamage, tDType, bTarget);
			bTarget.entity->applyADamage(bTarget.entity->ship.getSArmor()*tDamage);

			mp_dmg.mCScreen(true);
		}

		if (bTarget.entity->ship.getSHull() > 0)
		{
			mp_dmg.dSDamageH(bTarget.entity->ship.getSHull()*tDamage, tDType, bTarget);
			bTarget.entity->applyHDamage(bTarget.entity->ship.getSHull()*tDamage);

			mp_dmg.mCScreen(true);
		}
	}
}

void Damage::processTDamage_PDP(bEntity& bTarget, int elm)
{
	
	//Store damage and type values for use in a second
//	tDamage = bTarget.pDefense->cDamage.at(elm).getDamage();
//	tDType = bTarget.pDefense->cDamage.at(elm).getType();

//	if (tDType == "Napalm") //If damage type is napalm
//	{
//	if (tDamage < bTarget.pDefense->getSPoints()) //If armor is currently above zero and damage less than total apoints
	//{
	//bTarget.pDefense->updateSPoints(tDamage, "sub"); //Subtract damage from armor
	//}

//	else  //Else if tdamage is greater than sp
	//{
//	bTarget.pDefense->updateSPoints(0.0f, "set");
//	}

//	}

//	else if (tDType == "Nanite")
//	{
//	if (bTarget.pDefense->getSPoints() > 0)
//	{
//	bTarget.pDefense->updateSPoints(bTarget.pDefense->getSPoints()*tDamage, "sub");
//	}
//	}
	
}

void Damage::setupWQueue(bEntity& bAttacker)
{
	cleanWQueue(); //Clear vector

	//Get currently selected vector id from attacker
	bCSpread = bAttacker.entity->ship.getCSVector();

	if (aType == "allout")
	{
		for (i = 0; i < bAttacker.entity->ship.getSSize(bCSpread); i++)
		{
			weaponQueue.push_back(bAttacker.entity->ship.getSHPoint(i));
		}
	}

	else if (aType == "spread")
	{
		for (i = 0; i < bAttacker.entity->ship.getSSize(bCSpread); i++)
		{
			weaponQueue.push_back(bAttacker.entity->ship.getSHPoint(i));
		}
	}

	else if (aType == "wsystem")
	{
		for (i = 0; i < bAttacker.entity->ship.getSSize(bCSpread); i++)
		{
			weaponQueue.push_back(bAttacker.entity->ship.getSHPoint(i));
		}
	}

	else if (aType == "single")
	{
		weaponQueue.push_back(bAttacker.entity->ship.getWVHPoint(0));
	}
}

void Damage::setupWQueue_PD(bEntity& bAttacker)
{
	cleanWQueue();

	weaponQueue.push_back(hardPoint(0,"defense")); //This is for visual purposes only.  There are no hardpoints to set so we create a virtual one with the type of defense so that it can be picked up in processWQueue.
}

void Damage::cleanWQueue()
{
	weaponQueue.clear();
}

void Damage::setupBAT(Entity* entity, Entity* entity2)
{
	bEntity bAttacker = bEntity(entity);
	bEntity bTarget = bEntity(entity2);

	dmgProcessing(bAttacker, bTarget);
}

void Damage::clearBAT(bEntity& bAttacker, bEntity& bTarget)
{
	bAttacker.clearE();
	bTarget.clearE();
}

void Damage::setupBAT_PS(Entity* entity, Shield* pShield, Planet* bPlanet)
{
	bEntity bAttacker = bEntity(entity);
	bEntity bTarget = bEntity(pShield);

	tempPlanet = bPlanet; //Store the planet here for use later on in the code

	dmgProcessing_PS(bAttacker, bTarget);
}

void Damage::clearBAT_PS(bEntity& bAttacker, bEntity& bTarget)
{
	bAttacker.clearE();
	tempPlanet = 0; //Clear the tempPlanet pointer
}

void Damage::setupBAT_PDPA(Entity* entity, Defense* pDefense, Planet* bPlanet)
{
	bEntity bAttacker = bEntity(entity);
	bEntity bTarget = bEntity(pDefense);

	tempPlanet = bPlanet; //Store the planet here for use later on in the code

	dmgProcessing_PDP(bAttacker, bTarget);
}

void Damage::clearBAT_PDPA(bEntity& bAttacker, bEntity& bTarget)
{
	bAttacker.clearE();
	tempPlanet = 0; //Clear the tempPlanet pointer
}

void Damage::setupBAT_PDDA(Defense* pDefense, Entity* entity)
{
	bEntity bAttacker = bEntity(pDefense);
	bEntity bTarget = bEntity(entity);

	//tempPlanet = bPlanet; //Store the planet here for use later on in the code

	dmgProcessing_PDD(bAttacker, bTarget);
}

void Damage::clearBAT_PDDA(bEntity& bAttacker, bEntity& bTarget)
{
	bTarget.clearE();
	//tempPlanet = 0; //Clear the tempPlanet pointer
}

void Damage::setupBAT_PB(Entity* entity, Planet* bPlanet)
{
	bEntity bAttacker = bEntity(entity);
	bEntity bTarget = bEntity(bPlanet);

	tempPlanet = bPlanet; //Store the planet here for use later on in the code

	dmgProcessing_PB(bAttacker, bTarget);
}

void Damage::clearBAT_PB(bEntity& bAttacker, bEntity& bTarget)
{
	bAttacker.clearE();
	bTarget.clearP();
	tempPlanet = 0; //Clear the tempPlanet pointer
}

void Damage::setupAType(bool allout, bool spread, bool wsystem, bool single)
{
	if (allout)
	{
		aType = "allout";
	}

	else if (spread)
	{
		aType = "spread";
	}

	else if (wsystem)
	{
		aType = "wsystem";
	}

	else if (single)
	{
		aType = "single";
	}
}

/*Damage Types:

piercing1: Armor Piercing, does not affect hull
piercing2: Hull Piercing, does not affect armor
piercing3: Armor and Hull piercing
napalm1: low level napalm damage, lasts two turns
napalm2: medium level napalm damage, lasts four turns
napalm3: high level napalm damage, lasts six turns
destructor: higher damage to defenses
nanite1: low level nanite damage, does 5% of HP damage for two turns
nanite2: medium level nanite damage, does 8% of HP damage for four turns
nanite3: high level nanite damage, does 15% of HP damage for eight turns
doomsday1: large scale damage, kills off 25% of population instantly along with 15% of all infrastructure and 10% of biomass
doomsday2: larger scale damage, kills off 40% of population instantly along with 25% of all infrastructure and 18% of biomass
stealth: invisible to point defenses, point defenses will still have a 2% chance to destroy a missile volley per point defense up to 10%.
frigonly: only damages frigate class ships, no damage to higher classes
null: no special damage
emp1: low level shield damage, if shields down will cripple non-emp protected target for one turn
emp2: medium level shield damage, if shields down will cripple non-emp protected target for three turns
emp3: high level shield damage, if shields down will cripple non-emp protected target for seven turns
virus1: scrambles targeting systems of enemy ship, target will not attack for two turns and loses shields
virus2: scrambles targeting systems and crashes computer, target will not attack for five turns and loses shields
virus3: scrambles targeting systems, crashes computer, and disables life support and loses shields (RTS/RPG).  Crews of ships lower then crusier class can be killed in two turns and ship can be salvaged whole (twice the resources; RTS only)
virus4: crashes all systems and injects core breach code into engines and loses shields_dmg.  35% chance that the ship will self destruct over 4 turns, after which systems reboot and core breach stopped.  10% chance per 20 tech crewmen or 5 tech module on board to avert code breach. (RTS only)
massaccel: Mass Accelerator damage bypasses shield and armor and deals direct hull damage.

*/
