using UnityEngine;
using System.Collections;

public class CameraFollow : MonoBehaviour 
{
	public int distance = 25;
	public GameObject followThis;
	public Transform target;

	void Start()
	{
		target = followThis.transform;
	}
	
	
	void Update()
	{	
		target = GameObject.FindWithTag ("Player").transform;
		float x = target.position.x;
		float y = target.position.y + distance;
		float z = target.position.z;
		transform.position = new Vector3 (x,y,z);
	}
}
