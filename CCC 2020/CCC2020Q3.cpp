
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int inf= 1e9;



bool is_perm(map<char,int> m1,map<char,int> m2){
    for(int i=0; i< 26; i++){
        char letter= 'a' + i;
        if(m1[letter]!= m2[letter]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string N,H;    int count =0;

    cin >> N >> H;
    map<char, int> fN, fH;
    map<size_t, bool> used;


    for(int i=0; i< N.length(); i++){
        fN[N[i]]++;
    }

    for(int i=0; i< H.length()-N.length()+1; i++){
        string sub= H.substr(i, N.length());
        if(i==0){
            for(int j=0; j< sub.length(); j++) fH[H[j]]++; 
        }
        else{
            char remove= H[i-1], add= H[i+ sub.length() -1];
            fH[add]++; fH[remove]--;
        }
        hash<string> hasher;
        size_t hash= hasher(sub);
        
        if(is_perm(fN, fH) && !used[hash]){
            count++;
            used[hash]= true;
        }
    }

    cout << count << endl;

    



}