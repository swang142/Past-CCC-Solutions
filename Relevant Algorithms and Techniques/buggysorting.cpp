#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

void buggySorting(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if(n<=2){
        cout << -1;  return;
    }

    for(int i=n; i>1; i--){
        cout << i << " ";
    }
    cout << 1;



}

int main(){

    cin>> n;
    buggySorting();

}