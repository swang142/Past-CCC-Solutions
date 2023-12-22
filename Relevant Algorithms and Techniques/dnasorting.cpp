#include <bits/stdc++.h>
using namespace std;

typedef long long ll;




int main(){
    string dna, result= "";
    int count [100]= {0};
    cin >> dna;

    for(char c: dna){
        count[(int)c]++;
    }

    char characters[4]= {'A', 'C', 'G', 'T'};
    
    for(char a: characters){
        for(int i=0; i< count[(int)a]; i++){
            result+=a;
        }
    }

    cout << result << '\n';


}