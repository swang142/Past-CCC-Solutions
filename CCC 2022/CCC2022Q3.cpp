#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int inf= 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n, m, k; cin >> n >> m >> k;
    vector<int> notes(n);
 //   cout << "working" << endl;


    if(k < n){ 
      cout << -1 << endl;
      return 0;
     // cout << "kys" << endl;
    }

     int prev= 1;
     int diff= k-n;
     int temp= diff;
    for(int i=0; i< n; i++){
      if(i!=0){
        if(temp>0){
          notes[i]= !(prev-1) +1; prev= notes[i];
          temp--;
        }
        else{
          notes[i]= prev;
        }
      }
      else{
        notes[i]= 1;
      }
    }

    if(temp > 0){ cout << -1 << endl; return 0; }

    for(int i=0; i< n; i++){
      cout << notes[i] << " ";
    } 



}
