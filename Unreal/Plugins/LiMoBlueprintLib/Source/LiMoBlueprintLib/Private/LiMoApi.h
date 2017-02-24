#pragma once

#define kEvent_CMD_ARM				100
#define kEvent_CMD_Motion			200

#define kEvent_CMD_VibratorNormal		17300

#define KEvent_Param1_Start			1
#define KEvent_Param1_Stop			2

#define KEvent_Param1_Motion_Mode		100

typedef int(__stdcall *_SendCommandCB)(int Cmd, int Param0, int Param1, int Param2, int Param3);

typedef int (*_LiMo_Initlize)(int ApplicationType, _SendCommandCB fp);

typedef int (*_LiMo_SendCommand)(int Cmd, int Param0, int Param1, int Param2, int Param3);

typedef int (*_LiMo_Finalize)(int nExitCode);

typedef float (*_LiMo_GetLeftArmX)();
typedef float (*_LiMo_GetLeftArmY)();
typedef float (*_LiMo_GetLeftSlider)();

typedef float (*_LiMo_GetRightArmX)();
typedef float (*_LiMo_GetRightArmY)();
typedef float (*_LiMo_GetRightSlider)();

typedef float (*_LiMo_GetFoot1)();
typedef float (*_LiMo_GetFoot2)();
typedef float (*_LiMo_GetFoot3)();

typedef int (*_LiMo_GetLeftTrigger)();
typedef int (*_LiMo_GetLeftAction)();
typedef int (*_LiMo_GetLeftCancel)();

typedef int (*_LiMo_GetRightTrigger)();
typedef int (*_LiMo_GetRightAction)();
typedef int (*_LiMo_GetRightCancel)();

typedef int  (*_LiMo_MotionData_Config)(int ActuratorMaxSpeed, int ActuratorSmooth);
typedef int  (*_LiMo_MotionData_MaxValue)(float MaxMove_surge, float MaxMove_sway, float MaxMove_heave, float MaxRot_roll, float MaxRot_pitch, float MaxRot_yaw);
typedef int  (*_LiMo_MotionData_Set)(float TtimeSec, float Rotx, float Roty, float Rotz, float Posx, float Posy, float Posz, float Forwardx, float Forwardy, float Forwardz);//Degree
typedef int  (*_LiMo_MotionData_Reset)();
//typedef int  (*_LiMo_MotionData_Set_BaseMotion)(float _ctimeSec, float _rx, float _ry, float _rz, float _px, float _py, float _pz);

class LiMoAPISet
{
public :
	LiMoAPISet();
	~LiMoAPISet();

	_LiMo_Initlize								  LiMo_Initlize;

	_LiMo_SendCommand                         LiMo_SendCommand;

	_LiMo_Finalize                                LiMo_Finalize;

	_LiMo_GetLeftArmX                         LiMo_GetLeftArmX;
	_LiMo_GetLeftArmY                         LiMo_GetLeftArmY;
	_LiMo_GetLeftSlider                       LiMo_GetLeftSlider;

	_LiMo_GetRightArmX                        LiMo_GetRightArmX;
	_LiMo_GetRightArmY                        LiMo_GetRightArmY;
	_LiMo_GetRightSlider                      LiMo_GetRightSlider;

	_LiMo_GetFoot1                            LiMo_GetFoot1;
	_LiMo_GetFoot2                            LiMo_GetFoot2;
	_LiMo_GetFoot3                            LiMo_GetFoot3;

	_LiMo_GetLeftTrigger                      LiMo_GetLeftTrigger;
	_LiMo_GetLeftAction                       LiMo_GetLeftAction;
	_LiMo_GetLeftCancel                       LiMo_GetLeftCancel;

	_LiMo_GetRightTrigger                     LiMo_GetRightTrigger;
	_LiMo_GetRightAction                      LiMo_GetRightAction;
	_LiMo_GetRightCancel                      LiMo_GetRightCancel;

	_LiMo_MotionData_Config						LiMo_MotionData_Config;
	_LiMo_MotionData_MaxValue					LiMo_MotionData_MaxValue;

	_LiMo_MotionData_Set                      LiMo_MotionData_Set;
	_LiMo_MotionData_Reset					  LiMo_MotionData_Reset;

	bool m_bInitlized;

	void Initlize();

}LiMoAPI;

