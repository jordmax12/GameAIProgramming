// C#
using System;
using UnityEngine;

public class GunLook : MonoBehaviour
{
	public Transform target;
	
	void Update()
	{
		if(target != null)
		{
			transform.LookAt(target);
		}
	}
}