#include<iostream>
#include<queue>
using namespace std;
class graph{
int V,E,i,j;
vector <int> *g;
queue <int> qu;
public:
    int *pred;
    graph(int x){
        V = x;
      g = new vector<int >[V];
      pred = new int[V];
    }
    void addEdge(int a,int b);
   void bfs(int s,int dist[]);
};
void graph :: addEdge(int a,int b){
g[a].push_back(b);
}


void graph :: bfs(int s,int dist[]){
bool visited[V];
for(int i=1;i<=V;i++){
    visited[i] = false;
    dist[i] = 0;
}
visited[s]  = true;

qu.push(s);
pred[s] = -1;

while(!qu.empty()){
        int v = qu.front();

    vector<int> :: iterator it;
    for(it=g[v].begin();it!=g[v].end();++it){
            if(visited[*it] == false ){
                dist[*it] = dist[v] + 1;
                qu.push(*it);
                pred[*it] = v;
                visited[*it] = true;
            }
    }
    qu.pop();

}
return;
}


int main(){
    int v,e,i,j,a,b,s;
    cin>>v>>e;
    int dist[v+1];
    graph g(v+1);
    for(i=0;i<e;i++){
            cin>>a>>b;
        g.addEdge(a,b);
    }
    cout<<"Enter source vertex\n";
    cin>>s;
   g.bfs(s,dist);

   for(i=1;i<=v;i++)
    cout<<dist[i]<<" ";
cout<<endl<<"enter end vertex\n";

 cin>>v;
   while(1)
        {
            if(v==-1)
            {
                break;
            }
            else if(v==s)
            {
                cout<<v;
                break;
            }
            else
            {
                cout<<v<<" ";
                v=g.pred[v];
            }
        }cout<<endl;
return 0;
}
