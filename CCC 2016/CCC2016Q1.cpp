#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

unordered_map<char, int> nC;
unordered_map<char, int> anC;
string N;
string an;

int main(){
    cin >> N >> an;


    for(char c: N){
        nC[c]++;
    }
    for(char c: an){
        anC[c]++;
    }


    int len= 0;

    for(char c: an){
        if( c != '*' && anC[c] > nC[c]){
            cout << 'N' << '\n'; return 0;
        }  
    }

    if(an.length() == N.length()){
        cout << "A" << '\n';
    }
    else{
        cout << "N" << '\n';
    }
    

    


}