#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

unordered_map<string, vector<pair<string, int>>> adjList;
unordered_map<string, int> ids;
unordered_map<string, int> lowLink;
unordered_set<string> visited;
unordered_map<string, bool> artPoints;
int outgoingEdgesFromRoot=0; 
int id=0;


void dfs(string root, string curNode, string prevNode){
    if(prevNode == root) outgoingEdgesFromRoot++;
    visited.insert(curNode);
    id++;
    ids[curNode]= id; lowLink[curNode]= id; //low link is initially the id of the node

    for(auto neighbour: adjList[curNode]){
        string neighbourNode= neighbour.first;
        if(neighbourNode == prevNode) continue; // the reason we keep track of previous nodes is so we dont bump into them again to create inf loops if we're dealing with undirected edges.
        if(!visited.count(neighbourNode)){
            dfs(root, neighbourNode, curNode);
            lowLink[curNode]= min(lowLink[curNode], lowLink[neighbourNode]);   //updates our low link recursively using the current smallest low link.

            if(ids[curNode] < lowLink[neighbourNode]){ //art point found via bridge logic.
                artPoints[curNode]= true;
            }
            if(ids[curNode] == lowLink[neighbourNode]){ //art point found via cycle.
                artPoints[curNode]= true;
            }
        }
        else{
            lowLink[curNode]= min(lowLink[curNode], ids[neighbourNode]);
        }
        

    }

}

void findArtPoints(){


    string curNode;
    for(auto pair: adjList){
        curNode= pair.first;
        if(!visited.count(curNode)){ //ensures we only perform our dfs on different components
            outgoingEdgesFromRoot= 0;
            dfs(curNode, curNode, "-1" ); //our starting node does not have a prev node.
            artPoints[curNode]= (outgoingEdgesFromRoot>1); //the root is only an artPoint if it has >1 neighbours

           
        } 
    }


}


int main(){
  //  adjList= {  {"E", {"A", "F", "D"}}, {"C", {"B", "A"}}, {"A", {"D"}}, {"D",{"H", "G"}}, {"B", {"D"}}, {"G", {"I"}}, {"F",{"K", "J"}}, {"K", {"J"}}, {"J", {"M","L"}}, {"H",{"J", "I"}},{"M", {}}, {"L", {}}, {"I", {"L"}}};

               adjList= { {"0", {{"1",1}, {"2",1}} }, {"1", {{"2",4}, {"0",4}} }, {"2", {{"0",8}, {"1",4}, {"3",11}, {"5",11}} }, {"3", {{"2",4}, {"4",5}} }, {"4", {{"3",4}} }, {"5", {{"2",4}, {"6",9}, {"8",4}} }, {"6", {{"5",4}, {"7",1}} }, {"7", {{"6",4},{"8",2}} }, {"8", {{"7",4},{"5",2}} } };

        findArtPoints();
        for(auto pair: artPoints){
            if(pair.second){
                cout << pair.first << endl;
            }
        }
    

}