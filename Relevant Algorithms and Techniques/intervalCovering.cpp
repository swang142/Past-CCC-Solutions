#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int intervalCovering(vector<pair<int, int>>& intervals, int fullLength){

        //we assume each pair is organized as (startPoint, endPoint). 
        //As we are trying to select the earliest starting points.

    sort(intervals.begin(), intervals.end()); //intervals are sorted based on start point

    int intervalsTaken=0, i= 0;
    int lengthCovered= 0, nextIntervalFinish;

    while(lengthCovered < fullLength){
        //finds the rightmost interval (interval ends the furthest)  which intersects with the current one
        nextIntervalFinish= lengthCovered;
        while(i < intervals.size() && intervals[i].first <= lengthCovered){
            //determines where the interval finishes
            nextIntervalFinish= max(nextIntervalFinish, intervals[i].second); 
            i++;
        }

        //No intersecting intervals to the right
        if(nextIntervalFinish == lengthCovered){  
            //no way to further cover the line, not possible
            return -1;
        }

        //takes the found rightmost interval
        intervalsTaken++; //increment number of intervals taken
        lengthCovered= nextIntervalFinish; //updates lengthCovered
    }

    if(lengthCovered < fullLength){ //if line cannot be covered
        return -1;
    }

    return intervalsTaken;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

}