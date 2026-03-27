#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>

#include <android/content/Intent.h>



#include "imgui/imgui.h"
#include "Helper/Icon.h"
#include "Helper/Iconcpp.h"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include <Helper/define.h>
#include "Helper/ImguiPP.h"
#include "Helper/Menu.h"
#include "Helper/fake_dlfcn.h"
#include "Helper/Includes.h"
#include "Helper/plthook.h"
#include "Helper/json.hpp"
#include "Helper/StrEnc.h"
#include "Helper/Spoof.h"
#include "Helper/Tools.h"
#include "Helper/obfuscate.h"
//#include "tlshook/common.h"
//#include "tlshook/tlshook.h"
#include "Helper/Dobby/dobby.h"
#include "Helper/Items.h"
#include "Helper/Vector3.hpp"
#include "Helper/ElfImg.h"
#include "Helper/Rect.h"
#include "Substrate/SubstrateHook.h"
#include "patch/MemoryPatch.h"
#include "THUNDER.h"
#include "base64/base64.h"
#include "SDK.hpp"

ImFont* basic = nullptr;
char extras[32];
#include <cstring>
#include <string.h>
bool Logo = true;
float accent_color[4] = { 0.300f, 0.220f, 0.750f, 1.000f };
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
using namespace SDK;
using json = nlohmann::json;
int gScreenWidth;
int gScreenHeight;

static float destination[3] = { 100.0f, 200.0f, 10.0f };
static float rotation[3] = { 0.0f, 0.0f, 0.0f };

// ======================================================================== //
#include <curl/curl.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/md5.h>

//#include <hook/hook.h>

#include "Helper/UE4.h"

#define PATCH_LIB
#define HOOK_LIB_NO_ORIG
#define eglSwapBuffers_32 0x9FFAD54

#define GNames_Offset  0x4ae0120
#define GUObject_Offset 0xa1c35d8
#define ProcessEvent_Offset 0x663584c
#define ProcessEvent_Offset 0x4d49144
#define GNativeAndroidApp_Offset 0x9FF16D0
#define GetActorArray 0x6ad2478
#define ShootEvent_Offset 0x343032c
#define Unlock120Fps_Offset 0x2f99138
#define UnlockHDR_Offset 0x2f98e34
#define Lobby_Skin_Player_Offset 0x359b948
#define eglSwapBuffers  0x71acb9c
#define Actors_Offset 0x70 

#define PostRender  0x69d7224
#define K2_DrawText 0x2aefee4
#define K2_DrawLine 0x6f57c74
#define K2_DrawTexture 0x70063c4

bool deadboxskin;
bool bos2;
bool bos7;
bool SkinHelmetMod;
bool SkinbgMod;
bool BosOlan;
bool CarSkin;
bool SkinMod;
bool bos3;
bool pink = false;
bool show_esp_window = true;
bool show_another_window = true;
bool show_items_window = false;
bool show_aimbot_window = false;
bool show_memory_window = false;
int MenuSkinSelecttt;
bool carskinmenu;
bool weaponskinmenu;
bool suitandolayermenu;
static int helmett3 = 1;
static int bag3 = 1;
int modM4 = 101004;
int modAKM = 101001;
bool SkinEnableTesy;
std::string strSkinTestWeaponIdd;
std::string strSkinTest;
bool autoM = false;
float autoMY = 115.0f;
static int modXsuit = 1400129;
bool ModSkinn = false;
bool KillMessage = false;
bool LobbySkin = false;
bool DeasBoxSkin;
 
int sEmote1 = 2200101;
int sEmote2 = 2200201;
int sEmote3 = 2200301;
bool ModSkinnn = false;
int ModEmote1 = 0;
namespace Active {
  inline int SkinCarDefault = 0;
  inline int SkinCarMod = 0;
  inline int SkinCarNew = 0;
}

android_app *g_App = 0;
#include "jsonPreferences.h"
#include "Menu.h"


static int a = 0;
time_t rng = 0;
static 
std::string expiredDate = " 1st login";
std::string name ="";
std::string deviceSlot = "";
std::string status = "";
std::string floating ="";
std::string g_Token, g_Auth;

static bool WantTextInputLast = false;

ProcMap g_Handle;

struct  MemTrap_t {
  uintptr_t baseAddr;
  uintptr_t endAddr;
};

std::vector<MemTrap_t> MemTraps = std::vector<MemTrap_t>();

bool IsObjectInvalid(UObject *pObject) {
    if (pObject == 0)
        return true;

    for (auto &i : MemTraps) {
        if ((uintptr_t) pObject >= i.baseAddr && (uintptr_t) pObject <= i.endAddr) {
            return true;
        }
    }
    return false;
}




#define targetLibName OBFUSCATE("libanort.so")
bool initImGui = false;
int screenWidth = -1, glWidth, screenHeight = -1, glHeight;
float density = -1;
json items_data;
bool bValid = false;
#define SLEEP_TIME 1000LL / 120LL
uintptr_t anort;
static char s[64];




// ====================================================================== //


uintptr_t UE4;


bool WriteAddr(void *addr, void *buffer, size_t length) {
    unsigned long page_size = sysconf(_SC_PAGESIZE);
    unsigned long size = page_size * sizeof(uintptr_t);
    return mprotect((void *) ((uintptr_t) addr - ((uintptr_t) addr % page_size) - page_size), (size_t) size, PROT_EXEC | PROT_READ | PROT_WRITE) == 0 && memcpy(addr, buffer, length) != 0;
}




// ====================================================================== //

static UEngine *GEngine = 0;
UWorld *GetWorld() {
    while (!GEngine) {
        GEngine = UObject::FindObject<UEngine>("UAEGameEngine Transient.UAEGameEngine_1"); // Auto 
        sleep(1);
    }
    if (GEngine) {
        auto ViewPort = GEngine->GameViewport;

        if (ViewPort) {
   //return {};
            return ViewPort->World;
        }
    }
    return 0;
}

TNameEntryArray *GetGNames() {
    return ((TNameEntryArray *(*)()) (UE4 + GNames_Offset))();
}

std::vector<AActor *> GetActors() {
    auto World = GetWorld();
    if (!World)
        return std::vector<AActor *>();

    auto PersistentLevel = World->PersistentLevel;
    if (!PersistentLevel)
        return std::vector<AActor *>();

    auto Actors = *(TArray<AActor *> *)((uintptr_t) PersistentLevel + Actors_Offset);
     int totalEnemies = 0, totalBots = 0;

    std::vector<AActor *> actors;
    for (int i = 0; i < Actors.Num(); i++) {
        auto Actor = Actors[i];
        if (Actor) {
            actors.push_back(Actor);
        }
    }
    return actors;
}


enum EAim {
  Distance = 0,
  Croshhair = 1
};

enum EAimTarget {
    Head = 0,
    Chest = 1
};

enum EEsp {
  EspTop = 0,
  EspBelow = 1,
  EspNone = 3
  
};

enum ECount {
  Count =0,
  Countb = 1,
  Countc = 2
  
};

enum EAimTrigger {
    None = 0,
    Shooting = 1,
    Scoping = 2,
    Both = 3,
    Any = 4
};

std::map<int, bool> Items;
std::map<int, float *> ItemColors;

static float chestY = 25.0f;
bool BTBUTTON;

struct sConfig {
    int Ipads;
	bool Bypass;
 	float Skill;
	float Skill1;
	float Skill3;
	float Skill4;
	float Skill2;
    float Recc;
	float Line;
	float Prid;
	float Pridd;
	float Skeleton;	
	float Meter;
	float RadarX;
	float RadarY;
    float Loot;
bool Antiban;
bool IgnoreKnocked;
bool VisCheck;
bool IgnoreBots;
bool Linee;
bool Radar;
bool Health;
bool Name;
bool CounterStyle;
bool Distance;
bool TeamID;
bool Weapon;
bool Malik;
bool Malik2;
bool Dbox;
bool LootBox;
bool Ping;
bool LootI;
bool NoBot;
bool Alert;
bool Air;
bool Warning;
bool Genn;
bool ShowVehicle;
bool VehicleFuel;
bool Small;
bool Cross;
bool Ipad;
bool Unlock;
bool Less;
bool Skeletonn;
bool Plane;
bool VehicleHealth;
bool info;
bool autowalljump;
bool autoall;
bool Fovb;
bool GameInfo;
bool bypasss;
bool BypassLogo;
bool SpawanByp;
	
    struct sESPMenu {
        bool Line;
        bool Box;
        bool Skeleton;
        bool island;
        bool Health;
        bool ShowKnockedHealth;
        bool Name;
        bool Distance;
        bool TeamID;
        bool Weapon;
        bool Dbox;
        bool Radar;
        bool Offsc;
        bool Genn;
		
        bool NoBot;
        bool Loot;

		EEsp By;
		ECount Byy;
    };
    sESPMenu ESPMenu;


    struct sHighRisk {
        bool Shake;
        bool Recoil;
        bool Instant;
		bool Ghost;
        bool Para;
        bool Cross;
        bool IPad;
		bool HitEffect;
    };
    sHighRisk HighRisk{0};
    struct sVehicleESP {
        bool ShowVehicle;
        bool ShowDistance;
    };
    sVehicleESP VehicleESP{0};
     struct sSilentAim {
        bool Enable;
        bool AimBot;
		float Cross;
        float Recc;
		EAim By;
        EAimTarget Target;
        EAimTrigger Trigger;
        bool Pred;
        bool ReCo;
        bool IgnoreKnocked;
        bool VisCheck;
		bool IgnoreBots;
		bool Recoil;
    };
    sSilentAim SilentAim{0};
	
	
	
	struct sAimMenu {
        bool Enable;
        bool AimBot;
        bool Malik;
        
        bool Pred;
        float Recc;
		float chestX;
		float Cross;
		float chestY;
		EAim By;
		bool ReCo;
        EAimTarget Target;
        EAimTrigger Trigger;
        bool IgnoreKnocked;
        bool VisCheck;
		bool IgnoreBot;
		bool RecoilComparison;
		
		
    };

    sAimMenu AimBot{0};
	
	
	
	   struct sOTHER {
        bool FPS;
    };
    sOTHER OTHER{0};

    struct sColorsESP {
		float *Text;
	float *Menucolour;
        float *Line;
        float *Box;
		float *Linebot1;
		float *Line1;
		float *Visline;
		float *Boxbot;
        float *Name;
        float *Distance;
        float *Skeleton;
		 float *Skeletonbot;
         float *Skeletonnon;
         float *BotNn;
         float *BotNv;
         float *PotNn;
         float *PotNv;
         
		 float *nonbot;
       //  float *Radar;
		  float *Linebot;
        float *Count;
        float *Vehicle;
		float *Fov;
		float *ImColor;
		float *aimbot;
		
    };
    sColorsESP ColorsESP{0};
};

sConfig Config{0};



// ======================================================================== //
#define CREATE_COLOR(r, g, b, a) new float[4] {(float)r, (float)g, (float)b, (float)a};

// ======================================================================== //
uintptr_t anogs;
uintptr_t g_Anogs;
uintptr_t g_gcloud;
uintptr_t g_swappy;
uintptr_t g_TDataMaster;

//uintptr_t anort;
uintptr_t ANOGS;
//uintptr_t UE4;
uintptr_t g_UE4;
uintptr_t Anogs;
uintptr_t gcloud;
//uintptr_t g_Anogs;
//uintptr_t anogs;
//uintptr_t g_gcloud;
uintptr_t PandoraVideo;
uintptr_t GKPxStudio;
uintptr_t tgpa;
uintptr_t cubehawk;
uintptr_t shared;
uintptr_t INTLFoundation;
uintptr_t INTLCompliance;
uintptr_t CrashSight;
uintptr_t antiban;
uintptr_t GCloudVoice;
uintptr_t ijkffmpeg;
uintptr_t gcloudcore;
uintptr_t gnustl_shared;
uintptr_t igshare;
uintptr_t ITOP;
uintptr_t marsxlog;
uintptr_t swappy;
uintptr_t GvoiceNN;
uintptr_t TDataMaster;
uintptr_t g_cloud;
uintptr_t AimBullet_Offset;
uintptr_t GWorld_Offset, GUObjectArray_Offset, SilentAim_Offset;


ASTExtraPlayerCharacter *g_LocalPlayer = 0;
ASTExtraPlayerController *g_LocalController = 0;

// ======================================================================== //

// ======================================================================== //
struct sRegion {
    uintptr_t start, end;
};

std::vector<sRegion> trapRegions;

bool isObjectInvalid(UObject *obj) {
    if (!Tools::IsPtrValid(obj)) {
        return true;
    }

    if (!Tools::IsPtrValid(obj->ClassPrivate)) {
        return true;
    }

    if (obj->InternalIndex <= 0) {
        return true;
    }

    if (obj->NamePrivate.ComparisonIndex <= 0) {
        return true;
    }

    if ((uintptr_t)(obj) % sizeof(uintptr_t) != 0x0 && (uintptr_t)(obj) % sizeof(uintptr_t) != 0x4) {
        return true;
    }

    if (std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj) >= region.start && ((uintptr_t) obj) <= region.end; }) ||
        std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj->ClassPrivate) >= region.start && ((uintptr_t) obj->ClassPrivate) <= region.end; })) {
        return true;
    }

    return false;
}

template<class T>
void GetAllActors(std::vector<T *> &Actors) {
UGameplayStatics *gGameplayStatics = (UGameplayStatics *) gGameplayStatics->StaticClass();
auto GWorld = GetWorld();
if (GWorld) {
TArray<AActor *> Actors2;
gGameplayStatics->GetAllActorsOfClass((UObject *) GWorld, T::StaticClass(), &Actors2);
for (int i = 0; i < Actors2.Num(); i++) {
Actors.push_back((T *) Actors2[i]);
}
}
}

// ======================================================================== //
std::string getObjectPath(UObject *Object) {
    std::string s;
    for (auto super = Object->ClassPrivate; super; super = (UClass *) super->SuperStruct) {
        if (!s.empty())
            s += ".";
        s += super->NamePrivate.GetName();
    }
    return s;
}


// ======================================================================== //

// ======================================================================== //
//Auto
/*
static UEngine *GEngine = 0;
UWorld *GetWorld() {
    while (!GEngine) {
        GEngine = UObject::FindObject<UEngine>("UAEGameEngine Transient.UAEGameEngine_1"); // Auto 
        sleep(1);
    }
    if (GEngine) {
        auto ViewPort = GEngine->GameViewport;

        if (ViewPort) {
   //return {};
            return ViewPort->World;
        }
    }
    return 0;
}
/*
template<class T>
void GetAllActors(std::vector<T *> &Actors) {
    UGameplayStatics *gGameplayStatics = (UGameplayStatics *) gGameplayStatics->StaticClass();
    auto GWorld = GetWorld();
    if (GWorld) {
        TArray<AActor *> Actors2;
        gGameplayStatics->GetAllActorsOfClass((UObject *) GWorld, T::StaticClass(), &Actors2);
        for (int i = 0; i < Actors2.Num(); i++) {
            Actors.push_back((T *) Actors2[i]);
        }
    }
}
TNameEntryArray *GetGNames()
{
    return ((TNameEntryArray * (*)()) (UE4 + GNames_Offset))();
}*/

std::vector<AActor *> getActors() {
    auto World = GetWorld();
    if (!World)
        return std::vector<AActor *>();
 
    auto PersistentLevel = World->PersistentLevel;
    if (!PersistentLevel)
        return std::vector<AActor *>();
 
    struct GovnoArray {
        uintptr_t base;
        int32_t count;
        int32_t max;
    };
    static thread_local GovnoArray Actors{};
 
    Actors = *(((GovnoArray*(*)(uintptr_t))(UE4 + GetActorArray))(reinterpret_cast<uintptr_t>(PersistentLevel)));
 
    if (Actors.count <= 0) {
        return {};
    }
 
    std::vector<AActor *> actors;
    for (int i = 0; i < Actors.count; i++) {
        auto Actor = *(uintptr_t *) (Actors.base + (i * sizeof(uintptr_t)));
        if (Actor) {
            actors.push_back(reinterpret_cast<AActor *const>(Actor));
        }
    }
    return actors;
}
template<typename T>
void Write(uintptr_t addr, T value) {
    WriteAddr((void *) addr, &value, sizeof(T));
}
// ======================================================================== //


