using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class Node : MonoBehaviour 
{
	public GameObject[] neighbors;

	public GameObject goal;

	void OnDrawGizmos() //editor function, if gizmos is turned on
	{
		Gizmos.DrawWireCube(transform.position, Vector3.one);
		foreach(GameObject neighor in neighbors)
		{
			Gizmos.DrawLine (transform.position, neighor.transform.position);
			Gizmos.DrawWireSphere(neighor.transform.position, 0.25f);
	    }

		if(goal)
		{
			Gizmos.color = Color.green;
			GameObject current = gameObject;

			Stack<GameObject> path = DijkstraAlgorithm.Dijkstra(GameObject.FindGameObjectsWithTag("Node"), gameObject, goal);

			foreach(GameObject obj in path)
			{
				Gizmos.DrawWireSphere(obj.transform.position, 1.0f);

				Gizmos.DrawLine(current.transform.position, obj.transform.position);
				current = obj;
			}
		}
	}
}
