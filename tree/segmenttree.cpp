#include <bits/stdc++.h>
#define mod 1000000007
int st[40004],stree[10002];
 int gcd( int a, int b){
while(b){
    b ^= a ^= b ^= a %= b;
}
return a;
}

int lcm(int a,int b){
return (((a/gcd(a,b))%mod)*b)%mod;
}
int getMid(int s, int e) {  return s + (e -s)/2;  }

int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{

    if (qs <= ss && qe >= se)
        return st[index];


    if (se < qs || ss > qe)
        return 1;


    int mid = getMid(ss, se);
    return lcm(getSumUtil(st, ss, mid, qs, qe, 2*index+1)%mod ,
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2)%mod)%mod;
}

void updateValueUtil(int *st, int ss, int se, int i, int x, int index)
{
    if (i < ss || i > se)

    st[index] = lcm((st[index]/stree[i])%mod,x)%mod;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, x, 2*index + 1);
        updateValueUtil(st, mid+1, se, i,x, 2*index + 2);
    }
}

void updateValue(int arr[], int *st, int n, int i, int x)
{
    if (i < 0 || i > n-1)
    {

        return;
    }
    updateValueUtil(st, 0, n-1, i, x, 0);
}


int getSum(int *st, int n, int qs, int qe)
{

    if (qs < 0 || qe > n-1 || qs > qe)
    {

        return 1;
    }

    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int construct(int arr[], int ss, int se, int *st, int si)
{

    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    int mid = getMid(ss, se);
    st[si] =  lcm(construct(arr, ss, mid, st, si*2+1)%mod ,
              construct(arr, mid+1, se, st, si*2+2)%mod)%mod;
    return st[si];
}

int main(){

int n,i,j,q;
scanf("%d",&n);
fflush(stdin);
for(int i=0;i<n;i++){
    scanf("%d",&stree[i]);
}
//cout<<gcd(3,2);
//cout<<lcm(3,2);
memset(st,1,4*n);
construct(stree,0,n-1,st,0);
fflush(stdin);
scanf("%d",&q);
/*for(int i=0;i<4*n;i++){
    printf("%d  ",st[i]);
}*/

//    cout<<stree1[i]<<" ";
while(q--){
    int x,a,b;
    fflush(stdin);
    scanf("%d%d%d",&x,&a,&b);
    if(x==1){
        updateValue(stree,st,n,a,b);
        stree[a-1]  = b;
    }
    else{
        printf("%d\n",getSum(st,n,a,b));
    }

}
return 0;
}



