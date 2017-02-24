// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "LiMoBlueprintLibPrivatePCH.h"
#include "LiMoInputDevicePlugin.h"
#include "LiMoApi.h"

#define LOCTEXT_NAMESPACE "FLiMoBlueprintLibModule"



void FLiMoBlueprintLibModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	UE_LOG(LiMo, Warning, TEXT("LiMoBlueprintLibModule initiated!"));

	// IMPORTANT: This line registers our input device module with the engine.
	//	      If we do not register the input device module with the engine,
	//	      the engine won't know about our existence. Which means 
	//	      CreateInputDevice never gets called, which means the engine
	//	      will never try to poll for events from our custom input device.
	IModularFeatures::Get().RegisterModularFeature(IInputDeviceModule::GetModularFeatureName(), this);

	LiMoAPI.Initlize();
	if (LiMoAPI.m_bInitlized)
	{
		

	}
}

void FLiMoBlueprintLibModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UE_LOG(LiMo, Warning, TEXT("FLiMoBlueprintLibModule shut down!"));

	if (LiMoAPI.m_bInitlized)
	{
		UE_LOG(LiMo, Warning, TEXT("LiMoAPI Stop"));
		LiMoAPI.LiMo_Finalize(0);
	}

	// Unregister our input device module
	IModularFeatures::Get().UnregisterModularFeature(IInputDeviceModule::GetModularFeatureName(), this);

}

TSharedPtr<class IInputDevice> FLiMoBlueprintLibModule::CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
	UE_LOG(LiMo, Warning, TEXT("Created new input device [LiMo] !"));

	// See GenericInputDevice.h for the definition of the IInputDevice we are returning here
	return MakeShareable(new FLiMoInputDevice(InMessageHandler));
}




#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLiMoBlueprintLibModule, LiMoBlueprintLib)