#include<iostream>
using namespace std;
int power(int x,unsigned int n)
{
    int i=1,m[n+1];
    m[0]=1;
    m[1]=x;
    if(n==1)
        return m[1];
        else
   while(2*i<n)
   {
    m[2*i]= m[i]*m[i];
    i=i*2;
   }
   if(n!=i)
   {
       return power(x,n-i)*m[i];
   }
   else
    return m[i];
}
int main()
{
    int x;
    unsigned int n;
    cin>>x>>n;
    cout<<power(x,n);
    return 0;
}
