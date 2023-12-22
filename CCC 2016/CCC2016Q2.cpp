#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

int choice, N;

vector<int> dmoj, peg;



void sort(){
    if(choice == 2){
        sort(dmoj.begin(), dmoj.end());
        sort(peg.begin(), peg.end(), greater<int>());
    }
    else{
        sort(dmoj.begin(), dmoj.end());
        sort(peg.begin(), peg.end());
    }
}

int main(){

    cin >> choice >> N;

    for(int i=0; i< N; i++){    
        int e; cin >> e;
        dmoj.push_back(e);
    }
    for(int i=0; i< N; i++){    
        int e; cin >> e;
        peg.push_back(e);
    }

    sort();

    int sum = 0;

    for(int i=0; i< N; i++){    
        sum+=  max(dmoj[i], peg[i]);
    }

    cout << sum << '\n';

}
