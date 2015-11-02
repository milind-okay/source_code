#include<iostream>
using namespace std;
struct btree
{
    int info,leftL=0,rightL=0;
    struct btree *left,*right;
};
typedef struct btree *node;
node newnode(int data)
{
   node temp = new btree();
    temp->info =  data;
    temp->left = temp->right = NULL;
    return temp;
}
node builtTree(node root,int data)
{
    if(root == NULL)
    {
        root = newnode(data);
        return root;
    }
    if(root->leftL <= root->rightL)
    {
        ++root->leftL;
        root->left = builtTree(root->left,data);
    }
    else
    {
        ++root->rightL;
        root->right = builtTree(root->right,data);
    }
    return root;
}
int numberOfleaf(node root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {

        return numberOfleaf(root->left) + numberOfleaf(root->right);
    }
}
int main()
{
    int n,i,j;
    cin>>n;
    node head= NULL;

    for(i=0;i<n;i++)
    {
        cin>>j;
        head = builtTree(head,j);

    }
    //cout<<"okay";
    cout<<numberOfleaf(head);
    //cout<<"okay1";
    return 0;
}
