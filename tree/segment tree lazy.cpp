#include<bits/stdc++.h>
#define inf 0x7fffffff
using namespace std;
//** 1 based index
int A[100002];
int stree[500001],lazy[500001];
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
    return p+q;
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
			lazy[(index*2 )+1] += val;
		}

    		return;
	}

	update_tree(index*2, ss, (ss+se)/2, l, r, val);
	update_tree(1 +index*2, 1+(ss+se)/2, se, l, r, val);

	stree[index] = stree[index*2]+ stree[(index*2)+1];
}

int construct_st_util(int A[],int ss,int se,int *stree,int index)
{

        if(ss==se)
    {
        stree[index]=A[ss];
        return A[ss];

    }
    int mid=get_mid(ss,se);
    stree[index] = construct_st_util(A,ss,mid,stree,2*index)+construct_st_util(A,mid+1,se,stree,2*index+1);
    return stree[index];

}
int *construct_st(int A[],int n)
{

int x=construct_st_util(A,1,n,stree,1);

return stree;
}
int main()
{
    int n,i,x,q;
    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    cin>>q;
    int *stree=construct_st(A,n);
    while(q--){
            int type,l,r,x,y;
        cin>>type;
    if(type==1){
        cin>>l>>r;
        cout<<(find_sum(stree,l,r,1,n,1))<<endl;
    }
    else{
        cin>>l>>r>>x;
        y = find_sum(stree,l,r,1,n,1);
        for(i=l;i<=r;i++){
                update_tree(1,i,i,1,n,(A[i]^x) - A[i]);
            A[i] = A[i]^x;

        }

    }
    }

    return 0;
}
