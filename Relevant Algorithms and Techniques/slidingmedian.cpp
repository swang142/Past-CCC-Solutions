#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void median(vector<int>& nums, int k){


    vector<int> curWindow(k);

    for(int i=0; i<k; i++){
        curWindow[i]= nums[i]; //gets the sum of the first k values: the first window
    }


    vector<int> sortedWindow= curWindow;
    sort(sortedWindow.begin(), sortedWindow.end());

    if(curWindow.size() % 2==0){
        cout << sortedWindow[(curWindow.size()/2)-1]<< " ";
    }
    else{
        cout << sortedWindow[(curWindow.size()/2)] << " ";
    }
    


    for(int i=k; i< (int)nums.size(); i++){
        rotate(curWindow.begin(), curWindow.begin()+1, curWindow.end());
        curWindow[k-1]= nums[i];



        vector<int> sortedWindow= curWindow;
        sort(sortedWindow.begin(), sortedWindow.end());

        if(curWindow.size() % 2==0){
            cout << sortedWindow[(curWindow.size()/2)-1]<< " ";
        }
        else{
            cout << sortedWindow[(curWindow.size()/2)]<< " ";
        }

    }


}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>> n;
    int k; cin >> k;
    vector<int> arr(n);

    for(int i=0; i< n; i++) cin >> arr[i];

    median(arr, k);



}