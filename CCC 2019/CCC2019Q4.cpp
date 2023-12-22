#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;
int N, K;

vector<int> order;
vector<vector<int>> dp;

int bS(int sP, int nD){
    if(nD == 0){
        if(sP == order.size()){
            return 0;
        }
        else{
            return INT_MIN;
        }
        
    }   
    int maxSum= 0;
    for(int i=1; i<= K; i++){
        int maxE= 0;
        if(dp[sP][i] != inf){
            maxE= dp[sP][i];
        }
        else{
            maxE= *max_element(order.begin() + sP, order.begin() + sP +i);
            dp[sP][i]= maxE;
        }
       // int maxE= *max_element(order.begin() + sP, order.begin() + sP +i);
        maxSum= max(maxSum, maxE+ bS(sP + i, nD- 1));
    }

    return maxSum;
}

int main(){
    cin >> N >> K;

    dp.assign(N+1, vector<int>(K+1, inf));

    for(int i=0; i< N; i++){
        int e; cin >> e;
        order.push_back(e);
    }

    int nD= ceil((double)N/K);

    cout << bS(0, nD) << endl;


}
