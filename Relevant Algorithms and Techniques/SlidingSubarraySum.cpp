#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int maxKSum(vector<int>& nums, int k){

    if(nums.size() < k){
        return -1;
    }

    int curWindow= 0;
    for(int i=0; i<k; i++){
        curWindow+= nums[i]; //gets the sum of k values- the first window
    }

    int maxSum= curWindow; //sets the current max sum to the first window

    for(int i=k; i< nums.size(); i++){
        curWindow= curWindow -nums[i-k] + nums[i]; 
        //subtracts the first value of the previous window and adds the next value in the list.
        //Hence, the 'sliding window'. It slides from one index to the next.
        maxSum= max(maxSum, curWindow);
    }

    return maxSum;
}

 int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums= {1, 3, 4, 5, 6}; //Output: 18
    cout << maxKSum(nums, 4) << '\n';


}