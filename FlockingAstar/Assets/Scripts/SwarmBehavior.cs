using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class SwarmBehavior : MonoBehaviour {


	public int droneCount = 10;
	public int offset;

	public float spawnRadius = 50f;
	public List<GameObject> drones;

	public Vector2 swarmBounds = new Vector2(300f, 300f);

	public GameObject prefab;
	// Use this for initialization
	public virtual void Start () {

		GameObject EmptyRayGameObject = new GameObject();

		if(prefab == null) //drone prefab
		{
			Debug.Log ("please assign a drone prefab."); 
			return;
		}

		GameObject droneTemp;
		drones = new List<GameObject>();
		for (int i = 0; i < droneCount; i++)
		{
			droneTemp = (GameObject) GameObject.Instantiate(prefab);

		}
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
