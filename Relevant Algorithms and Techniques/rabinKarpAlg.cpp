#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

ll p= 127; //prime approx equal to size of the alphabet used
ll m= 1e9 + 9; //10^9 +9, large prime number cardinality


// Let SLen = S.length():
// returns (S[0]*p^(SLen-1) + S[1]*p^(SLen-2) + ... + S[SLen-1]*p^0) % m
    //Remember!
    //(a+b)%m= a%m + b%m
    //(a*c)%m= (a%m) * (b%m)
//= S[0]*p^(SLen-1) % m + S[1]*p^(SLen-2) % m+ ... + S[SLen-1]*p^0 % m
//= (S[0]% m)*(p^(SLen-1)% m)  + (S[1]% m)*(p^(SLen-2) % m+) ... + (S[SLen-1]% m)*(p^0 % m)
// ... you can simplify even further!
ll stringHash(string S){

    ll hashValue=0;

    for(int i= 0; i< S.length(); i++){
        hashValue= (p*hashValue+ S[i])%m;
    }

    return hashValue;
}

// takes stringHash(S[i, i+keyLen)) and returns stringHash(S[i+1, i+1+keyLen))
ll reHash(ll curHash, string & S, int i, int keyLen) {

    //Since curHash will always have the same length of the key, its current value is:
    //f(i)= (S[i]*p^(keyLen-1) + S[i+1]*p^(keyLen-2) + ... + S[i+keyLen-1]*p^0) % m
    //by moving up 1 char, we want to convert that to:
    //g(i)= (S[i+1]*p^(keyLen-1) + S[i+2]*p^(keyLen-2) + ... + S[i+1+keyLen-1]*p^0) % m
    
    //we do that by doing the following operations ↓↓↓

    ll powerLength= 1;
    for(int i=0; i< keyLen-1; i++){
        powerLength= (powerLength* p) % m;
    }
    //powerLength= p^(keyLen-1)%mz`

	curHash = (p*(curHash - S[i]*powerLength) + S[i + keyLen]) % m;

	if (curHash < 0) //mod of a neg number in C++ can sometimes give a neg number, so all we need to do is add m to get positive.
		curHash += m;

	return curHash;
}




vector<int> searchString(string s, string key){ 

//polynomial rolling hash function

    if(s.length() < key.length()) return {}; 

    vector<int> allOcc= {};

    ll keyHash= stringHash(key);
    ll curHash= stringHash(s.substr(0, key.length()));

    for(int i=0; i<= s.length()- key.length(); i++){
        
        if(keyHash == curHash && s.substr(i, key.length())== key){ //only compares (==) strings after hash values are not equal.
            allOcc.push_back(i);
        }
        if (i < s.length()- key.length())
			curHash = reHash(curHash, s, i, key.length());

    }

    return allOcc;

    
}
 int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>> t;

    while(t--){
        string A; cin>> A;
        string B; cin>> B;

        auto v= searchString(A, B);

        if(v.empty()){
            cout << "Not Found" << '\n';
        }
        else{
            cout << v.size()<< '\n';
            for(int a: v){
                cout << a+1 << " ";
            }
            cout << '\n';
        }
        
        if (t > 0)
			cout << '\n';
    }
    

 }