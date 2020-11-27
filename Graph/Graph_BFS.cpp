#include<iostream>
#include<list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}
void Graph::BFS(int s){
    bool *visited = new bool[V];
    
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    
    list<int> queue;
    visited[s] = true;    
    list<int>::iterator i;
    queue.push_back(s);
    while(!queue.empty()){
         s = queue.front();
         cout<< s << " ";
         queue.pop_front(); 

         for(i=adj[s].begin();i!=adj[s].end();i++){
             if(!visited[*i]){
                  queue.push_back(*i);
                  visited[*i]=true;
             }
         }
    }
}

int main(){
    Graph g(6);
    g.addEdge(0,1);    
    g.addEdge(1,4);    
    g.addEdge(0,2);    
    g.addEdge(2,5);    
    g.addEdge(0,3);    
    g.addEdge(2,0);    
    g.addEdge(2,3);    
    g.addEdge(5,2);    
    g.addEdge(1,5);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
    cout<<"\n";  
    return 0; 
}
