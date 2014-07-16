#include "globalvars.h"
#include "debug.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "boost/program_options.hpp"
#include "boost/algorithm/string.hpp"
#include "boost/algorithm/string/split.hpp"

using std::string;
using std::endl;
using std::cout;
using std::ifstream;
using std::to_string;
using std::vector;
using boost::split;

namespace pOps = boost::program_options;

Debug d_gv;


namespace gVars
{
	//Get the config data from the ini file
	void getCData()
	{
		pOps::options_description desc("Settings");
		desc.add_options()
			//Item ID Ranges

			//Ship IDs By Class
			("itemid.ssrlow",pOps::value<int>(&iIRSShips.iLow),"Start Ship ID Range; Low")
			("itemid.ssrhigh",pOps::value<int>(&iIRSShips.iHigh),"Start Ship ID Range; High")
			("itemid.scflow",pOps::value<int>(&iIRSCFrig.iLow),"Frigate ID Range; Low")
			("itemid.scfhigh",pOps::value<int>(&iIRSCFrig.iHigh),"Frigate ID Range; High")
			("itemid.scdlow",pOps::value<int>(&iIRSCDest.iLow),"Destoyer ID Range; Low")
			("itemid.scdhigh",pOps::value<int>(&iIRSCDest.iHigh),"Destoyer ID Range; High")
			("itemid.scclow",pOps::value<int>(&iIRSCCrui.iLow),"Cruiser ID Range; Low")
			("itemid.scchigh",pOps::value<int>(&iIRSCCrui.iHigh),"Cruiser ID Range; High")
			("itemid.scbclow",pOps::value<int>(&iIRSCBCru.iLow),"Battle Cruiser ID Range; Low")
			("itemid.scbchigh",pOps::value<int>(&iIRSCBCru.iHigh),"Battle Cruiser ID Range; High")
			("itemid.scblow",pOps::value<int>(&iIRSCBShi.iLow),"Battleship ID Range; Low")
			("itemid.scbhigh",pOps::value<int>(&iIRSCBShi.iHigh),"Battleship ID Range; High")
			("itemid.sccslow",pOps::value<int>(&iIRSCCShi.iLow),"Commandship ID Range; Low")
			("itemid.sccshigh",pOps::value<int>(&iIRSCCShi.iHigh),"Commandship ID Range; High")
			("itemid.scmlow",pOps::value<int>(&iIRSCMShi.iLow),"Mothership ID Range; Low")
			("itemid.scmhigh",pOps::value<int>(&iIRSCMShi.iHigh),"Mothership ID Range; High")
			("itemid.sctlow",pOps::value<int>(&iIRSCTita.iLow),"Titan ID Range; Low")
			("itemid.scthigh",pOps::value<int>(&iIRSCTita.iHigh),"Titan ID Range; High")
			("itemid.scmblow",pOps::value<int>(&iIRSCMBar.iLow),"Mining Barge ID Range; Low")
			("itemid.scmbhigh",pOps::value<int>(&iIRSCMBar.iHigh),"Mining Barge ID Range; High")

			//Weapon IDs By Class
			("itemid.lwflow",pOps::value<int>(&iIRLCFrig.iLow),"Frigate Laser ID Range; Low")
			("itemid.lwfhigh",pOps::value<int>(&iIRLCFrig.iHigh),"Frigate Laser ID Range; High")
			("itemid.mwflow",pOps::value<int>(&iIRMCFrig.iLow),"Frigate Missile ID Range; Low")
			("itemid.mwfhigh",pOps::value<int>(&iIRMCFrig.iHigh),"Frigate Missile ID Range; High")
			("itemid.bwflow",pOps::value<int>(&iIRBCFrig.iLow),"Frigate Bomb ID Range; Low")
			("itemid.bwfhigh",pOps::value<int>(&iIRBCFrig.iHigh),"Frigate Bomb ID Range; High")
			("itemid.rwflow",pOps::value<int>(&iIRRCFrig.iLow),"Frigate Rail ID Range; Low")
			("itemid.rwfhigh",pOps::value<int>(&iIRRCFrig.iHigh),"Frigate Rail ID Range; High")
			("itemid.hwflow",pOps::value<int>(&iIRHCFrig.iLow),"Frigate Heavy ID Range; Low")
			("itemid.hwfhigh",pOps::value<int>(&iIRHCFrig.iHigh),"Frigate Heavy ID Range; High")			
			("itemid.lwdlow",pOps::value<int>(&iIRLCDest.iLow),"Destroyer Laser ID Range; Low")
			("itemid.lwdhigh",pOps::value<int>(&iIRLCDest.iHigh),"Destroyer Laser ID Range; High")
			("itemid.mwdlow",pOps::value<int>(&iIRMCDest.iLow),"Destroyer Missile ID Range; Low")
			("itemid.mwdhigh",pOps::value<int>(&iIRMCDest.iHigh),"Destroyer Missile ID Range; High")
			("itemid.bwdlow",pOps::value<int>(&iIRBCDest.iLow),"Destroyer Bomb ID Range; Low")
			("itemid.bwdhigh",pOps::value<int>(&iIRBCDest.iHigh),"Destroyer Bomb ID Range; High")
			("itemid.rwdlow",pOps::value<int>(&iIRRCDest.iLow),"Destroyer Rail ID Range; Low")
			("itemid.rwdhigh",pOps::value<int>(&iIRRCDest.iHigh),"Destroyer Rail ID Range; High")
			("itemid.hwdlow",pOps::value<int>(&iIRHCDest.iLow),"Destroyer Heavy ID Range; Low")
			("itemid.hwdhigh",pOps::value<int>(&iIRHCDest.iHigh),"Destroyer Heavy ID Range; High")
			("itemid.lwclow",pOps::value<int>(&iIRLCCrui.iLow),"Cruiser Laser ID Range; Low")
			("itemid.lwchigh",pOps::value<int>(&iIRLCCrui.iHigh),"Cruiser Laser ID Range; High")
			("itemid.mwclow",pOps::value<int>(&iIRMCCrui.iLow),"Cruiser Missile ID Range; Low")
			("itemid.mwchigh",pOps::value<int>(&iIRMCCrui.iHigh),"Cruiser Missile ID Range; High")
			("itemid.bwclow",pOps::value<int>(&iIRBCCrui.iLow),"Cruiser Bomb ID Range; Low")
			("itemid.bwchigh",pOps::value<int>(&iIRBCCrui.iHigh),"Cruiser Bomb ID Range; High")
			("itemid.rwclow",pOps::value<int>(&iIRRCCrui.iLow),"Cruiser Rail ID Range; Low")
			("itemid.rwchigh",pOps::value<int>(&iIRRCCrui.iHigh),"Cruiser Rail ID Range; High")
			("itemid.hwclow",pOps::value<int>(&iIRHCCrui.iLow),"Cruiser Heavy ID Range; Low")
			("itemid.hwchigh",pOps::value<int>(&iIRHCCrui.iHigh),"Cruiser Heavy ID Range; High")
			("itemid.lwbclow",pOps::value<int>(&iIRLCBCru.iLow),"Battle Cruiser Laser ID Range; Low")
			("itemid.lwbchigh",pOps::value<int>(&iIRLCBCru.iHigh),"Battle Cruiser Laser ID Range; High")
			("itemid.mwbclow",pOps::value<int>(&iIRMCBCru.iLow),"Battle Cruiser Missile ID Range; Low")
			("itemid.mwbchigh",pOps::value<int>(&iIRMCBCru.iHigh),"Battle Cruiser Missile ID Range; High")
			("itemid.bwbclow",pOps::value<int>(&iIRBCBCru.iLow),"Battle Cruiser Bomb ID Range; Low")
			("itemid.bwbchigh",pOps::value<int>(&iIRBCBCru.iHigh),"Battle Cruiser Bomb ID Range; High")
			("itemid.rwbclow",pOps::value<int>(&iIRRCBCru.iLow),"Battle Cruiser Rail ID Range; Low")
			("itemid.rwbchigh",pOps::value<int>(&iIRRCBCru.iHigh),"Battle Cruiser Rail ID Range; High")
			("itemid.hwbclow",pOps::value<int>(&iIRHCBCru.iLow),"Battle Cruiser Heavy ID Range; Low")
			("itemid.hwbchigh",pOps::value<int>(&iIRHCBCru.iHigh),"Battle Cruiser Heavy ID Range; High")
			("itemid.lwblow",pOps::value<int>(&iIRLCBShi.iLow),"Battleship Laser ID Range; Low")
			("itemid.lwbhigh",pOps::value<int>(&iIRLCBShi.iHigh),"Battleship Laser ID Range; High")
			("itemid.mwblow",pOps::value<int>(&iIRMCBShi.iLow),"Battleship Missile ID Range; Low")
			("itemid.mwbhigh",pOps::value<int>(&iIRMCBShi.iHigh),"Battleship Missile ID Range; High")
			("itemid.bwblow",pOps::value<int>(&iIRBCBShi.iLow),"Battleship Bomb ID Range; Low")
			("itemid.bwbhigh",pOps::value<int>(&iIRBCBShi.iHigh),"Battleship Bomb ID Range; High")
			("itemid.rwblow",pOps::value<int>(&iIRRCBShi.iLow),"Battleship Rail ID Range; Low")
			("itemid.rwbhigh",pOps::value<int>(&iIRRCBShi.iHigh),"Battleship Rail ID Range; High")
			("itemid.hwblow",pOps::value<int>(&iIRHCBShi.iLow),"Battleship Heavy ID Range; Low")
			("itemid.hwbhigh",pOps::value<int>(&iIRHCBShi.iHigh),"Battleship Heavy ID Range; High")
			("itemid.lwcslow",pOps::value<int>(&iIRLCCShi.iLow),"Commandship Laser ID Range; Low")
			("itemid.lwcshigh",pOps::value<int>(&iIRLCCShi.iHigh),"Commandship Laser ID Range; High")
			("itemid.mwcslow",pOps::value<int>(&iIRMCCShi.iLow),"Commandship Missile ID Range; Low")
			("itemid.mwcshigh",pOps::value<int>(&iIRMCCShi.iHigh),"Commandship Missile ID Range; High")
			("itemid.bwcslow",pOps::value<int>(&iIRBCCShi.iLow),"Commandship Bomb ID Range; Low")
			("itemid.bwcshigh",pOps::value<int>(&iIRBCCShi.iHigh),"Commandship Bomb ID Range; High")
			("itemid.rwcslow",pOps::value<int>(&iIRRCCShi.iLow),"Commandship Rail ID Range; Low")
			("itemid.rwcshigh",pOps::value<int>(&iIRRCCShi.iHigh),"Commandship Rail ID Range; High")
			("itemid.hwcslow",pOps::value<int>(&iIRHCCShi.iLow),"Commandship Heavy ID Range; Low")
			("itemid.hwcshigh",pOps::value<int>(&iIRHCCShi.iHigh),"Commandship Heavy ID Range; High")
			("itemid.lwmlow",pOps::value<int>(&iIRLCMShi.iLow),"Mothership Laser ID Range; Low")
			("itemid.lwmhigh",pOps::value<int>(&iIRLCMShi.iHigh),"Mothership Laser ID Range; High")
			("itemid.mwmlow",pOps::value<int>(&iIRMCMShi.iLow),"Mothership Missile ID Range; Low")
			("itemid.mwmhigh",pOps::value<int>(&iIRMCMShi.iHigh),"Mothership Missile ID Range; High")
			("itemid.bwmlow",pOps::value<int>(&iIRBCMShi.iLow),"Mothership Bomb ID Range; Low")
			("itemid.bwmhigh",pOps::value<int>(&iIRBCMShi.iHigh),"Mothership Bomb ID Range; High")
			("itemid.rwmlow",pOps::value<int>(&iIRRCMShi.iLow),"Mothership Rail ID Range; Low")
			("itemid.rwmhigh",pOps::value<int>(&iIRRCMShi.iHigh),"Mothership Rail ID Range; High")
			("itemid.hwmlow",pOps::value<int>(&iIRHCMShi.iLow),"Mothership Heavy ID Range; Low")
			("itemid.hwmhigh",pOps::value<int>(&iIRHCMShi.iHigh),"Mothership Heavy ID Range; High")
			("itemid.lwtlow",pOps::value<int>(&iIRLCTita.iLow),"Titan Laser ID Range; Low")
			("itemid.lwthigh",pOps::value<int>(&iIRLCTita.iHigh),"Titan Laser ID Range; High")
			("itemid.mwtlow",pOps::value<int>(&iIRMCTita.iLow),"Titan Missile ID Range; Low")
			("itemid.mwthigh",pOps::value<int>(&iIRMCTita.iHigh),"Titan Missile ID Range; High")
			("itemid.bwtlow",pOps::value<int>(&iIRBCTita.iLow),"Titan Bomb ID Range; Low")
			("itemid.bwthigh",pOps::value<int>(&iIRBCTita.iHigh),"Titan Bomb ID Range; High")
			("itemid.rwtlow",pOps::value<int>(&iIRRCTita.iLow),"Titan Rail ID Range; Low")
			("itemid.rwthigh",pOps::value<int>(&iIRRCTita.iHigh),"Titan Rail ID Range; High")
			("itemid.hwtlow",pOps::value<int>(&iIRHCTita.iLow),"Titan Heavy ID Range; Low")
			("itemid.hwthigh",pOps::value<int>(&iIRHCTita.iHigh),"Titan Heavy ID Range; High")


			//Non-Mining Barge Mining Laser IDs By Class
			("itemid.nmblcflow",pOps::value<int>(&iIRFMLaser.iLow),"Frigate Mining Laser ID Range; Low")
			("itemid.nmblcfhigh",pOps::value<int>(&iIRFMLaser.iHigh),"Frigate Mining Laser ID Range; High")
			("itemid.nmblcdlow",pOps::value<int>(&iIRDMLaser.iLow),"Destroyer Mining Laser ID Range; Low")
			("itemid.nmblcdhigh",pOps::value<int>(&iIRDMLaser.iHigh),"Destroyer Mining Laser ID Range; High")
			("itemid.nmblcclow",pOps::value<int>(&iIRCMLaser.iLow),"Cruiser Mining Laser ID Range; Low")
			("itemid.nmblcchigh",pOps::value<int>(&iIRCMLaser.iHigh),"Cruiser Mining Laser ID Range; High")
			("itemid.nmblcbclow",pOps::value<int>(&iIRBCMLaser.iLow),"Battle Cruiser Mining Laser ID Range; Low")
			("itemid.nmblcbchigh",pOps::value<int>(&iIRBCMLaser.iHigh),"Battle Cruiser Mining Laser ID Range; High")
			("itemid.nmblcblow",pOps::value<int>(&iIRBMLaser.iLow),"Battleship Mining Laser ID Range; Low")
			("itemid.nmblcbhigh",pOps::value<int>(&iIRBMLaser.iHigh),"Battleship Mining Laser ID Range; High")
			("itemid.nmblccslow",pOps::value<int>(&iIRCSMLaser.iLow),"Commandship Mining Laser ID Range; Low")
			("itemid.nmblccshigh",pOps::value<int>(&iIRCSMLaser.iHigh),"Commandship Mining Laser ID Range; High")
			("itemid.nmblcmlow",pOps::value<int>(&iIRMMLaser.iLow),"Mothership Mining Laser ID Range; Low")
			("itemid.nmblcmhigh",pOps::value<int>(&iIRMMLaser.iHigh),"Mothership Mining Laser ID Range; High")
			("itemid.nmblctlow",pOps::value<int>(&iIRTMLaser.iLow),"Titan Mining Laser ID Range; Low")
			("itemid.nmblcthigh",pOps::value<int>(&iIRTMLaser.iHigh),"Titan Mining Laser ID Range; High")

			//Mining Barge Mining Laser IDs
			("itemid.mbmllow",pOps::value<int>(&iIRMBMLaser.iLow),"Mining Barge Mining Laser ID Range; Low")
			("itemid.mbmlhigh",pOps::value<int>(&iIRMBMLaser.iHigh),"Mining Barge Mining Laser ID Range; High")

			//EMI IDs
			("itemid.pshdlow",pOps::value<int>(&iIRPShields.iLow),"Planetary Shield ID Range; Low")
			("itemid.pshdhigh",pOps::value<int>(&iIRPShields.iHigh),"Planetary Shield ID Range; High")
			("itemid.pdeflow",pOps::value<int>(&iIRPDefenses.iLow),"Planetary Defense ID Range; Low")
			("itemid.pdefhigh",pOps::value<int>(&iIRPDefenses.iHigh),"Planetary Defense ID Range; High")
			("itemid.cllow",pOps::value<int>(&iIRClones.iLow),"Clone ID Range; Low")
			("itemid.clhigh",pOps::value<int>(&iIRClones.iHigh),"Clone ID Range; High")

			//Planet Values
			("planet.pnames",pOps::value<int>(&pNames),"Number of planet/system names in the database")
			("planet.pslow",pOps::value<int>(&rPSize.iLow),"Planet Size Range; Low")
			("planet.pshigh",pOps::value<int>(&rPSize.iHigh),"Planet Size Range; High")
			("planet.pekslow",pOps::value<float>(&rPEKS.fLow),"Planet EKS Range; Low")
			("planet.pekshigh",pOps::value<float>(&rPEKS.fHigh),"Planet EKS Range; High")
			("planet.pt0low",pOps::value<float>(&rPT0.fLow),"Planet Type 0 Range; Low")
			("planet.pt0high",pOps::value<float>(&rPT0.fHigh),"Planet Type 0 Range; High")
			("planet.pt0psrlow",pOps::value<float>(&rPT0SRange.fLow),"Planet Type 0 Planet Size Range; Low")
			("planet.pt0psrhigh",pOps::value<float>(&rPT0SRange.fHigh),"Planet Type 0 Planet Size Range; High")
			("planet.pt1low",pOps::value<float>(&rPT1.fLow),"Planet Type 1 Range; Low")
			("planet.pt1high",pOps::value<float>(&rPT1.fHigh),"Planet Type 1 Range; High")
			("planet.pt1psrlow",pOps::value<float>(&rPT1SRange.fLow),"Planet Type 1 Planet Size Range; Low")
			("planet.pt1psrhigh",pOps::value<float>(&rPT1SRange.fHigh),"Planet Type 1 Planet Size Range; High")
			("planet.pt2low",pOps::value<float>(&rPT2.fLow),"Planet Type 2 Range; Low")
			("planet.pt2high",pOps::value<float>(&rPT2.fHigh),"Planet Type 2 Range; High")
			("planet.pt2psrlow",pOps::value<float>(&rPT2SRange.fLow),"Planet Type 2 Planet Size Range; Low")
			("planet.pt2psrhigh",pOps::value<float>(&rPT2SRange.fHigh),"Planet Type 2 Planet Size Range; High")
			("planet.pt3low",pOps::value<float>(&rPT3.fLow),"Planet Type 3 Range; Low")
			("planet.pt3high",pOps::value<float>(&rPT3.fHigh),"Planet Type 3 Range; High")
			("planet.pt3psrlow",pOps::value<float>(&rPT3SRange.fLow),"Planet Type 3 Planet Size Range; Low")
			("planet.pt3psrhigh",pOps::value<float>(&rPT3SRange.fHigh),"Planet Type 3 Planet Size Range; High")
			("planet.pt4low",pOps::value<float>(&rPT4.fLow),"Planet Type 4 Range; Low")
			("planet.pt4high",pOps::value<float>(&rPT4.fHigh),"Planet Type 4 Range; High")
			("planet.pt4psrlow",pOps::value<float>(&rPT4SRange.fLow),"Planet Type 4 Planet Size Range; Low")
			("planet.pt4psrhigh",pOps::value<float>(&rPT4SRange.fHigh),"Planet Type 4 Planet Size Range; High")
			("planet.pt5low",pOps::value<float>(&rPT5.fLow),"Planet Type 5 Range; Low")
			("planet.pt5high",pOps::value<float>(&rPT5.fHigh),"Planet Type 5 Range; High")
			("planet.pt5psrlow",pOps::value<float>(&rPT5SRange.fLow),"Planet Type 5 Planet Size Range; Low")
			("planet.pt5psrhigh",pOps::value<float>(&rPT5SRange.fHigh),"Planet Type 5 Planet Size Range; High")
			("planet.poprbase",pOps::value<int>(&popBase),"Planet Pop Base")
			("planet.popr1",pOps::value<int>(&rP1.iHigh),"Planet Pop Random 1 Range; High")
			("planet.popr2",pOps::value<int>(&rP2.iHigh),"Planet Pop Random 2 Range; High")
			("planet.popr3",pOps::value<int>(&rP3.iHigh),"Planet Pop Random 3 Range; High")

			//Game Values
			("game.gnsplanets",pOps::value<int>(&iNSPlanets),"Number of scannable planets")
			("game.gntstations",pOps::value<int>(&iNTStations),"Number of scannable stations")
			("game.gpdrlow",pOps::value<int>(&rGPDispo.iLow),"Planet Disposition Range; Low")
			("game.gpdrhigh",pOps::value<int>(&rGPDispo.iHigh),"Planet Dispostion Range; High")
			("game.gparlow",pOps::value<int>(&rGPAff.iLow),"Planet Affiliation Range; Low")
			("game.gparhigh",pOps::value<int>(&rGPAff.iHigh),"Planet Affiliation Range; High")

			//Asteroid/Belt Values
			("abelts.abarlow",pOps::value<int>(&rBAAmount.iLow),"Astroid Belt Asteroid Amount Range; Low")
			("abelts.abarhigh",pOps::value<int>(&rBAAmount.iHigh),"Astroid Belt Asteroid Amount Range; High")
			("abelts.abslow",pOps::value<float>(&rBSize.fLow),"Asteroid Belt Size Range; Low")
			("abelts.abshigh",pOps::value<float>(&rBSize.fHigh),"Asteroid Belt Size Range; High")
			("abelts.aoir1low",pOps::value<int>(&iIRS1Ore.iLow),"Stage 1 Ore Item ID Range; Low")
			("abelts.aoir1high",pOps::value<int>(&iIRS1Ore.iHigh),"Stage 1 Ore Item ID Range; High")
			("abelts.asr1low",pOps::value<float>(&rAS1Size.fLow),"Stage 1 Asteroid Size Range; Low")
			("abelts.asr1high",pOps::value<float>(&rAS1Size.fHigh),"Stage 1 Asteroid Size Range; High")
			("abelts.as1multi",pOps::value<float>(&aS1SMulti),"Stage 1 Asteroid Size Multiplier")
			("abelts.aoir2low",pOps::value<int>(&iIRS2Ore.iLow),"Stage 2 Ore Item ID Range; Low")
			("abelts.aoir2high",pOps::value<int>(&iIRS2Ore.iHigh),"Stage 2 Ore Item ID Range; High")
			("abelts.asr2low",pOps::value<float>(&rAS2Size.fLow),"Stage 2 Asteroid Size Range; Low")
			("abelts.asr2high",pOps::value<float>(&rAS2Size.fHigh),"Stage 2 Asteroid Size Range; High")
			("abelts.as2multi",pOps::value<float>(&aS2SMulti),"Stage 2 Asteroid Size Multiplier")
			("abelts.aoir3low",pOps::value<int>(&iIRS3Ore.iLow),"Stage 3 Ore Item ID Range; Low")
			("abelts.aoir3high",pOps::value<int>(&iIRS3Ore.iHigh),"Stage 3 Ore Item ID Range; High")
			("abelts.asr3low",pOps::value<float>(&rAS3Size.fLow),"Stage 3 Asteroid Size Range; Low")
			("abelts.asr3high",pOps::value<float>(&rAS3Size.fHigh),"Stage 3 Asteroid Size Range; High")
			("abelts.as3multi",pOps::value<float>(&aS3SMulti),"Stage 3 Asteroid Size Multiplier")

			//Ship Class Values
			("sclasses.sctypes",pOps::value<int>(&sCTypes),"Ship Class Types (number of classes)")
			("sclasses.scnames",pOps::value<string>(&sCNames),"Ship Class Names (comma-delimited)")

			//Mission Values
			("missions.mirlow",pOps::value<int>(&mIR.iLow),"Mission ID Range; Low")
			("missions.mirhigh",pOps::value<int>(&mIR.iHigh),"Mission ID Range; High")
			("missions.mmline",pOps::value<string>(&mMLine),"Main Mission Line")


			//Empire/Race Values
			("empires.etypes",pOps::value<int>(&eTypes),"Number of Empires")
			("empires.enames",pOps::value<string>(&eNames),"Empire Names (comma-delimited)")
			("races.rctypes",pOps::value<int>(&rcTypes),"Number of Races")
			("races.rcnames",pOps::value<string>(&rcNames),"Race Names (comma-delimited)")

			//Diplomacy Values
			("diplomacy.dtypes",pOps::value<int>(&dTypes),"Number of Diplomatic States")
			("diplomacy.dnames",pOps::value<string>(&dNames),"Names of Diplomating States (comma-delimited)")

			//Rank Values
			("ranks.rktypes",pOps::value<int>(&rkTypes),"Number of Ranks")
			("ranks.rknames",pOps::value<string>(&rkNames),"Rank Names (comma-delimited)")

			//Name Generation Values
			("names.nprlow",pOps::value<int>(&rNPfx.iLow),"Name Prefix ID Range; Low")
			("names.nprhigh",pOps::value<int>(&rNPfx.iHigh),"Name Prefix ID Range; High")
			("names.nsrlow",pOps::value<int>(&rNStem.iLow),"Name Stem ID Range; Low")
			("names.nsrhigh",pOps::value<int>(&rNStem.iHigh),"Name Stem ID Range; High")
			("names.nsfxrlow",pOps::value<int>(&rNSfx.iLow),"Name Suffix ID Range; Low")
			("names.nsfxrhigh",pOps::value<int>(&rNSfx.iHigh),"Name Suffix ID Range; High")

			//Message Values

			//Resource Values
			("resources.restypes",pOps::value<int>(&resTypes),"Number of resources in the game")
			("resources.resnames",pOps::value<string>(&resNames),"Resource Names (comma-delimited")

			//Casino Values

			//Slot Payouts
			("casino.psjp4",pOps::value<int>(&cSPJP4),"4x Jackpot Payout")
			("casino.psjp3_br",pOps::value<int>(&cSPJP3_Br),"3x Jackpot/1x Bar Payout")
			("casino.psjp3_7",pOps::value<int>(&cSPJP3_7),"3x Jackpot/1x 7 Payout")
			("casino.psjp3_h",pOps::value<int>(&cSPJP3_H),"3x Jackpot/1x Heart Payout")
			("casino.psjp3_b",pOps::value<int>(&cSPJP3_B),"3x Jackpot/1x Bell Payout")
			("casino.psjp3_n",pOps::value<int>(&cSPJP3_N),"3x Jackpot/1x Number Payout")
			("casino.psbr4",pOps::value<int>(&cSPBr4),"4x Bar Payout")
			("casino.psbr3_j",pOps::value<int>(&cSPBr3_J),"3x Bar/1x Jackpot Payout")
			("casino.psbr3_7",pOps::value<int>(&cSPBr3_7),"3x Bar/1x 7 Payout")
			("casino.psbr3_h",pOps::value<int>(&cSPBr3_H),"3x Bar/1x Heart Payout")
			("casino.psbr3_b",pOps::value<int>(&cSPBr3_B),"3x Bar/1x Bell Payout")
			("casino.psbr3_n",pOps::value<int>(&cSPBr3_N),"3x Bar/1x Number Payout")
			("casino.ps74",pOps::value<int>(&cSP74),"4x 7 Payout")
			("casino.ps73_j",pOps::value<int>(&cSP73_J),"3x 7/1x Jackpot Payout")
			("casino.ps73_br",pOps::value<int>(&cSP73_Br),"3x 7/1x Bar Payout")
			("casino.ps73_h",pOps::value<int>(&cSP73_H),"3x 7/1x Heart Payout")
			("casino.ps73_b",pOps::value<int>(&cSP73_B),"3x 7/1x Bell Payout")
			("casino.ps73_n",pOps::value<int>(&cSP73_N),"3x 7/1x Number Payout")
			("casino.psh4",pOps::value<int>(&cSPH4),"4x Heart Payout")
			("casino.psh3_j",pOps::value<int>(&cSPH3_J),"3x Heart/1x Jackpot Payout")
			("casino.psh3_br",pOps::value<int>(&cSPH3_Br),"3x Heart/1x Bar Payout")
			("casino.psh3_7",pOps::value<int>(&cSPH3_7),"3x Heart/1x 7 Payout")
			("casino.psh3_b",pOps::value<int>(&cSPH3_B),"3x Heart/1x Bell Payout")
			("casino.psh3_n",pOps::value<int>(&cSPH3_N),"3x Heart/1x Number Payout")
			("casino.psb4",pOps::value<int>(&cSPB4),"4x Bell Payout")
			("casino.psb3_j",pOps::value<int>(&cSPB3_J),"3x Bell/1x Jackpot Payout")
			("casino.psb3_br",pOps::value<int>(&cSPB3_Br),"3x Bell/1x Bar Payout")
			("casino.psb3_7",pOps::value<int>(&cSPB3_7),"3x Bell/1x 7 Payout")
			("casino.psb3_h",pOps::value<int>(&cSPB3_H),"3x Bell/1x Heart Payout")
			("casino.psb3_n",pOps::value<int>(&cSPB3_N),"3x Bell/1x Number Payout")
			("casino.psn4",pOps::value<int>(&cSPN4),"4x Number Payout")
			("casino.psn3_j",pOps::value<int>(&cSPN3_J),"3x Number/1x Jackpot Payout")
			("casino.psn3_br",pOps::value<int>(&cSPN3_Br),"3x Number/1x Bar Payout")
			("casino.psn3_7",pOps::value<int>(&cSPN3_7),"3x Number/1x 7 Payout")
			("casino.psn3_h",pOps::value<int>(&cSPN3_H),"3x Number/1x Heart Payout")
			("casino.psn3_b",pOps::value<int>(&cSPN3_B),"3x Number/1x Bell Payout")

			//Roulette Returns
			("casino.brzeros",pOps::value<float>(&cRBRZeros),"Zeroes Return")
			("casino.brnum",pOps::value<float>(&cRBRNum),"Number Return")
			("casino.brc_g",pOps::value<float>(&cRBRC_G),"Color: Green Return")
			("casino.brtype",pOps::value<float>(&cRBRType),"Even/Odd Return")
			("casino.brc_rb",pOps::value<float>(&cRBRC_RB),"Color: Red/Black Return")
			("casino.brs_s",pOps::value<float>(&cRBRS_S),"Section: Short Return")
			("casino.brs_l",pOps::value<float>(&cRBRS_L),"Section: Long Return")
			("casino.brquarter",pOps::value<float>(&cRBRQ),"Quarter Return")
			("casino.brhalf",pOps::value<float>(&cRBRH),"Half Return")

			//Damage Values
			("damage.dttypes",pOps::value<int>(&dTTypes),"Number of damage types")
			("damage.dtnames",pOps::value<string>(&dTNames),"Comma-delimited list of damage type names")
			("damage.dtedp",pOps::value<string>(&dTEDP),"Comma-delimited list of extra damage percentages")
			("damage.ddpt",pOps::value<string>(&dDPT),"Comma-delimited list of turn lengths for turn based damage");

		pOps::variables_map vm;

		try
		{
			ifstream settings_file("scSettings.ini",ifstream::in);
			pOps::store(pOps::parse_config_file(settings_file, desc, true), vm);
			settings_file.close();
			pOps::notify(vm);
		}

		catch (const pOps::error& e )
		{
			//std::cerr << e.what() << std::endl;

			string file = __FILE__;
			string bLocale = "File: " + file + "  Line: ";

			string time = __TIME__;
			string date = __DATE__;

			string bTDate = date + "  " + time;

			d_gv.createBReport("Configuration File Error", e.what(),bLocale + to_string(__LINE__),bTDate,"./SC_Log.txt");
		}

		if (iIRSCFrig.iLow > 0)
		{
			//Now deal with some of the values that we could not add through options (namely the low end of the population randoms for planets)
			
			setNIValues();

			cout << "Data successfully loaded from configuration file." << endl;
			system("Pause");
			system("CLS");				
		}

		else
		{
			cout << "Data was not successfully loaded from configuration file.  Please check the error log for more details" << endl;
			system("Pause");
			system("CLS");
		}
	}

