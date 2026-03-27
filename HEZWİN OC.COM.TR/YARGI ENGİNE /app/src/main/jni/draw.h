void (*orig_Broadcast)(ASTExtraPlayerController* thiz, struct FFatalDamageParameter* FatalDamageParameter);
void hk_Broadcast(ASTExtraPlayerController* thiz, struct FFatalDamageParameter* FatalDamageParameter)
{
    if (g_LocalPlayer->PlayerKey == FatalDamageParameter->CauserKey && !g_LocalController->STExtraBaseCharacter->CurrentVehicle) {
        if(KillMessage){
            if (preferences.Config.Skin.XSuits == 1)
					FatalDamageParameter->CauserClothAvatarID = new_Skin.XSuits; //blood raven x suit
                    }
                    if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "AKM")){
						if (preferences.AKM == 1)
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.AKM;//Sculpture - AKM
                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M416")){                  
                        if (preferences.M416 == 1) 
                            FatalDamageParameter->CauserWeaponAvatarID = new_Skin.M416_1;                                       }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "SCAR-L")){
                           if (preferences.SCARL == 1) 
                            FatalDamageParameter->CauserWeaponAvatarID = new_Skin.Scar; //Water Blaster - SCAR-L
                                                        
                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M762")){                  
                      if (preferences.M762 == 1) 
                            FatalDamageParameter->CauserWeaponAvatarID = new_Skin.M762; //8-bit Unicorn - M762
                            
                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "GROZA")){
                    if (preferences.GROZA == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.Groza;
                        
                        }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "UZI")){
                    if (preferences.UZI == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.UZI; //Savagery - UZI
                     
                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "ACE32")){
                    if (preferences.ACE32 == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.ACE32; //Savagery - UZI
                     
                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "UMP45")){
                      if (preferences.UMP == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.UMP;
                        
                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "Vector")){
                        if (preferences.VECTOR == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.Vector;
              
                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "Thompson")){
                        if (preferences.TOMMY == 1)
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.Thompson; //candy cane
                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "PP-19 Bizon")){
                    if (preferences.BIZON == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.Bizon;
                        
                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "Kar98K")){
                        if (preferences.KAR98 == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.K98;
                       
                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M24")){
                        if (preferences.M24 == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.M24;
                        
                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "AWM")){
                        if (preferences.AWM == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.AWM;

                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "DP28")){
                        if (preferences.DP28 == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.DP28;

                    }
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M16A4")){
                    if (preferences.M16 == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.M16A4;

                        }
                        
                        else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M249")){
                        if (preferences.M249== 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.M249;

                        }
                        
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "Pan")){
                        if (preferences.PAN == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.Pan;

                    }
                    
                    else if(strstr(g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "AUG")){
                    if (preferences.AUG == 1) 
                        FatalDamageParameter->CauserWeaponAvatarID = new_Skin.AUG;
                    
                    }
        }
  return orig_Broadcast(thiz, FatalDamageParameter);
}
static int prevXSuits = preferences.Config.Skin.XSuits;
static auto start = std::chrono::high_resolution_clock::now();
static bool callFunction = false;
static bool callNotify = false;
static bool callModSkin = false;
// ================================================================================================================================ //
std::chrono::steady_clock::time_point lastChangeTime;
