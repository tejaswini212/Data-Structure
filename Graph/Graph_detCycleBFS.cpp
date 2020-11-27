#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool cyclic_helper(vector<int>adj[],int s,int V,vector<bool>& visited){
    vector<int> parent(V,-1);
    queue<int> q;
    
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                parent[v]=u;
            }
            else if(parent[u]!=v)
                return true;
        }
    }
    return false;
}

bool isCyclic(vector<int>adj[],int V){
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++)
        if(!visited[i] && cyclic_helper(adj,i,V,visited))
            return true;
   return false;
}

int main(){
    int V=4;
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 1, 2); 
    //addEdge(adj, 2, 0); 
    addEdge(adj, 2, 3); 
  
    if (isCyclic(adj, V)) 
        cout << "Yes\n"; 
    else
        cout << "No\n";
    return 0;
}
