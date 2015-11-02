#include<iostream>
using namespace std;
void maxmin(int arr[],int l,int h,int& max,int& m)
{
    int mid;
    if(l==h)
    {
         max=arr[l];
         m= l;
    }
    else if(l=h-1)
    {
        if(arr[l]>=arr[h])
        {
            max=arr[l];
            m=l;
        }
        else
        {
            max=arr[h];
            m=h;
        }
    }
    else
    {
        mid=(l+h)/2;
        int max1,max2,m1,m2;
        maxmin(arr,l,mid,max1,m1);
        maxmin(arr,mid+1,h,max2,m2);
        if(max1>max2)
        {
            max=max1;
            m=m1;

        }
        else
        {
            max=max2;
            m=m2;

        }

    }
}
int main()
{
    int n,i,m,max;
    cin>>n;
    int mk[n];
    for(i=0;i<n;i++)
    {
        cin>>mk[i];
    }
    maxmin(mk,0,n-1,max,m);
    cout<<"max= "<<max<<"   min = "<<m;

    return 0;
}
