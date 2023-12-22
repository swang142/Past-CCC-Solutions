#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

int N;
vector<ll> villages;

int main(){
    cin >> N;

    for(int i=0; i< N; i++){
        ll v; cin>> v;
        villages.push_back(v);
    }

    sort(villages.begin(), villages.end());

   double mini= inf;

    for(int i=1; i<N-1 ; i++){
        ll v= villages[i];
        double nhood= ((v- villages[i-1])/2.0) + ((villages[i+1]- v)/2.0);

        
        mini= min(mini, nhood);

    }

    double num= 3.45542;
    cout << std::fixed << std::setprecision(2);
    cout << num << endl;



}