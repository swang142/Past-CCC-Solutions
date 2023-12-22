#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


unordered_map<string, vector<pair<string, int>>> adjList;
unordered_set<string> visited;


pair<string, int> farthestNode(string src){
    visited.clear(); 
    queue<string> q;
    q.push(src);
    queue<int> weights;
    weights.push(0);

    visited.insert(src);
    string current;
    int curDist;


    while(!q.empty()){
        current= q.front();
        curDist= weights.front();
        q.pop(); weights.pop();

        for(auto neighbour: adjList[current]){
            string neighbourNode=  neighbour.first;
            int dist= neighbour.second;

            if(!visited.count(neighbourNode)){
                q.push(neighbourNode);
                weights.push(curDist+ dist);
                visited.insert(neighbourNode);
            }
        }
    }

    return {current, curDist};
}

int treeDiameter(){
    string randNode= "3";
    auto farthestFromNode= farthestNode(randNode);
    string nodeFarthestFromNode= farthestFromNode.first;
    auto diameterNode= farthestNode(nodeFarthestFromNode);
    return diameterNode.second;


}






int main(){


    adjList= { {"3", {{"1",5}}}, {"1", {{"3",5}, {"0",4}}}, {"0", {{"1",4}, {"2",3}} }, {"2", {{"0",3}, {"5", 1}, {"4", 2}} }, {"5", {{"2",1}} }, {"4", {{"2",2}, {"6",7}} }, {"6", {{"4",7}} } };
    


    cout << treeDiameter();


}
