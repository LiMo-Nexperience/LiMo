using UnityEngine;
using System.Collections;

public class BulletMover : MonoBehaviour {

    Rigidbody rd;
    public float Speed = 10;
    public float SelfDestoryTime = 3;
	// Use this for initialization
	void Start () {
        rd = GetComponent<Rigidbody>();


	}
	
	// Update is called once per frame
	void Update () {
        rd.AddRelativeForce(0, 0, Speed, ForceMode.VelocityChange);

        SelfDestoryTime -= Time.deltaTime;
        if (SelfDestoryTime < 0) Destroy(gameObject);
	}

    void OnCollisionEnter(Collision collision)
    {
        Destroy(gameObject);

    }

}
