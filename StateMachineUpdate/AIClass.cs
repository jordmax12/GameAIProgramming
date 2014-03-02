using UnityEngine;
using System.Collections;

public class AIClass : MonoBehaviour
{
	public FleeScript scriptFlee;
	public AIClass scriptAI;

	public NavMeshAgent agent;
	
	//Ammo in gun before reloading is required
	public int ammo = 30;
	public int maxAmmo = 30;
	//Number of bullets a gun fires in sequence on 1 trigger pull
	public int chamber = 3;
	public int maxChamber = 3;
	//Pause between bursts or mouse presses, set to 0 for fully automatic
	public double chamberTime = 120;
	//How fast a gun fires in RPS
	public int fireRate = 7;
	public int fireTimer = 0;
	//How fast a gun can reload
	public int reloadTime = 3;
	public int reloadTimer = 0;
	//Number of bullets fired per shot
	public int bulletsFired = 1;
	public GameObject bulletClone;
	
	//Acceptable degrees as to which the AI will begin firing at its target
	public int firingAngle = 5;
	//Vision cone of degrees to left and right
	public int visionAngle = 35;
	public int visionDistance = 100;
	public int vRotationSpeed = 3;
	public int vIdleTimer = 0;
	public int vIdleTime = 300;
	public int searchTimer = 0;
	public int searchTime = 300;
	
	public int mIdleTimer = 0;
	public int mIdleTime = 300;
	
	
	public bool isFocusedOnPlayer = false;
	public bool seesPlayer = false;
	//
	public bool fleeBool;
	public bool flee;
	public enum MovementState
	{
		MSearch,
		MMoving,
		MIdle,
	}
	public enum CombatState
	{
		CFiring,
		CReloading,
		CIdle,
	}
	public enum ViewState
	{
		VSearch,
		VFocus,
		VIdle,
	}

	public enum FleeState
	{
		FSearch,
		FMoving,
		FIdle
	}
	public CombatState combatState;
	public ViewState viewState;
	public MovementState movementState;
	
