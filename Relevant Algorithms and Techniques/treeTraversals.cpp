#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<string, vector<string>> adjList;

unordered_set<string> visited;


bool dfs(string cur, string target){
    if(visited.count(cur)){
        return false;
    }
    visited.insert(cur);

    cout << cur << " ";

    if(cur== target){
        return true;
    }
    

    for(string d: adjList[cur]){
        if(dfs(d, target)) return true;
    }

    return false;
}


void bfs(string start, string target){
    queue<string> q;
    q.push(start);
    visited.insert(start);

    while(!q.empty()){
        string current= q.front();
        q.pop();

        cout <<  current << " ";

        if(current== target){
            return;
        }

        for(string neighbour: adjList[current]){
            if(!visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }

}

void buildGraph(vector<vector<string>> edgeList){

     for(auto edge: edgeList){
         
        if( adjList.find(edge[0]) == adjList.end()){
            adjList[edge[0]]= {};
        }
        if( adjList.find(edge[1]) == adjList.end() ){
            adjList[edge[1]]= {};
        }

        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);

     }

}


int main(){


    vector<vector<string>> edgeList;
    edgeList.push_back({"i", "j"}); edgeList.push_back({"k", "i"}); edgeList.push_back({"m", "k"}); edgeList.push_back({"k", "l"}); edgeList.push_back({"o", "n"});

    buildGraph(edgeList);

    bfs("k", "l");





}

