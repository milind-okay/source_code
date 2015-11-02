#include<bits/stdc++.h>
using namespace std;

 struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };

RandomListNode* copyRandomList(RandomListNode* A) {
    RandomListNode *head = NULL,*temp =NULL;
    temp = A;
    int num=0,i,j,m;
    vector <RandomListNode * >mk;
    while(temp!=NULL){
        mk.push_back(temp);
        num++;
        temp = temp->next;
    }
    m = num+1;
   // cout<<m<<" ";
    temp = A;
    RandomListNode *temp3 = new RandomListNode(temp->label);
    head = temp3;
    j = (temp->random->label);
    if(j == num || (j%m) == num){
        i =0;
    }
    else if(j > num){
        i = j%m;
    }
    else{
        i = j;
    }

    RandomListNode *temp1 = new RandomListNode(mk[i]->label);

    head->next = temp1;
    temp = temp->next;
    //cout<<temp->random->label;
    while(temp!=NULL){
        RandomListNode *temp2 = new RandomListNode(temp->label);
        temp1->next = temp2;
        temp1 = temp2;
        j = (temp->random->label);
        if(j == num || (j%m) == num){
        i =0;
    }
    else if(j > num){
        i = j%m;
    }
    else{
        i = j;
    }

    temp2 = new RandomListNode(mk[i]->label);


         temp1->next = temp2;
        temp1 = temp2;
        temp = temp->next;
    }
    return head;
}
int main(){
    RandomListNode *head,*temp,*temp1,*head1;
    head  = new RandomListNode(1);
    temp =  new RandomListNode(2);
    head->next = temp;
    temp1 =  new RandomListNode(3);
    temp->next = temp1;
    head1 = copyRandomList(head);
    while(head1!=NULL){
        cout<<(head1->label)<<" ";
        head1 = head1->next;
    }
return 0;
}
