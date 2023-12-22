#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool valid(string s){

    string chara;

    stack<string> stack;

    for(int i=0; i< s.size(); i++){
        chara= s[i];

        if(chara == "(" || chara == "{"){
            stack.push(chara);
        }

        else if(chara == ")"){
            if(stack.empty()) return false;
            if(stack.top()=="("){
                stack.pop();
            }
            else{
                return false;
            }   
        }

        else if(chara == "}"){
            if(stack.empty()) return false;
            if(stack.top()=="{"){
                stack.pop();
            }
            else{
                return false;
            }   
        }

    }

            return stack.empty();



}
void bfs(int ){
    queue<string> q;
    q.push(start);


    while(!q.empty()){
        string current= q.front();
        q.pop();
        cout << current << endl;


        for(string d: test[current]){
            q.push(d);
        }
    }


}

vector<vector<int>> adjList;

void addEdge(int node1, int node2){
    adjList[node1]= node2; //adds a directed edge from node1 to node2 
}

int main(){


    }




}