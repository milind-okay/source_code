#include<bits/stdc++.h>
#define MAX_CHAR 26
using namespace std;
class trie{


public:
	int count;
    int prifix;
	trie *mk[MAX_CHAR];
    trie(){
        count = 0;
        prifix = 0;

        for(int i=0;i<MAX_CHAR;i++){
           mk[i] = NULL;
        }

    }
};
class trie_root{
public:
    trie *root = NULL;
    trie *create_node();
    trie_root(){
    root = new trie;

    }
    void push_word(string str);
    string autoC(string ss);
    bool searchWord(string ss);
};
void trie_root :: push_word(string str){
    trie *temp = root;
    for(int i=0;i < str.length();i++){
        if(temp->mk[str[i] - 'a']){
            temp->mk[str[i] - 'a']->count++;
            temp = temp->mk[str[i] - 'a'];
        }
        else{
           temp->mk[str[i] - 'a'] = new trie;
            temp->mk[str[i] - 'a']->count++;
            temp = temp->mk[str[i] - 'a'];
        }

    }
    temp->prifix =1;
}
bool trie_root :: searchWord(string str){
    trie *temp = root;
    for(int i=0;i< str.length();i++){
        if(temp->mk[str[i] - 'a'] ==NULL)
            return false;
        temp = temp->mk[str[i] - 'a'];
    }
    if(temp->prifix == 1)
        return true;
    else
        return false;
}
string trie_root :: autoC(string str){
trie *temp = root;
string ss="";
    for(int i=0;i< str.length();i++){
        if(temp->mk[str[i] - 'a'] ==NULL)
            break;
            ss.push_back(str[i]);
        temp = temp->mk[str[i] - 'a'];
    }
    if(temp->prifix == 1){
            ss.push_back('\0');
        return ss;
    }
    while(temp->prifix != 1){
            int i;
        for(i=0;i<MAX_CHAR;i++){
            if(temp->mk[i] != NULL){
                ss.push_back(i + 97);
                break;
            }

        }
        temp = temp->mk[i];
    }
    return ss;

}
int main(){
    int n,i,j;
    string str;
    cin>>n;
    trie_root obj;
//trie obj;
    for(int i=0;i<n;i++){
        cin>>str;
        obj.push_word(str);
    }

    for(int i=0;i<n;i++){
            cin>>str;
    cout<<obj.autoC(str)<<endl;
    }

return 0;
}

