// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"
#include "IInputDeviceModule.h"

class FLiMoBlueprintLibModule : public IInputDeviceModule
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual TSharedPtr<class IInputDevice> CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) override; 

	static inline FLiMoBlueprintLibModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FLiMoBlueprintLibModule >("LiMoBlueprintLib");
	}

	/**
	* Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	*
	* @return True if the module is loaded and ready to use
	*/
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("LiMoBlueprintLib");
	}
};
DEFINE_LOG_CATEGORY_STATIC(LiMo, Log, All);