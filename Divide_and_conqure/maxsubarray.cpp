#include<iostream>
using namespace std;
int maxcrosssum(int array[],int l,int m,int h);
int maxsubarray(int array[],int l,int h);
int max(int a,int b,int c)
{
	if(a>=b&&a>=c)
	return a;
	else if(b>=a&&b>=c)
	return b;
	else
	 return c;
	
}
int main()
{
	cout<<"enter no of elements";
	int n,i;
	cin>>n;
	int array[n];
	for(i=0;i<n;i++)
	cin>>array[i];
	cout<<maxsubarray(array,0,n-1);
	return 0;
	
}
int maxcrosssum(int array[],int l,int m,int h)
{
	int i,j,leftsum=-99999,rightsum=-99999;
	int sum=0;
	for(i=m;i>=l;i--)
	{
		sum=sum+array[i];
		if(sum>=leftsum)
		leftsum=sum;
	}
	sum=0;
		for(i=m+1;i<=h;i++)
	{
		sum=sum+array[i];
		if(sum>=rightsum)
		rightsum=sum;
	}
	return leftsum+rightsum;
}
int maxsubarray(int array[],int l,int h)
{
	int x,y,z,mid;
	if(l==h)
	return array[l];
	else
	{
		mid=(h+l)/2;
		x=maxsubarray(array,l,mid);
		y=maxsubarray(array,mid+1,h);
		z=maxcrosssum(array,l,mid,h);
		return (max(x,y,z));
	}
}
