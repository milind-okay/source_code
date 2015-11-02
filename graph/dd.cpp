#include<bits/stdc++.h>
#define N 2002
using namespace std;
int dp[N][N], nxt[N], a[N], b[N],ans[N];;
bool vis[N];
inline void pre(){
    for(int x = 3; x < N; x++){
        dp[x][x] = x - 1;
        dp[x][x - 1] = x - 2;
        for(int i = x + 1; i < N; ++i){
            dp[x][i] = max(dp[x][i - x] + x - 1, dp[x][i - x + 1] + x - 2);
        }
    }
}
int main(){
int t;
pre();
cin>>t;
while(t--){
    int n,i,j,len =0,mk[2002],a,b,m_len=0,x;
    cin>>n;
        int ss[n+1],sd[n+1];
    for(i=0;i<2001;i++)
        mk[i]= 0;
    for(i=0;i<n;i++){
        cin>>ss[i];
    }
         for(i=0;i<n;i++){
        cin>>sd[i];
         }
        for(i=0;i<n;i++)
        mk[ss[i]] = sd[i];

    for(i=1;i<2001;i++){
        if(mk[i]!=0){
            a = mk[i];
            len=0;
            while(i!=a){
                len++;
                a = mk[a];
            }
        }
        if(m_len<len)
            m_len =len;
    }
int    cnt =m_len;
    if(cnt == 1){
                    ans[1]++;
                }
                else{
                    for(x = 3; x <= cnt + 1; x++){
                        ans[x] += dp[x][cnt];
                    }
                }


int fans = 0;
        for(x = 1; x <= n + 1; x++){
            fans = max(fans, ans[x]);
        }
        cout<<fans<<'\n';


}
return 0;
}
