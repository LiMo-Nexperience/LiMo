// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "LiMoBlueprintLib.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LiMoBlueprintFunctionLib.generated.h"
/**
 * 
 */
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ELimoChairVibratorID : uint8
{
	c_VIBID_Left_Hand			UMETA(DisplayName = "Vib Left Hand"),
	c_VIBID_Left_Arm			UMETA(DisplayName = "Vib Left Arm"),
	c_VIBID_Left_All			UMETA(DisplayName = "Vib Left All"),
	c_VIBID_Right_Hand			UMETA(DisplayName = "Vib Right Hand"),
	c_VIBID_Right_Arm			UMETA(DisplayName = "Vib Right Arm"),
	c_VIBID_Right_All			UMETA(DisplayName = "Vib Right All"),
	c_VIBID_Chair_Top_Left		UMETA(DisplayName = "Vib Chair Top Left"),
	c_VIBID_Chair_Top_Right		UMETA(DisplayName = "Vib Chair Top Right"),
	c_VIBID_Chair_Top_All		UMETA(DisplayName = "Vib Chair Top All"),
	c_VIBID_Chair_Center_Center UMETA(DisplayName = "Vib Chair Center"),
	c_VIBID_Chair_Bottom_Left	UMETA(DisplayName = "Vib Chair Bottom Left"),
	c_VIBID_Chair_Bottom_Right	UMETA(DisplayName = "Vib Chair Bottom Right"),
	c_VIBID_Chair_Bottom_All	UMETA(DisplayName = "Vib Chair Bottom All"),
	c_VIBID_Chair_All			UMETA(DisplayName = "Vib Chair All"),
	c_VIBID_All					UMETA(DisplayName = "Vib All")

};

