#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inf= 1e9;

vector<int> swiftPts, semaPts;
int n;

int day(){
    int swiftSum=0, semaSum=0;
    int maxDay= 0, day= 0;
    for(int i=0; i< n; i++){

        day++;
        swiftSum += swiftPts[i];
        semaSum += semaPts[i];

        if(swiftSum == semaSum){
            maxDay= max(day, maxDay);
        }
    }

    return maxDay;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;


    swiftPts.assign(n, 0);
    semaPts.assign(n, 0);


    for(int i=0; i< n; i++){
        int pt; cin>> pt;
        swiftPts[i]= pt;
    }
    for(int i=0; i< n; i++){
        int pt; cin>> pt;
        semaPts[i]= pt;

    }




    cout << day() << endl;

}