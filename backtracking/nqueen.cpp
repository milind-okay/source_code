#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int array[100];
bool place(int k,int i)
{
int j;
for(j=1;j<=k;j++)
{
	if(array[j]==i|| abs(array[j]-i)==abs(k-j))
	return false;
}
return true;
}
void nqueen(int n,int k)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			array[k] = i;


		if(k == n)
		{
		    cout<<"okay\n";
		for(j=1;j<=n;j++)
		cout<<array[j]<<endl;
	}
		else
		nqueen(n,k+1);
	}
	}
}
int main()
{
	int x,i;
	for(i=0;i<100;i++)
	array[i]=0;
	cout<<"enter dimension of matrix";
	cin>>x;
	nqueen(x,1);
	return 0;
}

