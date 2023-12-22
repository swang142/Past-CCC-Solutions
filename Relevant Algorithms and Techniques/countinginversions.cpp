#include <bits/stdc++.h>
using namespace std;


#define ll long long;


void merger(int array[], int low, int mid, int high);


void mergeSort(int array[], int low, int high) {
		if (low< high){
		      int mid = (low+high)/2;
		      mergeSort(array, low, mid);
		      mergeSort(array, mid+1, high);
		      merger(array, low, mid, high);
		}
}


	
void merger(int array[], int low, int mid, int high) {
    
    // Creating temporary subarrays
    int leftArray[mid- low + 1];
    int rightArray[high - (mid+1)+1];


    int llength= mid- low + 1;
    int rlength= high - (mid+1)+1;




    // Copying our subarrays into temporaries
    for (int i = 0; i < llength; i++)
        leftArray[i] = array[low + i];
    for (int i = 0; i < rlength; i++)
        rightArray[i] = array[mid+1 + i ];






    int i,j ,k;
    i=  j= 0;
    k= low; 
    
    while(i< llength && j< rlength) {
        if(leftArray[i] <= rightArray[j]) {
            array[k]= leftArray[i];
            i++;
        }
        else {
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
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

}
