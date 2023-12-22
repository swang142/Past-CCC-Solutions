#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int inf= 1e9;
 vector<vector<int>>  f;

ll getSumWalkingTime(int p){
    ll out=0;
    for(vector<int> a: f){
        ll walkDist= abs((p-a[0]))- a[2];
        if(walkDist > 0) out+= walkDist* a[1];
    }
    return out;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int N; cin >> N;
    f.assign(N,vector<int>(3, 0) );
    int low= inf, high=0;
    for(int i=0; i< N; i++){
        cin >> f[i][0] >> f[i][1] >> f[i][2];
        if(f[i][0]> high) high= f[i][0];     
        if(f[i][0]< low) low= f[i][0];
    }
    int mid; ll s;

    while(low <= high){
        
        int mid= low + (high-low)/2;
        s= getSumWalkingTime(mid);
        ll sLeft= getSumWalkingTime(mid-1); ll sRight= getSumWalkingTime(mid+1);
        
        if(s < sRight && s< sLeft){
            break;
        }
        else if(s == sRight && s== sLeft){
            break;
        }
        else if(s<sRight){
            high= mid-1;
        }
        else if(s<sLeft){
            low= mid+1;
            }
    }
    cout << s << endl;

}
