#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



ll merger(int array[], ll low, ll mid, ll high);


ll mergeSort(int array[], ll low, ll high) {
		if (low< high){
		      ll mid = (low+high)/2;
		      return mergeSort(array, low, mid) + mergeSort(array, mid+1, high) + merger(array, low, mid, high);
		}
        return 0;
}

	
ll merger(int array[], ll low, ll mid, ll high) {

    ll inversions= 0;
    
    // Creating temporary subarrays
    ll leftArray[mid- low + 1];
    ll rightArray[high - (mid+1)+1];


    ll llength= mid- low + 1;
    ll rlength= high - (mid+1)+1;



    // Copying our subarrays into temporaries
    for (ll i = 0; i < llength; i++)
        leftArray[i] = array[low + i];
    for (ll i = 0; i < rlength; i++)
        rightArray[i] = array[mid+1 + i ];




    ll i,j ,k;
    i=  j= 0;
    k= low; 
    
    while(i< llength && j< rlength) {
        if(leftArray[i] <= rightArray[j]) {
            array[k]= leftArray[i];
            i++;
        }
        else {
            inversions += (llength - i);  
            array[k]= rightArray[j];
            j++;
        }
        k++;
    }
    
//add remaining elements (will only be either right or left half)    
    while(i < llength) {
        array[k]= leftArray[i];
        k++;
        i++;
    }
    while(j < rlength) {
        array[k]= rightArray[j];
        k++;
        j++;
    }

    return inversions;
    
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    
    while(t--){
        ll n; cin >> n;
        int arr[n];
        for(ll i=0; i<n; i++){
            cin >> arr[i];
        }

        int inversions= mergeSort(arr, 0, n-1);


        cout << inversions << '\n';
    }

}