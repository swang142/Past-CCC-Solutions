#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct treeNode{
    string str;
    unordered_map<char, treeNode*> children;
    treeNode(string S){
        this-> str= S;
    }
};



void insertRecur(treeNode* curNode, int index,  string S){

    //Case #1: reached end of the string
    if(index== S.length()){
        return;
    }

    //Case #2: NO character match
    if(!curNode->children.count(S[index])){
        treeNode* t= new treeNode(S.substr(index)); 
        //once we've reached a layer that doesnt contain our current char, we KNOW that a chain of singular nodes will be produced. So we can just 'compress' all of them into a string.
        curNode->children[S[index]]=  t; //ex: children["i"]= new treeNode ("imize");
        return;
    }

    //Case #3: initial character matched -> we want to determine the common prefix
    treeNode* childNode= curNode->children[S[index]];
    string childStr= childNode->str;
    int minLength= min(S.length()- index, childStr.length());

    int i;
    for(i= 0; i< minLength; i++){
        if(S[i+index] != childStr[i]){
            break;
        }
    }
    //i = number of characters in the common prefix


    if(i == childNode->str.length()){ //if the entire inital node IS a prefix of the one we're inserting, add the part thats not common as a child node
        insertRecur(childNode, i+index, S); 
    }
    else{
        //create new nodes w/o the common prefix part
        treeNode* newNode1= new treeNode(childNode->str.substr(i));
        newNode1->children= childNode->children; //we can give the initial node's current children to one of the new nodes.
        treeNode* newNode2= new treeNode(S.substr(i+index));

        //update the inital node to be the common prefix part. Clear its children
        childNode->str= childNode->str.substr(0, i);
        childNode->children.clear();

        //assign the new nodes created to be its children
        childNode->children[childNode -> str[i]]= newNode1;
        childNode->children[S[i+index]]= newNode2;
    }

}

void insert(treeNode* root, string S){

    insertRecur(root ,0, S);
}

bool searchRecur(treeNode* curNode, int index, string S){
     //Case #1: reached end of the string. string found
    if(index== S.length()){
        return true;
    }
     //Case #2: NO character match, return false
    if(!curNode -> children.count(S[index])){
        return false;
    }

     //Case #3: initial character matched ->we want to determine the common prefix
    treeNode* childNode= curNode->children[S[index]];
    string childStr= childNode->str;
    int minLength= min(S.length()- index, childStr.length());

    int i;
    for(i= 0; i< minLength; i++){
        if(S[i+index] != childStr[i]){
            break;
        }
    }
    //i = number of characters in the common prefix


    if(i <= childNode->str.length()){ //if the entire inital node IS a prefix of the one we're searching for or contains the one we're searching for, we can continue
        return searchRecur(curNode, index+i, S);
    }

    return false; //if not, it doesnt exist.
}

bool search(treeNode* curNode, string S){
    return searchRecur(curNode, 0, S);
}

void dfs(treeNode* curNode){
    cout << curNode->str << endl;


    for(auto child: curNode->children){
        dfs(child.second);
    }
}


int main(){

    treeNode* root= new treeNode("-");
    insert(root, "lit");
    insert(root, "litmus");
    insert(root, "lite");
    insert(root, "ligloo");


    dfs(root);


}