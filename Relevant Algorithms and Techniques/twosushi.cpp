#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int maxLength(vector<int> & arr){
    int n= (int) arr.size();

    int start=0; 
    int end= n-1;

    int count1=0, count2 =0;


    while(start <= end){

        if(start == end ){

            if(arr[start]==1){
                count1++;
            }
            else{
                count2++;
            }
            break;
        }

        else{
            if(arr[start] ==1 ){
                count1++;
            }
            else{
                count1= 0;
            }
            start++;

            if(arr[end] == 2){
                count2 ++;
            }
            else{
                count2=0;
            }
            end--;
        }
            
    }

    int firsty= count1+ count2;

    start=0, end= n-1;
    count1=0, count2 =0;

    while(start <= end){
        if(start == end){
            if(arr[start]==2){
                count1++;
            }
            else{
                count2++;
            }
            break;
        }
        else{
            if(arr[start] ==2){
                count1++;
            }
            else{
                count1= 0;
            }
            start++;

            if(arr[end] == 1){
                count2 ++;
            }
            else{
                count2=0;
            }
            end--;
        }
    }


    int secondy= count1+ count2;

    return max(firsty, secondy);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);

    for(int i=0; i< n; i++){
        cin >> a[i];
    }

    cout << maxLength(a) << '\n';




}