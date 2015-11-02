#include<bits/stdc++.h>
using namespace std;
int arr[100001],nexts[100001],nextg[100001],mk[100001],cur;
long long sum[100001];
stack<int> st1;
void cal(int n){
    //cout<<" calI ";
st1.push(0);
int i=1,index,L;
while(i<=n){
        if(arr[i]>=arr[st1.top()]){
            index = st1.top();
            nextg[index] = arr[i];
            st1.pop();

            if(!st1.empty())
            while(!st1.empty() && arr[st1.top()]<arr[i]){

              index = st1.top();
            nextg[index] = arr[i];
            st1.pop();

            }

        }
        nexts[st1.top()] = i;
        st1.push(i);

    i++;
}
index = st1.top();
st1.pop();
while(!st1.empty()){


    index = st1.top();
    nextg[index] = n;

    st1.pop();
    if(!st1.empty())
    nexts[index] = st1.top();
}
nexts[index] = n;
//cout<<" calO ";
return;
}


int inline scan() {
    int N = 0;
    char C;
    C = getchar();
    while (C < '0' || C > '9') C = getchar();
    while (C >= '0' && C <= '9') {
        N = (N<<3) + (N<<1) + C - '0';
        C = getchar();
    }
    return N;
}
int main(){
    int n,q,i;
    n = scan();
    q = scan();
    for(i=0;i<n;i++){
        arr[i] = scan();
    }
    cal(n);
	for(i=0;i<n;i++){
        cout<<"l :"<<nexts[i]<<" r: "<<nextg[i]<<endl;
	}
	while(q--){
        int l,k;
        l = scan(),k = scan();


	}
return 0;
}