	void printData()
	{
		//TODO: Raname variable labels to ini file keys instead

		//Ship ID Ranges By Class
		cout << "Format: Description: name of low entry from scSettings.ini: imported value |" << endl;
		cout << "name of high entry from scSettings.ini: imported value" << endl << endl;

		cout << "Starter Ship Range: ssrlow: " << iIRSShips.iLow << " | ssrhigh: " << iIRSShips.iHigh << endl;
		cout << "Frigate ID Range: scflow: " << iIRSCFrig.iLow << " | scfhigh: " << iIRSCFrig.iHigh << endl;
		cout << "Destroyer ID Range: scdlow: " << iIRSCDest.iLow << " | scdhigh: " << iIRSCDest.iHigh << endl;
		cout << "Cruiser ID Range: scclow: " << iIRSCCrui.iLow << " | scchigh: " << iIRSCCrui.iHigh << endl;
		cout << "Battle Cruiser ID Range: scbclow: " << iIRSCBCru.iLow << " | scbchigh: " << iIRSCBCru.iHigh << endl;
		cout << "Battleship ID Range: scblow: " << iIRSCBShi.iLow << " | scbhigh: " << iIRSCBShi.iHigh << endl;
		cout << "Commandship ID Range: sccslow: " << iIRSCCShi.iLow << " | sccshigh: " << iIRSCCShi.iHigh << endl;
		cout << "Mothership ID Range: scmlow: " << iIRSCMShi.iLow << " | scmhigh: " << iIRSCMShi.iHigh << endl;
		cout << "Titan ID Range: sctlow: " << iIRSCTita.iLow << " | scthigh: " << iIRSCTita.iHigh << endl;
		cout << "Mining Barge ID Range: scmblow: " << iIRSCMBar.iLow << " | scmbhigh: " << iIRSCMBar.iHigh << endl;

		system("Pause");
		system("CLS");


		cout << "Number of ship classes: sctypes " << sCTypes << endl;
		cout << "Class names imported:" << endl;

		for (i = 0; i < sClasses.size(); i++)
		{
			cout << sClasses.at(i) << endl;
		}

		system("Pause");
		system("CLS");

		//Weapon ID Ranges By Class
		cout << "Format: Description: name of low entry from scSettings.ini: imported value |" << endl;
		cout << "name of high entry from scSettings.ini: imported value" << endl << endl;

		//Frigate Class
		cout << "Frigate Weapon ID Ranges:" << endl;
		cout << "Laser Weapons: lwflow: " << iIRLCFrig.iLow << " | " << "lwfhigh: " << iIRLCFrig.iHigh << endl;
		cout << "Missile Weapons: mwflow: " << iIRMCFrig.iLow << " | " << "mwfhigh: " << iIRMCFrig.iHigh << endl;
		cout << "Bomb Weapons: bwflow: " << iIRBCFrig.iLow << " | " << "bwfhigh: " << iIRBCFrig.iHigh << endl;
		cout << "Railgun Weapons: rwflow: " << iIRRCFrig.iLow << " | " << "rwfhigh: " << iIRRCFrig.iHigh << endl;
		cout << "Heavy Weapons: hwflow: " << iIRHCFrig.iLow << " | " << "hwfhigh: " << iIRHCFrig.iHigh << endl;
		cout << "Mining Lasers: nmblcflow: " << iIRFMLaser.iLow << " | " << "nmblcfhigh: " << iIRFMLaser.iHigh << endl << endl;

		//Destroyer Class
		cout << "Destroyer Weapon ID Ranges:" << endl;
		cout << "Laser Weapons: lwdlow: " << iIRLCDest.iLow << " | " << "lwdhigh: " << iIRLCDest.iHigh << endl;
		cout << "Missile Weapons: mwdlow: " << iIRMCDest.iLow << " | " << "mwdhigh: " << iIRMCDest.iHigh << endl;
		cout << "Bomb Weapons: bwdlow: " << iIRBCDest.iLow << " | " << "bwdhigh: " << iIRBCDest.iHigh << endl;
		cout << "Railgun Weapons: rwdlow: " << iIRRCDest.iLow << " | " << "rwdhigh: " << iIRRCDest.iHigh << endl;
		cout << "Heavy Weapons: hwdlow: " << iIRHCDest.iLow << " | " << "hwdhigh: " << iIRHCDest.iHigh << endl;
		cout << "Mining Lasers: nmblcdlow: " << iIRDMLaser.iLow << " | " << "nmblcdhigh: " << iIRDMLaser.iHigh << endl << endl;

		//Cruiser Class
		cout << "Cruiser Weapon ID Ranges:" << endl;
		cout << "Laser Weapons: lwclow: " << iIRLCCrui.iLow << " | " << "lwchigh: " << iIRLCCrui.iHigh << endl;
		cout << "Missile Weapons: mwclow: " << iIRMCCrui.iLow << " | " << "mwchigh: " << iIRMCCrui.iHigh << endl;
		cout << "Bomb Weapons: bwclow: " << iIRBCCrui.iLow << " | " << "bwchigh: " << iIRBCCrui.iHigh << endl;
		cout << "Railgun Weapons: rwclow: " << iIRRCCrui.iLow << " | " << "rwchigh: " << iIRRCCrui.iHigh << endl;
		cout << "Heavy Weapons: hwclow: " << iIRHCCrui.iLow << " | " << "hwchigh: " << iIRHCCrui.iHigh << endl;
		cout << "Mining Lasers: nmblcclow: " << iIRCMLaser.iLow << " | " << "nmblcchigh: " << iIRCMLaser.iHigh << endl << endl;

		//B. Cruiser Class
		cout << "Battle Cruiser Weapon ID Ranges:" << endl;
		cout << "Laser Weapons: lwbclow: " << iIRLCBCru.iLow << " | " << "lwbchigh: " << iIRLCBCru.iHigh << endl;
		cout << "Missile Weapons: mwbclow: " << iIRMCBCru.iLow << " | " << "mwbchigh: " << iIRMCBCru.iHigh << endl;
		cout << "Bomb Weapons: bwbclow: " << iIRBCBCru.iLow << " | " << "bwbchigh: " << iIRBCBCru.iHigh << endl;
		cout << "Railgun Weapons: rwbclow: " << iIRRCBCru.iLow << " | " << "rwbchigh: " << iIRRCBCru.iHigh << endl;
		cout << "Heavy Weapons: hwbclow: " << iIRHCBCru.iLow << " | " << "hwbchigh: " << iIRHCBCru.iHigh << endl;
		cout << "Mining Lasers: nmblcbclow: " << iIRBCMLaser.iLow << " | " << "nmblcbchigh: " << iIRBCMLaser.iHigh << endl << endl;

		//Battleship Class
		cout << "Battleship Weapon ID Ranges:" << endl;
		cout << "Laser Weapons: lwblow: " << iIRLCBShi.iLow << " | " << "lwbhigh: " << iIRLCBShi.iHigh << endl;
		cout << "Missile Weapons: mwblow: " << iIRMCBShi.iLow << " | " << "mwbhigh: " << iIRMCBShi.iHigh << endl;
		cout << "Bomb Weapons: bwblow: " << iIRBCBShi.iLow << " | " << "bwbhigh: " << iIRBCBShi.iHigh << endl;
		cout << "Railgun Weapons: rwblow: " << iIRRCBShi.iLow << " | " << "rwbhigh: " << iIRRCBShi.iHigh << endl;
		cout << "Heavy Weapons: hwblow: " << iIRHCBShi.iLow << " | " << "hwbhigh: " << iIRHCBShi.iHigh << endl;
		cout << "Mining Lasers: nmblcblow: " << iIRBMLaser.iLow << " | " << "nmblcbhigh: " << iIRBMLaser.iHigh << endl << endl;

		//Commandship Class
		cout << "Commandship Weapon ID Ranges:" << endl;
		cout << "Laser Weapons: lwcslow: " << iIRLCCShi.iLow << " | " << "lwcshigh: " << iIRLCCShi.iHigh << endl;
		cout << "Missile Weapons: mwcslow: " << iIRMCCShi.iLow << " | " << "mwcshigh: " << iIRMCCShi.iHigh << endl;
		cout << "Bomb Weapons: bwcslow: " << iIRBCCShi.iLow << " | " << "bwcshigh: " << iIRBCCShi.iHigh << endl;
		cout << "Railgun Weapons: rwcslow: " << iIRRCCShi.iLow << " | " << "rwcshigh: " << iIRRCCShi.iHigh << endl;
		cout << "Heavy Weapons: hwcslow: " << iIRHCCShi.iLow << " | " << "hwcshigh: " << iIRHCCShi.iHigh << endl;
		cout << "Mining Lasers: nmblccslow: " << iIRCSMLaser.iLow << " | " << "nmblccshigh: " << iIRCSMLaser.iHigh << endl << endl;

		//Mothership Class
		cout << "Mothership Weapon ID Ranges:" << endl;
		cout << "Laser Weapons: lwmlow: " << iIRLCMShi.iLow << " | " << "lwmhigh: " << iIRLCMShi.iHigh << endl;
		cout << "Missile Weapons: mwmlow: " << iIRMCMShi.iLow << " | " << "mwmhigh: " << iIRMCMShi.iHigh << endl;
		cout << "Bomb Weapons: bwmlow: " << iIRBCMShi.iLow << " | " << "bwmhigh: " << iIRBCMShi.iHigh << endl;
		cout << "Railgun Weapons: rwmlow: " << iIRRCMShi.iLow << " | " << "rwmhigh: " << iIRRCMShi.iHigh << endl;
		cout << "Heavy Weapons: hwmlow: " << iIRHCMShi.iLow << " | " << "hwmhigh: " << iIRHCMShi.iHigh << endl;
		cout << "Mining Lasers: nmblcmlow: " << iIRMMLaser.iLow << " | " << "nmblcmhigh: " << iIRMMLaser.iHigh << endl << endl;

		//Titan Class
		cout << "Titan Weapon ID Ranges:" << endl;
		cout << "Laser Weapons: lwtlow: " << iIRLCTita.iLow << " | " << "lwthigh: " << iIRLCTita.iHigh << endl;
		cout << "Missile Weapons: mwtlow: " << iIRMCTita.iLow << " | " << "mwthigh: " << iIRMCTita.iHigh << endl;
		cout << "Bomb Weapons: bwtlow: " << iIRBCTita.iLow << " | " << "bwthigh: " << iIRBCTita.iHigh << endl;
		cout << "Railgun Weapons: rwtlow: " << iIRRCTita.iLow << " | " << "rwthigh: " << iIRRCTita.iHigh << endl;
		cout << "Heavy Weapons: hwtlow: " << iIRHCTita.iLow << " | " << "hwthigh: " << iIRHCTita.iHigh << endl;
		cout << "Mining Lasers: nmblctlow: " << iIRTMLaser.iLow << " | " << "nmblcthigh: " << iIRTMLaser.iHigh << endl << endl;

		//Mining Barge Class
		cout << "Mining Barge Utility Ranges:" << endl;
		cout << "Mining Lasers: mbmllow: " << iIRMBMLaser.iLow << " | " << "mbmlhigh: " << iIRMBMLaser.iHigh << endl;
		//cout << "Strip Miners: mwflow: " << iIRMCFrig.iLow << " | " << "mwfhigh: " << iIRMCFrig.iHigh << endl; //TODO: Make laser and strippers two separate item types

		system("Pause");
		system("CLS");

		//EMI ID Ranges
		cout << "Format: Description: name of low entry from scSettings.ini: imported value |" << endl;
		cout << "name of high entry from scSettings.ini: imported value" << endl << endl;

		cout << "Planetary Shield ID Range: pshdlow: " << iIRPShields.iLow << " | pshdhigh: " << iIRPShields.iHigh << endl;
		cout << "Planetary Defense ID Ranges: pdeflow: " << iIRPDefenses.iLow << " | pdefhigh: " << iIRPDefenses.iHigh << endl;
		cout << "Clone ID Ranges: cllow: " << iIRClones.iLow << " | clhigh: " << iIRClones.iHigh << endl;


		system("Pause");
		system("CLS");

		
		/*Ship Related Values
		string sCNames; //Comma-delimited list of ship class names
		int sCTypes; //Number of ship classes


		//Planet Related Values	
		int pNames; //Number of planet/system names in the database
		Range rPSize; //Planet Size Range
		Range rPEKS; //Planet EKS Range
		Range rPT0; //Planet Type 0 Range
		Range rPT0SRange; //Planet Type 0 Size Range	
		Range rPT1; //Planet Type 1 Range
		Range rPT1SRange; //Planet Type 1 Size Range
		Range rPT2; //Planet Type 2 Range
		Range rPT2SRange; //Planet Type 2 Size Range
		Range rPT3; //Planet Type 3 Range
		Range rPT3SRange; //Planet Type 3 Size Range
		Range rPT4; //Planet Type 4 Range
		Range rPT4SRange; //Planet Type 4 Size Range
		Range rPT5; //Planet Type 5 Range
		Range rPT5SRange; //Planet Type 5 Size Range
		int popBase;
		Range rP1; //Planet Pop Range 1
		Range rP2; //Planet Pop Range 2
		Range rP3; //Planet Pop Range 3


		//Game Related Values
		int iNSPlanets; //The number of planets scannable at once TODO: make this the max possible
		int iNTStations; //The number of stations scannable at once TODO: same as above
		Range rGPDispo; //Planet disposition range
		Range rGPAff; //Planet affitiliation range


		//Asteroid/Belt Related Values
		Range rBAAmount; //Asteroid belt asteroid amount range
		Range rBSize; //Asteroid belt size range
		Range iIRS1Ore; //Stage 1 ore item ID range
		Range rAS1Size; //Stage 1 asteroid size range
		float aS1SMulti; //Stage 1 asteroid size multiplier
		Range iIRS2Ore; //Stage 2 ore item ID range
		Range rAS2Size; //Stage 2 asteroid size range
		float aS2SMulti; //Stage 2 asteroid size multiplier
		Range iIRS3Ore; //Stage 3 ore item ID range
		Range rAS3Size; //Stage 3 asteroid size range
		float aS3SMulti; //Stage 3 asteroid size multiplier

		//Mission Related Values
		Range mIR; //Mission ID Range

		//Empire/Race Related Values
		int rcTypes; //Number of races
		int eTypes; //Number of empires
		string rcNames; //Comma-delimited list of race names
		string eNames; //Comma-delimited list of empire names

		//Displomacy Related Values
		int dTypes; //Number of diplomatic states
		string dNames; //Comma-delimited list of diplomatic state names

		//Rank Related Values
		int rkTypes; //Number of ranks
		string rkNames; //Comma-delimited list of rank names

		//Name Generation Related Values
		Range rNPfx; //Prefix ID Range
		Range rNStem; //Stem ID Range
		Range rNSfx; //Suffix ID Range*/
	}

