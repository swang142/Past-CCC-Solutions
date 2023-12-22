#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

vector<int> tideLvls;
int numLvls;

int main(){
    cin >> numLvls;

    for(int i=0; i< numLvls; i++){
        int lvl; cin>> lvl;
        tideLvls.push_back(lvl);
    }

    sort(tideLvls.begin(), tideLvls.end());

    
    for(int i=(numLvls+1)/2-1, j= i+1; i>=0 || j< numLvls; i--, j++){
        if(i>=0){
            cout << tideLvls[i] << " ";
        }

        if(j< numLvls){
            cout << tideLvls[j] << " ";
        }
        
        
        
    }
}