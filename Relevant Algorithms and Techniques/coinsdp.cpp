#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


unordered_map<int, bool> memo;


bool canSum(int remainingSum, vector<int> &coins){


    if(memo.find(remainingSum)!= memo.end()){ //if it exists in the memo map
        return memo[remainingSum]; //return the value
    }
    if(remainingSum == 0){ //base case #1: target sum can be derived to perfectly
        return true;
    }
    if(remainingSum < 0){//base case #2: target sum cannot be derived to
        return false;
    }


    for(auto val: coins){
        int remainder= remainingSum- val; //determines the remainder based on each coin
        if(canSum(remainder, coins)){ //only returns true if canSum of the remainder returns true, which means the remainder be summed up to.


            memo[remainingSum]= true; //stores the corresponding value of true in the memo map for the current remainingSum to be used in the future
            return true; //returns true
        }
    }


    memo[remainingSum]= false; //stores the corresponding value of false in the memo map for the current remainingSum to be used in the future
    return false; //returns false


}

unordered_map<int, vector<int>> memo2;

vector<int> howSum(int remainingSum, vector<int> &coins){
    vector<int> v;

    if(memo2.find(remainingSum)!= memo2.end()){
        return memo2[remainingSum];

    }
    if(remainingSum == 0){ //base case #1: target sum can be derived to perfectly
        return v;
    }
    if(remainingSum < 0){//base case #2: target sum cannot be derived to
        v= {-1};
        return v;
    }

    for(auto val: coins){
        vector<int> c;
        int remainder= remainingSum- val; //determines the remainder based on each coin
        c= howSum(remainder, coins);
        if(c[0] != -1){ //only returns true if the howSum is not vector {-1}, which means the target sum can be derived to
            c.push_back(val); //adds the coin to the list
            memo2[remainingSum]= c;
            return c;
        }
    }
    
    v={-1};
    memo2[remainingSum]= v;
    return v; //returns vector {-1}


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "running" << endl;
    vector<int> coins= {7,14};


    auto result= howSum(7, coins);

    for(int a: result) cout << a << " ";

    cout << "works" << endl;


}