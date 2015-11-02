#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int x = (1<<31);
x|=(x>>1);
x|=(x>>2);
x|=(x>>4);
x|=(x>>8);
x|=(x>>16);
cout<<(x +  1)<<endl;
cout<<(n&(-n))<<endl;
cout<<(n^(n&(-n)));
return 0;
}
