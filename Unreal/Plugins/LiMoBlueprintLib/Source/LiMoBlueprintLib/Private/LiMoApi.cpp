#include "LiMoBlueprintLibPrivatePCH.h"
#include "LiMoApi.h"
#include "LiMoBlueprintFunctionLib.h"

LiMoAPISet::LiMoAPISet()
{
	memset(this, 0, sizeof(LiMoAPISet));
	m_bInitlized = false;
}

LiMoAPISet::~LiMoAPISet()
{
	if (m_bInitlized)
		LiMo_Finalize(0);
}


int __stdcall ReceiveCommand(int Cmd, int Param0, int Param1, int Param2, int Param3)
{
	//printf("Cmd : %d, P0 %d, P1 %d, P2 %d, P3 %d\n", Cmd, Param0, Param1, Param2, Param3);
	return 1;
}

void LiMoAPISet::Initlize()
{

	void *dllHandle = NULL;
	FString filePath = FPaths::Combine(*FPaths::GamePluginsDir(), TEXT("LiMoBlueprintLib/Binaries/Win64/"), TEXT("LiMoInterfaceDLL.dll"));
	UE_LOG(LiMo, Warning, TEXT("Find DLL Path %s"), *filePath);
	if (FPaths::FileExists(filePath))
	{
		dllHandle = FPlatformProcess::GetDllHandle(*filePath);

	}
	else
	{
		filePath = FPaths::Combine(*FPaths::GamePluginsDir(), TEXT("LiMoBlueprintLib/Source/LiMoBlueprintLib/lib/"), TEXT("LiMoInterfaceDLL.dll"));
		UE_LOG(LiMo, Warning, TEXT("Find DLL Path %s"), *filePath);
		if (FPaths::FileExists(filePath))
		{
			dllHandle = FPlatformProcess::GetDllHandle(*filePath);
		}
		else
		{
			filePath = FPaths::Combine(*FPaths::GamePluginsDir(), TEXT("LiMoInterfaceDLL.dll"));
			UE_LOG(LiMo, Warning, TEXT("Find DLL Path %s"), *filePath);
			if (FPaths::FileExists(filePath))
			{
				dllHandle = FPlatformProcess::GetDllHandle(*filePath);
			}
		}
	}

	
	if (dllHandle)
	{
		UE_LOG(LiMo, Warning, TEXT("DLL Found Initlize Function"));
		LiMo_Initlize = (_LiMo_Initlize)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_Initlize"));
		if (!LiMo_Initlize) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_Initlize Linked"));

		LiMo_SendCommand = (_LiMo_SendCommand)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_SendCommand"));
		if (!LiMo_SendCommand) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_SendCommand Linked"));

		LiMo_Finalize = (_LiMo_Finalize)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_Finalize"));
		if (!LiMo_Finalize) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_Finalize Linked"));

		LiMo_GetLeftArmX = (_LiMo_GetLeftArmX)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetLeftArmX"));
		if (!LiMo_GetLeftArmX) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetLeftArmX Linked"));
		LiMo_GetLeftArmY = (_LiMo_GetLeftArmY)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetLeftArmY"));
		if (!LiMo_GetLeftArmY) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetLeftArmY Linked"));
		LiMo_GetLeftSlider = (_LiMo_GetLeftSlider)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetLeftSlider"));
		if (!LiMo_GetLeftSlider) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetLeftSlider Linked"));

		LiMo_GetRightArmX = (_LiMo_GetRightArmX)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetRightArmX"));
		if (!LiMo_GetRightArmX) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetRightArmX Linked"));
		LiMo_GetRightArmY = (_LiMo_GetRightArmY)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetRightArmY"));
		if (!LiMo_GetRightArmY) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetRightArmY Linked"));
		LiMo_GetRightSlider = (_LiMo_GetRightSlider)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetRightSlider"));
		if (!LiMo_GetRightSlider) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetRightSlider Linked"));

		LiMo_GetFoot1 = (_LiMo_GetFoot1)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetFoot1"));
		if (!LiMo_GetFoot1) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetFoot1 Linked"));
		LiMo_GetFoot2 = (_LiMo_GetFoot2)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetFoot2"));
		if (!LiMo_GetFoot2) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetFoot2 Linked"));
		LiMo_GetFoot3 = (_LiMo_GetFoot3)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetFoot3"));
		if (!LiMo_GetFoot3) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetFoot3 Linked"));

		LiMo_GetLeftTrigger = (_LiMo_GetLeftTrigger)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetLeftTrigger"));
		if (!LiMo_GetLeftTrigger) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetLeftTrigger Linked"));
		LiMo_GetLeftAction = (_LiMo_GetLeftAction)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetLeftAction"));
		if (!LiMo_GetLeftAction) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetLeftAction Linked"));
		LiMo_GetLeftCancel = (_LiMo_GetLeftCancel)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetLeftCancel"));
		if (!LiMo_GetLeftCancel) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetLeftCancel Linked"));

		LiMo_GetRightTrigger = (_LiMo_GetRightTrigger)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetRightTrigger"));
		if (!LiMo_GetRightTrigger) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetRightTrigger Linked"));
		LiMo_GetRightAction = (_LiMo_GetRightAction)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetRightAction"));
		if (!LiMo_GetRightAction) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetRightAction Linked"));
		LiMo_GetRightCancel = (_LiMo_GetRightCancel)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_GetRightCancel"));
		if (!LiMo_GetRightCancel) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_GetRightCancel Linked"));

		LiMo_MotionData_Config = (_LiMo_MotionData_Config)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_MotionData_Config"));
		if (!LiMo_MotionData_Config) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_MotionData_Config Linked"));

		LiMo_MotionData_MaxValue = (_LiMo_MotionData_MaxValue)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_MotionData_MaxValue"));
		if (!LiMo_MotionData_MaxValue) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_MotionData_MaxValue Linked"));
		
		LiMo_MotionData_Set = (_LiMo_MotionData_Set)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_MotionData_Set"));
		if (!LiMo_MotionData_Set) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_MotionData_Set Linked"));

		LiMo_MotionData_Reset = (_LiMo_MotionData_Reset)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_MotionData_Reset"));
		if (!LiMo_MotionData_Reset) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_MotionData_Reset Linked"));
		/*LiMo_MotionData_Set_BaseMotion = (_LiMo_MotionData_Set_BaseMotion)FPlatformProcess::GetDllExport(dllHandle, TEXT("KiWi_MotionData_Set_BaseMotion"));
		if (!LiMo_MotionData_Set_BaseMotion) return;
		UE_LOG(LiMo, Warning, TEXT("KiWi_MotionData_Set_BaseMotion Linked"));*/

		
		UE_LOG(LiMo, Warning, TEXT("LiMoAPI Initlized"));
		LiMo_Initlize(100, ReceiveCommand);
		UE_LOG(LiMo, Warning, TEXT("LiMoAPI Start"));
		LiMoAPI.LiMo_SendCommand(kEvent_CMD_ARM, KEvent_Param1_Start, 0, 0, 0);
		//LiMoAPI.LiMo_SendCommand(kEvent_CMD_Motion, KEvent_Param1_Start, 0, 0, 0);

		m_bInitlized = true;

		return;
	}
	
	UE_LOG(LiMo, Warning, TEXT("Cannot Loading DLL File"));


}
