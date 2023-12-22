#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

unordered_map<string, vector<pair<string, int>>> adjList;
unordered_map<string, int> ids;
unordered_map<string, int> lowLink;
unordered_set<string> visited;
unordered_map<string, bool> onStack;
stack<string> Stack;

int id=0;
int sccCount= 0;


void dfs(string curNode){
    visited.insert(curNode);
    Stack.push(curNode);
    id++;
    ids[curNode]= id; lowLink[curNode]= id; //low link is initially the id of the node

    for(auto neighbour: adjList[curNode]){
        string neighbourNode= neighbour.first;
        if(!visited.count(neighbourNode)){
            dfs(curNode);
        }
        if(onStack[curNode]){
            lowLink[curNode]= min(lowLink[curNode], lowLink[neighbourNode]); //determines our SCCs
        }

        if(ids[curNode]== lowLink[curNode]){ //checking if we're back at the start of a SCC
            string stackTop= Stack.top();
            do{
                Stack.pop();
                onStack[stackTop]= false;
                lowLink[stackTop]= id[curNode]; //make sure all nodes in the same SCC share the same low link value
                stackTop= Stack.top();
            }while(stackTop != curNode);
            sccCount++;
        
        }
        

    }

}

void tarjansSCC(){

    for(auto pair: adjList){
        string node= pair.first;
        onStack[node]= false;
    }

    for(auto pair: adjList){
        string node= pair.first;
        if(!visited.count(node)){
            dfs(node);
        }
    }

    

}


int main(){
  //  adjList= {  {"E", {"A", "F", "D"}}, {"C", {"B", "A"}}, {"A", {"D"}}, {"D",{"H", "G"}}, {"B", {"D"}}, {"G", {"I"}}, {"F",{"K", "J"}}, {"K", {"J"}}, {"J", {"M","L"}}, {"H",{"J", "I"}},{"M", {}}, {"L", {}}, {"I", {"L"}}};

        adjList= { {"0", {{"1",1}, {"2",1}} }, {"1", {{"2",4}, {"0",4}} }, {"2", {{"0",8}, {"1",4}, {"3",11}, {"5",11}} }, {"3", {{"2",4}, {"4",5}} }, {"4", {{"3",4}} }, {"5", {{"2",4}, {"6",9}, {"8",4}} }, {"6", {{"5",4}, {"7",1}} }, {"7", {{"6",4},{"8",2}} }, {"8", {{"7",4},{"5",2}} } };
        cout << "working" << endl;
        
        tarjansSCC();

       cout << sccCount << endl;
    

}