using UnityEngine;
using System.Collections;
using System.Collections.Generic;



public class DijkstraAlgorithm 
{

	public static Stack<GameObject> Dijkstra(GameObject[] Graph, GameObject source, GameObject target)
	{

		Dictionary<GameObject, float> dist = new Dictionary<GameObject, float>();
		Dictionary<GameObject, GameObject> previous = new Dictionary<GameObject, GameObject>(); //previous NODE to the node that is currently on this script
		List<GameObject> Q = new List<GameObject>();

		foreach(GameObject v in Graph)
		{
			dist[v] = Mathf.Infinity;
			//for all gameobjects (nodes) it will insert it into our dictionary as a key (kind of like a vector in c++)
			previous[v] = null;
			Q.Add (v);

		}

		dist[source] = 0;

		while(Q.Count > 0)
		{
			float shortestDistance = Mathf.Infinity;
			GameObject shortestDistanceNode = null;
			foreach(GameObject obj in Q)
			{
				if(dist[obj] < shortestDistance) //very complicated if statement that basically finds the shortest distance based on whichever gameobject distance is not infinity.
				{
					shortestDistance = dist[obj];
					shortestDistanceNode = obj;
				}
			}

			GameObject u = shortestDistanceNode;
			Q.Remove (u);

			//Check to see if we made it to target
			if(u == target)
			{
				Stack<GameObject> S = new Stack<GameObject>();
				while(previous[u] != null)
				{
					S.Push (u);
					u = previous[u];
				}
				return S;
			}

			if(dist[u] == Mathf.Infinity)
			{
				break;
			}

			foreach(GameObject v in u.GetComponent<Node>().neighbors)
			{
				float alt = dist[u] + (u.transform.position - v.transform.position).magnitude;

				if (alt < dist[v])
				{
					dist[v] = alt;
					previous[v] = u;
				}
			}
		}
		return null;
	}
}

/*DIJKSTRA PSEUODCODE
 * function Dijkstra(Graph, source):
 *      for each vertex v in Graph:                                // Initializations
 *          dist[v]  := infinity ;                                  // Unknown distance function from 
 *                                                                 // source to v
 *          previous[v]  := undefined ;                             // Previous node in optimal path
 *      end for                                                    // from source
 *
 *      dist[source]  := 0 ;                                        // Distance from source to source
 *      Q := the set of all nodes in Graph ;                       // All nodes in the graph are
 *                                                                 // unoptimized – thus are in Q
 *      while Q is not empty:                                      // The main loop
 *          u := vertex in Q with smallest distance in dist[] ;    // Source node in first case
 *          remove u from Q ;
 *          if dist[u] = infinity:
 *              break ;                                            // all remaining vertices are
 *          end if                                                 // inaccessible from source
 *
 *          for each neighbor v of u:                              // where v has not yet been 
 *                                                                 // removed from Q.
 *              alt := dist[u] + dist_between(u, v) ;
 *              if alt < dist[v]:                                  // Relax (u,v,a)
 *                  dist[v]  := alt ;
 *                  previous[v]  := u ;
 *                  decrease-key v in Q;                           // Reorder v in the Queue (that is, heapify-down) 
 *              end if
 *          end for
 *      end while
 *      return dist[], previous[];
 *  end function
 * 
 * 
 * */