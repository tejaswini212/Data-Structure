#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list <int> *adj;
    int adjMat[20][20]={0};
    public:
        Graph(int V){
            this->V = V;
            adj=new list<int> [V];
        }
        void add_edge(int v,int w){
            adj[v].push_back(w);
            adj[w].push_back(v);
            adjMat[v][w]=1;
            adjMat[w][v]=1;
        }
        void dispMat(int v){
            int i,j;
            for(i=0;i<v;i++){
                for(j=0;j<v;j++){
                    cout<<adjMat[i][j]<<" ";                 
                }
                cout<<"\n";
            }
        }
        void BFS(int s){
            bool *visited = new bool[V];
            for(int i=0;i<V;i++)
                visited[i]=false;
            list<int> queue;
            visited[s]=true;
            queue.push_back(s);
            list<int>::iterator it;
            while(!queue.empty()){
                s = queue.front();
                cout<<s<<" ";
                queue.pop_front();
                for(it=adj[s].begin();it!=adj[s].end();++it){
                    if(!visited[*it]){
                        visited[*it] = true;
                        queue.push_back(*it);
                    }
                }
             }
             cout<<"\n";
        }
};

int main()
{
    Graph g(6);
    g.add_edge(0, 4);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(1, 5);
    g.add_edge(2, 3);
    g.add_edge(2, 5);
    g.add_edge(5, 3);
    g.add_edge(5, 4);
    g.dispMat(6);
    cout<<"Following is the breadth first traversal\n";
    g.BFS(2);
    return 0;
}

