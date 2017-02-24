using UnityEngine;
using System.Collections;
using LiMo;

public class Logger : MonoBehaviour {

  
	// Use this for initialization
	void Start () {
        //Application.runInBackground = true;
        Debug.Log(Input.GetJoystickNames().Length);
        foreach (string jn in Input.GetJoystickNames())
        {
            Debug.Log("{"+jn+"}");
        }

	}

    int LCnt = 199;
    int RCnt = 199;

    float LeftRemainTime = 0;
	// Update is called once per frame
	void Update () {
        //Debug.Log(Input.GetAxis("Horizontal") + "," + Input.GetAxis("Vertical"));
        //for(int i=1; i<= 28;i++)
        //{
        //    string dname;
        //    dname = "H"+i;
        //    float value1 = Input.GetAxisRaw(dname) * 1000;
        //    float value2 = Input.GetAxis(dname) * 1000;

        //    Debug.Log(dname +"," +value1+","+value2);
        //}

        //if (Input.GetButtonDown(InputMap.instance.GetLeftTriggerName()))
        //{
        //    KiWiRecv.SendVibEffectSmooth(0, (uint)LCnt, 150);
            
        //}

        if (LiMoInput.instance.LeftTriggerDown)
        {
            LeftRemainTime -= Time.deltaTime;
            if (LeftRemainTime <= 0)
            {
                LeftRemainTime = 0.2f;
                //KiWiRecv.SendVibEffectSmooth(0, (uint)LCnt, 150);
                LiMoRecv.SendVibEffect(0, (int)LCnt, 150);
            }

        }
        else
        {
            LeftRemainTime = 0;
        }

        if (LiMoInput.instance.LeftActionDown)
        {
            LCnt -= 10;
            if (LCnt <= 0) LCnt = 199;

        }


        if (LiMoInput.instance.RightTriggerDown)
        {
            LiMoRecv.SendVibEffect(3, (int)RCnt, 150);

            RCnt -= 10;
            if (LCnt <= 0) RCnt = 199;
        }
        
	}

    void OnGUI()
    {
        for (int i = 1; i < 10; i++)
        {
            string dname;
            dname = "J1_" + i;
            float value1 = Input.GetAxis(dname) * 125;
            float value2 = Input.GetAxisRaw(dname) * 125;

            //    Debug.Log(dname +"," +value1+","+value2);
            GUI.Label(new Rect(10, i*20, 200, 50), dname+":"+value1+","+value2+","+(value2-value1));
        }

        GUI.Label(new Rect(10, 11 * 20, 200, 50), "J1_Trigger" + ":" + LiMoInput.instance.LeftTrigger);
        GUI.Label(new Rect(10, 12 * 20, 200, 50), "J1_Action" + ":" + LiMoInput.instance.LeftAction);


        GUI.Label(new Rect(10, 18 * 20, 200, 50), "Dval" + LCnt + ", " + RCnt);


        for (int i = 1; i < 10; i++)
        {
            string dname;
            dname = "J2_" + i;
            //float value1 = Input.GetAxisRaw(dname) * 1000;
            float value1 = Input.GetAxis(dname) * 125;
            float value2 = Input.GetAxisRaw(dname) * 125;

            //    Debug.Log(dname +"," +value1+","+value2);
            GUI.Label(new Rect(220, i * 20, 200, 50), dname + ":" + value1 + "," + value2 + "," + (value2 - value1));
        }

        GUI.Label(new Rect(220, 10 * 20, 200, 50), "J2_LRSelect" + ":" + Input.GetButton("J2_LRSelect"));
        GUI.Label(new Rect(220, 11 * 20, 200, 50), "J2_Trigger" + ":" + Input.GetButton("J2_Trigger"));
        GUI.Label(new Rect(220, 12 * 20, 200, 50), "J2_Action" + ":" + Input.GetButton("J2_Action"));
        GUI.Label(new Rect(220, 13 * 20, 200, 50), "J2_Cancel" + ":" + Input.GetButton("J2_Cancel"));

        //GUI.Label(new Rect(10, 15 * 20, 200, 50), "LLimit" + ":" + Input.GetButton("LLimit"));
        //GUI.Label(new Rect(10, 16 * 20, 200, 50), "RLimit" + ":" + Input.GetButton("RLimit"));
        //GUI.Label(new Rect(10, 16 * 20, 200, 50), "RLimit" + ":" + Input.GetButton("RLimit"));

        
        
    }

}
