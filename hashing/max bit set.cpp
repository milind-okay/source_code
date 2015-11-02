#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
int main(){
    int t;
    cin>>t;
    while(t--){

  int n,k,m,i,j,x,a,count=0;

        cin>>n>>m>>k;
       int N[n],C[m],mk[m];
        for(i=0;i<n;i++){
            cin>>N[i];
        }
        for(i=0;i<m;i++){
            cin>>C[i];

        }
        for(i=0;i<m;i++){
            cin>>mk[i];

        }
       for(i=0;i<n;i++){
            a=0;
        for(j=0;j<m;j++){
                x = gcd(N[i],C[j]);
        //cout<<N[i]<<" "<<C[j]<< " "<<x<<"\n";
            if(x != 1){
                a += mk[j];
                //C[j] = 0;
            }

        }
         N[i] = a;
       }
       sort(N,N+n);
       i=n-1;
       while(k--){
        count+=N[i];
        i--;
       }
        cout<<count<<endl;
    }
    return 0;
}
