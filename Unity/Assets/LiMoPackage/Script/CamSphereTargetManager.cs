using UnityEngine;
using System.Collections;
using LiMo;

public class CamSphereTargetManager : MonoBehaviour {

    // Left / Right Target은 KiWi에서 넘어옴
    public Vector3 InputLeftTargetValue = new Vector3(0, 0,0);
    public Vector3 InputRightTargetValue = new Vector3(0, 0,0);

    public Transform Camera;

    public Transform LeftArm;
    public Transform RightArm;

    public Transform LeftAimPoint;
    public Transform RightAimPoint;


    //Wrist 회전은 우선 뺀다.
    //public Transform LeftWrist;
    //public Transform RightWrist;

    public Transform LeftTargetBase;
    public Transform RightTargetBase;

    public Transform LeftTargetPosition;
    public Transform RightTargetPosition;

    float LLastDist = 3000;
    float RLastDist = 3000;

    public float RightqueueTime = 0;
    public float LeftqueueTime = 0;

    public Rigidbody Bullet;

    //public LightCannonFire LeftArmcs;
    //public LightCannonFire RightArmcs;

    //public SimpleMissileLaunch LeftMissile;
    //public SimpleMissileLaunch RightMissile;

    //구형좌표계 변경
    // Pi는 수평 각도
    // InvTheta는 수직 각도 (원래 구형좌표계는 수직 각도를 z축과의 각도로 계산한다.)
    public float InitAimDirectionPi;    //Default = 0
    public float InitAimDirectionInvTheta;  // Default = -12


    // Use this for initialization
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        /*
        //if (GameManager.instance.bGameRunning)
        {
            InputLeftTargetValue.x = InputMap.instance.GetLeftArmAxisX();
            InputLeftTargetValue.y = InputMap.instance.GetLeftArmAxisY();
            InputRightTargetValue.x = InputMap.instance.GetRightArmAxisX();
            InputRightTargetValue.y = InputMap.instance.GetRightArmAxisY();

            if (InputLeftTargetValue.x > 60) InputLeftTargetValue.x = 60;
            if (InputRightTargetValue.x < -60) InputRightTargetValue.x = -60;
            Quaternion LeftRot = Quaternion.Euler(-(InputLeftTargetValue.y + InitAimDirectionInvTheta), InputLeftTargetValue.x - InitAimDirectionPi, 0);
            Quaternion RightRot = Quaternion.Euler(-(InputRightTargetValue.y + InitAimDirectionInvTheta), InputRightTargetValue.x + InitAimDirectionPi, 0);

            LeftTargetBase.localRotation = LeftRot;
            RightTargetBase.localRotation = RightRot;

            //Make Aim Point
            {
                Vector3 LeftTarget = FindAimTarget(Camera.position, LeftTargetPosition.position);

                LeftArm.transform.LookAt(LeftTarget);

                Vector3 RightTarget = FindAimTarget(Camera.position, RightTargetPosition.position);

                RightArm.transform.LookAt(RightTarget);

            }


            if (InputMap.instance.GetLeftTrigger())
            {
                LeftqueueTime += Time.deltaTime;
                if (LeftqueueTime >= 0.3f)
                {
                    Rigidbody Bul;
                    Bul = Instantiate(Bullet, LeftAimPoint.transform.position, LeftAimPoint.transform.rotation) as Rigidbody;
                    Bul.velocity = transform.TransformDirection(Bul.transform.forward * 1000);
                    LeftqueueTime = 0;

                    LiMoRecv.SendVibEffect((uint)LiMoConstant.ChairVibratorID.c_VIBID_Left_All, 100, 100);
                }
            }

            if (InputMap.instance.GetRightTrigger())
            {
                RightqueueTime += Time.deltaTime;
                if (RightqueueTime >= 0.3f)
                {
                    Rigidbody Bul;
                    Bul = Instantiate(Bullet, RightAimPoint.transform.position, RightAimPoint.transform.rotation) as Rigidbody;
                    Bul.velocity = transform.TransformDirection(Bul.transform.forward * 1000);
                    RightqueueTime = 0;

                    LiMoRecv.SendVibEffect((uint)LiMoConstant.ChairVibratorID.c_VIBID_Right_All, 100, 100);
                }
            }

        }
         * */
    }

    Vector3 FindAimTarget(Vector3 Eye, Vector3 TargetMark)
    {
        Vector3 Target = new Vector3();
        Vector3 Direction = TargetMark - Eye;
        Ray ray = new Ray(Eye, Direction);
        RaycastHit hitInfo;
        if (Physics.Raycast(ray, out hitInfo, 3000))
        {
            //ProcessCollision(hitInfo.collider);
            Target = hitInfo.point;
        }
        else
        {
            Target = TargetMark + Direction.normalized * 500;
        }
        return Target;
    }

}
