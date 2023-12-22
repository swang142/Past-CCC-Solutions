#include <bits/stdc++.h>
#include <optional>
using namespace std;
typedef long long ll;


unordered_map<int, bool> memo;

int inf= 1e9;

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


bool canSumIter(int targetSum, vector<int>& coins){
    vector<bool> table;
    table.assign(targetSum+1, false);
    table[0]= true;

    for(int val: coins){
        table[val]= true; //seed values
    }


    for(int i=1; i<= targetSum; i++){
        if(table[i]){
            for(int val: coins){
                if(i+val <= targetSum){
                    table[i+val]= true;
                }
            }
        }
    }

    return table[targetSum];

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
        
        int remainder= remainingSum- val; //determines the remainder based on each coin
        vector<int> c= howSum(remainder, coins);
        if(c.empty() || c[0] != -1){ //only returns true if the howSum is not vector {-1}, which means the target sum can be derived to. 
        //Making sure the vector is not empty or else [0] would not work
            c.push_back(val); //adds the coin to the list
            memo2[remainingSum]= c;
            return c;
        }
    }
    
    v={-1};
    memo2[remainingSum]= v;
    return v; //returns vector {-1}


}

vector<int> howSumIter(int targetSum, vector<int> &coins){

    vector<vector<int>> table;
    table.assign(targetSum+1, {inf});
    table[0]= {};

    for(int val: coins){
        table[val]= {val}; //seed values
    }


    for(int i=1; i<= targetSum; i++){
        if(table[i][0]!= inf){
            for(int val: coins){
                if(i+val <= targetSum){
                    auto cur= table[i];
                    cur.push_back(val);
                    table[i+val]= cur;
                }
            }
        }
    }

    return table[targetSum];

}


unordered_map<int, vector<int>> memo3;

vector<int> bestSum(int remainingSum, vector<int>& coins){

    vector<int> v;

    if(memo3.find(remainingSum) != memo3.end()){
        return memo3[remainingSum];
    }

    if(remainingSum == 0){ //base case #1: target sum can be derived to perfectly
        return v;
    }
    if(remainingSum < 0){//base case #2: target sum cannot be derived to
        v= {inf};
        return v;
    }
    
    vector<int> shortest= {inf};

    for(auto val: coins){
        int remainder= remainingSum - val;

        vector<int> c= bestSum(remainder, coins);
        if(c.empty() || c[0]!= inf){
            c.push_back(val);
            if(shortest[0]== inf || c.size() < shortest.size()){
                shortest= c; 
            }
        }
    }

    memo3[remainingSum]= shortest;
    return shortest;


}
vector<int> bestSumIter(int targetSum, vector<int> &coins){

    vector<vector<int>> table;
    table.assign(targetSum+1, {inf});
    table[0]= {};

    for(int val: coins){
        table[val]= {val}; //seed values
    }


    for(int i=1; i<= targetSum; i++){
        if(table[i][0]!= inf){
            for(int val: coins){
                if(i+val <= targetSum){
                    auto cur= table[i];
                    cur.push_back(val);
                    if(table[i+val][0] == inf || table[i+val].size() > cur.size()){
                        table[i+val]= cur;
                    }
                    
                }
            }
        }
    }

    return table[targetSum];

}

unordered_map<int, int> dp;

int bestNumCoins(int targetSum, vector<int> coins){

    if(targetSum == 0) return 0;
    if(targetSum < 0) return inf;
    if(dp[targetSum] != -inf) return dp[targetSum];


    int minCoinCount= inf;

    for(int val: coins){
        minCoinCount= min(minCoinCount, 1+ bestNumCoins(targetSum - val, coins));
    }


    return dp[targetSum]= minCoinCount;

}

vector<int> coinsList;

void findCoinList(int targetSum, vector<int> coins){
    if(targetSum <= 0){
        return;
    }

    for(int val: coins){
        if(val<= targetSum){
            if(dp[targetSum]== 1+ dp[targetSum- val]){
                coinsList.push_back(val);
                findCoinList(targetSum- val, coins);
                return;

            }
        }
    }
}


vector<int> helper(int targetSum, vector<int> coins){
    for(int i=0; i<= targetSum; i++){
        dp[i]= -inf;
    }
    dp[0]= 0;

    bestNumCoins(targetSum, coins) ;
    findCoinList(targetSum, coins);

    return coinsList;



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    vector<int> coins= {  1, 23,2, 47,3};

    auto list= helper(28, coins);


    for(auto d: list) cout << d << " ";



    


}