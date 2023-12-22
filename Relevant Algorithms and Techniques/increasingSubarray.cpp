#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll increaseSum(vector<int>& nums){

    ll count=1; 
    ll maxCount= 1;    
    
    for(auto i=1; i< nums.size(); i++){

        if(nums[i]> nums[i-1]){
            count++;
        }
        else{
            count= 1;
        }


        maxCount= max(count, maxCount);

    }
    return maxCount;


}




int main(){

    int n; cin>> n;
    vector<int> nums;

    for(int i=0; i< n; i++){
        int x; cin>> x;
        nums.push_back(x);
    }

    cout << increaseSum(nums);



}