	void setNIValues()
	{
		rP1.iLow = popBase;
		rP2.iLow = popBase;
		rP3.iLow = popBase;

		//Fill Vectors
		split(sClasses,sCNames,boost::is_any_of(","));
		split(eRanks,rkNames,boost::is_any_of(","));
		split(rNames,rcNames,boost::is_any_of(","));
		split(rENames,eNames,boost::is_any_of(","));
		split(sDNames, dTNames,boost::is_any_of(","));
		split(gRNames, resNames, boost::is_any_of(","));
		split(gDNames, dNames, boost::is_any_of(","));

		//Fill Non-String Vectors	
		clearVect(temp1); //Clear temp1 before each use
		split(temp1,mMLine,boost::is_any_of(","));
		fillVect(gMMissions, "int");

		clearVect(temp1);
		split(temp1, dDPT, boost::is_any_of(","));
		fillVect(sDETurns, "int");

		clearVect(temp1);
		split(temp1, dTEDP, boost::is_any_of(","));
		fillVect(sDDPerc, "float");
	}

	template<typename t> void fillVect(vector<t> vect, string type)
	{
		if (type == "int")
		{
			for (i = 0; i < temp1.size(); i++)
			{
				vect.push_back(atoi(temp1.at(i).c_str()));
			}
		}

		if (type == "float")
		{
			for (i = 0; i < temp1.size(); i++)
			{
				vect.push_back(atof(temp1.at(i).c_str()));
			}
		}

		/*if (type == "double")
		{
			for (i = 0; i < temp1.size(); i++)
			{
				vect.push_back(atod(temp1.at(i).c_str()));
			}
		}*/
	}

