#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

int N, M;
vector<vector<char>> grid;
vector<vector<int>> numMoves;
vector<vector<bool>> visited;

int sR, sC;

void seen(int r, int c){
    for(int i= r+1; i< N; i++){
        if(grid[i][c] == '.') grid[i][c]= 'K';
        
        if(grid[i][c] == 'W'){break; }
    }
    for(int i= r-1; i>=0 ; i--){
       if(grid[i][c] == '.') grid[i][c]= 'K';
        if(grid[i][c] == 'W'){break; }
    }
    for(int j= c+1; j< M; j++){
        if(grid[r][j] == '.') grid[r][j]= 'K';
        if(grid[r][j] == 'W'){break; }
    }
    for(int j= c-1; j>=0 ; j--){
        if(grid[r][j] == '.') grid[r][j]= 'K';
        if(grid[r][j] == 'W'){break; }
    }

}

void BFS(){

    int dr[4]= {-1, 1, 0, 0}; int dc[4]= {0, 0, -1, 1};
    queue<int> rq; queue<int> cq; queue<int> dq;
    rq.push(sR), cq.push(sC); dq.push(0);
    while(!rq.empty()){
        int curR= rq.front(); int curC= cq.front(); int curDist= dq.front();
        rq.pop(); cq.pop(); dq.pop();
        if(grid[curR][curC] == '.'){ numMoves[curR][curC]= curDist;}
        if(grid[curR][curC] == 'W'){continue;}
        if(grid[curR][curC]== 'K') continue;

        for(int i=0; i<4; i++){
            int neighbourR= curR+ dr[i]; int neighbourC= curC+ dc[i];
            if(neighbourR <0 || neighbourR>= grid.size()) continue;
            if(neighbourC <0 || neighbourC>= grid[0].size()) continue;
            if(grid[neighbourR][neighbourC]== 'W' || grid[neighbourR][neighbourC]== 'K') continue;


            if(!visited[neighbourR][neighbourC]){
                if(grid[neighbourR][neighbourC] != '.'){
                    visited[neighbourR][neighbourC]= true;
                    if(grid[neighbourR][neighbourC]== 'U') neighbourR--; if(grid[neighbourR][neighbourC]== 'D') neighbourR++; if(grid[neighbourR][neighbourC]== 'R') neighbourC++; 
                    if(grid[neighbourR][neighbourC]== 'L') neighbourC--;
                }
                visited[neighbourR][neighbourC]= true;
                rq.push(neighbourR); cq.push(neighbourC); dq.push(curDist+1);
            }
            
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cin>> N >> M;

    grid.assign(N, vector<char>(M, -1));
    numMoves.assign(N, vector<int>(M, -1));
    visited.assign(N, vector<bool>(M, false));

    for(int i=0; i< N; i++){

        for(int j=0; j < M; j++){
            char c; cin >> c;
            grid[i][j]= c;
            if(c == 'S'){sR=i; sC= j;}
        }
    }

    for(int i=0; i< N; i++){
        for(int j=0; j< M; j++){
            if(grid[i][j] == 'C'){
                seen(i, j);
            }
        }

    }

    BFS();


    for(int i=0; i< N; i++){
        for(int j=0; j< M; j++){
            if(grid[i][j] == '.' || grid[i][j] == 'K'){
                cout << numMoves[i][j] << '\n';
            }
        }

    }




}