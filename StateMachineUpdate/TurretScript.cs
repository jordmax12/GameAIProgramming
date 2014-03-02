using UnityEngine;
using System.Collections;

public class TurretScript : MonoBehaviour {
	[SerializeField]
	public GameObject Bullet;
	public float distance = 3.0f;
	public float secondsBetweenShots = 0.75f;
	public GameObject followThis;
	private Transform target;
	private float timeStamp = 0.0f;
	
	void Awake () {
		target = followThis.transform;
	}
	
	void Fire() 
	{
		GameObject bullet = (GameObject)Instantiate(Bullet, transform.position , transform.rotation);
		BulletBehavior behavior = bullet.GetComponent<BulletBehavior>();
		behavior.origin = this.transform.position;
		behavior.destination = target.transform.position;
		Debug.Log ("FIRE");
	}
	
	void Update () {
		if (Time.time >= timeStamp && (target.position - target.position).magnitude < distance) {
					Fire ();
					timeStamp = Time.time + secondsBetweenShots;
				}
	}
}