#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int>*adj;
    public:
        Graph(int V){
            this->V = V;
            adj = new list<int>[V];
        }

        void addEdge(int u,int v){
            adj[u].push_back(v);
        }
        void topSort();
};

void Graph::topSort(){
    //vector to store indegrees of all the vertices
    vector<int> in_degree(V,0);
    //traverse adjacency list to fill in indegrees
    for(int u=0;u<V;u++){
        list<int>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
            in_degree[*it]++;
    }
    queue<int> q;
    //enqueue all the vertices with indegree 0
    for(int i=0;i<V;i++){
        if(in_degree[i] == 0)
            q.push(i);
    }
    int count=0;
    //vector to store result of topological sort
    vector<int> top_order;
    //dequeue vertices one by one and enqueue the adjacents if their indegree becomes 0
    while(!q.empty()){
        int u=q.front();
        q.pop();
        top_order.push_back(u);
        list<int>::iterator it;
        //iterate through all the neighbouring nodes and decrement indegree
        for(it=adj[u].begin();it!=adj[u].end();it++)
            if(--in_degree[*it]==0)
                q.push(*it);
            count++;        
    }
    if(count!=V){
        cout<<"There exists a cycle in the graph\n";
        return;
    }
    for(int i=0;i<top_order.size();i++)
        cout<<top_order[i]<<" ";
    cout<<"\n";
}

int main(){
    Graph g(6);
    g.addEdge(5,2);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);
    
    cout << "Following is a Topological Sort of\n"; 
    g.topSort (); 
    return 0;
}
