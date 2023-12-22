#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<char>> grid;
unordered_set<string> visited;
int inf= 1e9;

int dfs(int r, int c){



    if(r <0 || r>= grid.size()) return 0;
    if(c<0 || c>= grid[0].size()) return 0;

    string pos= to_string(r)+ ","+ to_string(c);

    if(visited.count(pos)){
        return 0;
    }

    if(grid[r][c]== 'W'){
        return 0;
    }

    int count =1;

    visited.insert(pos);

    count += dfs(r-1,c);
    count += dfs(r+1,c);
    count += dfs(r,c-1);
    count += dfs(r,c+1);

    return count;

}


int minIsland(){

    int count= inf;



    for(int i=0; i< grid.size(); i++){
        for(int j=0; j< grid[0].size(); j++){
            int size= dfs(i,j);
            if(size >0){
                count= min(count, size);
            }
            
        }
    }



    return count;

}


int main(){ 

    grid={
  {'W', 'W'},
  {'L', 'L'},
  {'W', 'W'},
  {'W', 'L'}
};
    cout << minIsland() << endl;




}