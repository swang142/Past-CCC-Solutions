#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int numEvents(vector<pair<int, int>>& events){
    //we assume each pair is organized as (endTime, startTime). As we are trying to select the earliest
    //end times.

    sort(events.begin(), events.end()); //we sort the array of pairs.
    //NOTE: we couldve also used an ordered map for this.

    int numEvents= 1, currentEndTime= events[0].first; //gets the earliest end event first

    for(int i=1; i< events.size(); i++){
        if(currentEndTime<= events[i].second){ 
//ensures no overlap/conflicting events by comparing the current end time with the next earlist end time event's starting time. (wording is a lil confusing.)
            numEvents++;
            currentEndTime= events[i].first;
        }
    }

    return numEvents;

}

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