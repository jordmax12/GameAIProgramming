using UnityEngine;
using System.Collections;

public class PlayerScript : MonoBehaviour {
	
	// globals
	public string moveL;
	public string moveR;
	public string moveU;
	public string moveD;
	//
	public float playerSpeed;
	//
	public Vector3 tempV;
	public Vector3 _tempV;
	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
		tempV = new Vector3 ();
		tempV = transform.position;
		_tempV.x = tempV.x;
		//print ("playerPosition is " + playerPosition);
		if(Input.GetKey (moveL))
		{
			SetTransformX((transform.position.x) - playerSpeed);
		}
		if(Input.GetKey (moveR))
		{
			SetTransformX((transform.position.x) + playerSpeed);
		}

		if(Input.GetKey (moveU))
		{
			SetTransformY((transform.position.y) + playerSpeed);
		}
		if(Input.GetKey (moveD))
		{
			SetTransformY((transform.position.y) - playerSpeed);
		}
		
		else
		{
			rigidbody.angularVelocity = Vector3.zero;
		}
	}
	
	void SetTransformX(float n)
	{
		transform.position = new Vector3(n, transform.position.y, transform.position.z);
	}

	void SetTransformY(float n)
	{
		transform.position = new Vector3(transform.position.x, n, transform.position.z);
	}
}
//ONLY 50 LINES OF CODE TO MAKE A GAME LIKE FLAPPY BIRD