#include<bits/stdc++.h>
using namespace std;
char arr[100001];
int sum[100001][26];
void update(int ind,char ch,int n){
    while(ind<=n){
        sum[ind][ch - 'a']++;
        ind+=ind&(-ind);
    }
}
void update1(int ind,char ch,char c,int n){
    while(ind<=n){
            sum[ind][c - 'a']--;
        sum[ind][ch - 'a']++;
        ind+=ind&(-ind);
    }
}
void query(int ind,int *a){

while(ind>0){
    for(int i=0;i<26;i++){
        a[i] += sum[ind][i];
    }
    ind-=ind&(-ind);
}

}
void query1(int ind,int *a){

while(ind>0){
    for(int i=0;i<26;i++){
        a[i] -= sum[ind][i];
    }
    ind-=ind&(-ind);
}

}
bool queryQ(int l,int r){
int a[26],flag = 0;
for(int i =0;i<26;i++){
    a[i] = 0;
}
query(r,a);
query1(l - 1,a);
for(int i =0;i<26;i++){
        if(a[i]&1){
            if(flag == 1)
                return false;
            else
                flag = 1;
        }

}
return true;
}
int main(){
int n,i,q;

cin>>n>>q;
//fflush(stdin);
//scanf("%s",arr);
cin>>arr;
for(i=1;i<=n;i++){
    for(int j = 0;j<26;j++){
        sum[i][j] = 0;
    }
}
for(i=0;i<n;i++){
update(i + 1,arr[i],n);
}

while(q--){
    int type,l,r;
    char ch;
    cin>>type;

    if(type == 1){
            cin>>l>>ch;
            update1(l,ch,arr[l - 1],n);
            arr[l - 1]= ch;
    }else{
        cin>>l>>r;
        if(queryQ(l,r))
            printf("yes\n");
        else
            printf("no\n");
    }
}
return 0;
}
