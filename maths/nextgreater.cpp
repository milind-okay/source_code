#include<bits/stdc++.h>
using namespace std;
int arr[100001],nexts[100001],nextg[100001],mk[100001],cur;
long long sum[100001];
pair<int,int> pin[100001];
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

    arr[0] = INT_MAX;
	arr[n + 1] = INT_MAX;
	stack < int > s;
	s.push(0);
	for(int i = 1 ; i <= n ; ++i){
		while(arr[s.top()] < arr[i]){
			s.pop();
		}
		nexts[i] = s.top() + 1;
		s.push(i);
	}
	while(!s.empty()){
		s.pop();
	}
	s.push(n + 1);
	for(int i = n ; i >= 1 ; --i){
		while(arr[s.top()] <= arr[i]){
			s.pop();
		}
		nextg[i] = s.top() - 1;
		s.push(i);
	}
	for(int i = 1 ; i <= n ; ++i){
		pin[i].first = arr[i];
		pin[i].second = 1LL * (i - nexts[i] + 1) * (nextg[i] - i + 1);
	}
	sort(pin+1 , pin+1+n);
	sum[0] = 0;
	mk[0] = 0;
	pin[0].first = -1;
	for(int i = 1 ; i <= n ; ++i){
		if(pin[i].first == pin[i - 1].first){
			sum[cur] += pin[i].second;
		}
		else{
			mk[++cur] = pin[i].first;
			sum[cur] = sum[cur - 1] + pin[i].second;
		}
	}
	sum[cur + 1] = sum[cur];
	mk[cur + 1] = INT_MAX;
	for(i=0;i<n;i++){
        cout<<"sum: "<<sum[i]<<"l :"<<nexts[i]<<" r: "<<nextg[i]<<"mk "<<mk[i]<<endl;
	}
return 0;
}
