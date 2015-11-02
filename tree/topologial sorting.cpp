#include<bits/stdc++.h>
using namespace std;
int arr[100001];
struct node{
    vector<int>link;
    map<int,int>mk;
    map<int,int>*mm;
    int mapsize =0,maxsum =0,weight;
    node* next = NULL;
};
class Graph
{
	int V;

	vector<node* > adj;

	void topologicalSortUtil(int v, bool visited[], vector<int> &Stack);
public:
	Graph(int V);

	void addEdge(int v, int w);

	void topologicalSort();
	void cal(vector<int> &topo);
};
void Graph:: cal(vector<int> &topo){
    vector<int>:: iterator it = Stack.begin();
	while (it!=Stack.end())
	{
		if(adj[*it]->link.size() == 0){
           mk[adj[*it]->weight] = *it;
           maxsize = 1;
           if(adj[*it]->weigh>0)
           maxsum = 2*(adj[*it]->weight);
           else
            maxsum = adj[*it]->weight;
		}else{
                vector<int>:: iterator i=adj[*it]->begin();
                for()

		}
		it++;
	}
}

Graph::Graph(int V)
{
	this->V = V;
	for(int i=0;i<V;i++){
        node *temp = new node;
        temp->weight = arr[i];
        adj.push_back(temp);
	}
}

void Graph::addEdge(int v, int w)
{
	adj[v]->link.push_back(w );
}

void Graph::topologicalSortUtil(int v, bool visited[], vector<int> &Stack)
{

	visited[v] = true;

	vector<int>::iterator i;
	for (i = adj[v]->link.begin(); i != adj[v]->link.end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);


	Stack.push_back(v);
}

void Graph::topologicalSort()
{
	vector<int> Stack;


	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
	if (visited[i] == false)
		topologicalSortUtil(i, visited, Stack);

   /* vector<int>:: iterator it = Stack.begin();
	while (it!=Stack.end())
	{
		cout << *it << " ";
		it++;
	}*/
}

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n,m,k,i,j;
    cin>>n>>m>>k;
    for(int i =0 ;i<n;i++){
        cin>>arr[i];
    }
	Graph g(n);
	int x,y;
	for(int i =0;i<n -1;i++){
	    cin>>x>>y;
	g.addEdge(x,y);

}

	cout << "Following is a Topological Sort of the given graph \n";
	g.topologicalSort();
    }
	return 0;
}

