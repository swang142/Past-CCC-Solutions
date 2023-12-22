#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

struct edge{
    int dest, time, hull;
    edge(int d, int t, int h ){
        dest= d; time= t; hull = h;
    }
};

int K, N, M;

vector<vector<edge>> adjList;
vector<vector<int>> shortestT;
unordered_set<int> visited;

bool comp(edge a, edge b){
    if(a.time == b.time){
        return a.hull > b.hull;
    }
    return a.time > b.time;
}

int dijkstra(int src, int dest){

  shortestT[src][K]= 0;

  priority_queue<edge, vector<edge>, decltype(&comp)> pq(comp);
  pq.push({src, 0, K});

  while(!pq.empty()){
      auto e= pq.top(); pq.pop();
      int curNode= e.dest, curHull= e.hull, curT= e.time;


    if(curNode == dest) return shortestT[dest][curHull];


      for(auto neigh: adjList[curNode]){
          int neighNode= neigh.dest, neighT= neigh.time,  neighH= neigh.hull;
            int newT= shortestT[curNode][curHull] + neighT;
            int newH= curHull - neighH;


              if(newH > 0 && newT < shortestT[neighNode][newH]){
                 shortestT[neighNode][newH]= newT;
                  pq.push({neighNode, newT, newH});

              }
      }
  }

  return -1;



}
int main(){

    cin>> K >> N >> M;
    
    shortestT.assign(N+1, vector<int>(M+1, inf));
    adjList.assign(N+1, {});
    for(int i=0; i<M; i++){
        int a, b, t, h; cin>> a >> b >> t >>h;
        adjList[a].push_back({b, t, h}); adjList[b].push_back({a, t, h});
    }
    int A, B; cin >> A >> B;

    cout << dijkstra(A, B);

}