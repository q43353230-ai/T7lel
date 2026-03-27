#pragma once

// PUBG MOBILE (3.8.0) TELEGRAM MALIK:-@K_Y_2  
// GENERATE ON Wed May  7 14:35:32 2025
 
namespace SDK
{
//---------------------------------------------------------------------------
//Enums
//---------------------------------------------------------------------------

// Enum CommonLib.DownloadResult
enum class EDownloadResult : uint8_t
{
	SuccessDownloading             = 0,
	DownloadFailed                 = 1,
	SaveFailed                     = 2,
	DirectoryCreationFailed        = 3,
	DownloadResult_MAX             = 4
};



//---------------------------------------------------------------------------
//Script Structs
//---------------------------------------------------------------------------

// ScriptStruct CommonLib.ServiceCollection
// 0x003C
struct FServiceCollection
{
	TMap<struct FString, class UObject*>               ServiceMap;                                               // 0x0000(0x0050) (ZeroConstructor)
};

}

