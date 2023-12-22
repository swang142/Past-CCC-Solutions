#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;


unordered_map<string, vector<pair<string, int>>> adjList;
unordered_map<string, int> shortestDistances; //contains the best distances from our source node to all others


bool comp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second; //larger costs have smaller priority, while the smaller costs have larger priority. Remember! Priority queues put the highest priority item at the front/
}


int lazyDijkstras(string src, string dest){
    for(auto e: adjList){
        string node= e.first;
        shortestDistances[node]= inf;
    }    
    shortestDistances[src]= 0;


    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(&comp)> pq(comp);


    pq.push({src,0});


    while(!pq.empty()){
        auto pair= pq.top(); pq.pop();
        string curNode= pair.first; int curDistance= pair.second;


        if(shortestDistances[curNode] < curDistance) continue;         //Which means we've obtained a better distance routing through other nodes before processing our current one so we can just ignore it.

        if(curNode == dest) return shortestDistances[dest];

        for(auto neighbour: adjList[curNode]){ 
            string neighbourNode= neighbour.first; int cost= neighbour.second;
          
            //relax edge by updating minimum cost if possible
            int newDist= shortestDistances[curNode]+ cost;
            if(newDist<shortestDistances[neighbourNode]){
                shortestDistances[neighbourNode]= newDist;
                pq.push({neighbourNode, shortestDistances[neighbourNode]});
            }
            
        }
    }

    return inf; //no possible path
}




int main(){
  //  adjList= {  {"E", {"A", "F", "D"}}, {"C", {"B", "A"}}, {"A", {"D"}}, {"D",{"H", "G"}}, {"B", {"D"}}, {"G", {"I"}}, {"F",{"K", "J"}}, {"K", {"J"}}, {"J", {"M","L"}}, {"H",{"J", "I"}},{"M", {}}, {"L", {}}, {"I", {"L"}}};


    adjList= { {"A", {{"B",3}, {"C",6}} }, {"B", {{"D",4}, {"C",4}, {"E", 11}}}, {"C", {{"D",8}, {"G",11}} }, {"D", {{"F",5}, {"E", 4}, {"G", 2}} }, {"E", {{"H",9}} }, {"F", {{"H",1}} }, {"G", {{"H",2}} }, {"H", {} } };
    cout << lazyDijkstras("A", "G") << endl;
    
    


}
