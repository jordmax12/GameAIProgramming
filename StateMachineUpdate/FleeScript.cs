using UnityEngine;
using System.Collections;

public class FleeScript : MonoBehaviour {
	public AIClass a;
	public int nextStateClicker;//change to private
	public float FleeTime;
	public GameObject target;
	public Transform targetTrans;

	public float maxVel;
	// Use this for initialization
	void Start () 
	{
		Debug.Log ("Player has obtained coin, flee mode!");
		ChangeStateFlee ();
		target = GameObject.Find ("Player");
		targetTrans = target.transform;
		maxVel = 28;
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	public enum FleeState
	{
		FSearch,
		FFlee,
	}

	public FleeState fleeState;

	IEnumerator FSearchState()
	{
		fleeState = FleeState.FFlee;
		yield return 0;

	}

	IEnumerator FFleeState()
	{
		Vector3 distance = targetTrans.position - transform.position;
		float updatesAhead = distance.magnitude / maxVel;
		Vector3 movePosition = target.transform.position + target.transform.rigidbody.velocity * updatesAhead;
		yield return (movePosition);
	}

	/*IEnumerator FleeTimer()
	{

	} Set Later */

	void ChangeStateFlee()
	{
		StartCoroutine(FSearchState ());
	}

	void ChangeStateSearch()
	{
		StartCoroutine(FFleeState());
	}
}
