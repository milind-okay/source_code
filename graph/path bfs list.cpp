#include<iostream>
#include <list>

using namespace std;
int pd[100];
// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
   pd[s] = -1;
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        //pd[s]=-1;
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                pd[*i]=s;
                queue.push_back(*i);
            }
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    int v,a,s,x,y,n,i,e;
    cin>>n>>e;
    Graph g(n+1);
    for(i=1;i<=e;i++)
    {
        cin>>x>>y;
        g.addEdge(x,y);
        g.addEdge(y,x);
    }


    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    cin>>s;
    g.BFS(s);
    cin>>v;

while(1)
        {
            if(v==-1)
            {
                break;
            }
            else if(v==s)
            {
                cout<<v<<" ";
                break;
            }
            else
            {
                cout<<v<<" ";
                v=pd[v];
            }
        }cout<<endl;
    return 0;
}
