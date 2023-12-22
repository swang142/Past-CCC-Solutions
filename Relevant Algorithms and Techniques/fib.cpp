#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

vector<int> memo;

int fib(int n){

    if(memo[n]!= -1){ //if the value of the fib(n) has already been stored, return that value
        return memo[n];
    }
    if(n==0){
        return 0;
    }
    if(n== 1){
        return 1; 
    }

    memo[n]= fib(n-1) + fib(n-2); //or else, calculate that value recursively, and then store it.

    return memo[n]; //return the value
}

int recurFib(int n){
    memo.assign(n+1, -1); //makes memo a vector of size n+1 with all elements being -1. (Remember, size MUST be n+1 to store values from 0-n)

    return fib(n);

}

int iterFib(int n){
    vector<int> memo;

    memo.assign(n+1, -1); //makes memo a vector of size n+1 with all elements being -1. (Remember, size MUST be n+1 to store values from 0-n)
    memo[0]= 0; //fib(0) will always be 0
    memo[1]= 1; //fib(1) will always be 1

    for(int i=2; i<= n; i++){
        memo[i]= memo[i-1]+ memo[i-2]; //fills out all previous values before determining the one we want
    }

    return memo[n];

}

int improvedIterFib(int n){
    vector<int> memo (2);
    memo[0]= 0; //memo[0] will store the prev prev solution- fib(i-2)
    memo[1]= 1; //memo[1] will store the prev solution- fib(i-1)

    int current;

    for(int i=2; i<= n; i++){
        current= memo[0]+ memo[1];
        
        memo[0]= memo[1];
        memo[1]= current;   
        
    }

    return current;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << improvedIterFib(6) << endl;

}