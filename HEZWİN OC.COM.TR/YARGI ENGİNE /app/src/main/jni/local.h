void RenderESP(AHUD *HUD, int SizeX, int SizeY) {
  updateSkin();
        ASTExtraPlayerCharacter *localPlayer = 0;
        ASTExtraPlayerController *localPlayerController = 0;

        
        UCanvas *Canvas = HUD->Canvas;
        if (Canvas) {

            
            UGameplayStatics *gGameplayStatics = (UGameplayStatics *) UGameplayStatics::StaticClass();
            auto GWorld = GetWorld();
            if (GWorld) {
                UNetDriver *NetDriver = GWorld->NetDriver;
                if (NetDriver) {
                    UNetConnection *ServerConnection = NetDriver->ServerConnection;
                    if (ServerConnection) {
                        localPlayerController = (ASTExtraPlayerController *) ServerConnection->PlayerController;
                    }
                }

                if (localPlayerController) {
                     
                    std::vector<ASTExtraPlayerCharacter *> PlayerCharacter;
                    GetAllActors(PlayerCharacter);
                    for (auto actor = PlayerCharacter.begin();
                         actor != PlayerCharacter.end(); actor++) {
                        auto Actor = *actor;

                        if (Actor->PlayerKey ==
                            ((ASTExtraPlayerController *) localPlayerController)->PlayerKey) {
                            localPlayer = Actor;
                            break;
                        }
                    }
                    {
if (localPlayer) {                          
if (ModSkinn){
if (KillMessage) {
int pController = 979;
auto VTable = (void **) g_LocalController->VTable;
auto f_mprotect = [](uintptr_t addr, size_t len, int32_t prot) -> int32_t {
static_assert(PAGE_SIZE == 4096);
constexpr
size_t page_size = static_cast<size_t>(PAGE_SIZE);
void *start = reinterpret_cast<void *>(addr &-page_size);
uintptr_t end = (addr + len + page_size - 20) & -page_size;
return mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
};
if (VTable && (VTable[pController] != hk_Broadcast)) {
orig_Broadcast = decltype(orig_Broadcast)(VTable[pController]);
f_mprotect((uintptr_t)(&VTable[pController]), sizeof(uintptr_t), PROT_READ | PROT_WRITE);
VTable[pController] = (void *) hk_Broadcast;
}
}
if (localPlayer->WeaponManagerComponent != 0) {
if (localPlayer->WeaponManagerComponent->CurrentWeaponReplicated != 0) {
int weapowep = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponID();
auto currentTime = std::chrono::steady_clock::now();
auto& landchud = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->synData;
auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastWeaponChangeTime).count();
if (timeDiff > 1000) {
for (int j = 0; j < landchud.Num(); j++) {
auto& weaponInfo = landchud[j];
auto weaponid = weaponInfo.DefineID.TypeSpecificID;
if (weaponid != 0) {
				 if (preferences.AKM && weapowep == 101001){
				 for (int i = 0; i < sizeof(akmv) / sizeof(akmv[0]); i++) {
                 if (weaponid == akmv[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AKM;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(akmmag) / sizeof(akmmag[0]); i++) {
                 if (weaponid == akmmag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AKM_Mag;
                     break;
                  }
				 }
				}
				if (preferences.KAR98 && weapowep == 103001){
				 for (int i = 0; i < sizeof(kar) / sizeof(kar[0]); i++) {
                 if (weaponid == kar[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.K98;
                     break;
                  }
				 }
				}
				if (preferences.M24 && weapowep == 103002){
				 for (int i = 0; i < sizeof(m24) / sizeof(m24[0]); i++) {
                 if (weaponid == m24[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M24;
                     break;
                  }
				 }
				}
				if (preferences.AWM && weapowep == 103003){
				 for (int i = 0; i < sizeof(awm) / sizeof(awm[0]); i++) {
                 if (weaponid == awm[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AWM;
                     break;
                  }
				 }
				}
				
				
				if (preferences.TOMMY && weapowep == 102004){
				 for (int i = 0; i < sizeof(tommy) / sizeof(tommy[0]); i++) {
                 if (weaponid == tommy[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Thompson;
                     break;
                  }
				 }
				}
				if (preferences.ACE32 && weapowep == 101102){
				 for (int i = 0; i < sizeof(ace32) / sizeof(ace32[0]); i++) {
                 if (weaponid == ace32[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.ACE32;
                     break;
                  }
				 }
				}
				
				if (preferences.BIZON && weapowep == 102005){
				 for (int i = 0; i < sizeof(bizon) / sizeof(bizon[0]); i++) {
                 if (weaponid == bizon[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Bizon;
                     break;
                  }
				 }
				}
				/*
				if (preferences.VECTOR && weapowep == 102003){
				 for (int i = 0; i < sizeof(vector) / sizeof(vector[0]); i++) {
                 if (weaponid == vector[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Vector;
                     break;
                  }
				 }
				}*/
				if (preferences.UMP && weapowep == 102002){
				 for (int i = 0; i < sizeof(ump) / sizeof(ump[0]); i++) {
                 if (weaponid == ump[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.UMP;
                     break;
                  }
				 }
				}
				if (preferences.UZI && weapowep == 102001){
				 for (int i = 0; i < sizeof(uzi) / sizeof(uzi[0]); i++) {
                 if (weaponid == uzi[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.UZI;
                     break;
                  }
				 }
				}
				if (preferences.M16 && weapowep == 101002){
				 for (int i = 0; i < sizeof(m16) / sizeof(m16[0]); i++) {
                 if (weaponid == m16[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(m16s) / sizeof(m16s[0]); i++) {
                 if (weaponid == m16s[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4_Stock;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(m16mag) / sizeof(m16mag[0]); i++) {
                 if (weaponid == m16mag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4_Mag;
                     break;
                  }
				 }
				}
				if (preferences.PAN && weapowep == 108004){
				 for (int i = 0; i < sizeof(pan) / sizeof(pan[0]); i++) {
                 if (weaponid == pan[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Pan;
                     break;
                  }
				 }
				}
				if (preferences.AUG && weapowep == 101006){
				 for (int i = 0; i < sizeof(aug) / sizeof(aug[0]); i++) {
                 if (weaponid == aug[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AUG;
                     break;
                  }
				 }
				}
				if (preferences.GROZA && weapowep == 101005){
				 for (int i = 0; i < sizeof(groza) / sizeof(groza[0]); i++) {
                 if (weaponid == groza[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Groza;
                     break;
                  }
				 }
				}
				if (preferences.DP28 && weapowep == 105002){
				 for (int i = 0; i < sizeof(dp) / sizeof(dp[0]); i++) {
                 if (weaponid == dp[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.DP28;
                     break;
                  }
				 }
				}
				if (preferences.M249 && weapowep == 105001){
				 for (int i = 0; i < sizeof(m249) / sizeof(m249[0]); i++) {
                 if (weaponid == m249[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M249;
                     break;
                  }
				 }
				}
				
				if (preferences.SCARL && weapowep == 101003){
				 for (int i = 0; i < sizeof(scar) / sizeof(scar[0]); i++) {
                 if (weaponid == scar[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Scar;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(scarmag) / sizeof(scarmag[0]); i++) {
                 if (weaponid == scarmag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Scar_Mag;
                     break;
                  }
				 }
				}
				
				if (preferences.M762 && weapowep == 101008){
				 for (int i = 0; i < sizeof(m7) / sizeof(m7[0]); i++) {
                 if (weaponid == m7[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M762;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(m7mag) / sizeof(m7mag[0]); i++) {
                 if (weaponid == m7mag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M762_Mag;
                     break;
                  }
				 }
				}
				
				if (preferences.M416 && weapowep == 101004){
				 for (int i = 0; i < sizeof(m4v) / sizeof(m4v[0]); i++) {
                 if (weaponid == m4v[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_1;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(m4mag) / sizeof(m4mag[0]); i++) {
                 if (weaponid == m4mag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_2;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(m4sight) / sizeof(m4sight[0]); i++) {
                 if (weaponid == m4sight[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_3;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(m4stock) / sizeof(m4stock[0]); i++) {
                 if (weaponid == m4stock[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_4;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(m4stock1) / sizeof(m4stock1[0]); i++) {
                 if (weaponid == m4stock1[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_stock;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(m4reddot) / sizeof(m4reddot[0]); i++) {
                 if (weaponid == m4reddot[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_reddot;
                     break;
                  }
				 }
				}
                 localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->DelayHandleAvatarMeshChanged();
                 lastWeaponChangeTime = currentTime;
             }
         }
     }
 }
}
//

if (localPlayer -> CurrentVehicle) {
        if (localPlayer -> CurrentVehicle -> VehicleAvatar) {
          std::string SkinIDStr = std::to_string((int) localPlayer -> CurrentVehicle -> VehicleAvatar -> GetDefaultAvatarID());
          Active::SkinCarDefault = localPlayer -> CurrentVehicle -> GetAvatarID();

		  
          if (preferences.Moto && strstr(SkinIDStr.c_str(), "1901")) {
            Active::SkinCarMod = new_Skin.Moto;
            Active::SkinCarNew = true;
          } else if (preferences.Dacia && strstr(SkinIDStr.c_str(), "1903")) {
            Active::SkinCarMod = new_Skin.Dacia;
            Active::SkinCarNew = true;
          } else if (preferences.Boat && strstr(SkinIDStr.c_str(), "1911")) {
            Active::SkinCarMod = new_Skin.Boat;
            Active::SkinCarNew = true;
          } else if (preferences.MiniBus && strstr(SkinIDStr.c_str(), "1904")) {
            Active::SkinCarMod = new_Skin.MiniBus;
            Active::SkinCarNew = true;
          } else if (preferences.Mirado && strstr(SkinIDStr.c_str(), "1914")) {
            Active::SkinCarMod = new_Skin.Mirado;
            Active::SkinCarNew = true;
          } else if (preferences.Mirado && strstr(SkinIDStr.c_str(), "1915")) {
            Active::SkinCarMod = new_Skin.Mirado;
            Active::SkinCarNew = true;
          } else if (preferences.Buggy && strstr(SkinIDStr.c_str(), "1907")) {
            Active::SkinCarMod = new_Skin.Buggy;
            Active::SkinCarNew = true;
          }else if (preferences.CoupeRB && strstr(SkinIDStr.c_str(), "1961")) {
            Active::SkinCarMod = new_Skin.CoupeRP;
            Active::SkinCarNew = true;
          } else if (preferences.BigFoot && strstr(SkinIDStr.c_str(), "1953")) {
            Active::SkinCarMod = new_Skin.Bigfoot;
            Active::SkinCarNew = true;
          } else if (preferences.UAZ && strstr(SkinIDStr.c_str(), "1908")) {
            Active::SkinCarMod = new_Skin.UAZ;
            Active::SkinCarNew = true;
          } else Active::SkinCarNew = false;

          if (Active::SkinCarDefault != Active::SkinCarMod && Active::SkinCarNew) {
            
            localPlayer -> CurrentVehicle -> VehicleAvatar -> ChangeItemAvatar(Active::SkinCarMod, true);
          }
        }
      }

 if (localPlayerController->BackpackComponent){
	 auto data = localPlayerController->BackpackComponent->ItemListNet;
	 auto bag = data.IncArray;
	 for (int j = 0; j < bag.Num(); j++) {
	 int ID = bag[j].Unit.DefineID.TypeSpecificID;
	 if (preferences.Outfit){
 for (int i = 0; i < sizeof(SuitX) / sizeof(SuitX[0]); i++) {
                 if (ID == SuitX[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = new_Skin.XSuits;
                     break;
                  }
				 }
				}
				if (preferences.Bagg){
for (int i = 0; i < sizeof(Bag) / sizeof(Bag[0]); i++) {
                 if (ID == Bag[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = bag3;
                     break;
                  }
				 }
				}
				if (preferences.Helmett){
for (int i = 0; i < sizeof(Helmet) / sizeof(Helmet[0]); i++) {
                 if (ID == Helmet[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = helmett3;
                     break;
                  }
				 }
				}
				if (preferences.Emote){
for (int i = 0; i < sizeof(emote1) / sizeof(emote1[0]); i++) {
                 if (ID == emote1[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = sEmote1;
                     break;
                  }
				 }
for (int i = 0; i < sizeof(emote2) / sizeof(emote2[0]); i++) {
                 if (ID == emote2[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = sEmote2;
                     break;
                  }
				 }
for (int i = 0; i < sizeof(emote3) / sizeof(emote3[0]); i++) {
                 if (ID == emote3[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = sEmote3;
                     break;
                  }
				 }
				}
				if (preferences.PAN){
				 for (int i = 0; i < sizeof(pan) / sizeof(pan[0]); i++) {
                 if (ID == pan[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = new_Skin.Pan;
                     break;
                    }
				  }
				}
            }
        }

 if (localPlayer->AvatarComponent2) {
   auto AvatarComp = localPlayer -> AvatarComponent2;
   auto NetAvatarComp = * (FNetAvatarSyncData * )((uintptr_t) AvatarComp + 0x2a8);
   auto Slotsybc = NetAvatarComp.SlotSyncData;
        if (preferences.Parachute){
        Slotsybc[9].ItemId = new_Skin.Parachute;
        }
        if (preferences.Outfit){
        Slotsybc[2].ItemId = new_Skin.XSuits;
        }
        if (preferences.Bagg){
        Slotsybc[5].ItemId = bag3;
        }
        if (preferences.Helmett){
        Slotsybc[6].ItemId = helmett3;
        }
  auto now = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();

if (elapsed < 400 && callFunction) {
    localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
    //g_LocalController->BackpackComponent->OnRep_ItemListNet();
} else {
    callFunction = false;
}
}
}
}
}
}
g_LocalPlayer = localPlayer;
g_LocalController = localPlayerController;
}
}
}
