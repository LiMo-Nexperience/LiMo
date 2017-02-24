// Fill out your copyright notice in the Description page of Project Settings.

#include "LiMoBlueprintLibPrivatePCH.h"
#include "LiMoTargetComponent.h"
#include "LiMoApi.h"
#include "Engine.h"
#include "CoreUObject.h"

//#include "NxpVRDeviceCtrl.h"


// Sets default values for this component's properties
ULiMoTargetComponent::ULiMoTargetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULiMoTargetComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BeginPlay"));
	LiMoAPI.LiMo_SendCommand(kEvent_CMD_Motion, KEvent_Param1_Start, 0, 0, 0);
	// ...
}

void ULiMoTargetComponent::EndPlay(const EEndPlayReason::Type endtype)
{
	LiMoAPI.LiMo_SendCommand(kEvent_CMD_Motion, KEvent_Param1_Stop, 0, 0, 0);
	UE_LOG(LogTemp, Warning, TEXT(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>EndPlay"));
	Super::EndPlay(endtype);
	
}


int AngleDir(FVector fwd, FVector targetDir, FVector up)
{
	FVector perp = FVector::CrossProduct(fwd, targetDir);
	float dir = FVector::DotProduct(perp, up);

	if (dir > 0.0)
		return 1;
	else if (dir < 0.0)
		return -1;
	else
		return 0;
}


float ContAngle(FVector fwd, FVector targetDir)
{
	FVector fwdnormal = fwd.GetSafeNormal();
	FVector targetDirnormal = targetDir.GetSafeNormal();
	//UE_LOG(LogTemp, Warning, TEXT("1Test01  deg1 : %f,%f,%f, deg2 : %f,%f,%f"), fwdnormal.X, fwdnormal.Y, fwdnormal.Z, targetDirnormal.X, targetDirnormal.Y, targetDirnormal.Z);

	float dotvalue = FVector::DotProduct(fwdnormal, targetDirnormal);

	float angle = 0;
	
	if (dotvalue >= 1)
	{
		angle = 0;
	}
	else if(dotvalue <= -1)
	{
		angle = 180;
	}
	else
		angle = FMath::RadiansToDegrees(acosf(dotvalue));

	//UE_LOG(LogTemp, Warning, TEXT("dot fangle %f, %f"), dotvalue, angle);
	if (AngleDir(fwd, targetDir, FVector::UpVector) == -1)
	{
		angle = 360.0f - angle;
		if (angle > 359.9999f)
			angle -= 360.0f;
		return angle;
	}
	else
		return angle;
}


// Called every frame
void ULiMoTargetComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	FVector pos = this->GetComponentLocation();
	FVector rot = this->GetComponentRotation().Euler();
	FVector Forward = this->GetForwardVector();
	FVector Right = this->GetRightVector();

	FVector vec3 = FVector(Forward.X, Forward.Y, 0);
	FVector vec4 = FVector(Right.X, Right.Y, 0);

	//UE_LOG(LogTemp, Warning, TEXT("Test01  deg1 : %f,%f,%f, deg2 : %f,%f,%f"), Forward.X, Forward.Y, Forward.Z, Right.X, Right.Y, Right.Z);

	float deg1 = ContAngle(Forward, vec3);
	if (Forward.Z < 0)
		deg1 *= -1.0f;

	float deg2 = ContAngle(Right, vec4);
	if (Right.Z < 0)
		deg2 *= -1.0f;

	//UE_LOG(LogTemp, Warning, TEXT("Axis  deg1 : %f, deg2 : %f"), -deg1, deg2);
	//UE_LOG(LogTemp, Warning, TEXT("Position : %f, %f, %f"), pos.X, pos.Y, pos.Z);
	LiMoAPI.LiMo_MotionData_Set(GetWorld()->GetAudioTimeSeconds(), -deg1, 0, deg2, pos.Y*0.01f, pos.Z*0.01f, pos.X*0.01f, Forward.Y, Forward.Z, Forward.X);
	// if (NxpVRDeviceCtrl::Setting_Common_CommandEnable())
	// {
		// if (NxpVRDeviceCtrl::GetPlaySate() == ePLAYSTATE::PLAYING)
			// NxpVRDeviceCtrl::SetMotion(GetWorld()->GetTimeSeconds(), rot.X, rot.Y, rot.Z, pos.X, pos.Y, pos.Z);
	// }

}

