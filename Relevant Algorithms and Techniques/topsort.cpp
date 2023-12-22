#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<string, vector<string>> adjList;

unordered_set<string> visited;

void dfs(vector<string>& orderings, string curNode){
    if(!visited.count(curNode)){
        visited.insert(curNode);

        for(auto neighbour: adjList[curNode]){
            dfs(orderings, neighbour);
        }
        orderings.insert(orderings.begin(), curNode);

    }
     
}

vector<string> topsort(){
    vector<string> orderings;

    
        dfs(orderings, "H");
    dfs(orderings, "E");
    dfs(orderings, "C");

    return orderings;
}

int main(){
    adjList= {  {"E", {"A", "F", "D"}}, {"C", {"B", "A"}}, {"A", {"D"}}, {"D",{"H", "G"}}, {"B", {"D"}}, {"G", {"I"}}, {"F",{"K", "J"}}, {"K", {"J"}}, {"J", {"M","L"}}, {"H",{"J", "I"}},{"M", {}}, {"L", {}}, {"I", {"L"}}};

    auto d= topsort();

    cout << adjList.size() << endl;

    for(string w: d) cout << w << " ";
    }