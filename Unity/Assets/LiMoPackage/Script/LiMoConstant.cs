namespace LiMo
{
    static public class LiMoConstant
    {
        public const int kEvent_CMD_ArmConEvent = 15000;
        public const int kEvent_CMD_ArmConAngle = 15100;
        //HS Yoon : Arm값을 angle에서 좌표 기반으로 변경된 값, subparam은 ArmConAngle과 동일하다.
        public const int kEvent_CMD_ArmConAngleConv = 15101;


        public const int kEvent_CMD_VibratorNormal = 17300;

        public enum ChairVibratorNormal : int
        {
	        cEvent_Param_VibratorResetAll = kEvent_CMD_VibratorNormal,
            cEvent_Param_VibratorPlay = kEvent_CMD_VibratorNormal+1,
            cEvent_Param_VibratorPlaySmooth = kEvent_CMD_VibratorNormal + 2,

	        cEvent_Param_VibratorMAX
        };

        public enum ChairVibratorID : int
        {
	        c_VIBID_Left_Hand = 32,
	        c_VIBID_Left_Arm = 64,
	        c_VIBID_Left_All = 96,
	        c_VIBID_Right_Hand = 128,
	        c_VIBID_Right_Arm = 256,
	        c_VIBID_Right_All = 384,
	        c_VIBID_Chair_Top_Left = 512,
	        c_VIBID_Chair_Top_Right = 1024,
	        c_VIBID_Chair_Top_All	= 1536,
	        c_VIBID_Chair_Center_Center = 2048,
	        c_VIBID_Chair_Bottom_Left = 4096,
	        c_VIBID_Chair_Bottom_Right = 8192,
	        c_VIBID_Chair_Bottom_All = 12288,
	        c_VIBID_Chair_ALL = 15872,
	        c_VIBID_ALL = 16352
        };

        public const int kEvent_CMD_ARM = 100;
        public const int kEvent_CMD_Motion = 200;
        public const int KEvent_Param1_Start = 1;
        public const int KEvent_Param1_Stop = 2;

        public const int KEvent_Param1_Motion_Mode = 100;



    }
}