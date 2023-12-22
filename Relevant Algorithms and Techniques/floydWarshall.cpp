#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

unordered_map<string, unordered_map<string, int>> adjMatrix;
unordered_map<string, unordered_map<string, int>> shortestDistances; //contains the best distances from our source node to all others
unordered_map<string, unordered_map<string, string>> nextN; //stores the nodes that come after the current node

void floydWarshall(){


    //makes an exact copy of adj matrix
    for(auto a: adjMatrix){
        string node1= a.first;
        for(auto b: adjMatrix[node1]){
            string node2= b.first;
            int dist= adjMatrix[node1] [node2];
            shortestDistances[node1][node2]= dist;
            if(dist != inf){
                nextN[node1][node2]= node2; //the node that comes after node1 is node2 obviously. 
            }
        }
    }


    for(auto pairK: adjMatrix){
        string k= pairK.first;
        for(auto pairI: adjMatrix){
            string i= pairI.first;
            for(auto pairJ: adjMatrix){
                string j= pairJ.first;
                if(shortestDistances[i][k] + shortestDistances[k][j] < shortestDistances[i][j]  ){
                    shortestDistances[i][j]= shortestDistances[i][k] + shortestDistances[k][j];
                    nextN[i][j]= nextN[i][k]; //updates our next values when we find a shorter path through a diff route.

                }
            }
        }
    }

    //detects negative cycles
        for(auto pairK: adjMatrix){
        string k= pairK.first;
        for(auto pairI: adjMatrix){
            string i= pairI.first;
            for(auto pairJ: adjMatrix){
                string j= pairJ.first;
                if(shortestDistances[i][k] + shortestDistances[k][j] < shortestDistances[i][j]  ){
                    shortestDistances[i][j]= -inf; //part of a negative cycle
                    nextN[i][j]= "-1"; //part of a negative cycle
                }
            }
        }
    }

}

vector<string> reconstructPath(string src, string dest){
    vector<string> path;

    if(shortestDistances[src][dest] == inf) return path; //no possible path

    string curNode= src;



    while(curNode != dest){
        if(curNode == "-1") return {"-1"}; //encountered negative cycle
        path.push_back(curNode);
        curNode= nextN[curNode][dest];
    }

    if(nextN[curNode][dest]== "-1") return {"-1"}; //encountered negative cycle at the dest
    path.push_back(dest);

    return path;


}

int main(){
  //  adjList= {  {"E", {"A", "F", "D"}}, {"C", {"B", "A"}}, {"A", {"D"}}, {"D",{"H", "G"}}, {"B", {"D"}}, {"G", {"I"}}, {"F",{"K", "J"}}, {"K", {"J"}}, {"J", {"M","L"}}, {"H",{"J", "I"}},{"M", {}}, {"L", {}}, {"I", {"L"}}};

        for(int i=0; i<=4; i++){
            for(int j=0; j<=4; j++){
                adjMatrix[to_string(i)][to_string(j)]= inf;
                if(i == j) adjMatrix[to_string(i)][to_string(j)]= 0;
            }
        }
        adjMatrix["1"]["3"] = -2;
        adjMatrix["2"]["3"] = 3;
        adjMatrix["3"]["4"] = 2;
        adjMatrix["4"]["2"] = -1;
        adjMatrix["2"]["1"] = 4;

        floydWarshall();

        auto path= reconstructPath("1", "2");

        for(auto d: path) cout << d << " ";
    

}