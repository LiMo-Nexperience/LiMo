// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
 
#include "LiMoBlueprintLibPrivatePCH.h"
#include "LiMoInputDevicePlugin.h"
#include "IInputInterface.h"
#include "LiMoApi.h"


#define LOCTEXT_NAMESPACE "LiMoInput"


const FKey FLiMoKey::LiMo_LeftArmAxisX("LiMo_LeftArmAxisX");
const FKey FLiMoKey::LiMo_LeftArmAxisY("LiMo_LeftArmAxisY");
const FKey FLiMoKey::LiMo_LeftArmSliderAxis("LiMo_LeftArmSliderAxis");
const FKey FLiMoKey::LiMo_LeftArmSliderKey("LiMo_LeftArmSliderKey");

const FKey FLiMoKey::LiMo_RightArmAxisX("LiMo_RightArmAxisX");
const FKey FLiMoKey::LiMo_RightArmAxisY("LiMo_RightArmAxisY");
const FKey FLiMoKey::LiMo_RightArmSliderAxis("LiMo_RightArmSliderAxis");
const FKey FLiMoKey::LiMo_RightArmSliderKey("LiMo_RightArmSliderKey");

const FKey FLiMoKey::LiMo_FootAxis1("LiMo_FootAxis1");
const FKey FLiMoKey::LiMo_FootAxis2("LiMo_FootAxis2");
const FKey FLiMoKey::LiMo_FootAxis3("LiMo_FootAxis3");
const FKey FLiMoKey::LiMo_FootKey1("LiMo_FootKey1");
const FKey FLiMoKey::LiMo_FootKey2("LiMo_FootKey2");
const FKey FLiMoKey::LiMo_FootKey3("LiMo_FootKey3");

const FKey FLiMoKey::LiMo_LeftTrigger("LiMo_LeftTrigger");
const FKey FLiMoKey::LiMo_LeftAction("LiMo_LeftAction");
//const FKey FLiMoKey::LiMo_LeftCancel("LiMo_LeftCancel");

const FKey FLiMoKey::LiMo_RightTrigger("LiMo_RightTrigger");
const FKey FLiMoKey::LiMo_RightAction("LiMo_RightAction");
//const FKey FLiMoKey::LiMo_RightCancel("LiMo_RightCancel");


const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_LeftArmAxisX("LiMo_LeftArmAxisX");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_LeftArmAxisY("LiMo_LeftArmAxisY");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_LeftArmSliderAxis("LiMo_LeftArmSliderAxis");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_LeftArmSliderKey("LiMo_LeftArmSliderKey");

const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_RightArmAxisX("LiMo_RightArmAxisX");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_RightArmAxisY("LiMo_RightArmAxisY");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_RightArmSliderAxis("LiMo_RightArmSliderAxis");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_RightArmSliderKey("LiMo_RightArmSliderKey");

const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_FootAxis1("LiMo_FootAxis1");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_FootAxis2("LiMo_FootAxis2");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_FootAxis3("LiMo_FootAxis3");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_FootKey1("LiMo_FootKey1");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_FootKey2("LiMo_FootKey2");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_FootKey3("LiMo_FootKey3");

const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_LeftTrigger("LiMo_LeftTrigger");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_LeftAction("LiMo_LeftAction");
//const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_LeftCancel("LiMo_LeftCancel");

const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_RightTrigger("LiMo_RightTrigger");
const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_RightAction("LiMo_RightAction");
//const FLiMoKeyNames::Type FLiMoKeyNames::LiMo_RightCancel("LiMo_RightCancel");


