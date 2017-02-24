// Fill out your copyright notice in the Description page of Project Settings.

#include "LiMoBlueprintLibPrivatePCH.h"
#include "LiMoBlueprintFunctionLib.h"
#include "LiMoApi.h"

/**
* 생성자
*/

FVector2D ULiMoBlueprintFunctionLib::GetLeftArmAxis()
{
	FVector2D abs(0,0);
	if (LiMoAPI.m_bInitlized)
	{
		abs.X = LiMoAPI.LiMo_GetLeftArmX();
		abs.Y = LiMoAPI.LiMo_GetLeftArmY();
	}

	return abs;
}

float ULiMoBlueprintFunctionLib::GetLeftArmAxisX()
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_GetLeftArmX();
	}
	return 0;
}

float ULiMoBlueprintFunctionLib::GetLeftArmAxisY()
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_GetLeftArmY();
	}
	return 0;
}

float ULiMoBlueprintFunctionLib::GetLeftArmSlider()
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_GetLeftSlider();
	}
	return 0;
}

FVector2D ULiMoBlueprintFunctionLib::GetRightArmAxis()
{
	FVector2D abs(0,0);
	if (LiMoAPI.m_bInitlized)
	{
		abs.X = LiMoAPI.LiMo_GetRightArmX();
		abs.Y = LiMoAPI.LiMo_GetRightArmY();
	}

	return abs;
}

float ULiMoBlueprintFunctionLib::GetRightArmAxisX()
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_GetRightArmX();
	}
	return 0;
}

float ULiMoBlueprintFunctionLib::GetRightArmAxisY()
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_GetRightArmY();
	}
	return 0;
}

float ULiMoBlueprintFunctionLib::GetRightArmSlider()
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_GetRightSlider();
	}
	return 0;
}


FVector ULiMoBlueprintFunctionLib::GetFootAxis()
{
	FVector abs(0,0,0);

	if (LiMoAPI.m_bInitlized)
	{
		abs.X = LiMoAPI.LiMo_GetFoot1();
		abs.Y = LiMoAPI.LiMo_GetFoot2();
		abs.Z = LiMoAPI.LiMo_GetFoot3();
	}

	return abs;
}

float ULiMoBlueprintFunctionLib::GetFootAxis1()
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_GetFoot1();
	}
	return 0;
}

float ULiMoBlueprintFunctionLib::GetFootAxis2()
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_GetFoot2();
	}
	return 0;
}

float ULiMoBlueprintFunctionLib::GetFootAxis3()
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_GetFoot3();
	}
	return 0;
}

bool ULiMoBlueprintFunctionLib::GetLeftTrigger()
{
	if (LiMoAPI.m_bInitlized)
	{
		if (LiMoAPI.LiMo_GetLeftTrigger() == 0)
			return false;
		else
			return true;

	}
	return 0;
}


bool ULiMoBlueprintFunctionLib::GetLeftAction()
{
	if (LiMoAPI.m_bInitlized)
	{
		if (LiMoAPI.LiMo_GetLeftAction() == 0)
			return false;
		else
			return true;
	}
	return 0;
}


bool ULiMoBlueprintFunctionLib::GetLeftCancel()
{
	if (LiMoAPI.m_bInitlized)
	{
		if(LiMoAPI.LiMo_GetLeftCancel() == 0)
			return false;
		else
			return true;
	}
	return 0;
}


bool ULiMoBlueprintFunctionLib::GetRightTrigger()
{
	if (LiMoAPI.m_bInitlized)
	{
		if(LiMoAPI.LiMo_GetRightTrigger() == 0)
			return false;
		else
			return true;
	}
	return 0;
}


bool ULiMoBlueprintFunctionLib::GetRightAction()
{
	if (LiMoAPI.m_bInitlized)
	{
		if(LiMoAPI.LiMo_GetRightAction() == 0)
			return false;
		else
			return true;
	}
	return 0;
}


bool ULiMoBlueprintFunctionLib::GetRightCancel()
{
	if (LiMoAPI.m_bInitlized)
	{
		if(LiMoAPI.LiMo_GetRightCancel() == 0)
			return false;
		else
			return true;
	}
	return 0;
}

void ULiMoBlueprintFunctionLib::SendVibEffect(ELimoChairVibratorID id, uint8 weight)
{
	ULiMoBlueprintFunctionLib::SendVibEffectDuration(id, weight, 0);

}

enum ChairVibratorID : unsigned long
{
	c_VIBID_Left_Hand = 32,
	c_VIBID_Left_Arm = 64,
	c_VIBID_Left_All = 96,
	c_VIBID_Right_Hand = 128,
	c_VIBID_Right_Arm = 256,
	c_VIBID_Right_All = 384,
	c_VIBID_Chair_Top_Left = 512,
	c_VIBID_Chair_Top_Right = 1024,
	c_VIBID_Chair_Top_All = 1536,
	c_VIBID_Chair_Center_Center = 2048,
	c_VIBID_Chair_Bottom_Left = 4096,
	c_VIBID_Chair_Bottom_Right = 8192,
	c_VIBID_Chair_Bottom_All = 12288,
	c_VIBID_Chair_ALL = 15872,
	c_VIBID_ALL = 16352
};

#define kEvent_CMD_VibratorNormal		17300

enum ChairVibratorNormal : unsigned long
{
	cEvent_Param_VibratorResetAll = kEvent_CMD_VibratorNormal,
	cEvent_Param_VibratorPlay = kEvent_CMD_VibratorNormal + 1,
	cEvent_Param_VibratorPlaySmooth = kEvent_CMD_VibratorNormal + 2,
	cEvent_Param_VibratorMAX
};


