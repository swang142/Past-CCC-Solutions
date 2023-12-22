#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


vector<int> minCoinsNeeded(int changeRemaining, vector<int>& coins){

    int currentIndex= coins.size()- 1;

    vector<int> coinsNeeded;

    while(changeRemaining>0 && currentIndex >= 0){
        while(currentIndex >= 0 && coins[currentIndex] > changeRemaining){
            currentIndex --;
        }
        changeRemaining -= coins[currentIndex];
        coinsNeeded.push_back(coins[currentIndex]);
    }

    return coinsNeeded;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> coins= {1,2,4,10};

    cout << minCoinsNeeded(9, coins).size() << '\n';


}