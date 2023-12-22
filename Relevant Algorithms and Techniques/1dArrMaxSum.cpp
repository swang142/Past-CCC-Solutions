#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int max1DRangeSum(vector<int>& nums){
    vector<int> memo (nums.size());
    memo[0]= max(nums[0], 0);

    int maxSum= memo[0];
    
    for(int i=1; i< nums.size(); i++){
        
        int sum= memo[i-1]+ nums[i];
        memo[i]= max(sum,0); //memo[i] stores the contiguous sum up till index i, so long as it is a positive number. 
        //Once it becomes negative, we reset our sum, since we know its going to be AT LEAST 0. This is where we we reset our contiguos array.

        maxSum= max(maxSum,memo[i]);
    }

  //  for(auto val: memo) cout << val << " ";

    return maxSum;

}

int improvedMax1DRangeSum(vector<int>& nums){
    int currentSum= max(nums[0], 0);

    int maxSum= currentSum;
    
    for(int i=1; i< nums.size(); i++){
        
        int sum= currentSum+ nums[i];
        currentSum= max(sum,0); //currentSum stores the contiguous sum up till index i, so long as it is a positive number. 
        //Once it becomes negative, we reset our sum, since we know its going to be AT LEAST 0. This is where we we reset our contiguos array.

        maxSum= max(maxSum,currentSum);
    }


    return maxSum;
}



int main(){

    vector<int> nums= {-2, 1, -3, 4, -1, -2, 100, 150, 12};
    cout << improvedMax1DRangeSum(nums) << endl;
 
}