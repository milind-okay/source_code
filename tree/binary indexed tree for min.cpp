#include<iostream>
using namespace std;
int sum(int arr[],int i)
{
    i=i+1;
    int sum=999999999;
    while(i>0)
    {
        if(sum>arr[i])
        sum=arr[i];

        i-=i&(-i);
    }
    return sum;
}
void update(int *arr,int n,int i,int val)
{
    i=i+1;

    while(i<=n)
    {
        if(arr[i]>val)
        arr[i]=val;

        i+=i&(-i);
    }
}
int *constBIT(int mk[],int n)
{
    int *BITree=new int[n+1];

    for(int i=0;i<=n;i++)
        BITree[i]=99999999;

    for(int i=0;i<n;i++)
    {

        update(BITree,n,i,mk[i]);
    }
    return BITree;
}
int main()
{
    int n,i;
    cin>>n;
    int mk[n+1];
    for(i=0;i<n;i++)
    {
        cin>>mk[i];
    }
    int *BITree=constBIT(mk,n);
   // for(i=0;i<=n;i++)
    //cout<<BITree[i]<<endl;
    cout<<sum(BITree,2);
    return 0;
}