	template<typename t> void clearVect(vector<t> vect)
	{
		vect.clear();
	}


	//Configuration Variables

	//EMI ID Ranges	
	Range iIRPShields; //Planetary Shield Item ID Range
	Range iIRPDefenses; //Planetary Defense Item ID Range
	Range iIRClones; //Clone Item ID Range
	Range iIRShips; //Ship Item ID Range

	Range iIRSShips; //Starter Ship ID Range

	//Ship ID Ranges By Class
	Range iIRSCFrig; //Frigate ID Range
	Range iIRSCDest; //Destroyer ID Range
	Range iIRSCCrui; //Cruiser ID Range
	Range iIRSCBCru; //Battle Cruiser ID Range
	Range iIRSCBShi; //Battleship ID Range
	Range iIRSCCShi; //Commandship ID Range
	Range iIRSCMShi; //Mother Ship ID Range
	Range iIRSCTita; //Titan Ship ID Range
	Range iIRSCMBar; //Mining Barge Item ID Range

	//Weapon ID Ranges By Class

	//Frigate Ranges
	Range iIRLCFrig; //Laser ID Range
	Range iIRMCFrig; //Missile ID Range
	Range iIRBCFrig; //Bomb ID Range
	Range iIRRCFrig; //Rail ID Range
	Range iIRHCFrig; //Heavy ID Range

