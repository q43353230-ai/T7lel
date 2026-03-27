#pragma once

// PUBG MOBILE (3.8.0) TELEGRAM MALIK:-@K_Y_2  
// GENERATE ON Wed May  7 14:35:34 2025
 
namespace SDK
{
//---------------------------------------------------------------------------
//Enums
//---------------------------------------------------------------------------

// Enum PixUILog.EPxLogLevels
enum class EPxLogLevels : uint8_t
{
	EPxLogLevels__Log              = 0,
	EPxLogLevels__Warning          = 1,
	EPxLogLevels__Error            = 2,
	EPxLogLevels__Debug            = 3,
	EPxLogLevels__Count            = 4,
	EPxLogLevels__EPxLogLevels_MAX = 5
};


// Enum PixUILog.EPxLogGroups
enum class EPxLogGroups : uint8_t
{
	EPxLogGroups__Core             = 0,
	EPxLogGroups__Plugin           = 1,
	EPxLogGroups__Script           = 2,
	EPxLogGroups__Profiler         = 3,
	EPxLogGroups__Count            = 4,
	EPxLogGroups__EPxLogGroups_MAX = 5
};



}

