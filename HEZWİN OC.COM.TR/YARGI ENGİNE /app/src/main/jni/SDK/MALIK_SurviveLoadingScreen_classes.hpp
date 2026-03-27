#pragma once

// PUBG MOBILE (3.8.0) TELEGRAM MALIK:-@K_Y_2  
// GENERATE ON Wed May  7 14:35:32 2025
 
namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// Class SurviveLoadingScreen.SurviveLoadingSettings
// 0x0018 (0x0048 - 0x0030)
class USurviveLoadingSettings : public UDeveloperSettings
{
public:
	TArray<struct FSoftObjectPath>                     Images;                                                   // 0x0030(0x000C) (Edit, ZeroConstructor, Config)
	TArray<struct FSoftObjectPath>                     Videos;                                                   // 0x003C(0x000C) (Edit, ZeroConstructor, Config)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class SurviveLoadingScreen.SurviveLoadingSettings");
		return pStaticClass;
	}

};


}