	//Search state (knows where player is and will head to the player's location)
	IEnumerator MSearchState ()
	{	
		mIdleTimer = 0;
		int stuckTimer = 0;
		
		while (movementState == MovementState.MSearch)
		{
			//I've arrived at my location, if idle too long, then go back to idle state
			if(Vector3.Distance(transform.position,agent.destination) < 3)
				mIdleTimer++;
			//I'm stuck and haven't moved in a while, go back to idle state
			if(agent.velocity.magnitude < 1)
				stuckTimer++;
			if(seesPlayer || mIdleTimer > mIdleTime + 200 || stuckTimer > 300  && !flee)
			{
				agent.destination = transform.position;
				movementState = MovementState.MIdle;
			}
			yield return 0;
		}
			NextMovementState();
	}
	//Wander state
	IEnumerator MMovingState ()
	{	
		while (movementState == MovementState.MMoving)
		{
			//Wander code... Create a random angle and convert it to radians
			float randomAngle = (float)(3.14/180)*Random.Range(0,360);
			//Normalize direction vector, as we will be using it to calculate where we place the circle
			Vector3 tempV = agent.velocity;
			Vector3.Normalize (tempV);
			//Using our relative position, 5 units in front of us. Use the generated angle to find the point on the circle that we want to go to
			agent.destination =  transform.position + tempV * 3 + new Vector3(Mathf.Cos (randomAngle)*3,0,Mathf.Sin (randomAngle)*3);
			//Check to see if we are within the arena bounds, if not, push our projected vector back inside
			if(agent.destination.x > 24)
				agent.destination = agent.destination + new Vector3(-7,0,0);
			if(agent.destination.x < -24)
				agent.destination = agent.destination + new Vector3(7,0,0);
			if(agent.destination.z > 24)
				agent.destination = agent.destination + new Vector3(0,0,-7);
			if(agent.destination.z < -24)
				agent.destination = agent.destination + new Vector3(0,0,7);
			
			if(seesPlayer)
			{
				agent.destination = transform.position;
				movementState = MovementState.MIdle;
			}
			yield return 0;
		}
						NextMovementState ();
	}
	//Not moving, if I don't see the player for awhile, then go wander
	IEnumerator MIdleState ()
	{	
		mIdleTimer = 0;
		while (movementState == MovementState.MIdle)
		{
			if(seesPlayer)
				mIdleTimer = 0;
			else
				mIdleTimer++;
			if(mIdleTimer > mIdleTime + Random.Range (-100,100)  && !flee)
				movementState = MovementState.MMoving;
			yield return 0;
		}
		if (!flee) {
						NextMovementState ();
				}
	}
	//Visual search state, randomly look around and check to see if we see the player
	IEnumerator VSearchState ()
	{	
		Transform target = GameObject.FindWithTag ("Player").transform;
		Vector3 targetPosition = target.position;
		while (viewState == ViewState.VSearch)
		{
			searchTimer--;
			//Vision Cone calculation
			Vector3 targetDir = target.position - transform.position;
			Vector3 forward = transform.forward;
			float angle = Vector3.Angle(targetDir, forward);
			//If player is within vision cone then proceed
			if (angle < visionAngle)
			{
				//Check to see if there are any object between player and myself
				RaycastHit hit;
				if (Physics.Raycast(transform.position, targetDir, out hit))
				{
					if(hit.transform == target)
					{
						seesPlayer = true;
						viewState = ViewState.VFocus;
					}
				}
			}
			//Look in another direction
			if(searchTimer < 0)
			{
				searchTimer = searchTime + Random.Range (-100,100);
				targetPosition = new Vector3(Random.Range (-100,100),transform.position.y,Random.Range (-100,100));
			}
			transform.rotation = Quaternion.Slerp(transform.rotation,Quaternion.LookRotation(targetPosition - transform.position), vRotationSpeed*Time.deltaTime);
			
			yield return 0;
		}
						NextViewState ();
	}
	//Focus on player
	IEnumerator VFocusState ()
	{	
		Transform target = GameObject.FindWithTag ("Player").transform;
		while (viewState == ViewState.VFocus)
		{
			//Vision Cone calculation
			Vector3 targetDir = target.position - transform.position;
			Vector3 forward = transform.forward;
			float angle = Vector3.Angle(targetDir, forward);
			if (angle > visionAngle)
				viewState = ViewState.VIdle;
			else
			{
				RaycastHit hit;
				//Check if there are any objects in the way
				if (Physics.Raycast(transform.position, targetDir, out hit))
				{
					if(hit.transform == target)
					{
						//Tell other AI where player is
						GameObject[] objArray = GameObject.FindGameObjectsWithTag ("Enemy");
						AIClass[] enemyArray = new AIClass[objArray.Length];
						for(int i = 0; i < enemyArray.Length; i++)
						{

							enemyArray[i] = (AIClass)objArray[i].GetComponent(typeof(AIClass));
							if(i >= enemyArray.Length/2)
							{
								//Debug.Log ("AI: I see him!"); 
								enemyArray[i].agent.destination = target.position;
							}
							else if(!flee)
								enemyArray[i].agent.destination = target.position + target.forward*5;
							enemyArray[i].movementState = MovementState.MSearch;

						}
						seesPlayer = true;
						transform.rotation = Quaternion.Slerp(transform.rotation,Quaternion.LookRotation(target.position - transform.position), vRotationSpeed*Time.deltaTime);
						//Check to see player is within sights of the gun
						if (angle < firingAngle)
						{
							//Debug.Log ("AI: Got him in my sights!");
							isFocusedOnPlayer = true;
						}
						else
							isFocusedOnPlayer = false;
					}
					else
					{
						//I no longer see the player
						//Debug.Log ("AI: Sorry guys, no longer got him");
						seesPlayer = false;
						viewState = ViewState.VIdle;
						isFocusedOnPlayer = false;
					}
				}
			}
			yield return 0;
		}
						NextViewState ();
	}
	//Visual idle state, basically the ai is just looking forward
	IEnumerator VIdleState ()
	{	
		vIdleTimer = 0;
		Transform target = GameObject.FindWithTag ("Player").transform;
		while (viewState == ViewState.VIdle)
		{
			//Vision cone calculation
			vIdleTimer++;
			Vector3 targetDir = target.position - transform.position;
			Vector3 forward = transform.forward;
			float angle = Vector3.Angle(targetDir, forward);
			//Check to see if there is an object is between the ai and the player
			if (angle < visionAngle)
			{
				RaycastHit hit;
				if (Physics.Raycast(transform.position, targetDir, out hit))
				{
					if(hit.transform == target)
					{
						seesPlayer = true;
						viewState = ViewState.VFocus;
					}
				}
			}
			if(vIdleTimer > vIdleTime && !flee)
				viewState = ViewState.VSearch;
			yield return 0;
		}
						NextViewState ();
	}
	//Firing gun state
	IEnumerator CFiringState ()
	{	
		while (combatState == CombatState.CFiring)
		{
			if(!isFocusedOnPlayer)
				combatState = CombatState.CIdle;
			fireTimer--;
			if(ammo > 0)
			{
				if(chamber > 0)
				{
					if(fireTimer <= 0)
					{
						for(int i = 0; i < bulletsFired;i++)
						{
							GameObject temp = (GameObject) Instantiate (bulletClone,transform.position + transform.forward,transform.rotation);
							temp.rigidbody.AddForce(transform.forward*500);
						}
						fireTimer = 60 / fireRate;
						ammo--;
						chamber--;
					}
				}
				else
				{
					chamber = maxChamber;
					fireTimer = (int)(60/chamberTime);
				}
			}
			else
			{
				if(!flee)
				{
				combatState = CombatState.CReloading;
				}
			}
			yield return 0;
		}
						NextCombatState ();
	}
	
