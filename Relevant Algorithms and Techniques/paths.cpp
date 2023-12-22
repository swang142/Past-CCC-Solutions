
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N= 5;
vector<vector<int>> grid;

int pathCount=0;



bool isFull(){
    for(auto a: grid){
        for(int i: a){
            if(i ==0 ) return false;
        }
    }

    return true;

}

void solve(int row, int col, char direc){


    if(row<0 || row>=N || col<0 || col>=N) return;
    
    if(grid[row][col] ==1) return;
    if(row == N-1 && col == N-1){
        grid[row][col]= 1;
        if(isFull()){
            pathCount++;
        }
        grid[row][col]= 0;
        return;
    }

    if((col== N-1 && direc == 'R') || (col==0 && direc == 'L')){
        if(row!= 0 && grid[row-1][col]== 0 && grid[row+1][col]==0){
            return;
        }
    }

    else if((row==N-1 && direc == 'D') || (row==0 && direc == 'U')){
        if(col!= 0 && col != N-1 && grid[row][col-1]== 0 && grid[row][col+1]==0){
            return;
        }
    }
    

    grid[row][col]= 1;

    
    if(row ==0 && col== 0){
        solve(row+1, col, 'D');
        solve(row, col+1, 'R');
    }
    else{
        solve(row+1, col, 'D');
        solve(row, col+1, 'R');
        solve(row-1, col, 'U');
        solve(row, col-1, 'L');
    }

    grid[row][col]= 0;

    


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);



    for(int i=0; i<N; i++){
        vector<int> a;
        for(int j=0; j<N; j++){
            a.push_back(0);
        }
        grid.push_back(a);
        
    }

    cout << "works" << endl;

    solve(0,0, 'z');
    cout << pathCount << '\n';




}