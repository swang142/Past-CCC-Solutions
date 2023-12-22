
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<char, int> freq;

struct Node{
    char character; int weight; Node* left; Node* right;


    Node(char character, int weight, Node*left, Node* right){
        this-> character = character;
        this -> weight= weight;
       this -> left= left;
       this -> right= right;
    }
};


int comp(Node* a, Node* b){ //returns if a<= b
    return a->weight > b->weight;
}



Node* makeTree(){

    priority_queue<Node*, vector<Node*>, decltype(&comp)> q(comp);


    for(auto p: freq){

        Node* n= new Node(p.first, p.second, nullptr, nullptr);
        q.push(n);
    }



    
    while(q.size() >1){

       Node* min= q.top();
        q.pop();

        Node* secMin= q.top();
        q.pop();

        Node* parent= new Node('*', min->weight+ secMin->weight, min, secMin);

        q.push(parent);
        
    }

    return q.top();


}

void printCodeWord(Node* node, string str){

    if(node== nullptr){
        return;
    }
    if(node->character != '*'){
        cout << node->character << ": " << str << "\n";
    }
    printCodeWord(node->left, str+ "0");
    printCodeWord(node -> right, str + "1");
    
}

void frequencyTable(string s){
    for (int i=0; i<s.size(); i++){
        freq[s[i]]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    frequencyTable("");

    Node* root= makeTree();

    printCodeWord(root, "");



}