#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>>adj[],int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
void printGraph(vector<pair<int,int>>adj[],int V){
    int v,w;
    for(int i=0;i<V;i++){
        cout<<"For "<<i<<"\n";
        for(auto it=adj[i].begin();it!=adj[i].end();it++){
            v = it->first;
            w = it->second;
            cout<<"Edge "<<v<<"with weight "<<w<<"\n";
        }
        cout<<"\n";
    }
}
int main(){
    int V=5;
    vector<pair<int,int>> adj[V];
    addEdge(adj,0,1,10);
    addEdge(adj,0,4,20);
    addEdge(adj,1,2,30);
    addEdge(adj,1,3,40);
    addEdge(adj,1,4,50);
    addEdge(adj,2,3,60);
    addEdge(adj,3,4,70);
    printGraph(adj,V);
    return 0;
}
