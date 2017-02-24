using UnityEngine;
using System.Collections;

namespace LiMo
{

	public class LiMoUserControl : MonoBehaviour 
	{

		private Vector3 m_CurrPos;
		private float m_startTime, m_deltaTime;

        public float MaxMove_surge = 30.0f;
        public float MaxMove_sway = 30.0f;
        public float MaxMove_heave = 30;
        public float MaxRot_roll = 30;
        public float MaxRot_pitch = 30;
        public float MaxRot_yaw = 30;
        public int ActuratorMaxSpeed = 400;
        public int ActuratorSmooth = 6;

		void Awake()
		{
		}

		// Use this for initialization
		void Start () 
		{
            //KiWi_MotionData_Config(5.0f, 20.0f, 30.0f, 60.0f, 60.0f, 60.0f, 500, 5);
            LiMoRecv.KiWi_MotionData_Config(ActuratorMaxSpeed, ActuratorSmooth);
            LiMoRecv.KiWi_MotionData_MaxValue(MaxMove_surge, MaxMove_sway, MaxMove_heave, MaxRot_roll, MaxRot_pitch, MaxRot_yaw);
            
            LiMoRecv.StartMotion();
        }

        void OnApplicationQuit()
        {
            LiMoRecv.StopMotion();
        }

		void OnDestroy()
		{
		}

		private float ContAngle(Vector3 fwd, Vector3 targetDir)
		{
			float angle = Vector3.Angle(fwd, targetDir);

			if (AngleDir(fwd, targetDir, Vector3.up) == -1)
			{
				angle = 360.0f - angle;
				if (angle > 359.9999f)
					angle -= 360.0f;
				return angle;
			}
			else
				return angle;
		}
		private int AngleDir(Vector3 fwd, Vector3 targetDir, Vector3 up)
		{
			Vector3 perp = Vector3.Cross(fwd, targetDir);
			float dir = Vector3.Dot(perp, up);

			if (dir > 0.0)
				return 1;
			else if (dir < 0.0)
				return -1;
			else
				return 0;
		}
		
		public void GameStart()
		{
			m_startTime = Time.unscaledTime;
		}


		void FixedUpdate () 
		{
			{
				m_deltaTime += Time.fixedDeltaTime;
				m_CurrPos = transform.position;

				Vector3 _forward = transform.forward;
				Vector3 _right = transform.right;
				Vector3 vec3 = new Vector3(_forward.x, 0, _forward.z);
				Vector3 vec4 = new Vector3(_right.x, 0, _right.z);

				float deg1 = ContAngle(_forward, vec3);
				if (_forward.y > 0)
					deg1 *= -1.0f;

				float deg2 = ContAngle(_right, vec4);
				if (_right.y < 0)
					deg2 *= -1.0f;

				Vector3 _rot = new Vector3(deg1, 0, deg2);
                LiMoRecv.KiWi_MotionData_Set((m_startTime + m_deltaTime), _rot.x, _rot.y, _rot.z, m_CurrPos.x, m_CurrPos.y, m_CurrPos.z, _forward.x, _forward.y, _forward.z);
			}
		}

		void Update()
		{
		}
	}
}