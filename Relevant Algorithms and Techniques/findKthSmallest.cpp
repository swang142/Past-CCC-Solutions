#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


unsigned arr [5000000];

void randomize(unsigned a,unsigned b,unsigned mod)
{
	for( unsigned i=0 ; i<5000000 ; i++ )
	{
		a = 31014 * (a & 65535) + (a >> 16);
		b = 17508 * (b & 65535) + (b >> 16);
		arr[i] = ((a << 16) + b) % mod;
	}
}

unsigned generatePivotIndex(unsigned low, unsigned high){
    return rand() % (high - low+1) + low;
}

unsigned partition(unsigned start, unsigned end, unsigned arr[]){
    unsigned pivotIndex= generatePivotIndex(start, end);




    //move pivot to the front
    swap(arr[pivotIndex], arr[start]);


    pivotIndex= start;
    unsigned pivot= arr[pivotIndex];



    for(unsigned i=start+1; i<= end; i++){
        if(arr[i]<= arr[start]){
            pivotIndex++;
            swap(arr[pivotIndex], arr[i]);
        }
    }




    swap(arr[start], arr[pivotIndex]); 
    return pivotIndex;
}


unsigned quickSelect(unsigned l, unsigned r, unsigned order, unsigned arr[]){


    //order refers to the nth smallest element. It is still 0-indexed!
    if(l >= r) return arr[l]; //when the resulting array has 1 elemen


    unsigned k= partition(l,r, arr);


    if(k== order){ 
//if the pivot index is equal to our wanted index, we return the element there. (Think ab it! The pivot pounsigned will have always reached its final position)
        return arr[k];
    }
    else if(order < k){ //if its  greater than, search in the left subarray
        return quickSelect(l, k-1, order, arr);
    }
    else{ //if its less than, search in the right subarray
        return quickSelect(k+1, r, order, arr);
    }


}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned a; cin>> a;
    unsigned b;  cin>> b;
    unsigned mod; cin >> mod;
    unsigned K; cin >> K;

    randomize(a,b, mod);

   

    cout << quickSelect(0, 5000000-1, 22, arr)<< endl;

 }