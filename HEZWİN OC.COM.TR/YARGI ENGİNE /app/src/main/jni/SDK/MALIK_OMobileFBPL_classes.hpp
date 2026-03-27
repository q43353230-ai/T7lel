#pragma once

// PUBG MOBILE (3.8.0) TELEGRAM MALIK:-@K_Y_2  
// GENERATE ON Wed May  7 14:35:33 2025
 
namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// Class OMobileFBPL.OMobileFBPL
// 0x0000 (0x0020 - 0x0020)
class UOMobileFBPL : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class OMobileFBPL.OMobileFBPL");
		return pStaticClass;
	}


	static bool IsRunningOnBattery();
	static bool IsBatteryStateCharging();
	static int GetVolumeState();
	static struct FString GetDeviceName();
	static float GetBatteryTemperature();
	static int GetBatteryLevel();
	static bool AreHeadphonesPluggedIn();
};


}

