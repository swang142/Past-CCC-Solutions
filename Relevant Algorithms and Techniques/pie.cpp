#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
    vector<int> keyCount(30);

 int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>> n; 

    string s; cin >> s;


    int numKeys=0;
    

    for(int i=0; i< s.length(); i++){
        char letr= s[i];
        if(i%2==0){
            
            keyCount[letr- 97]++;
        }
        else{
            letr= tolower(letr);
            
            if(keyCount[letr-97] ==0){
                numKeys++;
            }
            else{
                keyCount[letr-97]--;
            }
        }
    }

    cout << numKeys << '\n';



 }