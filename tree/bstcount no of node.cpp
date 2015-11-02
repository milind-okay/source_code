#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long int mk[10];
struct node{
int info;
long int self,nonode=0;
struct node *left,*right;

};
typedef struct node *Node;
Node newNode(int data,int i)
{
    Node temp = new node();
    temp->info = data;
    temp->self=mk[i];
    temp->left = NULL;
    temp->right = NULL;
    return temp;

}
Node Bst(Node root,int data,int i)
{
    if(root == NULL)
    {
        Node temp = newNode(data,i);
        root = temp;

    }
    else if(root->info==data){
        root->self+=mk[i];

    }
    else if(root->info>=data)
    {
        root->nonode+=mk[i];
       root->left= Bst(root->left,data,i);
    }
    else
    {
        root->nonode+=mk[i];
        root->right = Bst(root->right,data,i);
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
        cout<<root->info<<" "<<root->nonode<<endl;
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
long int searchnode(Node root,int data){
if(root==NULL)
    return 0;

else if(root->info<data){
        int l=0;
        if(root->right!=NULL)
         if(root->right->info<data){
            l = searchnode(root->right,data);
         }
        if(root->left!=NULL)
    return root->self + root->left->nonode + root->left->self +l;
else
    return root->self + l;

}
else{
    return searchnode(root->left,data);
}

}
long int searchnodeequal(Node root,int data){
if(root==NULL)
    return 0;

else if(root->info==data){
return root->self;

}
else if(root->info>data){
    return searchnodeequal(root->left,data);
}
else{
    return searchnodeequal(root->right,data);
}
}
int main()
{
    int n;
    cin>>n;
    Node root=NULL,top = NULL;
    int x,i;

    for(i=0;i<n;i++)
    {
        cin>>mk[i];


    }
    cin>>x;
    root  = newNode(x,0);

    for(i=1;i<n;i++)
    {
        cin>>x;
        root = Bst(root,x,i);

    }

cout<<searchnode(root,2)<<"   "<<searchnode(root,4);

cout<<endl<<searchnodeequal(root,2)<<"   "<<searchnodeequal(root,4);
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