	//Destroyer Ranges
	Range iIRLCDest; //Laser ID Range
	Range iIRMCDest; //Missile ID Range
	Range iIRBCDest; //Bomb ID Range
	Range iIRRCDest; //Rail ID Range
	Range iIRHCDest; //Heavy ID Range

	//Crusiser Ranges
	Range iIRLCCrui; //Laser ID Range
	Range iIRMCCrui; //Missile ID Range
	Range iIRBCCrui; //Bomb ID Range
	Range iIRRCCrui; //Rail ID Range
	Range iIRHCCrui; //Heavy ID Range

	//Battle Cruiser Ranges
	Range iIRLCBCru; //Laser ID Range
	Range iIRMCBCru; //Missile ID Range
	Range iIRBCBCru; //Bomb ID Range
	Range iIRRCBCru; //Rail ID Range
	Range iIRHCBCru; //Heavy ID Range

	//Battleship Ranges
	Range iIRLCBShi; //Laser ID Range
	Range iIRMCBShi; //Missile ID Range
	Range iIRBCBShi; //Bomb ID Range
	Range iIRRCBShi; //Rail ID Range
	Range iIRHCBShi; //Heavy ID Range

	//Commandship Ranges
	Range iIRLCCShi; //Laser ID Range
	Range iIRMCCShi; //Missile ID Range
	Range iIRBCCShi; //Bomb ID Range
	Range iIRRCCShi; //Rail ID Range
	Range iIRHCCShi; //Heavy ID Range