// ======================================================================== //

int32_t ToColor(float *col) {
    return ImGui::ColorConvertFloat4ToU32(*(ImVec4 *) (col));
}
//==//
/*FRotator ToRotator(FVector local, FVector target) {
    FVector rotation = UKismetMathLibrary::Subtract_VectorVector(local, target);
    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);
    FRotator newViewAngle = {0};
    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Roll = (float) 0.f;
    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;
    return newViewAngle;
}*/

    auto protect(uintptr_t addr, size_t len, int32_t prot) {
     static_assert(PAGE_SIZE == 4096);
     constexpr size_t page_size =                static_cast<size_t>(PAGE_SIZE);
    void* start = reinterpret_cast<void*>(addr & -page_size);
    uintptr_t end = (addr + len + page_size - 1) & -page_size;
    return mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
}

#define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(localController, w, true, s)
//=====Aiming======//

bool isInsideFOVs(int x, int y) {
    if (!Config.SilentAim.Cross)
        return true;

    int circle_x = glWidth / 2;
    int circle_y = glHeight / 2;
    int rad = Config.SilentAim.Cross*0.5f;
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}

auto GetTargetForCross() {
   ASTExtraPlayerCharacter *result = 0;
	float max = std::numeric_limits<float>::infinity();
	auto Actors = getActors();
	auto localPlayer = g_LocalPlayer;
	auto localController = g_LocalController;
	if (localPlayer)
	{
		for (auto Actor : Actors)
		{
			if (isObjectInvalid(Actor))
				continue;
			if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass()))
			{
			
			     auto Player = (ASTExtraPlayerCharacter *)Actor;
                auto Target = (ASTExtraPlayerCharacter *) Actor;

               float dist = localPlayer->GetDistanceTo(Target) / 100.0f;    
               if (dist > Config.Meter)
                    continue;

			
			if (Player->PlayerKey == localPlayer->PlayerKey)
					continue;
				if (Player->TeamID == localPlayer->TeamID)
					continue;
				if (Player->bDead)
					continue;
					
					
                              if (Config.SilentAim.IgnoreKnocked) {
                            if (Player->Health == 0.0f)
                                continue;
                        }


                        if (Config.SilentAim.VisCheck) {
                            if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
                                continue;
                        }
                        if (Config.SilentAim.IgnoreBots) {
                            if (Player->bIsAI)
                                continue;
                        }

                auto Root = Player->GetBonePos("Root", {});
				auto Head = Player->GetBonePos("Head", {});
				FVector2D RootSc, HeadPosSC;
				if (W2S(Root, &RootSc) && W2S(Head, &HeadPosSC))
				{
					float height = abs(HeadPosSC.Y - RootSc.Y);
					float width = height * 0.20f;

					FVector middlePoint = {HeadPosSC.X + (width / 2), HeadPosSC.Y + (height / 2), 0};
					if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight))
					{
						FVector2D v2Middle = FVector2D((float)(glWidth / 2), (float)(glHeight / 2));
						FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
						
						
                                if(isInsideFOVs((int)middlePoint.X, (int)middlePoint.Y)) {

                                float dist = FVector2D::Distance(v2Middle, v2Loc);

                                if (dist < max) {
                                    max = dist;
                                    result = Player;
                                }
                              }
                            }
                        }
                    
                
            }
        }
    }

    return result;
}


bool isInsideFOVAim(int x, int y) {
    if (!Config.AimBot.Cross)
        return true;

    int circle_x = glWidth / 2;
    int circle_y = glHeight / 2;
    int rad = Config.AimBot.Cross*0.5f;
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}

auto GetTargetForAimBot() {
   ASTExtraPlayerCharacter *result = 0;
	float max = std::numeric_limits<float>::infinity();
	auto Actors = getActors();
	auto localPlayer = g_LocalPlayer;
	auto localController = g_LocalController;
	if (localPlayer)
	{
		for (auto Actor : Actors)
		{
			if (isObjectInvalid(Actor))
				continue;
			if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass()))
			{
			
			     auto Player = (ASTExtraPlayerCharacter *)Actor;
                auto Target = (ASTExtraPlayerCharacter *) Actor;

               float dist = localPlayer->GetDistanceTo(Target) / 100.0f;    
               if (dist > Config.Meter)
                    continue;

			
			if (Player->PlayerKey == localPlayer->PlayerKey)
					continue;
				if (Player->TeamID == localPlayer->TeamID)
					continue;
				if (Player->bDead)
					continue;
					
					
                              if (Config.AimBot.IgnoreKnocked) {
                            if (Player->Health == 0.0f)
                                continue;
                        }


                        if (Config.AimBot.VisCheck) {
                            if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
                                continue;
                        }
                        if (Config.AimBot.IgnoreBot) {
                            if (Player->bIsAI)
                                continue;
                        }

                        auto Root = Player->GetBonePos("Root", {});
				auto Head = Player->GetBonePos("Head", {});
				FVector2D RootSc, HeadPosSC;
				if (W2S(Root, &RootSc) && W2S(Head, &HeadPosSC))
				{
					float height = abs(HeadPosSC.Y - RootSc.Y);
					float width = height * 0.20f;

					FVector middlePoint = {HeadPosSC.X + (width / 2), HeadPosSC.Y + (height / 2), 0};
					if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight))
					{
						FVector2D v2Middle = FVector2D((float)(glWidth / 2), (float)(glHeight / 2));
						FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
						
						
                                if(isInsideFOVAim((int)middlePoint.X, (int)middlePoint.Y)) {

                                float dist = FVector2D::Distance(v2Middle, v2Loc);

                                if (dist < max) {
                                    max = dist;
                                    result = Player;
                                }
                              }
                            }
                        }
                    
                
            }
        }
    }

    return result;
}

// ======================================================================== //

const char *GetVehicleName(ASTExtraVehicleBase *Vehicle) {
    switch (Vehicle->VehicleShapeType) {
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike_SideCart:
            return "Motorbike";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Dacia:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyDacia:
            return "Dacia";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MiniBus:
            return "Mini Bus";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyPickup:
            return "Pick Up";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Buggy:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyBuggy:
            return "Buggy";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ02:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ03:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUAZ:
            return "UAZ";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PG117:
            return "PG117";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Aquarail:
            return "Aquarail";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado01:
            return "Mirado";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Rony:
            return "Rony";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Scooter:
            return "Scooter";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowMobile:
            return "Snow Mobile";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_TukTukTuk:
            return "Tuk Tuk";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowBike:
            return "Snow Bike";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Surfboard:
            return "Surf Board";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Snowboard:
            return "Snow Board";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Amphibious:
            return "Amphibious";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_LadaNiva:
            return "Lada Niva";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAV:
            return "UAV";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MegaDrop:
            return "Mega Drop";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini01:
            return "Lamborghini";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_GoldMirado:
            return "Gold Mirado";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_BigFoot:
            return "Big Foot";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUH60:
            return "UH60";
            break;
        default:
            return "Vehicle";
            break;
    }
    return "Vehicle";
}

#include "draw.h"
#include "local.h"

void (*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2) = 0;

//bool qwcifqvs86y8fify = false;

void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, ASTExtraShootWeapon *weapon, int unk1) {

        if (Config.SilentAim.Enable) {
        ASTExtraPlayerCharacter *Target = GetTargetForCross();
        if (Target) {
            bool triggerOk = false;
            if (Config.SilentAim.Trigger != EAimTrigger::None) {
                if (Config.SilentAim.Trigger == EAimTrigger::Shooting) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring;
                } else if (Config.SilentAim.Trigger == EAimTrigger::Scoping) {
                    triggerOk = g_LocalPlayer->bIsGunADS;
                } else if (Config.SilentAim.Trigger == EAimTrigger::Both) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring && g_LocalPlayer->bIsGunADS;
                } else if (Config.SilentAim.Trigger == EAimTrigger::Any) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
                }
            } else triggerOk = true;
            if (triggerOk) {
                FVector targetAimPos = Target->GetBonePos("Head", {});
                //if (Config.SilentAim.Target == EAimTarget::Chest) {
                    targetAimPos.Z -= 25.0f;
                //}

                UShootWeaponEntity *ShootWeaponEntityComponent = thiz->ShootWeaponEntityComponent;

				
			
                if (ShootWeaponEntityComponent) {
                    ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                    if (CurrentVehicle) {
                        FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
                    } else {
                        FVector Velocity = Target->GetVelocity();

                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
                    }
                    FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos, start);
                    FRotator sex = UKismetMathLibrary::Conv_VectorToRotator(fDir);
                    rot = sex;
                }
            }
        }
    }

    return orig_shoot_event(thiz, start, rot, weapon, unk1);
}
//=======================================================//

//3D BOX
FRotator ToRotator(FVector local, FVector target) {
    FVector rotation = UKismetMathLibrary::Subtract_VectorVector(local, target);

    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);

    FRotator newViewAngle = {0};
    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Roll = (float) 0.f;

    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;

    return newViewAngle;
}


void Line(ImDrawList *draw,FVector2D origin, FVector2D dest, ImColor color)
{
   draw->AddLine({origin.X, origin.Y},{dest.X, dest.Y},color, 1.0f);
}
bool W2S2(FVector worldPos, FVector2D *screenPos) {
    return g_LocalController->ProjectWorldLocationToScreen(worldPos, true, screenPos);
}


void Box3D(ImDrawList *draw, FVector origin, Vector3 extends, ImColor col) {
    
    origin.X -= extends.X / 2.f;
    origin.Y -= extends.Y / 2.f;
    origin.Z -= extends.Z / 2.f;
 FVector one = origin;
 FVector two = origin; two.X += extends.X;
 FVector tree = origin; tree.X += extends.X; tree.Y += extends.Y;
 FVector four = origin; four.Y += extends.Y;

 FVector five = one; five.Z += extends.Z;
 FVector six = two; six.Z += extends.Z;
 FVector seven = tree; seven.Z += extends.Z;
 FVector eight = four; eight.Z += extends.Z;

    FVector2D s1, s2, s3, s4, s5, s6, s7, s8;
    if (W2S2(one, &s1) && W2S2(two, &s2) && W2S2(tree, &s3) && W2S2(four, &s4) &&
    W2S2(five, &s5) && W2S2(six, &s6) && W2S2(seven, &s7) && W2S2(eight, &s8))
    {
        
    Line(draw,s1, s2, col);
    Line(draw,s2, s3, col);
    Line(draw,s3, s4, col);
    Line(draw,s4, s1, col);
 
    Line(draw,s5, s6, col);
    Line(draw,s6, s7, col);
    Line(draw,s7, s8, col);
    Line(draw,s8, s5, col);
 
    Line(draw,s1, s5, col);
    Line(draw,s2, s6, col);
    Line(draw,s3, s7, col);
    Line(draw,s4, s8, col);

}  
}


