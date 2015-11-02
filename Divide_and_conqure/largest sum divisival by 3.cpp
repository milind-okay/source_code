#include<bits/stdc++.h>
using namespace std;
long int squ[100001][2],point[100001][2];
int main(){
   long int n,m,i,j,l,sum=0,count=0;
   cin>>n>>m>>l;
   for(i=0;i<n;i++){
    scanf("%d%d",&squ[i][0],&squ[i][1]);
   }

   for(i=0;i<m;i++){
    scanf("%d%d",&point[i][0],&point[i][1]);
   }
   for(i=0;i<m;i++){
        count=0;
    for(j=0;j<n;j++){
        if(squ[j][0]<= point[i][0] && squ[j][1]<=point[i][1] && squ[j][0] + l>=point[i][0] && squ[j][1]+l>=point[i][1])
            count++;
    }
    if(sum<count)
        sum=count;
   }
   cout<<sum<<endl;
return 0;
}
