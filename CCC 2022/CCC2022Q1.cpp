#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int inf= 1e9;


int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int N; cin >> N;
    int count =0;

    while(N>=0){
        if(N % 5==0){
            count++;
        }
        N-=4;
    }
    
    cout << count;


}
