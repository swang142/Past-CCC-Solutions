#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

unordered_map<string, vector<pair<string, int>>> adjList;
unordered_set<string> visited;


struct edge{
    string startNode;
    string endNode;
    int cost;
    edge(string sN, string eN, int c){
        startNode= sN; endNode= eN; cost= c;

    }
};

bool comp(edge a, edge b){
    return a.cost > b.cost; 
    //larger costs have smaller priority, while the smaller costs have larger priority. Remember! Priority queues put the highest priority item at the front/
}

int primsAlg(string src){
    int numEdges= adjList.size()-1;  // the number of edge in minimum spanning tree will be always less than (V -1), where V is number of vertices in graph
    int MSTCost=0;
    int edgeCount=0;
    priority_queue<edge, vector<edge>, decltype(&comp)> pq(comp);

    visited.insert(src);
    for(auto neighbour: adjList[src] ){ 
        string neighbourNode= neighbour.first;
        int cost= neighbour.second;
        edge newE= edge(src, neighbourNode, cost);
        if(!visited.count(neighbourNode)){
            pq.push(newE);
        }
    }


    while(!pq.empty() && edgeCount < numEdges){
        edge curEdge= pq.top(); pq.pop();

        if(visited.count(curEdge.endNode)) continue; //points to already visited node

        MSTCost+= curEdge.cost; 
        edgeCount++;

        visited.insert(curEdge.endNode);

        for(auto neighbour: adjList[curEdge.endNode] ){ //ensures we are only visiting nodes connected to our current component.
            string neighbourNode= neighbour.first;
            int cost= neighbour.second;
            edge newE= edge(curEdge.endNode, neighbourNode, cost);
            if(!visited.count(neighbourNode)){
                pq.push(newE);
            }
        }
    }

    if(edgeCount < numEdges){ //MST not possible
        return -1; 
    }

    return MSTCost;

    
    
}

int main(){
  //  adjList= {  {"E", {"A", "F", "D"}}, {"C", {"B", "A"}}, {"A", {"D"}}, {"D",{"H", "G"}}, {"B", {"D"}}, {"G", {"I"}}, {"F",{"K", "J"}}, {"K", {"J"}}, {"J", {"M","L"}}, {"H",{"J", "I"}},{"M", {}}, {"L", {}}, {"I", {"L"}}};

        adjList= { {"1", {{"2",5}, {"4",4}} }, {"2", {{"1",5},{"4",2},{"3",3}} }, {"3", {{"2",3}, {"4",6}} }, {"4", {{"2",2}, {"3",6}, {"1",4}} }};

        cout << primsAlg("3") << endl; //we can start at any random node

        
        

    

}