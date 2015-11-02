#include<bits/stdc++.h>
using namespace std;
//** 1 based index
int get_mid(int ss,int se)
{
    return (ss+se)/2;
}
int find_sum(int *stree ,int L,int R,int ss,int se,int index)
{
    if(ss==L && se==R)
        return stree[index];
    if(ss>=R || se<=L)
        return 0;
    int mid =get_mid(ss,se);
    return find_sum(stree,L,R,ss,mid,2*index)+find_sum(stree,L,R,mid+1,se,2*index+1);
}
int construct_st_util(int A[],int ss,int se,int *stree,int index)
{

        if(ss==se)
    {
        stree[index]=A[ss];
        return A[ss];

    }
    int mid=get_mid(ss,se);
    stree[index]=construct_st_util(A,ss,mid,stree,2*index)+construct_st_util(A,mid+1,se,stree,2*index+1);
    return stree[index];

}
int *construct_st(int A[],int n)
{
    int x=(int )(ceil(log2(n)));
    int max_size=2*(int)pow(2,x)-1;
    int *stree=new int[max_size+16];
    x=construct_st_util(A,1,n,stree,1);

return stree;
}
int main()
{
    int n,i,x;
    cin>>n;
    int A[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    int *stree=construct_st(A,n);
    for(i=1;i<2*n;i++)
        cout<<stree[i]<<endl;
   cout<<(x=find_sum(stree,2,4,1,n,1));
    return 0;
}
