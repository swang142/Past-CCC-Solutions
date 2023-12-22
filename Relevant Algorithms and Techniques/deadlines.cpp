
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int maxScore(vector<pair<int,int>>& tasks){
    //we assume each pair is organized as (duration, deadline), as we are sorting by durations.
    sort(tasks.begin(), tasks.end());

    int maxScore=0, currentTime=0;

    for(auto pair: tasks){
        currentTime+= pair.first;
        maxScore+= pair.second - currentTime;
    }

    return maxScore;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> p1= {4,2};
    pair<int, int> p2= {3,5};
    pair<int, int> p3= {2,7};
    pair<int, int> p4= {4,5};
    vector<pair<int,int>> tasks= {p1, p2, p3, p4};

    cout << maxScore(tasks) << endl;


}