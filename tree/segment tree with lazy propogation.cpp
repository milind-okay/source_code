#include<bits/stdc++.h>
using namespace std;
vector <int > mk[400005];
void update(int index,int L,int R,int l,int r)
{
    if(L>R || L>r || R<l )
    {
        return ;
    }
 if(L==l && R==r)
 {
     mk[index][0] += 1;
     mk[index][1] = R - L + 1 - mk[index][1];
     return ;
 }
 int mid = (L + R)>>1;
 int left= index<<1;
 int right = left + 1;

 if(r<=mid)
 {
     update(left,L,mid,l,r);
 }
 else if(l>mid)
 {
     update(right,mid+1,R,l,r);
 }
 else
 {
     update(left,L,mid,l,mid);
     update(right,mid+1,R,mid+1,r);

}
mk[index][1] = mk[left][1] + mk[right][1];
if(mk[index][0]%2 == 1)
{
    mk[index][1]= R - L + 1 - mk[index][1];
}

}
int query(int index,int L,int R,int l,int r,int flip)
{
    if(L>R || L>r || R<l )
    {
        return 0;
    }
    if(L==l && R==r)
    {
        if(flip%2 == 1)
        {
            return (R - L + 1 - mk[index][1] );
        }
        else
        {
            return (mk[index][1]);
        }
    }

    flip+=mk[index][0];
    int mid = (L + R)>>1;
    int left = index<<1;
    int right = left + 1;

    if(r<=mid)
    {
       return query(left,L,mid,l,r,flip);
    }
    else if(l>mid)
    {
        return query(right,mid+1,R,l,r,flip);

    }
    else
    {
        return query(left,L,mid,l,mid,flip) + query(right,mid+1,R,mid+1,r,flip);
    }
}
int main()
{
    int n,q,i,j,x,a,b;
    cin>>n>>q;
    j = n<<2;
    for(i=0;i<=j;i++)
    {
        mk[i].push_back(0);
        mk[i].push_back(0);
    }
    while(q--)
    {
        fflush(stdin);
        scanf("%d%d%d",&x,&a,&b);
        if(x==0)
        {
            update(1,0,n-1,a,b);


        }
        else
        {
           printf("%d\n",query(1,0,n-1,a,b,0));
        }
    }
//    mk.clear();
    return 0;
}
