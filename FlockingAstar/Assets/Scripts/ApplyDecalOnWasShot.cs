using UnityEngine;
using System.Collections;

public class ApplyDecalOnWasShot : MonoBehaviour
{
	public GameObject[] decals;
	public float offset = 0.01f;
	
	void WasShot(RaycastHit info)
	{
		foreach(GameObject decal in decals)
		{
			Quaternion rotation = Quaternion.LookRotation(info.normal);
		
			GameObject instance = Instantiate(decal, info.point+info.normal*offset, rotation) as GameObject;
			instance.transform.parent = transform;
		}
	}
}
