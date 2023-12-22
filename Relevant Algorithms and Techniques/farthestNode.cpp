#include <bits/stdc++.h>
using namespace std;
typedef long long ll;




unordered_map<string, vector<string>> adjList;
unordered_set<string> visited;

string farthestNode(string src){
    visited.clear();
    queue<string> q;
    q.push(src);
    visited.insert(src);

    string current;

    while(!q.empty()){
        current= q.front();
        q.pop();

        for(string neighbour: adjList[current]){
            if(!visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }

    return current;

}

int main(){

    adjList["0"]= {"1","3"}; adjList["1"]= {"0","2", "4"}; adjList["2"]= {"1","5"}; adjList["3"]= {"0"}; adjList["4"]= {"1","5"}; adjList["5"]= {"2","4"}; 

    for(auto d: adjList){
        string node= d.first;
        cout << farthestNode(node) << '\n';
    }

}