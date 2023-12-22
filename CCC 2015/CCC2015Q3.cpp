#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

int G, P;

vector<int> pLndgs; vector<bool> gates;
void solve(){

    for(int j=1; j< pLndgs.size();j ++){
        int a= pLndgs[j];
        bool canLand= false;

        for(int i= a; i>=1; i--){
            if(!gates[i]){
                gates[i]= true;
                canLand= true;
                break;
            }
        }
        if(!canLand) return;
    }
}

int main(){
    cin >>  G>> P;

    gates.assign(G+1, false);
    pLndgs.assign(P +1, 0);
    for(int i=1;i <= P; i++){
        int a; cin >> a; pLndgs[i]= a;
    }

    

    solve();

    int count=0;

    for(bool d: gates){
        if(d) count ++;
    }

    cout << count << endl;



}