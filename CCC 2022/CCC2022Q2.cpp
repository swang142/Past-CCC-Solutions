#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int inf= 1e9;

vector<string> groups;
unordered_map<string, vector<string>> same, diff;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int x, y, g; cin >> x;
    for(int i=0; i< x; i++){
        string n1, n2; cin >> n1 >> n2;
        same[n1].push_back(n2); 
    }

    cin>> y;
    for(int i=0; i< y; i++){
        string n1, n2; cin >> n1 >> n2;
        diff[n1].push_back(n2);
    }
    
    int constraintCount=0;
    cin >> g;
    for(int i=0; i< g; i++){
        string n1, n2, n3; cin>> n1 >> n2 >> n3;
      //  cout << "same" << endl;
        for(auto name: same[n1]){
          //  cout << name << endl;
            if(!(name== n2 || name==n3) ) constraintCount++;
        }
        for(auto name: same[n2]){
           // cout << name<< endl;
            if(!(name==n1 || name==n3) ) constraintCount++;
        }
        for(auto name: same[n3]){
           // cout << name<< endl;
            if(!(name==n2 || name==n1) ) constraintCount++;
        }
       // cout << "diff"<< endl;
        for(auto name: diff[n1]){
          //  cout << name << endl; 
            if(name== n2 || name==n3 ) constraintCount++;
        }
        for(auto name: diff[n2]){
            //cout << name << endl;
            if(name==n3 || name==n1) constraintCount++;
        }
        for(auto name: diff[n3]){
          //  cout << name << endl;
            if(name==n2 || name==n1) constraintCount++;
        }

    }

    cout << constraintCount << endl;


}
