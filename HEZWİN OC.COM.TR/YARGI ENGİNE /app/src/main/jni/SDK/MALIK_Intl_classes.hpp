#pragma once

// PUBG MOBILE (3.8.0) TELEGRAM MALIK:-@K_Y_2  
// GENERATE ON Wed May  7 14:35:32 2025
 
namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// Class Intl.StatManager
// 0x0144 (0x0160 - 0x001C)
class UStatManager : public UObject
{
public:
	unsigned char                                      UnknownData00[0x144];                                     // 0x001C(0x0144) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Intl.StatManager");
		return pStaticClass;
	}


	void ReportUAStatsEvent(TArray<struct FString> InReportChannels, const struct FString& InEventName, TMap<struct FString, struct FString> InParams, bool InIsRealTime);
	void ReportRevenue(int InPurchaseEventType, const struct FString& InCurrencyCode, const struct FString& InExpense, TMap<struct FString, struct FString> InParams, const struct FString& InExtraJson);
	void ReportPurchase(int InPurchaseEventType, const struct FString& InCurrencyCode, const struct FString& InExpense, bool isRealTime);
	void ReportEventWithString(int EventType, const struct FString& _eventBody, bool isRealTime);
	void ReportEventWithParam(int EventType, TMap<struct FString, struct FString> _params, bool isRealTime);
	void ReportEventWithNoParam(int EventType, bool isRealTime);
	static class UStatManager* GetInstance();
};


}

