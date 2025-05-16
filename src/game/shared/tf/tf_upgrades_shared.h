//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:		Load item upgrade data from KeyValues
//
// $NoKeywords: $
//=============================================================================

#ifndef TF_UPGRADES_SHARED_H
#define TF_UPGRADES_SHARED_H

#ifdef CLIENT_DLL
#define CTFPlayer C_TFPlayer
#endif

class CTFPlayer;

#include "tf_shareddefs.h"

class CMannVsMachineUpgrades
{
public:
	char szAttrib[ MAX_ATTRIBUTE_DESCRIPTION_LENGTH ];
	char szIcon[ MAX_PATH ];
	float flIncrement;
	float flCap;
	int nCost;
	int nUIGroup;
	int nQuality;
	int nTier;		// If set, upgrades in the same tier - for the same player/item - will be mutually exclusive

	bool bCustom;
	bool bClass[TF_CLASS_COUNT_ALL];
	bool bSlot[TF_WPN_TYPE_COUNT];
	bool bWeapon[TF_WEAPON_COUNT + 1];
};


class CMannVsMachineUpgradeManager : public CAutoGameSystem
{
public:
	CMannVsMachineUpgradeManager();

	virtual void LevelInitPostEntity();
	virtual void LevelShutdownPostEntity();

	void ParseUpgradeBlockForUIGroup( KeyValues *pKV, int iDefaultUIGroup );

	int GetAttributeIndexByName( const char* pszAttributeName );

	void LoadUpgradesFile( void );
	void LoadUpgradesFileFromPath( const char *pszPath );

public:
	CUtlVector< CMannVsMachineUpgrades > m_Upgrades;

private:
	CUtlMap< const char*, int > m_AttribMap;

};

extern CMannVsMachineUpgradeManager g_MannVsMachineUpgrades;
int GetUpgradeStepData( CTFPlayer *pPlayer, int nWeaponSlot, int nUpgradeIndex, int &nCurrentStep, bool &bOverCap );

#endif // TF_UPGRADES_H
