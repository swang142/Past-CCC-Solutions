
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n= 4, counts=0;

/* A utility function to check if a queen can
   be placed on board[row][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */
bool isSafe(int board[][4], int row, int col){

    /* Check this row on left side */
    for(int j=0; j< col; j++){
        if(board[row][j]==1){
            return false;
        }
    }

    /* Check upper diagonal on left side */
    for(int i=row, j= col; i>=0 && j>=0; i--, j--){
        if(board[i][j]==1){
            return false;
        }
    }

     /* Check lower diagonal on left side */
    for (int i = row, j = col; j >= 0 && i < n; i++, j--){
        if(board[i][j]==1){
            return false;
        }
    }

    return true;
    

}

void solve(int board[][4], int curCol){

    if(curCol == n){
        counts++;
        return;
    }

    for(int i=0; i< n; i++){
        if(isSafe(board, i, curCol)){
            /* Place this queen in board[i][col] */
            board[i][curCol] = 1;
            solve(board, curCol+1);

            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            board[i][curCol] = 0; // BACKTRACK
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int board[4][4] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
    solve(board, 0);
    cout << counts << '\n';
}

