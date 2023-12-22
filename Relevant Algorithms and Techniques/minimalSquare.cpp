#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int minSquare(int a, int b){
    int mini= min(a, b);
    int maxi= max(a,b);

   
    return pow(max(2*mini, maxi),2);
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >>t;

    while(t--){
        int a; cin >> a; int b; cin>>b;
        cout << minSquare(a,b) << '\n';
    }



}