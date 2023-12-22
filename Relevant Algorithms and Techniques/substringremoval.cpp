#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

void playerTurn(int&  score);

int determineScore(){

    int aScore= 0, bScore= 0;


    while(s.find("1")!= string::npos){
            playerTurn(aScore);
            playerTurn(bScore);
    }


    





    return aScore;


}

void playerTurn(int&  score){

    int max=0; int index=0; int numConsec= 0;

    for(int i=0; i< s.length(); i++){

        
        if(s.substr(i, 1) == "1"){
            numConsec++;

        }
        else{
            if(numConsec > max){
                max= numConsec;
                index= i;
            }
            numConsec= 0;
        }
        if(i== s.length()-1){
            if(numConsec > max){
                max= numConsec;
                index= i;
            }
            numConsec= 0;
        }
    }



    score+= max;
    s= s.substr(0, index-max)+ s.substr(index);
   
}

int main(){
    int t; cin>> t;

    while(t--){
        cin >> s;
        cout << determineScore() << '\n';
    }

    

}