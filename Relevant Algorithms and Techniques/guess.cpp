#include <iostream>
using namespace std;

typedef long long ll;

int answer= 300;
int passCount= 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 1 <= answer <= 1000
    int low=0, high= 1000;

    while(low <= high){
        passCount++;
        int mid= low + (high-low)/2;
        
        if(mid == answer){
            break;
        }
        else if(mid < answer){
            low= mid+1;
        }
        else{
            high= mid-1;
        }
        
    }

    cout << passCount << '\n';


}

