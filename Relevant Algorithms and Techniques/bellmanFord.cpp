#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

unordered_map<string, vector<pair<string, int>>> adjList;
unordered_map<string, int> shortestDistances; //contains the best distances from our source node to all others



void bellmanFord(string src){
    
    int numNodes= adjList.size();

    for(auto pair: adjList){
        string node= pair.first;
        shortestDistances[node]= inf;
    }

    shortestDistances[src]=0;

    for(int i=0; i< numNodes-1; i++){
        for(auto pair: adjList){
            string curNode= pair.first;
            int curDistance= shortestDistances[curNode];- 
            for(auto neighbour: adjList[curNode]){
                string neighbourNode= neighbour.first;
                int edgeLength= neighbour.second;
                int newDist= edgeLength + curDistance;
                shortestDistances[neighbourNode]= min(shortestDistances[neighbourNode], newDist); //relaxes the edge
            }
        }
    }

    //check for negative cycles
    for(int i=0; i< numNodes-1; i++){
        for(auto pair: adjList){
        string curNode= pair.first;
        int curDistance= shortestDistances[curNode];
        for(auto neighbour: adjList[curNode]){
            string neighbourNode= neighbour.first;
            int edgeLength= neighbour.second;
            int newDist= edgeLength + curDistance;
            if(newDist < shortestDistances[neighbourNode]){
                shortestDistances[neighbourNode]= -inf;
                }
            }
        }
    }

}

int main(){
  //  adjList= {  {"E", {"A", "F", "D"}}, {"C", {"B", "A"}}, {"A", {"D"}}, {"D",{"H", "G"}}, {"B", {"D"}}, {"G", {"I"}}, {"F",{"K", "J"}}, {"K", {"J"}}, {"J", {"M","L"}}, {"H",{"J", "I"}},{"M", {}}, {"L", {}}, {"I", {"L"}}};

        adjList= { {"A", {{"B",3}, {"C",6}} }, {"B", {{"D",4}, {"C",4}, {"E", 11}}}, {"C", {{"D",8}, {"G",11}} }, {"D", {{"F",5}, {"E", -4}, {"G", 2}} }, {"E", {{"H",9}} }, {"F", {{"H",1}} }, {"G", {{"H",2}} }, {"H", {} } };

        bellmanFord("A");

        cout << shortestDistances["D"] << endl;
    

}