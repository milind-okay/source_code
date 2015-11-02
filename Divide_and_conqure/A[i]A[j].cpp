#include<bits/stdc++.h>
using namespace std;
void mer(int arr[],int l,int r,int *count){
if(l == r)
    return;
int mid = (l + r)>>1;
mer(arr,l,mid,count);
mer(arr,mid + 1,r,count);
int temp[100];
int i = l,k = 0,j = mid + 1;
while(1){
        if(arr[i]<=arr[j] && i<=mid){
        temp[k++] = arr[i++];
        }else if(j<=r){
            temp[k++] = arr[j++];
            *count+=(mid - i + 1);
            cout<<"->"<<*count;
        }else
        break;


}
while(i <= mid){
    temp[k++] = arr[i++];
}
while(j <= r){
    temp[k++] = arr[j++];
}
for(i=0,j = l;i<k;i++,j++){
    arr[j] = temp[i];
}
}
int main(){
    int n,count = 0;
    cin>>n;
    int mk[n];
    for(int i=0;i<n;i++){
       cin>>mk[i];
    }
    mer(mk,0,n-1,&count);
    for(int i=0;i<n;i++){
      cout<<mk[i]<<" ";
    }
    cout<<endl<<count;
return 0;
}
