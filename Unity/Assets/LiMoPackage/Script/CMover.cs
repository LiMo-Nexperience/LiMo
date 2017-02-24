using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using LiMo;

public class CMover : MonoBehaviour {

    Vector3 moveDirection  = Vector3.zero;
    public float speed = 5;
    public float Rspeed = 0.1f;



    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {

        CharacterController controller = GetComponent<CharacterController>();


        //if(LiMoInput.instance.Foot1 > 0.5f)
        //{
        //    speed += (LiMoInput.instance.Foot1 - 0.5f) * 5;
        //}
        //if (LiMoInput.instance.Foot2 > 0.5f)
        //{
        //    speed += (LiMoInput.instance.Foot2 - 0.5f) * 5;
        //}

        float gravity = -9.81f * Time.deltaTime;

        //moveDirection = transform.forward * speed;



        

        
        

        moveDirection = transform.TransformDirection(Input.GetAxis("Horizontal"), gravity, Input.GetAxis("Vertical"));
        moveDirection *= speed;

        controller.Move(moveDirection * Time.deltaTime);

        float rvalue = 0;
        if (Input.GetKey("z"))
            rvalue += 1;
        if (Input.GetKey("c"))
            rvalue -= 1;

        Quaternion rot = transform.rotation;
        float roty = rot.eulerAngles.y;

        roty += rvalue * Rspeed;

        transform.rotation = Quaternion.Euler(rot.eulerAngles.x, roty, rot.eulerAngles.z);
    }
}
