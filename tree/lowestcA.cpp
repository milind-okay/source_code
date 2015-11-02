#include<iostream>
using namespace std;
class node{
public:
//protected:
    int val;
    node *left,*right;
public:
    node(int data){
    this->val = data;
    left = NULL;
    right = NULL;
    }
};
class tree {
    public:
    node* createbst(node* ,int );
};
node* newnode(int data){
    node *temp = new node();
    temp->val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node* createbst(node* root,int data){
    if(root == NULL){
        return newnode(data);
    }
    if(data > root->val){
        root->left = createbst(root->left,data);
    }
    else{
        root->right = createbst(root->right,data);
    }
    return root;
}
void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}
int main(){
    int n,i,j;
    cin>>n;
    node *root = NULL;
    tree o;
    for(i = 0;i<n;i++){
        cin>>j;
        root = createbst(root,j);
    }
    cout<<"okay";
    inorder(root);
return 0;
}
