using UnityEngine;
using System.Collections;

public class PlayerController : MonoBehaviour 
{
	public int maxVelocity = 10;

	// Use this for initialization
	void Start ()
	{
	}
	
	// Update is called once per frame
	void Update () 
	{
		if(rigidbody.velocity.magnitude>1)
		transform.rotation = Quaternion.LookRotation(rigidbody.velocity,Vector3.up);
		if (Input.GetKey (KeyCode.W))
		{
			rigidbody.AddForce (new Vector3 (0, 0, 25));
			//transform.rotation = Quaternion.Euler (0,0,0);
		}
		if (Input.GetKey (KeyCode.S)) 
		{
			rigidbody.AddForce (new Vector3 (0, 0, -25));
			//transform.rotation = Quaternion.Euler (0,180,0);
		}
		if (Input.GetKey (KeyCode.A))
		{
			rigidbody.AddForce (new Vector3 (-25, 0, 0));
			//transform.rotation = Quaternion.Euler (0,-90,0);
		}
		if (Input.GetKey (KeyCode.D))
		{
			rigidbody.AddForce (new Vector3 (25, 0, 0));
			//transform.rotation = Quaternion.Euler (0,90,0);
		}
		if (rigidbody.velocity.magnitude > maxVelocity)
		{
			Vector3 newVelocity = rigidbody.velocity.normalized;
			newVelocity *= maxVelocity;
			rigidbody.velocity = newVelocity;
		}
	}
}
