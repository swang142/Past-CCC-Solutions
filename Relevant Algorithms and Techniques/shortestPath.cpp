#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

unordered_map<string, vector<string>> adjList;
unordered_set<string> visited;
unordered_map<string, string> parentN;

int multiSourceBFS(vector<string> roots, string dest){


    queue<string> q;
    queue<int> weights;

    for(string src: roots){
        q.push(src);
        weights.push(0);
        visited.insert(src);
    }


    while(!q.empty()){
        string cur= q.front();
        q.pop();
        int curDist= weights.front();
        weights.pop();



        if(curNode == dest){
            return curDist;
        }


        for(auto neighbour: adjList[curNode]){
            if(visited.find(neighbour)== visited.end()){
                q.push(neighbour);
                weights.push(curDist+1)
                visited.insert(neighbour);
            }
        }
    }


    return -1;




}




vector<string> shortestPathBFS(string src, string dest){
    queue<string> q;
    q.push(src);
    visited.insert(src);

    while(!q.empty()){
        string cur= q.front(); q.pop();
        if(cur== dest){
            break;
        }

        for(string neighbour: adjList[cur]){
            if(!visited.count(neighbour)){
                visited.insert(neighbour);
                q.push(neighbour);
                parentN[neighbour]= cur;
            }
        }
    }

    vector<string> path;
    string curNode= dest;

    while(curNode != ""){
        path.push_back(curNode);
        curNode= parentN[curNode];
    }

    reverse(path.begin(), path.end());

    if(path[0] == src){
        return path;
    }
    return {};

    
}


void buildGraph(vector<vector<string>> edgeList){


     for(auto edge: edgeList){
         
        if( adjList.find(edge[0]) == adjList.end() ){
            adjList[edge[0]]= {};
        }
        if( adjList.find(edge[1]) == adjList.end() ){
            adjList[edge[1]]= {};
        }


        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);


     }


}

int shortestLengthBFS(string src, string dest){

    queue<pair<string, int>> q;
    q.push({src, 0});

    while(!q.empty()){
        auto cur= q.front();
        q.pop();

        string curNode= cur.first; 
        int curDist= cur.second;

        if(curNode == dest){
            return curDist;
        }
        visited.insert(curNode);

        for(auto neighbour: adjList[curNode]){
            if(visited.find(neighbour)== visited.end()){
                q.push({neighbour, curDist+1});
                visited.insert(neighbour);
            }
        }
    }

    return -1;


}


int main(){
    vector<vector<string>> edges {
  {"m", "n"},
  {"n", "o"},
  {"o", "p"},
  {"p", "q"},
  {"t", "o"},
  {"r", "q"},
  {"r", "s"},
  {"t", "j"},
  {"j","f"},
  {"f", "p"}

};


    buildGraph(edges);

    auto path= shortestPathBFS("m", "p");

    for(auto d: path) cout << d << " ";

}