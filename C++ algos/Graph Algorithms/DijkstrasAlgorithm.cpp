/*

Dijkstra's Algorithm
--------------------
Used to find the shortest distance from src node to all other nodes in a weighted graph with no negative weights. Graph can be directed or undirected.

It is a single source shortest path algo since from a single source, we can find the shortest distance to all other vertices of the graph.


Steps
-----
Initially, src node has distance 0 and all other nodes have distance inf as they are unvisited.
We need to maintain distance of all nodes. Using an array will be time consuming since everytime we will have to loop to find the node with minimum
distance. Using a set, we can find node with min distance in O(1) and remove it in O(logn). Set stores values in sorted manner.

Start from src node. Explore its neighbours and update their distance:
if(dist[node] > dist[parent] + edge_wt) => dist[node] = dist[parent] + edge_wt
After updating a nodes distance, add that node to set.
Once all neighbours of a node have been explored, remove that node from the set.

Once we have picked a node from set, its distance is finalized. ie that nodes min distance is found.




*/




#include <bits/stdc++.h>
using namespace std;



template<typename T>
class Graph {

	map<T, list<pair<T, int>>> l;

public:

	void addEdge(T x, T y, int wt) {
		l[x].push_back({y, wt});
		l[y].push_back({x, wt});
	}

	void print() {
		for (auto p : l) {
			T node = p.first;
			cout << node << " => ";

			for (auto nbr : l[node]) {
				cout << "(" << nbr.first << "," << nbr.second << ") ";
			} cout << endl;

		}
	}

	void sssp(T src) {


		unordered_map<T, int> dist;

		// Initialising distance to inf
		for (auto p : l) {
			T node = p.first;
			dist[node] = INT_MAX;
		}
		// Dist of src from itself = 0
		dist[src] = 0;

		// Set to find out node with minimum distance
		// 		dist, node
		set<pair<int, T>> s;
		s.insert({0, src});

		while (!s.empty()) {
			// Find the pair at the front
			pair<int, T> p = *s.begin();
			T currNode = p.second;

			int currNodeDistance = p.first;
			// Remove finalised node
			s.erase(s.begin());

			// Visit nbrs of curr node
			for (auto nbr : l[currNode]) {

				T nbrNode = nbr.first;
				int nbrNodeDist = nbr.second;

				// Potential new distance = currNodeDistance + nbrNodeDist

				if (currNodeDistance + nbrNodeDist < dist[nbrNode]) {


					// Update set and map
					auto f = s.find({dist[nbrNode], nbrNode});
					if (f != s.end()) {
						s.erase(f);
					}

					dist[nbrNode] = currNodeDistance + nbrNodeDist;
					s.insert({ dist[nbrNode], nbrNode});
				}
			}

		}

		for (auto x : dist) {
			cout << x.first << " is at distance " << x.second << endl;
		}



	}

};

int main() {

	Graph<string> g;

	g.addEdge("A", "D", 1);
	g.addEdge("A", "J", 4);
	g.addEdge("D", "J", 2);
	g.addEdge("M", "J", 8);
	g.addEdge("B", "A", 2);
	g.addEdge("M", "B", 3);
	g.addEdge("A", "D", 1);

	g.print();
	cout << endl;
	g.sssp("A");
  
  return 0;

}






