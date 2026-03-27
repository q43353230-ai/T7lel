#pragma once

// PUBG MOBILE (3.8.0) TELEGRAM MALIK:-@K_Y_2  
// GENERATE ON Wed May  7 14:35:34 2025
 
namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// Class CreativeLua.CreativeBridgeLuaVM
// 0x0020 (0x02A8 - 0x0288)
class UCreativeBridgeLuaVM : public UCreativeLuaVM
{
public:
	unsigned char                                      UnknownData00[0x4];                                       // 0x0288(0x0004) MISSED OFFSET
	struct FString                                     RegisterUGCVMFunctionHandlerName;                         // 0x028C(0x000C) (ZeroConstructor)
	struct FString                                     UGCVMPostInitFunctionHandlerName;                         // 0x0298(0x000C) (ZeroConstructor)
	unsigned char                                      UnknownData01[0x4];                                       // 0x02A4(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class CreativeLua.CreativeBridgeLuaVM");
		return pStaticClass;
	}


	void UGCLuaError(int errCode);
	void RegisterSluaCallUgcluaEventHandler();
	void PostInit();
};


}

