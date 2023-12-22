#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N; 
unordered_map <int,ll> dp;


 ll numBalanced(int weight){
     if(weight == 1 || weight == 2) return 1;

     if(dp.count(weight)) return dp[weight];

     ll ans= 0;
    for(int i=2; i<= weight; i++){
        int weightST= weight/i ;
        ans+= numBalanced(weightST);
    }

     return dp[weight]= ans;


 }

 int main(){
     cin >> N;

     cout << numBalanced(N) << endl;


 }