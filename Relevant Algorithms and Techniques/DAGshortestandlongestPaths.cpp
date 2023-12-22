#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

unordered_map<string, vector<pair<string, int>>> adjList;

unordered_set<string> visited;


void dfs(vector<string>& orderings, string curNode){
    if(!visited.count(curNode)){
        visited.insert(curNode);

        for(auto neighbour: adjList[curNode]){
            dfs(orderings, neighbour.first);
        }
        orderings.insert(orderings.begin(), curNode);

    }
     
}

vector<string> topsort(){
    vector<string> orderings;

    
    for(auto e: adjList){
        string node= e.first;
        dfs(orderings, node);
    }


    return orderings;
}

unordered_map<string, int> pathLengths;

void DAGShortestPath(string src){
    auto orderings= topsort();

    for(string e: orderings){
        pathLengths[e]= inf;
    }   
    pathLengths[src]=0;

    for(string e: orderings){
        cout << e << endl;
        if(pathLengths[e]!= inf){
            for(auto neighbour: adjList[e]){
                string node= neighbour.first;

                int edgeWeight= neighbour.second;
                int newDist= pathLengths[e] + edgeWeight;
                
                pathLengths[node]= min(pathLengths[node], newDist);


            }

        }
    }

}

void DAGLongestPath(string src){
    auto orderings= topsort();

    for(string e: orderings){
        pathLengths[e]= inf;
    }   
    pathLengths[src]=0;

    for(string e: orderings){
        if(pathLengths[e]!= inf){
            for(auto neighbour: adjList[e]){
                string node= neighbour.first;

                int edgeWeight= neighbour.second;
                int newDist= pathLengths[e] - edgeWeight;
                
                pathLengths[node]= min(pathLengths[node], newDist);


            }

        }
    }

}


int main(){
  //  adjList= {  {"E", {"A", "F", "D"}}, {"C", {"B", "A"}}, {"A", {"D"}}, {"D",{"H", "G"}}, {"B", {"D"}}, {"G", {"I"}}, {"F",{"K", "J"}}, {"K", {"J"}}, {"J", {"M","L"}}, {"H",{"J", "I"}},{"M", {}}, {"L", {}}, {"I", {"L"}}};

    adjList= { {"A", {{"B",3}, {"C",-100}} }, {"B", { {"C",4}}}, {"C", {{"D",8}, {"G",11}} }, {"D", {{"F",5}, {"E", -4}, {"G", 2}} }, {"E", {{"H",9}, {"B", -11}} }, {"F", {{"H",1}} }, {"G", {{"H",2}} }, {"H", {} } };
    DAGShortestPath("D");


    for(auto q: pathLengths){
        cout << q.first << " " << q.second << endl;
    }


}