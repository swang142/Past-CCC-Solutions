#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf= 1e9;

vector<vector<char>> grid;


int shortestLengthBFS(int startPos[], vector<vector<bool>> visited){

    int dr[4]= {-1, 1, 0, 0};
    int dc[4]= {0, 0, -1, 1};


    queue<int> rq;
    queue<int> cq;
    queue<int> dq;
    rq.push(startPos[0]); 
    cq.push(startPos[1]);
    dq.push(0);

    visited[startPos[0]][startPos[1]]= true;

    while(!rq.empty()){
        

        int curR= rq.front();
        int curC= cq.front();
        int curDist= dq.front();
        rq.pop(); cq.pop(); dq.pop();

        if(grid[curR][curC]== 'E'){
            return curDist;
        }


        for(int i=0; i<4; i++){
            int neighbourR= curR+ dr[i];
            int neighbourC= curC+ dc[i];
            if(neighbourR <0 || neighbourR>= grid.size()) continue;
            if(neighbourC <0 || neighbourC>= grid[0].size()) continue;
            if(grid[neighbourR][neighbourC]== '#') continue;


            if(!visited[neighbourR][neighbourC]){
                rq.push(neighbourR); cq.push(neighbourC); dq.push(curDist+1);
                visited[neighbourR][neighbourC]= true;
            }
        }
    }

    return -1;


}


int main(){

grid ={
  {'S', '.', '.', '#', '.','.','.'},
  {'.', '#', '.', '.', '.','#', '.'},
  {'.', '#', '.', '.', '.', '#', '.'},
  {'.', '.', '#', '#', '.', '#' , '.'},
  {'#', '.', '#', '#', '.' , '#', 'E' }
};

vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

int startPos[2]= {0,0};

cout << shortestLengthBFS(startPos, visited) << endl;




}