//=======================================================//
void DrawESP(ImDrawList *draw) {
ImGui::PushFontShadow(0xFF000000);
if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {
	
	auto Actors = getActors();

    int totalEnemies = 0, totalBots = 0;

    ASTExtraPlayerCharacter *localPlayer = 0;
    ASTExtraPlayerController *localController = 0;




		  if (Config.AimBot.Enable) {
              draw->AddCircle(ImVec2(glWidth / 2.0f, glHeight / 2.0f), Config.AimBot.Cross*0.5f, ToColor(Config.ColorsESP.Fov), 100, 0.f);
           }







			draw->AddText2({((float) density / 10.0f), 50}, IM_COL32(0, 255, 0, 255), OBFUSCATE("TG @SanalOwnerTR"));




    for (int i = 0; i < Actors.size(); i++) {
        auto Actor = Actors[i];
        if (isObjectInvalid(Actor))
            continue;

        if (Actor->IsA(ASTExtraPlayerController::StaticClass())) {
            localController = (ASTExtraPlayerController *) Actor;
            break;
        }
    }

    if (localController) {
        for (int i = 0; i < Actors.size(); i++) {
            auto Actor = Actors[i];
            if (isObjectInvalid(Actor))
                continue;

              if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                if (((ASTExtraPlayerCharacter *) Actor)->PlayerKey == localController->PlayerKey) {
                    localPlayer = (ASTExtraPlayerCharacter *) Actor;
                    break;
                }
            }
        }

        if (localPlayer) {
            if (localPlayer->PartHitComponent) {
                auto ConfigCollisionDistSqAngles = localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
                for (int j = 0; j < ConfigCollisionDistSqAngles.Num(); j++) {
                    ConfigCollisionDistSqAngles[j].Angle = 180.0f;
                }
                localPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
            }

                    static bool bShooting = false;
                 if (Config.SilentAim.Enable) {
					draw->AddCircle(ImVec2(glWidth / 2.0f, glHeight / 2.0f), Config.SilentAim.Cross*0.5f, ToColor(Config.ColorsESP.Fov), 100, 0.f);
                    auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                    if (WeaponManagerComponent) {
                        auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                        if ((int) propSlot.GetValue() >= 1 && (int) propSlot.GetValue() <= 3) {
                            auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                            if (CurrentWeaponReplicated) {
                                auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                if (ShootWeaponComponent) {
                                    int shoot_event_idx = 168;
                                    auto VTable = (void **) ShootWeaponComponent->VTable;
                                    // CHANGE22222 add lambda function f_mprotect
                                    auto f_mprotect = [](uintptr_t addr, size_t len, int32_t prot) -> int32_t {
                                      static_assert(PAGE_SIZE == 4096);
                                      constexpr size_t page_size = static_cast<size_t>(PAGE_SIZE);
                                      void* start = reinterpret_cast<void*>(addr & -page_size);
                                      uintptr_t end = (addr + len + page_size - 1) & -page_size;
                                      return mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
                                    };
                                    if (VTable && (VTable[shoot_event_idx] != shoot_event)) {
                                        orig_shoot_event = decltype(orig_shoot_event)(
                                                VTable[shoot_event_idx]);
                                        // CHANGE22222 add call of f_mprotect
                                        f_mprotect((uintptr_t)(&VTable[shoot_event_idx]), sizeof(uintptr_t), PROT_READ | PROT_WRITE);
                                        VTable[shoot_event_idx] = (void *) shoot_event;
                                    }
                                }
                            }
                       }
                  }
              }
                ///===================== Memory Function ====================//
			if (Config.AimBot.Enable) {
					draw->AddCircle(ImVec2(glWidth / 2.0f, glHeight / 2.0f), Config.AimBot.Cross*0.5f, ToColor(Config.ColorsESP.Fov), 100, 0.f);
                        ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
                        if (Target) {
                            bool triggerOk = false;
							triggerOk = localPlayer->bIsWeaponFiring;
                            
                            if (triggerOk) {
                                FVector targetAimPos = Target->GetBonePos("Head", {});
                                if (Config.AimBot.Target == EAimTarget::Chest) {
                                    targetAimPos.Z -= 50.0f;
                                }

                                auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                                if (WeaponManagerComponent) {
                                    auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                                    if ((int) propSlot.GetValue() >= 1 && (int) propSlot.GetValue() <= 3) {
                                        auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                                        if (CurrentWeaponReplicated) {
                                            auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                            if (ShootWeaponComponent) {
                                                UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
                                                if (ShootWeaponEntityComponent) {
                                                    ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                                                    if (CurrentVehicle) {
                                                        FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

                                                        float dist = localPlayer->GetDistanceTo(Target);
                                                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                                                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
                                                    } else {
                                                        FVector Velocity = Target->GetVelocity();

                                                        float dist = localPlayer->GetDistanceTo(Target);
                                                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                                                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
                                                    }
                                                    localController->SetControlRotation(ToRotator(localController->PlayerCameraManager->CameraCache.POV.Location, targetAimPos), "");
                                                }
             												

                                                
                                                if (Config.AimBot.RecoilComparison) {
                                                    if (g_LocalPlayer->bIsGunADS) {
                                                        if (g_LocalPlayer->bIsWeaponFiring) {
                                                            float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.f;                                                                                 
                                                            targetAimPos.Z -= dist * Config.AimBot.Recc;
                                                        }  
                                                    }
                                                }
                                                localController->SetControlRotation(ToRotator(localController->PlayerCameraManager->CameraCache.POV.Location, targetAimPos), "");
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
			  

                    if (Config.AimBot.Enable) {
                        ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
                   
                    if (Target) {
                        FVector HEAD = Target->GetBonePos("Head", {});
                        
                        ImVec2 HeadPosSC;
                        if (W2S(HEAD, (FVector2D *)&HeadPosSC)) {
                    
                           
                          draw->AddLine({(float) glWidth / 2,  (float) (glHeight / 2)}, HeadPosSC,
                                              IM_COL32(255, 0, 0, 200), 2.0f);
                            
                        }
                      }
                    }
					

				if (Config.Radar) {
                     bool out = false;                              
                     struct Vector3 Pos;
                     Pos.X = screenWidth / 4.395;
                     Pos.Y = screenHeight / 400;
                     struct Vector3 Size;
                     Size.X = 200; //Width of Radar Box.
                     Size.Y = 210; //Height of Radar Box.
                     float RadarCenterX = Pos.X + (Size.X / 2);
                     float RadarCenterY = Pos.Y + (Size.Y / 2);
                     ImColor CircleColor = ImColor(0, 0, 0, 100);
                     ImColor PointColor = ImColor(255, 255, 0, 255);
                     draw->AddLine(ImVec2(RadarCenterX, RadarCenterY), ImVec2(RadarCenterX, Pos.Y), IM_COL32(0, 255, 0, 255), 1.f);
                     draw->AddLine(ImVec2(RadarCenterX, RadarCenterY), ImVec2(Pos.X , RadarCenterY), IM_COL32(0, 255, 0, 255), 1.f);
                     draw->AddLine(ImVec2(Pos.X, RadarCenterY), ImVec2(Pos.X + Size.X, RadarCenterY), IM_COL32(0, 255, 0, 255), 1.f);
                     draw->AddLine(ImVec2(RadarCenterX, RadarCenterY), ImVec2(RadarCenterX, Pos.Y + Size.Y), IM_COL32(0, 255, 0, 255), 1.f);
                                                         
                     draw->AddCircleFilled(ImVec2(RadarCenterX, RadarCenterY), 100.f, CircleColor, 1000); //Background
                     draw->AddCircle(ImVec2(RadarCenterX, RadarCenterY), 100.f, PointColor, 1000); // Circle Around Background
                     draw->AddCircle(ImVec2(RadarCenterX, RadarCenterY), 80.f, PointColor, 1000); // Circle Around Bac
                     draw->AddCircle(ImVec2(RadarCenterX, RadarCenterY), 60.f, PointColor, 1000); // Circle Around Bac
                     draw->AddCircle(ImVec2(RadarCenterX, RadarCenterY), 40.f, PointColor, 1000); // Circle Around Bac
                     draw->AddCircle(ImVec2(RadarCenterX, RadarCenterY), 20.f, PointColor, 1000); // Circle Around Bac
                     draw->AddCircleFilled(ImVec2(RadarCenterX + 0.5f, RadarCenterY + 0.5f), 3.f, PointColor, 1000); // Center of Cross Ci 

                 }

               if (Config.autowalljump)
               {
                   UCharacterMovementComponent *CharacterMovement = localPlayer->CharacterMovement;
                   if (CharacterMovement)
                   {
                       CharacterMovement->MaxStepHeight = 799.9f;
                   }
               }

                FVector ViewPosY{0, 0, 0};
                        if (localPlayer) {
                        ViewPosY = localPlayer->GetBonePos("Head", {});
                        ViewPosY.Z += 360.f;
                         } 
            
				
                     for (int i = 0; i < Actors.size(); i++) {
                auto Actor = Actors[i];
                if (isObjectInvalid(Actor))
                    continue;
					            
 
                            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                            auto Player = (ASTExtraPlayerCharacter *) Actor;					
                            if (isObjectInvalid(Actor))
                            continue;
                            long SCOLOR2 = IM_COL32(245, 233, 0, 255); 
							long SCOLORA = IM_COL32(255, 0, 0, 255);
                            long SCOLOR = IM_COL32(0, 255, 0, 255);
							long SCOLOR1 = IM_COL32(255, 255, 255, 255);
							
							long PlayerBoxClrCf = IM_COL32(255, 255, 255, 255);
					    	long PlayerBoxClrCfline = IM_COL32(255, 255, 255, 255);
					    	long PlayerBoxClrCfbx = IM_COL32(255, 255, 255, 255);
                        
                            if (!localController->LineOfSightTo(Player, {0, 0, 0}, true)) {
                            
							SCOLORA = IM_COL32(10, 250, 250, 255); 
                          //  SCOLOR2 = IM_COL32(10, 250, 250, 255); 
                            SCOLOR = IM_COL32(10, 250, 250, 255); 
							SCOLOR = IM_COL32(10, 250, 250, 255); 
							SCOLOR1 = IM_COL32(10, 250, 250, 255); 
							
							PlayerBoxClrCf = IM_COL32(0, 255, 0, 255);
							PlayerBoxClrCfline = IM_COL32(0, 255, 0, 255);
							PlayerBoxClrCfbx = IM_COL32(0, 255, 0, 255);
							
                            }
                            

                        float Distance = localPlayer->GetDistanceTo(Player) / 100.0f;
                    if (Distance > 500.0f)
                         continue;

                    if (Player->PlayerKey == localController->PlayerKey)
                         continue;

                    if (Player->TeamID == localController->TeamID)
                         continue;

                    if (Player->bDead)
                         continue;
                                
                    if (!Player->RootComponent)
                         continue;							
				   
                        int Colorhealth;
						int healthOutline;
						int radarcolor;
						int ColorEspAlert;
						int alertcol;
                        if (Player->bIsAI)
						   {
                            totalBots++;
							Colorhealth = IM_COL32(0, 255, 0, 120);//143, 242, 212, 110
							ColorEspAlert = IM_COL32(154, 255, 60, 225);
							healthOutline = IM_COL32(255, 255, 255, 255);
							radarcolor = IM_COL32(154, 255, 60, 255);
							alertcol = IM_COL32(0, 255, 0, 200);
						    }
                        else 
						    {
							totalEnemies++;
							Colorhealth = IM_COL32(255, 0, 255, 120);
							ColorEspAlert = IM_COL32(171, 0, 169, 225);
							healthOutline = IM_COL32(255, 255, 255, 255);
							radarcolor = IM_COL32(154, 255, 60, 255);
							alertcol = IM_COL32(255, 0, 255, 200);
							}
                        
                        
                    if (Config.NoBot)
                    if (Player->bIsAI)
                        continue;                  
                            
                     auto HeadPos = Player->GetBonePos("Head", {});
                        ImVec2 HeadPosSC;
					
				 FVector ViewPosY{0, 0, 0};	
			     if (localPlayer) {                   
                 ViewPosY = localPlayer->GetBonePos("Head", {});
                 ViewPosY.Z += 10.f;
                 }
                 
                 if (Config.Radar) {
                      FVector MyPosition;
                      ASTExtraVehicleBase *CurrentVehiclea = Player->CurrentVehicle;
                 if (CurrentVehiclea) {
                      MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                       } else {
                      MyPosition = Player->RootComponent->RelativeLocation;
                       }                                     
                      FVector EnemyPosition;
                      ASTExtraVehicleBase *CurrentVehicle = localPlayer->CurrentVehicle;
                 if (CurrentVehicle) {
                      EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                       }  else {
                      EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                }
               bool out = false;                              
               struct Vector3 Pos;
               Pos.X = screenWidth / 4.395;
               Pos.Y = screenHeight / 400;
               struct Vector3 Size;
               Size.X = 200; //Width of Radar Box.
               Size.Y = 210; //Height of Radar Box.
               float RadarCenterX = Pos.X + (Size.X / 2);
               float RadarCenterY = Pos.Y + (Size.Y / 2);                                    
                                                   
               //bool IsVisible = localController->LineOfSightTo(Player, ViewPosY, true);
               FVector RadarSketch = WorldToRadar(localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, Pos.X, Pos.Y, Vector3(Size.X, Size.Y, 0), out);
              if (Distance >= 0.f) {

               draw->AddCircleFilled(ImVec2(RadarSketch.X, RadarSketch.Y), 5, radarcolor, 0.0f);    
                 
             }
            }
				   
						auto upper_r = Player->GetBonePos("upperarm_r", {});
                        ImVec2 upper_rPoSC;
                        auto lowerarm_r = Player->GetBonePos("lowerarm_r", {});
                        ImVec2 lowerarm_rPoSC;
                        auto hand_r = Player->GetBonePos("hand_r", {});
                        ImVec2 hand_rPoSC;
                        auto upper_l = Player->GetBonePos("upperarm_l", {});
                        ImVec2 upper_lPoSC;
                        auto lowerarm_l = Player->GetBonePos("lowerarm_l", {});
                        ImVec2 lowerarm_lSC;
                        auto hand_l = Player->GetBonePos("hand_l", {});
                        ImVec2 hand_lPoSC;
                        auto thigh_l = Player->GetBonePos("thigh_l", {});
                        ImVec2 thigh_lPoSC;
                        auto calf_l = Player->GetBonePos("calf_l", {});
                        ImVec2 calf_lPoSC;
                        auto foot_l = Player->GetBonePos("foot_l", {});
                        ImVec2 foot_lPoSC;
                        auto thigh_r = Player->GetBonePos("thigh_r", {});
                        ImVec2 thigh_rPoSC;
                        auto calf_r = Player->GetBonePos("calf_r", {});
                        ImVec2 calf_rPoSC;
                        auto foot_r = Player->GetBonePos("foot_r", {});
                        ImVec2 foot_rPoSC;
                        auto neck_01 = Player->GetBonePos("neck_01", {});
                        ImVec2 neck_01PoSC;
                        auto pelvis = Player->GetBonePos("pelvis", {});
                        ImVec2 pelvisPoSC;
                        auto RootPos = Player->GetBonePos("Root", {});
                        ImVec2 RootPosSC;
                        if (W2S(HeadPos, (FVector2D *) &HeadPosSC) &&
                            W2S(upper_r, (FVector2D *) &upper_rPoSC) &&
                            W2S(upper_l, (FVector2D *) &upper_lPoSC) &&
                            W2S(lowerarm_r, (FVector2D *) &lowerarm_rPoSC) &&
                            W2S(hand_r, (FVector2D *) &hand_rPoSC) &&
                            W2S(lowerarm_l, (FVector2D *) &lowerarm_lSC) &&
                            W2S(hand_l, (FVector2D *) &hand_lPoSC) &&
                            W2S(thigh_l, (FVector2D *) &thigh_lPoSC) &&
                            W2S(calf_l, (FVector2D *) &calf_lPoSC) &&
                            W2S(foot_l, (FVector2D *) &foot_lPoSC) &&
                            W2S(thigh_r, (FVector2D *) &thigh_rPoSC) &&
                            W2S(calf_r, (FVector2D *) &calf_rPoSC) &&
                            W2S(foot_r, (FVector2D *) &foot_rPoSC) &&
                            W2S(neck_01, (FVector2D *) &neck_01PoSC) &&
                            W2S(pelvis, (FVector2D *) &pelvisPoSC) &&
                            W2S(RootPos, (FVector2D *) &RootPosSC)) {
				
							
                         if (Config.Linee || Config.autoall) {
                           float boxWidth = density / 1.6f;
                                                boxWidth -= std::min(
                                              ((boxWidth / 2) / 00.0f) * Distance,
                                                boxWidth / 2);
                                                float boxHeight = boxWidth * 0.15f;
												
                                draw->AddLine({(float) glWidth / 2, 105}, {HeadPosSC.x, HeadPosSC.y - (boxHeight * 1.99f)} , IM_COL32(255, 255, 255, 255), 0);
							}
							
				          if (Config.Dbox || Config.autoall) {
                                float boxHeight = abs(HeadPosSC.y - RootPosSC.y);
                                float boxWidth = boxHeight * 0.50f;
                                ImVec2 vStart = {HeadPosSC.x - (boxWidth / 2),
                                                 HeadPosSC.y - (boxHeight * 0.05f)};
                                ImVec2 vEnd = {vStart.x + boxWidth,
                                               vStart.y + boxHeight};

                              draw->AddRect(vStart, vEnd, PlayerBoxClrCfbx, 4.0f);
                                            }
						
								if (Config.Skeletonn || Config.autoall) {
                                                // ESP Head
                                                float boxWidth = 7.f - Distance * 0.03;
                                                draw->AddCircle({HeadPosSC.x, HeadPosSC.y},
                                                                boxWidth,
                                                                PlayerBoxClrCfline,
                                                                0, 1);

                                                //Skeleton
                                                draw->AddLine({upper_rPoSC.x, upper_rPoSC.y},
                                                              neck_01PoSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);
                                                draw->AddLine({upper_lPoSC.x, upper_lPoSC.y},
                                                              neck_01PoSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);

                                                draw->AddLine({upper_rPoSC.x, upper_rPoSC.y},
                                                              lowerarm_rPoSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);
                                                draw->AddLine({lowerarm_rPoSC.x, lowerarm_rPoSC.y},
                                                              hand_rPoSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);

                                                draw->AddLine({upper_lPoSC.x, upper_lPoSC.y},
                                                              lowerarm_lSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);
                                                draw->AddLine({lowerarm_lSC.x, lowerarm_lSC.y},
                                                              hand_lPoSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);

                                                draw->AddLine({thigh_rPoSC.x, thigh_rPoSC.y},
                                                              thigh_lPoSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);

                                                draw->AddLine({thigh_lPoSC.x, thigh_lPoSC.y},
                                                              calf_lPoSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);
                                                draw->AddLine({calf_lPoSC.x, calf_lPoSC.y},
                                                              foot_lPoSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);

                                                draw->AddLine({thigh_rPoSC.x, thigh_rPoSC.y},
                                                              calf_rPoSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);
                                                draw->AddLine({calf_rPoSC.x, calf_rPoSC.y},
                                                              foot_rPoSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);

                                                draw->AddLine({neck_01PoSC.x, neck_01PoSC.y},
                                                              pelvisPoSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);
                                                draw->AddLine({neck_01PoSC.x, neck_01PoSC.y},
                                                              HeadPosSC,
                                                              PlayerBoxClrCf,
                                                              1.0f);

                                            }
                                            
                                          if (Config.Health || Config.autoall) {
                                   int CurHP = (int) std::max(0, std::min((int) Player->Health, (int) Player->HealthMax));
                                    int MaxHP = (int) Player->HealthMax;


long HPColor = IM_COL32(255, 0, 0, 200);
long HPColorS = IM_COL32(0, 255, 0, 200);

                                    if (Player->Health == 0.0f && !Player->bDead) {
                                        HPColor = IM_COL32(255, 255, 0, 130);

                                        CurHP = Player->NearDeathBreath;
                                        if (Player->NearDeatchComponent) {
                                            MaxHP = Player->NearDeatchComponent->BreathMax;
                                        }
                                    }

                                    float boxWidth = density / 6.0f;
                                    boxWidth -= std::min(((boxWidth / 2) / 700.0f) * Distance, boxWidth / 2);
                                    float boxHeight = boxWidth * 0.15f;


                                    ImVec2 vStart = {HeadPosSC.x - (boxWidth / 2), HeadPosSC.y - (boxHeight * 2.5f)};

                                    ImVec2 vEndFilled = {vStart.x + (CurHP * boxWidth / MaxHP), vStart.y + boxHeight};
                                    ImVec2 vEndRect = {vStart.x + boxWidth, vStart.y + boxHeight};
                                    
                                    
           if (Player->bIsAI) {                                       
draw->AddRectFilled(vStart, vEndRect, IM_COL32(0, 0, 0, 150), 0.0f);
draw->AddRectFilled(vStart, vEndFilled, HPColorS, 0.0f);
 
} else {
draw->AddRectFilled(vStart, vEndRect, IM_COL32(0, 0, 0, 150), 0.0f);
draw->AddRectFilled(vStart, vEndFilled, HPColor, 0.0f);

                                }
                                }											

											
							
if (Config.Name || Config.TeamID || Config.autoall) {
                                         
                                                 
                                                   
                              float boxWidth = density / 1.6f;
                              boxWidth -= std::min(((boxWidth / 2) / 00.0f) * Distance,
                              boxWidth / 2);
                              float boxHeight = boxWidth * 0.13f;
                              std::string s;       
  

                                if (Config.TeamID) {
                                        s += "[";
                                        s += std::to_string(Player->TeamID);
                                        s += "] ";
                                    }

                            
                                    if (Config.Name) {
                                    if (Player->Health == 0.0f) {
                                    s += "Knocked";
                                    } else {
                            
                            
                                if (Player->bIsAI) {
                                    s += "RoBot";
                                } else {
                                    s += Player->PlayerName.ToString();
                                }
                            }
                            }
                            
						auto textSize = ImGui::CalcTextSize2(s.c_str(), 0, ((float) density / 30.0f));
                            draw->AddText2(NULL, ((float) density / 26.0f), {HeadPosSC.x - (textSize.x / 2), HeadPosSC.y - (boxHeight * 2.7f)}, IM_COL32(255, 255, 255, 255), s.c_str());
									}                            
                            



							if (Config.Distance || Config.autoall) {
								std::string s;
								s += std::to_string((int)Distance);
								s += "m";
								auto textSize = ImGui::CalcTextSize2(s.c_str(), 0, ((float) density / 30.0f));
								draw->AddText2(NULL, ((float) density / 22.0f), {RootPosSC.x - (textSize.x / 2), RootPosSC.y}, IM_COL32(255, 255, 255, 255), s.c_str());
							
							}
							



                                                    
                                   }//Pos End

                                            
                                   
								  

                       if (Config.Alert) {
						 bool out = false;
                            FVector MyPosition, EnemyPosition;
                            ASTExtraVehicleBase * CurrentVehiclea = Player->CurrentVehicle;
                            if (CurrentVehiclea) {
                                MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                            } else {
                                MyPosition = Player->RootComponent->RelativeLocation;
                            }
                            ASTExtraVehicleBase * CurrentVehicle = localPlayer->CurrentVehicle;
                            if (CurrentVehicle) {
                                EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                            } else {
                                EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                            }
                            FVector EntityPos = WorldToRadar(localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, NULL, NULL, Vector3(glWidth, glHeight, 0), out);
                            FVector angle = FVector();
                            Vector3 forward = Vector3((float)(glWidth / 2) - EntityPos.X, (float)(glHeight / 2) - EntityPos.Y, 0.0f);
                            VectorAnglesRadar(forward, angle);
                            const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);
                            const auto new_point_x = (glWidth / 2) + (55/*alert dist from me*/) / 2 * 8 * cosf(angle_yaw_rad);
                            const auto new_point_y = (glHeight / 2) + (55/*alert dist from me*/) / 2 * 8 * sinf(angle_yaw_rad);
                            std::array<Vector3, 3> points { Vector3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y - ((55) / 4 + 3.5f) / 2, 0.f), Vector3(new_point_x + ((90) / 4 + 3.5f) / 4, new_point_y, 0.f), Vector3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y + ((55) / 4 + 3.5f) / 2, 0.f)};
                            RotateTriangle(points, angle.Y + 180.f);
                            draw->AddTriangle(ImVec2(points.at(0).X, points.at(0).Y), ImVec2(points.at(1).X, points.at(1).Y), ImVec2(points.at(2).X, points.at(2).Y), IM_COL32(0, 0, 0, 80), 1.5f);
                            draw->AddTriangleFilled(ImVec2(points.at(0).X, points.at(0).Y), ImVec2(points.at(1).X, points.at(1).Y), ImVec2(points.at(2).X, points.at(2).Y), alertcol);
                         }
						 
											//paste in main drawing function
                          	if (Config.Weapon) {
								auto WeaponManagerComponent = Player->WeaponManagerComponent;
								if (WeaponManagerComponent) {
								    {
										auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
										if (CurrentWeaponReplicated) {
											auto WeaponId = (int)CurrentWeaponReplicated->GetWeaponID();
											if (WeaponId) {
												std::string s;
												s += CurrentWeaponReplicated->GetWeaponName().ToString();
												auto textSize = ImGui::CalcTextSize(s.c_str(), 0, ((float) density / 30.0f));
												draw->AddText(NULL, ((float) density / 30.0f), {RootPosSC.x - (textSize.x / 2), RootPosSC.y}, IM_COL32(255, 255, 255, 255), s.c_str());
											}
										}
									}
								}
							}
							
                                
                     }
                     
				
				        if (Config.VehicleFuel)
					{
						if (Actors[i]->IsA(ASTExtraVehicleBase::StaticClass()))
						{
							auto Vehicle = (ASTExtraVehicleBase *)Actors[i];
							if (!Vehicle->Mesh)
								continue;
							int CurHP = (int) std::max(0, std::min((int) Vehicle->VehicleCommon->HP, (int) Vehicle->VehicleCommon->HPMax));
                            int MaxHP = (int) Vehicle->VehicleCommon->HPMax;
                            long curHP_Color = IM_COL32(std::min(((510 * (MaxHP - CurHP)) / MaxHP), 255), std::min(((510 * CurHP) / MaxHP), 255), 0, 155);
							float Distance = Vehicle->GetDistanceTo(localPlayer) / 100.f;
							FVector2D vehiclePos;
							if (W2S(Vehicle->K2_GetActorLocation(), &vehiclePos))
							{
								auto mWidthScale = std::min(0.10f * Distance, 50.f);
								auto mWidth = 70.f - mWidthScale;
								auto mHeight = mWidth * 0.15f;
							    if (Config.VehicleFuel)
								{
									std::string sf;
                           sf += "Fuel[";
                           sf += std::to_string((int)(100 * Vehicle->VehicleCommon->Fuel / Vehicle->VehicleCommon->FuelMax));
                                    sf += "]";
                  draw->AddText2(NULL, 15.0f, {vehiclePos.X - (mWidth / 2), vehiclePos.Y + 15.f}, IM_COL32(255, 155, 0, 255), sf.c_str());
						}
						
						            if (Config.VehicleHealth)
                                    {
                                    ImVec2 vStart = {vehiclePos.X - (mWidth / 2), vehiclePos.Y - (mHeight * 1.5f)};
                                    ImVec2 vEndFilled = {vStart.x + (CurHP * mWidth / MaxHP), vStart.y + mHeight};
                                    ImVec2 vEndRect = {vStart.x + mWidth, vStart.y + mHeight};
                                    draw->AddRectFilled(vStart, vEndFilled, curHP_Color, 3.2f, 240);
                                    draw->AddRect(vStart, vEndRect, IM_COL32(255, 255, 255, 50), 3.2f, 240);
						}
					}
				}
			}
			
                      if (Config.ShowVehicle) {
                        if (Actors[i]->IsA(ASTExtraVehicleBase::StaticClass())) {
							auto Vehicle = (ASTExtraVehicleBase *)Actors[i];
							if (!Vehicle->Mesh)
								continue;

							int CurHP = (int) std::max(0, std::min((int) Vehicle->VehicleCommon->HP, (int) Vehicle->VehicleCommon->HPMax));
							int sCurHP = (int) std::max(0, std::min((int) Vehicle->VehicleCommon->Fuel, (int) Vehicle->VehicleCommon->FuelMax));
							int MaxHP = (int) Vehicle->VehicleCommon->HPMax;
							int sMaxHP = (int) Vehicle->VehicleCommon->FuelMax;
							float Distance = Vehicle->GetDistanceTo(localPlayer) / 100.0f;
							if (Distance <= 300.0f) {
								FVector2D vehiclePos;
								if (W2S(Vehicle->K2_GetActorLocation(), &vehiclePos)) {
									auto mWidthScale = std::min(00.0f * Distance, 50.0f);
									auto mWidth = 70.0f - mWidthScale;
									auto mHeight = mWidth * 0.10f;
									auto smWidth = 70.0f - mWidthScale;
									auto smHeight = smWidth * 0.10f;
									if (Config.ShowVehicle) {
										std::string s = GetVehicleName(Vehicle);
										s += " - ";
										s += std::to_string((int)Distance);
										s += "M";
										auto textSize = ImGui::CalcTextSize2(s.c_str(), 0, ((float) density / 30.0f));
										draw->AddText2(NULL, ((float) density / 30.0f), {vehiclePos.X - (mWidth / 2), vehiclePos.Y - 40}, IM_COL32(255, 255, 255, 255), s.c_str());
									}
									if (Config.ShowVehicle) {
										ImVec2 vStart = {vehiclePos.X - (smWidth / 2), vehiclePos.Y - (smHeight * 1.75f)};
										ImVec2 vEndFilled = {vStart.x + (sCurHP * smWidth / sMaxHP), vStart.y + smHeight};
										draw->AddRectFilled(vStart, vEndFilled, IM_COL32(200, 200, 0, 200), 0.0f, 240);
										draw->AddRect(vStart, vEndFilled, IM_COL32(255, 255, 255, 255), 0.0f, 240);
									}
									if (Config.ShowVehicle) {
										ImVec2 vStart = {vehiclePos.X - (mWidth / 2), vehiclePos.Y - (mHeight * 3.00f)};
										ImVec2 vEndFilled = {vStart.x + (CurHP * mWidth / MaxHP), vStart.y + mHeight};
										draw->AddRectFilled(vStart, vEndFilled, IM_COL32(200, 0, 0, 200), 0.0f, 240);
										draw->AddRect(vStart, vEndFilled, IM_COL32(255, 255, 255, 255), 0.0f, 240);
									}
								}
							}
						}
					}
						
					
						
				   if (Config.Plane) {
                    if (Actors[i]->IsA(AAirDropPlane::StaticClass())) {
                        auto AirDropPlane = (AAirDropPlane *) Actors[i];

                        auto RootComponent = AirDropPlane->RootComponent;
                        if (!RootComponent)
                            continue;
                        float Distance = AirDropPlane->GetDistanceTo(localPlayer) / 3000.f;
                        FVector2D AirDropPlanePos;
                        if (W2S(AirDropPlane->K2_GetActorLocation(), &AirDropPlanePos)) {
                            std::string s = "Plane";
                            s += " [";
                            s += std::to_string((int) Distance);
                            s += "M]";
                            draw->AddText2(NULL, ((float) density / 25.0f), {AirDropPlanePos.X, AirDropPlanePos.Y}, IM_COL32(255, 255, 255, 255), s.c_str());

                        }
                    }
                }		
						
						
 		        	if (Config.Genn) {
						if (Actors[i]->IsA(ASTExtraGrenadeBase::StaticClass())) {
							auto Grenade = (ASTExtraGrenadeBase *) Actors[i];
							auto RootComponent = Grenade->RootComponent;
							if (!RootComponent)
								continue;
						float Distance = Grenade->GetDistanceTo(localPlayer) / 70.0f;
							
                  							
							FVector2D grenadePos;
							if (W2S(Grenade->K2_GetActorLocation(), & grenadePos)) {
								std::string s = ICON_FA_BOMB" ";
								s += std::to_string((int) Distance);
								s += "M";
								std::string t;
								t += ICON_FA_BOMB"  Nade Nade Nade.......!   ";
								auto textSize = ImGui::CalcTextSize2(t.c_str(), 0, ((float) density / 15.5f));
								draw->AddText(NULL, ((float) density / 13.0f), ImVec2(glWidth / 2 - (textSize.x / 2), 120), IM_COL32(255, 0, 0, 220), t.c_str());
								draw->AddText(NULL, ((float) density / 25.0f), {grenadePos.X - 10, grenadePos.Y - 10}, IM_COL32(255, 0, 0, 255), s.c_str());
							}
						}
					}
						
			    if (Config.Plane) {
                    if (Actors[i]->IsA(AAirDropBoxActor::StaticClass())) {
                        auto DropBox = (AAirDropBoxActor *) Actors[i];

                        auto RootComponent = DropBox->RootComponent;
                        if (!RootComponent)
                            continue;
                        float Distance = DropBox->GetDistanceTo(localPlayer) / 1000.f;
                        FVector2D DropBoxPos;
                        if (W2S(DropBox->K2_GetActorLocation(), &DropBoxPos)) {
                            std::string s = "AirDrop";
                            s += " [";
                            s += std::to_string((int) Distance);
                            s += "M]";
                            draw->AddText2(NULL, ((float) density / 25.0f), {DropBoxPos.X, DropBoxPos.Y}, IM_COL32(255, 255, 255, 255), s.c_str());

                        }
                    }
                }
                             
			            if (Config.GameInfo || Config.autoall) {     
                                if (Actor->IsA(ASTExtraGameStateBase::StaticClass())) {
                                auto InGame = (ASTExtraGameStateBase *) Actor;
                                std::string s;
  s += "\nMatch ID : ";
  s += std::to_string((int) InGame->GameID);
  s += "\nMode: ";
  s += std::to_string((int) InGame->PlayerNumPerTeam);
 s += "\nPlayers: ";
 s += std::to_string((int) InGame->PlayerNum);
 s += "\nMatch Time : ";
 s += std::to_string((int) InGame->ElapsedTime);
 s += "s | ";
 s += std::to_string((int) InGame->ElapsedTime / 60);
 s += "m";


draw->AddText2({((float) density / 15.0f), 500}, IM_COL32(255, 255, 255, 255),s.c_str());

                            }
                      }
							 
                      if (Config.LootBox) {
                          if (Actors[i]->IsA(APickUpListWrapperActor::StaticClass())) {
                        auto PickUpList = (APickUpListWrapperActor *) Actors[i];

                        //auto RootComponent = PickUpList->RootComponent;
                        if (!PickUpList->RootComponent)
                            continue;

							//auto PickUpDataList2 = *(TArray<FPickUpItemData> *)((uintptr_t) PickUpList + LootBox_Offset); //PickUpItemData[] PickUpDataList;//[Offset
						    auto PickUpDataList2 = (TArray<FPickUpItemData>)PickUpList->GetDataList();
							
                        float Distance = PickUpList->GetDistanceTo(localPlayer) / 100.f;
                        FVector2D PickUpListsPos;
                        if (W2S(PickUpList->K2_GetActorLocation(), &PickUpListsPos)) {
                            std::string s = "Loot Box";
                            s += " [";
                            s += std::to_string((int) Distance);
                            s += "m";
                            draw->AddText(NULL, ((float) density / 25.0f), {PickUpListsPos.X, PickUpListsPos.Y}, IM_COL32(255, 255, 255, 255), s.c_str());
                            
                       if (Config.LootBox)  {
                          if (Distance <= 500.f) {
                               auto mWidthScale = std::min(0.1f * Distance, 35.f);
                               auto boxWidth = 75.f - mWidthScale;
                               auto boxHeight = boxWidth * 0.120f;
                               Rect PlayerRect(PickUpListsPos.X - (boxWidth / 2), PickUpListsPos.Y, boxWidth, boxHeight);       
							   float posY = PickUpListsPos.Y - (PlayerRect.height * 1.00f);
							   
                          for (int j = 0; j < PickUpDataList2.Num(); j++) {
						  
						
                                std::vector<std::string> s2;
                                //std::string itm;
                                uint32_t tc = 0xFF000000;
       
                        //for (auto &category : itemData) {
                          for (auto &item : items_data) {
                          if (item["itemId"] == PickUpDataList2[j].ID.TypeSpecificID) {
                              s2.push_back(item["itemName"].get<std::string>());
                              tc = strtoul(item["itemTextColor"].get<std::string>().c_str(), 0, 16);
                              break;
                              }
                          }
                      //}
                     if (!s2.empty())  {
                     if (PickUpDataList2[j].Count > 1){
                         s2.push_back(" * ");
                         s2.push_back(std::to_string(PickUpDataList2[j].Count));
                     }
                         std::string s3;
                         for (auto &s4 : s2)   {
                              s3 += s4;
                     }
					     
						 
                         draw->AddText2(NULL, ((float) density / 25.0f), {PickUpListsPos.X, posY}, tc, s3.c_str());  
                         posY -= PlayerRect.height * 1.00f;
                         }
                     }
                 }	
             }
          }
       }
   }

                                    if (Actors[i]->IsA(APickUpWrapperActor::StaticClass())) {
                                        auto PickUp = (APickUpWrapperActor *) Actors[i];
                                        if (Items[PickUp->DefineID.TypeSpecificID]) {
                                            auto RootComponent = PickUp->RootComponent;
                                            if (!RootComponent)
                                                continue;

                                            float Distance =
                                                    PickUp->GetDistanceTo(localPlayer) / 100.f;

                                            FVector2D itemPos;
                                            if (W2S(PickUp->K2_GetActorLocation(), &itemPos)) {
                                                std::string s;
                                                uint32_t tc = 0xFF000000;

                                                for (auto &category : items_data) {
                                                    for (auto &item : category["Items"]) {
                                                        if (item["itemId"] ==
                                                            PickUp->DefineID.TypeSpecificID) {
                                                            s = item["itemName"].get<std::string>();
                                                            tc = strtoul(
                                                                    item["itemTextColor"].get<std::string>().c_str(),
                                                                    0,
                                                                    16);
                                                            break;
                                                        }
                                                    }
                                                }

                                                s += " - ";
                                                s += std::to_string((int) Distance);
                                                s += "m";

                                                draw->AddText2(NULL, ((float) density / 25.0f),
                                                              {itemPos.X, itemPos.Y},
                                                              tc, s.c_str());
                                            }
                                        }
                                    }//Item's Esp End
                                    
                                    
                             }
                           }//localplayer

g_LocalController = localController;
g_LocalPlayer = localPlayer;

sprintf(extras, "P : %d", totalEnemies);
ImGui::GetForegroundDrawList()->AddText2({glWidth / 2 - 97.877, 45}, ImColor(255, 0, 0), extras); // Changed to red
sprintf(extras, "B : %d", totalBots);
ImGui::GetForegroundDrawList()->AddText2({glWidth / 2 + 15.330, 45}, ImColor(255, 0, 0), extras); // Changed to red


				
                         }//localcontroller

		
  } //g_auth && g_token
} //Draw Esp

                                    
									
// ======================================================================== //

bool UrlLink;

int OpenURL(const char* url)
{
    JavaVM* java_vm = g_App->activity->vm;
    JNIEnv* java_env = NULL;

    jint jni_return = java_vm->GetEnv((void**)&java_env, JNI_VERSION_1_6);
    if (jni_return == JNI_ERR)
        return -1;

    jni_return = java_vm->AttachCurrentThread(&java_env, NULL);
    if (jni_return != JNI_OK)
        return -2;

    jclass native_activity_clazz = java_env->GetObjectClass(g_App->activity->clazz);
    if (native_activity_clazz == NULL)
        return -3;

    jmethodID method_id = java_env->GetMethodID(native_activity_clazz, "AndroidThunkJava_LaunchURL", "(Ljava/lang/String;)V");
    if (method_id == NULL)
        return -4;
        
    jstring retStr = java_env->NewStringUTF(url);
    java_env->CallVoidMethod(g_App->activity->clazz, method_id, retStr);

    jni_return = java_vm->DetachCurrentThread();
    if (jni_return != JNI_OK)
        return -5;

    return 0;
}


    std::string getClipboardText() {
    if (!g_App)
        return "";

    auto activity = g_App->activity;
    if (!activity)
        return "";

    auto vm = activity->vm;
    if (!vm)
        return "";

    auto object = activity->clazz;
    if (!object)
        return "";

    std::string result;

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
    {
        auto ContextClass = env->FindClass("android/content/Context");
        auto getSystemServiceMethod = env->GetMethodID(ContextClass, "getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;");

        auto str = env->NewStringUTF("clipboard");
        auto clipboardManager = env->CallObjectMethod(object, getSystemServiceMethod, str);
        env->DeleteLocalRef(str);

        auto ClipboardManagerClass = env->FindClass("android/content/ClipboardManager");
        auto getText = env->GetMethodID(ClipboardManagerClass, "getText", "()Ljava/lang/CharSequence;");

        auto CharSequenceClass = env->FindClass("java/lang/CharSequence");
        auto toStringMethod = env->GetMethodID(CharSequenceClass, "toString", "()Ljava/lang/String;");

        auto text = env->CallObjectMethod(clipboardManager, getText);
        if (text) {
            str = (jstring) env->CallObjectMethod(text, toStringMethod);
            result = env->GetStringUTFChars(str, 0);
            env->DeleteLocalRef(str);
            env->DeleteLocalRef(text);
        }

        env->DeleteLocalRef(CharSequenceClass);
        env->DeleteLocalRef(ClipboardManagerClass);
        env->DeleteLocalRef(clipboardManager);
        env->DeleteLocalRef(ContextClass);
    }
    vm->DetachCurrentThread();

    return result;
}


const char *GetAndroidID(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
    jmethodID getContentResolverMethod = env->GetMethodID(contextClass, /*getContentResolver*/ StrEnc("E8X\\7r7ys_Q%JS+L+~", "\x22\x5D\x2C\x1F\x58\x1C\x43\x1C\x1D\x2B\x03\x40\x39\x3C\x47\x3A\x4E\x0C", 18).c_str(), /*()Landroid/content/ContentResolver;*/ StrEnc("8^QKmj< }5D:9q7f.BXkef]A*GYLNg}B!/L", "\x10\x77\x1D\x2A\x03\x0E\x4E\x4F\x14\x51\x6B\x59\x56\x1F\x43\x03\x40\x36\x77\x28\x0A\x08\x29\x24\x44\x33\x0B\x29\x3D\x08\x11\x34\x44\x5D\x77", 35).c_str());
    jclass settingSecureClass = env->FindClass(/*android/provider/Settings$Secure*/ StrEnc("T1yw^BCF^af&dB_@Raf}\\FS,zT~L(3Z\"", "\x35\x5F\x1D\x05\x31\x2B\x27\x69\x2E\x13\x09\x50\x0D\x26\x3A\x32\x7D\x32\x03\x09\x28\x2F\x3D\x4B\x09\x70\x2D\x29\x4B\x46\x28\x47", 32).c_str());
    jmethodID getStringMethod = env->GetStaticMethodID(settingSecureClass, /*getString*/ StrEnc("e<F*J5c0Y", "\x02\x59\x32\x79\x3E\x47\x0A\x5E\x3E", 9).c_str(), /*(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;*/ StrEnc("$6*%R*!XO\"m18o,0S!*`uI$IW)l_/_knSdlRiO1T`2sH|Ouy__^}%Y)JsQ:-\"(2_^-$i{?H", "\x0C\x7A\x4B\x4B\x36\x58\x4E\x31\x2B\x0D\x0E\x5E\x56\x1B\x49\x5E\x27\x0E\x69\x0F\x1B\x3D\x41\x27\x23\x7B\x09\x2C\x40\x33\x1D\x0B\x21\x5F\x20\x38\x08\x39\x50\x7B\x0C\x53\x1D\x2F\x53\x1C\x01\x0B\x36\x31\x39\x46\x0C\x15\x43\x2B\x05\x30\x15\x41\x43\x46\x55\x70\x0D\x59\x56\x00\x15\x58\x73", 71).c_str());

    auto obj = env->CallObjectMethod(context, getContentResolverMethod);
    auto str = (jstring) env->CallStaticObjectMethod(settingSecureClass, getStringMethod, obj, env->NewStringUTF(/*android_id*/ StrEnc("ujHO)8OfOE", "\x14\x04\x2C\x3D\x46\x51\x2B\x39\x26\x21", 10).c_str()));
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceModel(JNIEnv *env) {
    jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("m5I{GKGWBP-VOxkA", "\x0C\x5B\x2D\x09\x28\x22\x23\x78\x2D\x23\x02\x14\x3A\x11\x07\x25", 16).c_str());
    jfieldID modelId = env->GetStaticFieldID(buildClass, /*MODEL*/ StrEnc("|}[q:", "\x31\x32\x1F\x34\x76", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());

    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceBrand(JNIEnv *env) {
    jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("0iW=2^>0zTRB!B90", "\x51\x07\x33\x4F\x5D\x37\x5A\x1F\x15\x27\x7D\x00\x54\x2B\x55\x54", 16).c_str());
    jfieldID modelId = env->GetStaticFieldID(buildClass, /*BRAND*/ StrEnc("@{[FP", "\x02\x29\x1A\x08\x14", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());

    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetPackageName(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
    jmethodID getPackageNameId = env->GetMethodID(contextClass, /*getPackageName*/ StrEnc("YN4DaP)!{wRGN}", "\x3E\x2B\x40\x14\x00\x33\x42\x40\x1C\x12\x1C\x26\x23\x18", 14).c_str(), /*()Ljava/lang/String;*/ StrEnc("VnpibEspM(b]<s#[9cQD", "\x7E\x47\x3C\x03\x03\x33\x12\x5F\x21\x49\x0C\x3A\x13\x20\x57\x29\x50\x0D\x36\x7F", 20).c_str());

    auto str = (jstring) env->CallObjectMethod(context, getPackageNameId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid) {
    jclass uuidClass = env->FindClass(/*java/util/UUID*/ StrEnc("B/TxJ=3BZ_]SFx", "\x28\x4E\x22\x19\x65\x48\x47\x2B\x36\x70\x08\x06\x0F\x3C", 14).c_str());

    auto len = strlen(uuid);

    jbyteArray myJByteArray = env->NewByteArray(len);
    env->SetByteArrayRegion(myJByteArray, 0, len, (jbyte *) uuid);

    jmethodID nameUUIDFromBytesMethod = env->GetStaticMethodID(uuidClass, /*nameUUIDFromBytes*/ StrEnc("P6LV|'0#A+zQmoat,", "\x3E\x57\x21\x33\x29\x72\x79\x67\x07\x59\x15\x3C\x2F\x16\x15\x11\x5F", 17).c_str(), /*([B)Ljava/util/UUID;*/ StrEnc("sW[\"Q[W3,7@H.vT0) xB", "\x5B\x0C\x19\x0B\x1D\x31\x36\x45\x4D\x18\x35\x3C\x47\x1A\x7B\x65\x7C\x69\x3C\x79", 20).c_str());
    jmethodID toStringMethod = env->GetMethodID(uuidClass, /*toString*/ StrEnc("2~5292eW", "\x46\x11\x66\x46\x4B\x5B\x0B\x30", 8).c_str(), /*()Ljava/lang/String;*/ StrEnc("P$BMc' #j?<:myTh_*h0", "\x78\x0D\x0E\x27\x02\x51\x41\x0C\x06\x5E\x52\x5D\x42\x2A\x20\x1A\x36\x44\x0F\x0B", 20).c_str());

    auto obj = env->CallStaticObjectMethod(uuidClass, nameUUIDFromBytesMethod, myJByteArray);
    auto str = (jstring) env->CallObjectMethod(obj, toStringMethod);
    return env->GetStringUTFChars(str, 0);
}

struct MemoryStruct {
    char *memory;
    size_t size;
};
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;

    mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

    std::string Login(const char *user_key) {
    if (!g_App)
        return "Internal Error";

    auto activity = g_App->activity;
    if (!activity)
        return "Internal Error";

    auto vm = activity->vm;
    if (!vm)
        return "Internal Error";

    auto object = activity->clazz;
    if (!object)
        return "Internal Error";

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
    std::string hwid = user_key;
    hwid += GetAndroidID(env, object);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);
    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());
    vm->DetachCurrentThread();
    std::string errMsg;
    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
if (curl) {
        std::string BHATIA = OBFUSCATE ("http://192.168.1.2:5000/connect");
        curl_easy_setopt(curl, CURLOPT_URL ,BHATIA.c_str());

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, /*https*/ StrEnc("!mLBO", "\x49\x19\x38\x32\x3C", 5).c_str());
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, /*Content-Type: application/x-www-form-urlencoded*/ StrEnc("@;Ls\\(KP4Qrop`b#d3094/r1cf<c<=H)AiiBG6i|Ta66s2[", "\x03\x54\x22\x07\x39\x46\x3F\x7D\x60\x28\x02\x0A\x4A\x40\x03\x53\x14\x5F\x59\x5A\x55\x5B\x1B\x5E\x0D\x49\x44\x4E\x4B\x4A\x3F\x04\x27\x06\x1B\x2F\x6A\x43\x1B\x10\x31\x0F\x55\x59\x17\x57\x3F", 47).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        char data[4096];
        sprintf(data, /*game=PUBG&user_key=%s&serial=%s*/ StrEnc("qu2yXK,YkJyGD@ut0.u~Nb'5(:.:chK", "\x16\x14\x5F\x1C\x65\x1B\x79\x1B\x2C\x6C\x0C\x34\x21\x32\x2A\x1F\x55\x57\x48\x5B\x3D\x44\x54\x50\x5A\x53\x4F\x56\x5E\x4D\x38", 31).c_str(), user_key, UUID.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                if (result[/*status*/ StrEnc("(>_LBm", "\x5B\x4A\x3E\x38\x37\x1E", 6).c_str()] == true) {
                    std::string token = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*token*/ StrEnc("{>3Lr", "\x0F\x51\x58\x29\x1C", 5).c_str()].get<std::string>();
                    
                    time_t rng = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*rng*/ StrEnc("+n,", "\x59\x00\x4B", 3).c_str()].get<time_t>();
                     if (rng + 30 > time(0)) {
                        std::string auth = /*PUBG*/ StrEnc("Q*) ", "\x01\x7F\x6B\x67", 4).c_str();;
                        auth += "-";
                        auth += user_key;
                        auth += "-";
                        auth += UUID;
                        auth += "-";
                        auth += /*Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E*/ StrEnc("-2:uwZdV^%]?{{wHs2V,+(^NJU;kC*_{", "\x7B\x5F\x02\x39\x1C\x6D\x31\x3C\x6C\x6F\x30\x4C\x11\x38\x27\x1E\x23\x64\x3C\x5E\x67\x49\x69\x34\x2D\x33\x43\x58\x36\x50\x66\x3E", 32).c_str();
                        std::string outputAuth = Tools::CalcMD5(auth);
     
                        g_Token = token;
                        g_Auth = outputAuth;

                        bValid = g_Token == g_Auth;
						
							expiredDate = result["data"]["EXP"];

status = result ["data"]["mod_status"];
                        deviceSlot = result ["data"]["device"];
                        floating = result ["data"]["credit"];
                        name = result ["data"]["modname"];
						
                        
                    }
                } else {
                    errMsg = result[/*reason*/ StrEnc("LW(3(c", "\x3E\x32\x49\x40\x47\x0D", 6).c_str()].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = "{";
                errMsg += e.what();
                errMsg += "}\n{";
                errMsg += chunk.memory;
                errMsg += "}";
            }
       } else {
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);
    vm->DetachCurrentThread();

    return bValid ? "OK" : errMsg;
}
   




//=================///

// ======================================================================== //
void loadConfig()
{
int fd = open("/data/data/com.tencent.ig/files/Rubel.ini", O_RDONLY);   
read(fd, &Config, sizeof(Config));   
read(fd, &s, sizeof(s));         
close(fd);  
}

void saveConfig()
{   
    int fd = open("/data/data/com.tencent.ig/files/Rubel.ini", O_WRONLY | O_CREAT);
    system("chmod 777 /data/data/com.tencent.ig/files/Rubel.ini");
    write(fd, &Config, sizeof(Config));
	write(fd, &s, sizeof(s));    
    close(fd);
}
void loadCFG(){
loadConfig();
}

void saveCFG(){
saveConfig();
}	

void Logs() 
{

}
void Antiban(){
Logs();
}


// ======================================================================== //

#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))
namespace Settings
{
    static int Tab = 1;
}


// ======================================================================== //


EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
    EGLBoolean _eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
    if (glWidth <= 0 || glHeight <= 0)
    return orig_eglSwapBuffers(dpy, surface);
    if (!g_App)
    return orig_eglSwapBuffers(dpy, surface);
    screenWidth = ANativeWindow_getWidth(g_App->window);
    screenHeight = ANativeWindow_getHeight(g_App->window);
    density = AConfiguration_getDensity(g_App->config);

// ======================================================================== //
	
        if (!initImGui) {
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigWindowsMoveFromTitleBarOnly = true;
    io.FontGlobalScale = 1.2f;

    ImGuiStyle* style = &ImGui::GetStyle();
    style->WindowPadding = ImVec2(12, 12);
    style->FramePadding = ImVec2(12, 8);
    style->ItemSpacing = ImVec2(10, 6);
    style->ItemInnerSpacing = ImVec2(6, 4);
    style->WindowBorderSize = 1.5f;
    style->FrameBorderSize = 1.0f;
    style->FrameRounding = 8.0f;
    style->GrabRounding = 6.0f;
    style->ScrollbarSize = 14.0f;
    style->ScrollbarRounding = 7.0f;
    style->TabRounding = 9.0f;
    style->WindowRounding = 12.0f;
    style->PopupRounding = 8.0f;
    style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style->ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style->ScaleAllSizes(1.3f);

    ImVec4* colors = style->Colors;
    colors[ImGuiCol_Text] = ImColor(255, 255, 255);
    colors[ImGuiCol_TextDisabled] = ImColor(130, 130, 130);
    colors[ImGuiCol_WindowBg] = ImColor(18, 18, 18, 255);
    colors[ImGuiCol_ChildBg] = ImColor(20, 20, 20, 255);
    colors[ImGuiCol_PopupBg] = ImColor(25, 25, 25, 240);
    colors[ImGuiCol_Border] = ImColor(65, 65, 65, 180);
    colors[ImGuiCol_FrameBg] = ImColor(30, 30, 30, 240);
    colors[ImGuiCol_FrameBgHovered] = ImColor(45, 45, 45, 255);
    colors[ImGuiCol_FrameBgActive] = ImColor(60, 60, 60, 255);
    colors[ImGuiCol_TitleBg] = ImColor(28, 28, 28, 255);
    colors[ImGuiCol_TitleBgActive] = ImColor(35, 35, 35, 255);
    colors[ImGuiCol_TitleBgCollapsed] = ImColor(20, 20, 20, 200);
    colors[ImGuiCol_Tab] = ImColor(0, 120, 255, 180);
    colors[ImGuiCol_TabHovered] = ImColor(255, 255, 0, 200);
    colors[ImGuiCol_TabActive] = ImColor(255, 220, 0, 255);
    colors[ImGuiCol_TabUnfocused] = ImColor(35, 35, 35, 120);
    colors[ImGuiCol_TabUnfocusedActive] = ImColor(42, 110, 207, 150);
    colors[ImGuiCol_Button] = ImColor(255, 210, 0, 230);
    colors[ImGuiCol_ButtonHovered] = ImColor(255, 255, 0, 255);
    colors[ImGuiCol_ButtonActive] = ImColor(255, 180, 0, 255);
    colors[ImGuiCol_CheckMark] = ImColor(255, 255, 0, 255);
    colors[ImGuiCol_SliderGrab] = ImColor(255, 255, 0, 255);
    colors[ImGuiCol_SliderGrabActive] = ImColor(255, 220, 0, 255);
    colors[ImGuiCol_Header] = ImColor(255, 255, 0, 100);
    colors[ImGuiCol_HeaderHovered] = ImColor(255, 255, 0, 160);
    colors[ImGuiCol_HeaderActive] = ImColor(255, 255, 0, 200);
    colors[ImGuiCol_Separator] = ImColor(80, 80, 80, 120);
    colors[ImGuiCol_SeparatorHovered] = ImColor(120, 120, 120, 180);
    colors[ImGuiCol_SeparatorActive] = ImColor(140, 140, 140, 255);
    colors[ImGuiCol_ResizeGrip] = ImColor(60, 60, 60, 180);
    colors[ImGuiCol_ResizeGripHovered] = ImColor(90, 90, 90, 220);
    colors[ImGuiCol_ResizeGripActive] = ImColor(110, 110, 110, 255);
    colors[ImGuiCol_ScrollbarBg] = ImColor(30, 30, 30, 150);
    colors[ImGuiCol_ScrollbarGrab] = ImColor(42, 110, 207, 180);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImColor(62, 130, 227, 220);
    colors[ImGuiCol_ScrollbarGrabActive] = ImColor(72, 140, 247, 255);

    ImGui_ImplAndroid_Init();
    ImGui_ImplOpenGL3_Init("#version 300 es");



      //  ImGuiIO &io = ImGui::GetIO();

        io.ConfigWindowsMoveFromTitleBarOnly = true;
        io.IniFilename = NULL;

		//io.Fonts->AddFontFromMemoryTTF((void *)BaiduZY_data, BaiduZY_size, 20.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
        ImFontConfig cfg;
        cfg.SizePixels = ((float) density / 20.0f);
        io.Fonts->AddFontDefault(&cfg);

        memset(&Config, 0, sizeof(sConfig));
		
// ===============================ESPCOLOR ================================== //

         Config.ColorsESP.Line = CREATE_COLOR(255, 0, 0, 255);
		 Config.ColorsESP.Line1 = CREATE_COLOR(255, 255, 255, 255);
		 Config.ColorsESP.Linebot = CREATE_COLOR(255, 0, 0, 255);
		 Config.ColorsESP.Linebot1 = CREATE_COLOR(255, 255, 255, 255);
		 Config.ColorsESP.Skeletonbot = CREATE_COLOR(255, 255, 255, 255);
	     Config.ColorsESP.Boxbot = CREATE_COLOR(255, 255, 255, 255);
         Config.ColorsESP.Box = CREATE_COLOR(255, 0, 0, 255);
         Config.ColorsESP.Name = CREATE_COLOR(255, 0, 0, 255);
         Config.ColorsESP.Distance = CREATE_COLOR(255, 0, 255, 255);
         Config.ColorsESP.Skeleton = CREATE_COLOR(255, 0, 0, 255);
         Config.ColorsESP.Vehicle = CREATE_COLOR(255, 0, 0, 255);
       // Config.ColorsESP.Items = CREATE_COLOR(255, 255, 255, 255);
	     Config.ColorsESP.Fov = CREATE_COLOR(255, 255, 255, 255);
         Config.ColorsESP.aimbot  = CREATE_COLOR(255, 255, 255, 255);
		
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
		initImGui = true;
		
            for (auto &i : items_data) {
            for (auto &item : i["Items"]) {
                int r, g, b;
                sscanf(item["itemTextColor"].get<std::string>().c_str(), "#%02X%02X%02X", &r, &g, &b);
                ItemColors[item["itemId"].get<int>()] = CREATE_COLOR(r, g, b, 255);
            }
        }
        initImGui = true;
		//Config.Logo = true;
	
		loadConfig();
		Logs();
    }
	
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();
    DrawESP(ImGui::GetBackgroundDrawList());
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	
int CounterStyle = 0;
bool CounterStyleEnabled = true;
	
const char* counterStyles[] = {
    "Style 1",
    "Style 2",
    "Style 3",
    "Style 4"
};

// Seçilen öğenin indeksini tutacak değişken (static veya global olabilir)
static int CounterStyleIndex = 0;

static bool YargıGuvenlik = false; 
                            static ImVec4 active = ImColor(158, 158, 158, 255);
		     	static ImVec4 inactive = ImColor(66, 66, 66, 255);
	
	
ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.32f, (float) glHeight * 0.83f), ImGuiCond_Once);  
    
