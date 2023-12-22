#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n; int t; int p;



struct Contestant{

    int ID;

    int numSolved=0; int score=0; 

    int problemSet[2000]= {0};


 };

 bool comp(Contestant one, Contestant two){

    if(one.score== two.score){
        if(one.numSolved==two.numSolved){
            return one.ID > two.ID;
        }
        return one.numSolved< two.numSolved;
    }

    return one.score < two.score;
}

 int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
     cin >> n; cin >> t; cin >> p;

     Contestant arr [n];

     for(int i=1; i<= n; i++){
         Contestant& con= arr[i-1];
         con.ID= i;

         for(int j=0; j<t; j++){
             
             int ans; cin >>ans;
            
             con.problemSet[j]= ans;

             if(ans == 1){
                 con.numSolved++;
             }
        }
     }



     for(int i=0; i< t; i++){
        int points=0;

        for(Contestant& a: arr){
            if(a.problemSet[i]==0) points++;
        }


        for(Contestant& a: arr){
            if(a.problemSet[i]==1) a.score+=points;
           
        }
     }

     sort(arr, arr+n, comp);


     for(int i=0; i< n; i++){
         if(arr[i].ID== p){
             cout << arr[i].score << " " << (n-i);
         }
     }
     





     




 }