using UnityEngine;
using System.Collections;

public class BulletBehavior : MonoBehaviour {

	/*// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		if (rigidbody.velocity.magnitude <= 0.5)
						Destroy (gameObject);
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
			if(collision.gameObject.tag == "SolidObject")
			{
				Destroy(gameObject);
			}
			if(collision.gameObject.tag == "Player")
			{
				Destroy(gameObject);
			}
		}
	}
	*/

	private const float DefaultSpeed = 1.0f;
	private float startTime;
	
	public Vector3 destination;
	public Vector3 origin;
	public float? speed;
	
	public void Start()
	{
		speed = speed ?? DefaultSpeed;
		startTime = Time.time;
	}
	
	public void Update()
	{
		float fracJourney = (Time.time - startTime) * speed.GetValueOrDefault();
		this.transform.position = Vector3.Lerp (origin, destination, fracJourney);
	}
}
