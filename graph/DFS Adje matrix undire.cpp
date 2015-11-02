#include<iostream>
using namespace std;
int m[100][100],v1[100];
int Dfs(int x,int y,int n)
{
    int i,v;
    if(x==y)
        return 1;
        v1[x]=1;
        for(i=0;i<n;i++)
        {
            if(m[x][i]==1 && v1[i]==0)
            {
                v=Dfs(i,y,n);
                if(v==1)
                    return 1;
            }
        }
        return 0;
}
int main()
{
    int n,i,j,x,y;
    cin>>n;

    for(i=0;i<n;i++)
    {
        v1[i]=0;
    }
        m[0][1]=1;
        m[1][2]=1;
        m[2][3]=1;
        m[1][3]=1;
        m[0][2]=1;
        m[4][4]=1;
    cout<<"enter to find path from x ,y";
    cin>>x>>y;
    if(Dfs(x,y,n)==1)
    cout<<"path available";
    else
        cout<<"path not available";
    return 0;
}