	//Mothership Ranges
	Range iIRLCMShi; //Laser ID Range
	Range iIRMCMShi; //Missile ID Range
	Range iIRBCMShi; //Bomb ID Range
	Range iIRRCMShi; //Rail ID Range
	Range iIRHCMShi; //Heavy ID Range

	//Titan Ranges
	Range iIRLCTita; //Laser ID Range
	Range iIRMCTita; //Missile ID Range
	Range iIRBCTita; //Bomb ID Range
	Range iIRRCTita; //Rail ID Range
	Range iIRHCTita; //Heavy ID Range

	//Mining Lasers by Class
	Range iIRFMLaser; //Frigate Mining Laser ID Range
	Range iIRDMLaser; //Destroyer Mining Laser ID Range
	Range iIRCMLaser; //Cruiser Mining Laser ID Range
	Range iIRBCMLaser; //Battle Cruiser Mining Laser ID Range
	Range iIRBMLaser; //Battleship Mining Laser ID Range
	Range iIRCSMLaser; //Commandship Mining Laser ID Range
	Range iIRMMLaser; //Mothership Mining Laser ID Range
	Range iIRTMLaser; //Titan Mining Laser ID Range

	//Mining Barge Mining Laser ID Range
	Range iIRMBMLaser;


	//Ship Related Values
	string sCNames; //Comma-delimited list of ship class names
	int sCTypes; //Number of ship classes


