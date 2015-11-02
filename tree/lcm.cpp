#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long int stree1[40009],stree[10002];

long long int gcd(long long int a,long long int b){
while(b){
    b ^= a ^= b ^= a %= b;
}
return a;
}

long long int lcm(long long int a,long long int b){
return (((a/gcd(a,b))%mod)*b)%mod;
}
long long int builttM(int l,int r,int index){
    if(l>r)
        return 1;
   if(l==r){
    stree1[index] = stree[l];
    return stree[l];
   }
   int mid = (l + r)>>1;
   int left = index<<1;
   int right = left +1;
   stree1[index] = lcm(builttM(l,mid,left) , builttM(mid + 1,r,right));
   return stree1[index];
}
void update_dr(int l,int r,int i,long long int x,int index){
if(i<l || i>r)
    return;
stree1[index] = lcm((stree1[index]/stree[i]),x);
if(l != r){
int mid =(l + r)>>1;
int left = index<<1;
update_dr(mid + 1,r,i,x,left +1);
update_dr(l,mid,i,x,left);
}

}
long long int findLCM(int ss,int se,int L,int R,int index){
    if(ss > R || se < L){
        return 1;
    }
    if(L <= ss && R >= se)
        return stree1[index];

    int mid = (ss + se)>>1;
    int left = index<<1;
    return lcm(findLCM(ss,mid,L,R,left),findLCM(mid + 1,se,L,R,left + 1));

}
int main(){
int n,i,j,q;
cin>>n;
for(int i=1;i<=n;i++){
    scanf("%lld",&stree[i]);
}
//cout<<gcd(3,2);
//cout<<lcm(3,2);
memset(stree1,1,4*n);
builttM(1,n,1);

cin>>q;
//    cout<<stree1[i]<<" ";
while(q--){
    int x,a,b;
    fflush(stdin);
    scanf("%d%d%d",&x,&a,&b);
    if(x==1){
        update_dr(1,n,a,(long long int)b,1);
        stree[a] = b;
    }
    else{
        cout<<findLCM(1,n,a,b,1)%mod<<endl;
    }

}
return 0;
}