void ULiMoBlueprintFunctionLib::SendVibEffectDuration(ELimoChairVibratorID id, uint8 weight, int32 Duration)
{
	unsigned long IDFilter = 0;

	if (id == ELimoChairVibratorID::c_VIBID_Left_Hand) IDFilter = c_VIBID_Left_Hand;
	if (id == ELimoChairVibratorID::c_VIBID_Left_Arm) IDFilter = c_VIBID_Left_Arm;
	if (id == ELimoChairVibratorID::c_VIBID_Left_All) IDFilter = c_VIBID_Left_All;
	if (id == ELimoChairVibratorID::c_VIBID_Right_Hand) IDFilter = c_VIBID_Right_Hand;
	if (id == ELimoChairVibratorID::c_VIBID_Right_Arm) IDFilter = c_VIBID_Right_Arm;
	if (id == ELimoChairVibratorID::c_VIBID_Right_All) IDFilter = c_VIBID_Right_All;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Top_Left) IDFilter = c_VIBID_Chair_Top_Left;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Top_Right) IDFilter = c_VIBID_Chair_Top_Right;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Top_All) IDFilter = c_VIBID_Chair_Top_All;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Center_Center) IDFilter = c_VIBID_Chair_Center_Center;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Bottom_Left) IDFilter = c_VIBID_Chair_Bottom_Left;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Bottom_Right) IDFilter = c_VIBID_Chair_Bottom_Right;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Bottom_All) IDFilter = c_VIBID_Chair_Bottom_All;

	if (id == ELimoChairVibratorID::c_VIBID_Chair_All) IDFilter = c_VIBID_Chair_ALL;
	if (id == ELimoChairVibratorID::c_VIBID_All) IDFilter = c_VIBID_ALL;

	if (LiMoAPI.m_bInitlized)
	{
		LiMoAPI.LiMo_SendCommand(kEvent_CMD_VibratorNormal, cEvent_Param_VibratorPlay, IDFilter, weight, Duration);
	}
}

void ULiMoBlueprintFunctionLib::SendVibEffectSmooth(ELimoChairVibratorID id, uint8 weight, int32 Duration)
{
	unsigned long IDFilter = 0;

	if (id == ELimoChairVibratorID::c_VIBID_Left_Hand) IDFilter = c_VIBID_Left_Hand;
	if (id == ELimoChairVibratorID::c_VIBID_Left_Arm) IDFilter = c_VIBID_Left_Arm;
	if (id == ELimoChairVibratorID::c_VIBID_Left_All) IDFilter = c_VIBID_Left_All;
	if (id == ELimoChairVibratorID::c_VIBID_Right_Hand) IDFilter = c_VIBID_Right_Hand;
	if (id == ELimoChairVibratorID::c_VIBID_Right_Arm) IDFilter = c_VIBID_Right_Arm;
	if (id == ELimoChairVibratorID::c_VIBID_Right_All) IDFilter = c_VIBID_Right_All;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Top_Left) IDFilter = c_VIBID_Chair_Top_Left;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Top_Right) IDFilter = c_VIBID_Chair_Top_Right;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Top_All) IDFilter = c_VIBID_Chair_Top_All;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Center_Center) IDFilter = c_VIBID_Chair_Center_Center;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Bottom_Left) IDFilter = c_VIBID_Chair_Bottom_Left;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Bottom_Right) IDFilter = c_VIBID_Chair_Bottom_Right;
	if (id == ELimoChairVibratorID::c_VIBID_Chair_Bottom_All) IDFilter = c_VIBID_Chair_Bottom_All;

	if (id == ELimoChairVibratorID::c_VIBID_Chair_All) IDFilter = c_VIBID_Chair_ALL;
	if (id == ELimoChairVibratorID::c_VIBID_All) IDFilter = c_VIBID_ALL;

	if (LiMoAPI.m_bInitlized)
	{
		LiMoAPI.LiMo_SendCommand(kEvent_CMD_VibratorNormal, cEvent_Param_VibratorPlaySmooth, IDFilter, weight, Duration);
	}
}

int ULiMoBlueprintFunctionLib::SendMessage(int Cmd, int Param0, int Param1, int Param2, int Param3)
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_SendCommand(Cmd, Param0, Param1, Param2, Param3);
	}
	return 0;
}

int  ULiMoBlueprintFunctionLib::MotionData_Config(int ActuratorMaxSpeed, int ActuratorSmooth)
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_MotionData_Config(ActuratorMaxSpeed, ActuratorSmooth);
	}
	return 0;
}

int  ULiMoBlueprintFunctionLib::MotionData_MaxValue(float MaxMove_surge, float MaxMove_sway, float MaxMove_heave, float MaxRot_roll, float MaxRot_pitch, float MaxRot_yaw)
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_MotionData_MaxValue(MaxMove_surge, MaxMove_sway, MaxMove_heave, MaxRot_roll, MaxRot_pitch, MaxRot_yaw);
	}
	return 0;
}


int  ULiMoBlueprintFunctionLib::MotionData_Reset()
{
	if (LiMoAPI.m_bInitlized)
	{
		return LiMoAPI.LiMo_MotionData_Reset();
	}
	return 0;
}

int ULiMoBlueprintFunctionLib::SetMotionPlateMode(int nMode)
{
	if (LiMoAPI.m_bInitlized)
	{
		LiMoAPI.LiMo_SendCommand(kEvent_CMD_Motion, KEvent_Param1_Motion_Mode, nMode, 0, 0);
		return 1;
	}
	return 0;
}
