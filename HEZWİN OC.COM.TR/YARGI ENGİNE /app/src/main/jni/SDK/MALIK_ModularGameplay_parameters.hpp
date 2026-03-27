#pragma once

// PUBG MOBILE (3.8.0) TELEGRAM MALIK:-@K_Y_2  
// GENERATE ON Wed May  7 14:35:34 2025
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------
//Parameters
//---------------------------------------------------------------------------

// Function ModularGameplay.GameFrameworkComponentManager.RemoveReceiver
struct UGameFrameworkComponentManager_RemoveReceiver_Params
{
	class AActor*                                      Receiver;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function ModularGameplay.GameFrameworkComponentManager.AddReceiver
struct UGameFrameworkComponentManager_AddReceiver_Params
{
	class AActor*                                      Receiver;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bAddOnlyInGameWorlds;                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

}

