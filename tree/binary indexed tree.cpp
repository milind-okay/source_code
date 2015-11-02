#include<bits/stdc++.h>
using namespace std;
int sum[100],arr[100];
void update(int ind,int val,int n){
    while(ind<=n){
        sum[ind]+=val;
        ind+=ind&(-ind);
    }
}
int query(int ind){
    int ans = 0;
while(ind>0){
    ans+=sum[ind];
    ind-=ind&(-ind);
}
return ans;
}
int main(){
int n,i;
cin>>n;
for(i=1;i<=n;i++){
   cin>>arr[i];
    update(i,arr[i],n);
}
cout<<query(4)-query(2)<<endl;
cout<<query(3)-query(0);

return 0;
}
