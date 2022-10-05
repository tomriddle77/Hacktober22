#include<bits/stdc++.h>
using namespace std;
class graph{
int V;
list<int>*adj;
void topolog(int v,bool visited[],stack<int>&s);
public:
    graph(int V);
    void addEdge(int u,int v);
    void topologicalSort();
};
graph::graph(int V)
{

    this->V=V;
    adj=new list<int>[V];
}
void graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}
void graph::topolog(int v,bool visited[],stack<int>&s)
{
    visited[v]=true;
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
            topolog(*i,visited,s);
    }
    s.push(v);
}
void graph::topologicalSort()
{
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    stack<int>s;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            topolog(i,visited,s);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    graph g(6);
     g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 cout<<"\nTopological sort:\n";
 g.topologicalSort();
 return 0;
}
