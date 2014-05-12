using UnityEngine;
using System.Collections;

public class HPManager : MonoBehaviour
{
	public float hp = 10;
	public Rigidbody[] gibs;
	public float explosionRadius = 1.0f;
	public float explosionPower = 100.0f;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update ()
	{
		
	}
	
	void WasShot()
	{
		hp--;
		if(hp <= 0)
		{
			Die();
		}
	}
	
	void Die()
	{
		foreach(Rigidbody gib in gibs)
		{
			Rigidbody instance = Instantiate(gib,transform.position+Random.insideUnitSphere*explosionRadius*0.5f,Random.rotation) as Rigidbody;
			instance.AddExplosionForce(explosionPower,transform.position, explosionRadius);
		}
		Destroy(gameObject);
	}
}
