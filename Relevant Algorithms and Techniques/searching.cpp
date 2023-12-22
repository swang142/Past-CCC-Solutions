#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//linear search
int linearSearch(int arr[], int length, int key){

    for(int i=0; i< length; i++){
        if(arr[i]== key)
            return i;
    }
    return -1;

}

//binary search
int binarySearch(int arr[], int length, int key){

    int low=0;
    int high= length;

    while(low <= high){
        int middle= low + (high-low)/2; //same as (high+low)/2;

        if(arr[middle]== key)  
            return middle;
        else if(arr[middle]< key) 
            low= middle +1;
        else if(arr[middle] > key)
            high= middle;

    }

    return -1;

}

int recurBinarySearch(int arr[], int length, int key, int start, int end){
    int middle= (start + end)/2;

    if(arr[middle]== key)
        return middle;
    else if(start > end)
        return -1;
    else if(arr[middle] < key)
        return recurBinarySearch(arr, length, key, middle+1, end);
    else if(arr[middle] > key)
        return recurBinarySearch(arr, length, key,start, middle);

    return -1;

}


//quick select
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

int quickSelect(int l, int r, int order, int arr[]){

    //order refers to the nth smallest element. It is still 0-indexed!
    if(l >= r) return arr[l]; //when the resulting array has 1 element

    int k= partition(l,r, arr);

    if(k== order){ 
//if the pivot index is equal to our wanted index, we return the element there. (Think ab it! The pivot point will have always reached its final position)
        return arr[k];
    }
    else if(order < k){ //if its  greater than, search in the left subarray
        return quickSelect(l, k, order, arr);
    }
    else{ //if its less than, search in the right subarray
        return quickSelect(k+1, r, order, arr);
    }



}







int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[]= {3 ,1 ,2 ,5, 7, 8,9 ,20};
    int n= sizeof(arr)/sizeof(arr[0]);

    cout << quickSelect(0, n-1, 0, arr);

}