#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp = *a;
    *a= *b;
    *b = temp;
    return;
}
void addminheap(int *mk,int x,int pos)
{
    mk[pos] = x;
    int k = pos>>1;
    while(k != 0 && mk[k]>mk[pos])
    {
        swap(&mk[k],&mk[pos]);
        pos=k;
        k>>=1;

    }
    return ;

}
void creatminHeap(int *arr,int *mk,int n)
{
    for(int i =1;i<=n;i++)
    {
        addminheap(mk,arr[i],i);
    }
    return ;
}
void heapify(int i,int size,int *mk)
{
    int  smallest = i;
        if((i<<1)<size && mk[i] > mk[i<<1])
        {
            smallest = i<<1;

        }
        if((i<<1)+1 <size && mk[smallest]> mk[(i<<1) + 1])
        {
            smallest = (i<<1) + 1;

        }
        if(smallest != i)
        {
            swap(&mk[i],&mk[smallest]);
            heapify(smallest,size,mk);
        }
}
int getEle(int *mk,int *p)
{
    //cout<<"oo"<<*p;
    int temp = mk[1],smallest;
    mk[1] = mk[*p];

    int i=1;

    //cout<<"o1"<<p;
    heapify(1,*p,mk);
      //cout<<"o1"<<p;
      *p -= 1;
    return temp;
}

void pp(int *mk,int *p)
{
    for(int i=1;i<= *p;i++)
    {
        cout<<mk[i];
    }
}
int main()
{
    int n,i,*mk,*arr,p;
    cin>>n;
    arr  = new int[n+1];
    mk = new int [n+1];
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    creatminHeap(arr,mk,n);
    p = n;
    //cout<<"1o"<<*p;

    int z = getEle(mk,&p);

    cout<<z<<endl;
    pp(mk,&p);

    return 0;
}
