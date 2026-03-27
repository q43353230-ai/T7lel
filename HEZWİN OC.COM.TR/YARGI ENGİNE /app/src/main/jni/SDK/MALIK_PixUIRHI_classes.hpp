#pragma once

// PUBG MOBILE (3.8.0) TELEGRAM MALIK:-@K_Y_2  
// GENERATE ON Wed May  7 14:35:34 2025
 
namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// Class PixUIRHI.PxRHIImage
// 0x0004 (0x0020 - 0x001C)
class UPxRHIImage : public UObject
{
public:
	unsigned char                                      UnknownData00[0x4];                                       // 0x001C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class PixUIRHI.PxRHIImage");
		return pStaticClass;
	}


	class UObject* GetHandleObject();
};


// Class PixUIRHI.PxRHIMgr
// 0x0004 (0x0020 - 0x001C)
class UPxRHIMgr : public UObject
{
public:
	unsigned char                                      UnknownData00[0x4];                                       // 0x001C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class PixUIRHI.PxRHIMgr");
		return pStaticClass;
	}


	static bool RHIImageUpdate(class UPxRHIMgr* pPxRHIImage);
	static class UPxRHIMgr* RHIImageFindByObject(class UObject* pCoreObject);
	static bool RHIImageDestroy(class UPxRHIMgr* pPxRHIImage);
	static class UPxRHIImage* RHIImageCreate();
	static class UPxRHIMgr* Get();
};


}

