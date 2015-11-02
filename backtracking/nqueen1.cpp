#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int array[100];
int board[100][100];
bool place(int k,int i)
{
int j;
for(j=1;j<k;j++)
{
	if(array[j]==i|| abs(array[j]-i)==abs(k-j))
	return false;
}
return true;
}
void nqueen(int n,int k,int *count)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			array[k] = i;


		if(k == n)
		{
		    *count+=1;
		   /* cout<<"okay\n";
		    for(int z=1;z<=n;z++)
		for(j=1;j<=n;j++)
            board[z][j]=0;
        for(j=1;j<=n;j++)
		board[j][array[j]]=1;
		    for(int z=1;z<=n;z++){

		for(j=1;j<=n;j++)
            cout<<board[z][j]<<" ";
            cout<<endl;
		    }*/

	}
		else
		nqueen(n,k+1,count);
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
	int count=0;
	nqueen(x,1,&count);
	 cout<<count<<endl;
	return 0;
}

