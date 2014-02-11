using UnityEngine;
using System.Collections;

public class AIScript : MonoBehaviour {
	private PlayerScript GO;
	public float position;
	public Vector3 PStempV;

	// Use this for initialization
	void Start () {
		GO = GameObject.Find("Player").GetComponent<PlayerScript>();
	}

	void Awake() {

	}
	
	// Update is called once per frame
	void Update () {
		int stop = 0;

		if (stop == 0)
		{
			PStempV = transform.position;
			/*PStempV.x -= 10;
			transform.position = (GO.tempV - PStempV);*/
			PStempV.x = GO._tempV.x - 10;
			transform.position = PStempV;
			++stop;
		}

	}

	void Test() {


	}
}
