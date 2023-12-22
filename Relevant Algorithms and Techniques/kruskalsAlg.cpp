#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

unordered_map<string, vector<pair<string, int>>> adjList;
unordered_map<string, string> parents;
unordered_map<string, int> setSizes;

int numSets= 0;


string find(string node){
    if(parents[node]== node){
        return node;
    }

    parents[node]= find(parents[node]);
    return parents[node];
}

void Union(string x, string y){
    string rootX= find(x);
    string rootY= find(y);
    if(rootX!= rootY){
        numSets--;
        if(setSizes[rootX] < setSizes[rootY]){
            parents[rootX]= rootY;
            setSizes[rootY]+= setSizes[rootX];
        }
        else{
            parents[rootX]= rootY;
            setSizes[rootX]+= setSizes[rootY];
        }
    }

}

struct edge{
    string startNode;
    string endNode;
    int cost;
    edge(string sN, string eN, int c){
        startNode= sN; endNode= eN; cost= c;

    }
};

bool comp(edge a, edge b){
    return a.cost < b.cost; 
}

int kruskalsAlg(){

    vector<edge> edgeList;

    for(auto pair: adjList){ //creates edgeList by looping through all nodes
        string curNode= pair.first;
        auto neighbours= pair.second;
        for(auto neighbour: neighbours){
            edge e= edge(curNode, neighbour.first, neighbour.second );
            edgeList.push_back(e);
        }
    }

    sort(edgeList.begin(), edgeList.end(), comp); //sorts our edgeList based on cost
    
    for(auto pair: adjList){
        string node= pair.first;
        parents[node]= node;
        setSizes[node]= 1;
        numSets++;
    }

    int MSTCost= 0;

    for(auto edge: edgeList){ //loops through all edges
        if(numSets == 1){ //breaks once all nodes are a part of a set
            return MSTCost;
        }
         string startNode= edge.startNode;
         string endNode= edge.endNode;
         if(find(startNode) == find(endNode)){ //if part of the same disjoint set, discard edge
            continue;
         }
         MSTCost+= edge.cost;
         Union(startNode, endNode);

    }

    return MSTCost;

}

int main(){
  //  adjList= {  {"E", {"A", "F", "D"}}, {"C", {"B", "A"}}, {"A", {"D"}}, {"D",{"H", "G"}}, {"B", {"D"}}, {"G", {"I"}}, {"F",{"K", "J"}}, {"K", {"J"}}, {"J", {"M","L"}}, {"H",{"J", "I"}},{"M", {}}, {"L", {}}, {"I", {"L"}}};

        adjList= { {"1", {{"6",10}, {"2",28}} }, {"2", {{"1",28}, {"7",14},{"3",16}} }, {"7", {{"2",14}, {"5",24}, {"4",18}} }, {"3", {{"2",16}, {"4",12}}}, {"4", {{"7",18}, {"3",12}, {"5",22}}}, {"5", {{"6",25}, {"7",24}, {"4",22}}}, {"6", {{"1",10}, {"5",25}}}, {"8", {}}, {"9", {}} };

        cout << kruskalsAlg() << endl; //we can start at any random node

        cout << numSets << endl;

        
        

    

}