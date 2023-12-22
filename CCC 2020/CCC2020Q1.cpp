#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

int N=0;
double ma= 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int> tisp;

    cin >> N;

    for(int i=0; i< N; i++){
        int a,b; cin>> a >> b;
        tisp[a]= b;
    }

    int pti=0, pd=0, d=0, ti= 0;
    double sp= 0;

    for(auto x: tisp){
        if(x.first == 0){
            pd= x.second; continue;
        }
        ti= x.first- pti; d= abs(x.second- pd);
        pti= x.first; pd= x.second;
        sp= (double) d /ti;

        ma= max(sp, ma);
    }

    cout << ma << endl;










}