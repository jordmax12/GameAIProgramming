using UnityEngine;
using System.Collections;

public class DestroyOnWasShot : MonoBehaviour
{
	void WasShot()
	{
		Destroy(gameObject);
	}
}
