#include<iostream>
#include<list>
using namespace std;
class Graph {
int V;
list<int> *adj;
public :
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];

    }
    void addedge(int s,int d);
    void dfs(int v);
    void dfsUtil(int v,bool visited[]);



};
 void Graph :: addedge(int s,int d)
{
    adj[s].push_back(d);
}
void Graph :: dfsUtil(int v,bool visited[])
{
    visited[v]= true;
    cout<<v<<" ";
    list<int> ::iterator it;
    for(it= adj[v].begin();it!= adj[v].end();++it)
    {
        if(visited[*it] != true)
        {
            dfsUtil(*it,visited);
        }
    }
}
 void Graph :: dfs(int v)
{
    bool *visited = new bool[V];
    for(int i=0;i<V;++i)
    {
        visited[i] = false;
    }
    dfsUtil(v,visited);
}
int main()
{
    int n,j,e,x,y;

    cin>>n>>e;
    Graph g(n);
    for(j =0;j<e;j++)
    {
        cin>>x>>y;
        g.addedge(x,y);

    }
    cin>>x;
    g.dfs(x);
    return 0;
}
