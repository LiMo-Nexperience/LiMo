using UnityEngine;
using System.Collections;
using LiMo;
public class Inputhandler : MonoBehaviour {

    public Transform LeftArmBase;
    public Transform RightArmBase;

    public Transform LeftTarget;
    public Transform RightTarget;

    public Transform Foot1;
    public Transform Foot2;
    public Transform Foot3;

    public Transform Bullet;

    public Transform CannonBall;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update ()
    {
        LeftArmBase.localRotation = Quaternion.Euler(-LiMoInput.instance.LeftArmY, -LiMoInput.instance.LeftArmX, 0);
        LeftArmBase.localPosition = new Vector3(0, 0, LiMoInput.instance.LeftSlider*0.3f);

        RightArmBase.localRotation = Quaternion.Euler(-LiMoInput.instance.RightArmY, -LiMoInput.instance.RightArmX, 0);
        RightArmBase.localPosition = new Vector3(0, 0, LiMoInput.instance.RightSlider * 0.3f);

        Foot1.localRotation = Quaternion.Euler(LiMoInput.instance.Foot1*30, 0, 0);
        Foot2.localRotation = Quaternion.Euler(LiMoInput.instance.Foot2*30, 0, 0);
        Foot3.localRotation = Quaternion.Euler(LiMoInput.instance.Foot3*30, 0, 0);

        //if (LiMoInput.instance.LeftTriggerDown)
        //{
        //    Instantiate(Bullet, LeftTarget.position, LeftTarget.rotation);
        //    StartCoroutine("TopHit");
        //}

        //if (LiMoInput.instance.RightTriggerDown)
        //{
        //    Instantiate(Bullet, RightTarget.position, RightTarget.rotation);
        //    StartCoroutine("BackHit2");
        //}

        //if (LiMoInput.instance.LeftActionDown)
        //{
        //    Instantiate(CannonBall, LeftTarget.position, LeftTarget.rotation);
        //    StartCoroutine("BackHit3");
        //}

        //if (LiMoInput.instance.RightActionDown)
        //{
        //    Instantiate(CannonBall, RightTarget.position, RightTarget.rotation);
        //    StartCoroutine("BackHit4");
        //}

    }

    IEnumerator LeftHit()
    {
        LiMoRecv.SendVibEffect((int)LiMoConstant.ChairVibratorID.c_VIBID_Chair_Top_Left+ (int)LiMoConstant.ChairVibratorID.c_VIBID_Chair_Bottom_Left, 180, 200);
        yield return new WaitForSeconds(0.15f);

        LiMoRecv.SendVibEffect((int)LiMoConstant.ChairVibratorID.c_VIBID_Chair_Top_Left + (int)LiMoConstant.ChairVibratorID.c_VIBID_Chair_Bottom_Left, 120, 200);
    }

    IEnumerator RightHit()
    {
        LiMoRecv.SendVibEffect((int)LiMoConstant.ChairVibratorID.c_VIBID_Chair_Top_Right + (int)LiMoConstant.ChairVibratorID.c_VIBID_Chair_Bottom_Right, 180, 200);
        yield return new WaitForSeconds(0.15f);

        LiMoRecv.SendVibEffect((int)LiMoConstant.ChairVibratorID.c_VIBID_Chair_Top_Right + (int)LiMoConstant.ChairVibratorID.c_VIBID_Chair_Bottom_Right, 120, 200);
    }

    IEnumerator BigHit()
    {
        LiMoRecv.SendVibEffect((int)LiMoConstant.ChairVibratorID.c_VIBID_Chair_Center_Center, 120, 200);
        yield return new WaitForSeconds(0.15f);
        LiMoRecv.SendVibEffect((int)LiMoConstant.ChairVibratorID.c_VIBID_Chair_ALL, 180, 300);
        yield return new WaitForSeconds(0.2f);
        LiMoRecv.SendVibEffect((int)LiMoConstant.ChairVibratorID.c_VIBID_Chair_Center_Center, 120, 100);
    }

}
