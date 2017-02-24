using UnityEngine;
using System.Collections;

namespace LiMo
{

    public class LiMoInput : MonoBehaviour
    {
        public float LeftArmX = 0;
        public float LeftArmY = 0;
        public float LeftSlider = 0;

        public float RightArmX = 0;
        public float RightArmY = 0;
        public float RightSlider = 0;

        public float Foot1 = 0;
        public float Foot2 = 0;
        public float Foot3 = 0;

        public bool LeftTrigger = false;
        public bool LeftTriggerDown = false;
        public bool LeftTriggerUp = false;

        public bool LeftAction = false;
        public bool LeftActionDown = false;
        public bool LeftActionUp = false;

        public bool RightTrigger = false;
        public bool RightTriggerDown = false;
        public bool RightTriggerUp = false;

        public bool RightAction = false;
        public bool RightActionDown = false;
        public bool RightActionUp = false;


        public static LiMoInput instance;
        public void Awake()
        {

            LiMoInput.instance = this;
        }


        // Use this for initialization
        void Start()
        {
            //KiWi_MotionData_Config(5.0f, 20.0f, 30.0f, 60.0f, 60.0f, 60.0f, 500, 5);
            LiMoRecv.StartArm();
        }

        void OnApplicationQuit()
        {
            LiMoRecv.StopArm();
        }


        void Update()
        {
            LeftArmX = LiMoRecv.KiWi_GetLeftArmX();
            LeftArmY = LiMoRecv.KiWi_GetLeftArmY();
            LeftSlider = LiMoRecv.KiWi_GetLeftSlider();

            RightArmX = LiMoRecv.KiWi_GetRightArmX();
            RightArmY = LiMoRecv.KiWi_GetRightArmY();
            RightSlider = LiMoRecv.KiWi_GetRightSlider();

            Foot1 = LiMoRecv.KiWi_GetFoot1();
            Foot2 = LiMoRecv.KiWi_GetFoot2();
            Foot3 = LiMoRecv.KiWi_GetFoot3();

            SetLeftTrigger();
            SetLeftAction();
            SetRightTrigger();
            SetRightAction();
        }

        void SetLeftTrigger()
        {
            int Tvalue = LiMoRecv.KiWi_GetLeftTrigger();
            LeftTriggerDown = false;
            LeftTriggerUp = false;
            if(Tvalue == 0)
            {
                if(LeftTrigger)
                {
                    LeftTriggerUp = true;
                }
                LeftTrigger = false;
            }
            else
            {
                if (!LeftTrigger)
                {
                    LeftTriggerDown = true;
                }
                LeftTrigger = true;
            }
        }
        void SetLeftAction()
        {
            int Tvalue = LiMoRecv.KiWi_GetLeftAction();
            LeftActionDown = false;
            LeftActionUp = false;
            if (Tvalue == 0)
            {
                if (LeftAction)
                {
                    LeftActionUp = true;
                }
                LeftAction = false;
            }
            else
            {
                if (!LeftAction)
                {
                    LeftActionDown = true;
                }
                LeftAction = true;
            }
        }

        void SetRightTrigger()
        {
            int Tvalue = LiMoRecv.KiWi_GetRightTrigger();
            RightTriggerDown = false;
            RightTriggerUp = false;
            if (Tvalue == 0)
            {
                if (RightTrigger)
                {
                    RightTriggerUp = true;
                }
                RightTrigger = false;
            }
            else
            {
                if (!RightTrigger)
                {
                    RightTriggerDown = true;
                }
                RightTrigger = true;
            }
        }

        void SetRightAction()
        {
            int Tvalue = LiMoRecv.KiWi_GetRightAction();
            RightActionDown = false;
            RightActionUp = false;
            if (Tvalue == 0)
            {
                if (RightAction)
                {
                    RightActionUp = true;
                }
                RightAction = false;
            }
            else
            {
                if (!RightAction)
                {
                    RightActionDown = true;
                }
                RightAction = true;
            }
        }
    }
}