if (ImGui::Begin(OBFUSCATE("YARGI ENGINE ~ PUBG MOBILE 3.8 [ VIP ]")), 0, ImGuiWindowFlags_NoBringToFrontOnFocus) {
	   
    static bool isLogin = false;
static int failedAttempts = 0;
static std::string errorMsg;
static char username[64] = "YARGI - ENGINE";
static char keyInput[128] = "";

if (failedAttempts >= 3) {
  //  MessageBoxA(0, "Too many failed attempts.\nApplication will now close.", "Access Denied", );
    exit(0);
}

if (!isLogin) {
ImGui::TextColored(ImVec4(0.2f, 0.8f, 1.0f, 1.0f), ">>> YARGI ENGINE LOGIN  <<<");
ImGui::Spacing();
ImGui::Text("Secure Login System");
ImGui::Separator();
ImGui::Spacing();

ImGui::InputTextWithHint("##username", "Enter your username...", username, sizeof(username));
ImGui::Spacing();
ImGui::InputTextWithHint("##key", "Enter your license key...", keyInput, sizeof(keyInput), ImGuiInputTextFlags_Password);
ImGui::Spacing();

if (ImGui::Button("Paste Key", ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
    std::string clipboardKey = getClipboardText();
    strncpy(keyInput, clipboardKey.c_str(), sizeof(keyInput) - 1);
    keyInput[sizeof(keyInput) - 1] = '\0';
    YargıGuvenlik = true;
}

ImGui::Spacing();

if (ImGui::Button("Unlock", ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
    if (strlen(keyInput) < 10) {
        errorMsg = "License key too short!";
        failedAttempts++;
    } else {
        errorMsg = Login(keyInput); 
        if (errorMsg == "OK") {
            isLogin = true;
  
        } else {
            failedAttempts++;
        }
    }
}

if (!errorMsg.empty() && errorMsg != "OK") {
    ImGui::Spacing();
    ImGui::TextColored(ImVec4(1, 0.3f, 0.3f, 1), ("Error: " + errorMsg).c_str());
}

} else {


if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {      
	if(YargıGuvenlik){        

            
    if (ImGui::BeginTabBar("MainTabs")) {


        if (ImGui::BeginTabItem("ESP Control")) {
            if (ImGui::BeginTabBar("EspSubTabs")) {

             
                if (ImGui::BeginTabItem("Player")) {
                    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Player Esp:");
                    if (ImGui::BeginTable("PlayerTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {

                    ImGui::TableNextColumn(); ImGui::Checkbox("ESP", &Config.autoall);
                    ImGui::TableNextColumn(); ImGui::Checkbox("Show Line", &Config.Linee);
                    ImGui::TableNextColumn(); ImGui::Checkbox("Show Bone", &Config.Skeletonn);
                    ImGui::TableNextColumn(); ImGui::Checkbox("Show Player Box", &Config.Dbox);
                    ImGui::TableNextColumn(); ImGui::Checkbox("Show Info", &Config.Name);
                    ImGui::TableNextColumn(); ImGui::Checkbox("Health", &Config.Health);
                    ImGui::TableNextColumn(); ImGui::Checkbox("Distance", &Config.Distance);
                    ImGui::TableNextColumn(); ImGui::Checkbox("Screen Warning", &Config.GameInfo);
                    ImGui::TableNextColumn(); ImGui::Checkbox("Grenade Warning", &Config.Genn);
                    ImGui::TableNextColumn(); ImGui::Checkbox("Team ID", &Config.TeamID);
                    ImGui::TableNextColumn(); ImGui::Checkbox("360 Alert", &Config.Alert);
                    ImGui::TableNextColumn(); ImGui::Checkbox("Vehicle Esp", &Config.ShowVehicle);

                        ImGui::EndTable();
                    }

                    ImGui::Separator();
                    ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Counter Style (?)");
                    const char* counterStyles[] = { "Count Style 1", "Count Style 2", "Count Style 3" };
                    ImGui::Combo("##CounterStyle", &CounterStyleIndex, counterStyles, IM_ARRAYSIZE(counterStyles));

                    ImGui::Text("Key expiration date:");
                    ImGui::TextColored(ImVec4(0.0f, 0.6f, 1.0f, 1.0f), "0day 18hours 25minutes 32second");
                    ImGui::EndTabItem();
                }

          
                if (ImGui::BeginTabItem("Items")) {
                    ImGui::Spacing();
                    ImGui::Text("Items ESP settings (dummy placeholder).");
                    for (auto& i : items_data) {
                        if (ImGui::TreeNode(i["Category"].get<std::string>().c_str())) {
                            for (auto& item : i["Items"]) {
                                ImGui::Checkbox(item["itemName"].get<std::string>().c_str(),
                                                (bool*)&Items[item["itemId"].get<int>()]);
                            }
                            ImGui::TreePop();
                        }
                    }
                    ImGui::EndTabItem();
                }

           
                if (ImGui::BeginTabItem("Settings")) {
                    ImGui::Text("Settings Placeholder");
                    ImGui::EndTabItem();
                }

                ImGui::EndTabBar(); 
            }
            ImGui::EndTabItem(); 
        }


        if (ImGui::BeginTabItem("AimSimulation")) {
            if (ImGui::BeginTable("AimSimTable", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
     Config.AimBot.VisCheck = true;
    // Config.AimBot.Recc
     Config.AimBot.RecoilComparison = true;
     						
					//	ImGui::Checkbox("Bullet Track", &Config.SilentAim.Enable);
						ImGui::Checkbox("Aimbot Simulation", &Config.AimBot.Enable);
						
				        ImGui::Spacing();
                        ImGui::SliderFloat("Circle", &Config.AimBot.Cross, 0.0f, 400.0f); 
				    	ImGui::SliderFloat("Meter", &Config.Meter, 0.0f, 120.0f, "%.0f");
						ImGui::SliderFloat("Recoil", &Config.AimBot.Recc, 0.0f, 2.0f);
						ImGui::Spacing();	 
                        static const char *targets[] = {"Head", "Chest"};
                        ImGui::Combo("##Target", (int *) &Config.AimBot.Target, targets, 2, -1);       
                        ImGui::Spacing();	           
                        ImGui::Spacing();	 
		    	        static const char *triggers[] = {"None", "Shooting", "Scoping", "Both ( Shooting / Scoping )", "ANY ( Shooting / Scoping )"};
                        ImGui::Combo("##Trigger", (int *) &Config.AimBot.Trigger, triggers, 5, -1);
                        ImGui::Spacing();	
				        ImGui::Checkbox("Ignore Khocked", &Config.AimBot.IgnoreKnocked);					
                        ImGui::SameLine();

			            ImGui::Checkbox("Igrone Bots", &Config.AimBot.IgnoreBot); 
            ImGui::EndTabItem();
        }


        if (ImGui::BeginTabItem("Skin")) {
            ImGui::Spacing();    
            ImGui::Text("Skin Settings");
            ImGui::Text("  Skin ID :");ImGui::SameLine();
            ImGui::TextColored(ImColor(0, 255, 0, 255), strSkinTestWeaponIdd.c_str());      
        if (ImGui::BeginTable("##ModGun", 1, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
            ImGui::TableSetupColumn("SKIN MOD ENABLE", ImGuiTableColumnFlags_WidthStretch);
            ImGui::TableSetupColumn("KILL-MESSAGE ENABLE", ImGuiTableColumnFlags_WidthStretch);           
            ImGui::TableHeadersRow();
            ImGui::TableNextColumn();        
                        ImGui::Checkbox(OBFUSCATE("Skin-Mod"), &ModSkinn);
                        ImGui::SameLine();
                        ImGui::Checkbox(OBFUSCATE("Kill-Message"), &KillMessage);
                        ImGui::SameLine();
                        ImGui::Checkbox(OBFUSCATE("DeadBox Skin"), &DeasBoxSkin);
                        ImGui::EndTable(); 
                }
                  if (ImGui::BeginTable("##ModGun", 3, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
            ImGui::TableSetupColumn("PLAYER ENABLE", ImGuiTableColumnFlags_WidthStretch);
            ImGui::TableSetupColumn("WEAPON SKIN ENABLE", ImGuiTableColumnFlags_WidthStretch);
            ImGui::TableSetupColumn("CAR SKIN ENABLE", ImGuiTableColumnFlags_WidthStretch);
            ImGui::TableHeadersRow();
            ImGui::TableNextColumn();        
                        ImGui::RadioButton(OBFUSCATE("PLAYER"), &MenuSkinSelecttt, 0);
               ImGui::TableNextColumn();    
              ImGui::RadioButton(OBFUSCATE("WEAPON"), &MenuSkinSelecttt, 1);
              ImGui::TableNextColumn(); 
              ImGui::RadioButton(OBFUSCATE("CAR"), &MenuSkinSelecttt, 2);
              ImGui::EndTable(); 
                }

            


                      
                  if (MenuSkinSelecttt == 0) {
                      suitandolayermenu = true;
                      
                      weaponskinmenu = false;
                            carskinmenu = false;
             
                      }
                      
                  if (MenuSkinSelecttt == 1) {
                      weaponskinmenu = true;
                      carskinmenu = false;
                      suitandolayermenu = false;
           
                      }
                          if (MenuSkinSelecttt == 2) {
                      carskinmenu = true; 
                      
                      suitandolayermenu = false;
                      
                      weaponskinmenu = false;
                      
           
                      }
                      if (ModSkinn){
                        if (suitandolayermenu) {
                            
                            
                            
                        preferences.Outfit = true;
                        preferences.Parachute = true;
                        preferences.Emote = true;
                        preferences.Helmett = true;
                        preferences.Bagg = true;
                        preferences.Face = true;
                        
                    if (ImGui::BeginTable("##ModGun", 2, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
            ImGui::TableSetupColumn(" Xsuit Skin Name", ImGuiTableColumnFlags_WidthStretch);
            ImGui::TableSetupColumn("Edit Skin", ImGuiTableColumnFlags_WidthStretch);
          
            ImGui::TableHeadersRow();
            
            ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("X-SUIT & SET SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* xsuity[] = { "NO SKIN", "Golden Pharaoh X-Suit", "Blood Raven X-Suit", "Poseidon X-Suit", "Avalanche X-suit", "Silvanus X-suit", "Iridescence X-suit", "Arcane Jester X-Suit", "Stygian Liege X-Suit", "Marmoris X-Suit ", "Fiore X-Suit  ", "Infected Patient", "Bape Full set ", "Mummy (Yellow) " , "Psychophage Set   ", "Mummy (White) ", "Glacial Bride Set ", "Crimson Ephialtes Set ", "Dimwalker Set  ", "Godzilla Set  ","Gon Character Set  "};
                                    ImGui::Combo("##xs", &preferences.Config.Skin.XSuits, xsuity, IM_ARRAYSIZE(xsuity));
                                
                    start = std::chrono::high_resolution_clock::now();
                    callFunction = true;
                    prevXSuits = preferences.Config.Skin.XSuits;
                    
                
                
                    ImGui::TableNextColumn();
                    ImGui::Text(OBFUSCATE("BackPack SKIN "));
                    ImGui::TableNextColumn();;                   
                    const char* bgg[] = { "NO SKIN", "Pharaoh Backpack", "Blood Raven Backpack", "The Fool BackPack", "Luminous Galaxy BackPack", "Poseidon BackPack", "GACKT MOONSAGA BackPack", "Godzilla BackPack","Frosty Snowglobe BackPack"};
                    ImGui::Combo("##Bag", &preferences.bag, bgg, IM_ARRAYSIZE(bgg));
                    
                    
                    ImGui::TableNextColumn();
                    ImGui::Text(OBFUSCATE("Helmets SKIN "));
                    ImGui::TableNextColumn();          
                    const char* hmm[] = { "NO SKIN", "Inferno Rider", "Scarlet Beast", "Glacier", "Gold and Silk", "Mutated", "Intergalactic", "Masked Psychic", "First Love ", "Atlantic Tech"};
                    ImGui::Combo("##Helmet", &preferences.helmet, hmm, IM_ARRAYSIZE(hmm));
                    
                    
                    
                    ImGui::TableNextColumn();
                    ImGui::Text(OBFUSCATE("Emote "));
                    ImGui::TableNextColumn();;                   
                    const char* emt[] = { "NO Emote", "Emote 1", "Emote 2", "Emote 3", "Emote 4", "Emote 5", "Emote 6", "Emote 7","Emote 8"};
                    ImGui::Combo("##emote", &ModEmote1, emt, IM_ARRAYSIZE(emt));
                    
                    ImGui::TableNextColumn();
                    ImGui::Text(OBFUSCATE("Parachute SKIN "));
                    ImGui::TableNextColumn();;                   
                    const char* prt[] = { "NO SKIN", "Pharaoh's Scarab Parachute", "Enigmatic Nomad Parachute", "Poseidon Parachute", "Paperfold Gambit Parachute", "Labyrinth Beast Parachute", "Flamewraith Parachute", "Mega Kitty Parachute","Mega Yeti Parachute",  "Endless Glory Parachute", "Magma Skull Parachute", "Aquatic Fury Parachute", "CyberGen: Zero Parachute", "Radiant Phoenix Adarna Parachute", "Will of Horus Parachute", "Anubian Magistrate Parachute"};
                    ImGui::Combo("##Parachute", &preferences.Config.Skin.Parachute, prt, IM_ARRAYSIZE(prt));
                    }
                ImGui::EndTable(); 
                }
            
                        }
                        if  (weaponskinmenu) {
                            preferences.AWM = true;
                            preferences.DP28 = true;
                            preferences.M249 = true;
                            preferences.UZI = true;
                            preferences.UMP = true;
                            preferences.TOMMY = true;
                            preferences.VECTOR = true;
                            preferences.BIZON = true;
                            preferences.PAN = true;
                            preferences.M416 = true;
                            preferences.AKM = true;
                            preferences.SCARL = true;
                            preferences.M762 = true;
                            preferences.GROZA = true;
                            preferences.AUG = true;
                            preferences.M16 = true;
                            preferences.ACE32 = true;
                            preferences.KAR98 = true;
                            preferences.M24 = true;
                            

                    if (ImGui::BeginTable("##ModGun", 2, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
            ImGui::TableSetupColumn(" Weapon Skin Name", ImGuiTableColumnFlags_WidthStretch);
            ImGui::TableSetupColumn("Edit Skin", ImGuiTableColumnFlags_WidthStretch);
        
            ImGui::TableHeadersRow();
              ImGui::TableNextColumn();
                                    
                                    ImGui::Text(OBFUSCATE("M416 SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* m416[] = { "NO SKIN", "Glacier - M416", "The Fool - M416","Wanderer - M416","Lizard Roar - M416","Call of the Wild - M416", "TechnoCore - M416", "Imperial Splendor - M416", "Silver Guru - M416","Tidal Embrace - M416 ", "Shinobi Kami - M416 "};
                                    ImGui::Combo("##m4", &preferences.Config.Skin.M416, m416, IM_ARRAYSIZE(m416));
                                    
                            
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("AKM SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* AKM[] = { "NO SKIN", "Glacier - AKM", "Desert Fossil - AKM","Jack-o'-lantern - AKM","Ghillie Dragon - AKM","Gold Pirate - AKM","Codebreaker - AKM","Wandering Tyrant - AKM", "Starsea Admiral - AKM","Bunny Munchkin - AKM","Decisive Day - AKM"};
                                    ImGui::Combo("##AKM", &preferences.Config.Skin.AKM, AKM, IM_ARRAYSIZE(AKM));
                                    
                                   
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("SCAR-L SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* scr[] = { "NO SKIN", "Water Blaster - SCAR-L", "Enchanted Pumpkin - SCAR-L","Operation Tomorrow - SCAR-L","Hextech Crystal - SCAR-L ","Thorn of Malice - SCAR-L","Bloodstained Nemesis - SCAR-L", "Folly's Clasp - SCAR-L "};
                                    ImGui::Combo("##scar", &preferences.Config.Skin.Scar, scr, IM_ARRAYSIZE(scr));
                                    
                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("M762 SKIN"));
                                    ImGui::TableNextColumn();;
                                    const char* mya[] =  {"NO SKIN", "8-bit Unicorn - M762", "Concerto of Love - M762","Deadly Precision - M762",  "Stray Rebellion - M762","Starcore - M762","Messi Football Icon - M762","Noctum Sunder - M762"};
                                    ImGui::Combo("##M762", &preferences.Config.Skin.M762, mya, IM_ARRAYSIZE(mya));
                                    
                                    
                                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("GROZA SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* gyz[] =  {"NO SKIN", "Forest Raider - GROZA", "Eventide Aria - Groza","Ryomen Sukuna - GROZA","Splendid Battle - GROZA","River Styx - Groza","Pumpkin Carol - Groza"};
                                    ImGui::Combo("##GROZA", &preferences.Config.Skin.Groza, gyz, IM_ARRAYSIZE(gyz));
                                    
                                    
                                    
                                    ImGui::TableNextColumn();                               
                                    ImGui::Text(OBFUSCATE("AUG SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* asd[] =  {"NO SKIN", "Wandering Circus - AUG","Evangelion 4th Angel - AUG","Forsaken Glace - AUG"};
                                    ImGui::Combo("##AUG", &preferences.Config.Skin.AUG, asd, IM_ARRAYSIZE(asd));
                                    
                                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("M16A4 SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* moa[] =  {"NO SKIN", "Blood & Bones - M16A4", "Aurora Pulse - M16A4","Radiant Edge - M16A4","Skeletal Core - M16A4","Dracoguard - M16A4"};
                                    ImGui::Combo("##M16A4", &preferences.Config.Skin.M16A4, moa, IM_ARRAYSIZE(moa));
                                    
                                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("ACE32 SKIN "));
                                    ImGui::TableNextColumn();
                                    const char* acs[] =  {"NO SKIN", "Beam Blast - ACE32 ","Icicle Spike - ACE32"};
                                    ImGui::Combo("##ACE", &preferences.Config.Skin.ACE32, acs, IM_ARRAYSIZE(acs));            
                                    
                                    
                                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("KAR98K SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* lkh[] =  {"NO SKIN", "Terror Fang - Kar98K", "Kukulkan Fury - Kar98K","Moonlit Grace - Kar98K","Titanium Shark - Kar98K","Nebula Hunter - Kar98K","Violet Volt - Kar98K"};
                                    ImGui::Combo("##KAR98K", &preferences.Config.Skin.K98, lkh, IM_ARRAYSIZE(lkh));
                                    
                                    
                                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("M24 SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* myd[] =  {"NO SKIN", "The Seven Seas - M24", "Pharaoh's Might - M24","Lady Butterfly - M24","Circle of Life - M24","Cadence Maestro - M24"};
                                    ImGui::Combo("##M24", &preferences.Config.Skin.M24, myd, IM_ARRAYSIZE(myd));
                                    
                                    
                                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("AWM SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* ahy[] =  {"NO SKIN", "Mauve Avenger - AWM", "Field Commander - AWM","Godzilla - AWM","Rainbow Drake - AWM","Flamewave - AWM"};
                                    ImGui::Combo("##AWM", &preferences.Config.Skin.AWM, ahy, IM_ARRAYSIZE(ahy));
                                    
                                    
                                    
                                    ImGui::TableNextColumn();      
                                    ImGui::Text(OBFUSCATE("DP28 SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* dpp[] =  {"NO SKIN", "Enigmatic Hunter - DP28", "Gilded Jade Dragon - DP28","Nautical Warrior - DP-28","Shenron - DP-28"};
                                    ImGui::Combo("##DP", &preferences.Config.Skin.DP28, dpp, IM_ARRAYSIZE(dpp));
                                    
                                    
                                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("M249 SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* mkk[] =  {"NO SKIN", "Winter Queen - M249", "Party Parcel - M249 V","Moondrop Eterna - M249","Stargaze Fury - M249"};
                                    ImGui::Combo("##M249", &preferences.Config.Skin.M249, mkk, IM_ARRAYSIZE(mkk));
                                    
                                    
                                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("UZI SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* uzy[] = { "NO SKIN", "Savagery - UZI", "Ethereal Emblem - UZI","Romantic Moments - UZI","Shimmer Power - UZI","Mystech - UZI","Juicer - UZI"};
                                    ImGui::Combo("##UZI", &preferences.Config.Skin.UZI, uzy, IM_ARRAYSIZE(uzy));
                                    
                                    
                                    
                                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("UMP SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* umy[] = { "NO SKIN", "Dragonfire - UMP45", "Outlawed Fantasy - UMP45","8-Bit Blast - UMP45","Rainbow Stinger - UMP45","Marine Evolution - UMP45","Carnival Waves - UMP45","Cryofrost Shard - UMP45"};
                                    ImGui::Combo("##UMP", &preferences.Config.Skin.UMP, umy, IM_ARRAYSIZE(umy));
                                    
                                    
                                    
                                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("Thompson SKIN "));
                                    ImGui::TableNextColumn();
                                    const char* tho[] =  {"NO SKIN", "Candy Cane - Thompson","Steampunk - Thompson "};
                                    ImGui::Combo("##Thompson", &preferences.Config.Skin.Thompson, tho, IM_ARRAYSIZE(tho));            
                                    
                                    
                                    
                                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("BIZON SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* bzy[] =  {"NO SKIN", "Blazing Chameleon - PP-19 Bizon", "Skullcrusher - PP-19 Bizon","Soldier Soul - PP-19 Bizon"};
                                    ImGui::Combo("##BIZON", &preferences.Config.Skin.Bizon, bzy, IM_ARRAYSIZE(bzy));
                                    
                                    
                                    
                                    
                                    ImGui::TableNextColumn();
                                    ImGui::Text(OBFUSCATE("PAN SKIN"));
                                    ImGui::TableNextColumn();
                                    const char* pnh[] = { "NO SKIN", "Glacier - PAN", "Night of Rock - PAN","Crocodile - PAN","Accolade - PAN","Break Pad - PAN","Chicken Hot - PAN","Faerie Luster - PAN","Anniversary - PAN","Olive Branch - PAN"};
                                    ImGui::Combo("##Pan", &preferences.Config.Skin.Pan, pnh, IM_ARRAYSIZE(pnh));
                                    }
                    ImGui::EndTable(); 
                        }
                        
                        
                        
                        if (carskinmenu) {
                            preferences.Boat = true;
                            preferences.MiniBus = true;
                            preferences.Buggy = true;
                            preferences.Mirado = true;
                            preferences.BigFoot = true;
                            preferences.Moto = true;
                            preferences.UAZ = true;
                            preferences.CoupeRB = true;
                            preferences.Dacia = true;
                            
                            

    if (ImGui::BeginTable("##ModGun", 2, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
        ImGui::TableSetupColumn("Car Skin Name", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("Edit Skin", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableHeadersRow();

        // DACIA
        ImGui::TableNextColumn();
        ImGui::Text(OBFUSCATE("DACIA SKIN"));
        ImGui::TableNextColumn();
        const char* pou[] = {
            "NO SKIN", "Koenigsegg Gemera (Dawn)", "Lamborghini Estoque Oro", "Tesla Roadster (Diamond)",
            "Pumpkin Dacia", "Castle Dacia", "Speedy Reindeer Dacia", "Zombie Mess Dacia",
            "Dodge Charger SRT Hellcat - Fuchsia", "Dodge Charger SRT Hellcat - Tuscan Torque",
            "Dodge Charger SRT Hellcat Jailbreak - Violet Venom", "Koenigsegg Gemera (Silver Gray)",
            "Koenigsegg Gemera (Rainbow)", "Tesla Roadster (Amethyst)", "Tesla Roadster (Digital Water)",
            "Lamborghini Estoque Metal Grey", "Ghost Rosa", "Ghost Violet", "Ghost Gleam",
            "Midknight Dacia (Lv. 4)"
        };
        ImGui::Combo("##dac", &preferences.Config.Skin.Dacia, pou, IM_ARRAYSIZE(pou));

        // Coupe RB
        ImGui::TableNextColumn();
        ImGui::Text(OBFUSCATE("Coupe RB SKIN"));
        ImGui::TableNextColumn();
        const char* cou[] = {
            "NO SKIN", "Lamborghini Aventador SVJ Blue", "Bugatti La Voiture Noire (Nebula)", "Warp Dawn",
            "Koenigsegg Jesko (Dawn)", "McLaren 570S (Zenith Black)", "McLaren 570S (Lunar White)",
            "Aston Martin Valkyrie (Racing Green)", "Aston Martin Valkyrie (Luminous Diamond)",
            "McLaren 570S (Raspberry)", "McLaren 570S (Glory White)", "McLaren 570S (Royal Black)",
            "McLaren 570S (Pearlescent)", "Koenigsegg Jesko (Silver Gray)", "Koenigsegg Jesko (Rainbow)",
            "Lamborghini Aventador SVJ Verde Alceo", "Lamborghini Centenario Galassia", "Lamborghini Centenario Carbon Fiber",
            "Koenigsegg One:1 Gilt", "Koenigsegg One:1 Cyber Nebula", "Koenigsegg One:1 Jade", "Koenigsegg One:1 Phoenix",
            "Warp Green", "Warp Universe", "Dodge Challenger SRT Hellcat - Blaze", "Dodge Challenger SRT Hellcat - Lime",
            "Maserati MC20 Bianco Audace", "Maserati MC20 Rosso Vincente", "Maserati MC20 Sogni",
            "Bugatti Veyron 16.4 (Shining)", "Bugatti Veyron 16.4 (Gold)", "Bugatti Veyron 16.4",
            "Bugatti La Voiture Noire", "Bugatti La Voiture Noire (Alloy)", "Bugatti La Voiture Noire (Warrior)",
            "Dodge Challenger SRT Hellcat Jailbreak - Hellfire", "Pagani Zonda R (Tricolore Carbon)",
            "Pagani Zonda R (Bianco Benny)", "Pagani Zonda R (Melodic Midnight)", "Pagani Imola (Grigio Montecarlo)",
            "Pagani Imola (Crystal Clear Carbon)", "Pagani Imola (Nebula Dream)", "Pagani Imola (Arctic Aegis)"
        };
        ImGui::Combo("##Coupe", &preferences.Config.Skin.CoupeRP, cou, IM_ARRAYSIZE(cou));

        // UAZ
        ImGui::TableNextColumn();
        ImGui::Text(OBFUSCATE("UAZ SKIN"));
        ImGui::TableNextColumn();
        const char* uazz[] = {
            "NO SKIN", "Lamborghini Urus Giallo Inti", "Cute Kitten UAZ", "Godzilla UAZ (Lv. 3)", "Robust Wild",
            "Lamborghini Urus Pink", "Maserati Levante Blu Emozione", "Maserati Luce Arancione",
            "Maserati Levante Neon Urbano", "Maserati Levante Firmamento", "Aston Martin DBX707 (Neon Purple)",
            "Aston Martin DBX707 (Quasar Blue)", "Dodge Hornet - Scarlet Sting", "Dodge Hornet GLH Concept - Redline",
            "Dodge Hornet - Sunburst", "Armed UAZ"
        };
        ImGui::Combo("##uaz", &preferences.Config.Skin.UAZ, uazz, IM_ARRAYSIZE(uazz));

        // Moto
        ImGui::TableNextColumn();
        ImGui::Text(OBFUSCATE("MotoBike"));
        ImGui::TableNextColumn();
        const char* motoo[] = {
            "NO SKIN", "DUCATI Panigale V4S", "Ducati Panigale V4S Black Phantom", "Ducati Panigale V4S Crimson Storm",
            "Phantom Motorcycle (Lv. 7)", "LINE FRIENDS Lovey Dovey 2-Seat Motorcycle (Lv. 4)",
            "Ducati Panigale V4S Swift Mirage", "Roaring Tiger Motorcycle (Lv. 3)", "Skeleton Chariot (Lv. 3)"
        };
        ImGui::Combo("##moto", &preferences.Config.Skin.Moto, motoo, IM_ARRAYSIZE(motoo));

        // Boat
        ImGui::TableNextColumn();
        ImGui::Text(OBFUSCATE("Boat SKIN"));
        ImGui::TableNextColumn();
        const char* foot[] = {
            "NO SKIN", "Imperial Gold Speedboat", "Lifesaver Speedboat", "Chicken Speedboat", "Hungry Shark Speedboat",
            "The Seven Seas Speedboat", "Neko Sakura Speedboat", "Pineapple Speedboat", "Cute Penguin Speedboat",
            "Armored Carrier", "Kong Team Speedboat"
        };
        ImGui::Combo("##Bigfoot", &preferences.Config.Skin.Boat, foot, IM_ARRAYSIZE(foot));

        // Mirado
        ImGui::TableNextColumn();
        ImGui::Text(OBFUSCATE("Mirado SKIN"));
        ImGui::TableNextColumn();
        const char* rado[] = { "NO SKIN", "Armored Hunter Mirado" };
        ImGui::Combo("##OMirado", &preferences.Config.Skin.Mirado, rado, IM_ARRAYSIZE(rado));

        // Buggy
        ImGui::TableNextColumn();
        ImGui::Text(OBFUSCATE("Buggy SKIN"));
        ImGui::TableNextColumn();
        const char* uggy[] = {
            "NO SKIN", "Ceratops Blitz Buggy (Lv. 4)", "Ancient Guardian Buggy", "Bowknot Buggy",
            "Lifesaver Buggy", "Black Magma Buggy", "Naughty Christmas Buggy", "Off-road Buggy", "Street Art Buggy"
        };
        ImGui::Combo("##Buggy", &preferences.Config.Skin.Buggy, uggy, IM_ARRAYSIZE(uggy));

        // MiniBus
        ImGui::TableNextColumn();
        ImGui::Text(OBFUSCATE("MiniBus SKIN"));
        ImGui::TableNextColumn();
        const char* mini[] = {
            "NO SKIN", "Winning Chicken Bus", "Tsunami Bus", "Wrestling Bus", "Cartoon Chicken Bus",
            "Roaring Grizzly Bus", "Ice Cream Bus"
        };
        ImGui::Combo("##miniB", &preferences.Config.Skin.MiniBus, mini, IM_ARRAYSIZE(mini));

        // YARGI ENGINE
        ImGui::TableNextColumn();
        ImGui::Text(OBFUSCATE("YARGI ENGINE SKIN"));
        ImGui::TableNextColumn();
        const char* bgyuz[] = { "NO SKIN", "Jovial Tread YARGI ENGINE" };
        ImGui::Combo("##bg77", &preferences.Config.Skin.Bigfoot, bgyuz, IM_ARRAYSIZE(bgyuz));
                ImGui::EndTable();
            }
            ImGui::EndTabItem();
        }

    /*    
        if (ImGui::BeginTabItem("Settings")) {
            ImGui::Text("Settings Options Here");
            ImGui::EndTabItem();
        }

        
        if (ImGui::BeginTabItem("Items")) {
            ImGui::Text("Items ESP as main tab");
            ImGui::EndTabItem();
        }*/

        ImGui::EndTabBar();

    }
}
ImGui::End();

               }//Login
             }
             }
			 }
             
             
ImGui::End();
ImGui::Render();
ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
return orig_eglSwapBuffers(dpy, surface);
                }     
                void (*orig_onInputEvent)(void *inputEvent, void *ex_ab, void *ex_ac);
                void onInputEvent(void *inputEvent, void *ex_ab, void *ex_ac) {
                orig_onInputEvent(inputEvent, ex_ab, ex_ac);
                if (initImGui) {
                ImGui_ImplAndroid_HandleInputEvent((AInputEvent*)inputEvent, {(float) screenWidth / (float) glWidth, (float) screenHeight / (float) glHeight});
                }}  

void *(*oProcessEvent)(UObject *pObj, UFunction *pFunc, void *pArgs);
void *hkProcessEvent(UObject *pObj, UFunction *pFunc, void *pArgs) {
  if (pFunc) {
        if (pFunc->GetFullName() == "Function Engine.HUD.ReceiveDrawHUD") {
            AHUD *pHUD = (AHUD *)pObj;
            if (pHUD) {
                auto Params = (AHUD_ReceiveDrawHUD_Params *)pArgs;
                if (Params) {
                    RenderESP(pHUD, Params->SizeX, Params->SizeY);
                }
            }
        }
    }
if( std::string(pFunc->GetFullName().c_str()).find("BackpackBlueprintUtils_BP.BackpackBlueprintUtils_BP_C.CreateBattleItemHandle") != std::string::npos ) {
UBackpackUtils_CreateBattleItemHandle_Params *PARAMS = ( UBackpackUtils_CreateBattleItemHandle_Params * ) pArgs;
strSkinTestWeaponIdd = std::to_string((int)PARAMS->DefineID.TypeSpecificID);}
if (std::string(pFunc->GetFullName().c_str()).find("BackpackBlueprintUtils_BP.BackpackBlueprintUtils_BP_C.CreateBattleItemHandle") != std::string::npos)
{
UBackpackUtils_CreateBattleItemHandle_Params *PARAMS = ( UBackpackUtils_CreateBattleItemHandle_Params * ) pArgs;
std::string strWeaponId = std::to_string((int)PARAMS->DefineID.TypeSpecificID);
std::string strHelmet = std::to_string((int)PARAMS->DefineID.TypeSpecificID);
std::string strBackPack = std::to_string((int)PARAMS->DefineID.TypeSpecificID);
}
    
    if (DeasBoxSkin) {
    if( std::string(pObj->GetName().c_str()).find("DeadBoxAvatarComponent") != std::string::npos ) {
   UDeadBoxAvatarComponent *DeadBoxPointer = ( UDeadBoxAvatarComponent *) pObj; 
    if( std::string(pFunc->GetFullName().c_str()).find("GetLuaFilePath") != std::string::npos ) {
    uint32_t Key = DeadBoxPointer->IsSelf();              
    auto GWorld = GetWorld();
    if (GWorld){
        if (GWorld->NetDriver->ServerConnection)
            if(GWorld->NetDriver->ServerConnection->PlayerController){
    ASTExtraPlayerController *g_PlayerController = (ASTExtraPlayerController *)GWorld->NetDriver->ServerConnection->PlayerController;
    ASTExtraPlayerCharacter *g_LocalPlayer = (ASTExtraPlayerCharacter *)g_PlayerController->AcknowledgedPawn;
                if(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated){
if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M416")){        
if (preferences.M416 == 1) 
DeadBoxPointer->ChangeItemAvatar(new_Skin.M416_1, true); //Glacier - M416 

}
if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "AKM")){
if (preferences.AKM == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.AKM, true); //Sculpture - AKM


}
if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "SCAR")){
if (preferences.SCARL == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.Scar, true); //Sculpture - AKM

}
if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M762")){
if (preferences.M762 == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.M762, true); //Sculpture - AKM

}
if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "GROZA")){
if (preferences.GROZA == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.Groza, true); //Sculpture - AKM

}
if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "UZI")){
if (preferences.UZI == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.UZI, true); //Sculpture - AKM

}
if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M16A4")){
if (preferences.M16 == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.M16A4, true); //Sculpture - AKM

}
if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "UMP45")){
if (preferences.UMP == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.UMP, true); //Sculpture - AKM

}
if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "ACE32")){
if (preferences.ACE32 == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.ACE32, true); //Sculpture - AKM

}
if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "AWM")){
if (preferences.AWM == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.AWM, true); //Sculpture - AKM

}
if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M24")){
if (preferences.M24 == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.M24, true); //Sculpture - AKM

}

if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "AWM")){
if (preferences.M249 == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.M249, true); //Sculpture - AKM

}
if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "DP28")){
if (preferences.DP28 == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.DP28, true); //Sculpture - AKM

}

if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "AUG")){
if (preferences.AUG == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.AUG, true); //Sculpture - AKM
}

if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "KAR")){
if (preferences.KAR98 == 1)
DeadBoxPointer->ChangeItemAvatar( new_Skin.K98, true); //Sculpture - AKM

}}}}}}}
    return oProcessEvent(pObj, pFunc, pArgs);
}


