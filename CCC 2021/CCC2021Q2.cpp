#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll inf= 1e9;
ll M,N, K, bCount, gCount;

vector<int>  rOp, cOp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> M >> N >> K;  gCount= 0; rOp.assign(M, 0), cOp.assign(N,0);

    char c; ll v;

    for(ll i=0; i< K; i++){
        cin >> c >> v;
        if(c == 'R'){  rOp[v-1]++;}
        else{  cOp[v-1]++;}
    }

    for(int r=0; r< M; r++){
        for(int c=0; c< N; c++){
            if((rOp[r]+ cOp[c]) %2 !=0){
                gCount++;
             //   cout << r << " " << c << endl;
            }
        }   
    }

    cout << gCount << endl;
}
