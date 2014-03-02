using UnityEngine;
using System.Collections;

public class TimedBulletDestroyer : MonoBehaviour {
	
	public float DestroyTime;
	// Use this for initialization
	void Start () {
		StartCoroutine ("DestroyMe");
	}
	
	IEnumerator DestroyMe()
	{
		yield return new WaitForSeconds(DestroyTime);
		Destroy (gameObject);
	}
}