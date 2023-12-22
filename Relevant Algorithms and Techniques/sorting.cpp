#include <bits/stdc++.h>
using namespace std;


#define ll long long;


//quick sort
int generatePivotIndex(int low, int high){
    return rand() % (high - low+1) + low;
}


int partition(int start, int end, int arr[]){
    int pivotIndex= generatePivotIndex(start, end);


    //move pivot to the front
    swap(arr[pivotIndex], arr[start]);


    pivotIndex= start;
    int pivot= arr[pivotIndex];




    for(int i=start+1; i<= end; i++){
        if(arr[i]<= arr[start]){
            pivotIndex++;
            swap(arr[pivotIndex], arr[i]);
        }
    }


    swap(arr[start], arr[pivotIndex]); 
    return pivotIndex;
}

void quickSort(int start, int end, int arr[]){
    if(start>= end) return; 


    int pIndex= partition(start, end, arr);


    quickSort(start, pIndex-1, arr);
    quickSort(pIndex+1, end, arr);
}

//merge sort

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


    int arr[]= {0, 6, 7, 9, 1, 3 ,4 ,2 ,5 ,8  };


    mergeSort(arr, 0 ,9);
    for(int i: arr){
        cout << i << " ";
    }


}


