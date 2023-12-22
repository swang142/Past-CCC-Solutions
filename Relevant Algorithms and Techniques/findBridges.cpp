#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

unordered_map<string, vector<pair<string, int>>> adjList;
unordered_map<string, int> ids;
unordered_map<string, int> lowLink;
unordered_set<string> visited;

int id=0;


void dfs(string curNode, string prevNode, vector<pair<string,string>>& bridges){
    visited.insert(curNode);
    id++;
    ids[curNode]= id; lowLink[curNode]= id; //low link is initially the id of the node

    for(auto neighbour: adjList[curNode]){
        string neighbourNode= neighbour.first;
        if(neighbourNode == prevNode) continue; // the reason we keep track of previous nodes is so we dont bump into them again to create inf loops if we're dealing with undirected edges.
        if(!visited.count(neighbourNode)){
            dfs(neighbourNode, curNode, bridges);
            lowLink[curNode]= min(lowLink[curNode], lowLink[neighbourNode]);   //updates our low link recursively using the current smallest low link.

            if(ids[curNode] < lowLink[neighbourNode]){ //bridge condition is met.
                bridges.push_back({curNode, neighbourNode});
            }
        }
        else{
            lowLink[curNode]= min(lowLink[curNode], ids[neighbourNode]);
             //if we encounter a node we've already visited, its low link might have not been computed yet, but it is AT LEAST its id, so we compare w/ its id.
        }
        

    }

}

vector<pair<string,string>> findBridges(){
    vector<pair<string,string>> bridges;

    string curNode;
    for(auto pair: adjList){
        curNode= pair.first;
        if(!visited.count(curNode)){ //ensures we only perform our dfs on different components
            dfs(curNode, "-1", bridges); //our starting node does not have a prev node.
        } 
    }

    return bridges;

}


int main(){
  //  adjList= {  {"E", {"A", "F", "D"}}, {"C", {"B", "A"}}, {"A", {"D"}}, {"D",{"H", "G"}}, {"B", {"D"}}, {"G", {"I"}}, {"F",{"K", "J"}}, {"K", {"J"}}, {"J", {"M","L"}}, {"H",{"J", "I"}},{"M", {}}, {"L", {}}, {"I", {"L"}}};

        adjList= { {"0", {{"1",1}, {"2",1}} }, {"1", {{"2",4}, {"0",4}} }, {"2", {{"0",8}, {"1",4}, {"3",11}, {"5",11}} }, {"3", {{"2",4}, {"4",5}} }, {"4", {{"3",4}} }, {"5", {{"2",4}, {"6",9}, {"8",4}} }, {"6", {{"5",4}, {"7",1}} }, {"7", {{"6",4},{"8",2}} }, {"8", {{"7",4},{"5",2}} } };

        auto bridges= findBridges();

        for(auto pair: bridges){
            cout << pair.first << ", "<< pair.second << endl;
        }
    

}