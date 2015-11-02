#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
int info;
struct node *left,*right;

};
typedef struct node *Node;
Node newNode(int data)
{
    Node temp = new node();
    temp->info = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;

}
Node Bst(Node root,int data)
{
    if(root == NULL)
    {
        Node temp = newNode(data);
        root = temp;

    }
    else if(root->info>=data)
    {
       root->left= Bst(root->left,data);
    }
    else
    {
        root->right = Bst(root->right,data);
    }
    return root;
}
//inorder trv :-
//I method :-
void inorder(Node root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->info<<endl;
        inorder(root->right);
    }
}
void printN(Node root){
 if(root->left != NULL)
 {
     printN(root->left);
      cout<<root->info<<"\n";


 }
else cout<<root->info<<"\n";
  if(root->right!=NULL)
        printN(root->right);

}
//preorder :-
//M I:-
void preorder1(Node root)
{
    if(root != NULL)
    {
        cout<<root->info<<endl;
        preorder1(root->left);
        preorder1(root->right);
    }
}
//M II
 void preorder(Node root)
 {
     cout<<root->info<<"\n";
     if (root->left!=NULL)
     {
         preorder(root->left);
     }
     if(root->right !=NULL)
     {
         preorder(root->right);
     }
     return;
 }

 void postOrder(Node root)
 {
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->info<<"\n";
    }
 }
 void _del_Tree(Node root)
 {
     if(root != NULL)
     {
         _del_Tree(root->left);
         _del_Tree(root->right);
         cout<<root->info;
         delete root;

         //root = NULL;
     }
 }
 void del_Tree(Node * root)
 {
     _del_Tree(*root);
     *root = NULL;
 }
 Node findMin(Node root)
 {
     if(root->left!=NULL)
     {
        return findMin(root->left);
     }
     else
     {
         return root;
     }
 }
 Node del(Node root,int data)
 {
     if(root == NULL)
     {
         return root;

     }
     else if(root->info>data)
     {
         root->left = del(root->left,data);
     }
     else if(root->info<data)
     {
         root->right = del(root->right,data);
     }
     else
     {
         if(root->left == NULL)
         {
             Node temp = root->right;
             delete root;
             return temp;

         }
         else if (root->right ==NULL)
         {
             Node temp = root->left;
             delete root;
             return temp;

         }

             Node temp = findMin(root->right);
             root->info = temp->info;
             root->right = del(root->right,temp->info);

    }
     return root;
 }

int hightBtree(Node root){
int r,l;
if(root != NULL)
{

    l = hightBtree(root->left) + 1;
    r = hightBtree(root->right) + 1;
    return max(l,r);
}
else
return 0;
}
int checkBalanc(Node root){
     int r,l;
if(root != NULL)
{

    l = checkBalanc(root->left) - 1;
    r = checkBalanc(root->right) + 1;
    return r + l;
}
else
return 0;
}
int main()
{
    int n;
    cin>>n;
    Node root=NULL,top = NULL;
    int x,i;

    cin>>x;
    root  = newNode(x);

    for(i=1;i<n;i++)
    {
        cin>>x;
        root = Bst(root,x);

    }
    cout<<"inorde:M I \n";
    printN(root);
    cout<<"M II \n";
    inorder(root);
    cout<<"preorder : \n M I\n";
    preorder1(root);
    cout<<"M II \n";
    preorder1(root);
    cout<<"postOrder \n";
    postOrder(root);
    cout<<"enter element to delete: \ n";
    cin>>x;
    del(root,x);
    printN(root);


    cout<<"hight of tree :\n";
    cout<<hightBtree(root);
    cout<<"Is tree blanced ?\n";
    int aa;
    if(( aa = abs(checkBalanc(root)))>1){
        cout<<aa<<"NO\n";
    }
    else
        cout<<aa<<"YES\n";
    cout<<"deleting the tree\n";
    del_Tree(&root);
    inorder(root);
    return 0;
}