FLiMoInputDevice::FLiMoInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) :
MessageHandler(InMessageHandler)
{
	// Initiate your device here

	mLastLeftArmAxisX = 0;
	mLastLeftArmAxisY = 0;
	mLastLeftArmSlider = 0;

	mLastRightArmAxisX = 0;
	mLastRightArmAxisY = 0;
	mLastRightArmSlider = 0;

	mLastFootAxis1 = 0;
	mLastFootAxis2 = 0;
	mLastFootAxis3 = 0;

	mLastLeftTrigger = false;
	mLastLeftAction = false;
	//mLastLeftCancel = false;

	mLastRightTrigger = false;
	mLastRightAction = false;
	//mLastRightCancel = false;

	RegisterInputKey();
}
 
 
FLiMoInputDevice::~FLiMoInputDevice()
{
	// Close your device here
}
 
 
void FLiMoInputDevice::Tick(float DeltaTime)
{
	// Nothing necessary to do (boilerplate code to complete the interface)
}
 
 
void FLiMoInputDevice::SendControllerEvents()
{
	// Poll your device here and fire off events related to its current state
 
	// Example: Sending a dummy value
	//UE_LOG(LiMo, Warning, TEXT("Sending dummy analog controller event!"));

	if (LiMoAPI.m_bInitlized)
	{
		//UE_LOG(LiMo, Warning, TEXT("Sending controller event!"));

		// Read Device Values

		float LeftArmX = LiMoAPI.LiMo_GetLeftArmX();
		float LeftArmY = LiMoAPI.LiMo_GetLeftArmY();
		float LeftSlider = LiMoAPI.LiMo_GetLeftSlider();

		float RightArmX = LiMoAPI.LiMo_GetRightArmX();
		float RightArmY = LiMoAPI.LiMo_GetRightArmY();
		float RightSlider = LiMoAPI.LiMo_GetRightSlider();

		float Foot1 = LiMoAPI.LiMo_GetFoot1();
		float Foot2 = LiMoAPI.LiMo_GetFoot2();
		float Foot3 = LiMoAPI.LiMo_GetFoot3();

		bool bLeftTrigger = false;
		if (LiMoAPI.LiMo_GetLeftTrigger()) bLeftTrigger = true;;
		bool bLeftAction = false;
		if (LiMoAPI.LiMo_GetLeftAction()) bLeftAction = true;
		//bool bLeftCancel = false;
		//if (LiMoAPI.LiMo_GetLeftCancel()) bLeftCancel = true;

		bool bRightTrigger = false;
		if (LiMoAPI.LiMo_GetRightTrigger()) bRightTrigger = true;
		bool bRightAction = false;
		if (LiMoAPI.LiMo_GetRightAction()) bRightAction = true;
		//bool bRightCancel = false;
		//if (LiMoAPI.LiMo_GetRightCancel()) bRightCancel = true;

		// Update Events/Values

		if (LeftArmX != mLastLeftArmAxisX)
		{
			MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_LeftArmAxisX, 0, LeftArmX);
			mLastLeftArmAxisX = LeftArmX;
		}

		if (LeftArmY != mLastLeftArmAxisY)
		{
			MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_LeftArmAxisY, 0, LeftArmY);
			mLastLeftArmAxisY = LeftArmY;
		}

		if (LeftSlider != mLastLeftArmSlider)
		{
			float KeyEventLimitValue = 0.2f;
			if (mLastLeftArmSlider > KeyEventLimitValue && LeftSlider <= KeyEventLimitValue)
			{
				MessageHandler->OnControllerButtonPressed(FLiMoKeyNames::LiMo_LeftArmSliderKey, 0, false);
			}
			if (mLastLeftArmSlider < KeyEventLimitValue && LeftSlider >= KeyEventLimitValue)
			{
				MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_LeftArmSliderKey, 0, false);
			}

			MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_LeftArmSliderAxis, 0, LeftSlider);
			mLastLeftArmSlider = LeftSlider;
		}

		if (RightArmX != mLastRightArmAxisX)
		{
			MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_RightArmAxisX, 0, RightArmX);
			mLastRightArmAxisX = RightArmX;
		}

		if (RightArmY != mLastRightArmAxisY)
		{
			MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_RightArmAxisY, 0, RightArmY);
			mLastRightArmAxisY = RightArmY;
		}

		if (RightSlider != mLastRightArmSlider)
		{
			float KeyEventLimitValue = 0.2f;
			if (mLastRightArmSlider > KeyEventLimitValue && RightSlider <= KeyEventLimitValue)
			{
				MessageHandler->OnControllerButtonPressed(FLiMoKeyNames::LiMo_RightArmSliderKey, 0, false);
			}
			if (mLastRightArmSlider < KeyEventLimitValue && RightSlider >= KeyEventLimitValue)
			{
				MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_RightArmSliderKey, 0, false);
			}

			MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_RightArmSliderAxis, 0, RightSlider);
			mLastRightArmSlider = RightSlider;
		}

		if (Foot1 != mLastFootAxis1)
		{
			float KeyEventLimitValue = 0.5f;
			if (mLastFootAxis1 < KeyEventLimitValue && Foot1 >= KeyEventLimitValue)
			{
				MessageHandler->OnControllerButtonPressed(FLiMoKeyNames::LiMo_FootKey1, 0, false);
			}
			if (mLastFootAxis1 > KeyEventLimitValue && Foot1 <= KeyEventLimitValue)
			{
				MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_FootKey1, 0, false);
			}

			MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_FootAxis1, 0, Foot1);
			mLastFootAxis1 = Foot1;
		}
		if (Foot2 != mLastFootAxis2)
		{
			float KeyEventLimitValue = 0.5f;
			if (mLastFootAxis2 < KeyEventLimitValue && Foot2 >= KeyEventLimitValue)
			{
				MessageHandler->OnControllerButtonPressed(FLiMoKeyNames::LiMo_FootKey2, 0, false);
			}
			if (mLastFootAxis2 > KeyEventLimitValue && Foot2 <= KeyEventLimitValue)
			{
				MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_FootKey2, 0, false);
			}

			MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_FootAxis2, 0, Foot2);
			mLastFootAxis2 = Foot2;
		}
		if (Foot3 != mLastFootAxis3)
		{
			float KeyEventLimitValue = 0.5f;
			if (mLastFootAxis3 < KeyEventLimitValue && Foot3 >= KeyEventLimitValue)
			{
				MessageHandler->OnControllerButtonPressed(FLiMoKeyNames::LiMo_FootKey3, 0, false);
			}
			if (mLastFootAxis3 > KeyEventLimitValue && Foot3 <= KeyEventLimitValue)
			{
				MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_FootKey3, 0, false);
			}

			MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_FootAxis3, 0, Foot3);
			mLastFootAxis3 = Foot3;
		}

		if (bLeftTrigger != mLastLeftTrigger)
		{
			if (bLeftTrigger)
				MessageHandler->OnControllerButtonPressed(FLiMoKeyNames::LiMo_LeftTrigger, 0, false);
			else
				MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_LeftTrigger, 0, false);

			mLastLeftTrigger = bLeftTrigger;
		}

		if (bLeftAction != mLastLeftAction)
		{
			if (bLeftAction)
				MessageHandler->OnControllerButtonPressed(FLiMoKeyNames::LiMo_LeftAction, 0, false);
			else
				MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_LeftAction, 0, false);

			mLastLeftAction = bLeftAction;
		}

		/*if (bLeftCancel != mLastLeftCancel)
		{
			if (bLeftCancel)
				MessageHandler->OnControllerButtonPressed(FLiMoKeyNames::LiMo_LeftCancel, 0, false);
			else
				MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_LeftCancel, 0, false);

			mLastLeftCancel = bLeftCancel;
		}*/

		if (bRightTrigger != mLastRightTrigger)
		{
			if (bRightTrigger)
				MessageHandler->OnControllerButtonPressed(FLiMoKeyNames::LiMo_RightTrigger, 0, false);
			else
				MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_RightTrigger, 0, false);

			mLastRightTrigger = bRightTrigger;
		}

		if (bRightAction != mLastRightAction)
		{
			if (bRightAction)
				MessageHandler->OnControllerButtonPressed(FLiMoKeyNames::LiMo_RightAction, 0, false);
			else
				MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_RightAction, 0, false);

			mLastRightAction = bRightAction;
		}

		/*if (bRightCancel != mLastRightCancel)
		{
			if (bRightCancel)
				MessageHandler->OnControllerButtonPressed(FLiMoKeyNames::LiMo_RightCancel, 0, false);
			else
				MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_RightCancel, 0, false);

			mLastRightCancel = bRightCancel;
		}*/
	}
	else
	{
		/*
		MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_LeftArmAxisX, 0, 0);
		MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_LeftArmAxisY, 0, 0);
		MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_LeftArmSliderAxis, 0, 0);
		MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_LeftArmSliderKey, 0, false);

		MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_RightArmAxisX, 0, 0);
		MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_RightArmAxisY, 0, 0);
		MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_RightArmSliderAxis, 0, 0);
		MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_RightArmSliderKey, 0, false);

		MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_FootAxis1, 0, 0);
		MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_FootAxis2, 0, 0);
		MessageHandler->OnControllerAnalog(FLiMoKeyNames::LiMo_FootAxis3, 0, 0);
		MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_FootKey1, 0, false);
		MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_FootKey2, 0, false);
		MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_FootKey3, 0, false);

		MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_LeftTrigger, 0, false);
		MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_LeftAction, 0, false);
		//MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_LeftCancel, 0, false);

		MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_RightTrigger, 0, false);
		MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_RightAction, 0, false);
		//MessageHandler->OnControllerButtonReleased(FLiMoKeyNames::LiMo_RightCancel, 0, false);
		*/
	}
}
 
 
void FLiMoInputDevice::SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	MessageHandler = InMessageHandler;
}
 
 
bool FLiMoInputDevice::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	// Nothing necessary to do (boilerplate code to complete the interface)
	return false;
}
 
 
void FLiMoInputDevice::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value)
{
	// Nothing necessary to do (boilerplate code to complete the interface)
}
 
 
void FLiMoInputDevice::SetChannelValues(int32 ControllerId, const FForceFeedbackValues &values)
{
	// Nothing necessary to do (boilerplate code to complete the interface)
}

