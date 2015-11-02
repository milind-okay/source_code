#include<iostream>
using namespace std;
int power(int x,unsigned int n)
{
    int y;
    if(n==0)
        return 1;
        y=power(x,n/2);
    if(n%2==0)
        return y*y;
    else
        return y*y*x;
}
int main()
{
    int x;
    unsigned int n;
    cin>>x>>n;
    cout<<power(x,n);
    return 0;
}
