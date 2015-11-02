#include<iostream>
using namespace std;
struct bbst
{
    int info;
    struct bbst *left,*right;
};
typedef struct bbst *node;
node newnode(int data)
{
    node temp = new bbst();
    temp->info = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node createbbst(int arr[],int l,int r)
{
    if(l>r)
    return NULL;
        int mid = (l+r)>>1;
    node root = newnode(arr[mid]);

    root->left = createbbst(arr,l,mid-1);

    root->right = createbbst(arr,mid+1,r);
    return root;

}
void inorder(node root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->info<<"\n";
        inorder(root->right);
    }
}
int main()
{
    int n,i,j;
    cin>>n;
    int mk[n];
    for (i=0;i<n;i++)
    {
        cin>>mk[i];
    }
node root = createbbst(mk,0,n);

 inorder(root);

    return 0;
}
