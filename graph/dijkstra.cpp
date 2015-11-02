#include<iostream>
#include<queue>
using namespace std;
class graph{
int V,E,i,j;
vector <pair< int ,int> > *g;
queue <int> qu;
public:
    int *pred;
    graph(int x){
        V = x;
      g = new vector<pair< int, int > >[V];
      pred = new int[V];
    }
    void addEdge(int a,pair<int,int> b);
   void bfs(int s,int dist[]);
};
void graph :: addEdge(int a,pair<int,int> b){
g[a].push_back(b);
}


void graph :: bfs(int s,int dist[]){

for(int i=1;i<=V;i++){

    dist[i] = 9999999;
}


qu.push(s);
pred[s] = -1;

while(!qu.empty()){
        int v = qu.front();

    vector<pair<int,int> > :: iterator it;
    for(it=g[v].begin();it!=g[v].end();++it){
            int q  = dist[v] + g[v].second();
            if(q<dist[*it.first()] ){
                dist[*it.first()] = q;
                qu.push(*it.first());
                pred[*it.first()] = v;

            }
    }
    qu.pop();

}
return;
}


int main(){
    int v,e,i,j,a,b,s,c;
    cin>>v>>e;
    int dist[v+1];
    graph g(v+1);
    pair<int,int> w
    for(i=0;i<e;i++){
            cin>>a>>b>>c;
            w.first(b);
            w.second(c);
        g.addEdge(a,w);
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
