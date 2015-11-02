#include<bits/stdc++.h>
#define inf 0x7fffffff
using namespace std;

int stree[500001],lazy[500001];
int gcd(int a,int b){
while(b){
    b ^= a ^= b ^= a %= b;
}
return b;
}

int lcm(int a,int b){
return (a/gcd(a,b))*b;
}
int get_mid(int ss,int se)
{
    return (ss+se)/2;
}
int find_sum(int *stree ,int L,int R,int ss,int se,int index)
{
    if(ss > se || ss > R || se < L) return inf;

	if(lazy[index] != 0) {
		stree[index] += lazy[index];

		if(ss != se) {
			lazy[index*2] += lazy[index];
			lazy[index*2+1] += lazy[index];
		}

		lazy[index] = 0;
	}
    if(ss>=L && se<=R)
        return stree[index];

    int mid =get_mid(ss,se);
    int q = find_sum(stree,L,R,ss,mid,2*index);
    int p = find_sum(stree,L,R,mid+1,se,2*index+1);
    return lcm(q,p);
}

void update_tree(int index, int ss, int se, int l, int r, int val) {

  	if(lazy[index] != 0) {
   		stree[index] += lazy[index];
   		if(ss != se) {
			lazy[index*2] += lazy[index];
    			lazy[index*2+1] += lazy[index];
		}

   		lazy[index] = 0;
  	}

	if(ss >se || ss > r || se < l)
		return;

  	if(ss >= l && se <= r) {
    		stree[index] += val;

		if(ss != se) {
			lazy[index*2] += val;
			lazy[index*2+1] += val;
		}

    		return;
	}

	update_tree(index*2, ss, (ss+se)/2, l, r, val);
	update_tree(1+index*2, 1+(ss+se)/2, se, l, r, val);

	stree[index] = min(stree[index*2], stree[index*2+1]);
}

void updatedr(int arr[],int i,int n,int val){
int a = val - arr[i];
update_tree(1,i,i,1,n,a);
}
int construct_st_util(int A[],int ss,int se,int *stree,int index)
{

        if(ss==se)
    {
        stree[index]=A[ss];
        return A[ss];

    }
    int mid=get_mid(ss,se);
    stree[index] = lcm(construct_st_util(A,ss,mid,stree,2*index) ,construct_st_util(A,mid+1,se,stree,2*index+1));
    return stree[index];

}
int *construct_st(int A[],int n)
{

int x=construct_st_util(A,1,n,stree,1);

return stree;
}
int main()
{
    int n,i,x;
    cin>>n;
    int A[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    int *stree=construct_st(A,n);
    for(i=1;i<2*n;i++)
        cout<<stree[i]<<endl;
   cout<<(x=find_sum(stree,2,4,1,n,1));
   cin>>x;
   updatedr(A,2,n,x);
   cin>>x;
      updatedr(A,4,n,x);
      cout<<(x=find_sum(stree,1,n,1,n,1));

    return 0;
}
