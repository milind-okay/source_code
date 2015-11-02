#include<iostream>
using namespace std;
void maxmin(int arr[],int l,int h,int* max,int* min)
{
    int mid;
    if(l==h)
    {
         *max=*min=arr[l];
    }
    else if(l=h-1)
    {
        if(arr[l]>=arr[h])
        {
            *max=arr[l];
            *min=arr[h];
        }
        else
        {
            *max=arr[h];
            *min=arr[l];
        }
    }
    else
    {
        mid=(l+h)/2;
        int *max1,*max2,*min1,*min2;
        maxmin(arr,l,mid,max1,min1);
        maxmin(arr,mid+1,h,max2,min2);
        if(*max1>*max2)
        {
            *max=*max1;

        }
        else
        {
            *max=*max2;

        }
        if(*min1<*min2)
        {
            *min=*min1;
        }
        else
        {
            *min=*min2;
        }
    }
}
int main()
{
    int n,i,*min,*max;
    cin>>n;
    int m[n];
    for(i=0;i<n;i++)
    {
        cin>>m[i];
    }
    maxmin(m,0,n-1,max,min);
    cout<<"max= "<<*max<<"   min = "<<*min;

    return 0;
}
