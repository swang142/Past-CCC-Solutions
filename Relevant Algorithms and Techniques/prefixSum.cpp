#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> prefixSum;

void fillPrefixSum(vector<int>& nums){

     prefixSum.assign(nums.size(), 0);

    prefixSum[0]= nums[0];

    for(int i= 1; i< prefixSum.size(); i++){
        prefixSum[i]= prefixSum[i-1]+ nums[i];
    }



}

int rangeSum(int i, int j){
    if(i == 0){
        return prefixSum[j]; //sum from indices [0,6] is just the element at j in the array.
    }
    return prefixSum[j]- prefixSum[i-1]; //finds sum from indices [i,j] inclusive

}

int main(){
    vector<int> nums= {6,5,3,4,-2, -1};

    fillPrefixSum(nums);

    for(auto l: prefixSum) cout << l << " ";

    cout << endl;

    cout << rangeSum(1, 5) << endl;

}