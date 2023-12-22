#include <bits/stdc++.h>
using namespace std;
typedef long long ll;




unordered_map<string, vector<pair<string, int>>> adjList;
unordered_set<string> visited;


int treeShortestBFS(string src, string dest){

    queue<string> q;
    queue<int> weights;


    q.push(src);
    weights.push(0);
    visited.insert(src);
    


    while(!q.empty()){
        string curNode= q.front();
        q.pop();
        int curDist= weights.front();
        weights.pop();

        if(curNode == dest){
            return curDist;
        }


        for(auto neighbour: adjList[curNode]){
            string neighbourNode= neighbour.first;
            int edgeWeight= neighbour.second;
            if(visited.count(neighbourNode)){
                q.push(neighbourNode);
                weights.push(curDist+edgeWeight);
                visited.insert(neighbourNode);
            }
        }
    }




    return -1;




}

int main(){

    	adjList = {{{"1", "4"}, {"2", "3"}}, {{"0", "4"}, {"3", "5"}},
			{{"0", "3"}, {"4", "2"}, {"5", "1"}}, {{"1", "5"}},
			{{"2", "2"}, {"6", "7"}}, {{"2", "1"}}, {{"4", "7"}}};
        cout << treeShortestBFS("3","6") << endl;

}