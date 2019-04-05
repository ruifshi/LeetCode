// A simple C++ implementation to find minimum  
// spanning tree for adjacency representation. 
#include "stdafx.h"
#include <vector>

using namespace std;

//https://www.programiz.com/dsa/prim-algorithm

#define V 5 

// Returns true if edge u-v is a valid edge to be 
// include in MST. An edge is valid if one end is 
// already included in MST and other is not in MST. 
bool isValidEdge(int u, int v, vector<bool> inMST)
{
	if (u == v)
		return false;
	if (inMST[u] == false && inMST[v] == false)
		return false;
	else if (inMST[u] == true && inMST[v] == true)
		return false;
	return true;
}

void primMST(int cost[][V])
{
	vector<bool> inMST(V, false);

	// Include first vertex in MST 
	inMST[0] = true;

	// Keep adding edges while number of included 
	// edges does not become V-1. 
	int edge_count = 0, mincost = 0;
	while (edge_count < V - 1) {

		// Find minimum weight valid edge.   
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (cost[i][j] < min) {
					if (isValidEdge(i, j, inMST)) {
						min = cost[i][j];
						a = i;
						b = j;
					}
				}
			}
		}
		if (a != -1 && b != -1) {
			printf("Edge %d:(%d, %d) cost: %d \n",
				edge_count++, a, b, min);
			mincost = mincost + min;
			inMST[b] = inMST[a] = true;
		}
	}
	printf("\n Minimum cost= %d \n", mincost);
}

/*
// Prints shortest paths from src to all other vertices
void Graph::primMST()
{
	// Create a priority queue to store vertices that
	// are being preinMST. This is weird syntax in C++.
	// Refer below link for details of this syntax
	// http://geeksquiz.com/implement-min-heap-using-stl/
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

	int src = 0; // Taking vertex 0 as source

	// Create a vector for keys and initialize all
	// keys as infinite (INF)
	vector<int> key(V, INF);

	// To store parent array which in turn store MST
	vector<int> parent(V, -1);

	// To keep track of vertices included in MST
	vector<bool> inMST(V, false);

	// Insert source itself in priority queue and initialize
	// its key as 0.
	pq.push(make_pair(0, src));
	key[src] = 0;

	// Looping till priority queue becomes empty 
while (!pq.empty())
{
	// The first vertex in pair is the minimum key 
	// vertex, extract it from priority queue. 
	// vertex label is stored in second of pair (it 
	// has to be done this way to keep the vertices 
	// sorted key (key must be first item 
	// in pair) 
	int u = pq.top().second;
	pq.pop();

	inMST[u] = true;  // Include vertex in MST 

	// 'i' is used to get all adjacent vertices of a vertex 
	list< pair<int, int> >::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		// Get vertex label and weight of current adjacent 
		// of u. 
		int v = (*i).first;
		int weight = (*i).second;

		//  If v is not in MST and weight of (u,v) is smaller 
		// than current key of v 
		if (inMST[v] == false && key[v] > weight)
		{
			// Updating key of v 
			key[v] = weight;
			pq.push(make_pair(key[v], v));
			parent[v] = u;
		}
	}
}

// Print edges of MST using parent array 
for (int i = 1; i < V; ++i)
	printf("%d - %d\n", parent[i], i);
}
*/