#define SLEEP_TIME 1000LL / 60LL

[[noreturn]] void *maps_thread(void *) {
    while (true) {

        auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        std::vector<sRegion> tmp;
        char line[512];
        FILE *f = fopen("/proc/self/maps", "r");
        if (f) {
            while (fgets(line, sizeof line, f)) {
                uintptr_t start, end;
                char tmpProt[16];
                if (sscanf(line, "%" PRIXPTR "-%" PRIXPTR " %16s %*s %*s %*s %*s", &start, &end, tmpProt) > 0) {
                    if (tmpProt[0] != 'r') {
                        tmp.push_back({start, end});
                    }
                }
            }
            fclose(f);
        }
        trapRegions = tmp;

        auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
        std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
    }
}



    
void *main_thread(void *) {

    UE4 = Tools::GetBaseAddress("libUE4.so");
    while (!UE4) {
        UE4 = Tools::GetBaseAddress("libUE4.so");
        sleep(1);
    }

    anogs = Tools::GetBaseAddress("libanogs.so");
    while (!anogs) {
        anogs = Tools::GetBaseAddress("libanogs.so");
        sleep(1);
    }

    g_gcloud = Tools::GetBaseAddress("libgcloud.so");
    while (!g_gcloud) {
        g_gcloud = Tools::GetBaseAddress("libgcloud.so");
        sleep(1);
    }

    anort = Tools::GetBaseAddress("libanort.so");
    while (!anort) {
        anort = Tools::GetBaseAddress("libanort.so");
        sleep(1);
    }

    TDataMaster = Tools::GetBaseAddress("libTDataMaster.so");
    while (!TDataMaster) {
        TDataMaster = Tools::GetBaseAddress("libTDataMaster.so");
        sleep(1);
    }


    while (!g_App) {
        g_App = *(android_app **)(UE4 + GNativeAndroidApp_Offset);
        sleep(1);
    }


    FName::GNames = GetGNames();
    while (!FName::GNames) {
        FName::GNames = GetGNames();
        sleep(1);
    }


    UObject::GUObjectArray = (FUObjectArray *)(UE4 + GUObject_Offset);

    // input hook (initializeMotionEvent)
    void *input = dlopen_ex("libinput.so", 4);
    while (!input) {
        input = dlopen_ex("libinput.so", 4);
        sleep(1);
    }

    void *initMotionEvent = dlsym_ex(input, "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE");
    if (initMotionEvent) {
        HOOK(initMotionEvent, onInputEvent, &orig_onInputEvent);
    }
    dlclose_ex(input);


    Tools::Hook((void *)eglSwapBuffers_32, (void *)_eglSwapBuffers, (void **)&orig_eglSwapBuffers);
    Tools::Hook((void *)DobbySymbolResolver("/system/lib/libEGL.so", "eglSwapBuffers"), (void *)_eglSwapBuffers, (void **)&orig_eglSwapBuffers);

    uintptr_t eglSwapAddr = (uintptr_t)dlsym(RTLD_NEXT, "eglSwapBuffers");
    if (eglSwapAddr != 0 && eglSwapAddr != (uintptr_t)nullptr) {
        LOGD("eglSwapBuffers başarıyla bulundu: 0x%X", eglSwapAddr);
        HOOK((void *)eglSwapAddr, _eglSwapBuffers, &orig_eglSwapBuffers);
    } else {
        LOGD("eglSwapBuffers adresi bulunamadı.");
    }


    Tools::Hook((void *)(UE4 + ProcessEvent_Offset), (void *)hkProcessEvent, (void **)&oProcessEvent);


    Tools::Hook((void *)(UE4 + 0x31FB8E4), (void *)shoot_event, (void **)&orig_shoot_event);


    items_data = json::parse(ITEMS);


    pthread_t maps;
    pthread_create(&maps, 0, maps_thread, 0);

    return 0;
}

__attribute__((constructor)) void _init() {
    pthread_t t;
    pthread_create(&t, NULL, main_thread, NULL);
}
