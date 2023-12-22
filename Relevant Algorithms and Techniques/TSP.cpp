#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

vector<vector<int>> adjMatrix;
unordered_map<int, unordered_map<int, int>> memo;
int num;



int solve(int curNode, int remainingNodes){

    if(memo[curNode][remainingNodes] != -inf){
        return memo[curNode][remainingNodes];
    }

    int minDist= inf;

    for(int i=0; i< num; i++){
        if(remainingNodes & (1<< i)){ //goes through each of our remaining nodes
            int remaining = remainingNodes&~(1 << i); //marks the node as visited (0), updating our remaining nodes
            int dist = adjMatrix[curNode][i]+ solve(i, remaining); //adds the distance from the currentNode to the remaining nodes to our new recursive call with our updated remaining nodes
            minDist= min(minDist, dist); //determines the min distance at each level
        }
    }

    memo[curNode][remainingNodes]= minDist;
    return minDist;

}

int tsp(int src){
    num= adjMatrix.size();
    int NO_NODES_REMAINING= 0; //0000, no nodes remaining
    int ALL_NODES_REMAINING= (1<<num) -1; //1111, all nodes remaining

    ALL_NODES_REMAINING= ALL_NODES_REMAINING&~(1 << src); //marks our source node as visited. ex: 1110


    int numCols= int(pow(2,num));

    
    for(int i=0; i< num; i++){
        for(int j=0; j< numCols; j++){
            memo[i][j]= -inf;
        }
    }

    for(int i=0; i< num; i++){
        memo[i][NO_NODES_REMAINING]= adjMatrix[i][src]; // for all cases where we've reached our end node and and need to loop back to the source node.
    }


    return solve(src, ALL_NODES_REMAINING);
     
}





int main(){
  //  adjList= {  {E, {A, F, D}}, {C, {B, A}}, {A, {D}}, {D,{H, G}}, {B, {D}}, {G, {I}}, {F,{K, J}}, {K, {J}}, {J, {M,L}}, {H,{J, I}},{M, {}}, {L, {}}, {I, {L}}};

        adjMatrix= {
{0, 10 ,15 , 20},
{5, 0, 9, 10},
{6, 13, 0, 12},
{8, 8, 9 ,0 }};


        cout << tsp(0) << endl;


    

}