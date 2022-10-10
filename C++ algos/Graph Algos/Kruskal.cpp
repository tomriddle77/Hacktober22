#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

bool cmp(node a, node b){
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &par){
    //for individual single component 
    if(u == par[u]) return u;
    
    //path compression : 
    return par[u] = findPar(par[u],par); 
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findPar(u,parent);
    v = findPar(v,parent);
    //when the ranks are different, attach the smaller component to larger component
    //when smaller attached to larger, rank of larger doesn't increase
    if(rank[u] < rank[v]){
        parent[u] = v;
    }

    else if(rank[u] > rank[v]){
        parent[v] = u;
    }
    
    //when similar rank components are joined, attach anyone to the other
    //increase the rank of attached-to component : 
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main(){
    int n,m;
    cin>>n,m;

    vector<node> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    
    sort(edges.begin(),edges.end(),cmp);
    
    //considering the elements of graph as individual components : 
    vector<int> parent(n);
    for(int i=0;i<n;i++) parent[i] = i;

    vector<int> rank(n,0);
    int mstCost=0;
    vector<pair<int,int>> mst;
    for(auto it : edges){
        //including the edges in which nodes have different parents :
        if(findPar(it.u,parent) != findPar(it.v,parent)){
            mstCost += it.wt;
            mst.push_back({it.u,it.v});
            Union(it.u,it.v,parent,rank);
        }
    }
    cout<<mstCost<<"\n";
    for(auto it : mst){
        cout<<it.first<<" - "<<it.second<<"\n";
    }
return 0;
}
