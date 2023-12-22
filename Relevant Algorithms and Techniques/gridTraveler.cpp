#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

unordered_map<string, int> memo;

//dont think about regular 2D array indices rn! As long as you're not using an actual 2D array,you can just think ab normal indices
// so top-left corner is (n,m), and bottom-right is (1,1 )

int gridTraveler(int row, int col){
    string key= to_string(row)+ ","+ to_string(col); //makes the key the coordinate

    if(memo.find(key)!= memo.end()){ //if it exists in the map
        return memo[key]; //return the value
    }
    if(row== 0 || col ==0) return 0; //base case 1: out of bounds
    if(row==1 && col== 1) return 1; //base case 2: reached bottom right

    memo[key]= gridTraveler(row-1, col) + gridTraveler(row, col-1); //calculates and memoizes the value

    return memo[key]; //returns the value 
}

int gridTravelerIter(int row, int col){

    int memo[(row+1)][(col+1)];

    memset( memo, 0, sizeof(memo) );

    memo[1][1]= 1;

    for(int i=0; i<= row; i++){
        for(int j=0; j<= col; j++){
            int current= memo[i][j];
            if(i+1 <= row) memo[i+1][j]+= current;
            if(j+1 <= col) memo[i][j+1]+= current;
        }
    }

    for(int i=0; i<= row; i++){
        for(int j=0; j<= col; j++){
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }

    return memo[row][col];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    cout << gridTravelerIter(10, 10) << endl;


}