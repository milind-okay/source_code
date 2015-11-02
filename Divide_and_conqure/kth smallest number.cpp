#include<bits/stdc++.h>
#include<climits>
using namespace std;
int partition(int mk[],int l,int r){
int x = mk[r],j=l;
for(int i =l;i<r;i++){
    if(mk[i]<x){
            swap(mk[i],mk[j]);
        j++;

    }
}
swap(mk[j],mk[r]);
return j;
}
int randpartition(int mk[],int l,int r){
    int n;
    n = r-l+1;
int pos = rand()%n;
swap(mk[pos + l],mk[r]);
return partition(mk,l,r);
}
int kthsmallest(int mk[] ,int l,int r,int k){
if(k>0 && k<r-l+1){
int pos = randpartition(mk,l,r);

if(pos - l == k - 1){
    return pos;
}
if(pos - l > k-1){
    return kthsmallest(mk,l,pos - 1,k);
}

    return kthsmallest(mk,pos + 1,r,k-pos+l-1);
}
    return INT_MAX;
}



int main(){
int n,i,j;
cin>>n;
int mk[n];
for(i=0;i<n;i++){
    cin>>mk[i];
}
cout<<mk[kthsmallest(mk,0,n-1,3)];
return 0;
}
