#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> commonDivisors(string& s){

    vector<string> divisors;

    for(int l=1; l<= s.length(); l++){
        string test= s.substr(0, l);

        int index= l;
        while(true){

            if(index== s.length()){
                divisors.push_back(test);
            }
            if(s.substr(index, l)!= test){
                break;
            }
            if(index > s.length()){
                break;
            }
        
            index+=l;
        }
    }
    return divisors;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1; cin >> s1;
    string s2; cin >> s2;

    vector<string> common1= commonDivisors(s1);
    vector<string> common2= commonDivisors(s2);

    int count=0;

    for(string s: common1){
        for(string t: common2){
            if(s == t){
                count++;
            }
        }
    }

    cout << count << '\n';

}