	//Planet Related Values	
	int pNames; //Number of planet/system names in the database
	Range rPSize; //Planet Size Range
	Range rPEKS; //Planet EKS Range
	Range rPT0; //Planet Type 0 Range
	Range rPT0SRange; //Planet Type 0 Size Range	
	Range rPT1; //Planet Type 1 Range
	Range rPT1SRange; //Planet Type 1 Size Range
	Range rPT2; //Planet Type 2 Range
	Range rPT2SRange; //Planet Type 2 Size Range
	Range rPT3; //Planet Type 3 Range
	Range rPT3SRange; //Planet Type 3 Size Range
	Range rPT4; //Planet Type 4 Range
	Range rPT4SRange; //Planet Type 4 Size Range
	Range rPT5; //Planet Type 5 Range
	Range rPT5SRange; //Planet Type 5 Size Range
	int popBase;
	Range rP1; //Planet Pop Range 1
	Range rP2; //Planet Pop Range 2
	Range rP3; //Planet Pop Range 3


	//Game Related Values
	int iNSPlanets; //The number of planets scannable at once TODO: make this the max possible
	int iNTStations; //The number of stations scannable at once TODO: same as above
	Range rGPDispo; //Planet disposition range
	Range rGPAff; //Planet affitiliation range


	//Asteroid/Belt Related Values
	Range rBAAmount; //Asteroid belt asteroid amount range
	Range rBSize; //Asteroid belt size range
	Range iIRS1Ore; //Stage 1 ore item ID range
	Range rAS1Size; //Stage 1 asteroid size range
	float aS1SMulti; //Stage 1 asteroid size multiplier
	Range iIRS2Ore; //Stage 2 ore item ID range
	Range rAS2Size; //Stage 2 asteroid size range
	float aS2SMulti; //Stage 2 asteroid size multiplier
	Range iIRS3Ore; //Stage 3 ore item ID range
	Range rAS3Size; //Stage 3 asteroid size range
	float aS3SMulti; //Stage 3 asteroid size multiplier

