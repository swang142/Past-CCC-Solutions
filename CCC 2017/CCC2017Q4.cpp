#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll inf= 1e9;

struct edge{
    ll startNode;
    ll endNode;
    ll cost;
    bool on;
    edge(ll sN, ll eN, ll c, bool o){
        startNode= sN; endNode= eN; cost= c; on= o;
    }
};


unordered_map<ll, vector<edge>> adjList;
unordered_map<ll, ll> parents;
unordered_map<ll, ll> setSizes;
ll numSets= 0;


ll find(ll node){
    if(parents[node]== node){
        return node;
    }
    parents[node]= find(parents[node]);
    return parents[node];
}


void Union(ll x, ll y){
    ll rootX= find(x);
    ll rootY= find(y);
    if(rootX!= rootY){
        numSets--;
        if(setSizes[rootX] < setSizes[rootY]){
            parents[rootX]= rootY;
            setSizes[rootY]+= setSizes[rootX];
        }
        else{
            parents[rootY]= rootX;
            setSizes[rootX]+= setSizes[rootY];
        }
    }
}

bool comp(edge a, edge b){
    if(a.cost!= b.cost){
        return a.cost < b.cost;
    }

    else{
        if(a.on && !b.on){
            return true;
        }
        return false;
    }
     
}

vector<edge> MST;
vector<edge> edgeList;

ll kruskalsAlg(){


    for(auto pair: adjList){ //creates edgeList by looping through all nodes
        auto neighbours= pair.second;
        for(auto e: neighbours){
            edgeList.push_back(e);
        }
    }

    sort(edgeList.begin(), edgeList.end(), comp); //sorts our edgeList based on cost

    
    for(auto pair: adjList){
        ll node= pair.first;
        parents[node]= node;
        setSizes[node]= 1;
        numSets++;
    }


    ll MSTCost= 0;



    for(auto edge: edgeList){ //loops through all edges
        if(numSets == 1){ //breaks once all nodes are a part of a set
            return MSTCost;
        }
         ll startNode= edge.startNode;
         ll endNode= edge.endNode;
         if(find(startNode) == find(endNode)){ //if part of the same disjoll set, discard edge
            continue;
         }

         MSTCost+= edge.cost;
         MST.push_back(edge);
         Union(startNode, endNode);
    }


    return MSTCost;

}


ll N, M, D;


int main(){
    cin >> N >> M >> D;

    for(ll i=0; i< M; i++){
        ll A, B, C;
        cin >> A >> B >> C;



        if(N>1){
            edge e1= edge(A, B, C, true);
            edge e2= edge(B, A, C, true);
            adjList[A].push_back(e1);
            adjList[B].push_back(e2);
            N--;


        }
        else{
            edge e3= edge(A, B, C, false);
            edge e4= edge(B, A, C, false);
            adjList[A].push_back(e3);
            adjList[B].push_back(e4);

        }

    }

    kruskalsAlg();



    ll needOn= 0;
    for(auto a: MST){
        if(!a.on){
            a.on= true;
            needOn+=1;
        }
    }


    




    cout << needOn << " ";









}