UCLASS()
class LIMOBLUEPRINTLIB_API ULiMoBlueprintFunctionLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
		/**
		* Controller의 왼쪽 팔 각도를 얻어온다.
		*
		* [out]
		* @return: FVector2D.X 수평각도 FVector2D.Y 수직각도 Degree로 넘어오며 정면, 수평상태가 0도이다.
		*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static FVector2D GetLeftArmAxis();

	/**
	* Controller의 왼쪽 팔 수평 각도를 얻어온다.
	*
	* [out]
	* @return: float 수평각도 Degree로 넘어오며 정면일떄가 0도이고 왼쪽으로 갈수록 값이 커진다.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static float GetLeftArmAxisX();

	/**
	* Controller의 왼쪽 팔 수직 각도를 얻어온다.
	*
	* [out]
	* @return: float 수직 Degree로 넘어오며 수평일떄가 0도이고, 위로 올라갈수록 값이 커진다.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static float GetLeftArmAxisY();

	/**
	* 왼쪽 Arm Slider의 위치 정보
	*
	* [out]
	*
	* @return: [0,1] Slider가 사용자쪽으로 당겨지면 0, 앞쪽으로 밀고있으면 1이 출력되나 스프링 탄성등을 이유로 0.1~0.6 값을 사용하는것을 추천
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static float GetLeftArmSlider();

	/**
	* Controller의 오른쪽 팔 각도를 얻어온다.
	*
	* [out]
	* @return: FVector2D.X 수평각도 FVector2D.Y 수직각도 Degree로 넘어오며 정면, 수평상태가 0도이다.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static FVector2D GetRightArmAxis();

	/**
	* Controller의 오른쪽 팔 수평 각도를 얻어온다.
	*
	* [out]
	* @return: float 수평각도 Degree로 넘어오며 정면일떄가 0도이고 왼쪽으로 갈수록 값이 커진다.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static float GetRightArmAxisX();

	/**
	* Controller의 오른쪽 팔 수직 각도를 얻어온다.
	*
	* [out]
	* @return: float 수직 Degree로 넘어오며 수평일떄가 0도이고, 위로 올라갈수록 값이 커진다.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static float GetRightArmAxisY();

	/**
	* 오른쪽 Arm Slider의 위치 정보
	*
	* [out]
	*
	* @return: [0,1] Slider가 사용자쪽으로 당겨지면 0, 앞쪽으로 밀고있으면 1이 출력되나 스프링 탄성등을 이유로 0.1~0.6 값을 사용하는것을 추천
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static float GetRightArmSlider();

	/**
	* foot controller의 눌림 정도를 표시
	*
	* [out]
	*
	* @return: FVector2D.X : 왼쪽 발 컨트롤러, FVector2D.Y : 중앙 발 컨트롤러, FVector2D.Z : 오른쪽 발 컨트롤러, 
	           범위 스펙상 0은 뗀 상태이고 1이 눌린 상태이나 탄성등을 고려하면 0.2~0.8정도의 값을 사용하는것을 추천
	*            
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static FVector GetFootAxis();

	/**
	* foot controller의 눌림 정도를 표시
	*
	* [out]
	*
	* @return: 왼쪽 발 컨트롤러, 범위 스펙상 0은 뗀 상태이고 1이 눌린 상태이나 탄성등을 고려하면 0.2~0.8정도의 값을 사용하는것을 추천
	*
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static float GetFootAxis1();

	/**
	* foot controller의 눌림 정도를 표시
	*
	* [out]
	*
	* @return: 중앙 발 컨트롤러, 범위 스펙상 0은 뗀 상태이고 1이 눌린 상태이나 탄성등을 고려하면 0.2~0.8정도의 값을 사용하는것을 추천
	*
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static float GetFootAxis2();


	/**
	* foot controller의 눌림 정도를 표시
	*
	* [out]
	*
	* @return: 오른쪽 발 컨트롤러, 범위 스펙상 0은 뗀 상태이고 1이 눌린 상태이나 탄성등을 고려하면 0.2~0.8정도의 값을 사용하는것을 추천
	*
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static float GetFootAxis3();

	/**
	* Left Trigger가 눌렸는지 확인
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static bool GetLeftTrigger();

	/**
	* Left Action버튼이 눌렸는지 확인
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static bool GetLeftAction();

	/**
	* Left Cancel버튼이 눌렸는지 확인
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static bool GetLeftCancel();

	/**
	* Right Trigger가 눌렸는지 확인
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static bool GetRightTrigger();

	/**
	* Right Action버튼이 눌렸는지 확인
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static bool GetRightAction();

	/**
	* Right Cancel버튼이 눌렸는지 확인 : 현재 디바이스에서는 버튼이 삭제되어있는 상태
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LiMo Blueprint Library")
		static bool GetRightCancel();


	/**
	* Force Feedback을 전달하는 함수 
	*
	* [in]
	* @param id Force Feedback ID 위쪽 주석을 참조
	* @param weight 0~199까지 사용, 0으로 주면 진동이 꺼짐
	*
	*/
	UFUNCTION(BlueprintCallable, Category = "LiMo Blueprint Library")
		static void SendVibEffect(ELimoChairVibratorID id, uint8 weight);

	/**
	* Force Feedback을 전달과 동시에 force feedback의 지속시간도 같이 설정 할 수 있음.
	*
	* [in]
	* @param id Force Feedback ID 위쪽 주석을 참조
	* @param weight 0~199까지 사용
	* @param duration 0~60000까지 사용 
	*
	*/
	UFUNCTION(BlueprintCallable, Category = "LiMo Blueprint Library")
		static void SendVibEffectDuration(ELimoChairVibratorID id, uint8 weight, int32 Duration);

	/**
	* Force Feedback을 전달과 동시에 force feedback의 지속시간도 같이 설정 할 수 있음.
	* 지속시간이 끝날때, 진동이 바로 꺼지는 것이 아니라 진동이 부드럽게 감소하면서 꺼짐.
	*
	* [in]
	* @param id Force Feedback ID 위쪽 주석을 참조
	* @param weight 0~199까지 사용
	* @param duration 0~60000까지 사용 
	*/
	UFUNCTION(BlueprintCallable, Category = "LiMo Blueprint Library")
		static void SendVibEffectSmooth(ELimoChairVibratorID id, uint8 weight, int32 Duration);

	//UFUNCTION(BlueprintCallable, Category = "LiMo Blueprint Library")
	//	static void SendVibEffectSmooth(ELimoChairVibratorID id, uint8 weight, int32 Duration);


	UFUNCTION(BlueprintCallable, Category = "LiMo Blueprint Library")
		static int SendMessage(int Cmd, int Param0, int Param1, int Param2, int Param3);

	UFUNCTION(BlueprintCallable, Category = "LiMo Blueprint Library")
	static int  MotionData_Config(int ActuratorMaxSpeed, int ActuratorSmooth);

	UFUNCTION(BlueprintCallable, Category = "LiMo Blueprint Library")
	static int  MotionData_MaxValue(float MaxMove_surge, float MaxMove_sway, float MaxMove_heave, float MaxRot_roll, float MaxRot_pitch, float MaxRot_yaw);

	UFUNCTION(BlueprintCallable, Category = "LiMo Blueprint Library")
	static int  MotionData_Reset();

	UFUNCTION(BlueprintCallable, Category = "LiMo Blueprint Library")
		static int SetMotionPlateMode(int nMode);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FReceiveMessage, int, cmd, int, Param0, int, Param1, int, Param2, int, Param3);
	UPROPERTY(BlueprintAssignable)
		FReceiveMessage recvMsg;
	
};
