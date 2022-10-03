#include<bits/stdc++.h>
using namespace std;

// BFS Traversal of an undirected and unweighted graph


// takes in 2 vertices which we need to connect
// update the adjacency list of both vertices since the graph is bidirectional
void createAndAddEdge(vector<int> adjList[], int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u); 
}



// given the source node and graph, thiis function prints the BFS traversal
void BFS(vector<int> adjList[], vector<bool> visitedVertex, int source){
  queue <int> Q; // use a queue to store nodes
  int v;
  Q.push(source);
  visitedVertex[source] = true;
  while(!Q.empty()){
    v = Q.front();
    Q.pop();
    
    // print the vertex
    cout << v << " ";
    
    // iterate over all its neighbours and push the unvisted ones into the queue
    for(auto it = adjList[v].begin(); it!=adjList[v].end(); it++){
      if(!visitedVertex[*it]){
        Q.push(*it); // Push unvisted vertex onto the queue
        visitedVertex[*it] = true;
      }
  }
    
  cout << endl;
  return;
}
  
  
  

int main(){
  int numVertices = 6;
  int source = 0;
  vector<int> adjList[numVertices];
  vector<bool> visitedVertex(numVertices, false);
  
  // create the graph
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 2);
  createAndAddEdge(adjList, 1, 5);
  createAndAddEdge(adjList, 2, 3);
  createAndAddEdge(adjList, 2, 4);
  createAndAddEdge(adjList, 3, 3);
  createAndAddEdge(adjList, 4, 4);
  createAndAddEdge(adjList, 5, 5);
  
  // run BFS on the graph
  BFS(adjList, visitedVertex, source);
  
  return 0;
}
