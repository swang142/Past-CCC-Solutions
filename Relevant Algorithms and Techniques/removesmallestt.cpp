#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t; cin >>t;

    while(t--){
        int n; cin>>n; int arr[101]= {0};
        for(int i=0; i< n; i++){
            int e; cin>> e;
            arr[e]=1;
        }

        if(n==1){
            cout << "YES" << '\n';
            continue;
        }

        for(int i=0; i<100; i++){
            if(arr[i+1]==1 && arr[i]==1){
                arr[i]=0;
            }
        }

        int sum=0;
        for(int num: arr){
            sum+= num;
        }

        if(sum==1){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }


    }
}