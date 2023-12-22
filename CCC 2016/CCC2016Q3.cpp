#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

int N, M, root;

unordered_set<int> restr;
unordered_map<int, vector<int>> adjList;
vector<bool> valid;
unordered_set<int> visited1;

pair<int, int> farthestNode(int src){ 
    visited1.clear();
    queue<int> q, weights;
    q.push(src);
    weights.push(0);
    visited1.insert(src);
    int curDist;
    int current;
    while(!q.empty()){
        current= q.front();
        curDist= weights.front();
        q.pop(); weights.pop();
        for(int neighbour: adjList[current]){
            if(!visited1.count(neighbour) && valid[neighbour]){
                q.push(neighbour);
                weights.push(curDist+ 1);
                visited1.insert(neighbour);
            }
        }
    }
    return {current, curDist};
}

int treeDiameter(){
    auto farthestFromNode= farthestNode(root);
    int nodeFarthestFromNode= farthestFromNode.first;
    auto diameterNode= farthestNode(nodeFarthestFromNode);
    return diameterNode.second;
}


unordered_set<int> visited2;

bool prune(int cur){
    visited2.insert(cur);
    

    for(int neigh: adjList[cur]){
        if(!visited2.count(neigh)){
            visited2.insert(neigh);
            if(prune(neigh)) valid[cur]= true;
        }
    }

    return valid[cur];
}

int main(){

    cin >> N >> M;

    valid.assign(N+1, false);

    for(int i=0; i< M; i++){
        int r; cin >> r;
        restr.insert(r);
        valid[r]= true;
        root = r;

    }


    for(int i=0; i< N-1; i++){
        int a, b; cin>> a >> b;
        adjList[a].push_back(b); adjList[b].push_back(a);
    }

    prune(root);
    
    int size=0;
    for(int i=0; i< valid.size(); i++){
        if(valid[i]) size++;
    }
    cout << (size-1)*2 - treeDiameter() << endl;

}