	//Mission Related Values
	Range mIR; //Mission ID Range
	string mMLine; //Comma-delimited list of main mission line IDs

	//Empire/Race Related Values
	int rcTypes; //Number of races
	int eTypes; //Number of empires
	string rcNames; //Comma-delimited list of race names
	string eNames; //Comma-delimited list of empire names

	//Displomacy Related Values
	int dTypes; //Number of diplomatic states
	string dNames; //Comma-delimited list of diplomatic state names

	//Rank Related Values
	int rkTypes; //Number of ranks
	string rkNames; //Comma-delimited list of rank names

	//Name Generation Related Values
	Range rNPfx; //Prefix ID Range
	Range rNStem; //Stem ID Range
	Range rNSfx; //Suffix ID Range

	//Message Related Values

	//Resource Related Values
	int resTypes; //Number of resources in the game
	string resNames; //Comma-delimited list of resource names

	//Casino Related Values

	//Slot Payouts
	int cSPJP4; //Four Jackpots
	int cSPJP3_Br; //Three Jackpots + Bar
	int cSPJP3_7; //Three Jackpots + 7
	int cSPJP3_H; //Three Jackpots + Heart
	int cSPJP3_B; //Three Jackpots + Bell
	int cSPJP3_N; //Three Jackpots + Number

	//Bars
	int cSPBr4; //Four Bars
	int cSPBr3_J; //Three Bars + Jackpot
	int cSPBr3_7; //Three Bars + 7
	int cSPBr3_H; //Three Bars + Heart
	int cSPBr3_B; //Three Bars + Bell
	int cSPBr3_N; //Three Bars + Number

	//Sevens
	int cSP74; //Four Sevens
	int cSP73_J; //Three Sevens + Jackpot
	int cSP73_Br; //Three Sevens + Bar
	int cSP73_H; //Three Sevens + Heart
	int cSP73_B; //Three Sevens + Bell
	int cSP73_N; //Three Sevens + Number

	//Hearts
	int cSPH4; //Four Hearts
	int cSPH3_J; //Three Hearts + Jackpot
	int cSPH3_Br; //Three Hearts + Bar
	int cSPH3_7; //Three Hearts + 7
	int cSPH3_B; //Three Hearts + Bell
	int cSPH3_N; //Three Hearts + Number

	//Bells
	int cSPB4; //Four Bells
	int cSPB3_J; //Three Bells + Jackpot
	int cSPB3_Br; //Three Bells + Bar
	int cSPB3_7; //Three Bells + 7
	int cSPB3_H; //Three Bells + Heart
	int cSPB3_N; //Three Bells + Number

	//Numbers
	int cSPN4; //Four Numbers
	int cSPN3_J; //Three Numbers + Jackpot
	int cSPN3_Br; //Three Numbers + Bar
	int cSPN3_7; //Three Numbers + 7
	int cSPN3_H; //Three Numbers + Heart
	int cSPN3_B; //Three Numbers + Bell


	//Roulette Returns
	float cRBRZeros; //Zeros
	float cRBRNum; //Number
	float cRBRC_G; //Color; Green
	float cRBRType; //Type
	float cRBRC_RB; //Color; Red/Black
	float cRBRS_S; //Section; Small
	float cRBRS_L; //Section; Long
	float cRBRQ; //Quarter
	float cRBRH; //Half

	//Damage Related Values
	int dTTypes; //Number of damage types
	string dTNames; //Comma-delimited string of damage type names
	string dTEDP; //Comma-delimited string of extra damage percentages
	string dDPT; //Comma-delimited string of turns for turn based damage

	//Vectors
	vector<string> sClasses; //Ship Classes
	vector<string> eRanks; //Entity Ranks
	vector<string> rNames; //Race Names
	vector<string> rENames; //Race Empire Names
	vector<string> sDNames; //Secondary Damage Names
	vector<float>  sDDPerc; //Secondary Damage Damage Percentges
	vector<int>	   sDETurns; //Secondary Damage Effect Turns
	vector<string> gRNames; //Resource Names
	vector<string> gDNames; //Diplomatic State Names
	vector<int>	gMMissions; //Main mission line
	vector<string> temp1; //Temp vector for storing strings to be cast to something else
	
	//Misc
	int i,i2,i3,i4; //For for loops
}