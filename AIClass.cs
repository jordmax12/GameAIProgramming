using UnityEngine;
using System.Collections;

public class AIClass : MonoBehaviour
{

	public GameObject bullet;
	int bulletCount;
	float stunned;

	public enum CombatAIStates
	{
		Firing = 0,
		Stunned = 1,
		Reloading = 2,
		Following = 3,
		Idle = 4
	}
	
	public CombatAIStates currentState = CombatAIStates.Firing;
		
	void Update()
	{

		switch (currentState) 
		{
		case CombatAIStates.Firing:
			++bulletCount;
			Instantiate(bullet, transform.position, transform.rotation);
			Debug.Log ("Firing. Bullet: ");
			Debug.Log (bulletCount);
			if(bulletCount >= 5)
			{
				currentState = CombatAIStates.Stunned;
				bulletCount = 0;
			}
			break;

		case CombatAIStates.Stunned:
				Debug.Log ("Stunned.");

			//currentState = CombatAIStates.Firing;
			break;
		}



	}
}
