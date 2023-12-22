#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct trieNode{
    char c;
    unordered_map<char, trieNode*> children;
    trieNode(char c){
        this-> c= c;
    }
};

void insertRecur(trieNode* curNode, int index,  string S){

    if(index== S.length()){
        return;
    }
    if(!curNode->children.count(S[index])){
        trieNode* t= new trieNode(S[index]);
        curNode->children[S[index]]=  t;
    }
    insertRecur(curNode->children[S[index]], index+1, S);

}

void insert(trieNode* root, string S){
    cout << S << endl;

    insertRecur(root ,0, S);
}

bool searchRecur(trieNode* curNode, int index, string S){
    if(index== S.length()){
        return true;
    }
    if(!curNode -> children.count(S[index])){
        return false;
    }
    return searchRecur(curNode -> children[S[index]], index+1, S);
}

bool search(trieNode* curNode, string S){
    return searchRecur(curNode, 0, S);
}

void dfs(trieNode* curNode){
    cout << curNode->c << endl;

    for(auto child: curNode->children){
        dfs(child.second);
    }
}

int main(){
    trieNode* root= new trieNode('-');
    string s= "minimize";

    for(int i=0; i<s.length(); i++){
        insert(root, s.substr(i, s.length()- i));
    }


}