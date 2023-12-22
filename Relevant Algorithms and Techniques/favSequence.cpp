#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int maxTeams(vector<int>& arr){
    int n= arr.size();
    int maxTeams= 0;

    for(int i=0; i< n; i++){
        for(int j= n-1; j>i; j--){
            int S= arr[i] + arr[j];
            int teams= 1;

            int a= i+1;
            int b= j-1;

            while(a< b){

                if(arr[a]+arr[b] == S){
                    teams++;
                    a++;
                    b--;
                }
                else if(arr[a]+arr[b] < S){
                    a++;
                }
                else{
                    b--;
                }
            }

            maxTeams= max(maxTeams, teams);
        }

    }

    return maxTeams;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin>> n;
        vector<int> a(n);

        for(int i=0; i< n; i++){
            cin >> a[i];
        }

            sort(a.begin(), a.end());
            int m= maxTeams(a);

            cout << m << '\n';

    }

}