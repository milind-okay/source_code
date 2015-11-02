#include<bits/stdc++.h>
using namespace std;
struct node{
int info;
node *left =NULL,*right=NULL;

};
typedef struct node *Node;
Node newnode(int data){
    Node temp = new node;
    temp->info = data;
    temp->left = temp->right = NULL;
    return temp;
}
vector<Node> createBST(int l,int r){
    vector<Node> mk;
if(l>r){
    mk.push_back(NULL);
    return mk;
}
for(int i=l;i<=r;i++){
    vector<Node> leftstree = createBST(l,i - 1);
    vector<Node> rightstree = createBST(i + 1,r);


    for(int k=0;k<leftstree.size();k++){
            Node left = leftstree[k];
        for(int j=0;j<rightstree.size();j++){
            Node right = rightstree[j];
            Node temp = newnode(k);
            temp->left = left;
            temp->right = right;
            mk.push_back(temp);
        }
    }
}
    return mk;
}
void postorder(Node temp){
if(temp != NULL){
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->info<<" ";
}
}
int main(){
    int n,i;
    cin>>n;

   vector<Node> root = createBST(1,n);
for(int i=0;i<root.size();i++)
postorder(root[i]);
return 0;
}
