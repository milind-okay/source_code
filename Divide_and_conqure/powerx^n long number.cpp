#include<iostream>
using namespace std;
 long long int y;
long long int power(long long int x,long long int n)
{

    if(n==0)
        return 1;
        y=power(x,n>>1);
    if(n%2==0)
        return y*y;
    else
        return y*y*x;
}
int main()
{
   long long int x;
    long long int n;
    cin>>x>>n;
    cout<<power(x,n);
    return 0;
}