	IEnumerator CReloadingState ()
	{
		reloadTimer = reloadTime * 60;
		while (combatState == CombatState.CReloading)
		{
			reloadTimer--;
			if(reloadTimer <= 0 && !flee)
			{
				ammo = maxAmmo;
				combatState = CombatState.CIdle;
			}
			yield return 0;
		}
						NextCombatState ();
	}
	
	IEnumerator CIdleState ()
	{	
		while (combatState == CombatState.CIdle)
		{
			if(isFocusedOnPlayer && !flee)
				combatState = CombatState.CFiring;
			yield return 0;
		}
						NextCombatState ();
	}
	
	void Start ()
	{
		fleeBool = false;
		flee = false;
		NextCombatState();
		NextViewState();
		NextMovementState();

		//scriptFlee.enabled = false;
	}
	void NextMovementState()
	{	
		string methodName = movementState.ToString() + "State";
		System.Reflection.MethodInfo info = GetType().GetMethod(methodName, System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
		StartCoroutine((IEnumerator)info.Invoke(this, null));
	}
	void NextCombatState ()
	{
		string methodName = combatState.ToString() + "State";
		System.Reflection.MethodInfo info = GetType().GetMethod(methodName, System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
		StartCoroutine((IEnumerator)info.Invoke(this, null));
	}
	void NextViewState ()
	{
		string methodName = viewState.ToString() + "State";
		System.Reflection.MethodInfo info = GetType().GetMethod(methodName, System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
		StartCoroutine((IEnumerator)info.Invoke(this, null));
	}

	void NextFleeState()
	{
		string methodName = viewState.ToString() + "State";
		System.Reflection.MethodInfo info = GetType().GetMethod(methodName, System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
		StartCoroutine((IEnumerator)info.Invoke(this, null));
	}
	
	void Update()
	{
		Debug.DrawLine(transform.position, transform.position+transform.forward*5, Color.red);
		if (fleeBool == true) 
		{
			flee = true;
		}

		if (flee == true) {
			//scriptAI.enabled = false;
			//scriptFlee.enabled = true;
			//Instantiate (scriptFlee);
			Destroy (this);
			gameObject.AddComponent("FleeScript");
			Debug.Log ("Disabled AIClass.");
			Debug.Log ("Enabled FleeScript.");

				}

	}

}