void FLiMoInputDevice::RegisterInputKey()
{
	// Register the FKeys

	UE_LOG(LiMo, Warning, TEXT("Register Keys"));

	EKeys::AddMenuCategoryDisplayInfo("LiMo", LOCTEXT("LiMo Arm Controller", "LiMo"), TEXT("GraphEditor.PadEvent_16x"));

	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_LeftArmAxisX, LOCTEXT("LiMo_LeftArmAxisX", "LiMo LeftArmAxisX"), FKeyDetails::FloatAxis, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_LeftArmAxisY, LOCTEXT("LiMo_LeftArmAxisY", "LiMo LeftArmAxisY"), FKeyDetails::FloatAxis, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_LeftArmSliderAxis, LOCTEXT("LiMo_LeftArmSliderAxis", "LiMo LeftArmSliderAxis"), FKeyDetails::FloatAxis, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_LeftArmSliderKey, LOCTEXT("LiMo_LeftArmSliderKey", "LiMo LeftArmSliderKey"), FKeyDetails::GamepadKey, "LiMo"));

	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_RightArmAxisX, LOCTEXT("LiMo_RightArmAxisX", "LiMo RightArmAxisX"), FKeyDetails::FloatAxis, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_RightArmAxisY, LOCTEXT("LiMo_RightArmAxisY", "LiMo RightArmAxisY"), FKeyDetails::FloatAxis, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_RightArmSliderAxis, LOCTEXT("LiMo_RightArmSliderAxis", "LiMo RightArmSliderAxis"), FKeyDetails::FloatAxis, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_RightArmSliderKey, LOCTEXT("LiMo_RightArmSliderKey", "LiMo RightArmSliderKey"), FKeyDetails::GamepadKey, "LiMo"));

	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_FootAxis1, LOCTEXT("LiMo_FootAxis1", "LiMo FootAxis1"), FKeyDetails::FloatAxis, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_FootAxis2, LOCTEXT("LiMo_FootAxis2", "LiMo FootAxis2"), FKeyDetails::FloatAxis, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_FootAxis3, LOCTEXT("LiMo_FootAxis3", "LiMo FootAxis3"), FKeyDetails::FloatAxis, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_FootKey1, LOCTEXT("LiMo_FootKey1", "LiMo FootKey1"), FKeyDetails::GamepadKey, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_FootKey2, LOCTEXT("LiMo_FootKey2", "LiMo FootKey2"), FKeyDetails::GamepadKey, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_FootKey3, LOCTEXT("LiMo_FootKey3", "LiMo FootKey3"), FKeyDetails::GamepadKey, "LiMo"));

	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_LeftTrigger, LOCTEXT("LiMo_LeftTrigger", "LiMo LeftTrigger"), FKeyDetails::GamepadKey, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_LeftAction, LOCTEXT("LiMo_LeftAction", "LiMo LeftAction"), FKeyDetails::GamepadKey, "LiMo"));
	//EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_LeftCancel, LOCTEXT("LiMo_LeftCancel", "LiMo LeftCancel"), FKeyDetails::GamepadKey, "LiMo"));

	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_RightTrigger, LOCTEXT("LiMo_RightTrigger", "LiMo RightTrigger"), FKeyDetails::GamepadKey, "LiMo"));
	EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_RightAction, LOCTEXT("LiMo_RightAction", "LiMo RightAction"), FKeyDetails::GamepadKey, "LiMo"));
	//EKeys::AddKey(FKeyDetails(FLiMoKey::LiMo_RightCancel, LOCTEXT("LiMo_RightCancel", "LiMo RightCancel"), FKeyDetails::GamepadKey, "LiMo"));
}