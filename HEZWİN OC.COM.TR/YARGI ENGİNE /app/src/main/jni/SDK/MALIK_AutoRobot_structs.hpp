#pragma once

// PUBG MOBILE (3.8.0) TELEGRAM MALIK:-@K_Y_2  
// GENERATE ON Wed May  7 14:35:34 2025
 
namespace SDK
{
//---------------------------------------------------------------------------
//Enums
//---------------------------------------------------------------------------

// Enum AutoRobot.EAutoRunTestFlag
enum class EAutoRunTestFlag : uint8_t
{
	Game4Win                       = 0,
	PVEBattleTest                  = 1,
	EAutoRunTestFlag_MAX           = 2
};



//---------------------------------------------------------------------------
//Script Structs
//---------------------------------------------------------------------------

// ScriptStruct AutoRobot.BulletImpactAutoTestData
// 0x001C
struct FBulletImpactAutoTestData
{
	unsigned char                                      UnknownData00[0x1C];                                      // 0x0000(0x001C) MISSED OFFSET
};

}

