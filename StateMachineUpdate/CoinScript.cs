using UnityEngine;
using System.Collections;

public class CoinScript : MonoBehaviour {

	private AIClass a;
	// Use this for initialization
	void Start () {
		a = GameObject.Find("Enemy").GetComponent<AIClass>();
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnCollisionEnter(Collision collision)
	{
		if (collision.collider)
		{
			if(collision.gameObject.tag == "Enemy" || collision.gameObject.tag == "EnemyProjectile")
			{
				Physics.IgnoreCollision(rigidbody.collider,collision.collider);
				//Debug.Log ("Enemy");
			}
			if(collision.gameObject.tag == "Player")
			{
				Debug.Log ("triggered!");
				a.fleeBool = true;
				Destroy(gameObject);
			}
		}
	}
}
