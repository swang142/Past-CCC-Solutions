#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

int N;
vector<vector<int>> grid;


bool isValid(vector<vector<int>> g){

    for(int i=0; i< N; i++){
        for(int j=0; j< N; j++){
            if(i>0 && g[i][j]<= g[i-1][j]){return false;}
            if(j>0 && g[i][j] <= g[i][j-1]){ return false;}
        }
    }
    return true;
}

void printGrid(vector<vector<int>> g){
    for(auto l: g){
        for(int i: l){
            cout << i << " ";
        }
        cout << '\n';
    }

}
vector<vector<int>> rotateBy90(){

    vector<vector<int>> newGrid(N, vector<int>(N, 0));

    for(int r=0; r< N; r++){
        for(int c=0; c< N; c++){
            newGrid[r][c]= grid[abs(c- (N-1))][r];
        }
    }

    return newGrid;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cin>> N;

    grid.assign(N, vector<int>(N, 0));

    for(int i=0; i< N; i++){
        for(int j=0; j <N; j++){
            int n; cin>> n;
            grid[i][j]= n;
        }
    }

    for(int i=0; i< 4; i++){
        if(isValid(grid)){ printGrid(grid); return 0;}
        grid= rotateBy90();
    }



}