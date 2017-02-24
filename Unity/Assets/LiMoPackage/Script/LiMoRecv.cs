using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;
using System.Text;
using System;

namespace LiMo
{
    public class LiMoRecv : MonoBehaviour
    {

        // Use this for initialization
        void Start()
        {

        }

        // Update is called once per frame
        void Update()
        {

        }


        public static int[] mLastVibStrength = new int[11] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

        const string DLLNAME = "LiMoInterfaceDLL";
        public delegate int CommandProc(int Cmd, int Param0, int Param1, int Param2, int Param3);


        [DllImport(DLLNAME)]
        static extern int KiWi_Initlize(int ApplicationType, CommandProc fp);

        [DllImport(DLLNAME)]
        static extern int KiWi_Finalize(int nExitCode);


        [DllImport(DLLNAME)]
        static extern int KiWi_SendCommand(int Cmd, int Param0, int Param1, int Param2, int Param3);

        [DllImport(DLLNAME)]
        public static extern float KiWi_GetLeftArmX();
        [DllImport(DLLNAME)]
        public static extern float KiWi_GetLeftArmY();
        [DllImport(DLLNAME)]
        public static extern float KiWi_GetLeftSlider();

        [DllImport(DLLNAME)]
        public static extern float KiWi_GetRightArmX();
        [DllImport(DLLNAME)]
        public static extern float KiWi_GetRightArmY();
        [DllImport(DLLNAME)]
        public static extern float KiWi_GetRightSlider();

        [DllImport(DLLNAME)]
        public static extern float KiWi_GetFoot1();
        [DllImport(DLLNAME)]
        public static extern float KiWi_GetFoot2();
        [DllImport(DLLNAME)]
        public static extern float KiWi_GetFoot3();

        [DllImport(DLLNAME)]
        public static extern int KiWi_GetLeftTrigger();
        [DllImport(DLLNAME)]
        public static extern int KiWi_GetLeftAction();

        [DllImport(DLLNAME)]
        public static extern int KiWi_GetRightTrigger();
        [DllImport(DLLNAME)]
        public static extern int KiWi_GetRightAction();

        [DllImport(DLLNAME)]
        public static extern int KiWi_MotionData_Config(int ActuratorMaxSpeed, int ActuratorSmooth);
        [DllImport(DLLNAME)]
        public static extern int KiWi_MotionData_MaxValue(float MaxMove_surge, float MaxMove_sway, float MaxMove_heave, float MaxRot_roll, float MaxRot_pitch, float MaxRot_yaw);


        [DllImport(DLLNAME)]
        public static extern int KiWi_MotionData_Set(float TtimeSec, float Rotx, float Roty, float Rotz, float Posx, float Posy, float Posz, float Forwardx, float Forwardy, float Forwardz);//Degree
        [DllImport(DLLNAME)]
        public static extern int KiWi_MotionData_Reset();




        void Awake()
        {
            KiWi_Initlize(0, new CommandProc(this.ReceiveCommandFromDLL));
        }
        void OnDestroy()
        {
            KiWi_Finalize(0);
        }

        public static void StartArm()
        {
            LiMoRecv.SendCommand2DLL(LiMoConstant.kEvent_CMD_ARM, LiMoConstant.KEvent_Param1_Start);
        }

        public static void StopArm()
        {
            LiMoRecv.SendCommand2DLL(LiMoConstant.kEvent_CMD_ARM, LiMoConstant.KEvent_Param1_Stop);
        }

        public static void StartMotion()
        {
            LiMoRecv.SendCommand2DLL(LiMoConstant.kEvent_CMD_Motion, LiMoConstant.KEvent_Param1_Start);
        }

        public static void StopMotion()
        {
            LiMoRecv.SendCommand2DLL(LiMoConstant.kEvent_CMD_Motion, LiMoConstant.KEvent_Param1_Stop);
        }


        public static void SendVibEffect(int id, int weight)
        {
            if (mLastVibStrength[id] != weight)
            {
                mLastVibStrength[id] = weight;
                LiMoRecv.SendCommand2DLL(LiMoConstant.kEvent_CMD_VibratorNormal, (int)LiMoConstant.ChairVibratorNormal.cEvent_Param_VibratorPlay, id, weight);
            }
        }

        public static void SendVibEffect(int id, int weight, int Duration)
        {
            LiMoRecv.SendCommand2DLL(LiMoConstant.kEvent_CMD_VibratorNormal, (int)LiMoConstant.ChairVibratorNormal.cEvent_Param_VibratorPlay, id, weight, Duration);
        }

        public static void SendVibEffectAllChair(int weight, int Duration)
        {
            LiMoRecv.SendCommand2DLL(LiMoConstant.kEvent_CMD_VibratorNormal, (int)LiMoConstant.ChairVibratorNormal.cEvent_Param_VibratorPlay, (int)LiMoConstant.ChairVibratorID.c_VIBID_Chair_ALL, weight, Duration);
        }

        //// ref를 사용하지 않으면 memcopy를 하게되니.... call by reference로..
        //public static int SendBinary2DLL(uint Cmd, ref byte[] array)
        //{
        //    int retvalue = 0;
        //    int size = Marshal.SizeOf(array[0]) * array.Length;

        //    IntPtr pnt = Marshal.AllocHGlobal(size);

        //    try
        //    {
        //        // Copy the array to unmanaged memory.
        //        Marshal.Copy(array, 0, pnt, array.Length);

        //        // Copy the unmanaged array back to another managed array.

        //        //byte[] managedArray2 = new byte[array.Length];

        //        //Marshal.Copy(pnt, managedArray2, 0, array.Length);

        //        retvalue = KiWi_SendBinary(Cmd, pnt, (uint)array.Length);
        //        //Console.WriteLine("The array was copied to unmanaged memory and back.");

        //    }
        //    finally
        //    {
        //        // Free the unmanaged memory.
        //        Marshal.FreeHGlobal(pnt);
        //    }

        //    return retvalue;

        //}

        public static int SendCommand2DLL(int Cmd, int Param0 = 0, int Param1 = 0, int Param2 = 0, int Param3 = 0)
        {
            return KiWi_SendCommand(Cmd, Param0, Param1, Param2, Param3);
        }


        int ReceiveCommandFromDLL(int Cmd, int Param0, int Param1, int Param2, int Param3)
        {
            return 1;
        }


    }
}