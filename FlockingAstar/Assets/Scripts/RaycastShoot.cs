using UnityEngine;
using System.Collections;

public class RaycastShoot : MonoBehaviour
{
	public string fireButton = "Fire1";
	
	// Use this for initialization
	void Start ()
	{
	
	}
	
	// Update is called once per frame
	void Update ()
	{
		if(Input.GetButtonDown(fireButton))
		{
			//Shoot a ray from the center of the screen and send a message to any object hit
			Ray ray = Camera.main.ViewportPointToRay(new Vector3(0.5f,0.5f,0.0f));
			
			RaycastHit info;
			
			if(Physics.Raycast(ray, out info))
			{
				info.collider.gameObject.SendMessage("WasShot",info,SendMessageOptions.DontRequireReceiver);
			}
		}
	}
}
