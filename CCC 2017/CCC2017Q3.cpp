
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

int N;

vector<int> heightsToLength;
vector<int> numWoods;


void getAllPairs(){
    heightsToLength.assign(4001, 0);
    for(int i=0; i<= 2000; i++){
        int num1= numWoods[i];
        if(num1 > 1){
            heightsToLength[i*2]+= num1/2;

        }
        for(int j= i+1; j <= 2000; j++){
            int num2=  numWoods[j];
            heightsToLength[i+j]+= min(num1, num2);
        }
        
    }


}

void largestLength(){
    int maxLength= 0, numMax= 0;

    for(auto p: heightsToLength){

        if(p > maxLength){
            maxLength= p;
        }
    }

    for(auto p: heightsToLength){

        if(p == maxLength){
            numMax++;
        }
    }

    cout << maxLength << " "<< numMax;


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>> N;

    numWoods.assign(2001, 0);

    for(int i=0; i< N; i++){
        int l; cin>> l;
        numWoods[l]++;
    }

    getAllPairs();
    largestLength();





    
        
        
    }
