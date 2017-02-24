// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
 
#pragma once
#include "Engine.h" 
#include "IInputDevice.h"


struct FLiMoKey
{
	static const FKey LiMo_LeftArmAxisX;
	static const FKey LiMo_LeftArmAxisY;
	static const FKey LiMo_LeftArmSliderAxis;
	static const FKey LiMo_LeftArmSliderKey;

	static const FKey LiMo_RightArmAxisX;
	static const FKey LiMo_RightArmAxisY;
	static const FKey LiMo_RightArmSliderAxis;
	static const FKey LiMo_RightArmSliderKey;

	static const FKey LiMo_FootAxis1;
	static const FKey LiMo_FootAxis2;
	static const FKey LiMo_FootAxis3;

	static const FKey LiMo_FootKey1;
	static const FKey LiMo_FootKey2;
	static const FKey LiMo_FootKey3;

	static const FKey LiMo_LeftTrigger;
	static const FKey LiMo_LeftAction;
	//static const FKey LiMo_LeftCancel;

	static const FKey LiMo_RightTrigger;
	static const FKey LiMo_RightAction;
	//static const FKey LiMo_RightCancel;
};


struct FLiMoKeyNames
{
	typedef FName Type;

	static const FName LiMo_LeftArmAxisX;
	static const FName LiMo_LeftArmAxisY;
	static const FName LiMo_LeftArmSliderAxis;
	static const FName LiMo_LeftArmSliderKey;

	static const FName LiMo_RightArmAxisX;
	static const FName LiMo_RightArmAxisY;
	static const FName LiMo_RightArmSliderAxis;
	static const FName LiMo_RightArmSliderKey;

	static const FName LiMo_FootAxis1;
	static const FName LiMo_FootAxis2;
	static const FName LiMo_FootAxis3;

	static const FName LiMo_FootKey1;
	static const FName LiMo_FootKey2;
	static const FName LiMo_FootKey3;

	static const FName LiMo_LeftTrigger;
	static const FName LiMo_LeftAction;
	//static const FName LiMo_LeftCancel;

	static const FName LiMo_RightTrigger;
	static const FName LiMo_RightAction;
	//static const FName LiMo_RightCancel;

};


class FLiMoInputDevice : public IInputDevice
{
public:
	FLiMoInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler);
	~FLiMoInputDevice();
 
	/** Tick the interface (e.g. check for new controllers) */
	virtual void Tick(float DeltaTime) override;
 
	/** Poll for controller state and send events if needed */
	virtual void SendControllerEvents() override;
 
	/** Set which MessageHandler will get the events from SendControllerEvents. */
	virtual void SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override;
 
	/** Exec handler to allow console commands to be passed through for debugging */
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;
 
	/** IForceFeedbackSystem pass through functions **/
	virtual void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) override;
	virtual void SetChannelValues(int32 ControllerId, const FForceFeedbackValues &values) override;

	void RegisterInputKey();
 
private:
	/* Message handler */
	TSharedRef<FGenericApplicationMessageHandler> MessageHandler;

	float mLastLeftArmAxisX;
	float mLastLeftArmAxisY;
	float mLastLeftArmSlider;

	float mLastRightArmAxisX;
	float mLastRightArmAxisY;
	float mLastRightArmSlider;

	float mLastFootAxis1;
	float mLastFootAxis2;
	float mLastFootAxis3;

	bool	mLastLeftTrigger;
	bool	mLastLeftAction;
	//bool	mLastLeftCancel;

	bool	mLastRightTrigger;
	bool	mLastRightAction;
	//bool	mLastRightCancel;
};